////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "YAppThread.hpp"
#include "YMain.hpp"
#include <yq/tachyon/api/ThreadMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::YAppThread)

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
        while(!Thread::m_quit){
            AppThread::tick();
        }
        Thread::s_current   = nullptr;
    }

    Execution YAppThread::subtick(const Context&ctx) 
    {
        if(QAbstractEventDispatcher* events = eventDispatcher()){
            events->processEvents(QEventLoop::AllEvents);
        }
        return AppThread::subtick(ctx);
    }
}

#include "moc_YAppThread.cpp"
