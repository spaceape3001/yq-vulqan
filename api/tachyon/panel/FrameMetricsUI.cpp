////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "FrameMetricsUI.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/api/Thread.hpp>
#include <tachyon/api/ThreadData.hpp>
#include <tachyon/ui/UIFormMetaWriter.hpp>

namespace yq::tachyon {
    void FrameMetricsUI::init_info()
    {
        auto w = writer<FrameMetricsUI>();
        w.description("FrameMetrics UI");
        w.field("FPS", &FrameMetricsUI::fps);
    }
    
    FrameMetricsUI::FrameMetricsUI(UIFlags flags) : UIForm(flags)
    {
    }
    
    FrameMetricsUI::FrameMetricsUI(const FrameMetricsUI& cp) : UIForm(cp)
    {
    }
    
    FrameMetricsUI::~FrameMetricsUI()
    {
    }
        
    FrameMetricsUI* FrameMetricsUI::clone() const 
    {
        return new FrameMetricsUI(*this);
    }

    void    FrameMetricsUI::cycle()
    {
        ImGui::Text(unit::Millisecond(m_data->cycleTime).value);  ImGui::SameLine(); ImGui::TextUnformatted(" ms");
    }

    void    FrameMetricsUI::fps()
    {
        ImGui::Text(1.0 / unit::Second(m_data->cycleTime).value);
    }

    void    FrameMetricsUI::render()
    {
        m_frame = Frame::current();
        if(!m_frame)
            return;
        m_thread    = Thread::current();
        if(!m_thread)
            return;
        m_data      = m_frame->data(m_thread->id());
        if(!m_data) 
            return ;
        m_snap      = m_frame->snap(m_thread->id());
        if(!m_snap)
            return ;
        UIForm::render();
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::FrameMetricsUI)
