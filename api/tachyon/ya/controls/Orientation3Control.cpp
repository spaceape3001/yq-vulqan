////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/controls/Orientation3Control.hpp>
#include <yt/api/Frame.hpp>
#include <ya/proxies/POrientation3.hpp>
#include <yt/ui/MyImGui.hpp>
#include <yt/ui/ControlInfoWriter.hpp>

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
            ImGui::BeginGroup();
            imgui_content();
            ImGui::EndGroup();
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

        bool    changed = false;
    
        changed = ImGui::InputDouble("Heading", &heading.value) || changed;
        changed = ImGui::InputDouble("Pitch", &pitch.value) || changed;
        changed = ImGui::InputDouble("Roll", &roll.value) || changed;
            
        if(changed){
            proxy -> orientation(SET, HPR, heading, pitch, roll);
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
