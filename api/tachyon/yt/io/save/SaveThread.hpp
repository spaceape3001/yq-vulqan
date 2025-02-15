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
        SaveThread(Save&, std::string_view, uint64_t);
        
        const ThreadInfo* info() const;
        virtual bool    isThread() const { return true; }
        virtual bool    valid() const override;
        
    protected:
        virtual ~SaveThread();
    };
}
