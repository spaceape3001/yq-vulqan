////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "AppThread.hpp"

#include <yq/core/StreamOps.hpp>
#include <yq/stream/Logger.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/Context.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/ThreadData.hpp>
#include <yq/tachyon/api/ThreadMetaWriter.hpp>
#include <yq/tachyon/api/Widget.hpp>
#include <yq/tachyon/app/Application.hpp>
#include <yq/tachyon/app/Viewer.hpp>
#include <yq/tachyon/command/app/ViewerCreateCommand.hpp>
#include <yq/tachyon/event/tachyon/DestroyEvent.hpp>
#include <yq/tachyon/os/Desktop.hpp>
#include <yq/tachyon/os/Window.hpp>
#include <yq/tachyon/thread/ViewerThread.hpp>

#include <yq/tachyon/api/Tachyon.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::AppThread)

namespace yq::tachyon {
    struct AppThread::WinStart {
        ThreadID                thread;
        uint64_t                ticks       = 0;
        Viewer*                 viewer      = nullptr;
        ViewerID                viewerID;
        WidgetPtr               widget;
        Window*                 window      = nullptr;
    };

    AppThread::AppThread(Application& app, const Param&p) : Thread(p), m_app(app)
    {
        Thread::s_current       = this;
        m_name  = "APP";
    }
    
    AppThread::~AppThread()
    {
        Thread::s_current       = nullptr;
    }

    void AppThread::add(TachyonID t)
    {
        m_others.insert(t);
    }
    
    void AppThread::create(viewer_k, const ViewerCreateInfo& vci, WidgetPtr wid)
    {
        mail(new ViewerCreateCommand({}, vci, wid));
    }

    ViewerID    AppThread::create_viewer(const ViewerCreateInfo& vci, WidgetPtr wid)
    {
        m_winStarts.push_back({.widget=wid});
        auto& win   = m_winStarts.back();

        if(!m_app.m_desktop){
            tachyonAlert << "Unable to create a viewer without a valid desktop.";
            return {};
        }
        win.window  = m_app.m_desktop->create(WINDOW, vci);
        if(!win.window){
            tachyonError << "Window creation failed, so no viewer.";
            return {};
        }

        if(m_app.m_thread.viewer){
            win.thread  = m_app.m_thread.viewer->id();
        } else if(std::get_if<per_k>(&m_app.m_cInfo.thread.viewer.enable)){
            do {
                Ref<ViewerThread>   tt;
                if(m_app.m_cInfo.thread.viewer.create){
                    tt  = (m_app.m_cInfo.thread.viewer.create)(m_app);
                    if(!tt){
                        tachyonCritical << "Unable to create viewer thread (it'll default to app-thread)!";
                        break;
                    }
                } else 
                    tt = new ViewerThread;
                m_app.m_thread.viewers.push_back(tt);
                tt -> start();
                win.thread = tt->id();
                m_app.m_threads.push_back(tt);
            } while(false);
        } else {
            win.thread      = Thread::standard(VIEWER);
        }


        win.viewer  = Tachyon::create<Viewer>(win.window, wid.ptr(), vci);
        m_viewers.insert(win.viewer->id());
        
        // viewer <-> app thread
        win.viewer->subscribe(id());    
        subscribe(win.viewer->id());  
        
        // viewer <-> window
        win.window->subscribe(win.viewer->id());
        win.viewer->subscribe(win.window->id());
        
        return win.viewer->id();
    }

    void AppThread::run()
    {
        Thread::run();
        
    }

    void AppThread::shutdown()
    {
        /* TODO */
    }

    Execution AppThread::subtick(const Context&ctx) 
    {
        for(auto itr = m_winStarts.begin(); itr != m_winStarts.end();){
            if(subtick_done(*itr)){
                itr = m_winStarts.erase(itr);
            } else {
                ++itr;
            }
        }
        
        return {};
    }

    bool    AppThread::subtick_done(WinStart& win)
    {
        if(++win.ticks <= 2)
            return false;
        if(win.viewer->starting())
            return false;

        if((win.thread != m_app.m_thread.app->id()) && (win.viewer->owner() != win.thread)){
            win.widget->owner(PUSH, win.thread);
            win.viewer->owner(PUSH, win.thread);
        }

        return true;
    }

    void    AppThread::on_destroy_event(const DestroyEvent& evt)
    {
        TypedID     source  = evt.source();
        if(source(Type::Viewer)){
            m_viewers.erase((ViewerID) source);
        } else {
            m_others.erase({source.id});
        }
        if(m_viewers.empty() && m_others.empty()){
            tachyonNotice << "AppThread: Viewers & likewise dropped to zero, shutting down";
            m_app.shutting_down();
            cmd_teardown();
        }
    }

    void    AppThread::on_viewer_create_command(const ViewerCreateCommand& cmd)
    {
        create_viewer(cmd.create_info(), cmd.widget());
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void AppThread::init_meta()
    {
        auto w = writer<AppThread>();
        w.description("Application Thread");
        w.slot(&AppThread::on_destroy_event);
        w.slot(&AppThread::on_viewer_create_command);
    }
}
