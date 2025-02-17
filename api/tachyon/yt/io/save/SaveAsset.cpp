////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveAsset.hpp"
#include <yt/io/Save.hpp>
#include <yq/asset/Asset.hpp>

namespace yq::tachyon {
    SaveAsset::SaveAsset(Save&save, const Asset& ass) : SaveObject(save, ass, ass.id()), 
        m_filepath(save.relativize(ass.filepath()))
    {
    }
    
    SaveAsset::SaveAsset(Save&save, const AssetInfo* info, uint64_t i, const std::filesystem::path& fp) : 
        SaveObject(save, info, i), m_filepath(fp)
    {
    }
    
    SaveAsset::~SaveAsset()
    {
    }

    const AssetInfo* SaveAsset::info() const
    {
        return dynamic_cast<const AssetInfo*>(SaveObject::info());
    }

    bool    SaveAsset::valid() const 
    {
        return info() && id();
    }
}
