////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/app/AppThread.hpp>

#include <yq/core/StreamOps.hpp>
#include <yq/stream/Logger.hpp>
#include <yt/logging.hpp>
#include <yt/api/Context.hpp>
#include <yt/api/Frame.hpp>
#include <yt/api/ThreadData.hpp>
#include <yt/api/ThreadInfoWriter.hpp>
#include <ya/events/ViewerDestroyEvent.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::AppThread)

namespace yq::tachyon {
    AppThread::AppThread(Application* app, const Param&p) : Thread(p), m_app(app)
    {
        Thread::s_current       = this;
        tachyonInfo << ident() << " constructed";
    }
    
    AppThread::~AppThread()
    {
        Thread::s_current       = nullptr;
        tachyonInfo << ident() << " destroyed";
    }
    
    void AppThread::shutdown()
    {
        /* TODO */
    }

    Execution AppThread::subtick(Context&ctx) 
    {
        return {};
    }

    void    AppThread::on_viewer_destroy_event(const ViewerDestroyEvent&)
    {
        tachyonInfo << "AppThread::on_viewer_destroy_event";
        if(!--m_viewers){
            quit();
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void AppThread::init_info()
    {
        auto w = writer<AppThread>();
        w.description("Application Thread");
        w.slot(&AppThread::on_viewer_destroy_event);
    }
}
