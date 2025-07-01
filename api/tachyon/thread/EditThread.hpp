////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Thread.hpp>

namespace yq::tachyon {
    class Application;

    class EditThread : public Thread {
        YQ_TACHYON_DECLARE(EditThread, Thread)
    public:
    
        EditThread(const Param&p = Param{});
        ~EditThread();
        
        static void init_meta();

    private:
        friend class Application;
        void        shutdown();
    };
}
