////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UITachyonEditor.hpp"

#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/text/match.hpp>
#include <tbb/spin_rw_mutex.h>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UITachyonEditor)

namespace yq::tachyon {
    struct UITachyonEditor::Info {
        const TachyonMeta*                  tac = nullptr;
        std::vector<const UIEditorMeta*>    panels;
    };

    struct UITachyonEditor::Repo {
        std::unordered_map<const TachyonMeta*, const Info*> editors;
        mutable tbb::spin_rw_mutex                          mutex;
        
        const Info*       info(const TachyonMeta& ti)
        {
            {
                tbb::spin_rw_mutex::scoped_lock _lock(mutex, false);
                auto i = editors.find(&ti);
                if(i != editors.end())
                    return i->second;
            }

            struct HET {
                int                     hops    = 0;
                const UIEditorMeta*     editor  = nullptr;
            };
            
            auto&   ifaces      = ti.interfaces(ALL);
            
            static constexpr const int      kProxyHops   = -20;
            
            std::vector<HET>        edits;
            for(const UIEditorMeta* ui : UIEditorMeta::all()){
                if(!ui)
                    continue;
                if(ui->is_abstract())
                    continue;
                    
                for(const TachyonMeta* t2 : ui->edits(TACHYON)){
                    if(!t2)
                        continue;
                    int h   = t2->hops_to_derived(ti);
                    if(h < 0)
                        continue;
                    edits.push_back({ h, ui  });
                }
                
                for(const InterfaceMeta* i2 : ui->edits(PROXY)){
                    if(!i2)
                        continue;
                    if(!ifaces.contains(i2))
                        continue;
                    edits.push_back({ kProxyHops, ui  });
                }
            }
            
            std::stable_sort(edits.begin(), edits.end(), [](const HET& a, const HET& b){
                if(a.hops != b.hops)    // want high hops first
                    return b.hops < a.hops;
                return is_less_igCase(a.editor->stem(), b.editor->stem());
            });

            std::vector<const UIEditorMeta*>    epack;
            std::set<const UIEditorMeta*>       present;
            for(auto& het : edits){
                if(present.insert(het.editor).second)
                    epack.push_back(het.editor);
            }

            tbb::spin_rw_mutex::scoped_lock _lock(mutex, true);
            auto i = editors.find(&ti);
            if(i != editors.end())
                return i->second;
            
            Info*   in  = new Info{.tac=&ti, .panels=std::move(epack)};
            editors[&ti] = in;
            return in;
        }
        
        
        const std::vector<const UIEditorMeta*>& panels(const TachyonMeta& ti)
        {
            return info(ti) -> panels;
        }
    };

    UITachyonEditor::Repo& UITachyonEditor::repo()
    {
        static Repo s_repo;
        return s_repo;
    }

    void UITachyonEditor::init_meta()
    {
        auto w = writer<UITachyonEditor>();
        w.description("Inspector UI");
    }

    UITachyonEditor::UITachyonEditor(UIFlags flags) : UIEditor(flags)
    {
    }

    UITachyonEditor::UITachyonEditor(const UITachyonEditor& cp) : UIEditor(cp)
    {
    }

    UITachyonEditor::~UITachyonEditor()
    {
        _clear();
    }

    void    UITachyonEditor::_clear()
    {
        for(auto& itr : m_panels)
            for(UIEditor* e : itr.second)
                delete e;
        m_panels.clear();
    }

    std::span<UIEditor*>    UITachyonEditor::_panels(TypedID tid)
    {
        auto i = m_panels.find((TachyonID) tid);
        if(i != m_panels.end())
            return i->second;
            
        const Frame*   frame    = Frame::current();
        
        //  alright, generating...
        const TachyonMeta*  tac = frame->meta((TachyonID) tid);
        if(!tac)
            return {};
            
        auto& ret   = m_panels[tid];
            
        for(const UIEditorMeta* ei : repo().panels(*tac)){
            if(!ei)
                continue;
            Object*     obj = ei -> create();
            if(!obj)
                continue;
            UIEditor*   ui  = dynamic_cast<UIEditor*>(obj);
            if(!ui){
                delete obj;
                continue;
            }
            if(!ui -> bind(tid)){
                delete ui;
                continue;
            }
            ret.push_back(ui);
        }
        
        return ret;
    }

    void UITachyonEditor::_render(TypedID tid)
    {
        const Frame* frame  = Frame::current();
        
        const TachyonSnap*  sn    = frame->snap((TachyonID) tid);
        if(!sn)
            return;
            
        std::string id  = std::format("tachyon{}", tid.id);
        ImGui::PushID(id.c_str());
            
        for(UIEditor* ui : _panels(tid)){
            ImGui::PushID(ui);
            ui->draw();
            ImGui::PopID();
        }
        
        if(flag(UIFlag::Children)){
            for(TypedID c : sn->children){
                const TachyonSnap*  cs  = frame->snap((TachyonID) c);
                if(!cs)
                    continue;
                const TachyonMeta*  ci  = frame->meta((TachyonID) c);
                if(!ci)
                    continue;
                    
                std::string str;
                if(cs->name.empty()){
                    str = std::format("{}({})##TREE{}", ci->stem(), c.id, c.id);
                } else {
                    str = std::format("{}({}:{})##TREE{}", cs -> name, ci->stem(), c.id, c.id);
                }
                if(ImGui::TreeNode(str.c_str())){
                    _render(c);
                    ImGui::TreePop();
                }
            }
        }
        ImGui::PopID();
    }


    UITachyonEditor* UITachyonEditor::clone() const 
    {
        return new UITachyonEditor(*this);
    }

    bool UITachyonEditor::bind(TypedID tid) 
    {
        if(!UIEditor::bind(tid))
            return false;

        const Frame* frame  = Frame::current();
        if(!frame)
            return false;
            
        const TachyonMeta*  tac = frame->meta((TachyonID) tid);
        if(!tac)
            return false;

        _clear();
        _panels(tid);
        return true;
    }

    void UITachyonEditor::render() 
    {
        if(!Frame::current())
            return;

        UIEditor::render();
        _render(bound());
    }

}
