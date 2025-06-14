////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "InspectorUI.hpp"

#include <tachyon/MyImGui.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/api/TachyonData.hpp>
#include <tachyon/ui/UIEditorInfoWriter.hpp>
#include <yq/text/match.hpp>
#include <tbb/spin_rw_mutex.h>

YQ_OBJECT_IMPLEMENT(InspectorUI)

struct InspectorUI::Info {
    const TachyonInfo*                  tac = nullptr;
    std::vector<const UIEditorInfo*>    panels;
};

struct InspectorUI::Repo {
    std::unordered_map<const TachyonInfo*, const Info*> editors;
    mutable tbb::spin_rw_mutex                          mutex;
    
    const Info*       info(const TachyonInfo& ti)
    {
        {
            tbb::spin_rw_mutex::scoped_lock _lock(mutex, false);
            auto i = editors.find(&ti);
            if(i != editors.end())
                return i->second;
        }

        struct HET {
            int                     hops    = 0;
            const UIEditorInfo*     editor  = nullptr;
        };
        
        auto&   ifaces      = ti.interfaces(ALL);
        
        static constexpr const int      kProxyHops   = -20;
        
        std::vector<HET>        edits;
        for(const UIEditorInfo* ui : UIEditorInfo::all()){
            if(!ui)
                continue;
            if(ui->is_abstract())
                continue;
                
            for(const TachyonInfo* t2 : ui->edits(TACHYON)){
                if(!t2)
                    continue;
                int h   = t2->hops_to_derived(ti);
                if(h < 0)
                    continue;
                edits.push_back({ h, ui  });
            }
            
            for(const InterfaceInfo* i2 : ui->edits(PROXY)){
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

        std::vector<const UIEditorInfo*>    epack;
        std::set<const UIEditorInfo*>       present;
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
    
    
    const std::vector<const UIEditorInfo*>& panels(const TachyonInfo& ti)
    {
        return info(ti) -> panels;
    }
};

InspectorUI::Repo& InspectorUI::repo()
{
    static Repo s_repo;
    return s_repo;
}

void InspectorUI::init_info()
{
    auto w = writer<InspectorUI>();
    w.description("Inspector UI");
}

InspectorUI::InspectorUI(UIFlags flags) : UIEditor(flags)
{
}

InspectorUI::InspectorUI(const InspectorUI& cp) : UIEditor(cp)
{
}

InspectorUI::~InspectorUI()
{
    _clear();
}

void    InspectorUI::_clear()
{
    for(auto& itr : m_panels)
        for(UIEditor* e : itr.second)
            delete e;
    m_panels.clear();
}

std::span<UIEditor*>    InspectorUI::_panels(TypedID tid)
{
    auto i = m_panels.find((TachyonID) tid);
    if(i != m_panels.end())
        return i->second;
        
    const Frame*   frame    = Frame::current();
    
    //  alright, generating...
    const TachyonInfo*  tac = frame->info((TachyonID) tid);
    if(!tac)
        return {};
        
    auto& ret   = m_panels[tid];
        
    for(const UIEditorInfo* ei : repo().panels(*tac)){
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

void InspectorUI::_render(TypedID tid)
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
    
    for(TypedID c : sn->children){
        const TachyonSnap*  cs  = frame->snap((TachyonID) c);
        if(!cs)
            continue;
        const TachyonInfo*  ci  = frame->info((TachyonID) c);
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
    
    ImGui::PopID();
}


InspectorUI* InspectorUI::clone() const 
{
    return new InspectorUI(*this);
}

bool InspectorUI::bind(TypedID tid) 
{
    if(!UIEditor::bind(tid))
        return false;

    const Frame* frame  = Frame::current();
    if(!frame)
        return false;
        
    const TachyonInfo*  tac = frame->info((TachyonID) tid);
    if(!tac)
        return false;

    _clear();
    _panels(tid);
    return true;
}

void InspectorUI::render() 
{
    if(!Frame::current())
        return;

    UIEditor::render();
    _render(bound());
}

