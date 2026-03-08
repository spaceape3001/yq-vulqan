////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/meta/ResourceVectorAppend.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/tachyon/errors.hpp>

namespace yq::tachyon {
    template <SomeObject O, SomeResource A>
    class DynamicResourceVectorAppend : public ResourceVectorAppend {
    public:
    
        virtual const ObjectMeta&    object() const override { return meta<O>(); }
        virtual const ResourceMeta&     resource() const override { return meta<A>(); }
    
    protected:
        DynamicResourceVectorAppend(ResourceVectorProperty* propInfo, const std::source_location& sl) : ResourceVectorAppend(propInfo, sl) 
        {
        }
    };

    template <SomeObject O, typename C, SomeResource A>
    class IPM_ResourceVectorAppend : public DynamicResourceVectorAppend<O,A> {
    public:
    
        typedef std::vector<Ref<const A>> (C::*P);
        
        IPM_ResourceVectorAppend(ResourceVectorProperty* propInfo, const std::source_location& sl, P pointer) : 
            DynamicResourceVectorAppend<O,A>(propInfo, sl), m_pointer(pointer)
        {
            assert(pointer);
        }
    
    private:
    
        virtual std::error_code append(Object*obj, ResourceCPtrCSpan res) const override
        {
            C*    c   = dynamic_cast<C*>(obj);
            if(!c)
                return errors::not_object_looking_for();
                
            auto& cont  = c->*m_pointer;
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
}
