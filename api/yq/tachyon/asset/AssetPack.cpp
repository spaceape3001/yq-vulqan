////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AssetPack.hpp"
#include <yq/resource/ResourceLibraryMetaWriter.hpp>
#include <yq/tachyon/asset/CameraSpec.hpp>
#include <yq/tachyon/asset/LightSpec.hpp>
#include <yq/tachyon/asset/Material.hpp>
#include <yq/tachyon/asset/Mesh.hpp>
#include <yq/tachyon/asset/Raster.hpp>
#include <yq/tachyon/asset/Sampler.hpp>
#include <yq/tachyon/asset/Sound.hpp>
#include <yq/tachyon/asset/Texture.hpp>
#include <yq/tachyon/asset/Video.hpp>

namespace yq::tachyon {
    void AssetPack::init_meta()
    {   
        auto w = writer<AssetPack>();
        w.description("Asset Library");
    }

    AssetPack::AssetPack()
    {
    }
    
    AssetPack::~AssetPack()
    {
    }

    void    AssetPack::post_add(ResourcePtr res) 
    {
        if(const CameraSpec* p = dynamic_cast<const CameraSpec*>(res.ptr()))
            m_cameras.push_back(p);
        if(const LightSpec* p = dynamic_cast<const LightSpec*>(res.ptr()))
            m_lights.push_back(p);
        if(const Material* p = dynamic_cast<const Material*>(res.ptr()))
            m_materials.push_back(p);
        if(const Mesh* p = dynamic_cast<const Mesh*>(res.ptr()))
            m_meshes.push_back(p);
        if(const Raster* p = dynamic_cast<const Raster*>(res.ptr()))
            m_rasters.push_back(p);
        if(const Sampler* p = dynamic_cast<const Sampler*>(res.ptr()))
            m_samplers.push_back(p);
        if(const Sound* p = dynamic_cast<const Sound*>(res.ptr()))
            m_sounds.push_back(p);
        if(const Texture* p = dynamic_cast<const Texture*>(res.ptr()))
            m_textures.push_back(p);
        if(const Video* p = dynamic_cast<const Video*>(res.ptr()))
            m_videos.push_back(p);
    }
}

YQ_RESOURCE_IMPLEMENT(yq::tachyon::AssetPack)

