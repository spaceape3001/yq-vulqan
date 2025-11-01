////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/typedef/clock.hpp>
#include <yq/tachyon/typedef/viewer.hpp>
#include <yq/tachyon/typedef/widget.hpp>

namespace yq::tachyon {
    class Application;
    class DestroyEvent;
    class ViewerCreateCommand;
    class Desktop;
    class VulqanManager;
    
    class AppThread : public Thread {
        YQ_TACHYON_DECLARE(AppThread, Thread)
    public:
        AppThread(Application&, const Param&p ={});
        ~AppThread();
        static void init_meta();
        
        using Thread::tick;
        
        virtual Execution subtick(const Context&) override;
        
        virtual void run();
        
        void        create(viewer_k, const ViewerCreateInfo&, WidgetPtr);
        
    private:
        void        on_viewer_create_command(const ViewerCreateCommand&);
        
    private:
        friend class Application;

        struct WinStart;
        
        Application&            m_app;
        bool                    m_quitOnZero    = false;
        std::vector<WinStart>   m_winStarts;
        std::set<ViewerID>      m_viewers;

        ViewerID    create_viewer(const ViewerCreateInfo&, WidgetPtr);
        
        void        on_destroy_event(const DestroyEvent&);
        
        bool        subtick_done(WinStart&);
        
        void        shutdown();
    };
}
