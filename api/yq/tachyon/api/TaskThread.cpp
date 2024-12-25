////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TaskThread.hpp"

#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/api/ThreadData.hpp>
#include <yq/tachyon/api/ThreadInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::TaskThread)

namespace yq::tachyon {
    TaskThread::TaskThread(const Param&p) : Thread(p)
    {
    }
    
    TaskThread::~TaskThread()
    {
    }
    
    void TaskThread::shutdown()
    {
        quit();
    }
    
    void TaskThread::init_info()
    {
        auto w = writer<TaskThread>();
        w.description("Task Thread");
    }
}
