////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/thread/EditThread.hpp>

#include <tachyon/api/Thread.hpp>
#include <tachyon/api/ThreadData.hpp>
#include <tachyon/api/ThreadInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::EditThread)

namespace yq::tachyon {
    EditThread::EditThread(const Param&p) : Thread(p)
    {
        m_name    = "EDIT";
    }
    
    EditThread::~EditThread()
    {
    }
    
    void EditThread::shutdown()
    {
        quit();
    }
    
    void EditThread::init_info()
    {
        auto w = writer<EditThread>();
        w.description("Edit Thread");
    }
}
