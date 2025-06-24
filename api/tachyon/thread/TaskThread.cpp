////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/thread/TaskThread.hpp>

#include <tachyon/api/Thread.hpp>
#include <tachyon/api/ThreadData.hpp>
#include <tachyon/api/ThreadInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::TaskThread)

namespace yq::tachyon {
    TaskThread::TaskThread(const Param&p) : Thread(p)
    {
        m_name  = "TASK";
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
