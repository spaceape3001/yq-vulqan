////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Thread.hpp>
#include <QAbstractEventDispatcher>
#include <QThread>

namespace yq::tachyon {
    template <SomeThread TH>
    class XThread : public QThread, public TH {
    public:
        
        XThread() : TH()
        {
            
        }
        
        ~XThread()
        {
        }
        
        void join() override
        {
            TH::quit();
            QThread::quit();
            QThread::wait();
        }
        
        void run() override
        {
            Thread::s_current   = this;
            if(QAbstractEventDispatcher* events = eventDispatcher()){
                events -> startingUp();
                while(!Thread::m_quit){
                    TH::tick();
                }
                events -> closingDown();
            }
            Thread::s_current   = nullptr;
        }
        
        void start() override
        {
            QThread::start();
        }
        
        Execution subtick(const Context&ctx) override
        {
            if(QAbstractEventDispatcher* events = eventDispatcher()){
                events->processEvents(QEventLoop::AllEvents);
            }
            return TH::subtick(ctx);
        }
        
    private:
        virtual void deleteMe() const 
        {
            const_cast<XThread*>(this) -> deleteLater();
        }
    };
}
