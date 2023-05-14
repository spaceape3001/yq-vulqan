////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/task/Task.hpp>

#include <thread>
#include <functional>

namespace yq::tachyon {
    class TaskEngine {
    public:
    
            //! Executes a full step of tasks
            //! \note This routine will BLOCK until all tasks are done.
        void                step();

            //! Executes a full step of tasks
            //! \note This routine will BLOCK until all tasks are done.
        void                step(TaskAPI&);

            //! Adds a task that'll run as specified
        bool                add(Task*, TaskExecutionControl ec=ALWAYS);

            //! Adds a task that'll run at specified interval
        bool                add(Task*, skip_t, unsigned int iv=2);
        
            //! Adds a single-shot task that'll run once
        //bool                once(std::function<void()>);
        
        TaskEngine();
        ~TaskEngine();
    
    private:
        std::vector<Task*>      m_tasks;
//        std::vector<Task*>      m_deletes;
        //std::thread             m_taskThread;
        void                    execute(Task*, TaskAPI&);
    };
};

