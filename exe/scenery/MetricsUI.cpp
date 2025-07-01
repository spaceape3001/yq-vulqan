////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MetricsUI.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/api/Thread.hpp>
#include <tachyon/api/ThreadData.hpp>
#include <tachyon/ui/UIFormMetaWriter.hpp>

void MetricsUI::init_info()
{
    auto w = writer<MetricsUI>();
    w.description("Metrics UI");
    w.field("FPS", &MetricsUI::fps);
    w.field("Cycle Time", &MetricsUI::cycle);
    w.field("Cameras", &MetricsUI::cameras);
    w.field("Lights", &MetricsUI::lights);
    w.field("Models", &MetricsUI::models);
    w.field("Rendereds", &MetricsUI::rendereds);
    w.field("Scenes", &MetricsUI::scenes);
    w.field("Threads", &MetricsUI::threads);
}

MetricsUI::MetricsUI(UIFlags flags) : UIForm(flags)
{
}

MetricsUI::MetricsUI(const MetricsUI& cp) : UIForm(cp)
{
}

MetricsUI::~MetricsUI()
{
}
    
void    MetricsUI::cameras()
{
    ImGui::Text(m_frame->count(CAMERA));
}

MetricsUI* MetricsUI::clone() const 
{
    return new MetricsUI(*this);
}

void    MetricsUI::cycle()
{
    ImGui::Text(unit::Millisecond(m_data->cycleTime).value);  ImGui::SameLine(); ImGui::TextUnformatted(" ms");
}

void    MetricsUI::fps()
{
    ImGui::Text(1.0 / unit::Second(m_data->cycleTime).value);
}

void    MetricsUI::lights()
{
    ImGui::Text(m_frame->count(LIGHT));
}

void    MetricsUI::models()
{
    ImGui::Text(m_frame->count(MODEL));
}

void    MetricsUI::render()
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

void    MetricsUI::rendereds()
{
    ImGui::Text(m_frame->count(RENDERED));
}

void    MetricsUI::scenes()
{
    ImGui::Text(m_frame->count(SCENE));
}

void    MetricsUI::threads()
{
    ImGui::Text(m_frame->count(THREAD));
}

YQ_OBJECT_IMPLEMENT(MetricsUI)
