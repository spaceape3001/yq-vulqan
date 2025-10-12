////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "GLTFLoader.hpp"

#include <tachyon/logging.hpp>
#include <tachyon/asset/AssetPack.hpp>
#include <tachyon/asset/CameraSpec.hpp>
#include <tachyon/asset/LightSpec.hpp>
#include <tachyon/asset/Mesh.hpp>
#include <tachyon/asset/MaterialSpec.hpp>
#include <tachyon/asset/Raster.hpp>
//#include <tachyon/asset/SceneSpec.hpp>
#include <tachyon/asset/Sampler.hpp>
#include <tachyon/asset/Sound.hpp>
#include <tachyon/asset/Texture.hpp>
#include <tachyon/asset/Video.hpp>

#include <yq/file/FileUtils.hpp>
#include <yq/resource/ResourceDriverAPI.hpp>
#include <yq/resource/Resource.hxx>
#include <yq/core/DelayInit.hpp>
#include <yq/container/ByteArray.hpp>

#include <tiny_gltf.h>

#include <fstream>

namespace yq::tachyon {


    static DataFormat       data_format(const tinygltf::Image& img)
    {
        switch(img.component){
        case 1:
            switch(img.pixel_type){
            case TINYGLTF_COMPONENT_TYPE_BYTE:
                return DataFormat::R8_SINT;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_BYTE:
                return DataFormat::R8_UINT;
            case TINYGLTF_COMPONENT_TYPE_SHORT:
                return DataFormat::R16_SINT;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_SHORT:
                return DataFormat::R16_UINT;
            case TINYGLTF_COMPONENT_TYPE_INT:
                return DataFormat::R32_SINT;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT:
                return DataFormat::R32_UINT;
            case TINYGLTF_COMPONENT_TYPE_FLOAT:
                return DataFormat::R32_SFLOAT;
            case TINYGLTF_COMPONENT_TYPE_DOUBLE:    
                return DataFormat::R64_SFLOAT;
            }
            break;
        case 2:
            switch(img.pixel_type){
            case TINYGLTF_COMPONENT_TYPE_BYTE:
                return DataFormat::R8G8_SINT;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_BYTE:
                return DataFormat::R8G8_UINT;
            case TINYGLTF_COMPONENT_TYPE_SHORT:
                return DataFormat::R16G16_SINT;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_SHORT:
                return DataFormat::R16G16_UINT;
            case TINYGLTF_COMPONENT_TYPE_INT:
                return DataFormat::R32G32_SINT;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT:
                return DataFormat::R32G32_UINT;
            case TINYGLTF_COMPONENT_TYPE_FLOAT:
                return DataFormat::R32G32_SFLOAT;
            case TINYGLTF_COMPONENT_TYPE_DOUBLE:    
                return DataFormat::R64G64_SFLOAT;
            }
            break;
        case 3:
            switch(img.pixel_type){
            case TINYGLTF_COMPONENT_TYPE_BYTE:
                return DataFormat::R8G8B8_SINT;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_BYTE:
                return DataFormat::R8G8B8_UINT;
            case TINYGLTF_COMPONENT_TYPE_SHORT:
                return DataFormat::R16G16B16_SINT;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_SHORT:
                return DataFormat::R16G16B16_UINT;
            case TINYGLTF_COMPONENT_TYPE_INT:
                return DataFormat::R32G32B32_SINT;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT:
                return DataFormat::R32G32B32_UINT;
            case TINYGLTF_COMPONENT_TYPE_FLOAT:
                return DataFormat::R32G32B32_SFLOAT;
            case TINYGLTF_COMPONENT_TYPE_DOUBLE:    
                return DataFormat::R64G64B64_SFLOAT;
            }
            break;
        case 4:
            switch(img.pixel_type){
            case TINYGLTF_COMPONENT_TYPE_BYTE:
                return DataFormat::R8G8B8A8_SINT;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_BYTE:
                return DataFormat::R8G8B8A8_UINT;
            case TINYGLTF_COMPONENT_TYPE_SHORT:
                return DataFormat::R16G16B16A16_SINT;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_SHORT:
                return DataFormat::R16G16B16A16_UINT;
            case TINYGLTF_COMPONENT_TYPE_INT:
                return DataFormat::R32G32B32A32_SINT;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT:
                return DataFormat::R32G32B32A32_UINT;
            case TINYGLTF_COMPONENT_TYPE_FLOAT:
                return DataFormat::R32G32B32A32_SFLOAT;
            case TINYGLTF_COMPONENT_TYPE_DOUBLE:    
                return DataFormat::R64G64B64A64_SFLOAT;
            }
            break;
        default:
            break;
        };
        return DataFormat::UNDEFINED;
    }
    
