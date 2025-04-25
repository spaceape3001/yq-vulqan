////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/meta/AssetProperty.hpp>
#include <yq/meta/MetaWriter.hpp>
#include <tachyon/api/meta/DynamicAssetSetter.hpp>

namespace yq::tachyon {
    template <SomeAsset A>
    class AssetProperty::Writer : public Meta::Writer {
    public:
        Writer(AssetProperty* pi) : Meta::Writer(pi) {}
    };
    
    template <SomeObject O, SomeAsset A> 
    class AssetProperty::PropW : public Writer<A> {
    public:
    
        template <typename C>
        Writer<A>&  setter(void (C::*function)(const Ref<A>&), const std::source_location& sl = std::source_location::current())
        {
            assert(function);
            assert(Meta::Writer::m_meta);
            assert(thread_safe_write());

            if(function && Meta::Writer::m_meta && thread_safe_write()){
                new IFR_AssetSetter<O,C,A>(static_cast<AssetProperty*>(Meta::Writer::m_meta), sl, function);
            }
            return *this;
        }
    
        PropW(AssetProperty* pi) : Writer<A>(pi) {}
    };
}
