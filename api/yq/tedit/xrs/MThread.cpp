////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MThread.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/api/Thread.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MThread)

namespace yq::tachyon {
    MThread::MThread(TypedID tid) : MTachyon(tid)
    {
    }
    
    MThread::~MThread()
    {
    }
    
    void MThread::init_meta()
    {
        auto w = writer<MThread>();
        w.description("Thread Qt Binder");
        w.manage<Thread>();
    }
}


#include "moc_MThread.cpp"
