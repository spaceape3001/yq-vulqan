////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Thread.hpp>

namespace yq::tachyon {
    class Application;

    class EditorThread : public Thread {
        YQ_TACHYON_DECLARE(EditorThread, Thread)
    public:
    
        EditorThread(const Param&p = Param{});
        ~EditorThread();
        
        static void init_info();

    private:
        friend class Application;
        void        shutdown();
    };
}
