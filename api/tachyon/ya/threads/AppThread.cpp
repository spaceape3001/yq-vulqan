////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/threads/AppThread.hpp>

#include <yq/core/StreamOps.hpp>
#include <yq/stream/Logger.hpp>
#include <yt/logging.hpp>
#include <yt/api/Context.hpp>
#include <yt/api/Frame.hpp>
#include <yt/api/ThreadData.hpp>
#include <yt/api/ThreadInfoWriter.hpp>
#include <ya/events/tachyon/DestroyEvent.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::AppThread)

namespace yq::tachyon {
    AppThread::AppThread(Application* app, const Param&p) : Thread(p), m_app(app)
    {
        Thread::s_current       = this;
    }
    
    AppThread::~AppThread()
    {
        Thread::s_current       = nullptr;
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
                quit();
            }
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void AppThread::init_info()
    {
        auto w = writer<AppThread>();
        w.description("Application Thread");
        w.slot(&AppThread::on_destroy_event);
    }
}
