////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Orientation3DUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_double.hpp>
#include <yq/tachyon/im/input_scaled_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/POrientation3D.hpp>
#include <yq/vector/Quaternion3.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Orientation³DUI)

namespace yq::tachyon {
    void Orientation³DUI::init_meta()
    {
        auto w = writer<Orientation³DUI>();
        w.description("UIEditor for Orientation³");
        w.edits<POrientation³D>();
        w.field("HPR", &Orientation³DUI::hpr);
        w.field("Quaternion", &Orientation³DUI::quaternion);
    }
    
    Orientation³DUI::Orientation³DUI(UIFlags flags)
    {
    }
    
    Orientation³DUI::Orientation³DUI(const Orientation³DUI& cp) : UIEditor(cp)
    {
    }
    
    Orientation³DUI* Orientation³DUI::clone() const
    {
        return new Orientation³DUI(*this);
    }

    void    Orientation³DUI::hpr()
    {
        POrientation³D* proxy   = snap()->proxy<POrientation³D>();
        if(!proxy)
            return ;

        Degree heading       = proxy->heading();
        Degree pitch         = proxy->pitch();
        Degree roll          = proxy->roll();

        if(ImGui::BeginTable("HPR", 3)){
            ImGui::TableSetupColumn("Hdg");
            ImGui::TableSetupColumn("Pitch");
            ImGui::TableSetupColumn("Roll");
            ImGui::TableHeadersRow();
            
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            if(ImGui::ArrowButton("+Yaw", ImGuiDir_Up)){
                proxy->orientation(ROTATE,YAW,m_stepFast);
            }
            ImGui::TableNextColumn();
            if(ImGui::ArrowButton("+Pitch", ImGuiDir_Up)){
                proxy->orientation(ROTATE,PITCH,m_stepFast);
            }
            ImGui::TableNextColumn();
            if(ImGui::ArrowButton("+Roll", ImGuiDir_Up)){
                proxy->orientation(ROTATE,ROLL,m_stepFast);
            }

            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            if(im::input("##heading", heading)){
                proxy->orientation(SET, HEADING, heading);
            }
            ImGui::TableNextColumn();
            //if(ImGui::SpinDouble("", &pitch, m_step, m_stepFast, "%.2f")){
            if(im::input("##pitch", pitch)){
                proxy->orientation(SET, PITCH, pitch);
            }
            ImGui::TableNextColumn();
            //if(ImGui::SpinDouble("", &roll, m_step, m_stepFast, "%.2f")){
            if(im::input("##roll", roll)){
                proxy->orientation(SET, ROLL, roll);
            }

            
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            if(ImGui::ArrowButton("-Yaw", ImGuiDir_Down)){
                proxy->orientation(ROTATE,YAW,-m_stepFast);
            }
            ImGui::TableNextColumn();
            if(ImGui::ArrowButton("-Pitch", ImGuiDir_Down)){
                proxy->orientation(ROTATE,PITCH,-m_stepFast);
            }
            ImGui::TableNextColumn();
            if(ImGui::ArrowButton("-Roll", ImGuiDir_Down)){
                proxy->orientation(ROTATE,ROLL,-m_stepFast);
            }
            
            
            ImGui::EndTable();
        }
    }

    void    Orientation³DUI::quaternion()
    {
        POrientation³D* proxy   = snap()->proxy<POrientation³D>();
        if(!proxy)
            return ;
            
        Quaternion3D    q   = proxy->orientation();
        
        if(im::input("##orientation", q)){
            if(q.length²() <= 1e-12){
                q = IDENTITY;
            } else {
                q = ~q;
            }
            proxy -> orientation(SET, q);
        }
    }
}
