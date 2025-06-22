////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CameraTableUI.hpp"
#include "CameraSelectEvent.hpp"

#include <tachyon/MyImGui.hpp>
#include <tachyon/api/Camera.hpp>
#include <tachyon/api/CameraData.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/gfx/Texture.hpp>
#include <tachyon/ui/UIElementInfoWriter.hpp>


struct CameraTableUI::Row {
    CameraID            camera;
    const CameraInfo*   info        = nullptr;
    std::string         sid;        // ID for selectable
    std::string         stype;
};

void CameraTableUI::init_info()
{
    auto w = writer<CameraTableUI>();
    w.description("Scene Editor's Camera Table");
}

CameraTableUI::CameraTableUI(UIFlags flags) : UIElement(flags)
{
}

CameraTableUI::CameraTableUI(const CameraTableUI& cp) : UIElement(cp)
{
}

CameraTableUI*   CameraTableUI::clone() const 
{
    return new CameraTableUI(*this);
}


void    CameraTableUI::render() 
{
    const Frame*    frame   = Frame::current();
    if(!frame)
        return ;
    update_table(*frame);

    float   sz  = ImGui::GetFrameHeight() * 0.9;
    
    Size2F      imgBtnSize    = { sz, sz };
    
    if(!m_editing)
        m_editing = install(texture("openicon/icons/png/32x32/symbols/pictogram-din-e001-direction-right.png"));
        
    if(ImGui::BeginTable("Cameras", 4)){
        ImGui::TableSetupColumn("Editing", ImGuiTableColumnFlags_WidthFixed|ImGuiTableColumnFlags_NoHeaderLabel, sz*1.2);
        ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_WidthStretch, 0.1);
        ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthStretch, 0.3);
        ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthStretch, 0.4);
        ImGui::TableHeadersRow();

        for(Row& e : m_rows){
            bool    isEdit  = (e.camera == m_selected);
            bool    wantEdit    = false;
            const CameraSnap*    ss  = frame->snap(e.camera);
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
                    sname   = std::format("(no-name)##{}.SELECT", e.camera.id); 
                } else
                   sname = std::format("{}##{}.SELECT", ss->name, e.camera.id); 

                if(ImGui::Selectable(sname.c_str(), isEdit) && !isEdit){
                    wantEdit    = true;
                }
            }
            
            if(wantEdit){
                mail(new CameraSelectEvent({}, e.camera));
                m_selected  = e.camera;
            }
        }
        ImGui::EndTable();
    }
}

void CameraTableUI::set_selected(CameraID ca)
{
    m_selected  = ca;
}

const char*    CameraTableUI::title() const 
{
    return "Cameras";
}

void           CameraTableUI::update_table(const Frame& frame)
{
    std::set<CameraID>  cameras = frame.ids(CAMERA);
    
    for(auto itr = m_rows.begin(); itr != m_rows.end(); ){
        if(!cameras.contains(itr->camera)){
            if(itr->camera == m_selected)
                m_selected  = {};
            itr = m_rows.erase(itr);
            continue;
        }
        
        cameras.erase(itr->camera);
        ++itr;
    }
    
    for(CameraID c : cameras){
        Row   en;
        en.camera       = c;
        en.info         = frame.info(c);
        en.sid          = std::format("{}##{}.SELECT_ID", en.camera.id, en.camera.id);
        en.stype        = std::format("{}##{}.SELECT_TYPE", en.info->stem(), en.camera.id);
        m_rows.push_back(en);
        
        if(!m_selected)
            m_selected  = c;
    }
    
}

YQ_OBJECT_IMPLEMENT(CameraTableUI)
