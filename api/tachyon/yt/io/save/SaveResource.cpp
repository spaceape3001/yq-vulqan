////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveResource.hpp"
#include <yt/api/Resource.hpp>

namespace yq::tachyon {
    SaveResource::SaveResource(Save&save, const Resource& ass) : SaveAsset(save, ass)
    {
    }
    
    SaveResource::SaveResource(Save& save, std::string_view k, uint64_t i, const std::filesystem::path& fp) : 
        SaveAsset(save, k, i, fp)
    {
    }
    
    SaveResource::~SaveResource()
    {
    }

    const ResourceInfo* SaveResource::info() const
    {
        return dynamic_cast<const ResourceInfo*>(SaveObject::info());
    }

    bool    SaveResource::valid() const 
    {
        return info() && id();
    }
}
