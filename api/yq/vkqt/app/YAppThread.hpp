////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/app/Application.hpp>
#include <yq/tachyon/thread/AppThread.hpp>
#include <yq/gluon/app/Application.hpp>

namespace yq::tachyon {
    class YMain;
    class YAppThread : public gluon::Application, public AppThread {
        YQ_TACHYON_DECLARE(YAppThread, AppThread)
        Q_OBJECT
    public:
        YAppThread(int&, char*[], tachyon::Application&);
        ~YAppThread();
      
        void    run() override;
        void    join() override;

        Execution subtick(const Context&ctx) override;
        
        using AppThread::finalize;
        
        void    add(YMain&);
        
    protected:
        using AppThread::add;
        void    deleteMe() const override;
    };
}

