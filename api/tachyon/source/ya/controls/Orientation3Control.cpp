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

    void    Orientation³Control::imgui_(ViContext& ctx) 
    {
        if(ImGui::Begin("Orientation")){
            
        }
        ImGui::End();
        
    }

    void    Orientation³Control::reset()
    {
        m_proxy         = nullptr;
        m_orientation   = IDENTITY;
        m_heading       = Degree(ZERO);
        m_pitch         = Degree(ZERO);
        m_roll          = Degree(ZERO);
    }
    
    void        Orientation³Control::set_tachyon(TachyonID tid)
    {
        if(tid != m_tachyon){
            m_tachyon       = tid;
            m_info          = nullptr;
            reset();
        }
    }

    Execution   Orientation³Control::tick(Context&) 
    {
        const Frame*  frame = Frame::current();
        if(!frame)
            return {};
        
        m_proxy     = frame -> interface<POrientation³>(m_tachyon);
        if(!m_proxy)
            return {};
        
        if(!m_info){
            Tachyon*    obj = frame->object(m_tachyon);
            assert(obj);
            if(!obj)
                return {};
                
            m_info      = &obj->metaInfo();
        }
            
        m_orientation   = m_proxy->orientation();
        m_heading       = m_proxy->heading();
        m_pitch         = m_proxy->pitch();
        m_roll          = m_proxy->roll();
        return {};
    }
    
    void Orientation³Control::init_info()
    {
        auto w = writer<Orientation³Control>();
        w.imgui();
    }
}
