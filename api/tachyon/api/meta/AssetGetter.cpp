////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AssetGetter.hpp"
#include <tachyon/api/meta/AssetProperty.hpp>
#include <cassert>

namespace yq::tachyon {
    AssetGetter::AssetGetter(AssetProperty* assetProp, const std::source_location& sl) : Meta("get", assetProp, sl) 
    {
        assert(assetProp);
        assert("no duplicate getters!" && !assetProp->m_getter);    //  duplicate property is an ERROR
        assetProp->m_getter     = this;
    }

    const AssetProperty* AssetGetter::property() const
    {
        return static_cast<const AssetProperty*>(parent());
    }
}
