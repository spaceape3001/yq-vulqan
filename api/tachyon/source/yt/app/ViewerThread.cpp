////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/app/ViewerThread.hpp>

#include <yt/logging.hpp>
#include <yt/api/Thread.hpp>
#include <yt/api/ThreadData.hpp>
#include <yt/api/ThreadInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::ViewerThread)

namespace yq::tachyon {
    ViewerThread::ViewerThread(const Param&p) : Thread(p)
    {
        tachyonInfo << ident() << " constructed";
    }
    
    ViewerThread::~ViewerThread()
    {
        tachyonInfo << ident() << " destroyed";
    }
    
    void    ViewerThread::shutdown()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerThread::init_info()
    {
        auto w = writer<ViewerThread>();
        w.description("Viewer Thread");
    }
}