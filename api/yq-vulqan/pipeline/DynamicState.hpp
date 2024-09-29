////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Enum.hpp>
#include <yq-toolbox/meta/InfoBinder.hpp>

namespace yq::tachyon {

    /*! \brief Dynamic State
    
    */

    YQ_ENUM(DynamicState, , 
        Viewport = 0,
        Scissor = 1,
        LineWidth = 2,
        DepthBias = 3,
        BlendConstants = 4,
        DepthBounds = 5,
        StencilCompareMask = 6,
        StencilWriteMask = 7,
        StencilReference = 8,
        CullMode = 1000267000,
        FrontFace = 1000267001,
        PrimitiveTopology = 1000267002,
        ViewportWithCount = 1000267003,
        ScissorWithCount = 1000267004,
        VertexInputBindingStride = 1000267005,
        DepthTestEnable = 1000267006,
        DepthWriteEnable = 1000267007,
        DepthCompareOp = 1000267008,
        DepthBoundsTestEnable = 1000267009,
        StencilTestEnable = 1000267010,
        StencilOp = 1000267011,
        RasterizerDiscardEnable = 1000377001,
        DepthBiasEnable = 1000377002,
        PrimitiveRestartEnable = 1000377004,
        ViewportWScaling = 1000087000,
        DiscardRectangle = 1000099000,
        DiscardRectangleEnable = 1000099001,
        DiscardRectangleMode = 1000099002,
        SampleLocations = 1000143000,
        RayTracingPipelineStackSize = 1000347000,
        ViewportShadingRatePalette = 1000164004,
        ViewportCoarseSampleOrder = 1000164006,
        ExclusiveScissorEnable = 1000205000,
        ExclusiveScissor = 1000205001,
        FragmentShadingRate = 1000226000,
        VertexInput = 1000352000,
        PatchControlPoints = 1000377000,
        LogicOp = 1000377003,
        ColorWriteEnable = 1000381000,
        DepthClampEnable = 1000455003,
        PolygonMode = 1000455004,
        RasterizationSamples = 1000455005,
        SampleMask = 1000455006,
        AlphaToCoverageEnable = 1000455007,
        AlphaToOneEnable = 1000455008,
        LogicOpEnable = 1000455009,
        ColorBlendEnable = 1000455010,
        ColorBlendEquation = 1000455011,
        ColorWriteMask = 1000455012,
        TessellationDomainOrigin = 1000455002,
        RasterizationStream = 1000455013,
        ConservativeRasterizationMode = 1000455014,
        ExtraPrimitiveOverestimationSize = 1000455015,
        DepthClipEnable = 1000455016,
        SampleLocationsEnable = 1000455017,
        ColorBlendAdvanced = 1000455018,
        ProvokingVertexMode = 1000455019,
        LineRasterizationMode = 1000455020,
        LineStippleEnable = 1000455021,
        DepthClipNegativeOneToOne = 1000455022,
        ViewportWScalingEnable = 1000455023,
        ViewportSwizzle = 1000455024,
        CoverageToColorEnable = 1000455025,
        CoverageToColorLocation = 1000455026,
        CoverageModulationMode = 1000455027,
        CoverageModulationTableEnable = 1000455028,
        CoverageModulationTable = 1000455029,
        ShadingRateImageEnable = 1000455030,
        RepresentativeFragmentTestEnable = 1000455031,
        CoverageReductionMode = 1000455032,
        AttachmentFeedbackLoopEnable = 1000524000,
        LineStipple = 1000259000
    )
}

YQ_TYPE_DECLARE(yq::tachyon::DynamicState)
