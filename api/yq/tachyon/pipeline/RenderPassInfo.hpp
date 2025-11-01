////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Flags.hpp>
#include <tachyon/pipeline/DataFormat.hpp>
#include <tachyon/pipeline/ImageLayout.hpp>
#include <tachyon/pipeline/LoadOp.hpp>
#include <tachyon/pipeline/PipelineBinding.hpp>
#include <tachyon/pipeline/SampleCount.hpp>
#include <tachyon/pipeline/StoreOp.hpp>

namespace yq::tachyon {
    struct AttachmentReference {
        uint32_t        attachment      = 0;
        ImageLayout     layout          = ImageLayout::ColorAttachment;
    };

    struct AttachmentDescription {
        enum class F : uint8_t {
            MayAlias = 0
        };
        using Flags     = ::yq::Flags<F,uint32_t>;
        
        Flags               flags           = {};
        DataFormat          format;
        SampleCountFlags    samples         = SampleCount::One;
        LoadOp              loadOp          = LoadOp::Load;
        StoreOp             storeOp         = StoreOp::Store;
        LoadOp              stencilLoadOp   = LoadOp::DontCare;
        StoreOp             stencilStoreOp  = StoreOp::DontCare;
        ImageLayout         initialLayout   = ImageLayout::Undefined;
        ImageLayout         finalLayout     = ImageLayout::PresentSrc;
    };
    
    struct SubpassEndpoint {
        uint32_t        subpass = 0;
        
    };
    
    struct SubpassDependency {
        enum class F : uint8_t {
            ByRegion        = 0,
            ViewLocal       = 1,
            DeviceGroup     = 2,
            FeedbackLoop    = 3
        };

        using Flags = ::yq::Flags<F>;
        
        Flags               flags = {};
        SubpassEndpoint     src, dst;
    };
    
    struct SubpassInfo {
        enum class F : uint8_t {
            PerViewAttributes           = 0,
            PerViewPositionXOnly        = 1,
            FragmentRegion              = 2,
            ShaderResolve               = 3,
            RasterizationOrderColor     = 4,
            RasterizationOrderDepth     = 5,
            RasterizationOrderStencil   = 6,
            LegacyDithering             = 7
        };
    
        using Flags = ::yq::Flags<F>;
        
        Flags                               flags = {};
        PipelineBinding                     bindPoint = PipelineBinding::Graphics;
        std::vector<AttachmentReference>    colorAttachments;
        std::vector<AttachmentReference>    inputAttachments;
        std::vector<AttachmentReference>    preserveAttachments;
        
        //  totally ignoring resolve & depth-stencil attachements (for now)
    };

    struct RenderPassInfo {
    
        enum class F : uint8_t {
            Transform   = 1
        };

        using Flags = ::yq::Flags<F>;
        
        Flags                               flags = {};
    
        std::vector<AttachmentDescription>  attachments;
        std::vector<SubpassInfo>            subpasses;
        std::vector<SubpassDependency>      dependencies;
    };
}
