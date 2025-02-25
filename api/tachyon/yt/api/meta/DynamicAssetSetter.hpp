////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/meta/AssetSetter.hpp>
#include <yq/asset/Asset.hpp>
#include <yt/errors.hpp>

namespace yq::tachyon {
    template <SomeObject O, SomeAsset A>
    class DynamicAssetSetter : public AssetSetter {
    public:
    
        virtual const ObjectInfo&    object() const override { return meta<O>(); }
        virtual const AssetInfo&     asset() const override { return meta<A>(); }
    
    protected:
        DynamicAssetSetter(AssetProperty* propInfo, const std::source_location& sl) : AssetSetter(propInfo, sl) 
        {
        }
    };

    template <SomeObject O, typename C, SomeAsset A>
    class IPM_AssetSetter : public DynamicAssetSetter<O,A> {
    public:
    
        typedef Ref<const A> (C::*P);
        
        IPM_AssetSetter(AssetProperty* propInfo, const std::source_location& sl, P pointer) : 
            DynamicAssetSetter<O,A>(propInfo, sl), m_pointer(pointer)
        {
            assert(pointer);
        }
    
    private:
    
        virtual std::error_code set(Object*obj, const AssetCPtr& acp) const override
        {
            C*    c   = dynamic_cast<C*>(obj);
            if(!c)
                return errors::not_object_looking_for();
                
            const A*    a   = dynamic_cast<const A*>(acp.ptr());
            if(!a)
                return errors::not_asset_looking_for();
                
            c->*m_pointer = a;
            return {};
        }
        
        P   m_pointer;
    };

    template <SomeObject O, typename C, SomeAsset A>
    class IFR_AssetSetter : public DynamicAssetSetter<O,A> {
    public:
    
        typedef void (C::*FN)(const Ref<const A>&);
        
        IFR_AssetSetter(AssetProperty* propInfo, const std::source_location& sl, FN function) : 
            DynamicAssetSetter<O,A>(propInfo, sl), m_function(function)
        {
            assert(function);
        }
    
    private:
    
        virtual std::error_code set(Object*obj, const AssetCPtr& acp) const override
        {
            C*    c   = dynamic_cast<C*>(obj);
            if(!c)
                return errors::not_object_looking_for();
                
            const A*    a   = dynamic_cast<const A*>(acp.ptr());
            if(!a)
                return errors::not_asset_looking_for();
            (c->*m_function)(a);
            return {};
        }
        
        FN  m_function;
    };
    
}
