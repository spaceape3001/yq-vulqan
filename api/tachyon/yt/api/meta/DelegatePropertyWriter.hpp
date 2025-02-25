////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/meta/DelegateProperty.hpp>
#include <yq/meta/MetaWriter.hpp>
#include <yt/api/meta/DynamicDelegateSetter.hpp>

namespace yq::tachyon {
    template <SomeDelegate D>
    class DelegateProperty::Writer : public Meta::Writer {
    public:
        Writer(DelegateProperty* pi) : Meta::Writer(pi) {}
    };
    
    template <SomeObject O, SomeDelegate D> 
    class DelegateProperty::PropW : public Writer<D> {
    public:
        template <typename C>
        Writer<D>&  setter(void (C::*function)(const Ref<D>&), const std::source_location& sl = std::source_location::current())
        {
            assert(function);
            assert(Meta::Writer::m_meta);
            assert(thread_safe_write());

            if(function && Meta::Writer::m_meta && thread_safe_write()){
                new IFR_DelegateSetter<O,C,D>(static_cast<DelegateProperty*>(Meta::Writer::m_meta), sl, function);
            }
            return *this;
        }
    
        PropW(DelegateProperty* pi) : Writer<D>(pi) {}
    };
}
