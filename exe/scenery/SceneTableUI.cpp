////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SceneTableUI.hpp"
#include "SceneEntry.hpp"

#include <tachyon/MyImGui.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/api/Scene.hpp>
#include <tachyon/api/SceneData.hpp>
#include <tachyon/gfx/Texture.hpp>
#include <tachyon/ui/UIElementInfoWriter.hpp>


void SceneEditor::ScenesTableUI::init_info()
{
    auto w = writer<ScenesTableUI>();
    w.description("Scene Editor's Scene Table");
}

// ................................

SceneEditor::ScenesTableUI::ScenesTableUI(UIFlags flags) : UIElement(flags)
{
}

SceneEditor::ScenesTableUI::ScenesTableUI(const ScenesTableUI& cp) : UIElement(cp)
{
}

SceneEditor::ScenesTableUI*   SceneEditor::ScenesTableUI::clone() const 
{
    return new ScenesTableUI(*this);
}

const char* SceneEditor::ScenesTableUI::title() const 
{
    return "Scenes";
}

void    SceneEditor::ScenesTableUI::render() 
{
    const Frame*    frame   = Frame::current();
    if(!frame){
        return ;
    }

    float   sz  = ImGui::GetFrameHeight() * 0.9;
    
    Size2F      imgBtnSize    = { sz, sz };
    
    if(!m_invisible)
        m_invisible = install(texture("openicon/icons/png/32x32/symbols/pictogram-din-p000-general.png"));
    if(!m_editing)
        m_editing   = install(texture("openicon/icons/png/32x32/symbols/pictogram-din-e001-direction-right.png"));
    if(!m_visible)
        m_visible   = install(texture("sdk/scenery/eyeball48.png"));
    
    SceneEditor*    editor  = dynamic_cast<SceneEditor*>(widget());
    if(!editor)
        return ;
        
    if(editor->m_scenes.empty())
        return;
        
    if(ImGui::BeginTable("Scenes", 5)){
        ImGui::TableNextRow(ImGuiTableRowFlags_Headers);
        ImGui::TableSetupColumn("", ImGuiTableColumnFlags_WidthFixed, sz*1.2);
        ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_WidthStretch, 0.1);
        ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthStretch, 0.3);
        ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthStretch, 0.4);
        ImGui::TableSetupColumn("Camera", ImGuiTableColumnFlags_WidthStretch, 0.2);
        ImGui::TableHeadersRow();

        for(SceneEntry& e : editor->m_scenes){
            bool    isEdit  = &e == editor->m_editing;
            bool    wantEdit    = false;
            const SceneSnap*    ss  = frame->snap(e.scene);
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
                } else {
                    if(e.flags(E::Invisible)){
                        if(m_invisible ? ImGui::ImageButton(e.invisBtn.c_str(), m_invisible, imgBtnSize) : ImGui::Button(e.invisBtn2.c_str())){
                            e.flags -= E::Invisible;
                            editor->m_flags |= F::Stale;
                        }
                    } else {
                        if(m_visible ? ImGui::ImageButton(e.visBtn.c_str(), m_visible, imgBtnSize) : ImGui::Button(e.visBtn2.c_str())){
                            e.flags |= E::Invisible;
                            editor->m_flags |= F::Stale;
                        }
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
                    sname   = std::format("(no-name)##{}.SELECT", e.scene.id); 
                } else
                   sname = std::format("{}##{}.SELECT", ss->name, e.scene.id); 

                if(ImGui::Selectable(sname.c_str(), isEdit) && !isEdit){
                    wantEdit    = true;
                }
            }
            
            if(wantEdit){
                if(e.flags(E::Invisible)){
                    e.flags -= E::Invisible;
                    editor->m_flags |= F::Stale;
                }
                editor->m_editing = &e;
            }

            if(ImGui::TableNextColumn()){
                //  TODO.....
            }
            
        }
        ImGui::EndTable();
    }
}

YQ_OBJECT_IMPLEMENT(SceneEditor::ScenesTableUI)

