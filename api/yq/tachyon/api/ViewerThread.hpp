////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Thread.hpp>

namespace yq::tachyon {
    class Application;
    /*! \brief Viewer threads run viewers
        
        A viewer thread will own and run viewers (can be one, or more)
    */
    class ViewerThread : public Thread {
        YQ_TACHYON_DECLARE(ViewerThread, Thread)
    public:
        ViewerThread(const Param&p ={});
        ~ViewerThread();
        static void init_info();
        
    private:
        friend class Application;
        void    shutdown();
    };
}
