////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/meta/ResourceVectorEAdd.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/tachyon/errors.hpp>

namespace yq::tachyon {
    template <SomeObject O, SomeResource A>
    class DynamicResourceVectorEAdd : public ResourceVectorEAdd {
    public:
    
        virtual const ObjectMeta&    object() const override { return meta<O>(); }
        virtual const ResourceMeta&     resource() const override { return meta<A>(); }
    
    protected:
        DynamicResourceVectorEAdd(ResourceVectorProperty* propInfo, const std::source_location& sl) : ResourceVectorEAdd(propInfo, sl) 
        {
        }
    };
    
    template <SomeObject O, typename C, SomeResource A>
    class IPM_ResourceVectorEAdd : public DynamicResourceVectorEAdd<O,A> {
    public:
    
        typedef std::vector<Ref<const A>> (C::*P);
        
        IPM_ResourceVectorEAdd(ResourceVectorProperty* propInfo, const std::source_location& sl, P pointer) : 
            DynamicResourceVectorEAdd<O,A>(propInfo, sl), m_pointer(pointer)
        {
            assert(pointer);
        }
    
    private:
        virtual std::error_code add(Object* obj, const ResourceCPtr& acp) const override
        {
            C*    c   = dynamic_cast<C*>(obj);
            if(!c)
                return errors::not_object_looking_for();
            const A*    a   = dynamic_cast<const A*>(acp.ptr());
            if(!a)
                return errors::not_resource_looking_for();
                
            (c->*m_pointer).push_back(a);
            return {};
        }
        
        P   m_pointer;
    };
}
