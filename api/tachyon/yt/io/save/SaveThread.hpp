////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/io/save/SaveTachyon.hpp>

namespace yq::tachyon {
    class Thread;
    class ThreadInfo;
    
    class SaveThread : public SaveTachyon {
    public:
        SaveThread(Save&, const Thread&);
        SaveThread(Save&, const ThreadInfo*, uint64_t);
        
        const ThreadInfo* info() const;
        virtual bool        isThread() const { return true; }
        virtual bool        valid() const override;
        virtual SaveType    saveType() const override { return SaveType::Thread; }
        
    protected:
        virtual ~SaveThread();
    };
}
