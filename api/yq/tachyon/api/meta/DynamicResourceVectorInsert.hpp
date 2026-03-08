////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/meta/ResourceVectorInsert.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/tachyon/errors.hpp>

namespace yq::tachyon {
    template <SomeObject O, SomeResource A>
    class DynamicResourceVectorInsert : public ResourceVectorInsert {
    public:
    
        virtual const ObjectMeta&    object() const override { return meta<O>(); }
        virtual const ResourceMeta&     resource() const override { return meta<A>(); }
    
    protected:
        DynamicResourceVectorInsert(ResourceVectorProperty* propInfo, const std::source_location& sl) : ResourceVectorInsert(propInfo, sl) 
        {
        }
    };
    
    template <SomeObject O, typename C, SomeResource A>
    class IPM_ResourceVectorInsert : public DynamicResourceVectorInsert<O,A> {
    public:
    
        typedef std::vector<Ref<const A>> (C::*P);
        
        IPM_ResourceVectorInsert(ResourceVectorProperty* propInfo, const std::source_location& sl, P pointer) : 
            DynamicResourceVectorInsert<O,A>(propInfo, sl), m_pointer(pointer)
        {
            assert(pointer);
        }
    
    private:
        virtual std::error_code insert(Object* obj, size_t n, const ResourceCPtr& acp) const override
        {
            C*    c   = dynamic_cast<C*>(obj);
            if(!c)
                return errors::not_object_looking_for();
            const A*    a   = dynamic_cast<const A*>(acp.ptr());
            if(!a)
                return errors::not_resource_looking_for();
                
            auto& cont  = c->*m_pointer;
            if(n >= cont.size())
                return errors::bad_index();
            
            cont.insert(cont.begin()+n, a);
            return {};
        }
        
        P   m_pointer;
    };
}
