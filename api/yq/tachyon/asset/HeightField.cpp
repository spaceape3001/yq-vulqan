////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////


#include <yq/tachyon/asset/GriddedData.hpp>
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
        return load(pp, Sampler::simple(), HeightFieldInfo());
    }
    
    HeightFieldCPtr  HeightField::load(std::string_view pp, const SamplerCPtr& _sampler, const HeightFieldInfo& _info)
    {
        if(!_sampler)
            return {};
        GriddedDataCPtr   img = GriddedData::IO::load(pp);
        if(!img)
            return {};
        return new HeightField(img, _sampler, _info);
    }

    HeightFieldCPtr  HeightField::load(std::string_view pp, const HeightFieldInfo2& texInfo)
    {
        return load(pp, new Sampler(texInfo), texInfo);
    }
    
    HeightFieldCPtr  HeightField::load(std::string_view pp, const HeightFieldInfo& texInfo)
    {
        return load(pp, Sampler::simple(), texInfo);
    }

    // ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    HeightFieldCPtr  HeightField::load(std::initializer_list<std::string_view> pps)
    {
        return load(pps, Sampler::simple(), HeightFieldInfo());
    }
    
    HeightFieldCPtr  HeightField::load(std::initializer_list<std::string_view> pps, const HeightFieldInfo& texInfo)
    {
        return load(pps, Sampler::simple(), texInfo);
    }
    
    HeightFieldCPtr  HeightField::load(std::initializer_list<std::string_view> pps, const HeightFieldInfo2& texInfo)
    {
        return load(pps, new Sampler(texInfo), texInfo);
    }
    
    HeightFieldCPtr  HeightField::load(std::initializer_list<std::string_view> pps, const SamplerCPtr& _sampler, const HeightFieldInfo& texInfo)
    {
        if(!_sampler)
            return {};
        std::vector<GriddedDataCPtr> imgs;
        for(std::string_view pp : pps){
            GriddedDataCPtr  img = GriddedData::IO::load(pp);
            if(!img)
                return {};
            imgs.push_back(img);
        }

        return new HeightField(std::move(imgs), _sampler, texInfo);
    }

    // ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    HeightFieldCPtr  HeightField::load(std::span<const std::string_view> pps)
    {
        return load(pps, Sampler::simple(), HeightFieldInfo());
    }
    
    HeightFieldCPtr  HeightField::load(std::span<const std::string_view> pps, const HeightFieldInfo& texInfo)
    {
        return load(pps, Sampler::simple(), texInfo);
    }
    
    HeightFieldCPtr  HeightField::load(std::span<const std::string_view> pps, const HeightFieldInfo2& texInfo)
    {
        return load(pps, new Sampler(texInfo), texInfo);
    }
    
    HeightFieldCPtr  HeightField::load(std::span<const std::string_view> pps, const SamplerCPtr& _sampler, const HeightFieldInfo& texInfo)
    {
        if(!_sampler)
            return {};
        std::vector<GriddedDataCPtr> imgs;
        for(std::string_view pp : pps){
            GriddedDataCPtr  img = GriddedData::IO::load(pp);
            if(!img)
                return {};
            imgs.push_back(img);
        }

        return new HeightField(std::move(imgs), _sampler, texInfo);
    }
    
    // ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    HeightField::HeightField(GriddedDataCPtr img) : HeightField(img, Sampler::simple())
    {
    }
    
    HeightField::HeightField(GriddedDataCPtr img, const HeightFieldInfo& texInfo) : HeightField(img, Sampler::simple(), texInfo)
    {
    }

    HeightField::HeightField(GriddedDataCPtr img, const HeightFieldInfo2& texInfo) : HeightField(img, new Sampler(texInfo), texInfo)
    {
    }

    HeightField::HeightField(GriddedDataCPtr img, const SamplerCPtr& _sampler, const HeightFieldInfo& _info) : 
        griddeds({img}), sampler(_sampler), info(_info)
    {
    }

    HeightField::HeightField(std::vector<GriddedDataCPtr>&& imgs) : HeightField(std::move(imgs), Sampler::simple())
    {
    }
    
    HeightField::HeightField(std::vector<GriddedDataCPtr>&& imgs, const HeightFieldInfo& texInfo) : 
        HeightField(std::move(imgs), Sampler::simple(), texInfo)
    {
    }
    
    HeightField::HeightField(std::vector<GriddedDataCPtr>&& imgs, const HeightFieldInfo2& texInfo) : 
        HeightField(std::move(imgs), new Sampler(texInfo), texInfo)
    {
    }

    HeightField::HeightField(std::vector<GriddedDataCPtr>&& imgs, const SamplerCPtr& _sampler, const HeightFieldInfo& texInfo) : 
        griddeds(std::move(imgs)), sampler(_sampler), info(texInfo)
    {
    }
    
    HeightField::~HeightField()
    {
    }
}

YQ_RESOURCE_IMPLEMENT(yq::tachyon::HeightField)
