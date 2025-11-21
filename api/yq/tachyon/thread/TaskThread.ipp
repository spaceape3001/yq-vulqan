////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/thread/TaskThread.hpp>

#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/api/ThreadData.hpp>
#include <yq/tachyon/api/ThreadMetaWriter.hpp>

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
    
    void TaskThread::init_meta()
    {
        auto w = writer<TaskThread>();
        w.description("Task Thread");
    }
}
