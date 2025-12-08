////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ThreadOverclockEditUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/api/ThreadData.hpp>
#include <yq/tachyon/command/sim/SetOverclockCommand.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ThreadOverclockEditUI)

namespace yq::tachyon {
    void ThreadOverclockEditUI::init_meta()
    {
        auto w = writer<ThreadOverclockEditUI>();
        w.description("Control for thread overclock");
    }

    ThreadOverclockEditUI::ThreadOverclockEditUI(StdThread st, UIFlags flags) : UIElement(flags), m_stdThread(st)
    {
    }
    
    ThreadOverclockEditUI::ThreadOverclockEditUI(const ThreadOverclockEditUI&cp) : UIElement(cp), m_stdThread(cp.m_stdThread)
    {
    }
    
    ThreadOverclockEditUI::~ThreadOverclockEditUI()
    {
    }
    
    ThreadOverclockEditUI* ThreadOverclockEditUI::clone() const 
    {
        return new ThreadOverclockEditUI(*this);
    }
    
    void ThreadOverclockEditUI::render() 
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
        
        const ThreadSnap* snap  = f->snap(m_thread);
        if(!snap)
            return;
        
        static const ImGui::InputDoubleOptions kOptions = {
            .format = "%.4lf"
        };
        
        double  v   = snap->overclock;
        if(ImGui::Input("##Overclock", v, kOptions))
            send(new SetOverclockCommand({.target=m_sendTo}, v));
    }
}
