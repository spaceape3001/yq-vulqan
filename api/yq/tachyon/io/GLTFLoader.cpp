////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "GLTFLoader.hpp"

#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/asset/AssetPak.hpp>
#include <yq/tachyon/asset/CameraSpec.hpp>
#include <yq/tachyon/asset/LightSpec.hpp>
#include <yq/tachyon/asset/Mesh.hpp>
#include <yq/tachyon/asset/Material.hpp>
#include <yq/tachyon/asset/Raster.hpp>
//#include <yq/tachyon/asset/SceneSpec.hpp>
#include <yq/tachyon/asset/Sampler.hpp>
#include <yq/tachyon/asset/Sound.hpp>
#include <yq/tachyon/asset/Texture.hpp>
#include <yq/tachyon/asset/Video.hpp>

#include <yq/tachyon/asset/material/BasicMaterial.hpp>

#include <yq/core/DelayInit.hpp>
#include <yq/file/FileUtils.hpp>
#include <yq/container/ByteArray.hpp>
#include <yq/resource/ResourceDriverAPI.hpp>
#include <yq/text/match.hpp>

#include <yq/resource/Resource.hxx>

#include <tiny_gltf.h>

#include <fstream>

namespace yq::tachyon {
    DataFormat       data_format(const tinygltf::Image& img)
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

    RasterPtr              to_raster(const tinygltf::Image& img)
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

    SamplerPtr              to_sampler(const tinygltf::Sampler& sam)
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
    
    struct GLTFArray {
        tinygltf::Accessor*     acc     = nullptr;
        tinygltf::BufferView*   bv      = nullptr;
        tinygltf::Buffer*       buf     = nullptr;
    };

    
    struct GLTFContext {
        //  TODO >>> AUDIO
        std::vector<CameraSpecPtr>          cameras;
        std::vector<LightSpecPtr>           lights;
        std::vector<MaterialPtr>            materials;
        std::multimap<unsigned, MeshPtr>    meshes;
        //  TODO >>> NODES
        std::vector<RasterPtr>              rasters;
        std::vector<SamplerPtr>             samplers;
        //  TODO >>> SCENES
        std::vector<TexturePtr>             textures;
        
        AssetPak&                           lib;
        const tinygltf::Model&              model;
        const Url                           url;
        unsigned                            meshcnt = 0;
        
        GLTFContext(AssetPak& ap, const tinygltf::Model& mdl) : lib(ap), model(mdl), url(ap.url())
        {
        }

