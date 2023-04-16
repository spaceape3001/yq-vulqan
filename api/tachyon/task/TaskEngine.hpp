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

        void                add(Task*);
        
        Engine();
        ~Engine();
    
    private:
        std::vector<Task*>      m_tasks;
        //std::thread             m_taskThread;
        //bool                    m_quit;
    };
};

