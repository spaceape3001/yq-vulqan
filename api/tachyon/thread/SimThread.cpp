////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/thread/SimThread.hpp>

#include <tachyon/api/Thread.hpp>
#include <tachyon/api/ThreadData.hpp>
#include <tachyon/api/ThreadMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::SimThread)

namespace yq::tachyon {
    SimThread::SimThread(const Param&p) : Thread(p)
    {
        m_name  = "SIM";
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
