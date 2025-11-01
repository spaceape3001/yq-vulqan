////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/io/save/SaveTachyon.hpp>

namespace yq::tachyon {
    class Thread;
    class ThreadMeta;
    
    class SaveThread : public SaveTachyon {
    public:
        SaveThread(Save&, const Thread&);
        SaveThread(Save&, const ThreadMeta*, uint64_t);
        
        const ThreadMeta* info() const;
        virtual bool        isThread() const { return true; }
        virtual bool        valid() const override;
        virtual SaveType    saveType() const override { return SaveType::Thread; }
        
    protected:
        virtual ~SaveThread();
    };
}
