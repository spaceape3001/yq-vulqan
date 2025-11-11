////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/thread/NetworkThread.hpp>

#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/api/ThreadData.hpp>
#include <yq/tachyon/api/ThreadMetaWriter.hpp>

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
    
    void NetworkThread::init_meta()
    {
        auto w = writer<NetworkThread>();
        w.description("Network Thread");
    }
}
