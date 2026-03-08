////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/meta/ResourceVectorSetter.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/tachyon/errors.hpp>

namespace yq::tachyon {
    template <SomeObject O, SomeResource A>
    class DynamicResourceVectorSetter : public ResourceVectorSetter {
    public:
    
        virtual const ObjectMeta&    object() const override { return meta<O>(); }
        virtual const ResourceMeta&     resource() const override { return meta<A>(); }
    
    protected:
        DynamicResourceVectorSetter(ResourceVectorProperty* propInfo, const std::source_location& sl) : ResourceVectorSetter(propInfo, sl) 
        {
        }
    };

    template <SomeObject O, typename C, SomeResource A>
    class IPM_ResourceVectorSetter : public DynamicResourceVectorSetter<O,A> {
    public:
    
        typedef std::vector<Ref<const A>> (C::*P);
        
        IPM_ResourceVectorSetter(ResourceVectorProperty* propInfo, const std::source_location& sl, P pointer) : 
            DynamicResourceVectorSetter<O,A>(propInfo, sl), m_pointer(pointer)
        {
            assert(pointer);
        }
    
    private:
    
        virtual std::error_code set(Object*obj, ResourceCPtrCSpan res) const override
        {
            C*    c   = dynamic_cast<C*>(obj);
            if(!c)
                return errors::not_object_looking_for();
                
            auto& cont  = c->*m_pointer;
            cont.clear();
            if(res.empty())
                return {};
            
            cont.reserve(res.size());
            for(auto& rp : res){
                const A*    a   = dynamic_cast<const A*>(rp.ptr());
                if(!a)
                    continue;
                cont.push_back(a);
            }
            return {};
        }
        
        P   m_pointer;
    };

    template <SomeObject O, typename C, SomeResource A>
    class IFR_ResourceVectorSetter : public DynamicResourceVectorSetter<O,A> {
    public:
    
        typedef void (C::*FN)(std::span<const Ref<const A>>);
        
        IFR_ResourceVectorSetter(ResourceVectorProperty* propInfo, const std::source_location& sl, FN function) : 
            DynamicResourceVectorSetter<O,A>(propInfo, sl), m_function(function)
        {
            assert(function);
        }
    
    private:
    
        virtual std::error_code set(Object*obj, ResourceCPtrCSpan res) const override
        {
            C*    c   = dynamic_cast<C*>(obj);
            if(!c)
                return errors::not_object_looking_for();
                
            std::vector<const Ref<const A>> cont;
            if(!res.empty()){
                cont.reserve(res.size());
                for(auto& rp : res){
                    const A*    a   = dynamic_cast<const A*>(rp.ptr());
                    if(!a)
                        continue;
                    cont.push_back(a);
                }
            }
            (c->*m_function)(cont);
            return {};
        }
        
        FN  m_function;
    };
    
}
