////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "FrameMetricsUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/api/ThreadData.hpp>
#include <yq/tachyon/ui/UIFormMetaWriter.hpp>

namespace yq::tachyon {
    void FrameMetricsUI::init_meta()
    {
        auto w = writer<FrameMetricsUI>();
        w.description("Metrics UI");
        w.field("FPS", &FrameMetricsUI::fps);
        w.field("Cycle Time", &FrameMetricsUI::cycle);
        w.field("Cameras", &FrameMetricsUI::cameras);
        w.field("Lights", &FrameMetricsUI::lights);
        w.field("Models", &FrameMetricsUI::models);
        w.field("Rendereds", &FrameMetricsUI::rendereds);
        w.field("Scenes", &FrameMetricsUI::scenes);
        w.field("Threads", &FrameMetricsUI::threads);
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
        
    void    FrameMetricsUI::cameras()
    {
        ImGui::Text(m_frame->count(CAMERA));
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

    void    FrameMetricsUI::lights()
    {
        ImGui::Text(m_frame->count(LIGHT));
    }

    void    FrameMetricsUI::models()
    {
        ImGui::Text(m_frame->count(MODEL));
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

    void    FrameMetricsUI::rendereds()
    {
        ImGui::Text(m_frame->count(RENDERED));
    }

    void    FrameMetricsUI::scenes()
    {
        ImGui::Text(m_frame->count(SCENE));
    }

    void    FrameMetricsUI::threads()
    {
        ImGui::Text(m_frame->count(THREAD));
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::FrameMetricsUI)
