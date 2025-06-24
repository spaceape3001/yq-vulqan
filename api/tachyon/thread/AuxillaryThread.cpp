////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/thread/AuxillaryThread.hpp>

#include <tachyon/api/Thread.hpp>
#include <tachyon/api/ThreadData.hpp>
#include <tachyon/api/ThreadInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::AuxillaryThread)

namespace yq::tachyon {
    AuxillaryThread::AuxillaryThread(const Param&p) : Thread(p)
    {
        m_name = "AUX";
    }
    
    AuxillaryThread::~AuxillaryThread()
    {
    }
    
    void AuxillaryThread::shutdown()
    {
        quit();
    }
    
    void AuxillaryThread::init_info()
    {
        auto w = writer<AuxillaryThread>();
        w.description("Auxillary Thread");
    }
}
