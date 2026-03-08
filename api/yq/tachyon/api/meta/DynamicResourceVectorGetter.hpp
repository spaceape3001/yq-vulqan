////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/meta/ResourceVectorGetter.hpp>
#include <yq/resource/Resource.hpp>

namespace yq::tachyon {
    template <SomeObject O, SomeResource A>
    class DynamicResourceVectorGetter : public ResourceVectorGetter {
    public:
    
        virtual const ObjectMeta&    object() const override { return meta<O>(); }
        virtual const ResourceMeta&     resource() const override { return meta<A>(); }
    
    protected:
        DynamicResourceVectorGetter(ResourceVectorProperty* propInfo, const std::source_location& sl) : ResourceVectorGetter(propInfo, sl) 
        {
        }
    };
    
    template <SomeObject O, typename C, SomeResource A>
    class IPM_ResourceVectorGetter : public DynamicResourceVectorGetter<O,A> {
    public:
    
        typedef std::vector<Ref<const A>> (C::*P);
        
        IPM_ResourceVectorGetter(ResourceVectorProperty* propInfo, const std::source_location& sl, P pointer) : 
            DynamicResourceVectorGetter<O,A>(propInfo, sl), m_pointer(pointer)
        {
            assert(pointer);
        }
    
    private:
        virtual ResourceCPtrVector get(const Object* obj) const override
        {
            const C*    c   = dynamic_cast<const C*>(obj);
            if(!c)
                return {};
            
            ResourceCPtrVector ret;
            const auto& cont  = c->*m_pointer;
            ret.reserve(cont.size());
            for(auto& rp : cont)
                ret.push_back(rp.ptr());
            return ret;
        }
        
        P   m_pointer;
    };


    template <SomeObject O, typename C, SomeResource A>
    class IFV_ResourceVectorGetter : public  DynamicResourceVectorGetter<O,A> {
    public:
        typedef std::vector<Ref<const A>> (C::*FN)() const;
        
        IFV_ResourceVectorGetter(ResourceVectorProperty* propInfo, const std::source_location& sl, FN function) :
            DynamicResourceVectorGetter<O,A>(propInfo, sl), m_function(function)
        {
            assert(function);
        }
    private:
        virtual ResourceCPtrVector get(const Object* obj) const override 
        {
            const C*    c   = dynamic_cast<const C*>(obj);
            if(!c)
                return {};

            ResourceCPtrVector ret;
            const auto cont  = (c->*m_function)();
            ret.reserve(cont.size());
            for(auto& rp : cont)
                ret.push_back(rp.ptr());
            return ret;
        }
    
        FN m_function;
    };


    template <SomeObject O, typename C, SomeResource A>
    class IFR_ResourceVectorGetter : public  DynamicResourceVectorGetter<O,A> {
    public:
        typedef const std::vector<Ref<const A>>& (C::*FN)() const;
        IFR_ResourceVectorGetter(ResourceVectorProperty* propInfo, const std::source_location& sl, FN function) :
            DynamicResourceVectorGetter<O,A>(propInfo, sl), m_function(function)
        {
            assert(function);
        }
        
    private:
        virtual ResourceCPtrVector get(const Object* obj) const override 
        {
            const C*    c   = dynamic_cast<const C*>(obj);
            if(!c)
                return {};
                
            ResourceCPtrVector ret;
            const auto& cont  = (c->*m_function)();
            ret.reserve(cont.size());
            for(auto& rp : cont)
                ret.push_back(rp.ptr());
            return ret;
        }
    
        FN m_function;
    };
}