        template <typename T, unsigned int N, typename Pred>
        bool    _visit(const tinygltf::Accessor& acc, Pred pred)
        {
            if(acc.count == 0)
                return false;
            if((acc.bufferView < 0) || (acc.bufferView >= (int) model.bufferViews.size()))
                return false;
            const tinygltf::BufferView& bv  = model.bufferViews[acc.bufferView];
            if((bv.buffer < 0) || (bv.buffer >= (int) model.buffers.size()))
                return false;
            const tinygltf::Buffer& buf = model.buffers[bv.buffer];
            if(buf.data.empty())
                return false;
            
            size_t  base    = bv.byteOffset + acc.byteOffset;
            size_t  stride  = bv.byteStride ? bv.byteStride : sizeof(T);
            if(stride){
                if(stride < sizeof(T))
                    return false;
                if(stride > 252)
                    return false;
            }
            
            if(base + stride * acc.count * N + sizeof(T) > buf.data.size())  // we're going to exceed the buffer...bye
                return false;
           
            const unsigned char*    ptr = buf.data.data();
            T                       data[N];
            for(size_t i=0;i<acc.count;++i){
                for(unsigned n=0;n<N;++n){
                    size_t  m = N*i+n;
                    size_t  u   = base + stride * m;
                    data[n] = *(const T*)(ptr+u);
                }
                
                pred(data);
            }
            return true;
        }
        
        
        std::vector<RGB3F>       _rgb3f(const tinygltf::Accessor& acc, bool loop=false)
        {
            std::vector<RGB3F>   ret;
            ret.reserve(acc.count);
            
            bool    good    = false;
            switch(acc.componentType){
            case TINYGLTF_COMPONENT_TYPE_BYTE:
                //good    = _visit<int8_t,3>(acc, [&](const int8_t values[3]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_BYTE:
                good    = _visit<uint8_t,3>(acc, [&](const uint8_t values[3]){
                    ret.push_back(RGB3F( values[0] / 255.0, values[1] / 255.0, values[2] / 255.0 ));
                });
                break;
            case TINYGLTF_COMPONENT_TYPE_SHORT:
                //good    = _visit<int16_t,3>(acc, [&](const int16_t values[3]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_SHORT:
                good    = _visit<uint16_t,3>(acc, [&](const uint16_t values[3]){
                    ret.push_back(RGB3F(values[0] / 65535.0, values[1] / 65535.0, values[2] / 65535.0 ));
                });
                break;
            case TINYGLTF_COMPONENT_TYPE_INT:
                //good    = _visit<int32_t,3>(acc, [&](const int32_t values[3]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT:
                //good    = _visit<uint32_t,3>(acc, [&](const uint32_t values[3]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_FLOAT:
                good    = _visit<float,3>(acc, [&](const float values[3]){
                    ret.push_back(RGB3F(values[0], values[1], values[2]));
                });
                break;
            case TINYGLTF_COMPONENT_TYPE_DOUBLE:
                good    = _visit<double,3>(acc, [&](const double values[3]){
                    ret.push_back(RGB3F((float) values[0], (float) values[1], (float) values[2]));
                });
                break;
            default:
                break;
            }
            
            if(!good)
                return {};
            if(loop && !ret.empty())
                ret.push_back(ret.front());
            return ret;
        }

        std::vector<RGBA4F>      _rgba4f(const tinygltf::Accessor& acc, bool loop=false)
        {
            std::vector<RGBA4F>   ret;
            ret.reserve(acc.count);
            
            bool    good = false;
            switch(acc.componentType){
            case TINYGLTF_COMPONENT_TYPE_BYTE:
                //good    = _visit<int8_t,4>(acc, [&](const int8_t values[4]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_BYTE:
                good    = _visit<uint8_t,4>(acc, [&](const uint8_t values[4]){
                    ret.push_back(RGBA4F( values[0] / 255.0, values[1] / 255.0, values[2] / 255.0, values[3] / 255.0 ));
                });
                break;
            case TINYGLTF_COMPONENT_TYPE_SHORT:
                //good    = _visit<int16_t,4>(acc, [&](const int16_t values[4]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_SHORT:
                good    = _visit<uint16_t,4>(acc, [&](const uint16_t values[4]){
                    ret.push_back(RGBA4F(values[0] / 65535.0, values[1] / 65535.0, values[2] / 65535.0, values[3] / 65535.0 ));
                });
                break;
            case TINYGLTF_COMPONENT_TYPE_INT:
                //good    = _visit<int32_t,4>(acc, [&](const int32_t values[4]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT:
                //good    = _visit<uint32_t,4>(acc, [&](const uint32_t values[4]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_FLOAT:
                good    = _visit<float,4>(acc, [&](const float values[4]){
                    ret.push_back(RGBA4F(values[0], values[1], values[2], values[3]));
                });
                break;
            case TINYGLTF_COMPONENT_TYPE_DOUBLE:
                good    = _visit<double,4>(acc, [&](const double values[4]){
                    ret.push_back(RGBA4F((float) values[0], (float) values[1], (float) values[2], (float) values[3]));
                });
                break;
            default:
                break;
            }
            
            if(!good)
                return {};

            if(loop && !ret.empty())
                ret.push_back(ret.front());
            return ret;
        }

