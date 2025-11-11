////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/thread/IOThread.hpp>

#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/api/ThreadData.hpp>
#include <yq/tachyon/api/ThreadMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::IOThread)

namespace yq::tachyon {
    IOThread::IOThread(const Param&p) : Thread(p)
    {
        m_name  = "IO";
    }
    
    IOThread::~IOThread()
    {
    }
    
    void IOThread::shutdown()
    {
        quit();
    }
    
    void IOThread::init_meta()
    {
        auto w = writer<IOThread>();
        w.description("IO Thread");
    }
}
