////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/task/Task.hpp>

#include <thread>

namespace yq::tachyon {
    class Task::Engine {
    public:
    
            //! Executes a full step of tasks
            //! \note This routine will BLOCK until all tasks are done.
        void                step();

            //! Adds a task that'll run as specified
        bool                add(Task*, ExecutionControl ec=ALWAYS);

            //! Adds a task that'll run at specified interval
        bool                add(Task*, skip_t, unsigned int iv=2);
        
        Engine();
        ~Engine();
    
    private:
        std::vector<Task*>      m_tasks;
//        std::vector<Task*>      m_deletes;
        //std::thread             m_taskThread;
        //bool                    m_quit;
        void                    execute(Task*, API&);
    };
};

