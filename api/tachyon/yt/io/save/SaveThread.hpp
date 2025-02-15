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
        SaveThread(const Thread&);
        SaveThread(std::string_view, uint64_t);
        
        const ThreadInfo* info() const;
        virtual bool    valid() const override;
    protected:
        virtual ~SaveThread();
    };
}
