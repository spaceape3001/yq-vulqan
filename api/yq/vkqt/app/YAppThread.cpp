////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "YAppThread.hpp"
#include "YMain.hpp"
#include <yq/tachyon/api/ThreadMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::YAppThread)

/*
    12 Jan 2026
    Known bug... crashes/segfault on exit with 

    1768214629 WARN qt : QThreadStorage: entry 1 destroyed before end of thread 0x7f11ef957630 (??:0, ??)

    Could be a prebaked on-exit type of routine.  Not sure how to avoid, as I've tried leaking the pointer 
    to keep destruction from happening, still not fixing.
    
    NOTE: Check QGuiApplication & QApplication for cleanup steps.
*/

namespace yq::tachyon {
    YAppThread::YAppThread(int& argc, char* argv[], tachyon::Application& app) : 
        gluon::Application(argc, argv), AppThread(app)
    {
    }
    
    YAppThread::~YAppThread()
    {
    }

    void    YAppThread::add(YMain& ym)
    {
        ym.subscribe(id());
        add(ym.id());
    }

    void    YAppThread::deleteMe() const
    {
        const_cast<YAppThread*>(this) -> deleteLater();
    }

    void    YAppThread::join()
    {
        //  doesn't quite make sense...
        AppThread::quit();
        gluon::Application::quit();
    }

    void    YAppThread::run()
    {
        Thread::s_current   = this;
        if(QAbstractEventDispatcher* events = eventDispatcher()){
            events -> startingUp();
            while(!Thread::m_quit){
                AppThread::tick();
            }
            gluon::Application::quit();
            events -> closingDown();
        }
        Thread::s_current   = nullptr;
    }

    Execution YAppThread::subtick(const Context&ctx) 
    {
        if(QAbstractEventDispatcher* events = eventDispatcher()){
            events->processEvents(QEventLoop::AllEvents | QEventLoop::ApplicationExec);
        }
        return AppThread::subtick(ctx);
    }
}

#include "moc_YAppThread.cpp"