    template <typename T>
    bool        copy_in(Memory& mem, const tinygltf::Image& img, T alpha)
    {
        using rgb_t     = RGB<T>;
        using rgba_t    = RGBA<T>;
    
        size_t  cnt = (size_t) img.width * (size_t) img.height;
        size_t  pixs    = img.image.size() / sizeof(rgb_t);
        if(pixs < cnt)
            return false;
        std::span<const rgb_t> orig((const rgb_t*) img.image.data(), pixs);
        std::vector<rgba_t> tgt;
        for(size_t n=0;n<cnt;++n){
            auto& v     = orig[n];
            tgt[n]  = { v.red, v.green, v.blue, alpha };
        }
        mem = Memory(COPY, tgt);
        return true;
    }

    static RasterPtr              to_raster(const tinygltf::Image& img)
    {
        if(img.width<=0)
            return {};
        if(img.height<=0)
            return {};
        if(img.image.empty())
            return {};

        RasterInfo      info;
        Memory          memory;
        
        info.size.x = std::max(0, img.width);
        info.size.y = std::max(0, img.height);
        info.size.z = 1;
        info.size.w = 1;
        
        info.format         = data_format(img);
        switch(info.format){
        case DataFormat::UNDEFINED:
            return {};
        case DataFormat::R8G8B8_SINT:
            if(!copy_in<int8_t>(memory, img, 127))
                return {};
            info.format = DataFormat::R8G8B8A8_SINT;
            break;
        case DataFormat::R8G8B8A8_UINT:
            if(!copy_in<uint8_t>(memory, img, 255))
                return {};
            info.format = DataFormat::R8G8B8A8_UINT;
            break;
        case DataFormat::R16G16B16_SINT:
            if(!copy_in<int16_t>(memory, img, 32767))
                return {};
            info.format = DataFormat::R16G16B16A16_SINT;
            break;
        case DataFormat::R16G16B16_UINT:
            if(!copy_in<uint16_t>(memory, img, 65535))
                return {};
            info.format = DataFormat::R16G16B16A16_UINT;
            break;
        case DataFormat::R32G32B32_SINT:
            if(!copy_in<int32_t>(memory, img, 0x7FFFFFFF))
                return {};
            info.format = DataFormat::R32G32B32A32_SINT;
            break;
        case DataFormat::R32G32B32A32_UINT:
            if(!copy_in<uint32_t>(memory, img, 0xFFFFFFFF))
                return {};
            info.format = DataFormat::R32G32B32A32_UINT;
            break;
        case DataFormat::R32G32B32_SFLOAT:
            if(!copy_in<float>(memory, img, 1.f))
                return {};
            info.format = DataFormat::R32G32B32A32_SFLOAT;
            break;
        case DataFormat::R64G64B64_SFLOAT:
            if(!copy_in<double>(memory, img, 1.))
                return {};
            info.format = DataFormat::R64G64B64A64_SFLOAT;
            break;
        default:
            memory.set(img.image.data(), img.image.size());
            break;
        }
        
        RasterPtr ret =  new Raster(info, std::move(memory));
        ret->set_name(img.name);
        return ret;
    }

    static SamplerPtr              to_sampler(const tinygltf::Sampler& sam)
    {
        SamplerInfo info;
        
        switch(sam.minFilter){
        case -1:
            break;
        case 9728:  // nearest
            info.minFilter      = SamplerFilter::Nearest;
            break;
        case 9729:  // linear
            info.minFilter      = SamplerFilter::Linear;
            break;
        // ignoring mipmap
        }

        switch(sam.magFilter){
        case -1:
            break;
        case 9728:  // nearest
            info.magFilter      = SamplerFilter::Nearest;
            break;
        case 9729:  // linear
            info.magFilter      = SamplerFilter::Linear;
            break;
        }
        
        switch(sam.wrapS){
        case 33071: // clamp to edge
            info.addressMode.u  = SamplerAddressMode::ClampToEdge;
            break;
        case 33648: // mirrored repeat
            info.addressMode.u  = SamplerAddressMode::MirroredRepeat;
            break;
        case 10497: // repeat
            info.addressMode.u  = SamplerAddressMode::Repeat;
            break;
        }

        switch(sam.wrapT){
        case 33071: // clamp to edge
            info.addressMode.v  = SamplerAddressMode::ClampToEdge;
            break;
        case 33648: // mirrored repeat
            info.addressMode.v  = SamplerAddressMode::MirroredRepeat;
            break;
        case 10497: // repeat
            info.addressMode.v  = SamplerAddressMode::Repeat;
            break;
        }
        
        SamplerPtr ret = new Sampler(info);
        ret -> set_name(sam.name);
        return ret;
    }

    
    struct GLTFContext {
        std::vector<CameraSpecPtr>      cameras;
        std::vector<LightSpecPtr>       lights;
        std::vector<MaterialSpecPtr>    materials;
        std::vector<MeshPtr>            meshes;
        std::vector<RasterPtr>          rasters;
        std::vector<SamplerPtr>         samplers;
        std::vector<TexturePtr>         textures;
        
        AssetPack&                      lib;
        std::string                     path;
        
