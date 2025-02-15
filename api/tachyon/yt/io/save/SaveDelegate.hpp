////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/io/save/SaveObject.hpp>

namespace yq::tachyon {
    class Delegate;
    class DelegateInfo;
    
    class SaveDelegate : public SaveObject {
    public:
        SaveDelegate(const Delegate&);
        SaveDelegate(std::string_view, uint64_t);
        
        const DelegateInfo* info() const;
        virtual bool    valid() const override;
    protected:
        virtual ~SaveDelegate();
    };
}
