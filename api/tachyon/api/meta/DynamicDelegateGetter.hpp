////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/meta/DelegateGetter.hpp>
#include <tachyon/api/Delegate.hpp>

namespace yq::tachyon {
    template <SomeObject O, SomeDelegate A>
    class DynamicDelegateGetter : public DelegateGetter {
    public:
    
        virtual const ObjectInfo&       object() const override { return meta<O>(); }
        virtual const DelegateInfo&     delegate() const override { return meta<A>(); }
    
    protected:
        DynamicDelegateGetter(DelegateProperty* propInfo, const std::source_location& sl) : DelegateGetter(propInfo, sl) 
        {
        }
    };
    
    template <SomeObject O, typename C, SomeDelegate A>
    class IPM_DelegateGetter : public DynamicDelegateGetter<O,A> {
    public:
    
        typedef Ref<const A> (C::*P);
        
        IPM_DelegateGetter(DelegateProperty* propInfo, const std::source_location& sl, P pointer) : 
            DynamicDelegateGetter<O,A>(propInfo, sl), m_pointer(pointer)
        {
            assert(pointer);
        }
    
    private:
        virtual DelegateCPtr get(const Object* obj) const override
        {
            const C*    c   = dynamic_cast<const C*>(obj);
            if(!c)
                return {};
            return c->*m_pointer;
        }
        
        P   m_pointer;
    };


    template <SomeObject O, typename C, SomeDelegate A>
    class IFV_DelegateGetter : public  DynamicDelegateGetter<O,A> {
    public:
        typedef Ref<const A> (C::*FN)() const;
        
        
        IFV_DelegateGetter(DelegateProperty* propInfo, const std::source_location& sl, FN function) :
            DynamicDelegateGetter<O,A>(propInfo, sl), m_function(function)
        {
            assert(function);
        }
    private:
        virtual DelegateCPtr get(const Object* obj) const override 
        {
            const C*    c   = dynamic_cast<const C*>(obj);
            if(!c)
                return {};
            return (c->*m_function)();
        }
    
        FN m_function;
    };


    template <SomeObject O, typename C, SomeDelegate A>
    class IFR_DelegateGetter : public  DynamicDelegateGetter<O,A> {
    public:
        typedef const Ref<const A>& (C::*FN)() const;
        IFR_DelegateGetter(DelegateProperty* propInfo, const std::source_location& sl, FN function) :
            DynamicDelegateGetter<O,A>(propInfo, sl), m_function(function)
        {
            assert(function);
        }
        
    private:
        virtual DelegateCPtr get(const Object* obj) const override 
        {
            const C*    c   = dynamic_cast<const C*>(obj);
            if(!c)
                return {};
            return (c->*m_function)();
        }
    
        FN m_function;
    };
}
