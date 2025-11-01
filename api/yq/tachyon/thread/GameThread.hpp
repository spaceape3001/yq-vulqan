////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Thread.hpp>

namespace yq::tachyon {
    class Application;

    class GameThread : public Thread {
        YQ_TACHYON_DECLARE(GameThread, Thread)
    public:
    
        GameThread(const Param&p = Param{});
        ~GameThread();
        
        static void init_meta();

    private:
        friend class Application;
        void        shutdown();
    };
}
