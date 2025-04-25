////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Thread.hpp>

namespace yq::tachyon {
    class Application;

    class TaskThread : public Thread {
        YQ_TACHYON_DECLARE(TaskThread, Thread)
    public:
    
        TaskThread(const Param&p = Param{});
        ~TaskThread();
        
        static void init_info();

    private:
        friend class Application;
        void        shutdown();
    };
}