        std::vector<uint32_t>   _uint32(const tinygltf::Accessor& acc, bool loop=false)
        {
            std::vector<uint32_t>   ret;
            ret.reserve(acc.count);
            
            bool    good = false;
            switch(acc.componentType){
            case TINYGLTF_COMPONENT_TYPE_BYTE:
                good    = _visit<int8_t,1>(acc, [&](const int8_t values[0]){
                    if(values[0] < 0){
                        ret.push_back(0);
                    } else
                        ret.push_back(0);
                });
                break;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_BYTE:
                good    = _visit<uint8_t,1>(acc, [&](const uint8_t values[1]){
                    ret.push_back(values[0]);
                });
                break;
            case TINYGLTF_COMPONENT_TYPE_SHORT:
                good    = _visit<int16_t,1>(acc, [&](const int16_t values[1]){
                    if(values[0] < 0){
                        ret.push_back(0);
                    } else
                        ret.push_back(0);
                });
                break;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_SHORT:
                good    = _visit<uint16_t,1>(acc, [&](const uint16_t values[1]){
                    ret.push_back(values[0]);
                });
                break;
            case TINYGLTF_COMPONENT_TYPE_INT:
                good    = _visit<int32_t,1>(acc, [&](const int32_t values[1]){
                    if(values[0] < 0){
                        ret.push_back(0);
                    } else
                        ret.push_back(0);
                });
                break;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT:
                good    = _visit<uint32_t,1>(acc, [&](const uint32_t values[1]){
                    ret.push_back(values[0]);
                });
                break;
            case TINYGLTF_COMPONENT_TYPE_FLOAT:
                //good    = _visit<float,1>(acc, [&](const float values[1]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_DOUBLE:
                //good    = _visit<double,1>(acc, [&](const double values[1]){
                //});
                break;
            default:
                break;
            }
            
            if(!good)
                return {};
            
            if(loop && !ret.empty())
                ret.push_back(ret.front());
            return ret;
        }

        std::vector<UV2F>       _uv2(const tinygltf::Accessor& acc, bool loop=false)
        {
            std::vector<UV2F>   ret;
            ret.reserve(acc.count);
            
            bool    good = false;
            switch(acc.componentType){
            case TINYGLTF_COMPONENT_TYPE_BYTE:
                //good    = _visit<int8_t,2>(acc, [&](const int8_t values[2]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_BYTE:
                //good    = _visit<uint8_t,2>(acc, [&](const uint8_t values[2]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_SHORT:
                //good    = _visit<int16_t,2>(acc, [&](const int16_t values[2]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_SHORT:
                //good    = _visit<uint16_t,2>(acc, [&](const uint16_t values[2]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_INT:
                //good    = _visit<int32_t,2>(acc, [&](const int32_t values[2]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT:
                //good    = _visit<uint32_t,2>(acc, [&](const uint32_t values[2]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_FLOAT:
                good    = _visit<float,2>(acc, [&](const float values[2]){
                    ret.push_back(UV2F(values[0], values[1]));
                });
                break;
            case TINYGLTF_COMPONENT_TYPE_DOUBLE:
                good    = _visit<double,2>(acc, [&](const double values[2]){
                    ret.push_back(UV2F((float) values[0], (float) values[1]));
                });
                break;
            default:
                break;
            }
            
            if(!good)
                return {};
            if(loop && !ret.empty())
                ret.push_back(ret.front());
            return ret;
        }

        std::vector<UVW3F>       _uvw3(const tinygltf::Accessor& acc, bool loop=false)
        {
            std::vector<UVW3F>   ret;
            ret.reserve(acc.count);
            
            bool    good = false;
            switch(acc.componentType){
            case TINYGLTF_COMPONENT_TYPE_BYTE:
                //good    = _visit<int8_t,3>(acc, [&](const int8_t values[3]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_BYTE:
                //good    = _visit<uint8_t,3>(acc, [&](const uint8_t values[3]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_SHORT:
                //good    = _visit<int16_t,3>(acc, [&](const int16_t values[3]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_SHORT:
                //good    = _visit<uint16_t,3>(acc, [&](const uint16_t values[3]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_INT:
                //good    = _visit<int32_t,3>(acc, [&](const int32_t values[3]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT:
                //good    = _visit<uint32_t,3>(acc, [&](const uint32_t values[3]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_FLOAT:
                good    = _visit<float,3>(acc, [&](const float values[3]){
                    ret.push_back(UVW3F(values[0], values[1], values[2]));
                });
                break;
            case TINYGLTF_COMPONENT_TYPE_DOUBLE:
                good    = _visit<double,3>(acc, [&](const double values[3]){
                    ret.push_back(UVW3F((double) values[0], (double) values[1], (double) values[2]));
                });
                break;
            default:
                break;
            }
            
            if(!good)
                return {};
            if(loop && !ret.empty())
                ret.push_back(ret.front());
            return ret;
        }

