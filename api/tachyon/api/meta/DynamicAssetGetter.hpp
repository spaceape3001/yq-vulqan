////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/meta/AssetGetter.hpp>
#include <yq/asset/Asset.hpp>

namespace yq::tachyon {
    template <SomeObject O, SomeAsset A>
    class DynamicAssetGetter : public AssetGetter {
    public:
    
        virtual const ObjectMeta&    object() const override { return meta<O>(); }
        virtual const AssetMeta&     asset() const override { return meta<A>(); }
    
    protected:
        DynamicAssetGetter(AssetProperty* propInfo, const std::source_location& sl) : AssetGetter(propInfo, sl) 
        {
        }
    };
    
    template <SomeObject O, typename C, SomeAsset A>
    class IPM_AssetGetter : public DynamicAssetGetter<O,A> {
    public:
    
        typedef Ref<const A> (C::*P);
        
        IPM_AssetGetter(AssetProperty* propInfo, const std::source_location& sl, P pointer) : 
            DynamicAssetGetter<O,A>(propInfo, sl), m_pointer(pointer)
        {
            assert(pointer);
        }
    
    private:
        virtual AssetCPtr get(const Object* obj) const override
        {
            const C*    c   = dynamic_cast<const C*>(obj);
            if(!c)
                return {};
            return c->*m_pointer;
        }
        
        P   m_pointer;
    };


    template <SomeObject O, typename C, SomeAsset A>
    class IFV_AssetGetter : public  DynamicAssetGetter<O,A> {
    public:
        typedef Ref<const A> (C::*FN)() const;
        
        IFV_AssetGetter(AssetProperty* propInfo, const std::source_location& sl, FN function) :
            DynamicAssetGetter<O,A>(propInfo, sl), m_function(function)
        {
            assert(function);
        }
    private:
        virtual AssetCPtr get(const Object* obj) const override 
        {
            const C*    c   = dynamic_cast<const C*>(obj);
            if(!c)
                return {};
            return (c->*m_function)();
        }
    
        FN m_function;
    };


    template <SomeObject O, typename C, SomeAsset A>
    class IFR_AssetGetter : public  DynamicAssetGetter<O,A> {
    public:
        typedef const Ref<const A>& (C::*FN)() const;
        IFR_AssetGetter(AssetProperty* propInfo, const std::source_location& sl, FN function) :
            DynamicAssetGetter<O,A>(propInfo, sl), m_function(function)
        {
            assert(function);
        }
        
    private:
        virtual AssetCPtr get(const Object* obj) const override 
        {
            const C*    c   = dynamic_cast<const C*>(obj);
            if(!c)
                return {};
            return (c->*m_function)();
        }
    
        FN m_function;
    };
}
