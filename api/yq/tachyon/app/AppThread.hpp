////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/typedef/clock.hpp>

namespace yq::tachyon {
    class Application;
    class ViewerDestroyEvent;
    
    class AppThread : public Thread {
        YQ_TACHYON_DECLARE(AppThread, Thread)
    public:
        AppThread(Application*, const Param&p ={});
        ~AppThread();
        static void init_info();
        
        using Thread::tick;
        
        virtual Execution subtick(Context&) override;
        
    private:
        friend class Application;
        Application* const      m_app;
        int                     m_viewers   = 0;
        bool                    m_quitOnZero = false;
        
        void    on_viewer_destroy_event(const ViewerDestroyEvent&);
        
        void                shutdown();
    };
}
