////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/thread/IOThread.hpp>

#include <tachyon/api/Thread.hpp>
#include <tachyon/api/ThreadData.hpp>
#include <tachyon/api/ThreadInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::IOThread)

namespace yq::tachyon {
    IOThread::IOThread(const Param&p) : Thread(p)
    {
    }
    
    IOThread::~IOThread()
    {
    }
    
    void IOThread::shutdown()
    {
        quit();
    }
    
    void IOThread::init_info()
    {
        auto w = writer<IOThread>();
        w.description("IO Thread");
    }
}
