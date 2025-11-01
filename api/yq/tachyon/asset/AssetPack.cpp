////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AssetPack.hpp"
#include <yq/resource/ResourceLibraryMetaWriter.hpp>
#include <tachyon/asset/CameraSpec.hpp>
#include <tachyon/asset/LightSpec.hpp>
#include <tachyon/asset/MaterialSpec.hpp>
#include <tachyon/asset/Mesh.hpp>
#include <tachyon/asset/Raster.hpp>
#include <tachyon/asset/Sampler.hpp>
#include <tachyon/asset/Sound.hpp>
#include <tachyon/asset/Texture.hpp>
#include <tachyon/asset/Video.hpp>

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
        if(const MaterialSpec* p = dynamic_cast<const MaterialSpec*>(res.ptr()))
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

