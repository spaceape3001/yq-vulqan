////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AssetSetter.hpp"
#include <tachyon/api/meta/AssetProperty.hpp>
#include <cassert>

namespace yq::tachyon {
    AssetSetter::AssetSetter(AssetProperty* assetProp, const std::source_location& sl) : Meta("set", assetProp, sl) 
    {
        assert(assetProp);
        assert("no duplicate setters!" && !assetProp->m_setter);    //  duplicate property is an ERROR
        assetProp->m_setter     = this;
    }

    const AssetProperty* AssetSetter::property() const
    {
        return static_cast<const AssetProperty*>(parent());
    }
}
