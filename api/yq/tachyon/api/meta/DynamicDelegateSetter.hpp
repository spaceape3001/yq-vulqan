////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/meta/DelegateSetter.hpp>
#include <yq/tachyon/api/Delegate.hpp>
#include <yq/tachyon/errors.hpp>

namespace yq::tachyon {
    template <SomeObject O, SomeDelegate A>
    class DynamicDelegateSetter : public DelegateSetter {
    public:
    
        virtual const ObjectMeta&       object() const override { return meta<O>(); }
        virtual const DelegateMeta&     resource() const override { return meta<A>(); }
    
    protected:
        DynamicDelegateSetter(DelegateProperty* propInfo, const std::source_location& sl) : DelegateSetter(propInfo, sl) 
        {
        }
    };

    template <SomeObject O, typename C, SomeDelegate A>
    class IPM_DelegateSetter : public DynamicDelegateSetter<O,A> {
    public:
    
        typedef Ref<const A> (C::*P);
        
        IPM_DelegateSetter(DelegateProperty* propInfo, const std::source_location& sl, P pointer) : 
            DynamicDelegateSetter<O,A>(propInfo, sl), m_pointer(pointer)
        {
            assert(pointer);
        }
    
    private:
    
        virtual std::error_code set(Object*obj, const DelegateCPtr& acp) const override
        {
            C*    c   = dynamic_cast<C*>(obj);
            if(!c)
                return errors::not_object_looking_for();
                
            const A*    a   = dynamic_cast<const A*>(acp.ptr());
            if(!a)
                return errors::not_delegate_looking_for();
                
            c->*m_pointer = a;
            return {};
        }
        
        P   m_pointer;
    };

    template <SomeObject O, typename C, SomeDelegate A>
    class IFR_DelegateSetter : public DynamicDelegateSetter<O,A> {
    public:
    
        typedef void (C::*FN)(const Ref<const A>&);
        
        IFR_DelegateSetter(DelegateProperty* propInfo, const std::source_location& sl, FN function) : 
            DynamicDelegateSetter<O,A>(propInfo, sl), m_function(function)
        {
            assert(function);
        }
    
    private:
    
        virtual std::error_code set(Object*obj, const DelegateCPtr& acp) const override
        {
            C*    c   = dynamic_cast<C*>(obj);
            if(!c)
                return errors::not_object_looking_for();
                
            const A*    a   = dynamic_cast<const A*>(acp.ptr());
            if(!a)
                return errors::not_delegate_looking_for();
            (c->*m_function)(a);
            return {};
        }
        
        FN  m_function;
    };
    
}
