////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/core/UniqueID.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/tachyon/asset/SamplerInfo.hpp>
#include <yq/tachyon/pipeline/DataFormat.hpp>
#include <yq/tachyon/pipeline/ComponentSwizzle.hpp>
#include <yq/tachyon/pipeline/ImageAspect.hpp>
#include <yq/tachyon/pipeline/ImageViewCreateFlags.hpp>
#include <yq/tachyon/pipeline/ImageViewType.hpp>
#include <yq/tachyon/typedef/gridded_data.hpp>
#include <yq/tachyon/typedef/sampler.hpp>
#include <yq/tachyon/typedef/height_field.hpp>
#include <optional>

namespace yq::tachyon {

    struct HeightFieldInfo {
        //! Image view type
        std::optional<ImageViewType>    imageViewType;
        
        //! Image view flags
        ImageViewCreateFlags            imageViewFlags           = {};
        
        //! Image view format
        std::optional<DataFormat>       format;
        
        //! Image view swizzle
        RGBA<ComponentSwizzle>          swizzle         = { ComponentSwizzle::Identity, ComponentSwizzle::Identity, ComponentSwizzle::Identity, ComponentSwizzle::Identity };
        
        //! Image view aspect
        ImageAspectFlags                aspect          = ImageAspectFlags(ImageAspect::Color);
        
        //! Image view base mip level
        uint32_t                        baseMipLevel    = 0;
        
        //! Image view level count
        uint32_t                        levelCount      = 1;
        
        //! Image view base array layer
        uint32_t                        baseArrayLayer  = 0;
        
        //! Image view layer count
        uint32_t                        layerCount      = 1;
    };

    struct HeightFieldInfo2 : public HeightFieldInfo, public SamplerInfo {
    };


    //! HeightField (image & view/sampler info)
    class HeightField : public Resource {
        YQ_RESOURCE_DECLARE(HeightField, Resource)
    public:
    
        /*! Gridded Data(s)
        
            When there are multiple images, it'll imply multiple layers.  
            
            \note While sizes SHOULD MATCH, non-matching Images 
            will be RESIZED/RESCALED to the largest size. 
        */
        const std::vector<GriddedDataCPtr>   griddeds;

        // Should match dimensions in gridded.sizes...  If empty, default is [0,1] on each dimension
        std::vector<double>                 lower_limits;
        std::vector<double>                 upper_limits;

        //! Sampler info
        const SamplerCPtr                   sampler;
        
        //! View information
        const HeightFieldInfo               info;

        static HeightFieldCPtr  load(std::string_view);
        static HeightFieldCPtr  load(std::string_view, const HeightFieldInfo& texInfo);
        static HeightFieldCPtr  load(std::string_view, const HeightFieldInfo2& texInfo);
        static HeightFieldCPtr  load(std::string_view, const SamplerCPtr& _sampler, const HeightFieldInfo& texInfo = {});

        static HeightFieldCPtr  load(std::initializer_list<std::string_view>);
        static HeightFieldCPtr  load(std::initializer_list<std::string_view>, const HeightFieldInfo& texInfo);
        static HeightFieldCPtr  load(std::initializer_list<std::string_view>, const HeightFieldInfo2& texInfo);
        static HeightFieldCPtr  load(std::initializer_list<std::string_view>, const SamplerCPtr& _sampler, const HeightFieldInfo& texInfo = {});

        static HeightFieldCPtr  load(std::span<const std::string_view>);
        static HeightFieldCPtr  load(std::span<const std::string_view>, const HeightFieldInfo& texInfo);
        static HeightFieldCPtr  load(std::span<const std::string_view>, const HeightFieldInfo2& texInfo);
        static HeightFieldCPtr  load(std::span<const std::string_view>, const SamplerCPtr& _sampler, const HeightFieldInfo& texInfo = {});

        HeightField(GriddedDataCPtr);
        HeightField(GriddedDataCPtr, const SamplerCPtr& _sampler, const HeightFieldInfo& texInfo={});
        HeightField(GriddedDataCPtr, const HeightFieldInfo& texInfo);
        HeightField(GriddedDataCPtr, const HeightFieldInfo2& texInfo);
        
        HeightField(std::vector<GriddedDataCPtr>&&);
        HeightField(std::vector<GriddedDataCPtr>&&, const SamplerCPtr& _sampler, const HeightFieldInfo& texInfo={});
        HeightField(std::vector<GriddedDataCPtr>&&, const HeightFieldInfo& texInfo);
        HeightField(std::vector<GriddedDataCPtr>&&, const HeightFieldInfo2& texInfo);
        
        static void init_meta();
        virtual size_t      data_size() const override { return 0; }
        
    private:
        ~HeightField();
    };
}

