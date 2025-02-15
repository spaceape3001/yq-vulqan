////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveThread.hpp"
#include <yt/api/Thread.hpp>

namespace yq::tachyon {
    SaveThread::SaveThread(Save& save, const Thread& tac) : SaveTachyon(save, tac)
    {
    }
    
    SaveThread::SaveThread(Save&save, std::string_view k, uint64_t i) : SaveTachyon(save, k, i)
    {
    }
    
    SaveThread::~SaveThread()
    {
    }

    const ThreadInfo* SaveThread::info() const
    {
        return dynamic_cast<const ThreadInfo*>(SaveObject::info());
    }

    bool    SaveThread::valid() const 
    {
        return info() && id();
    }
}
