////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Thread.hpp>

namespace yq::tachyon {
    class Application;

    class AuxillaryThread : public Thread {
        YQ_TACHYON_DECLARE(AuxillaryThread, Thread)
    public:
    
        AuxillaryThread(const Param&p = Param{});
        ~AuxillaryThread();
        
        static void init_info();

    private:
        friend class Application;
        void        shutdown();
    };
}
