////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/io/save/SaveObject.hpp>

namespace yq::tachyon {
    class Delegate;
    class DelegateMeta;
    
    class SaveDelegate : public SaveObject {
    public:
        SaveDelegate(Save&, const Delegate&);
        SaveDelegate(Save&, const DelegateMeta*, uint64_t);
        
        const DelegateMeta* info() const;
        virtual bool    valid() const override;

        virtual bool        isDelegate() const { return true; }

        virtual SaveType    saveType() const override { return SaveType::Delegate; }
        
    protected:
        virtual ~SaveDelegate();
    };
}
