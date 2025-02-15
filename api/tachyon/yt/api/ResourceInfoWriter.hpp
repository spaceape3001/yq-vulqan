////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Resource.hpp>
#include <yq/asset/AssetInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class ResourceInfo::Writer : public AssetInfo::Writer<C> {
    public:
        Writer(ResourceInfo* assetInfoPtr) : AssetInfo::Writer<C>(assetInfoPtr)
        {
        }
        
        Writer(ResourceInfo& assetInfoRef) : Writer(&assetInfoRef)
        {
        }
    };
}
