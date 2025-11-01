////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/meta/ResourceProperty.hpp>
#include <yq/meta/MetaWriter.hpp>
#include <yq/tachyon/api/meta/DynamicResourceSetter.hpp>

namespace yq::tachyon {
    template <SomeResource A>
    class ResourceProperty::Writer : public Meta::Writer {
    public:
        Writer(ResourceProperty* pi) : Meta::Writer(pi) {}
    };
    
    template <SomeObject O, SomeResource A> 
    class ResourceProperty::PropW : public Writer<A> {
    public:
    
        template <typename C>
        Writer<A>&  setter(void (C::*function)(const Ref<A>&), const std::source_location& sl = std::source_location::current())
        {
            assert(function);
            assert(Meta::Writer::m_meta);
            assert(thread_safe_write());

            if(function && Meta::Writer::m_meta && thread_safe_write()){
                new IFR_ResourceSetter<O,C,A>(static_cast<ResourceProperty*>(Meta::Writer::m_meta), sl, function);
            }
            return *this;
        }
    
        PropW(ResourceProperty* pi) : Writer<A>(pi) {}
    };
}
