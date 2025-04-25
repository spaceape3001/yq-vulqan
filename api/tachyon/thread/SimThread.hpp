////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Thread.hpp>

namespace yq::tachyon {
    class Application;

    class SimThread : public Thread {
        YQ_TACHYON_DECLARE(SimThread, Thread)
    public:
    
        SimThread(const Param&p = Param{});
        ~SimThread();
        
        static void init_info();

    private:
        friend class Application;
        void        shutdown();
    };
}
