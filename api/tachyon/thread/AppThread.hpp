////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Thread.hpp>
#include <tachyon/typedef/clock.hpp>

namespace yq::tachyon {
    class Application;
    class DestroyEvent;
    
    class AppThread : public Thread {
        YQ_TACHYON_DECLARE(AppThread, Thread)
    public:
        AppThread(Application*, const Param&p ={});
        ~AppThread();
        static void init_meta();
        
        using Thread::tick;
        
        virtual Execution subtick(const Context&) override;
        
        virtual void run();
        
    private:
        friend class Application;
        Application* const      m_app;
        int                     m_viewers   = 0;
        bool                    m_quitOnZero = false;
        
        void    on_destroy_event(const DestroyEvent&);
        
        void                    shutdown();
    };
}
