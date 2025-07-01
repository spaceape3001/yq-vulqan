////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Thread.hpp>

namespace yq::tachyon {
    class Application;

    class NetworkThread : public Thread {
        YQ_TACHYON_DECLARE(NetworkThread, Thread)
    public:
    
        NetworkThread(const Param&p = Param{});
        ~NetworkThread();
        
        static void init_meta();

    private:
        friend class Application;
        void        shutdown();
    };
}
