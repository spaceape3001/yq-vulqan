////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveThread.hpp"
#include <yq/tachyon/api/Thread.hpp>

namespace yq::tachyon {
    SaveThread::SaveThread(Save& save, const Thread& tac) : SaveTachyon(save, tac)
    {
    }
    
    SaveThread::SaveThread(Save&save, const ThreadMeta* info, uint64_t i) : SaveTachyon(save, info, i)
    {
    }
    
    SaveThread::~SaveThread()
    {
    }

    const ThreadMeta* SaveThread::info() const
    {
        return dynamic_cast<const ThreadMeta*>(SaveObject::info());
    }

    bool    SaveThread::valid() const 
    {
        return info() && id();
    }
}
