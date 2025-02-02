////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/threads/SimThread.hpp>

#include <yt/api/Thread.hpp>
#include <yt/api/ThreadData.hpp>
#include <yt/api/ThreadInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::SimThread)

namespace yq::tachyon {
    SimThread::SimThread(const Param&p) : Thread(p)
    {
    }
    
    SimThread::~SimThread()
    {
    }
    
    void SimThread::shutdown()
    {
        quit();
    }
    
    void SimThread::init_info()
    {
        auto w = writer<SimThread>();
        w.description("Sim Thread");
    }
}
