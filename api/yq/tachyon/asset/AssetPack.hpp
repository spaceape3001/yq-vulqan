////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/resource/ResourceLibrary.hpp>
#include <yq/tachyon/typedef/asset_pack.hpp>
#include <yq/tachyon/typedef/camera_spec.hpp>
#include <yq/tachyon/typedef/light_spec.hpp>
#include <yq/tachyon/typedef/material_spec.hpp>
#include <yq/tachyon/typedef/mesh.hpp>
#include <yq/tachyon/typedef/raster.hpp>
#include <yq/tachyon/typedef/sampler.hpp>
#include <yq/tachyon/typedef/sound.hpp>
#include <yq/tachyon/typedef/texture.hpp>
#include <yq/tachyon/typedef/video.hpp>

namespace yq::tachyon {

    //! An asset pac
    //! \note This will NOT instantiate any tachyons (not directly)
    class AssetPack : public ResourceLibrary {
        YQ_RESOURCE_DECLARE(AssetPack, ResourceLibrary)
    public:
        AssetPack();
        ~AssetPack();
        
        static void init_meta();
        
        const auto& cameras() const { return m_cameras; }
        const auto& lights() const { return m_lights; }
        const auto& materials() const { return m_materials; }
        const auto& meshes() const { return m_meshes; }
        const auto& rasters() const { return m_rasters; }
        const auto& samplers() const { return m_samplers; }
        const auto& sounds() const { return m_sounds; }
        const auto& textures() const { return m_textures; }
        const auto& videos() const { return m_videos; }
        
    protected:
        virtual void    post_add(ResourcePtr) override;
        
    private:
        std::vector<CameraSpecCPtr>     m_cameras;
        std::vector<LightSpecCPtr>      m_lights;
        std::vector<MaterialSpecCPtr>   m_materials;
        std::vector<MeshCPtr>           m_meshes;
        std::vector<RasterCPtr>         m_rasters;
        std::vector<SamplerCPtr>        m_samplers;
        std::vector<SoundCPtr>          m_sounds;
        std::vector<TextureCPtr>        m_textures;
        std::vector<VideoCPtr>          m_videos;
    };
}
