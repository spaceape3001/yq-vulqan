////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/asset/Asset.hpp>
#include <basic/meta/ObjectInfoWriter.hpp>

namespace yq {
    namespace tachyon {
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
}
