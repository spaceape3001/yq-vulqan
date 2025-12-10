////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////


#include <yq/tachyon/asset/Raster.hpp>
#include <yq/tachyon/asset/Sampler.hpp>
#include <yq/tachyon/asset/HeightField.hpp>
#include <yq/resource/ResourceMetaWriter.hpp>

namespace yq::tachyon {
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
}

YQ_RESOURCE_IMPLEMENT(yq::tachyon::HeightField)
