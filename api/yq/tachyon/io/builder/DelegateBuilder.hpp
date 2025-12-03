////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/io/builder/ObjectBuilder.hpp>

namespace yq::tachyon {
    class Delegate;
    class DelegateMeta;
    
    struct DelegateSave : public ObjectSave {
        uint64_t            id  = 0;
        string_any_xmap_t   state;
    };

    class DelegateBuilder : public ObjectBuilder {
    public:
        DelegateBuilder(const Delegate&);
        DelegateBuilder(const DelegateCapture&);
        virtual ~DelegateBuilder();
        
        const DelegateMeta* meta() const { return m_meta; }
        virtual bool is_delegate() const override { return true; }
        
    private:
        const DelegateMeta* m_meta  = nullptr;
        uint64_t            m_id    = 0;
        string_any_xmap_t   m_state;
    };
}
