////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/meta/ResourceVectorProperty.hpp>
#include <yq/meta/MetaWriter.hpp>
#include <yq/tachyon/api/meta/DynamicResourceVectorSetter.hpp>

namespace yq::tachyon {
    template <SomeResource A>
    class ResourceVectorProperty::Writer : public Meta::Writer {
    public:
        Writer(ResourceVectorProperty* pi) : Meta::Writer(pi) {}
    };
    
    template <SomeObject O, SomeResource A> 
    class ResourceVectorProperty::PropW : public Writer<A> {
    public:
    
        template <typename C>
        Writer<A>&  setter(void (C::*function)(std::span<const Ref<const A>>&), const std::source_location& sl = std::source_location::current())
        {
            assert(function);
            assert(Meta::Writer::m_meta);
            assert(thread_safe_write());

            if(function && Meta::Writer::m_meta && thread_safe_write()){
                new IFR_ResourceVectorSetter<O,C,A>(static_cast<ResourceVectorProperty*>(Meta::Writer::m_meta), sl, function);
            }
            return *this;
        }
    
        PropW(ResourceVectorProperty* pi) : Writer<A>(pi) {}
    };
}