        GLTFContext(AssetPack& ap) : lib(ap)
        {
            path    = ap.url().path;
        }
        
        void    operator<<(const tinygltf::Image& img)
        {
            RasterPtr   p   = to_raster(img);
            rasters.push_back(p);    // yes, even null pointers
            if(!p){
                tachyonNotice << "GLTF load (" << path << "): failed to import image (" << rasters.size() << ")";
                return;
            }
            lib.add(p);
        }
        
        void    operator<<(const tinygltf::Sampler& sam)
        {
            SamplerPtr  p   = to_sampler(sam);
            samplers.push_back(p);
            if(!p){
                tachyonNotice << "GLTF load (" << path << "): failed to import sampler (" << samplers.size() << ")";
                return;
            }
            lib.add(p);
        }
        
        void    operator<<(const tinygltf::Texture& tex)
        {
            TexturePtr  p   = to_texture(tex);
            textures.push_back(p);
            if(!p){
                tachyonNotice << "GLTF load (" << path << "): failed to import texture (" << textures.size() << ")";
                return;
            }
            lib.add(p);
        }
        

        TexturePtr   to_texture(const tinygltf::Texture& tex)
        {
            SamplerCPtr  sam;
            RasterCPtr   ras;
            
            if(tex.sampler >= (int) samplers.size()){
                tachyonNotice << "GLTF load (" << path << "): texture has a bad sampler!";
                return {};
            }
            
            if(tex.sampler >= 0){
                sam = samplers[tex.sampler].ptr();
                if(!sam)
                    tachyonNotice << "GLTF load (" << path << "): texture references a bad sampler!";
            }
            
            if(!sam)
                sam     = Sampler::simple();
            
            if((tex.source < 0) || (tex.source >= (int) rasters.size())){
                tachyonNotice << "GLTF load (" << path << "): texture has a bad source!";
                return {};
            }
            
            ras     = rasters[tex.source].ptr();
            if(!ras)
                tachyonNotice << "GLTF load (" << path << "): texture references a bad image!";
            
            TexturePtr  ret = new Texture(ras, sam);
            ret -> set_name(tex.name);
            return ret;
        }

    };


    AssetPackPtr     gltfLoad(const tinygltf::Model& input, const Url& url)
    {
        AssetPackPtr        lib = new AssetPack;
        lib -> set_url(url);
        GLTFContext         ctx(*lib);
    
        for(const auto& img : input.images)
            ctx << img;
        for(const auto& sam : input.samplers)
            ctx << sam;
        for(const auto& tex : input.textures)
            ctx << tex;
            
        // TODO
        
    
        return lib;
    }

    AssetPackPtr     gltfLoad(const ByteArray& iData, const Url& url)
    {
        tinygltf::Model glTFInput;
        tinygltf::TinyGLTF gltfContext;
		std::string error, warning;

        bool loaded = gltfContext.LoadBinaryFromMemory(&glTFInput, &error, &warning, (const unsigned char*) iData.data(), iData.size());
        if(!error.empty())
            tachyonWarning << "GLTF load (" << url.path << "): " << error;
        if(!warning.empty())
            tachyonNotice << "GLTF load (" << url.path << "): " << warning;
        if(!loaded)
            return {};
        return gltfLoad(glTFInput, url);
    }

    AssetPackPtr     gltfLoad(const std::string& iData, const Url& url)
    {
        tinygltf::Model glTFInput;
        tinygltf::TinyGLTF gltfContext;
		std::string error, warning;
        std::string basedir = std::filesystem::path(url.path).parent_path().string();
        
        bool loaded = gltfContext.LoadASCIIFromString(&glTFInput, &error, &warning, iData.c_str(), iData.size(), basedir);
        if(!error.empty())
            tachyonWarning << "GLTF load (" << url.path << "): " << error;
        if(!warning.empty())
            tachyonNotice << "GLTF load (" << url.path << "): " << warning;
        if(!loaded)
            return {};
        return gltfLoad(glTFInput, url);
    }

    AssetPackPtr    loadGLTF_binary(const ByteArray& iData, const ResourceLoadAPI& api)
    {
        return gltfLoad(iData, api.url());
    }

    AssetPackPtr    loadGLTF_string(const std::string& iData, const ResourceLoadAPI& api)
    {
        return gltfLoad(iData, api.url());
    }

    static void reg_gltf()
    {
        ResourceLibrary::IO::add_loader({.extensions = { "glb" }}, loadGLTF_binary);
        ResourceLibrary::IO::add_loader({.extensions = { "gltf" }}, loadGLTF_string);
    }

    YQ_INVOKE( reg_gltf(); )

    AssetPackCPtr     loadGLTF(const std::filesystem::path& fp)
    {
        ByteArray   bytes   = file_bytes(fp);
        if(bytes.size() < 20){
            tachyonWarning << "Unable to load GLTF: " << fp << " (cannot open/read the file)";
            return {};
        }
        return gltfLoad(bytes, to_url(fp));
    }
}
