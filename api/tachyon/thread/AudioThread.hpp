////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Thread.hpp>

namespace yq::tachyon {
    class Application;

    class AudioThread : public Thread {
        YQ_TACHYON_DECLARE(AudioThread, Thread)
    public:
    
        AudioThread(const Param&p = Param{});
        ~AudioThread();
        
        static void init_meta();

    private:
        friend class Application;
        void        shutdown();
    };
}
