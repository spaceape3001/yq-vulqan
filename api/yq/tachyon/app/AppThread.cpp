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
    AppThread::AppThread(const Param&p) : Thread(p)
    {
    }
    
    AppThread::~AppThread()
    {
    }
    
    void AppThread::init_info()
    {
        auto w = writer<AppThread>();
        w.description("Application Thread");
    }
}
