////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/meta/ResourceVectorEGet.hpp>
#include <yq/resource/Resource.hpp>

namespace yq::tachyon {
    template <SomeObject O, SomeResource A>
    class DynamicResourceVectorEGet : public ResourceVectorEGet {
    public:
    
        virtual const ObjectMeta&    object() const override { return meta<O>(); }
        virtual const ResourceMeta&     resource() const override { return meta<A>(); }
    
    protected:
        DynamicResourceVectorEGet(ResourceVectorProperty* propInfo, const std::source_location& sl) : ResourceVectorEGet(propInfo, sl) 
        {
        }
    };
    
    template <SomeObject O, typename C, SomeResource A>
    class IPM_ResourceVectorEGet : public DynamicResourceVectorEGet<O,A> {
    public:
    
        typedef std::vector<Ref<const A>> (C::*P);
        
        IPM_ResourceVectorEGet(ResourceVectorProperty* propInfo, const std::source_location& sl, P pointer) : 
            DynamicResourceVectorEGet<O,A>(propInfo, sl), m_pointer(pointer)
        {
            assert(pointer);
        }
    
    private:
        virtual ResourceCPtr get(const Object* obj, size_t n) const override
        {
            const C*    c   = dynamic_cast<const C*>(obj);
            if(!c)
                return {};
            
            const auto& cont  = c->*m_pointer;
            if(n >= cont.size())
                return {};
            return cont[n];
        }
        
        P   m_pointer;
    };
}
