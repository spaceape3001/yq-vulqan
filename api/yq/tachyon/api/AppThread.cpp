////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AppThread.hpp"

#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/Context.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/ThreadData.hpp>
#include <yq/tachyon/api/ThreadInfoWriter.hpp>

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
        size_t  vc  = frame().count(VIEWER);
        if(vc && !m_quitOnZero){
            tachyonInfo << ident() << " now with viewers, quit-on-close activated";
            m_quitOnZero        = true;
        }
        if(m_quitOnZero && (vc == 0)){
            tachyonInfo << ident() << " all viewers closed, quitting";
            //quit();
        }
        return {};
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void AppThread::init_info()
    {
        auto w = writer<AppThread>();
        w.description("Application Thread");
    }
}