        std::vector<Vector2F>   _vector2(const tinygltf::Accessor& acc, bool loop=false)
        {
            std::vector<Vector2F>   ret;
            ret.reserve(acc.count);
            
            bool    good = false;
            switch(acc.componentType){
            case TINYGLTF_COMPONENT_TYPE_BYTE:
                //good    = _visit<int8_t,2>(acc, [&](const int8_t values[2]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_BYTE:
                //good    = _visit<uint8_t,2>(acc, [&](const uint8_t values[2]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_SHORT:
                //good    = _visit<int16_t,2>(acc, [&](const int16_t values[2]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_SHORT:
                //good    = _visit<uint16_t,2>(acc, [&](const uint16_t values[2]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_INT:
                //good    = _visit<int32_t,2>(acc, [&](const int32_t values[2]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT:
                //good    = _visit<uint32_t,2>(acc, [&](const uint32_t values[2]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_FLOAT:
                good    = _visit<float,2>(acc, [&](const float values[2]){
                    ret.push_back(Vector2F(values[0], values[1]));
                });
                break;
            case TINYGLTF_COMPONENT_TYPE_DOUBLE:
                good    = _visit<double,2>(acc, [&](const double values[2]){
                    ret.push_back(Vector2F((float) values[0], (float) values[1]));
                });
                break;
            default:
                break;
            }
            
            if(!good)
                return {};
            if(loop && !ret.empty())
                ret.push_back(ret.front());
            return ret;
        }
        
        std::vector<Vector3F>   _vector3(const tinygltf::Accessor& acc, bool loop=false)
        {
            std::vector<Vector3F>   ret;
            ret.reserve(acc.count);
            
            bool    good = false;
            switch(acc.componentType){
            case TINYGLTF_COMPONENT_TYPE_BYTE:
                //good    = _visit<int8_t,3>(acc, [&](const int8_t values[3]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_BYTE:
                //good    = _visit<uint8_t,3>(acc, [&](const uint8_t values[3]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_SHORT:
                //good    = _visit<int16_t,3>(acc, [&](const int16_t values[3]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_SHORT:
                //good    = _visit<uint16_t,3>(acc, [&](const uint16_t values[3]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_INT:
                //good    = _visit<int32_t,3>(acc, [&](const int32_t values[3]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT:
                //good    = _visit<uint32_t,3>(acc, [&](const uint32_t values[3]){
                //});
                break;
            case TINYGLTF_COMPONENT_TYPE_FLOAT:
                good    = _visit<float,3>(acc, [&](const float values[3]){
                    ret.push_back(Vector3F(values[0], values[1], values[2]));
                });
                break;
            case TINYGLTF_COMPONENT_TYPE_DOUBLE:
                good    = _visit<double,3>(acc, [&](const double values[3]){
                    ret.push_back(Vector3F((float) values[0], (float) values[1], (float) values[2]));
                });
                break;
            default:
                break;
            }
            
            if(!good)
                return {};
            if(loop && !ret.empty())
                ret.push_back(ret.front());
            return ret;
        }
        

        void    operator<<(const tinygltf::Camera& cam)
        {
            // currently fails
            cameras.push_back(nullptr);
        }
        
