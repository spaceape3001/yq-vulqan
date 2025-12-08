////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ThreadTimeEditUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/api/ThreadData.hpp>
#include <yq/tachyon/command/sim/SetTimeCommand.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ThreadTimeEditUI)

namespace yq::tachyon {
    void ThreadTimeEditUI::init_meta()
    {
        auto w = writer<ThreadTimeEditUI>();
        w.description("Control for thread time");
    }

    ThreadTimeEditUI::ThreadTimeEditUI(StdThread st, UIFlags flags) : UIElement(flags), m_stdThread(st)
    {
    }
    
    ThreadTimeEditUI::ThreadTimeEditUI(const ThreadTimeEditUI&cp) : UIElement(cp), m_stdThread(cp.m_stdThread)
    {
    }
    
    ThreadTimeEditUI::~ThreadTimeEditUI()
    {
    }
    
    ThreadTimeEditUI* ThreadTimeEditUI::clone() const 
    {
        return new ThreadTimeEditUI(*this);
    }
    
    void ThreadTimeEditUI::render() 
    {
        const Frame*    f   = Frame::current();
        if(!f)
            return;
            
        if(!m_thread){
            m_thread    = Thread::standard(m_stdThread);
            if(!m_thread)
                return;
        }
        if(!m_sendTo){
            m_sendTo    = f->typed(m_thread);
            if(!m_sendTo)
                return;
        }
        
        const ThreadData* data  = f->data(m_thread);
        if(!data)
            return;
        
        static const ImGui::InputDoubleOptions kOptions = {
            .format = "%.4lf"
        };
        
        double  v   = data->time.value;
        if(ImGui::Input("##Time", v, kOptions))
            send(new SetTimeCommand({.target=m_sendTo}, v));
    }
}
