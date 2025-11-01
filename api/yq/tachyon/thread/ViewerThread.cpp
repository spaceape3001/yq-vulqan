////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/thread/ViewerThread.hpp>

#include <tachyon/logging.hpp>
#include <tachyon/api/Thread.hpp>
#include <tachyon/api/ThreadData.hpp>
#include <tachyon/api/ThreadMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::ViewerThread)

namespace yq::tachyon {
    ViewerThread::ViewerThread(const Param&p) : Thread(p)
    {
        m_name  = "VIZ";
    }
    
    ViewerThread::~ViewerThread()
    {
    }
    
    void    ViewerThread::shutdown()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerThread::init_meta()
    {
        auto w = writer<ViewerThread>();
        w.description("Viewer Thread");
    }
}