        void    operator<<(const tinygltf::Image& img)
        {
            RasterPtr   p   = to_raster(img);
            rasters.push_back(p);    // yes, even null pointers
            if(!p){
                tachyonNotice << "GLTF load (" << to_string(url) << "): failed to import image (" << rasters.size() << ")";
                return;
            }
            lib.add(p);
        }

        void    operator<<(const tinygltf::Light& lht)
        {
            // currently fails
            lights.push_back(nullptr);
        }

        void    operator<<(const tinygltf::Material& mat)
        {
            MaterialPtr p   = to_material(mat);
            materials.push_back(p);
            if(!p){
                // currently the above will always fail 
                // tachyonNotice << "GLTF load (" << url << "): failed to import material (" << materials.size() << ")";
                return;
            }
            
            lib.add(p);
        }
        
        void    operator<<(const tinygltf::Sampler& sam)
        {
            SamplerPtr  p   = to_sampler(sam);
            samplers.push_back(p);
            if(!p){
                tachyonNotice << "GLTF load (" << to_string(url) << "): failed to import sampler (" << samplers.size() << ")";
                return;
            }
            lib.add(p);
        }
        
        void    operator<<(const tinygltf::Texture& tex)
        {
            TexturePtr  p   = to_texture(tex);
            textures.push_back(p);
            if(!p){
                tachyonNotice << "GLTF load (" << to_string(url) << "): failed to import texture (" << textures.size() << ")";
                return;
            }
            lib.add(p);
        }

        void    operator<<(const tinygltf::Mesh& msh)
        {
            for(const MeshPtr& p : to_mesh(msh)){
                if(!p)
                    continue;
                meshes.insert({ meshcnt, p });
                lib.add(p);
            }
            ++meshcnt;
        }
        
        MaterialPtr             to_material(const tinygltf::Material&)
        {
            return {};
        }
        
        std::vector<MeshPtr>    to_mesh(const tinygltf::Mesh& msh)
        {
            std::vector<MeshPtr>    ret;
            int                     pcnt    = -1;
            bool                    loop    = false;    // if its a line loop, we'll duplicate points
            
            for(const tinygltf::Primitive& p : msh.primitives){
                ++pcnt;
                
                    // going to ignore the multi...
                    
                MeshPtr         m   = new Mesh;
                switch(p.mode){
                case TINYGLTF_MODE_POINTS:
                    m->topology     = Topology::PointList;
                    break;
                case TINYGLTF_MODE_LINE:
                    m->topology     = Topology::LineList;
                    break;
                case TINYGLTF_MODE_LINE_LOOP:
                    m->topology     = Topology::LineList;
                    loop            = true;
                    break;
                case TINYGLTF_MODE_LINE_STRIP:
                    m->topology     = Topology::LineStrip;
                    break;
                case TINYGLTF_MODE_TRIANGLES:
                    m->topology     = Topology::TriangleList;
                    break;
                case TINYGLTF_MODE_TRIANGLE_STRIP:
                    m->topology     = Topology::TriangleStrip;
                    break;
                case TINYGLTF_MODE_TRIANGLE_FAN:
                    m->topology     = Topology::TriangleFan;
                    break;
                default:            // it's unknown to us
                    continue;  
                }
                
                m->set_name(msh.name);
                
                std::string     key;
                if(msh.name.empty())
                    key    = std::format("{}/{}", meshcnt, pcnt);
                else
                    key    = std::format("{}/{}", msh.name, pcnt);
                m->set_key(key);
                
                if((p.material>=0) && (p.material < (int) materials.size()))
                    m->material = (MaterialCPtr) materials[p.material];
                
                if((p.indices >= 0) && (p.indices < (int) model.accessors.size()))
                    m->index    = _uint32(model.accessors[p.indices], loop);
                    
                //  Add others in as discovered
                
                if(auto i = p.attributes.find("POSITION"); (i != p.attributes.end()) && (i->second >= 0) && (i->second < (int) model.accessors.size())){
                    const tinygltf::Accessor& acc   = model.accessors[i->second];
                    switch(acc.type){
                    case TINYGLTF_TYPE_VEC2:
                        m->xy           = _vector2(acc, loop);
                        break;
                    case TINYGLTF_TYPE_VEC3:
                        m->xyz          = _vector3(acc, loop);
                        break;
                    }
                }

                if(auto i = p.attributes.find("NORMAL"); (i != p.attributes.end()) && (i->second >= 0) && (i->second < (int) model.accessors.size())){
                    const tinygltf::Accessor& acc   = model.accessors[i->second];
                    switch(acc.type){
                    case TINYGLTF_TYPE_VEC3:
                        m->normal         = _vector3(acc, loop);
                        break;
                    }
                }

                if(auto i = p.attributes.find("TEXCOORD_0"); (i != p.attributes.end()) && (i->second >= 0) && (i->second < (int) model.accessors.size())){
                    const tinygltf::Accessor& acc   = model.accessors[i->second];
                    switch(acc.type){
                    case TINYGLTF_TYPE_VEC2:
                        m->uv           = _uv2(acc, loop);
                        break;
                    case TINYGLTF_TYPE_VEC3:
                        m->uvw          = _uvw3(acc, loop);
                        break;
                    }
                }
                
                ret.push_back(m);
            }

            return ret;
        }
        
