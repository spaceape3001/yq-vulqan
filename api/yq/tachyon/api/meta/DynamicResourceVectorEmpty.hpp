////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/meta/ResourceVectorEmpty.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/tachyon/errors.hpp>

namespace yq::tachyon {
    template <SomeObject O, SomeResource A>
    class DynamicResourceVectorEmpty : public ResourceVectorEmpty {
    public:
    
        virtual const ObjectMeta&    object() const override { return meta<O>(); }
        virtual const ResourceMeta&     resource() const override { return meta<A>(); }
    
    protected:
        DynamicResourceVectorEmpty(ResourceVectorProperty* propInfo, const std::source_location& sl) : ResourceVectorEmpty(propInfo, sl) 
        {
        }
    };
    
    template <SomeObject O, typename C, SomeResource A>
    class IPM_ResourceVectorEmpty : public DynamicResourceVectorEmpty<O,A> {
    public:
    
        typedef std::vector<Ref<const A>> (C::*P);
        
        IPM_ResourceVectorEmpty(ResourceVectorProperty* propInfo, const std::source_location& sl, P pointer) : 
            DynamicResourceVectorEmpty<O,A>(propInfo, sl), m_pointer(pointer)
        {
            assert(pointer);
        }
    
    private:
        virtual boolean_x empty(const Object* obj) const override
        {
            const C*    c   = dynamic_cast<const C*>(obj);
            if(!c)
                return errors::not_object_looking_for();
            
            return (c->*m_pointer).empty();
        }
        
        P   m_pointer;
    };
}
