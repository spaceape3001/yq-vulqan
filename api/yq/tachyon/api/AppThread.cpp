////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AppThread.hpp"

#include <yq/core/StreamOps.hpp>
#include <yq/stream/Logger.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/Context.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/ThreadData.hpp>
#include <yq/tachyon/api/ThreadInfoWriter.hpp>
#include <yq/tachyon/events/ViewerDestroyEvent.hpp>

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
    #if 0
        size_t  vc  = ctx.frame.count(VIEWER);
        if(vc && !m_quitOnZero){
            tachyonInfo << ident() << " now with viewers, quit-on-close activated";
            m_quitOnZero        = true;
        }
        if(m_quitOnZero && (vc == 0) && !missing()){
            #if 0
            {
                stream::Logger log(tachyonInfo);
                tachyonInfo << ident() << " all viewers closed, quitting\n";
                ctx.frame.report(log);
            }
            #endif
            quit();
        }
    #endif
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
