////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AssetProperty.hpp"
#include <yq/asset/Asset.hpp>
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/api/meta/AssetGetter.hpp>
#include <tachyon/api/meta/AssetSetter.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/errors.hpp>

namespace yq::tachyon {
    AssetProperty::AssetProperty(std::string_view zName, const std::source_location& sl, const AssetMeta& theAsset, ObjectInfo* parent) :
        Meta(zName, parent, sl), m_asset(theAsset)
    {
        assert(parent);
        
        if(TachyonInfo* ti = dynamic_cast<TachyonInfo*>(parent)){
            if(ti->m_assets.local.keys.has(zName))
                tachyonCritical << "AssetProperty::AssetProperty(" << parent->name() << "." << zName << ") -- duplicate detected!";
            ti->m_assets.local << this;
        }
    }

    AssetCPtr           AssetProperty::get(const Object*tac) const
    {
        if(!m_getter)
            return {};
        return m_getter -> get(tac);
    }
    
    std::error_code     AssetProperty::set(Object*tac, const AssetCPtr& ap) const
    {
        if(!m_setter)
            return errors::no_setter();
        return m_setter->set(tac, ap);
    }
}
