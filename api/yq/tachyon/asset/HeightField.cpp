////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////


#include <yq/tachyon/asset/Raster.hpp>
#include <yq/tachyon/asset/Sampler.hpp>
#include <yq/tachyon/asset/HeightField.hpp>
#include <yq/tachyon/utility/extract.hpp>
#include <yq/resource/ResourceMetaWriter.hpp>

namespace yq::tachyon {
#if 0
    void HeightField::init_meta()
    {
        auto w = writer<HeightField>();
        w.description("HeightField");
    }

    HeightFieldCPtr  HeightField::load(std::string_view pp)
    {
        return load(pp, Sampler::simple(), TextureInfo());
    }
    
    HeightFieldCPtr  HeightField::load(std::string_view pp, const SamplerCPtr& _sampler, const TextureInfo& _info)
    {
        if(!_sampler)
            return {};
        RasterCPtr   img = Raster::IO::load(pp);
        if(!img)
            return {};
        return new HeightField(img, _sampler, _info);
    }

    HeightFieldCPtr  HeightField::load(std::string_view pp, const TextureInfo2& texInfo)
    {
        return load(pp, new Sampler(texInfo), texInfo);
    }
    
    HeightFieldCPtr  HeightField::load(std::string_view pp, const TextureInfo& texInfo)
    {
        return load(pp, Sampler::simple(), texInfo);
    }


    // ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    HeightField::HeightField(RasterCPtr img) : HeightField(img, Sampler::simple())
    {
    }
    
    HeightField::HeightField(RasterCPtr img, const TextureInfo& texInfo) : HeightField(img, Sampler::simple(), texInfo)
    {
    }

    HeightField::HeightField(RasterCPtr img, const TextureInfo2& texInfo) : HeightField(img, new Sampler(texInfo), texInfo)
    {
    }

    HeightField::HeightField(RasterCPtr img, const SamplerCPtr& _sampler, const TextureInfo& _info) : 
        gridded(img), sampler(_sampler), info(_info)
    {
    }

    
    HeightField::~HeightField()
    {
    }
#endif

    HeightFieldCPtr     load_heightfield(const Url& u)
    {
        ResourceCPtr    res = Resource::resource_load({&meta<Texture>(), &meta<Raster>()}, u);
        if(!res)
            return {};
        if(const HeightField* h = dynamic_cast<const HeightField*>(res.ptr()))
            return h;
        if(const Raster* r = dynamic_cast<const Raster*>(res.ptr())){
            TextureInfo2    texInfo;
            // if we need to tweak...
            return new Texture(r, texInfo);
        }
        return {};
    }
    
    template <typename U, typename Pred >
    std::pair<float, float> minmax_of(const Memory& mem, Pred&& pred)
    {
        assert(sizeof(U) == mem.stride());
        
        const U*    data    = (const U*) mem.data();
        float   min, max;
        min = max = pred(*data);
        
        for(size_t n=1;n<mem.count();++n){
            float   v   = pred(data[n]);
            min = std::min(min, v);
            max = std::max(max, v);
        }
        return {min,max};
    }
    


    std::pair<float,float>  minmax_elevation(const HeightField& height)
    {
        if(height.images.empty())
            return {};
        if(!height.images[0])
            return {};
        
        const Raster& ras   = *(height.images[0]);
        if(ras.memory.count() == 0)
            return {};
            
        std::pair<float,float>  ret{};
        switch(ras.info.format){
        case DataFormat::R8_SINT:
            return minmax_of<int8_t>(ras.memory, x1_int8);
        case DataFormat::R8_UINT:
            return minmax_of<uint8_t>(ras.memory, x1_uint8);
        case DataFormat::R8G8_SINT:
            return minmax_of<glm::i8vec2>(ras.memory, x1_vec2i8);
        case DataFormat::R8G8_UINT:
            return minmax_of<glm::u8vec2>(ras.memory, x1_vec2u8);
        case DataFormat::R8G8B8_SINT:
            return minmax_of<glm::i8vec3>(ras.memory, x1_vec3i8);
        case DataFormat::R8G8B8_UINT:
            return minmax_of<glm::u8vec3>(ras.memory, x1_vec3u8);
        case DataFormat::R8G8B8A8_SINT:
            return minmax_of<glm::i8vec4>(ras.memory, x1_vec4i8);
        case DataFormat::R8G8B8A8_UINT:
            return minmax_of<glm::u8vec4>(ras.memory, x1_vec4u8);

        case DataFormat::R16_SINT:
            return minmax_of<int16_t>(ras.memory, x1_int16);
        case DataFormat::R16_UINT:
            return minmax_of<uint16_t>(ras.memory, x1_uint16);
        case DataFormat::R16G16_SINT:
            return minmax_of<glm::i16vec2>(ras.memory, x1_vec2i16);
        case DataFormat::R16G16_UINT:
            return minmax_of<glm::u16vec2>(ras.memory, x1_vec2u16);
        case DataFormat::R16G16B16_SINT:
            return minmax_of<glm::i16vec3>(ras.memory, x1_vec3i16);
        case DataFormat::R16G16B16_UINT:
            return minmax_of<glm::u16vec3>(ras.memory, x1_vec3u16);
        case DataFormat::R16G16B16A16_SINT:
            return minmax_of<glm::ivec4>(ras.memory, x1_vec4i16);
        case DataFormat::R16G16B16A16_UINT:
            return minmax_of<glm::uvec4>(ras.memory, x1_vec4u16);

        case DataFormat::R32_SFLOAT:
            return minmax_of<float>(ras.memory, x1_float);
        case DataFormat::R32_SINT:
            return minmax_of<int32_t>(ras.memory, x1_int32);
        case DataFormat::R32_UINT:
            return minmax_of<uint32_t>(ras.memory, x1_uint32);
        case DataFormat::R32G32_SFLOAT:
            return minmax_of<glm::vec2>(ras.memory, x1_vec2f);
        case DataFormat::R32G32_SINT:
            return minmax_of<glm::i32vec2>(ras.memory, x1_vec2i32);
        case DataFormat::R32G32_UINT:
            return minmax_of<glm::u32vec2>(ras.memory, x1_vec2u32);
        case DataFormat::R32G32B32_SFLOAT:
            return minmax_of<glm::vec3>(ras.memory, x1_vec3f);
        case DataFormat::R32G32B32_SINT:
            return minmax_of<glm::i32vec3>(ras.memory, x1_vec3i32);
        case DataFormat::R32G32B32_UINT:
            return minmax_of<glm::u32vec3>(ras.memory, x1_vec3u32);
        case DataFormat::R32G32B32A32_SFLOAT:
            return minmax_of<glm::vec4>(ras.memory, x1_vec4f);
        case DataFormat::R32G32B32A32_SINT:
            return minmax_of<glm::i32vec4>(ras.memory, x1_vec4i32);
        case DataFormat::R32G32B32A32_UINT:
            return minmax_of<glm::u32vec4>(ras.memory, x1_vec4u32);

        default:
            return {};
        }
    }
    

}

//YQ_RESOURCE_IMPLEMENT(yq::tachyon::HeightField)
