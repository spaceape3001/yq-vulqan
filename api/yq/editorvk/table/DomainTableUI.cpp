////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "DomainTableUI.hpp"

#include <yq/editorvk/event/DomainSelectEvent.hpp>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/texture.hpp>
#include <yq/tachyon/api/Domain.hpp>
#include <yq/tachyon/api/DomainData.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>

namespace yq::tachyon {

    struct DomainTableUI::Row {
        DomainID            domain;
        const DomainMeta*   info        = nullptr;
        std::string        sid;        // ID for selectable
        std::string        stype;
    };

    void DomainTableUI::init_meta()
    {
        auto w = writer<DomainTableUI>();
        w.description("Scene Editor's Domain Table");
    }

    DomainTableUI::DomainTableUI(UIFlags flags) : UIElement(flags)
    {
    }

    DomainTableUI::DomainTableUI(const DomainTableUI& cp) : UIElement(cp)
    {
    }

    DomainTableUI*   DomainTableUI::clone() const 
    {
        return new DomainTableUI(*this);
    }


    void    DomainTableUI::render() 
    {
        const Frame*    frame   = Frame::current();
        if(!frame)
            return ;

        float   sz  = ImGui::GetFrameHeight() * 0.9;
        
        Size2F      imgBtnSize    = { sz, sz };
        
        if(!m_editing)
            m_editing = install(texture("openicon/icons/png/32x32/symbols/pictogram-din-e001-direction-right.png"));
            
        if(ImGui::BeginTable("Domains", 4)){
            ImGui::TableSetupColumn("Editing", ImGuiTableColumnFlags_WidthFixed|ImGuiTableColumnFlags_NoHeaderLabel, sz*1.2);
            ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_WidthStretch, 0.1);
            ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthStretch, 0.3);
            ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthStretch, 0.4);
            ImGui::TableHeadersRow();

            for(Row& e : m_rows){
                bool    isEdit  = (e.domain == m_selected);
                bool    wantEdit    = false;
                const DomainSnap*    ss  = frame->snap(e.domain);
                if(!ss)
                    continue;

                ImGui::TableNextRow();
                if(ImGui::TableNextColumn()){
                    if(isEdit){
                        if(m_editing){
                            ImGui::ImageWithBg(m_editing.id, imgBtnSize);
                        } else {
                            ImGui::TextUnformatted("E");
                        }
                    }
                }
                
                if(ImGui::TableNextColumn()){
                    if(ImGui::Selectable(e.sid.c_str(), isEdit) && !isEdit){
                        wantEdit    = true;
                    }
                }
                if(ImGui::TableNextColumn()){
                    if(ImGui::Selectable(e.stype.c_str(), isEdit) && !isEdit){
                        wantEdit    = true;
                    }
                }            

                if(ImGui::TableNextColumn()){
                    std::string sname;
                    if(ss->name.empty()){
                        sname   = std::format("(no-name)##{}.SELECT", e.domain.id); 
                    } else
                       sname = std::format("{}##{}.SELECT", ss->name, e.domain.id); 

                    if(ImGui::Selectable(sname.c_str(), isEdit) && !isEdit){
                        wantEdit    = true;
                    }
                }
                
                if(wantEdit)
                    set_selected(e.domain);
            }
            ImGui::EndTable();
        }
    }

    void DomainTableUI::set_selected(DomainID ca)
    {
        m_selected  = ca;
        mail(new DomainSelectEvent({}, ca));
    }

    void           DomainTableUI::tick()
    {
        UIElement::tick();
        const Frame* frame = Frame::current();
        if(!frame)
            return;
        
        std::set<DomainID>  domains = frame->ids<Domain>();
        
        for(auto itr = m_rows.begin(); itr != m_rows.end(); ){
            if(!domains.contains(itr->domain)){
                if(itr->domain == m_selected){
                    set_selected({});
                }
                itr = m_rows.erase(itr);
                continue;
            }
            
            domains.erase(itr->domain);
            ++itr;
        }
        
        for(DomainID c : domains){
            Row   en;
            en.domain        = c;
            en.info         = frame->meta(c);
            en.sid          = std::format("{}##{}.SELECT_ID", c.id, c.id);
            en.stype        = std::format("{}##{}.SELECT_TYPE", en.info->stem(), c.id);
            m_rows.push_back(en);
            
            if(!m_selected)
                set_selected(c);
        }
        
    }

    const char*    DomainTableUI::title() const 
    {
        return "Domains";
    }

}

YQ_OBJECT_IMPLEMENT(yq::tachyon::DomainTableUI)
