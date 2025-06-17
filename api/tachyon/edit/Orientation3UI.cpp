////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Orientation3UI.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/api/TachyonData.hpp>
#include <tachyon/ui/UIEditorInfoWriter.hpp>
#include <tachyon/proxy/POrientation3.hpp>
#include <yq/vector/Quaternion3.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Orientation³UI)

namespace yq::tachyon {
    void Orientation³UI::init_info()
    {
        auto w = writer<Orientation³UI>();
        w.description("UIEditor for Orientation³");
        w.edits<POrientation³>();
        w.field("HPR", &Orientation³UI::hpr);
        w.field("Quaternion", &Orientation³UI::quaternion);
    }
    
    Orientation³UI::Orientation³UI(UIFlags flags)
    {
    }
    
    Orientation³UI::Orientation³UI(const Orientation³UI& cp) : UIEditor(cp)
    {
    }
    
    Orientation³UI* Orientation³UI::clone() const
    {
        return new Orientation³UI(*this);
    }

    void    Orientation³UI::hpr()
    {
        POrientation³* proxy   = snap()->proxy<POrientation³>();
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
            //if(ImGui::SpinDouble("", &heading, m_step, m_stepFast, "%.2f")){
            if(ImGui::InputDouble("##heading", &heading)){
                proxy->orientation(SET, HEADING, heading);
            }
            ImGui::TableNextColumn();
            //if(ImGui::SpinDouble("", &pitch, m_step, m_stepFast, "%.2f")){
            if(ImGui::InputDouble("##pitch", &pitch)){
                proxy->orientation(SET, PITCH, pitch);
            }
            ImGui::TableNextColumn();
            //if(ImGui::SpinDouble("", &roll, m_step, m_stepFast, "%.2f")){
            if(ImGui::InputDouble("##roll", &roll)){
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

    void    Orientation³UI::quaternion()
    {
        POrientation³* proxy   = snap()->proxy<POrientation³>();
        if(!proxy)
            return ;
            
        Quaternion3D    q   = proxy->orientation();
        
        if(ImGui::InputDouble("##orientation", q)){
            if(q.length²() <= 1e-12){
                q = IDENTITY;
            } else {
                q = ~q;
            }
            proxy -> orientation(SET, q);
        }
    }
}
