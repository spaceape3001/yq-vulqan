////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Thread.hpp>

namespace yq::tachyon {
    class Application;
    
    class AppThread : public Thread {
        YQ_TACHYON_DECLARE(AppThread, Thread)
    public:
        AppThread(Application*, const Param&p ={});
        ~AppThread();
        static void init_info();
    private:
        friend class Application;
        Application* const    m_app;
        
        void                shutdown();
    };
}
