////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIFrameMetrics.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/api/ThreadData.hpp>
#include <yq/tachyon/im/text.hpp>
#include <yq/tachyon/ui/UIFormMetaWriter.hpp>

namespace yq::tachyon {
    void UIFrameMetrics::init_meta()
    {
        auto w = writer<UIFrameMetrics>();
        w.description("Metrics UI");
        w.field("FPS", &UIFrameMetrics::fps);
        w.field("Cycle Time", &UIFrameMetrics::cycle);
        w.field("Cameras", &UIFrameMetrics::cameras);
        w.field("Lights", &UIFrameMetrics::lights);
        w.field("Models", &UIFrameMetrics::models);
        w.field("Rendereds", &UIFrameMetrics::rendereds);
        w.field("Scenes", &UIFrameMetrics::scenes);
        w.field("Threads", &UIFrameMetrics::threads);
    }

    UIFrameMetrics::UIFrameMetrics(UIFlags flags) : UIForm(flags)
    {
    }

    UIFrameMetrics::UIFrameMetrics(const UIFrameMetrics& cp) : UIForm(cp)
    {
    }

    UIFrameMetrics::~UIFrameMetrics()
    {
    }
        
    void    UIFrameMetrics::cameras()
    {
        im::text(m_frame->count(CAMERA));
    }

    UIFrameMetrics* UIFrameMetrics::clone() const 
    {
        return new UIFrameMetrics(*this);
    }

    void    UIFrameMetrics::cycle()
    {
        im::text(unit::Millisecond(m_data->cycleTime).value);  ImGui::SameLine(); im::text(" ms");
    }

    void    UIFrameMetrics::fps()
    {
        im::text(1.0 / unit::Second(m_data->cycleTime));
    }

    void    UIFrameMetrics::lights()
    {
        im::text(m_frame->count(LIGHT));
    }

    void    UIFrameMetrics::models()
    {
        im::text(m_frame->count(MODEL));
    }

    void    UIFrameMetrics::render()
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

    void    UIFrameMetrics::rendereds()
    {
        im::text(m_frame->count(RENDERED));
    }

    void    UIFrameMetrics::scenes()
    {
        im::text(m_frame->count(SCENE));
    }

    void    UIFrameMetrics::threads()
    {
        im::text(m_frame->count(THREAD));
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIFrameMetrics)
