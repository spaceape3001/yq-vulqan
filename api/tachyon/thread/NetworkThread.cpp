////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/thread/NetworkThread.hpp>

#include <tachyon/api/Thread.hpp>
#include <tachyon/api/ThreadData.hpp>
#include <tachyon/api/ThreadMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::NetworkThread)

namespace yq::tachyon {
    NetworkThread::NetworkThread(const Param&p) : Thread(p)
    {
        m_name  = "NET";
    }
    
    NetworkThread::~NetworkThread()
    {
    }
    
    void NetworkThread::shutdown()
    {
        quit();
    }
    
    void NetworkThread::init_info()
    {
        auto w = writer<NetworkThread>();
        w.description("Network Thread");
    }
}
