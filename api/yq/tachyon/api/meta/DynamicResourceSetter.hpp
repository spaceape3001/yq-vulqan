////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/meta/ResourceSetter.hpp>
#include <yq/resource/Resource.hpp>
#include <tachyon/errors.hpp>

namespace yq::tachyon {
    template <SomeObject O, SomeResource A>
    class DynamicResourceSetter : public ResourceSetter {
    public:
    
        virtual const ObjectMeta&    object() const override { return meta<O>(); }
        virtual const ResourceMeta&     resource() const override { return meta<A>(); }
    
    protected:
        DynamicResourceSetter(ResourceProperty* propInfo, const std::source_location& sl) : ResourceSetter(propInfo, sl) 
        {
        }
    };

    template <SomeObject O, typename C, SomeResource A>
    class IPM_ResourceSetter : public DynamicResourceSetter<O,A> {
    public:
    
        typedef Ref<const A> (C::*P);
        
        IPM_ResourceSetter(ResourceProperty* propInfo, const std::source_location& sl, P pointer) : 
            DynamicResourceSetter<O,A>(propInfo, sl), m_pointer(pointer)
        {
            assert(pointer);
        }
    
    private:
    
        virtual std::error_code set(Object*obj, const ResourceCPtr& acp) const override
        {
            C*    c   = dynamic_cast<C*>(obj);
            if(!c)
                return errors::not_object_looking_for();
                
            const A*    a   = dynamic_cast<const A*>(acp.ptr());
            if(!a)
                return errors::not_resource_looking_for();
                
            c->*m_pointer = a;
            return {};
        }
        
        P   m_pointer;
    };

    template <SomeObject O, typename C, SomeResource A>
    class IFR_ResourceSetter : public DynamicResourceSetter<O,A> {
    public:
    
        typedef void (C::*FN)(const Ref<const A>&);
        
        IFR_ResourceSetter(ResourceProperty* propInfo, const std::source_location& sl, FN function) : 
            DynamicResourceSetter<O,A>(propInfo, sl), m_function(function)
        {
            assert(function);
        }
    
    private:
    
        virtual std::error_code set(Object*obj, const ResourceCPtr& acp) const override
        {
            C*    c   = dynamic_cast<C*>(obj);
            if(!c)
                return errors::not_object_looking_for();
                
            const A*    a   = dynamic_cast<const A*>(acp.ptr());
            if(!a)
                return errors::not_resource_looking_for();
            (c->*m_function)(a);
            return {};
        }
        
        FN  m_function;
    };
    
}
