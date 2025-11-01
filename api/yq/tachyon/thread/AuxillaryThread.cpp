////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/thread/AuxillaryThread.hpp>

#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/api/ThreadData.hpp>
#include <yq/tachyon/api/ThreadMetaWriter.hpp>

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
    
    void AuxillaryThread::init_meta()
    {
        auto w = writer<AuxillaryThread>();
        w.description("Auxillary Thread");
    }
}
