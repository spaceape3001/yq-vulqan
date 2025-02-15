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
        SaveDelegate(Save&, const Delegate&);
        SaveDelegate(Save&, std::string_view, uint64_t);
        
        const DelegateInfo* info() const;
        virtual bool    valid() const override;

        virtual bool        isDelegate() const { return true; }
    protected:
        virtual ~SaveDelegate();
    };
}
