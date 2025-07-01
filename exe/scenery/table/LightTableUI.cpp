////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LightTableUI.hpp"
#include "event/LightSelectEvent.hpp"

#include <tachyon/MyImGui.hpp>
#include <tachyon/api/Light.hpp>
#include <tachyon/api/LightData.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/gfx/Texture.hpp>
#include <tachyon/ui/UIElementMetaWriter.hpp>


struct LightTableUI::Row {
    LightID            light;
    const LightMeta*   info        = nullptr;
    std::string        sid;        // ID for selectable
    std::string        stype;
};

void LightTableUI::init_info()
{
    auto w = writer<LightTableUI>();
    w.description("Scene Editor's Light Table");
}

LightTableUI::LightTableUI(UIFlags flags) : UIElement(flags)
{
}

LightTableUI::LightTableUI(const LightTableUI& cp) : UIElement(cp)
{
}

LightTableUI*   LightTableUI::clone() const 
{
    return new LightTableUI(*this);
}


void    LightTableUI::render() 
{
    const Frame*    frame   = Frame::current();
    if(!frame)
        return ;

    float   sz  = ImGui::GetFrameHeight() * 0.9;
    
    Size2F      imgBtnSize    = { sz, sz };
    
    if(!m_editing)
        m_editing = install(texture("openicon/icons/png/32x32/symbols/pictogram-din-e001-direction-right.png"));
        
    if(ImGui::BeginTable("Lights", 4)){
        ImGui::TableSetupColumn("Editing", ImGuiTableColumnFlags_WidthFixed|ImGuiTableColumnFlags_NoHeaderLabel, sz*1.2);
        ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_WidthStretch, 0.1);
        ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthStretch, 0.3);
        ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthStretch, 0.4);
        ImGui::TableHeadersRow();

        for(Row& e : m_rows){
            bool    isEdit  = (e.light == m_selected);
            bool    wantEdit    = false;
            const LightSnap*    ss  = frame->snap(e.light);
            if(!ss)
                continue;

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                if(isEdit){
                    if(m_editing){
                        ImGui::ImageWithBg(m_editing, imgBtnSize);
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
                    sname   = std::format("(no-name)##{}.SELECT", e.light.id); 
                } else
                   sname = std::format("{}##{}.SELECT", ss->name, e.light.id); 

                if(ImGui::Selectable(sname.c_str(), isEdit) && !isEdit){
                    wantEdit    = true;
                }
            }
            
            if(wantEdit)
                set_selected(e.light);
        }
        ImGui::EndTable();
    }
}

void LightTableUI::set_selected(LightID ca)
{
    m_selected  = ca;
    mail(new LightSelectEvent({}, ca));
}

void           LightTableUI::tick()
{
    UIElement::tick();
    const Frame* frame = Frame::current();
    if(!frame)
        return;
    
    std::set<LightID>  lights = frame->ids(LIGHT);
    
    for(auto itr = m_rows.begin(); itr != m_rows.end(); ){
        if(!lights.contains(itr->light)){
            if(itr->light == m_selected){
                set_selected({});
            }
            itr = m_rows.erase(itr);
            continue;
        }
        
        lights.erase(itr->light);
        ++itr;
    }
    
    for(LightID c : lights){
        Row   en;
        en.light        = c;
        en.info         = frame->meta(c);
        en.sid          = std::format("{}##{}.SELECT_ID", c.id, c.id);
        en.stype        = std::format("{}##{}.SELECT_TYPE", en.info->stem(), c.id);
        m_rows.push_back(en);
        
        if(!m_selected)
            set_selected(c);
    }
    
}

const char*    LightTableUI::title() const 
{
    return "Lights";
}



YQ_OBJECT_IMPLEMENT(LightTableUI)
