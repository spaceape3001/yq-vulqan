////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/threads/NetworkThread.hpp>

#include <yt/api/Thread.hpp>
#include <yt/api/ThreadData.hpp>
#include <yt/api/ThreadInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::NetworkThread)

namespace yq::tachyon {
    NetworkThread::NetworkThread(const Param&p) : Thread(p)
    {
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
