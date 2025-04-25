////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/thread/ViewerThread.hpp>

#include <yt/logging.hpp>
#include <tachyon/api/Thread.hpp>
#include <tachyon/api/ThreadData.hpp>
#include <tachyon/api/ThreadInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::ViewerThread)

namespace yq::tachyon {
    ViewerThread::ViewerThread(const Param&p) : Thread(p)
    {
    }
    
    ViewerThread::~ViewerThread()
    {
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
