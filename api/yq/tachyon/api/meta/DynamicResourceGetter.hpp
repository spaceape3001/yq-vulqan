////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/meta/ResourceGetter.hpp>
#include <yq/resource/Resource.hpp>

namespace yq::tachyon {
    template <SomeObject O, SomeResource A>
    class DynamicResourceGetter : public ResourceGetter {
    public:
    
        virtual const ObjectMeta&    object() const override { return meta<O>(); }
        virtual const ResourceMeta&     resource() const override { return meta<A>(); }
    
    protected:
        DynamicResourceGetter(ResourceProperty* propInfo, const std::source_location& sl) : ResourceGetter(propInfo, sl) 
        {
        }
    };
    
    template <SomeObject O, typename C, SomeResource A>
    class IPM_ResourceGetter : public DynamicResourceGetter<O,A> {
    public:
    
        typedef Ref<const A> (C::*P);
        
        IPM_ResourceGetter(ResourceProperty* propInfo, const std::source_location& sl, P pointer) : 
            DynamicResourceGetter<O,A>(propInfo, sl), m_pointer(pointer)
        {
            assert(pointer);
        }
    
    private:
        virtual ResourceCPtr get(const Object* obj) const override
        {
            const C*    c   = dynamic_cast<const C*>(obj);
            if(!c)
                return {};
            return c->*m_pointer;
        }
        
        P   m_pointer;
    };


    template <SomeObject O, typename C, SomeResource A>
    class IFV_ResourceGetter : public  DynamicResourceGetter<O,A> {
    public:
        typedef Ref<const A> (C::*FN)() const;
        
        IFV_ResourceGetter(ResourceProperty* propInfo, const std::source_location& sl, FN function) :
            DynamicResourceGetter<O,A>(propInfo, sl), m_function(function)
        {
            assert(function);
        }
    private:
        virtual ResourceCPtr get(const Object* obj) const override 
        {
            const C*    c   = dynamic_cast<const C*>(obj);
            if(!c)
                return {};
            return (c->*m_function)();
        }
    
        FN m_function;
    };


    template <SomeObject O, typename C, SomeResource A>
    class IFR_ResourceGetter : public  DynamicResourceGetter<O,A> {
    public:
        typedef const Ref<const A>& (C::*FN)() const;
        IFR_ResourceGetter(ResourceProperty* propInfo, const std::source_location& sl, FN function) :
            DynamicResourceGetter<O,A>(propInfo, sl), m_function(function)
        {
            assert(function);
        }
        
    private:
        virtual ResourceCPtr get(const Object* obj) const override 
        {
            const C*    c   = dynamic_cast<const C*>(obj);
            if(!c)
                return {};
            return (c->*m_function)();
        }
    
        FN m_function;
    };
}
