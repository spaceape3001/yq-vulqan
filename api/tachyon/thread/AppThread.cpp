////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/thread/AppThread.hpp>

#include <yq/core/StreamOps.hpp>
#include <yq/stream/Logger.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/api/Context.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/api/ThreadData.hpp>
#include <tachyon/api/ThreadMetaWriter.hpp>
#include <tachyon/app/Application.hpp>
#include <tachyon/event/tachyon/DestroyEvent.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::AppThread)

namespace yq::tachyon {
    AppThread::AppThread(Application* app, const Param&p) : Thread(p), m_app(app)
    {
        Thread::s_current       = this;
        m_name  = "APP";
    }
    
    AppThread::~AppThread()
    {
        Thread::s_current       = nullptr;
    }
    
    void AppThread::run()
    {
        Thread::run();
        
    }

    void AppThread::shutdown()
    {
        /* TODO */
    }

    Execution AppThread::subtick(const Context&ctx) 
    {
        return {};
    }

    void    AppThread::on_destroy_event(const DestroyEvent& evt)
    {
        if(evt.source()(Type::Viewer)){
            if(!--m_viewers){
                m_app -> shutting_down();
                cmd_teardown();
            }
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void AppThread::init_meta()
    {
        auto w = writer<AppThread>();
        w.description("Application Thread");
        w.slot(&AppThread::on_destroy_event);
    }
}
