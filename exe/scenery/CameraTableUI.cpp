////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CameraTableUI.hpp"
#include "CameraEntry.hpp"

#include <tachyon/MyImGui.hpp>
#include <tachyon/api/Camera.hpp>
#include <tachyon/api/CameraData.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/gfx/Texture.hpp>
#include <tachyon/ui/UIElementInfoWriter.hpp>


void SceneEditor::CameraTableUI::init_info()
{
    auto w = writer<CameraTableUI>();
    w.description("Scene Editor's Camera Table");
}

SceneEditor::CameraTableUI::CameraTableUI(UIFlags flags) : UIElement(flags)
{
}

SceneEditor::CameraTableUI::CameraTableUI(const CameraTableUI& cp) : UIElement(cp)
{
}

SceneEditor::CameraTableUI*   SceneEditor::CameraTableUI::clone() const 
{
    return new CameraTableUI(*this);
}

const char*    SceneEditor::CameraTableUI::title() const 
{
    return "Cameras";
}

void    SceneEditor::CameraTableUI::render() 
{
    const Frame*    frame   = Frame::current();
    if(!frame)
        return ;

    float   sz  = ImGui::GetFrameHeight() * 0.9;
    
    Size2F      imgBtnSize    = { sz, sz };
    
    if(!m_editing)
        m_editing = install(texture("openicon/icons/png/32x32/symbols/pictogram-din-e001-direction-right.png"));

    SceneEditor*    editor  = dynamic_cast<SceneEditor*>(widget());
    if(!editor)
        return ;
        
    if(editor->m_camera.entries.empty())
        return;
        
    if(ImGui::BeginTable("Cameras", 4)){
        ImGui::TableSetupColumn("Editing", ImGuiTableColumnFlags_WidthFixed|ImGuiTableColumnFlags_NoHeaderLabel, sz*1.2);
        ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_WidthStretch, 0.1);
        ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthStretch, 0.3);
        ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthStretch, 0.4);
        ImGui::TableHeadersRow();

        for(CameraEntry& e : editor->m_camera.entries){
            bool    isEdit  = &e == editor->m_camera.editing;
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
                editor->_activate(e.camera);
            }
        }
        ImGui::EndTable();
    }
}

YQ_OBJECT_IMPLEMENT(SceneEditor::CameraTableUI)
