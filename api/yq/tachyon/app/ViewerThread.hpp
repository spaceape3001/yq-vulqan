////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Thread.hpp>

namespace yq::tachyon {
    class Application;
    class Viewer;
    /*! \brief Viewer threads run viewers
        
        A viewer thread will own and run viewers (can be one, or more)
    */
    class ViewerThread : public Thread {
        YQ_TACHYON_DECLARE(ViewerThread, Thread)
    public:
    
        struct Param : public Thread::Param {
            Viewer*     viewer  = nullptr;
            
            Param(){}
        };
    
        ViewerThread(const Param&p = Param());
        ~ViewerThread();
        static void init_info();
        
    private:
        friend class Application;
        void        shutdown();
    };
}
