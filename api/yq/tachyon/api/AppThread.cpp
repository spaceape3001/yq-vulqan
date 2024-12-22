////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/api/ThreadData.hpp>
#include <yq/tachyon/api/ThreadInfoWriter.hpp>
#include "AppThread.hpp"

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

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void AppThread::init_info()
    {
        auto w = writer<AppThread>();
        w.description("Application Thread");
    }
}