        TexturePtr              to_texture(const tinygltf::Texture&tex)
        {
            SamplerCPtr  sam;
            RasterCPtr   ras;
            
            if(tex.sampler >= (int) samplers.size()){
                tachyonNotice << "GLTF load (" << to_string(url) << "): texture has a bad sampler!";
                return {};
            }
            
            if(tex.sampler >= 0){
                sam = samplers[tex.sampler].ptr();
                if(!sam)
                    tachyonNotice << "GLTF load (" << to_string(url) << "): texture references a bad sampler!";
            }
            
            if(!sam)
                sam     = Sampler::simple();
            
            if((tex.source < 0) || (tex.source >= (int) rasters.size())){
                tachyonNotice << "GLTF load (" << to_string(url) << "): texture has a bad source!";
                return {};
            }
            
            ras     = rasters[tex.source].ptr();
            if(!ras)
                tachyonNotice << "GLTF load (" << to_string(url) << "): texture references a bad image!";
            
            TexturePtr  ret = new Texture(ras, sam);
            ret -> set_name(tex.name);
            return ret;
        }
    };
        
    AssetPakPtr     to_assetpak(const tinygltf::Model&model)
    {
        return to_assetpak(model, {});
    }

    AssetPakPtr     to_assetpak(const tinygltf::Model& model, const Url& url)
    {
        AssetPakPtr        lib = new AssetPak;
        lib -> set_url(url);
        GLTFContext         ctx(*lib, model);
    
        //for(const auto& cam : model.cameras)
            //ctx << cam;
        for(const auto& img : model.images)
            ctx << img;
        //for(const auto& lht : model.lights)
            //ctx << lht;
        for(const auto& sam : model.samplers)
            ctx << sam;
        for(const auto& tex : model.textures)
            ctx << tex;
        for(const auto& mat : model.materials)
            ctx << mat;
        for(const auto& msh : model.meshes)
            ctx << msh;
            
        // TODO (if we want more)
    
        return lib;
    }


    /////////////////////////////////////////////////////////////////
    //  FILE/BUFFER LOADING (RAW)

    tinygltf::ModelSPtr     raw_load_gltf(const std::filesystem::path& fp)
    {
        std::string ext = fp.extension();
        if(is_similar(ext, ".gltf"))
            return raw_load_gltf(TEXT, fp);
        if(is_similar(ext, ".glb"))
            return raw_load_gltf(BINARY, fp);
        return {};
    }

