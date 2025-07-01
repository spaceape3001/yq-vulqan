////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIInfoList.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/api/Rendered.hpp>
#include <tachyon/api/Widget.hpp>
#include <tachyon/event/panel/InfoSelectionChangedEvent.hpp>
#include <tachyon/gfx/Texture.hpp>
#include <tachyon/ui/UIElementMetaWriter.hpp>
#include <tachyon/ui/UIStyle.hpp>
#include <yq/text/match.hpp>

namespace yq::tachyon {
    struct UIInfoList::Row {
        std::string_view    iconfile;
        TextureCPtr         icon;
        ImTextureID         tex;
        std::string         label;
        std::string         description;
        const TachyonMeta*  info        = nullptr;
    };

    void UIInfoList::init_meta()
    {
        auto w = writer<UIInfoList>();
        w.description("Table of tachyon infos");
        w.property("title", &UIInfoList::m_title);
    }

    UIInfoList::UIInfoList(std::string_view szTitle, UIFlags flags) : UIElement(flags), m_title(szTitle)
    {
    }

    UIInfoList::UIInfoList(const UIInfoList& cp) : UIElement(cp), m_rows(cp.m_rows), m_title(cp.m_title)
    {
    }

    UIInfoList::~UIInfoList()
    {
    }

    const char* UIInfoList::title() const 
    {
        return m_title.c_str();
    }

    void UIInfoList::render() 
    {
        if(!(m_status(S::NotFirst) && m_status(S::NotStale))){
            define_rows();
            m_status |= S::NotFirst;
            m_status |= S::NotStale;
        }

        if(ImGui::BeginTable("TachyonMetaTypes", 3)){
        
            //ImGui::TableNextRow();
            //ImGui::TableNextColumn();
            //ImGui::TextUnformatted("icon");
            ////  might get fancy with dynamic rendering... (later)
            //ImGui::TableNextColumn();
            //ImGui::TextUnformatted("name");
            
            Size2F     iconSize = style().icon.def_size;    //< TODO Actual size 

            ImGui::TableSetupColumn("icon", ImGuiTableColumnFlags_WidthFixed, iconSize.x*1.2);
            ImGui::TableSetupColumn("type", ImGuiTableColumnFlags_WidthStretch, 0.3);
            ImGui::TableSetupColumn("description", ImGuiTableColumnFlags_WidthStretch, 0.7);
        
            
            std::string_view    cat;
            for(auto& r : m_rows){
                bool        doSelect    = false;
            
                if(!is_similar(cat, r.info->category())){
                    cat = r.info->category();
                    ImGui::TableNextRow(ImGuiTableRowFlags_Headers);
                    if(ImGui::TableNextColumn())
                        ImGui::Separator();
                    if(ImGui::TableNextColumn())
                        ImGui::TextUnformatted(cat);
                    if(ImGui::TableNextColumn())
                        ImGui::Separator();
                }
                
                ImGui::TableNextRow();
                if(ImGui::TableNextColumn() && r.tex){
                    ImGui::Image(r.tex, iconSize);
                }
                if(ImGui::TableNextColumn()){
                    if(ImGui::Selectable(r.label.c_str(), r.info == m_selected)){
                        doSelect        = true;
                    }
                }
                if(ImGui::TableNextColumn()){
                    if(ImGui::Selectable(r.description.c_str(), r.info == m_selected)){
                        doSelect        = true;
                    }
                }
                
                if(doSelect && (m_selected != r.info)){
                    m_selected  = r.info;
                    if(m_flags(UIFlag::EmitSignal) && widget()){
                        widget() -> mail(new InfoSelectionChangedEvent({.source=widget(), .target=widget()}, m_selected));
                    }
                }
            }
            
            
            ImGui::EndTable();
        }
    }

    void        UIInfoList::define_rows()
    {
        for(const TachyonMeta* info : get_infos()){
            if(!info)
                continue;
            Row     r;
            r.iconfile  = info->icon(BIGGER,48);
            if(r.iconfile.empty())
                r.iconfile  = info->icon(SMALLER,48);
            if(r.iconfile.empty())
                r.iconfile  = style().icon.unknown;
            r.icon  = Texture::load(r.iconfile);
            r.tex   = install(r.icon);
            r.info  = info;
            
            r.label         = std::format("{}##{}", info->stem(), info->name());
            r.description   = std::format("{}##{}", info->description(), info->stem());
            m_rows.push_back(r);
        }
        
        std::stable_sort(m_rows.begin(), m_rows.end(), [](const Row& a, const Row&b){
            Compare cmp = compare_igCase(a.info->category(), b.info->category());
            if(cmp != Compare::EQUAL)
                return is_less(cmp);
            return is_less_igCase(a.label, b.label);
        });
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIInfoList);
