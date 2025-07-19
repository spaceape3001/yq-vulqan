////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveResource.hpp"
#include <tachyon/io/Save.hpp>
#include <yq/resource/Resource.hpp>

namespace yq::tachyon {
    SaveResource::SaveResource(Save&save, const Resource& ass) : SaveObject(save, ass, ass.id()), 
        m_filepath(save.relativize(ass.filepath()))
    {
    }
    
    SaveResource::SaveResource(Save&save, const ResourceMeta* info, uint64_t i, const std::filesystem::path& fp) : 
        SaveObject(save, info, i), m_filepath(fp)
    {
    }
    
    SaveResource::~SaveResource()
    {
    }

    const ResourceMeta* SaveResource::info() const
    {
        return dynamic_cast<const ResourceMeta*>(SaveObject::info());
    }

    bool    SaveResource::valid() const 
    {
        return info() && id();
    }
}
