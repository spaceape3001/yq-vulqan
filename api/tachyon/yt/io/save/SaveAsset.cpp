////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveAsset.hpp"
#include <yq/asset/Asset.hpp>

namespace yq::tachyon {
    SaveAsset::SaveAsset(Save&save, const Asset& ass) : SaveObject(save, ass, ass.id()), m_filepath(ass.filepath())
    {
    }
    
    SaveAsset::SaveAsset(Save&save, std::string_view k, uint64_t i, const std::filesystem::path& fp) : SaveObject(save, k, i), m_filepath(fp)
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
