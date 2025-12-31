////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ControllerTableUI.hpp"

#include <yq/scenevk/event/ControllerSelectEvent.hpp>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/texture.hpp>
#include <yq/tachyon/api/Controller.hpp>
#include <yq/tachyon/api/ControllerData.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>


struct ControllerTableUI::Row {
    ControllerID            controller;
    const ControllerMeta*   info        = nullptr;
    std::string        sid;        // ID for selectable
    std::string        stype;
};

void ControllerTableUI::init_meta()
{
    auto w = writer<ControllerTableUI>();
    w.description("Scene Editor's Controller Table");
}

ControllerTableUI::ControllerTableUI(UIFlags flags) : UIElement(flags)
{
}

ControllerTableUI::ControllerTableUI(const ControllerTableUI& cp) : UIElement(cp)
{
}

ControllerTableUI*   ControllerTableUI::clone() const 
{
    return new ControllerTableUI(*this);
}


void    ControllerTableUI::render() 
{
    const Frame*    frame   = Frame::current();
    if(!frame)
        return ;

    float   sz  = ImGui::GetFrameHeight() * 0.9;
    
    Size2F      imgBtnSize    = { sz, sz };
    
    if(!m_editing)
        m_editing = install(texture("openicon/icons/png/32x32/symbols/pictogram-din-e001-direction-right.png"));
        
    if(ImGui::BeginTable("Controllers", 4)){
        ImGui::TableSetupColumn("Editing", ImGuiTableColumnFlags_WidthFixed|ImGuiTableColumnFlags_NoHeaderLabel, sz*1.2);
        ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_WidthStretch, 0.1);
        ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthStretch, 0.3);
        ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthStretch, 0.4);
        ImGui::TableHeadersRow();

        for(Row& e : m_rows){
            bool    isEdit  = (e.controller == m_selected);
            bool    wantEdit    = false;
            const ControllerSnap*    ss  = frame->snap(e.controller);
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
                    sname   = std::format("(no-name)##{}.SELECT", e.controller.id); 
                } else
                   sname = std::format("{}##{}.SELECT", ss->name, e.controller.id); 

                if(ImGui::Selectable(sname.c_str(), isEdit) && !isEdit){
                    wantEdit    = true;
                }
            }
            
            if(wantEdit)
                set_selected(e.controller);
        }
        ImGui::EndTable();
    }
}

void ControllerTableUI::set_selected(ControllerID ca)
{
    m_selected  = ca;
    mail(new ControllerSelectEvent({}, ca));
}

void           ControllerTableUI::tick()
{
    UIElement::tick();
    const Frame* frame = Frame::current();
    if(!frame)
        return;
        
    std::set<ControllerID>  controllers = frame->ids(CONTROLLER);
    
    for(auto itr = m_rows.begin(); itr != m_rows.end(); ){
        if(!controllers.contains(itr->controller)){
            if(itr->controller == m_selected){
                set_selected({});
            }
            itr = m_rows.erase(itr);
            continue;
        }
        
        controllers.erase(itr->controller);
        ++itr;
    }
    
    for(ControllerID c : controllers){
        Row   en;
        en.controller       = c;
        en.info         = frame->meta(c);
        en.sid          = std::format("{}##{}.SELECT_ID", c.id, c.id);
        en.stype        = std::format("{}##{}.SELECT_TYPE", en.info->stem(), c.id);
        m_rows.push_back(en);
        
        if(!m_selected)
            set_selected(c);
    }
    
}


const char*    ControllerTableUI::title() const 
{
    return "Controllers";
}
YQ_OBJECT_IMPLEMENT(ControllerTableUI)
