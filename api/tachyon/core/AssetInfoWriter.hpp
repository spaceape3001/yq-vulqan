////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/core/Asset.hpp>
#include <meta/ObjectInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class AssetInfo::Writer : public ObjectInfo::Writer<C> {
    public:
        Writer(AssetInfo* assetInfo) : ObjectInfo::Writer<C>(assetInfo)
        {
        }
        
        Writer(AssetInfo& assetInfo) : Writer(&assetInfo)
        {
        }
    };
}