    tinygltf::ModelSPtr     raw_load_gltf(binary_k, const ByteArray& data)
    {
        tinygltf::ModelSPtr ret = std::make_shared<tinygltf::Model>();
        tinygltf::TinyGLTF gltfContext;
		std::string error, warning;
        
        bool loaded = gltfContext.LoadBinaryFromMemory(ret.get(), &error, &warning, (const unsigned char*) data.data(), data.size());
        if(!error.empty())
            tachyonWarning << "GLTF load (raw binary): " << error;
        if(!warning.empty())
            tachyonNotice << "GLTF load (raw binary): " << warning;
        if(!loaded)
            return {};
        return ret;
    }
    
    tinygltf::ModelSPtr     raw_load_gltf(binary_k, const std::filesystem::path& fp)
    {
        tinygltf::ModelSPtr ret = std::make_shared<tinygltf::Model>();
        tinygltf::TinyGLTF gltfContext;
		std::string error, warning;
        
        bool loaded = gltfContext.LoadBinaryFromFile(ret.get(), &error, &warning, fp.c_str());
        if(!error.empty())
            tachyonWarning << "GLTF load (" << fp << "): " << error;
        if(!warning.empty())
            tachyonNotice << "GLTF load (" << fp << "): " << warning;
        if(!loaded)
            return {};
        return ret;
    }
    

    tinygltf::ModelSPtr     raw_load_gltf(text_k, const std::filesystem::path& fp)
    {
        tinygltf::ModelSPtr ret = std::make_shared<tinygltf::Model>();
        tinygltf::TinyGLTF gltfContext;
		std::string error, warning;
        
        bool loaded = gltfContext.LoadASCIIFromFile(ret.get(), &error, &warning, fp.c_str());
        if(!error.empty())
            tachyonWarning << "GLTF load (" << fp << "): " << error;
        if(!warning.empty())
            tachyonNotice << "GLTF load (" << fp << "): " << warning;
        if(!loaded)
            return {};
        return ret;
    }

    tinygltf::ModelSPtr     raw_load_gltf(text_k, const std::string& data, const std::filesystem::path& directory)
    {
        tinygltf::ModelSPtr ret = std::make_shared<tinygltf::Model>();
        tinygltf::TinyGLTF gltfContext;
		std::string error, warning;
        
        bool loaded = gltfContext.LoadASCIIFromString(ret.get(), &error, &warning, data.c_str(), data.size(), directory.string());
        if(!error.empty())
            tachyonWarning << "GLTF load (file from " << directory << "): " << error;
        if(!warning.empty())
            tachyonNotice << "GLTF load (file from " << directory << "): " << warning;
        if(!loaded)
            return {};
        return ret;
    }
    
    /////////////////////////////////////////////////////////////////
    //  Resource adapter (& public load API)
    
    AssetPakCPtr     loadGLTF(const std::filesystem::path& fp)
    {
        auto mdl    = raw_load_gltf(fp);
        if(!mdl){
            tachyonWarning << "Unable to read/parse GLTF/GLB: " << fp;
            return {};
        }
        
        return to_assetpak(*mdl, to_url(fp));
    }

    AssetPakPtr     loadGLTF_binary(const ByteArray& iData, const ResourceLoadAPI& api)
    {
        auto mdl    = raw_load_gltf(BINARY, iData);
        if(!mdl){
            tachyonWarning << "Unable to parse GLB: " << to_string(api.url());
            return {};
        }
        return to_assetpak(*mdl, api.url());
    }

    AssetPakPtr    loadGLTF_string(const std::string& iData, const ResourceLoadAPI& api)
    {
        auto mdl    = raw_load_gltf(TEXT, iData, api.url().path);
        if(!mdl){
            tachyonWarning << "Unable to parse GLTF: " << to_string(api.url()) << " (cannot open/read the file)";
            return {};
        }
        return to_assetpak(*mdl, api.url());
    }

    static void reg_gltf()
    {
        ResourceLibrary::IO::add_loader({.extensions = { "glb" }}, loadGLTF_binary);
        ResourceLibrary::IO::add_loader({.extensions = { "gltf" }}, loadGLTF_string);
    }

    YQ_INVOKE( reg_gltf(); )

    
}
