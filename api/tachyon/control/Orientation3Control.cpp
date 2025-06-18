////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/control/Orientation3Control.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/proxy/POrientation3.hpp>
#include <tachyon/MyImGui.hpp>
#include <tachyon/api/ControlInfoWriter.hpp>
#include <yq/vector/Quaternion3.hxx>
#include <yq/util/Safety.hpp>
#include <tachyon/logging.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Orientation³Control)

namespace yq::tachyon {
    Orientation³Control::Orientation³Control(TachyonID tacID) : m_tachyon(tacID)
    {
        reset();
    }
    
    Orientation³Control::~Orientation³Control()
    {
    }


    void    Orientation³Control::imgui(ViContext& ctx) 
    {
        //if(!m_proxy)
            //return ;
            
        if(m_float){
            if(ImGui::BeginChild("Orientation³")){
                imgui_content();
                ImGui::EndChild();
            }
        } else {
            ImGui::Separator();
            ImGui::BeginGroup();
            imgui_content();
            ImGui::EndGroup();
            ImGui::Separator();
        }
    }

    void    Orientation³Control::imgui_content()
    {
        const Frame*  frame = Frame::current();
        if(!frame)
            return;
        
        POrientation³* proxy     = frame -> proxy<POrientation³>(m_tachyon);
        if(!proxy)
            return;
        
        Quaternion3D orientation   = proxy->orientation();
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
            if(ImGui::Input("##heading", heading)){
                proxy->orientation(SET, HEADING, heading);
            }
            ImGui::TableNextColumn();
            //if(ImGui::SpinDouble("", &pitch, m_step, m_stepFast, "%.2f")){
            if(ImGui::Input("##pitch", pitch)){
                proxy->orientation(SET, PITCH, pitch);
            }
            ImGui::TableNextColumn();
            //if(ImGui::SpinDouble("", &roll, m_step, m_stepFast, "%.2f")){
            if(ImGui::Input("##roll", roll)){
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
            
        if(ImGui::Input("##orientation", orientation)){
            if(orientation.length²() <= 1e-12){
                orientation = IDENTITY;
            } else {
                orientation = ~orientation;
            }
            proxy -> orientation(SET, orientation);
        }
    }

    void    Orientation³Control::reset()
    {
    }
    
    void        Orientation³Control::set_tachyon(TachyonID tid)
    {
        if(tid != m_tachyon){
            m_tachyon       = tid;
            m_info          = nullptr;
            reset();
        }
    }

    Execution   Orientation³Control::tick(const Context&) 
    {
        return {};
    }
    
    void Orientation³Control::init_info()
    {
        auto w = writer<Orientation³Control>();
        w.imgui();
    }
}
