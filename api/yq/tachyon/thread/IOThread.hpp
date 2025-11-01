////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Thread.hpp>

namespace yq::tachyon {
    class Application;

    class IOThread : public Thread {
        YQ_TACHYON_DECLARE(IOThread, Thread)
    public:
    
        IOThread(const Param&p = Param{});
        ~IOThread();
        
        static void init_meta();

    private:
        friend class Application;
        void        shutdown();
    };
}
