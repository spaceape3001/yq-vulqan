////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/app/TaskThread.hpp>

#include <yt/api/Thread.hpp>
#include <yt/api/ThreadData.hpp>
#include <yt/api/ThreadInfoWriter.hpp>

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
