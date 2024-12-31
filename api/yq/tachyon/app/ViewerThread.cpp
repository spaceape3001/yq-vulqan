////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerThread.hpp"

#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/api/ThreadData.hpp>
#include <yq/tachyon/api/ThreadInfoWriter.hpp>

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
