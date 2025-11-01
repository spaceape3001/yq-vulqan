////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/StdThread.hpp>
#include <yq/tachyon/typedef/thread.hpp>
#include <yq/tachyon/typedef/async_task.hpp>

namespace yq::tachyon {

    //!  These are meant as one-off task-at-a-time, basically turning the threads into
    //!  a task/thread pool
    class AsyncTask {
    public:
    
        virtual void    execute() = 0;

        AsyncTask(){}
        ~AsyncTask(){}
        
    private:
        //  outlaw copying & moving
        AsyncTask(const AsyncTask&) = delete;
        AsyncTask(AsyncTask&&) = delete;
        AsyncTask& operator=(const AsyncTask&) = delete;
        AsyncTask& operator=(AsyncTask&&) = delete;
    };
    
    void    schedule_this(StdThread, AsyncTaskUPtr&&);
    void    schedule_this(ThreadID, AsyncTaskUPtr&&);
}
