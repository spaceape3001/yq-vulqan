////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string_view>
#include <yq/core/Flags.hpp>

namespace yq::tachyon {
    enum class VqAccelerationStructureBuildType : uint32_t {
        HostKHR = 0,
        DeviceKHR = 1,
        HostOrDeviceKHR = 2
    };
    
    std::string_view    to_string_view(VqAccelerationStructureBuildType);

    enum class VqAccelerationStructureCompatibility : uint32_t {
        CompatibleKHR = 0,
        IncompatibleKHR = 1
    };
    
    std::string_view    to_string_view(VqAccelerationStructureCompatibility);

    enum class VqAccelerationStructureCreateFlagBits : uint32_t {
        DeviceAddressCaptureReplayBitKHR = 0x00000001,
        DescriptorBufferCaptureReplayBitEXT = 0x00000008,
        MotionBitNV = 0x00000004
    };
    
    std::string_view    to_string_view(VqAccelerationStructureCreateFlagBits);

    enum class VqAccelerationStructureMemoryRequirementsType : uint32_t {
        ObjectNV = 0,
        BuildScratchNV = 1,
        UpdateScratchNV = 2
    };
    
    std::string_view    to_string_view(VqAccelerationStructureMemoryRequirementsType);

    enum class VqAccelerationStructureMotionInstanceType : uint32_t {
        StaticNV = 0,
        MatrixMotionNV = 1,
        SrtMotionNV = 2
    };
    
    std::string_view    to_string_view(VqAccelerationStructureMotionInstanceType);

    enum class VqAccelerationStructureType : uint32_t {
        TopLevelKHR = 0,
        BottomLevelKHR = 1,
        GenericKHR = 2,
        TopLevelNV = TopLevelKHR,
        BottomLevelNV = BottomLevelKHR
    };
    
    std::string_view    to_string_view(VqAccelerationStructureType);

    enum class VqAccessFlagBits : uint32_t {
        IndirectCommandReadBit = 0x00000001,
        IndexReadBit = 0x00000002,
        VertexAttributeReadBit = 0x00000004,
        UniformReadBit = 0x00000008,
        InputAttachmentReadBit = 0x00000010,
        ShaderReadBit = 0x00000020,
        ShaderWriteBit = 0x00000040,
        ColorAttachmentReadBit = 0x00000080,
        ColorAttachmentWriteBit = 0x00000100,
        DepthStencilAttachmentReadBit = 0x00000200,
        DepthStencilAttachmentWriteBit = 0x00000400,
        TransferReadBit = 0x00000800,
        TransferWriteBit = 0x00001000,
        HostReadBit = 0x00002000,
        HostWriteBit = 0x00004000,
        MemoryReadBit = 0x00008000,
        MemoryWriteBit = 0x00010000,
        None = 0,
        TransformFeedbackWriteBitEXT = 0x02000000,
        TransformFeedbackCounterReadBitEXT = 0x04000000,
        TransformFeedbackCounterWriteBitEXT = 0x08000000,
        ConditionalRenderingReadBitEXT = 0x00100000,
        ColorAttachmentReadNoncoherentBitEXT = 0x00080000,
        AccelerationStructureReadBitKHR = 0x00200000,
        AccelerationStructureWriteBitKHR = 0x00400000,
        FragmentDensityMapReadBitEXT = 0x01000000,
        FragmentShadingRateAttachmentReadBitKHR = 0x00800000,
        CommandPreprocessReadBitNV = 0x00020000,
        CommandPreprocessWriteBitNV = 0x00040000,
        ShadingRateImageReadBitNV = FragmentShadingRateAttachmentReadBitKHR,
        AccelerationStructureReadBitNV = AccelerationStructureReadBitKHR,
        AccelerationStructureWriteBitNV = AccelerationStructureWriteBitKHR,
        NoneKHR = None
    };
    
    std::string_view    to_string_view(VqAccessFlagBits);

    enum class VqAcquireProfilingLockFlagBits : uint32_t {

    };
    
    std::string_view    to_string_view(VqAcquireProfilingLockFlagBits);

    enum class VqAttachmentDescriptionFlagBits : uint32_t {
        MayAliasBit = 0x00000001
    };
    
    std::string_view    to_string_view(VqAttachmentDescriptionFlagBits);

    enum class VqAttachmentLoadOp : uint32_t {
        Load = 0,
        Clear = 1,
        DontCare = 2,
        NoneKHR = 1000400000,
        NoneEXT = NoneKHR
    };
    
    std::string_view    to_string_view(VqAttachmentLoadOp);

    enum class VqAttachmentStoreOp : uint32_t {
        Store = 0,
        DontCare = 1,
        None = 1000301000,
        NoneKHR = None,
        NoneQCOM = None,
        NoneEXT = None
    };
    
    std::string_view    to_string_view(VqAttachmentStoreOp);

    enum class VqBlendFactor : uint32_t {
        Zero = 0,
        One = 1,
        SrcColor = 2,
        OneMinusSrcColor = 3,
        DstColor = 4,
        OneMinusDstColor = 5,
        SrcAlpha = 6,
        OneMinusSrcAlpha = 7,
        DstAlpha = 8,
        OneMinusDstAlpha = 9,
        ConstantColor = 10,
        OneMinusConstantColor = 11,
        ConstantAlpha = 12,
        OneMinusConstantAlpha = 13,
        SrcAlphaSaturate = 14,
        Src1Color = 15,
        OneMinusSrc1Color = 16,
        Src1Alpha = 17,
        OneMinusSrc1Alpha = 18
    };
    
    std::string_view    to_string_view(VqBlendFactor);

    enum class VqBlendOp : uint32_t {
        Add = 0,
        Subtract = 1,
        ReverseSubtract = 2,
        Min = 3,
        Max = 4,
        ZeroEXT = 1000148000,
        SrcEXT = 1000148001,
        DstEXT = 1000148002,
        SrcOverEXT = 1000148003,
        DstOverEXT = 1000148004,
        SrcInEXT = 1000148005,
        DstInEXT = 1000148006,
        SrcOutEXT = 1000148007,
        DstOutEXT = 1000148008,
        SrcAtopEXT = 1000148009,
        DstAtopEXT = 1000148010,
        XorEXT = 1000148011,
        MultiplyEXT = 1000148012,
        ScreenEXT = 1000148013,
        OverlayEXT = 1000148014,
        DarkenEXT = 1000148015,
        LightenEXT = 1000148016,
        ColordodgeEXT = 1000148017,
        ColorburnEXT = 1000148018,
        HardlightEXT = 1000148019,
        SoftlightEXT = 1000148020,
        DifferenceEXT = 1000148021,
        ExclusionEXT = 1000148022,
        InvertEXT = 1000148023,
        InvertRgbEXT = 1000148024,
        LineardodgeEXT = 1000148025,
        LinearburnEXT = 1000148026,
        VividlightEXT = 1000148027,
        LinearlightEXT = 1000148028,
        PinlightEXT = 1000148029,
        HardmixEXT = 1000148030,
        HslHueEXT = 1000148031,
        HslSaturationEXT = 1000148032,
        HslColorEXT = 1000148033,
        HslLuminosityEXT = 1000148034,
        PlusEXT = 1000148035,
        PlusClampedEXT = 1000148036,
        PlusClampedAlphaEXT = 1000148037,
        PlusDarkerEXT = 1000148038,
        MinusEXT = 1000148039,
        MinusClampedEXT = 1000148040,
        ContrastEXT = 1000148041,
        InvertOvgEXT = 1000148042,
        RedEXT = 1000148043,
        GreenEXT = 1000148044,
        BlueEXT = 1000148045
    };
    
    std::string_view    to_string_view(VqBlendOp);

    enum class VqBlendOverlap : uint32_t {
        UncorrelatedEXT = 0,
        DisjointEXT = 1,
        ConjointEXT = 2
    };
    
    std::string_view    to_string_view(VqBlendOverlap);

    enum class VqBlockMatchWindowCompareMode : uint32_t {
        MinQCOM = 0,
        MaxQCOM = 1
    };
    
    std::string_view    to_string_view(VqBlockMatchWindowCompareMode);

    enum class VqBorderColor : uint32_t {
        FloatTransparentBlack = 0,
        IntTransparentBlack = 1,
        FloatOpaqueBlack = 2,
        IntOpaqueBlack = 3,
        FloatOpaqueWhite = 4,
        IntOpaqueWhite = 5,
        FloatCustomEXT = 1000287003,
        IntCustomEXT = 1000287004
    };
    
    std::string_view    to_string_view(VqBorderColor);

    enum class VqBufferCreateFlagBits : uint32_t {
        SparseBindingBit = 0x00000001,
        SparseResidencyBit = 0x00000002,
        SparseAliasedBit = 0x00000004,
        ProtectedBit = 0x00000008,
        DeviceAddressCaptureReplayBit = 0x00000010,
        DescriptorBufferCaptureReplayBitEXT = 0x00000020,
        VideoProfileIndependentBitKHR = 0x00000040,
        DeviceAddressCaptureReplayBitEXT = DeviceAddressCaptureReplayBit,
        DeviceAddressCaptureReplayBitKHR = DeviceAddressCaptureReplayBit
    };
    
    std::string_view    to_string_view(VqBufferCreateFlagBits);

    enum class VqBufferUsageFlagBits : uint32_t {
        TransferSrcBit = 0x00000001,
        TransferDstBit = 0x00000002,
        UniformTexelBufferBit = 0x00000004,
        StorageTexelBufferBit = 0x00000008,
        UniformBufferBit = 0x00000010,
        StorageBufferBit = 0x00000020,
        IndexBufferBit = 0x00000040,
        VertexBufferBit = 0x00000080,
        IndirectBufferBit = 0x00000100,
        ShaderDeviceAddressBit = 0x00020000,
        VideoDecodeSrcBitKHR = 0x00002000,
        VideoDecodeDstBitKHR = 0x00004000,
        TransformFeedbackBufferBitEXT = 0x00000800,
        TransformFeedbackCounterBufferBitEXT = 0x00001000,
        ConditionalRenderingBitEXT = 0x00000200,
        ExecutionGraphScratchBitAmdx = 0x02000000,
        AccelerationStructureBuildInputReadOnlyBitKHR = 0x00080000,
        AccelerationStructureStorageBitKHR = 0x00100000,
        ShaderBindingTableBitKHR = 0x00000400,
        VideoEncodeDstBitKHR = 0x00008000,
        VideoEncodeSrcBitKHR = 0x00010000,
        SamplerDescriptorBufferBitEXT = 0x00200000,
        ResourceDescriptorBufferBitEXT = 0x00400000,
        PushDescriptorsDescriptorBufferBitEXT = 0x04000000,
        MicromapBuildInputReadOnlyBitEXT = 0x00800000,
        MicromapStorageBitEXT = 0x01000000,
        RayTracingBitNV = ShaderBindingTableBitKHR,
        ShaderDeviceAddressBitEXT = ShaderDeviceAddressBit,
        ShaderDeviceAddressBitKHR = ShaderDeviceAddressBit
    };
    
    std::string_view    to_string_view(VqBufferUsageFlagBits);

    enum class VqBuildAccelerationStructureFlagBits : uint32_t {
        AllowUpdateBitKHR = 0x00000001,
        AllowCompactionBitKHR = 0x00000002,
        PreferFastTraceBitKHR = 0x00000004,
        PreferFastBuildBitKHR = 0x00000008,
        LowMemoryBitKHR = 0x00000010,
        MotionBitNV = 0x00000020,
        AllowOpacityMicromapUpdateEXT = 0x00000040,
        AllowDisableOpacityMicromapsEXT = 0x00000080,
        AllowOpacityMicromapDataUpdateEXT = 0x00000100,
        AllowDisplacementMicromapUpdateNV = 0x00000200,
        AllowDataAccessKHR = 0x00000800,
        AllowUpdateBitNV = AllowUpdateBitKHR,
        AllowCompactionBitNV = AllowCompactionBitKHR,
        PreferFastTraceBitNV = PreferFastTraceBitKHR,
        PreferFastBuildBitNV = PreferFastBuildBitKHR,
        LowMemoryBitNV = LowMemoryBitKHR
    };
    
    std::string_view    to_string_view(VqBuildAccelerationStructureFlagBits);

    enum class VqBuildAccelerationStructureMode : uint32_t {
        BuildKHR = 0,
        UpdateKHR = 1
    };
    
    std::string_view    to_string_view(VqBuildAccelerationStructureMode);

    enum class VqBuildMicromapFlagBits : uint32_t {
        PreferFastTraceBitEXT = 0x00000001,
        PreferFastBuildBitEXT = 0x00000002,
        AllowCompactionBitEXT = 0x00000004
    };
    
    std::string_view    to_string_view(VqBuildMicromapFlagBits);

    enum class VqBuildMicromapMode : uint32_t {
        BuildEXT = 0
    };
    
    std::string_view    to_string_view(VqBuildMicromapMode);

    enum class VqChromaLocation : uint32_t {
        CositedEven = 0,
        Midpoint = 1,
        CositedEvenKHR = CositedEven,
        MidpointKHR = Midpoint
    };
    
    std::string_view    to_string_view(VqChromaLocation);

    enum class VqCoarseSampleOrderType : uint32_t {
        DefaultNV = 0,
        CustomNV = 1,
        PixelMajorNV = 2,
        SampleMajorNV = 3
    };
    
    std::string_view    to_string_view(VqCoarseSampleOrderType);

    enum class VqColorComponentFlagBits : uint32_t {
        RBit = 0x00000001,
        GBit = 0x00000002,
        BBit = 0x00000004,
        ABit = 0x00000008
    };
    
    std::string_view    to_string_view(VqColorComponentFlagBits);

    enum class VqColorSpace : uint32_t {
        SrgbNonlinearKHR = 0,
        DisplayP3NonlinearEXT = 1000104001,
        ExtendedSrgbLinearEXT = 1000104002,
        DisplayP3LinearEXT = 1000104003,
        DciP3NonlinearEXT = 1000104004,
        Bt709LinearEXT = 1000104005,
        Bt709NonlinearEXT = 1000104006,
        Bt2020LinearEXT = 1000104007,
        Hdr10St2084EXT = 1000104008,
        DolbyvisionEXT = 1000104009,
        Hdr10HlgEXT = 1000104010,
        AdobergbLinearEXT = 1000104011,
        AdobergbNonlinearEXT = 1000104012,
        PassThroughEXT = 1000104013,
        ExtendedSrgbNonlinearEXT = 1000104014,
        DisplayNativeAMD = 1000213000,
        VkColorspaceSrgbNonlinearKHR = SrgbNonlinearKHR,
        DciP3LinearEXT = DisplayP3LinearEXT
    };
    
    std::string_view    to_string_view(VqColorSpace);

    enum class VqCommandBufferLevel : uint32_t {
        Primary = 0,
        Secondary = 1
    };
    
    std::string_view    to_string_view(VqCommandBufferLevel);

    enum class VqCommandBufferResetFlagBits : uint32_t {
        ReleaseResourcesBit = 0x00000001
    };
    
    std::string_view    to_string_view(VqCommandBufferResetFlagBits);

    enum class VqCommandBufferUsageFlagBits : uint32_t {
        OneTimeSubmitBit = 0x00000001,
        RenderPassContinueBit = 0x00000002,
        SimultaneousUseBit = 0x00000004
    };
    
    std::string_view    to_string_view(VqCommandBufferUsageFlagBits);

    enum class VqCommandPoolCreateFlagBits : uint32_t {
        TransientBit = 0x00000001,
        ResetCommandBufferBit = 0x00000002,
        ProtectedBit = 0x00000004
    };
    
    std::string_view    to_string_view(VqCommandPoolCreateFlagBits);

    enum class VqCommandPoolResetFlagBits : uint32_t {
        ReleaseResourcesBit = 0x00000001
    };
    
    std::string_view    to_string_view(VqCommandPoolResetFlagBits);

    enum class VqCompareOp : uint32_t {
        Never = 0,
        Less = 1,
        Equal = 2,
        LessOrEqual = 3,
        Greater = 4,
        NotEqual = 5,
        GreaterOrEqual = 6,
        Always = 7
    };
    
    std::string_view    to_string_view(VqCompareOp);

    enum class VqComponentSwizzle : uint32_t {
        Identity = 0,
        Zero = 1,
        One = 2,
        R = 3,
        G = 4,
        B = 5,
        A = 6
    };
    
    std::string_view    to_string_view(VqComponentSwizzle);

    enum class VqComponentType : uint32_t {
        Float16KHR = 0,
        Float32KHR = 1,
        Float64KHR = 2,
        Sint8KHR = 3,
        Sint16KHR = 4,
        Sint32KHR = 5,
        Sint64KHR = 6,
        Uint8KHR = 7,
        Uint16KHR = 8,
        Uint32KHR = 9,
        Uint64KHR = 10,
        Float16NV = Float16KHR,
        Float32NV = Float32KHR,
        Float64NV = Float64KHR,
        Sint8NV = Sint8KHR,
        Sint16NV = Sint16KHR,
        Sint32NV = Sint32KHR,
        Sint64NV = Sint64KHR,
        Uint8NV = Uint8KHR,
        Uint16NV = Uint16KHR,
        Uint32NV = Uint32KHR,
        Uint64NV = Uint64KHR
    };
    
    std::string_view    to_string_view(VqComponentType);

    enum class VqCompositeAlphaFlagBits : uint32_t {
        OpaqueBitKHR = 0x00000001,
        PreMultipliedBitKHR = 0x00000002,
        PostMultipliedBitKHR = 0x00000004,
        InheritBitKHR = 0x00000008
    };
    
    std::string_view    to_string_view(VqCompositeAlphaFlagBits);

    enum class VqConditionalRenderingFlagBits : uint32_t {
        InvertedBitEXT = 0x00000001
    };
    
    std::string_view    to_string_view(VqConditionalRenderingFlagBits);

    enum class VqConservativeRasterizationMode : uint32_t {
        DisabledEXT = 0,
        OverestimateEXT = 1,
        UnderestimateEXT = 2
    };
    
    std::string_view    to_string_view(VqConservativeRasterizationMode);

    enum class VqCopyAccelerationStructureMode : uint32_t {
        CloneKHR = 0,
        CompactKHR = 1,
        SerializeKHR = 2,
        DeserializeKHR = 3,
        CloneNV = CloneKHR,
        CompactNV = CompactKHR
    };
    
    std::string_view    to_string_view(VqCopyAccelerationStructureMode);

    enum class VqCopyMicromapMode : uint32_t {
        CloneEXT = 0,
        SerializeEXT = 1,
        DeserializeEXT = 2,
        CompactEXT = 3
    };
    
    std::string_view    to_string_view(VqCopyMicromapMode);

    enum class VqCoverageModulationMode : uint32_t {
        NoneNV = 0,
        RgbNV = 1,
        AlphaNV = 2,
        RgbaNV = 3
    };
    
    std::string_view    to_string_view(VqCoverageModulationMode);

    enum class VqCoverageReductionMode : uint32_t {
        MergeNV = 0,
        TruncateNV = 1
    };
    
    std::string_view    to_string_view(VqCoverageReductionMode);

    enum class VqCubicFilterWeights : uint32_t {
        CatmullRomQCOM = 0,
        ZeroTangentCardinalQCOM = 1,
        BSplineQCOM = 2,
        MitchellNetravaliQCOM = 3
    };
    
    std::string_view    to_string_view(VqCubicFilterWeights);

    enum class VqCullModeFlagBits : uint32_t {
        None = 0,
        FrontBit = 0x00000001,
        BackBit = 0x00000002,
        FrontAndBack = 0x00000003
    };
    
    std::string_view    to_string_view(VqCullModeFlagBits);

    enum class VqDebugReportFlagBits : uint32_t {
        InformationBitEXT = 0x00000001,
        WarningBitEXT = 0x00000002,
        PerformanceWarningBitEXT = 0x00000004,
        ErrorBitEXT = 0x00000008,
        DebugBitEXT = 0x00000010
    };
    
    std::string_view    to_string_view(VqDebugReportFlagBits);

    enum class VqDebugReportObjectType : uint32_t {
        UnknownEXT = 0,
        InstanceEXT = 1,
        PhysicalDeviceEXT = 2,
        DeviceEXT = 3,
        QueueEXT = 4,
        SemaphoreEXT = 5,
        CommandBufferEXT = 6,
        FenceEXT = 7,
        DeviceMemoryEXT = 8,
        BufferEXT = 9,
        ImageEXT = 10,
        EventEXT = 11,
        QueryPoolEXT = 12,
        BufferViewEXT = 13,
        ImageViewEXT = 14,
        ShaderModuleEXT = 15,
        PipelineCacheEXT = 16,
        PipelineLayoutEXT = 17,
        RenderPassEXT = 18,
        PipelineEXT = 19,
        DescriptorSetLayoutEXT = 20,
        SamplerEXT = 21,
        DescriptorPoolEXT = 22,
        DescriptorSetEXT = 23,
        FramebufferEXT = 24,
        CommandPoolEXT = 25,
        SurfaceKHREXT = 26,
        SwapchainKHREXT = 27,
        DebugReportCallbackEXTEXT = 28,
        DisplayKHREXT = 29,
        DisplayModeKHREXT = 30,
        ValidationCacheEXTEXT = 33,
        SamplerYcbcrConversionEXT = 1000156000,
        DescriptorUpdateTemplateEXT = 1000085000,
        CuModuleNvxEXT = 1000029000,
        CuFunctionNvxEXT = 1000029001,
        AccelerationStructureKHREXT = 1000150000,
        AccelerationStructureNVEXT = 1000165000,
        CudaModuleNVEXT = 1000307000,
        CudaFunctionNVEXT = 1000307001,
        BufferCollectionFuchsiaEXT = 1000366000,
        DebugReportEXT = DebugReportCallbackEXTEXT,
        ValidationCacheEXT = ValidationCacheEXTEXT,
        DescriptorUpdateTemplateKHREXT = DescriptorUpdateTemplateEXT,
        SamplerYcbcrConversionKHREXT = SamplerYcbcrConversionEXT
    };
    
    std::string_view    to_string_view(VqDebugReportObjectType);

    enum class VqDebugUtilsMessageSeverityFlagBits : uint32_t {
        VerboseBitEXT = 0x00000001,
        InfoBitEXT = 0x00000010,
        WarningBitEXT = 0x00000100,
        ErrorBitEXT = 0x00001000
    };
    
    std::string_view    to_string_view(VqDebugUtilsMessageSeverityFlagBits);

    enum class VqDebugUtilsMessageTypeFlagBits : uint32_t {
        GeneralBitEXT = 0x00000001,
        ValidationBitEXT = 0x00000002,
        PerformanceBitEXT = 0x00000004,
        DeviceAddressBindingBitEXT = 0x00000008
    };
    
    std::string_view    to_string_view(VqDebugUtilsMessageTypeFlagBits);

    enum class VqDependencyFlagBits : uint32_t {
        ByRegionBit = 0x00000001,
        DeviceGroupBit = 0x00000004,
        ViewLocalBit = 0x00000002,
        FeedbackLoopBitEXT = 0x00000008,
        ViewLocalBitKHR = ViewLocalBit,
        DeviceGroupBitKHR = DeviceGroupBit
    };
    
    std::string_view    to_string_view(VqDependencyFlagBits);

    enum class VqDepthBiasRepresentation : uint32_t {
        LeastRepresentableValueFormatEXT = 0,
        LeastRepresentableValueForceUnormEXT = 1,
        FloatEXT = 2
    };
    
    std::string_view    to_string_view(VqDepthBiasRepresentation);

    enum class VqDescriptorBindingFlagBits : uint32_t {
        UpdateAfterBindBit = 0x00000001,
        UpdateUnusedWhilePendingBit = 0x00000002,
        PartiallyBoundBit = 0x00000004,
        VariableDescriptorCountBit = 0x00000008,
        UpdateAfterBindBitEXT = UpdateAfterBindBit,
        UpdateUnusedWhilePendingBitEXT = UpdateUnusedWhilePendingBit,
        PartiallyBoundBitEXT = PartiallyBoundBit,
        VariableDescriptorCountBitEXT = VariableDescriptorCountBit
    };
    
    std::string_view    to_string_view(VqDescriptorBindingFlagBits);

    enum class VqDescriptorPoolCreateFlagBits : uint32_t {
        FreeDescriptorSetBit = 0x00000001,
        UpdateAfterBindBit = 0x00000002,
        HostOnlyBitEXT = 0x00000004,
        AllowOverallocationSetsBitNV = 0x00000008,
        AllowOverallocationPoolsBitNV = 0x00000010,
        UpdateAfterBindBitEXT = UpdateAfterBindBit,
        HostOnlyBitValve = HostOnlyBitEXT
    };
    
    std::string_view    to_string_view(VqDescriptorPoolCreateFlagBits);

    enum class VqDescriptorSetLayoutCreateFlagBits : uint32_t {
        UpdateAfterBindPoolBit = 0x00000002,
        PushDescriptorBitKHR = 0x00000001,
        DescriptorBufferBitEXT = 0x00000010,
        EmbeddedImmutableSamplersBitEXT = 0x00000020,
        IndirectBindableBitNV = 0x00000080,
        HostOnlyPoolBitEXT = 0x00000004,
        PerStageBitNV = 0x00000040,
        UpdateAfterBindPoolBitEXT = UpdateAfterBindPoolBit,
        HostOnlyPoolBitValve = HostOnlyPoolBitEXT
    };
    
    std::string_view    to_string_view(VqDescriptorSetLayoutCreateFlagBits);

    enum class VqDescriptorType : uint32_t {
        Sampler = 0,
        CombinedImageSampler = 1,
        SampledImage = 2,
        StorageImage = 3,
        UniformTexelBuffer = 4,
        StorageTexelBuffer = 5,
        UniformBuffer = 6,
        StorageBuffer = 7,
        UniformBufferDynamic = 8,
        StorageBufferDynamic = 9,
        InputAttachment = 10,
        InlineUniformBlock = 1000138000,
        AccelerationStructureKHR = 1000150000,
        AccelerationStructureNV = 1000165000,
        SampleWeightImageQCOM = 1000440000,
        BlockMatchImageQCOM = 1000440001,
        MutableEXT = 1000351000,
        InlineUniformBlockEXT = InlineUniformBlock,
        MutableValve = MutableEXT
    };
    
    std::string_view    to_string_view(VqDescriptorType);

    enum class VqDescriptorUpdateTemplateType : uint32_t {
        DescriptorSet = 0,
        PushDescriptorsKHR = 1,
        DescriptorSetKHR = DescriptorSet
    };
    
    std::string_view    to_string_view(VqDescriptorUpdateTemplateType);

    enum class VqDeviceAddressBindingFlagBits : uint32_t {
        InternalObjectBitEXT = 0x00000001
    };
    
    std::string_view    to_string_view(VqDeviceAddressBindingFlagBits);

    enum class VqDeviceAddressBindingType : uint32_t {
        BindEXT = 0,
        UnbindEXT = 1
    };
    
    std::string_view    to_string_view(VqDeviceAddressBindingType);

    enum class VqDeviceDiagnosticsConfigFlagBits : uint32_t {
        EnableShaderDebugInfoBitNV = 0x00000001,
        EnableResourceTrackingBitNV = 0x00000002,
        EnableAutomaticCheckpointsBitNV = 0x00000004,
        EnableShaderErrorReportingBitNV = 0x00000008
    };
    
    std::string_view    to_string_view(VqDeviceDiagnosticsConfigFlagBits);

    enum class VqDeviceEventType : uint32_t {
        DisplayHotplugEXT = 0
    };
    
    std::string_view    to_string_view(VqDeviceEventType);

    enum class VqDeviceFaultAddressType : uint32_t {
        NoneEXT = 0,
        ReadInvalidEXT = 1,
        WriteInvalidEXT = 2,
        ExecuteInvalidEXT = 3,
        InstructionPointerUnknownEXT = 4,
        InstructionPointerInvalidEXT = 5,
        InstructionPointerFaultEXT = 6
    };
    
    std::string_view    to_string_view(VqDeviceFaultAddressType);

    enum class VqDeviceFaultVendorBinaryHeaderVersion : uint32_t {
        OneEXT = 1
    };
    
    std::string_view    to_string_view(VqDeviceFaultVendorBinaryHeaderVersion);

    enum class VqDeviceGroupPresentModeFlagBits : uint32_t {
        LocalBitKHR = 0x00000001,
        RemoteBitKHR = 0x00000002,
        SumBitKHR = 0x00000004,
        LocalMultiDeviceBitKHR = 0x00000008
    };
    
    std::string_view    to_string_view(VqDeviceGroupPresentModeFlagBits);

    enum class VqDeviceMemoryReportEventType : uint32_t {
        AllocateEXT = 0,
        FreeEXT = 1,
        ImportEXT = 2,
        UnimportEXT = 3,
        AllocationFailedEXT = 4
    };
    
    std::string_view    to_string_view(VqDeviceMemoryReportEventType);

    enum class VqDeviceQueueCreateFlagBits : uint32_t {
        ProtectedBit = 0x00000001
    };
    
    std::string_view    to_string_view(VqDeviceQueueCreateFlagBits);

    enum class VqDirectDriverLoadingMode : uint32_t {
        ExclusiveLUNARG = 0,
        InclusiveLUNARG = 1
    };
    
    std::string_view    to_string_view(VqDirectDriverLoadingMode);

    enum class VqDiscardRectangleMode : uint32_t {
        InclusiveEXT = 0,
        ExclusiveEXT = 1
    };
    
    std::string_view    to_string_view(VqDiscardRectangleMode);

    enum class VqDisplayEventType : uint32_t {
        FirstPixelOutEXT = 0
    };
    
    std::string_view    to_string_view(VqDisplayEventType);

    enum class VqDisplayPlaneAlphaFlagBits : uint32_t {
        OpaqueBitKHR = 0x00000001,
        GlobalBitKHR = 0x00000002,
        PerPixelBitKHR = 0x00000004,
        PerPixelPremultipliedBitKHR = 0x00000008
    };
    
    std::string_view    to_string_view(VqDisplayPlaneAlphaFlagBits);

    enum class VqDisplayPowerState : uint32_t {
        OffEXT = 0,
        SuspendEXT = 1,
        OnEXT = 2
    };
    
    std::string_view    to_string_view(VqDisplayPowerState);

    enum class VqDriverId : uint32_t {
        AMDProprietary = 1,
        AMDOpenSource = 2,
        MesaRadv = 3,
        NvidiaProprietary = 4,
        INTELProprietaryWindows = 5,
        INTELOpenSourceMesa = 6,
        ImaginationProprietary = 7,
        QualcommProprietary = 8,
        ArmProprietary = 9,
        GoogleSwiftshader = 10,
        GgpProprietary = 11,
        BroadcomProprietary = 12,
        MesaLlvmpipe = 13,
        Moltenvk = 14,
        CoreaviProprietary = 15,
        JuiceProprietary = 16,
        VerisiliconProprietary = 17,
        MesaTurnip = 18,
        MesaV3dv = 19,
        MesaPanvk = 20,
        SamsungProprietary = 21,
        MesaVenus = 22,
        MesaDozen = 23,
        MesaNvk = 24,
        ImaginationOpenSourceMesa = 25,
        MesaHoneykrisp = 26,
        Reserved27 = 27,
        AMDProprietaryKHR = AMDProprietary,
        AMDOpenSourceKHR = AMDOpenSource,
        MesaRadvKHR = MesaRadv,
        NvidiaProprietaryKHR = NvidiaProprietary,
        INTELProprietaryWindowsKHR = INTELProprietaryWindows,
        INTELOpenSourceMesaKHR = INTELOpenSourceMesa,
        ImaginationProprietaryKHR = ImaginationProprietary,
        QualcommProprietaryKHR = QualcommProprietary,
        ArmProprietaryKHR = ArmProprietary,
        GoogleSwiftshaderKHR = GoogleSwiftshader,
        GgpProprietaryKHR = GgpProprietary,
        BroadcomProprietaryKHR = BroadcomProprietary
    };
    
    std::string_view    to_string_view(VqDriverId);

    enum class VqDynamicState : uint32_t {
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
        ViewportWScalingNV = 1000087000,
        DiscardRectangleEXT = 1000099000,
        DiscardRectangleEnableEXT = 1000099001,
        DiscardRectangleModeEXT = 1000099002,
        SampleLocationsEXT = 1000143000,
        RayTracingPipelineStackSizeKHR = 1000347000,
        ViewportShadingRatePaletteNV = 1000164004,
        ViewportCoarseSampleOrderNV = 1000164006,
        ExclusiveScissorEnableNV = 1000205000,
        ExclusiveScissorNV = 1000205001,
        FragmentShadingRateKHR = 1000226000,
        VertexInputEXT = 1000352000,
        PatchControlPointsEXT = 1000377000,
        LogicOpEXT = 1000377003,
        ColorWriteEnableEXT = 1000381000,
        DepthClampEnableEXT = 1000455003,
        PolygonModeEXT = 1000455004,
        RasterizationSamplesEXT = 1000455005,
        SampleMaskEXT = 1000455006,
        AlphaToCoverageEnableEXT = 1000455007,
        AlphaToOneEnableEXT = 1000455008,
        LogicOpEnableEXT = 1000455009,
        ColorBlendEnableEXT = 1000455010,
        ColorBlendEquationEXT = 1000455011,
        ColorWriteMaskEXT = 1000455012,
        TessellationDomainOriginEXT = 1000455002,
        RasterizationStreamEXT = 1000455013,
        ConservativeRasterizationModeEXT = 1000455014,
        ExtraPrimitiveOverestimationSizeEXT = 1000455015,
        DepthClipEnableEXT = 1000455016,
        SampleLocationsEnableEXT = 1000455017,
        ColorBlendAdvancedEXT = 1000455018,
        ProvokingVertexModeEXT = 1000455019,
        LineRasterizationModeEXT = 1000455020,
        LineStippleEnableEXT = 1000455021,
        DepthClipNegativeOneToOneEXT = 1000455022,
        ViewportWScalingEnableNV = 1000455023,
        ViewportSwizzleNV = 1000455024,
        CoverageToColorEnableNV = 1000455025,
        CoverageToColorLocationNV = 1000455026,
        CoverageModulationModeNV = 1000455027,
        CoverageModulationTableEnableNV = 1000455028,
        CoverageModulationTableNV = 1000455029,
        ShadingRateImageEnableNV = 1000455030,
        RepresentativeFragmentTestEnableNV = 1000455031,
        CoverageReductionModeNV = 1000455032,
        AttachmentFeedbackLoopEnableEXT = 1000524000,
        LineStippleKHR = 1000259000,
        LineStippleEXT = LineStippleKHR,
        CullModeEXT = CullMode,
        FrontFaceEXT = FrontFace,
        PrimitiveTopologyEXT = PrimitiveTopology,
        ViewportWithCountEXT = ViewportWithCount,
        ScissorWithCountEXT = ScissorWithCount,
        VertexInputBindingStrideEXT = VertexInputBindingStride,
        DepthTestEnableEXT = DepthTestEnable,
        DepthWriteEnableEXT = DepthWriteEnable,
        DepthCompareOpEXT = DepthCompareOp,
        DepthBoundsTestEnableEXT = DepthBoundsTestEnable,
        StencilTestEnableEXT = StencilTestEnable,
        StencilOpEXT = StencilOp,
        RasterizerDiscardEnableEXT = RasterizerDiscardEnable,
        DepthBiasEnableEXT = DepthBiasEnable,
        PrimitiveRestartEnableEXT = PrimitiveRestartEnable
    };
    
    std::string_view    to_string_view(VqDynamicState);

    enum class VqEventCreateFlagBits : uint32_t {
        DeviceOnlyBit = 0x00000001,
        DeviceOnlyBitKHR = DeviceOnlyBit
    };
    
    std::string_view    to_string_view(VqEventCreateFlagBits);

    enum class VqExternalFenceFeatureFlagBits : uint32_t {
        ExportableBit = 0x00000001,
        ImportableBit = 0x00000002,
        ExportableBitKHR = ExportableBit,
        ImportableBitKHR = ImportableBit
    };
    
    std::string_view    to_string_view(VqExternalFenceFeatureFlagBits);

    enum class VqExternalFenceHandleTypeFlagBits : uint32_t {
        OpaqueFdBit = 0x00000001,
        OpaqueWin32Bit = 0x00000002,
        OpaqueWin32KmtBit = 0x00000004,
        SyncFdBit = 0x00000008,
        OpaqueFdBitKHR = OpaqueFdBit,
        OpaqueWin32BitKHR = OpaqueWin32Bit,
        OpaqueWin32KmtBitKHR = OpaqueWin32KmtBit,
        SyncFdBitKHR = SyncFdBit
    };
    
    std::string_view    to_string_view(VqExternalFenceHandleTypeFlagBits);

    enum class VqExternalMemoryFeatureFlagBits : uint32_t {
        DedicatedOnlyBit = 0x00000001,
        ExportableBit = 0x00000002,
        ImportableBit = 0x00000004,
        DedicatedOnlyBitKHR = DedicatedOnlyBit,
        ExportableBitKHR = ExportableBit,
        ImportableBitKHR = ImportableBit
    };
    
    std::string_view    to_string_view(VqExternalMemoryFeatureFlagBits);

    enum class VqExternalMemoryFeatureFlagBits : uint32_t {
        DedicatedOnlyBitNV = 0x00000001,
        ExportableBitNV = 0x00000002,
        ImportableBitNV = 0x00000004
    };
    
    std::string_view    to_string_view(VqExternalMemoryFeatureFlagBits);

    enum class VqExternalMemoryHandleTypeFlagBits : uint32_t {
        OpaqueFdBit = 0x00000001,
        OpaqueWin32Bit = 0x00000002,
        OpaqueWin32KmtBit = 0x00000004,
        D3d11TextureBit = 0x00000008,
        D3d11TextureKmtBit = 0x00000010,
        D3d12HeapBit = 0x00000020,
        D3d12ResourceBit = 0x00000040,
        DmaBufBitEXT = 0x00000200,
        AndroidHardwareBufferBitAndroid = 0x00000400,
        HostAllocationBitEXT = 0x00000080,
        HostMappedForeignMemoryBitEXT = 0x00000100,
        ZirconVmoBitFuchsia = 0x00000800,
        RdmaAddressBitNV = 0x00001000,
        ScreenBufferBitQnx = 0x00004000,
        OpaqueFdBitKHR = OpaqueFdBit,
        OpaqueWin32BitKHR = OpaqueWin32Bit,
        OpaqueWin32KmtBitKHR = OpaqueWin32KmtBit,
        D3d11TextureBitKHR = D3d11TextureBit,
        D3d11TextureKmtBitKHR = D3d11TextureKmtBit,
        D3d12HeapBitKHR = D3d12HeapBit,
        D3d12ResourceBitKHR = D3d12ResourceBit
    };
    
    std::string_view    to_string_view(VqExternalMemoryHandleTypeFlagBits);

    enum class VqExternalMemoryHandleTypeFlagBits : uint32_t {
        OpaqueWin32BitNV = 0x00000001,
        OpaqueWin32KmtBitNV = 0x00000002,
        D3d11ImageBitNV = 0x00000004,
        D3d11ImageKmtBitNV = 0x00000008
    };
    
    std::string_view    to_string_view(VqExternalMemoryHandleTypeFlagBits);

    enum class VqExternalSemaphoreFeatureFlagBits : uint32_t {
        ExportableBit = 0x00000001,
        ImportableBit = 0x00000002,
        ExportableBitKHR = ExportableBit,
        ImportableBitKHR = ImportableBit
    };
    
    std::string_view    to_string_view(VqExternalSemaphoreFeatureFlagBits);

    enum class VqExternalSemaphoreHandleTypeFlagBits : uint32_t {
        OpaqueFdBit = 0x00000001,
        OpaqueWin32Bit = 0x00000002,
        OpaqueWin32KmtBit = 0x00000004,
        D3d12FenceBit = 0x00000008,
        SyncFdBit = 0x00000010,
        ZirconEventBitFuchsia = 0x00000080,
        D3d11FenceBit = D3d12FenceBit,
        OpaqueFdBitKHR = OpaqueFdBit,
        OpaqueWin32BitKHR = OpaqueWin32Bit,
        OpaqueWin32KmtBitKHR = OpaqueWin32KmtBit,
        D3d12FenceBitKHR = D3d12FenceBit,
        SyncFdBitKHR = SyncFdBit
    };
    
    std::string_view    to_string_view(VqExternalSemaphoreHandleTypeFlagBits);

    enum class VqFenceCreateFlagBits : uint32_t {
        SignaledBit = 0x00000001
    };
    
    std::string_view    to_string_view(VqFenceCreateFlagBits);

    enum class VqFenceImportFlagBits : uint32_t {
        TemporaryBit = 0x00000001,
        TemporaryBitKHR = TemporaryBit
    };
    
    std::string_view    to_string_view(VqFenceImportFlagBits);

    enum class VqFilter : uint32_t {
        Nearest = 0,
        Linear = 1,
        CubicEXT = 1000015000,
        CubicImg = CubicEXT
    };
    
    std::string_view    to_string_view(VqFilter);

    enum class VqFormat : uint32_t {
        Undefined = 0,
        R4g4UnormPack8 = 1,
        R4g4b4a4UnormPack16 = 2,
        B4g4r4a4UnormPack16 = 3,
        R5g6b5UnormPack16 = 4,
        B5g6r5UnormPack16 = 5,
        R5g5b5a1UnormPack16 = 6,
        B5g5r5a1UnormPack16 = 7,
        A1r5g5b5UnormPack16 = 8,
        R8Unorm = 9,
        R8Snorm = 10,
        R8Uscaled = 11,
        R8Sscaled = 12,
        R8Uint = 13,
        R8Sint = 14,
        R8Srgb = 15,
        R8g8Unorm = 16,
        R8g8Snorm = 17,
        R8g8Uscaled = 18,
        R8g8Sscaled = 19,
        R8g8Uint = 20,
        R8g8Sint = 21,
        R8g8Srgb = 22,
        R8g8b8Unorm = 23,
        R8g8b8Snorm = 24,
        R8g8b8Uscaled = 25,
        R8g8b8Sscaled = 26,
        R8g8b8Uint = 27,
        R8g8b8Sint = 28,
        R8g8b8Srgb = 29,
        B8g8r8Unorm = 30,
        B8g8r8Snorm = 31,
        B8g8r8Uscaled = 32,
        B8g8r8Sscaled = 33,
        B8g8r8Uint = 34,
        B8g8r8Sint = 35,
        B8g8r8Srgb = 36,
        R8g8b8a8Unorm = 37,
        R8g8b8a8Snorm = 38,
        R8g8b8a8Uscaled = 39,
        R8g8b8a8Sscaled = 40,
        R8g8b8a8Uint = 41,
        R8g8b8a8Sint = 42,
        R8g8b8a8Srgb = 43,
        B8g8r8a8Unorm = 44,
        B8g8r8a8Snorm = 45,
        B8g8r8a8Uscaled = 46,
        B8g8r8a8Sscaled = 47,
        B8g8r8a8Uint = 48,
        B8g8r8a8Sint = 49,
        B8g8r8a8Srgb = 50,
        A8b8g8r8UnormPack32 = 51,
        A8b8g8r8SnormPack32 = 52,
        A8b8g8r8UscaledPack32 = 53,
        A8b8g8r8SscaledPack32 = 54,
        A8b8g8r8UintPack32 = 55,
        A8b8g8r8SintPack32 = 56,
        A8b8g8r8SrgbPack32 = 57,
        A2r10g10b10UnormPack32 = 58,
        A2r10g10b10SnormPack32 = 59,
        A2r10g10b10UscaledPack32 = 60,
        A2r10g10b10SscaledPack32 = 61,
        A2r10g10b10UintPack32 = 62,
        A2r10g10b10SintPack32 = 63,
        A2b10g10r10UnormPack32 = 64,
        A2b10g10r10SnormPack32 = 65,
        A2b10g10r10UscaledPack32 = 66,
        A2b10g10r10SscaledPack32 = 67,
        A2b10g10r10UintPack32 = 68,
        A2b10g10r10SintPack32 = 69,
        R16Unorm = 70,
        R16Snorm = 71,
        R16Uscaled = 72,
        R16Sscaled = 73,
        R16Uint = 74,
        R16Sint = 75,
        R16Sfloat = 76,
        R16g16Unorm = 77,
        R16g16Snorm = 78,
        R16g16Uscaled = 79,
        R16g16Sscaled = 80,
        R16g16Uint = 81,
        R16g16Sint = 82,
        R16g16Sfloat = 83,
        R16g16b16Unorm = 84,
        R16g16b16Snorm = 85,
        R16g16b16Uscaled = 86,
        R16g16b16Sscaled = 87,
        R16g16b16Uint = 88,
        R16g16b16Sint = 89,
        R16g16b16Sfloat = 90,
        R16g16b16a16Unorm = 91,
        R16g16b16a16Snorm = 92,
        R16g16b16a16Uscaled = 93,
        R16g16b16a16Sscaled = 94,
        R16g16b16a16Uint = 95,
        R16g16b16a16Sint = 96,
        R16g16b16a16Sfloat = 97,
        R32Uint = 98,
        R32Sint = 99,
        R32Sfloat = 100,
        R32g32Uint = 101,
        R32g32Sint = 102,
        R32g32Sfloat = 103,
        R32g32b32Uint = 104,
        R32g32b32Sint = 105,
        R32g32b32Sfloat = 106,
        R32g32b32a32Uint = 107,
        R32g32b32a32Sint = 108,
        R32g32b32a32Sfloat = 109,
        R64Uint = 110,
        R64Sint = 111,
        R64Sfloat = 112,
        R64g64Uint = 113,
        R64g64Sint = 114,
        R64g64Sfloat = 115,
        R64g64b64Uint = 116,
        R64g64b64Sint = 117,
        R64g64b64Sfloat = 118,
        R64g64b64a64Uint = 119,
        R64g64b64a64Sint = 120,
        R64g64b64a64Sfloat = 121,
        B10g11r11UfloatPack32 = 122,
        E5b9g9r9UfloatPack32 = 123,
        D16Unorm = 124,
        X8D24UnormPack32 = 125,
        D32Sfloat = 126,
        S8Uint = 127,
        D16UnormS8Uint = 128,
        D24UnormS8Uint = 129,
        D32SfloatS8Uint = 130,
        Bc1RgbUnormBlock = 131,
        Bc1RgbSrgbBlock = 132,
        Bc1RgbaUnormBlock = 133,
        Bc1RgbaSrgbBlock = 134,
        Bc2UnormBlock = 135,
        Bc2SrgbBlock = 136,
        Bc3UnormBlock = 137,
        Bc3SrgbBlock = 138,
        Bc4UnormBlock = 139,
        Bc4SnormBlock = 140,
        Bc5UnormBlock = 141,
        Bc5SnormBlock = 142,
        Bc6hUfloatBlock = 143,
        Bc6hSfloatBlock = 144,
        Bc7UnormBlock = 145,
        Bc7SrgbBlock = 146,
        Etc2R8g8b8UnormBlock = 147,
        Etc2R8g8b8SrgbBlock = 148,
        Etc2R8g8b8a1UnormBlock = 149,
        Etc2R8g8b8a1SrgbBlock = 150,
        Etc2R8g8b8a8UnormBlock = 151,
        Etc2R8g8b8a8SrgbBlock = 152,
        EacR11UnormBlock = 153,
        EacR11SnormBlock = 154,
        EacR11g11UnormBlock = 155,
        EacR11g11SnormBlock = 156,
        Astc4x4UnormBlock = 157,
        Astc4x4SrgbBlock = 158,
        Astc5x4UnormBlock = 159,
        Astc5x4SrgbBlock = 160,
        Astc5x5UnormBlock = 161,
        Astc5x5SrgbBlock = 162,
        Astc6x5UnormBlock = 163,
        Astc6x5SrgbBlock = 164,
        Astc6x6UnormBlock = 165,
        Astc6x6SrgbBlock = 166,
        Astc8x5UnormBlock = 167,
        Astc8x5SrgbBlock = 168,
        Astc8x6UnormBlock = 169,
        Astc8x6SrgbBlock = 170,
        Astc8x8UnormBlock = 171,
        Astc8x8SrgbBlock = 172,
        Astc10x5UnormBlock = 173,
        Astc10x5SrgbBlock = 174,
        Astc10x6UnormBlock = 175,
        Astc10x6SrgbBlock = 176,
        Astc10x8UnormBlock = 177,
        Astc10x8SrgbBlock = 178,
        Astc10x10UnormBlock = 179,
        Astc10x10SrgbBlock = 180,
        Astc12x10UnormBlock = 181,
        Astc12x10SrgbBlock = 182,
        Astc12x12UnormBlock = 183,
        Astc12x12SrgbBlock = 184,
        G8b8g8r8422Unorm = 1000156000,
        B8g8r8g8422Unorm = 1000156001,
        G8B8R83plane420Unorm = 1000156002,
        G8B8r82plane420Unorm = 1000156003,
        G8B8R83plane422Unorm = 1000156004,
        G8B8r82plane422Unorm = 1000156005,
        G8B8R83plane444Unorm = 1000156006,
        R10x6UnormPack16 = 1000156007,
        R10x6g10x6Unorm2pack16 = 1000156008,
        R10x6g10x6b10x6a10x6Unorm4pack16 = 1000156009,
        G10x6b10x6g10x6r10x6422Unorm4pack16 = 1000156010,
        B10x6g10x6r10x6g10x6422Unorm4pack16 = 1000156011,
        G10x6B10x6R10x63plane420Unorm3pack16 = 1000156012,
        G10x6B10x6r10x62plane420Unorm3pack16 = 1000156013,
        G10x6B10x6R10x63plane422Unorm3pack16 = 1000156014,
        G10x6B10x6r10x62plane422Unorm3pack16 = 1000156015,
        G10x6B10x6R10x63plane444Unorm3pack16 = 1000156016,
        R12x4UnormPack16 = 1000156017,
        R12x4g12x4Unorm2pack16 = 1000156018,
        R12x4g12x4b12x4a12x4Unorm4pack16 = 1000156019,
        G12x4b12x4g12x4r12x4422Unorm4pack16 = 1000156020,
        B12x4g12x4r12x4g12x4422Unorm4pack16 = 1000156021,
        G12x4B12x4R12x43plane420Unorm3pack16 = 1000156022,
        G12x4B12x4r12x42plane420Unorm3pack16 = 1000156023,
        G12x4B12x4R12x43plane422Unorm3pack16 = 1000156024,
        G12x4B12x4r12x42plane422Unorm3pack16 = 1000156025,
        G12x4B12x4R12x43plane444Unorm3pack16 = 1000156026,
        G16b16g16r16422Unorm = 1000156027,
        B16g16r16g16422Unorm = 1000156028,
        G16B16R163plane420Unorm = 1000156029,
        G16B16r162plane420Unorm = 1000156030,
        G16B16R163plane422Unorm = 1000156031,
        G16B16r162plane422Unorm = 1000156032,
        G16B16R163plane444Unorm = 1000156033,
        G8B8r82plane444Unorm = 1000330000,
        G10x6B10x6r10x62plane444Unorm3pack16 = 1000330001,
        G12x4B12x4r12x42plane444Unorm3pack16 = 1000330002,
        G16B16r162plane444Unorm = 1000330003,
        A4r4g4b4UnormPack16 = 1000340000,
        A4b4g4r4UnormPack16 = 1000340001,
        Astc4x4SfloatBlock = 1000066000,
        Astc5x4SfloatBlock = 1000066001,
        Astc5x5SfloatBlock = 1000066002,
        Astc6x5SfloatBlock = 1000066003,
        Astc6x6SfloatBlock = 1000066004,
        Astc8x5SfloatBlock = 1000066005,
        Astc8x6SfloatBlock = 1000066006,
        Astc8x8SfloatBlock = 1000066007,
        Astc10x5SfloatBlock = 1000066008,
        Astc10x6SfloatBlock = 1000066009,
        Astc10x8SfloatBlock = 1000066010,
        Astc10x10SfloatBlock = 1000066011,
        Astc12x10SfloatBlock = 1000066012,
        Astc12x12SfloatBlock = 1000066013,
        Pvrtc12bppUnormBlockImg = 1000054000,
        Pvrtc14bppUnormBlockImg = 1000054001,
        Pvrtc22bppUnormBlockImg = 1000054002,
        Pvrtc24bppUnormBlockImg = 1000054003,
        Pvrtc12bppSrgbBlockImg = 1000054004,
        Pvrtc14bppSrgbBlockImg = 1000054005,
        Pvrtc22bppSrgbBlockImg = 1000054006,
        Pvrtc24bppSrgbBlockImg = 1000054007,
        R16g16Sfixed5NV = 1000464000,
        A1b5g5r5UnormPack16KHR = 1000470000,
        A8UnormKHR = 1000470001,
        Astc4x4SfloatBlockEXT = Astc4x4SfloatBlock,
        Astc5x4SfloatBlockEXT = Astc5x4SfloatBlock,
        Astc5x5SfloatBlockEXT = Astc5x5SfloatBlock,
        Astc6x5SfloatBlockEXT = Astc6x5SfloatBlock,
        Astc6x6SfloatBlockEXT = Astc6x6SfloatBlock,
        Astc8x5SfloatBlockEXT = Astc8x5SfloatBlock,
        Astc8x6SfloatBlockEXT = Astc8x6SfloatBlock,
        Astc8x8SfloatBlockEXT = Astc8x8SfloatBlock,
        Astc10x5SfloatBlockEXT = Astc10x5SfloatBlock,
        Astc10x6SfloatBlockEXT = Astc10x6SfloatBlock,
        Astc10x8SfloatBlockEXT = Astc10x8SfloatBlock,
        Astc10x10SfloatBlockEXT = Astc10x10SfloatBlock,
        Astc12x10SfloatBlockEXT = Astc12x10SfloatBlock,
        Astc12x12SfloatBlockEXT = Astc12x12SfloatBlock,
        G8b8g8r8422UnormKHR = G8b8g8r8422Unorm,
        B8g8r8g8422UnormKHR = B8g8r8g8422Unorm,
        G8B8R83plane420UnormKHR = G8B8R83plane420Unorm,
        G8B8r82plane420UnormKHR = G8B8r82plane420Unorm,
        G8B8R83plane422UnormKHR = G8B8R83plane422Unorm,
        G8B8r82plane422UnormKHR = G8B8r82plane422Unorm,
        G8B8R83plane444UnormKHR = G8B8R83plane444Unorm,
        R10x6UnormPack16KHR = R10x6UnormPack16,
        R10x6g10x6Unorm2pack16KHR = R10x6g10x6Unorm2pack16,
        R10x6g10x6b10x6a10x6Unorm4pack16KHR = R10x6g10x6b10x6a10x6Unorm4pack16,
        G10x6b10x6g10x6r10x6422Unorm4pack16KHR = G10x6b10x6g10x6r10x6422Unorm4pack16,
        B10x6g10x6r10x6g10x6422Unorm4pack16KHR = B10x6g10x6r10x6g10x6422Unorm4pack16,
        G10x6B10x6R10x63plane420Unorm3pack16KHR = G10x6B10x6R10x63plane420Unorm3pack16,
        G10x6B10x6r10x62plane420Unorm3pack16KHR = G10x6B10x6r10x62plane420Unorm3pack16,
        G10x6B10x6R10x63plane422Unorm3pack16KHR = G10x6B10x6R10x63plane422Unorm3pack16,
        G10x6B10x6r10x62plane422Unorm3pack16KHR = G10x6B10x6r10x62plane422Unorm3pack16,
        G10x6B10x6R10x63plane444Unorm3pack16KHR = G10x6B10x6R10x63plane444Unorm3pack16,
        R12x4UnormPack16KHR = R12x4UnormPack16,
        R12x4g12x4Unorm2pack16KHR = R12x4g12x4Unorm2pack16,
        R12x4g12x4b12x4a12x4Unorm4pack16KHR = R12x4g12x4b12x4a12x4Unorm4pack16,
        G12x4b12x4g12x4r12x4422Unorm4pack16KHR = G12x4b12x4g12x4r12x4422Unorm4pack16,
        B12x4g12x4r12x4g12x4422Unorm4pack16KHR = B12x4g12x4r12x4g12x4422Unorm4pack16,
        G12x4B12x4R12x43plane420Unorm3pack16KHR = G12x4B12x4R12x43plane420Unorm3pack16,
        G12x4B12x4r12x42plane420Unorm3pack16KHR = G12x4B12x4r12x42plane420Unorm3pack16,
        G12x4B12x4R12x43plane422Unorm3pack16KHR = G12x4B12x4R12x43plane422Unorm3pack16,
        G12x4B12x4r12x42plane422Unorm3pack16KHR = G12x4B12x4r12x42plane422Unorm3pack16,
        G12x4B12x4R12x43plane444Unorm3pack16KHR = G12x4B12x4R12x43plane444Unorm3pack16,
        G16b16g16r16422UnormKHR = G16b16g16r16422Unorm,
        B16g16r16g16422UnormKHR = B16g16r16g16422Unorm,
        G16B16R163plane420UnormKHR = G16B16R163plane420Unorm,
        G16B16r162plane420UnormKHR = G16B16r162plane420Unorm,
        G16B16R163plane422UnormKHR = G16B16R163plane422Unorm,
        G16B16r162plane422UnormKHR = G16B16r162plane422Unorm,
        G16B16R163plane444UnormKHR = G16B16R163plane444Unorm,
        G8B8r82plane444UnormEXT = G8B8r82plane444Unorm,
        G10x6B10x6r10x62plane444Unorm3pack16EXT = G10x6B10x6r10x62plane444Unorm3pack16,
        G12x4B12x4r12x42plane444Unorm3pack16EXT = G12x4B12x4r12x42plane444Unorm3pack16,
        G16B16r162plane444UnormEXT = G16B16r162plane444Unorm,
        A4r4g4b4UnormPack16EXT = A4r4g4b4UnormPack16,
        A4b4g4r4UnormPack16EXT = A4b4g4r4UnormPack16,
        R16g16S105NV = R16g16Sfixed5NV
    };
    
    std::string_view    to_string_view(VqFormat);

    enum class VqFormatFeatureFlagBits : uint32_t {
        SampledImageBit = 0x00000001,
        StorageImageBit = 0x00000002,
        StorageImageAtomicBit = 0x00000004,
        UniformTexelBufferBit = 0x00000008,
        StorageTexelBufferBit = 0x00000010,
        StorageTexelBufferAtomicBit = 0x00000020,
        VertexBufferBit = 0x00000040,
        ColorAttachmentBit = 0x00000080,
        ColorAttachmentBlendBit = 0x00000100,
        DepthStencilAttachmentBit = 0x00000200,
        BlitSrcBit = 0x00000400,
        BlitDstBit = 0x00000800,
        SampledImageFilterLinearBit = 0x00001000,
        TransferSrcBit = 0x00004000,
        TransferDstBit = 0x00008000,
        MidpointChromaSamplesBit = 0x00020000,
        SampledImageYcbcrConversionLinearFilterBit = 0x00040000,
        SampledImageYcbcrConversionSeparateReconstructionFilterBit = 0x00080000,
        SampledImageYcbcrConversionChromaReconstructionExplicitBit = 0x00100000,
        SampledImageYcbcrConversionChromaReconstructionExplicitForceableBit = 0x00200000,
        DisjointBit = 0x00400000,
        CositedChromaSamplesBit = 0x00800000,
        SampledImageFilterMinmaxBit = 0x00010000,
        VideoDecodeOutputBitKHR = 0x02000000,
        VideoDecodeDpbBitKHR = 0x04000000,
        AccelerationStructureVertexBufferBitKHR = 0x20000000,
        SampledImageFilterCubicBitEXT = 0x00002000,
        FragmentDensityMapBitEXT = 0x01000000,
        FragmentShadingRateAttachmentBitKHR = 0x40000000,
        VideoEncodeInputBitKHR = 0x08000000,
        VideoEncodeDpbBitKHR = 0x10000000,
        SampledImageFilterCubicBitImg = SampledImageFilterCubicBitEXT,
        TransferSrcBitKHR = TransferSrcBit,
        TransferDstBitKHR = TransferDstBit,
        SampledImageFilterMinmaxBitEXT = SampledImageFilterMinmaxBit,
        MidpointChromaSamplesBitKHR = MidpointChromaSamplesBit,
        SampledImageYcbcrConversionLinearFilterBitKHR = SampledImageYcbcrConversionLinearFilterBit,
        SampledImageYcbcrConversionSeparateReconstructionFilterBitKHR = SampledImageYcbcrConversionSeparateReconstructionFilterBit,
        SampledImageYcbcrConversionChromaReconstructionExplicitBitKHR = SampledImageYcbcrConversionChromaReconstructionExplicitBit,
        SampledImageYcbcrConversionChromaReconstructionExplicitForceableBitKHR = SampledImageYcbcrConversionChromaReconstructionExplicitForceableBit,
        DisjointBitKHR = DisjointBit,
        CositedChromaSamplesBitKHR = CositedChromaSamplesBit
    };
    
    std::string_view    to_string_view(VqFormatFeatureFlagBits);

    enum class VqFragmentShadingRate : uint32_t {
        1InvocationPerPixelNV = 0,
        1InvocationPer1x2PixelsNV = 1,
        1InvocationPer2x1PixelsNV = 4,
        1InvocationPer2x2PixelsNV = 5,
        1InvocationPer2x4PixelsNV = 6,
        1InvocationPer4x2PixelsNV = 9,
        1InvocationPer4x4PixelsNV = 10,
        2InvocationsPerPixelNV = 11,
        4InvocationsPerPixelNV = 12,
        8InvocationsPerPixelNV = 13,
        16InvocationsPerPixelNV = 14,
        NoInvocationsNV = 15
    };
    
    std::string_view    to_string_view(VqFragmentShadingRate);

    enum class VqFragmentShadingRateCombinerOp : uint32_t {
        KeepKHR = 0,
        ReplaceKHR = 1,
        MinKHR = 2,
        MaxKHR = 3,
        MulKHR = 4
    };
    
    std::string_view    to_string_view(VqFragmentShadingRateCombinerOp);

    enum class VqFragmentShadingRateType : uint32_t {
        FragmentSizeNV = 0,
        EnumsNV = 1
    };
    
    std::string_view    to_string_view(VqFragmentShadingRateType);

    enum class VqFrameBoundaryFlagBits : uint32_t {
        FrameEndBitEXT = 0x00000001
    };
    
    std::string_view    to_string_view(VqFrameBoundaryFlagBits);

    enum class VqFramebufferCreateFlagBits : uint32_t {
        ImagelessBit = 0x00000001,
        ImagelessBitKHR = ImagelessBit
    };
    
    std::string_view    to_string_view(VqFramebufferCreateFlagBits);

    enum class VqFrontFace : uint32_t {
        CounterClockwise = 0,
        Clockwise = 1
    };
    
    std::string_view    to_string_view(VqFrontFace);

    enum class VqGeometryFlagBits : uint32_t {
        OpaqueBitKHR = 0x00000001,
        NoDuplicateAnyHitInvocationBitKHR = 0x00000002,
        OpaqueBitNV = OpaqueBitKHR,
        NoDuplicateAnyHitInvocationBitNV = NoDuplicateAnyHitInvocationBitKHR
    };
    
    std::string_view    to_string_view(VqGeometryFlagBits);

    enum class VqGeometryInstanceFlagBits : uint32_t {
        TriangleFacingCullDisableBitKHR = 0x00000001,
        TriangleFlipFacingBitKHR = 0x00000002,
        ForceOpaqueBitKHR = 0x00000004,
        ForceNoOpaqueBitKHR = 0x00000008,
        ForceOpacityMicromap2StateEXT = 0x00000010,
        DisableOpacityMicromapsEXT = 0x00000020,
        TriangleFrontCounterclockwiseBitKHR = TriangleFlipFacingBitKHR,
        TriangleCullDisableBitNV = TriangleFacingCullDisableBitKHR,
        TriangleFrontCounterclockwiseBitNV = TriangleFrontCounterclockwiseBitKHR,
        ForceOpaqueBitNV = ForceOpaqueBitKHR,
        ForceNoOpaqueBitNV = ForceNoOpaqueBitKHR
    };
    
    std::string_view    to_string_view(VqGeometryInstanceFlagBits);

    enum class VqGeometryType : uint32_t {
        TrianglesKHR = 0,
        AabbsKHR = 1,
        InstancesKHR = 2,
        TrianglesNV = TrianglesKHR,
        AabbsNV = AabbsKHR
    };
    
    std::string_view    to_string_view(VqGeometryType);

    enum class VqGraphicsPipelineLibraryFlagBits : uint32_t {
        VertexInputInterfaceBitEXT = 0x00000001,
        PreRasterizationShadersBitEXT = 0x00000002,
        FragmentShaderBitEXT = 0x00000004,
        FragmentOutputInterfaceBitEXT = 0x00000008
    };
    
    std::string_view    to_string_view(VqGraphicsPipelineLibraryFlagBits);

    enum class VqHostImageCopyFlagBits : uint32_t {
        MemcpyEXT = 0x00000001
    };
    
    std::string_view    to_string_view(VqHostImageCopyFlagBits);

    enum class VqImageAspectFlagBits : uint32_t {
        ColorBit = 0x00000001,
        DepthBit = 0x00000002,
        StencilBit = 0x00000004,
        MetadataBit = 0x00000008,
        Plane0Bit = 0x00000010,
        Plane1Bit = 0x00000020,
        Plane2Bit = 0x00000040,
        None = 0,
        MemoryPlane0BitEXT = 0x00000080,
        MemoryPlane1BitEXT = 0x00000100,
        MemoryPlane2BitEXT = 0x00000200,
        MemoryPlane3BitEXT = 0x00000400,
        Plane0BitKHR = Plane0Bit,
        Plane1BitKHR = Plane1Bit,
        Plane2BitKHR = Plane2Bit,
        NoneKHR = None
    };
    
    std::string_view    to_string_view(VqImageAspectFlagBits);

    enum class VqImageCompressionFixedRateFlagBits : uint32_t {
        NoneEXT = 0,
        1bpcBitEXT = 0x00000001,
        2bpcBitEXT = 0x00000002,
        3bpcBitEXT = 0x00000004,
        4bpcBitEXT = 0x00000008,
        5bpcBitEXT = 0x00000010,
        6bpcBitEXT = 0x00000020,
        7bpcBitEXT = 0x00000040,
        8bpcBitEXT = 0x00000080,
        9bpcBitEXT = 0x00000100,
        10bpcBitEXT = 0x00000200,
        11bpcBitEXT = 0x00000400,
        12bpcBitEXT = 0x00000800,
        13bpcBitEXT = 0x00001000,
        14bpcBitEXT = 0x00002000,
        15bpcBitEXT = 0x00004000,
        16bpcBitEXT = 0x00008000,
        17bpcBitEXT = 0x00010000,
        18bpcBitEXT = 0x00020000,
        19bpcBitEXT = 0x00040000,
        20bpcBitEXT = 0x00080000,
        21bpcBitEXT = 0x00100000,
        22bpcBitEXT = 0x00200000,
        23bpcBitEXT = 0x00400000,
        24bpcBitEXT = 0x00800000
    };
    
    std::string_view    to_string_view(VqImageCompressionFixedRateFlagBits);

    enum class VqImageCompressionFlagBits : uint32_t {
        DefaultEXT = 0,
        FixedRateDefaultEXT = 0x00000001,
        FixedRateExplicitEXT = 0x00000002,
        DisabledEXT = 0x00000004
    };
    
    std::string_view    to_string_view(VqImageCompressionFlagBits);

    enum class VqImageCreateFlagBits : uint32_t {
        SparseBindingBit = 0x00000001,
        SparseResidencyBit = 0x00000002,
        SparseAliasedBit = 0x00000004,
        MutableFormatBit = 0x00000008,
        CubeCompatibleBit = 0x00000010,
        AliasBit = 0x00000400,
        SplitInstanceBindRegionsBit = 0x00000040,
        2dArrayCompatibleBit = 0x00000020,
        BlockTexelViewCompatibleBit = 0x00000080,
        ExtendedUsageBit = 0x00000100,
        ProtectedBit = 0x00000800,
        DisjointBit = 0x00000200,
        CornerSampledBitNV = 0x00002000,
        SampleLocationsCompatibleDepthBitEXT = 0x00001000,
        SubsampledBitEXT = 0x00004000,
        DescriptorBufferCaptureReplayBitEXT = 0x00010000,
        MultisampledRenderToSingleSampledBitEXT = 0x00040000,
        2dViewCompatibleBitEXT = 0x00020000,
        FragmentDensityMapOffsetBitQCOM = 0x00008000,
        VideoProfileIndependentBitKHR = 0x00100000,
        SplitInstanceBindRegionsBitKHR = SplitInstanceBindRegionsBit,
        2dArrayCompatibleBitKHR = 2dArrayCompatibleBit,
        BlockTexelViewCompatibleBitKHR = BlockTexelViewCompatibleBit,
        ExtendedUsageBitKHR = ExtendedUsageBit,
        DisjointBitKHR = DisjointBit,
        AliasBitKHR = AliasBit
    };
    
    std::string_view    to_string_view(VqImageCreateFlagBits);

    enum class VqImageLayout : uint32_t {
        Undefined = 0,
        General = 1,
        ColorAttachmentOptimal = 2,
        DepthStencilAttachmentOptimal = 3,
        DepthStencilReadOnlyOptimal = 4,
        ShaderReadOnlyOptimal = 5,
        TransferSrcOptimal = 6,
        TransferDstOptimal = 7,
        Preinitialized = 8,
        DepthReadOnlyStencilAttachmentOptimal = 1000117000,
        DepthAttachmentStencilReadOnlyOptimal = 1000117001,
        DepthAttachmentOptimal = 1000241000,
        DepthReadOnlyOptimal = 1000241001,
        StencilAttachmentOptimal = 1000241002,
        StencilReadOnlyOptimal = 1000241003,
        ReadOnlyOptimal = 1000314000,
        AttachmentOptimal = 1000314001,
        PresentSrcKHR = 1000001002,
        VideoDecodeDstKHR = 1000024000,
        VideoDecodeSrcKHR = 1000024001,
        VideoDecodeDpbKHR = 1000024002,
        SharedPresentKHR = 1000111000,
        FragmentDensityMapOptimalEXT = 1000218000,
        FragmentShadingRateAttachmentOptimalKHR = 1000164003,
        RenderingLocalReadKHR = 1000232000,
        VideoEncodeDstKHR = 1000299000,
        VideoEncodeSrcKHR = 1000299001,
        VideoEncodeDpbKHR = 1000299002,
        AttachmentFeedbackLoopOptimalEXT = 1000339000,
        DepthReadOnlyStencilAttachmentOptimalKHR = DepthReadOnlyStencilAttachmentOptimal,
        DepthAttachmentStencilReadOnlyOptimalKHR = DepthAttachmentStencilReadOnlyOptimal,
        ShadingRateOptimalNV = FragmentShadingRateAttachmentOptimalKHR,
        DepthAttachmentOptimalKHR = DepthAttachmentOptimal,
        DepthReadOnlyOptimalKHR = DepthReadOnlyOptimal,
        StencilAttachmentOptimalKHR = StencilAttachmentOptimal,
        StencilReadOnlyOptimalKHR = StencilReadOnlyOptimal,
        ReadOnlyOptimalKHR = ReadOnlyOptimal,
        AttachmentOptimalKHR = AttachmentOptimal
    };
    
    std::string_view    to_string_view(VqImageLayout);

    enum class VqImageTiling : uint32_t {
        Optimal = 0,
        Linear = 1,
        DrmFormatModifierEXT = 1000158000
    };
    
    std::string_view    to_string_view(VqImageTiling);

    enum class VqImageType : uint32_t {
        1d = 0,
        2d = 1,
        3d = 2
    };
    
    std::string_view    to_string_view(VqImageType);

    enum class VqImageUsageFlagBits : uint32_t {
        TransferSrcBit = 0x00000001,
        TransferDstBit = 0x00000002,
        SampledBit = 0x00000004,
        StorageBit = 0x00000008,
        ColorAttachmentBit = 0x00000010,
        DepthStencilAttachmentBit = 0x00000020,
        TransientAttachmentBit = 0x00000040,
        InputAttachmentBit = 0x00000080,
        VideoDecodeDstBitKHR = 0x00000400,
        VideoDecodeSrcBitKHR = 0x00000800,
        VideoDecodeDpbBitKHR = 0x00001000,
        FragmentDensityMapBitEXT = 0x00000200,
        FragmentShadingRateAttachmentBitKHR = 0x00000100,
        HostTransferBitEXT = 0x00400000,
        VideoEncodeDstBitKHR = 0x00002000,
        VideoEncodeSrcBitKHR = 0x00004000,
        VideoEncodeDpbBitKHR = 0x00008000,
        AttachmentFeedbackLoopBitEXT = 0x00080000,
        InvocationMaskBitHuawei = 0x00040000,
        SampleWeightBitQCOM = 0x00100000,
        SampleBlockMatchBitQCOM = 0x00200000,
        ShadingRateImageBitNV = FragmentShadingRateAttachmentBitKHR
    };
    
    std::string_view    to_string_view(VqImageUsageFlagBits);

    enum class VqImageViewCreateFlagBits : uint32_t {
        FragmentDensityMapDynamicBitEXT = 0x00000001,
        DescriptorBufferCaptureReplayBitEXT = 0x00000004,
        FragmentDensityMapDeferredBitEXT = 0x00000002
    };
    
    std::string_view    to_string_view(VqImageViewCreateFlagBits);

    enum class VqImageViewType : uint32_t {
        1d = 0,
        2d = 1,
        3d = 2,
        Cube = 3,
        1dArray = 4,
        2dArray = 5,
        CubeArray = 6
    };
    
    std::string_view    to_string_view(VqImageViewType);

    enum class VqIndexType : uint32_t {
        Uint16 = 0,
        Uint32 = 1,
        NoneKHR = 1000165000,
        Uint8KHR = 1000265000,
        NoneNV = NoneKHR,
        Uint8EXT = Uint8KHR
    };
    
    std::string_view    to_string_view(VqIndexType);

    enum class VqIndirectCommandsLayoutUsageFlagBits : uint32_t {
        ExplicitPreprocessBitNV = 0x00000001,
        IndexedSequencesBitNV = 0x00000002,
        UnorderedSequencesBitNV = 0x00000004
    };
    
    std::string_view    to_string_view(VqIndirectCommandsLayoutUsageFlagBits);

    enum class VqIndirectCommandsTokenType : uint32_t {
        ShaderGroupNV = 0,
        StateFlagsNV = 1,
        IndexBufferNV = 2,
        VertexBufferNV = 3,
        PushConstantNV = 4,
        DrawIndexedNV = 5,
        DrawNV = 6,
        DrawTasksNV = 7,
        DrawMeshTasksNV = 1000328000,
        PipelineNV = 1000428003,
        DispatchNV = 1000428004
    };
    
    std::string_view    to_string_view(VqIndirectCommandsTokenType);

    enum class VqIndirectStateFlagBits : uint32_t {
        FlagFrontfaceBitNV = 0x00000001
    };
    
    std::string_view    to_string_view(VqIndirectStateFlagBits);

    enum class VqInstanceCreateFlagBits : uint32_t {
        EnumeratePortabilityBitKHR = 0x00000001
    };
    
    std::string_view    to_string_view(VqInstanceCreateFlagBits);

    enum class VqInternalAllocationType : uint32_t {
        Executable = 0
    };
    
    std::string_view    to_string_view(VqInternalAllocationType);

    enum class VqLatencyMarker : uint32_t {
        SimulationStartNV = 0,
        SimulationEndNV = 1,
        RendersubmitStartNV = 2,
        RendersubmitEndNV = 3,
        PresentStartNV = 4,
        PresentEndNV = 5,
        InputSampleNV = 6,
        TriggerFlashNV = 7,
        OutOfBandRendersubmitStartNV = 8,
        OutOfBandRendersubmitEndNV = 9,
        OutOfBandPresentStartNV = 10,
        OutOfBandPresentEndNV = 11
    };
    
    std::string_view    to_string_view(VqLatencyMarker);

    enum class VqLayerSettingType : uint32_t {
        Bool32EXT = 0,
        Int32EXT = 1,
        Int64EXT = 2,
        Uint32EXT = 3,
        Uint64EXT = 4,
        Float32EXT = 5,
        Float64EXT = 6,
        StringEXT = 7
    };
    
    std::string_view    to_string_view(VqLayerSettingType);

    enum class VqLayeredDriverUnderlyingApi : uint32_t {
        NoneMSFT = 0,
        D3d12MSFT = 1
    };
    
    std::string_view    to_string_view(VqLayeredDriverUnderlyingApi);

    enum class VqLineRasterizationMode : uint32_t {
        DefaultKHR = 0,
        RectangularKHR = 1,
        BresenhamKHR = 2,
        RectangularSmoothKHR = 3,
        DefaultEXT = DefaultKHR,
        RectangularEXT = RectangularKHR,
        BresenhamEXT = BresenhamKHR,
        RectangularSmoothEXT = RectangularSmoothKHR
    };
    
    std::string_view    to_string_view(VqLineRasterizationMode);

    enum class VqLogicOp : uint32_t {
        Clear = 0,
        And = 1,
        AndReverse = 2,
        Copy = 3,
        AndInverted = 4,
        NoOp = 5,
        Xor = 6,
        Or = 7,
        Nor = 8,
        Equivalent = 9,
        Invert = 10,
        OrReverse = 11,
        CopyInverted = 12,
        OrInverted = 13,
        Nand = 14,
        Set = 15
    };
    
    std::string_view    to_string_view(VqLogicOp);

    enum class VqMemoryAllocateFlagBits : uint32_t {
        DeviceMaskBit = 0x00000001,
        DeviceAddressBit = 0x00000002,
        DeviceAddressCaptureReplayBit = 0x00000004,
        DeviceMaskBitKHR = DeviceMaskBit,
        DeviceAddressBitKHR = DeviceAddressBit,
        DeviceAddressCaptureReplayBitKHR = DeviceAddressCaptureReplayBit
    };
    
    std::string_view    to_string_view(VqMemoryAllocateFlagBits);

    enum class VqMemoryHeapFlagBits : uint32_t {
        DeviceLocalBit = 0x00000001,
        MultiInstanceBit = 0x00000002,
        MultiInstanceBitKHR = MultiInstanceBit
    };
    
    std::string_view    to_string_view(VqMemoryHeapFlagBits);

    enum class VqMemoryMapFlagBits : uint32_t {
        PlacedBitEXT = 0x00000001
    };
    
    std::string_view    to_string_view(VqMemoryMapFlagBits);

    enum class VqMemoryOverallocationBehavior : uint32_t {
        DefaultAMD = 0,
        AllowedAMD = 1,
        DisallowedAMD = 2
    };
    
    std::string_view    to_string_view(VqMemoryOverallocationBehavior);

    enum class VqMemoryPropertyFlagBits : uint32_t {
        DeviceLocalBit = 0x00000001,
        HostVisibleBit = 0x00000002,
        HostCoherentBit = 0x00000004,
        HostCachedBit = 0x00000008,
        LazilyAllocatedBit = 0x00000010,
        ProtectedBit = 0x00000020,
        DeviceCoherentBitAMD = 0x00000040,
        DeviceUncachedBitAMD = 0x00000080,
        RdmaCapableBitNV = 0x00000100
    };
    
    std::string_view    to_string_view(VqMemoryPropertyFlagBits);

    enum class VqMemoryUnmapFlagBits : uint32_t {
        ReserveBitEXT = 0x00000001
    };
    
    std::string_view    to_string_view(VqMemoryUnmapFlagBits);

    enum class VqMicromapCreateFlagBits : uint32_t {
        DeviceAddressCaptureReplayBitEXT = 0x00000001
    };
    
    std::string_view    to_string_view(VqMicromapCreateFlagBits);

    enum class VqMicromapType : uint32_t {
        OpacityMicromapEXT = 0,
        DisplacementMicromapNV = 1000397000
    };
    
    std::string_view    to_string_view(VqMicromapType);

    enum class VqObjectType : uint32_t {
        Unknown = 0,
        Instance = 1,
        PhysicalDevice = 2,
        Device = 3,
        Queue = 4,
        Semaphore = 5,
        CommandBuffer = 6,
        Fence = 7,
        DeviceMemory = 8,
        Buffer = 9,
        Image = 10,
        Event = 11,
        QueryPool = 12,
        BufferView = 13,
        ImageView = 14,
        ShaderModule = 15,
        PipelineCache = 16,
        PipelineLayout = 17,
        RenderPass = 18,
        Pipeline = 19,
        DescriptorSetLayout = 20,
        Sampler = 21,
        DescriptorPool = 22,
        DescriptorSet = 23,
        Framebuffer = 24,
        CommandPool = 25,
        SamplerYcbcrConversion = 1000156000,
        DescriptorUpdateTemplate = 1000085000,
        PrivateDataSlot = 1000295000,
        SurfaceKHR = 1000000000,
        SwapchainKHR = 1000001000,
        DisplayKHR = 1000002000,
        DisplayModeKHR = 1000002001,
        DebugReportCallbackEXT = 1000011000,
        VideoSessionKHR = 1000023000,
        VideoSessionParametersKHR = 1000023001,
        CuModuleNvx = 1000029000,
        CuFunctionNvx = 1000029001,
        DebugUtilsMessengerEXT = 1000128000,
        AccelerationStructureKHR = 1000150000,
        ValidationCacheEXT = 1000160000,
        AccelerationStructureNV = 1000165000,
        PerformanceConfigurationINTEL = 1000210000,
        DeferredOperationKHR = 1000268000,
        IndirectCommandsLayoutNV = 1000277000,
        CudaModuleNV = 1000307000,
        CudaFunctionNV = 1000307001,
        BufferCollectionFuchsia = 1000366000,
        MicromapEXT = 1000396000,
        OpticalFlowSessionNV = 1000464000,
        ShaderEXT = 1000482000,
        DescriptorUpdateTemplateKHR = DescriptorUpdateTemplate,
        SamplerYcbcrConversionKHR = SamplerYcbcrConversion,
        PrivateDataSlotEXT = PrivateDataSlot
    };
    
    std::string_view    to_string_view(VqObjectType);

    enum class VqOpacityMicromapFormat : uint32_t {
        2StateEXT = 1,
        4StateEXT = 2
    };
    
    std::string_view    to_string_view(VqOpacityMicromapFormat);

    enum class VqOpacityMicromapSpecialIndex : uint32_t {
        FullyTransparentEXT = -1,
        FullyOpaqueEXT = -2,
        FullyUnknownTransparentEXT = -3,
        FullyUnknownOpaqueEXT = -4
    };
    
    std::string_view    to_string_view(VqOpacityMicromapSpecialIndex);

    enum class VqOpticalFlowExecuteFlagBits : uint32_t {
        DisableTemporalHintsBitNV = 0x00000001
    };
    
    std::string_view    to_string_view(VqOpticalFlowExecuteFlagBits);

    enum class VqOpticalFlowGridSizeFlagBits : uint32_t {
        UnknownNV = 0,
        1x1BitNV = 0x00000001,
        2x2BitNV = 0x00000002,
        4x4BitNV = 0x00000004,
        8x8BitNV = 0x00000008
    };
    
    std::string_view    to_string_view(VqOpticalFlowGridSizeFlagBits);

    enum class VqOpticalFlowPerformanceLevel : uint32_t {
        UnknownNV = 0,
        SlowNV = 1,
        MediumNV = 2,
        FastNV = 3
    };
    
    std::string_view    to_string_view(VqOpticalFlowPerformanceLevel);

    enum class VqOpticalFlowSessionBindingPoint : uint32_t {
        UnknownNV = 0,
        InputNV = 1,
        ReferenceNV = 2,
        HintNV = 3,
        FlowVectorNV = 4,
        BackwardFlowVectorNV = 5,
        CostNV = 6,
        BackwardCostNV = 7,
        GlobalFlowNV = 8
    };
    
    std::string_view    to_string_view(VqOpticalFlowSessionBindingPoint);

    enum class VqOpticalFlowSessionCreateFlagBits : uint32_t {
        EnableHintBitNV = 0x00000001,
        EnableCostBitNV = 0x00000002,
        EnableGlobalFlowBitNV = 0x00000004,
        AllowRegionsBitNV = 0x00000008,
        BothDirectionsBitNV = 0x00000010
    };
    
    std::string_view    to_string_view(VqOpticalFlowSessionCreateFlagBits);

    enum class VqOpticalFlowUsageFlagBits : uint32_t {
        UnknownNV = 0,
        InputBitNV = 0x00000001,
        OutputBitNV = 0x00000002,
        HintBitNV = 0x00000004,
        CostBitNV = 0x00000008,
        GlobalFlowBitNV = 0x00000010
    };
    
    std::string_view    to_string_view(VqOpticalFlowUsageFlagBits);

    enum class VqOutOfBandQueueType : uint32_t {
        RenderNV = 0,
        PresentNV = 1
    };
    
    std::string_view    to_string_view(VqOutOfBandQueueType);

    enum class VqPeerMemoryFeatureFlagBits : uint32_t {
        CopySrcBit = 0x00000001,
        CopyDstBit = 0x00000002,
        GenericSrcBit = 0x00000004,
        GenericDstBit = 0x00000008,
        CopySrcBitKHR = CopySrcBit,
        CopyDstBitKHR = CopyDstBit,
        GenericSrcBitKHR = GenericSrcBit,
        GenericDstBitKHR = GenericDstBit
    };
    
    std::string_view    to_string_view(VqPeerMemoryFeatureFlagBits);

    enum class VqPerformanceConfigurationType : uint32_t {
        CommandQueueMetricsDiscoveryActivatedINTEL = 0
    };
    
    std::string_view    to_string_view(VqPerformanceConfigurationType);

    enum class VqPerformanceCounterDescriptionFlagBits : uint32_t {
        PerformanceImpactingBitKHR = 0x00000001,
        ConcurrentlyImpactedBitKHR = 0x00000002,
        PerformanceImpactingKHR = PerformanceImpactingBitKHR,
        ConcurrentlyImpactedKHR = ConcurrentlyImpactedBitKHR
    };
    
    std::string_view    to_string_view(VqPerformanceCounterDescriptionFlagBits);

    enum class VqPerformanceCounterScope : uint32_t {
        CommandBufferKHR = 0,
        RenderPassKHR = 1,
        CommandKHR = 2,
        VkQueryScopeCommandBufferKHR = CommandBufferKHR,
        VkQueryScopeRenderPassKHR = RenderPassKHR,
        VkQueryScopeCommandKHR = CommandKHR
    };
    
    std::string_view    to_string_view(VqPerformanceCounterScope);

    enum class VqPerformanceCounterStorage : uint32_t {
        Int32KHR = 0,
        Int64KHR = 1,
        Uint32KHR = 2,
        Uint64KHR = 3,
        Float32KHR = 4,
        Float64KHR = 5
    };
    
    std::string_view    to_string_view(VqPerformanceCounterStorage);

    enum class VqPerformanceCounterUnit : uint32_t {
        GenericKHR = 0,
        PercentageKHR = 1,
        NanosecondsKHR = 2,
        BytesKHR = 3,
        BytesPerSecondKHR = 4,
        KelvinKHR = 5,
        WattsKHR = 6,
        VoltsKHR = 7,
        AmpsKHR = 8,
        HertzKHR = 9,
        CyclesKHR = 10
    };
    
    std::string_view    to_string_view(VqPerformanceCounterUnit);

    enum class VqPerformanceOverrideType : uint32_t {
        NullHardwareINTEL = 0,
        FlushGpuCachesINTEL = 1
    };
    
    std::string_view    to_string_view(VqPerformanceOverrideType);

    enum class VqPerformanceParameterType : uint32_t {
        HwCountersSupportedINTEL = 0,
        StreamMarkerValidBitsINTEL = 1
    };
    
    std::string_view    to_string_view(VqPerformanceParameterType);

    enum class VqPerformanceValueType : uint32_t {
        Uint32INTEL = 0,
        Uint64INTEL = 1,
        FloatINTEL = 2,
        BoolINTEL = 3,
        StringINTEL = 4
    };
    
    std::string_view    to_string_view(VqPerformanceValueType);

    enum class VqPhysicalDeviceLayeredApi : uint32_t {
        VulkanKHR = 0,
        D3d12KHR = 1,
        MetalKHR = 2,
        OpenglKHR = 3,
        OpenglesKHR = 4
    };
    
    std::string_view    to_string_view(VqPhysicalDeviceLayeredApi);

    enum class VqPhysicalDeviceType : uint32_t {
        Other = 0,
        IntegratedGpu = 1,
        DiscreteGpu = 2,
        VirtualGpu = 3,
        Cpu = 4
    };
    
    std::string_view    to_string_view(VqPhysicalDeviceType);

    enum class VqPipelineBindPoint : uint32_t {
        Graphics = 0,
        Compute = 1,
        ExecutionGraphAmdx = 1000134000,
        RayTracingKHR = 1000165000,
        SubpassShadingHuawei = 1000369003,
        RayTracingNV = RayTracingKHR
    };
    
    std::string_view    to_string_view(VqPipelineBindPoint);

    enum class VqPipelineCacheCreateFlagBits : uint32_t {
        ExternallySynchronizedBit = 0x00000001,
        ExternallySynchronizedBitEXT = ExternallySynchronizedBit
    };
    
    std::string_view    to_string_view(VqPipelineCacheCreateFlagBits);

    enum class VqPipelineCacheHeaderVersion : uint32_t {
        One = 1
    };
    
    std::string_view    to_string_view(VqPipelineCacheHeaderVersion);

    enum class VqPipelineColorBlendStateCreateFlagBits : uint32_t {
        RasterizationOrderAttachmentAccessBitEXT = 0x00000001,
        RasterizationOrderAttachmentAccessBitArm = RasterizationOrderAttachmentAccessBitEXT
    };
    
    std::string_view    to_string_view(VqPipelineColorBlendStateCreateFlagBits);

    enum class VqPipelineCompilerControlFlagBits : uint32_t {

    };
    
    std::string_view    to_string_view(VqPipelineCompilerControlFlagBits);

    enum class VqPipelineCreateFlagBits : uint32_t {
        DisableOptimizationBit = 0x00000001,
        AllowDerivativesBit = 0x00000002,
        DerivativeBit = 0x00000004,
        ViewIndexFromDeviceIndexBit = 0x00000008,
        DispatchBaseBit = 0x00000010,
        FailOnPipelineCompileRequiredBit = 0x00000100,
        EarlyReturnOnFailureBit = 0x00000200,
        RenderingFragmentShadingRateAttachmentBitKHR = 0x00200000,
        RenderingFragmentDensityMapAttachmentBitEXT = 0x00400000,
        RayTracingNoNullAnyHitShadersBitKHR = 0x00004000,
        RayTracingNoNullClosestHitShadersBitKHR = 0x00008000,
        RayTracingNoNullMissShadersBitKHR = 0x00010000,
        RayTracingNoNullIntersectionShadersBitKHR = 0x00020000,
        RayTracingSkipTrianglesBitKHR = 0x00001000,
        RayTracingSkipAabbsBitKHR = 0x00002000,
        RayTracingShaderGroupHandleCaptureReplayBitKHR = 0x00080000,
        DeferCompileBitNV = 0x00000020,
        CaptureStatisticsBitKHR = 0x00000040,
        CaptureInternalRepresentationsBitKHR = 0x00000080,
        IndirectBindableBitNV = 0x00040000,
        LibraryBitKHR = 0x00000800,
        DescriptorBufferBitEXT = 0x20000000,
        RetainLinkTimeOptimizationInfoBitEXT = 0x00800000,
        LinkTimeOptimizationBitEXT = 0x00000400,
        RayTracingAllowMotionBitNV = 0x00100000,
        ColorAttachmentFeedbackLoopBitEXT = 0x02000000,
        DepthStencilAttachmentFeedbackLoopBitEXT = 0x04000000,
        RayTracingOpacityMicromapBitEXT = 0x01000000,
        RayTracingDisplacementMicromapBitNV = 0x10000000,
        NoProtectedAccessBitEXT = 0x08000000,
        ProtectedAccessOnlyBitEXT = 0x40000000,
        DispatchBase = DispatchBaseBit,
        VkPipelineRasterizationStateCreateFragmentShadingRateAttachmentBitKHR = RenderingFragmentShadingRateAttachmentBitKHR,
        VkPipelineRasterizationStateCreateFragmentDensityMapAttachmentBitEXT = RenderingFragmentDensityMapAttachmentBitEXT,
        ViewIndexFromDeviceIndexBitKHR = ViewIndexFromDeviceIndexBit,
        DispatchBaseKHR = DispatchBase,
        FailOnPipelineCompileRequiredBitEXT = FailOnPipelineCompileRequiredBit,
        EarlyReturnOnFailureBitEXT = EarlyReturnOnFailureBit
    };
    
    std::string_view    to_string_view(VqPipelineCreateFlagBits);

    enum class VqPipelineCreationFeedbackFlagBits : uint32_t {
        ValidBit = 0x00000001,
        ApplicationPipelineCacheHitBit = 0x00000002,
        BasePipelineAccelerationBit = 0x00000004,
        ValidBitEXT = ValidBit,
        ApplicationPipelineCacheHitBitEXT = ApplicationPipelineCacheHitBit,
        BasePipelineAccelerationBitEXT = BasePipelineAccelerationBit
    };
    
    std::string_view    to_string_view(VqPipelineCreationFeedbackFlagBits);

    enum class VqPipelineDepthStencilStateCreateFlagBits : uint32_t {
        RasterizationOrderAttachmentDepthAccessBitEXT = 0x00000001,
        RasterizationOrderAttachmentStencilAccessBitEXT = 0x00000002,
        RasterizationOrderAttachmentDepthAccessBitArm = RasterizationOrderAttachmentDepthAccessBitEXT,
        RasterizationOrderAttachmentStencilAccessBitArm = RasterizationOrderAttachmentStencilAccessBitEXT
    };
    
    std::string_view    to_string_view(VqPipelineDepthStencilStateCreateFlagBits);

    enum class VqPipelineExecutableStatisticFormat : uint32_t {
        Bool32KHR = 0,
        Int64KHR = 1,
        Uint64KHR = 2,
        Float64KHR = 3
    };
    
    std::string_view    to_string_view(VqPipelineExecutableStatisticFormat);

    enum class VqPipelineLayoutCreateFlagBits : uint32_t {
        IndependentSetsBitEXT = 0x00000002
    };
    
    std::string_view    to_string_view(VqPipelineLayoutCreateFlagBits);

    enum class VqPipelineRobustnessBufferBehavior : uint32_t {
        DeviceDefaultEXT = 0,
        DisabledEXT = 1,
        RobustBufferAccessEXT = 2,
        RobustBufferAccess2EXT = 3
    };
    
    std::string_view    to_string_view(VqPipelineRobustnessBufferBehavior);

    enum class VqPipelineRobustnessImageBehavior : uint32_t {
        DeviceDefaultEXT = 0,
        DisabledEXT = 1,
        RobustImageAccessEXT = 2,
        RobustImageAccess2EXT = 3
    };
    
    std::string_view    to_string_view(VqPipelineRobustnessImageBehavior);

    enum class VqPipelineShaderStageCreateFlagBits : uint32_t {
        AllowVaryingSubgroupSizeBit = 0x00000001,
        RequireFullSubgroupsBit = 0x00000002,
        AllowVaryingSubgroupSizeBitEXT = AllowVaryingSubgroupSizeBit,
        RequireFullSubgroupsBitEXT = RequireFullSubgroupsBit
    };
    
    std::string_view    to_string_view(VqPipelineShaderStageCreateFlagBits);

    enum class VqPipelineStageFlagBits : uint32_t {
        TopOfPipeBit = 0x00000001,
        DrawIndirectBit = 0x00000002,
        VertexInputBit = 0x00000004,
        VertexShaderBit = 0x00000008,
        TessellationControlShaderBit = 0x00000010,
        TessellationEvaluationShaderBit = 0x00000020,
        GeometryShaderBit = 0x00000040,
        FragmentShaderBit = 0x00000080,
        EarlyFragmentTestsBit = 0x00000100,
        LateFragmentTestsBit = 0x00000200,
        ColorAttachmentOutputBit = 0x00000400,
        ComputeShaderBit = 0x00000800,
        TransferBit = 0x00001000,
        BottomOfPipeBit = 0x00002000,
        HostBit = 0x00004000,
        AllGraphicsBit = 0x00008000,
        AllCommandsBit = 0x00010000,
        None = 0,
        TransformFeedbackBitEXT = 0x01000000,
        ConditionalRenderingBitEXT = 0x00040000,
        AccelerationStructureBuildBitKHR = 0x02000000,
        RayTracingShaderBitKHR = 0x00200000,
        FragmentDensityProcessBitEXT = 0x00800000,
        FragmentShadingRateAttachmentBitKHR = 0x00400000,
        CommandPreprocessBitNV = 0x00020000,
        TaskShaderBitEXT = 0x00080000,
        MeshShaderBitEXT = 0x00100000,
        ShadingRateImageBitNV = FragmentShadingRateAttachmentBitKHR,
        RayTracingShaderBitNV = RayTracingShaderBitKHR,
        AccelerationStructureBuildBitNV = AccelerationStructureBuildBitKHR,
        TaskShaderBitNV = TaskShaderBitEXT,
        MeshShaderBitNV = MeshShaderBitEXT,
        NoneKHR = None
    };
    
    std::string_view    to_string_view(VqPipelineStageFlagBits);

    enum class VqPointClippingBehavior : uint32_t {
        AllClipPlanes = 0,
        UserClipPlanesOnly = 1,
        AllClipPlanesKHR = AllClipPlanes,
        UserClipPlanesOnlyKHR = UserClipPlanesOnly
    };
    
    std::string_view    to_string_view(VqPointClippingBehavior);

    enum class VqPolygonMode : uint32_t {
        Fill = 0,
        Line = 1,
        Point = 2,
        FillRectangleNV = 1000153000
    };
    
    std::string_view    to_string_view(VqPolygonMode);

    enum class VqPresentGravityFlagBits : uint32_t {
        MinBitEXT = 0x00000001,
        MaxBitEXT = 0x00000002,
        CenteredBitEXT = 0x00000004
    };
    
    std::string_view    to_string_view(VqPresentGravityFlagBits);

    enum class VqPresentMode : uint32_t {
        ImmediateKHR = 0,
        MailboxKHR = 1,
        FifoKHR = 2,
        FifoRelaxedKHR = 3,
        SharedDemandRefreshKHR = 1000111000,
        SharedContinuousRefreshKHR = 1000111001
    };
    
    std::string_view    to_string_view(VqPresentMode);

    enum class VqPresentScalingFlagBits : uint32_t {
        OneToOneBitEXT = 0x00000001,
        AspectRatioStretchBitEXT = 0x00000002,
        StretchBitEXT = 0x00000004
    };
    
    std::string_view    to_string_view(VqPresentScalingFlagBits);

    enum class VqPrimitiveTopology : uint32_t {
        PointList = 0,
        LineList = 1,
        LineStrip = 2,
        TriangleList = 3,
        TriangleStrip = 4,
        TriangleFan = 5,
        LineListWithAdjacency = 6,
        LineStripWithAdjacency = 7,
        TriangleListWithAdjacency = 8,
        TriangleStripWithAdjacency = 9,
        PatchList = 10
    };
    
    std::string_view    to_string_view(VqPrimitiveTopology);

    enum class VqProvokingVertexMode : uint32_t {
        FirstVertexEXT = 0,
        LastVertexEXT = 1
    };
    
    std::string_view    to_string_view(VqProvokingVertexMode);

    enum class VqQueryControlFlagBits : uint32_t {
        PreciseBit = 0x00000001
    };
    
    std::string_view    to_string_view(VqQueryControlFlagBits);

    enum class VqQueryPipelineStatisticFlagBits : uint32_t {
        InputAssemblyVerticesBit = 0x00000001,
        InputAssemblyPrimitivesBit = 0x00000002,
        VertexShaderInvocationsBit = 0x00000004,
        GeometryShaderInvocationsBit = 0x00000008,
        GeometryShaderPrimitivesBit = 0x00000010,
        ClippingInvocationsBit = 0x00000020,
        ClippingPrimitivesBit = 0x00000040,
        FragmentShaderInvocationsBit = 0x00000080,
        TessellationControlShaderPatchesBit = 0x00000100,
        TessellationEvaluationShaderInvocationsBit = 0x00000200,
        ComputeShaderInvocationsBit = 0x00000400,
        TaskShaderInvocationsBitEXT = 0x00000800,
        MeshShaderInvocationsBitEXT = 0x00001000,
        ClusterCullingShaderInvocationsBitHuawei = 0x00002000
    };
    
    std::string_view    to_string_view(VqQueryPipelineStatisticFlagBits);

    enum class VqQueryPoolSamplingMode : uint32_t {
        ManualINTEL = 0
    };
    
    std::string_view    to_string_view(VqQueryPoolSamplingMode);

    enum class VqQueryResultFlagBits : uint32_t {
        64Bit = 0x00000001,
        WaitBit = 0x00000002,
        WithAvailabilityBit = 0x00000004,
        PartialBit = 0x00000008,
        WithStatusBitKHR = 0x00000010
    };
    
    std::string_view    to_string_view(VqQueryResultFlagBits);

    enum class VqQueryResultStatus : uint32_t {
        ErrorKHR = -1,
        NotReadyKHR = 0,
        CompleteKHR = 1,
        InsufficientBitstreamBufferRangeKHR = -1000299000
    };
    
    std::string_view    to_string_view(VqQueryResultStatus);

    enum class VqQueryType : uint32_t {
        Occlusion = 0,
        PipelineStatistics = 1,
        Timestamp = 2,
        ResultStatusOnlyKHR = 1000023000,
        TransformFeedbackStreamEXT = 1000028004,
        PerformanceQueryKHR = 1000116000,
        AccelerationStructureCompactedSizeKHR = 1000150000,
        AccelerationStructureSerializationSizeKHR = 1000150001,
        AccelerationStructureCompactedSizeNV = 1000165000,
        PerformanceQueryINTEL = 1000210000,
        VideoEncodeFeedbackKHR = 1000299000,
        MeshPrimitivesGeneratedEXT = 1000328000,
        PrimitivesGeneratedEXT = 1000382000,
        AccelerationStructureSerializationBottomLevelPointersKHR = 1000386000,
        AccelerationStructureSizeKHR = 1000386001,
        MicromapSerializationSizeEXT = 1000396000,
        MicromapCompactedSizeEXT = 1000396001
    };
    
    std::string_view    to_string_view(VqQueryType);

    enum class VqQueueFlagBits : uint32_t {
        GraphicsBit = 0x00000001,
        ComputeBit = 0x00000002,
        TransferBit = 0x00000004,
        SparseBindingBit = 0x00000008,
        ProtectedBit = 0x00000010,
        VideoDecodeBitKHR = 0x00000020,
        VideoEncodeBitKHR = 0x00000040,
        OpticalFlowBitNV = 0x00000100
    };
    
    std::string_view    to_string_view(VqQueueFlagBits);

    enum class VqQueueGlobalPriority : uint32_t {
        LowKHR = 128,
        MediumKHR = 256,
        HighKHR = 512,
        RealtimeKHR = 1024,
        LowEXT = LowKHR,
        MediumEXT = MediumKHR,
        HighEXT = HighKHR,
        RealtimeEXT = RealtimeKHR
    };
    
    std::string_view    to_string_view(VqQueueGlobalPriority);

    enum class VqRasterizationOrder : uint32_t {
        StrictAMD = 0,
        RelaxedAMD = 1
    };
    
    std::string_view    to_string_view(VqRasterizationOrder);

    enum class VqRayTracingInvocationReorderMode : uint32_t {
        NoneNV = 0,
        ReorderNV = 1
    };
    
    std::string_view    to_string_view(VqRayTracingInvocationReorderMode);

    enum class VqRayTracingShaderGroupType : uint32_t {
        GeneralKHR = 0,
        TrianglesHitGroupKHR = 1,
        ProceduralHitGroupKHR = 2,
        GeneralNV = GeneralKHR,
        TrianglesHitGroupNV = TrianglesHitGroupKHR,
        ProceduralHitGroupNV = ProceduralHitGroupKHR
    };
    
    std::string_view    to_string_view(VqRayTracingShaderGroupType);

    enum class VqRenderPassCreateFlagBits : uint32_t {
        TransformBitQCOM = 0x00000002
    };
    
    std::string_view    to_string_view(VqRenderPassCreateFlagBits);

    enum class VqRenderingFlagBits : uint32_t {
        ContentsSecondaryCommandBuffersBit = 0x00000001,
        SuspendingBit = 0x00000002,
        ResumingBit = 0x00000004,
        EnableLegacyDitheringBitEXT = 0x00000008,
        ContentsInlineBitKHR = 0x00000010,
        ContentsSecondaryCommandBuffersBitKHR = ContentsSecondaryCommandBuffersBit,
        SuspendingBitKHR = SuspendingBit,
        ResumingBitKHR = ResumingBit,
        ContentsInlineBitEXT = ContentsInlineBitKHR
    };
    
    std::string_view    to_string_view(VqRenderingFlagBits);

    enum class VqResolveModeFlagBits : uint32_t {
        None = 0,
        SampleZeroBit = 0x00000001,
        AverageBit = 0x00000002,
        MinBit = 0x00000004,
        MaxBit = 0x00000008,
        ExternalFormatDownsampleAndroid = 0x00000010,
        NoneKHR = None,
        SampleZeroBitKHR = SampleZeroBit,
        AverageBitKHR = AverageBit,
        MinBitKHR = MinBit,
        MaxBitKHR = MaxBit
    };
    
    std::string_view    to_string_view(VqResolveModeFlagBits);

    enum class VqResult : uint32_t {
        VkSuccess = 0,
        VkNotReady = 1,
        VkTimeout = 2,
        VkEventSet = 3,
        VkEventReset = 4,
        VkIncomplete = 5,
        VkErrorOutOfHostMemory = -1,
        VkErrorOutOfDeviceMemory = -2,
        VkErrorInitializationFailed = -3,
        VkErrorDeviceLost = -4,
        VkErrorMemoryMapFailed = -5,
        VkErrorLayerNotPresent = -6,
        VkErrorExtensionNotPresent = -7,
        VkErrorFeatureNotPresent = -8,
        VkErrorIncompatibleDriver = -9,
        VkErrorTooManyObjects = -10,
        VkErrorFormatNotSupported = -11,
        VkErrorFragmentedPool = -12,
        VkErrorUnknown = -13,
        VkErrorOutOfPoolMemory = -1000069000,
        VkErrorInvalidExternalHandle = -1000072003,
        VkErrorFragmentation = -1000161000,
        VkErrorInvalidOpaqueCaptureAddress = -1000257000,
        VkPipelineCompileRequired = 1000297000,
        VkErrorSurfaceLostKHR = -1000000000,
        VkErrorNativeWindowInUseKHR = -1000000001,
        VkSuboptimalKHR = 1000001003,
        VkErrorOutOfDateKHR = -1000001004,
        VkErrorIncompatibleDisplayKHR = -1000003001,
        VkErrorValidationFailedEXT = -1000011001,
        VkErrorInvalidShaderNV = -1000012000,
        VkErrorImageUsageNotSupportedKHR = -1000023000,
        VkErrorVideoPictureLayoutNotSupportedKHR = -1000023001,
        VkErrorVideoProfileOperationNotSupportedKHR = -1000023002,
        VkErrorVideoProfileFormatNotSupportedKHR = -1000023003,
        VkErrorVideoProfileCodecNotSupportedKHR = -1000023004,
        VkErrorVideoStdVersionNotSupportedKHR = -1000023005,
        VkErrorInvalidDrmFormatModifierPlaneLayoutEXT = -1000158000,
        VkErrorNotPermittedKHR = -1000174001,
        VkErrorFullScreenExclusiveModeLostEXT = -1000255000,
        VkThreadIdleKHR = 1000268000,
        VkThreadDoneKHR = 1000268001,
        VkOperationDeferredKHR = 1000268002,
        VkOperationNotDeferredKHR = 1000268003,
        VkErrorInvalidVideoStdParametersKHR = -1000299000,
        VkErrorCompressionExhaustedEXT = -1000338000,
        VkIncompatibleShaderBinaryEXT = 1000482000,
        VkErrorOutOfPoolMemoryKHR = VkErrorOutOfPoolMemory,
        VkErrorInvalidExternalHandleKHR = VkErrorInvalidExternalHandle,
        VkErrorFragmentationEXT = VkErrorFragmentation,
        VkErrorNotPermittedEXT = VkErrorNotPermittedKHR,
        VkErrorInvalidDeviceAddressEXT = VkErrorInvalidOpaqueCaptureAddress,
        VkErrorInvalidOpaqueCaptureAddressKHR = VkErrorInvalidOpaqueCaptureAddress,
        VkPipelineCompileRequiredEXT = VkPipelineCompileRequired,
        VkErrorPipelineCompileRequiredEXT = VkPipelineCompileRequired,
        VkErrorIncompatibleShaderBinaryEXT = VkIncompatibleShaderBinaryEXT
    };
    
    std::string_view    to_string_view(VqResult);

    enum class VqSampleCountFlagBits : uint32_t {
        1Bit = 0x00000001,
        2Bit = 0x00000002,
        4Bit = 0x00000004,
        8Bit = 0x00000008,
        16Bit = 0x00000010,
        32Bit = 0x00000020,
        64Bit = 0x00000040
    };
    
    std::string_view    to_string_view(VqSampleCountFlagBits);

    enum class VqSamplerAddressMode : uint32_t {
        Repeat = 0,
        MirroredRepeat = 1,
        ClampToEdge = 2,
        ClampToBorder = 3,
        MirrorClampToEdge = 4,
        MirrorClampToEdgeKHR = MirrorClampToEdge
    };
    
    std::string_view    to_string_view(VqSamplerAddressMode);

    enum class VqSamplerCreateFlagBits : uint32_t {
        SubsampledBitEXT = 0x00000001,
        SubsampledCoarseReconstructionBitEXT = 0x00000002,
        DescriptorBufferCaptureReplayBitEXT = 0x00000008,
        NonSeamlessCubeMapBitEXT = 0x00000004,
        ImageProcessingBitQCOM = 0x00000010
    };
    
    std::string_view    to_string_view(VqSamplerCreateFlagBits);

    enum class VqSamplerMipmapMode : uint32_t {
        Nearest = 0,
        Linear = 1
    };
    
    std::string_view    to_string_view(VqSamplerMipmapMode);

    enum class VqSamplerReductionMode : uint32_t {
        WeightedAverage = 0,
        Min = 1,
        Max = 2,
        WeightedAverageRangeclampQCOM = 1000521000,
        WeightedAverageEXT = WeightedAverage,
        MinEXT = Min,
        MaxEXT = Max
    };
    
    std::string_view    to_string_view(VqSamplerReductionMode);

    enum class VqSamplerYcbcrModelConversion : uint32_t {
        RgbIdentity = 0,
        YcbcrIdentity = 1,
        Ycbcr709 = 2,
        Ycbcr601 = 3,
        Ycbcr2020 = 4,
        RgbIdentityKHR = RgbIdentity,
        YcbcrIdentityKHR = YcbcrIdentity,
        Ycbcr709KHR = Ycbcr709,
        Ycbcr601KHR = Ycbcr601,
        Ycbcr2020KHR = Ycbcr2020
    };
    
    std::string_view    to_string_view(VqSamplerYcbcrModelConversion);

    enum class VqSamplerYcbcrRange : uint32_t {
        ItuFull = 0,
        ItuNarrow = 1,
        ItuFullKHR = ItuFull,
        ItuNarrowKHR = ItuNarrow
    };
    
    std::string_view    to_string_view(VqSamplerYcbcrRange);

    enum class VqScope : uint32_t {
        DeviceKHR = 1,
        WorkgroupKHR = 2,
        SubgroupKHR = 3,
        QueueFamilyKHR = 5,
        DeviceNV = DeviceKHR,
        WorkgroupNV = WorkgroupKHR,
        SubgroupNV = SubgroupKHR,
        QueueFamilyNV = QueueFamilyKHR
    };
    
    std::string_view    to_string_view(VqScope);

    enum class VqSemaphoreImportFlagBits : uint32_t {
        TemporaryBit = 0x00000001,
        TemporaryBitKHR = TemporaryBit
    };
    
    std::string_view    to_string_view(VqSemaphoreImportFlagBits);

    enum class VqSemaphoreType : uint32_t {
        Binary = 0,
        Timeline = 1,
        BinaryKHR = Binary,
        TimelineKHR = Timeline
    };
    
    std::string_view    to_string_view(VqSemaphoreType);

    enum class VqSemaphoreWaitFlagBits : uint32_t {
        AnyBit = 0x00000001,
        AnyBitKHR = AnyBit
    };
    
    std::string_view    to_string_view(VqSemaphoreWaitFlagBits);

    enum class VqShaderCodeType : uint32_t {
        BinaryEXT = 0,
        SpirvEXT = 1
    };
    
    std::string_view    to_string_view(VqShaderCodeType);

    enum class VqShaderCorePropertiesFlagBits : uint32_t {

    };
    
    std::string_view    to_string_view(VqShaderCorePropertiesFlagBits);

    enum class VqShaderCreateFlagBits : uint32_t {
        LinkStageBitEXT = 0x00000001,
        AllowVaryingSubgroupSizeBitEXT = 0x00000002,
        RequireFullSubgroupsBitEXT = 0x00000004,
        NoTaskShaderBitEXT = 0x00000008,
        DispatchBaseBitEXT = 0x00000010,
        FragmentShadingRateAttachmentBitEXT = 0x00000020,
        FragmentDensityMapAttachmentBitEXT = 0x00000040
    };
    
    std::string_view    to_string_view(VqShaderCreateFlagBits);

    enum class VqShaderFloatControlsIndependence : uint32_t {
        32BitOnly = 0,
        All = 1,
        None = 2,
        32BitOnlyKHR = 32BitOnly,
        AllKHR = All,
        NoneKHR = None
    };
    
    std::string_view    to_string_view(VqShaderFloatControlsIndependence);

    enum class VqShaderGroupShader : uint32_t {
        GeneralKHR = 0,
        ClosestHitKHR = 1,
        AnyHitKHR = 2,
        IntersectionKHR = 3
    };
    
    std::string_view    to_string_view(VqShaderGroupShader);

    enum class VqShaderInfoType : uint32_t {
        StatisticsAMD = 0,
        BinaryAMD = 1,
        DisassemblyAMD = 2
    };
    
    std::string_view    to_string_view(VqShaderInfoType);

    enum class VqShaderStageFlagBits : uint32_t {
        VertexBit = 0x00000001,
        TessellationControlBit = 0x00000002,
        TessellationEvaluationBit = 0x00000004,
        GeometryBit = 0x00000008,
        FragmentBit = 0x00000010,
        ComputeBit = 0x00000020,
        AllGraphics = 0x0000001f,
        All = 0x7fffffff,
        RaygenBitKHR = 0x00000100,
        AnyHitBitKHR = 0x00000200,
        ClosestHitBitKHR = 0x00000400,
        MissBitKHR = 0x00000800,
        IntersectionBitKHR = 0x00001000,
        CallableBitKHR = 0x00002000,
        TaskBitEXT = 0x00000040,
        MeshBitEXT = 0x00000080,
        SubpassShadingBitHuawei = 0x00004000,
        ClusterCullingBitHuawei = 0x00080000,
        RaygenBitNV = RaygenBitKHR,
        AnyHitBitNV = AnyHitBitKHR,
        ClosestHitBitNV = ClosestHitBitKHR,
        MissBitNV = MissBitKHR,
        IntersectionBitNV = IntersectionBitKHR,
        CallableBitNV = CallableBitKHR,
        TaskBitNV = TaskBitEXT,
        MeshBitNV = MeshBitEXT
    };
    
    std::string_view    to_string_view(VqShaderStageFlagBits);

    enum class VqShadingRatePaletteEntry : uint32_t {
        NoInvocationsNV = 0,
        16InvocationsPerPixelNV = 1,
        8InvocationsPerPixelNV = 2,
        4InvocationsPerPixelNV = 3,
        2InvocationsPerPixelNV = 4,
        1InvocationPerPixelNV = 5,
        1InvocationPer2x1PixelsNV = 6,
        1InvocationPer1x2PixelsNV = 7,
        1InvocationPer2x2PixelsNV = 8,
        1InvocationPer4x2PixelsNV = 9,
        1InvocationPer2x4PixelsNV = 10,
        1InvocationPer4x4PixelsNV = 11
    };
    
    std::string_view    to_string_view(VqShadingRatePaletteEntry);

    enum class VqSharingMode : uint32_t {
        Exclusive = 0,
        Concurrent = 1
    };
    
    std::string_view    to_string_view(VqSharingMode);

    enum class VqSparseImageFormatFlagBits : uint32_t {
        SingleMiptailBit = 0x00000001,
        AlignedMipSizeBit = 0x00000002,
        NonstandardBlockSizeBit = 0x00000004
    };
    
    std::string_view    to_string_view(VqSparseImageFormatFlagBits);

    enum class VqSparseMemoryBindFlagBits : uint32_t {
        MetadataBit = 0x00000001
    };
    
    std::string_view    to_string_view(VqSparseMemoryBindFlagBits);

    enum class VqStencilFaceFlagBits : uint32_t {
        FrontBit = 0x00000001,
        BackBit = 0x00000002,
        FrontAndBack = 0x00000003,
        VkStencilFrontAndBack = FrontAndBack
    };
    
    std::string_view    to_string_view(VqStencilFaceFlagBits);

    enum class VqStencilOp : uint32_t {
        Keep = 0,
        Zero = 1,
        Replace = 2,
        IncrementAndClamp = 3,
        DecrementAndClamp = 4,
        Invert = 5,
        IncrementAndWrap = 6,
        DecrementAndWrap = 7
    };
    
    std::string_view    to_string_view(VqStencilOp);

    enum class VqSubgroupFeatureFlagBits : uint32_t {
        BasicBit = 0x00000001,
        VoteBit = 0x00000002,
        ArithmeticBit = 0x00000004,
        BallotBit = 0x00000008,
        ShuffleBit = 0x00000010,
        ShuffleRelativeBit = 0x00000020,
        ClusteredBit = 0x00000040,
        QuadBit = 0x00000080,
        PartitionedBitNV = 0x00000100,
        RotateBitKHR = 0x00000200,
        RotateClusteredBitKHR = 0x00000400
    };
    
    std::string_view    to_string_view(VqSubgroupFeatureFlagBits);

    enum class VqSubmitFlagBits : uint32_t {
        ProtectedBit = 0x00000001,
        ProtectedBitKHR = ProtectedBit
    };
    
    std::string_view    to_string_view(VqSubmitFlagBits);

    enum class VqSubpassContents : uint32_t {
        Inline = 0,
        SecondaryCommandBuffers = 1,
        InlineAndSecondaryCommandBuffersKHR = 1000451000,
        InlineAndSecondaryCommandBuffersEXT = InlineAndSecondaryCommandBuffersKHR
    };
    
    std::string_view    to_string_view(VqSubpassContents);

    enum class VqSubpassDescriptionFlagBits : uint32_t {
        PerViewAttributesBitNvx = 0x00000001,
        PerViewPositionXOnlyBitNvx = 0x00000002,
        FragmentRegionBitQCOM = 0x00000004,
        ShaderResolveBitQCOM = 0x00000008,
        RasterizationOrderAttachmentColorAccessBitEXT = 0x00000010,
        RasterizationOrderAttachmentDepthAccessBitEXT = 0x00000020,
        RasterizationOrderAttachmentStencilAccessBitEXT = 0x00000040,
        EnableLegacyDitheringBitEXT = 0x00000080,
        RasterizationOrderAttachmentColorAccessBitArm = RasterizationOrderAttachmentColorAccessBitEXT,
        RasterizationOrderAttachmentDepthAccessBitArm = RasterizationOrderAttachmentDepthAccessBitEXT,
        RasterizationOrderAttachmentStencilAccessBitArm = RasterizationOrderAttachmentStencilAccessBitEXT
    };
    
    std::string_view    to_string_view(VqSubpassDescriptionFlagBits);

    enum class VqSubpassMergeStatus : uint32_t {
        MergedEXT = 0,
        DisallowedEXT = 1,
        NotMergedSideEffectsEXT = 2,
        NotMergedSamplesMismatchEXT = 3,
        NotMergedViewsMismatchEXT = 4,
        NotMergedAliasingEXT = 5,
        NotMergedDependenciesEXT = 6,
        NotMergedIncompatibleInputAttachmentEXT = 7,
        NotMergedTooManyAttachmentsEXT = 8,
        NotMergedInsufficientStorageEXT = 9,
        NotMergedDepthStencilCountEXT = 10,
        NotMergedResolveAttachmentReuseEXT = 11,
        NotMergedSingleSubpassEXT = 12,
        NotMergedUnspecifiedEXT = 13
    };
    
    std::string_view    to_string_view(VqSubpassMergeStatus);

    enum class VqSurfaceCounterFlagBits : uint32_t {
        VblankBitEXT = 0x00000001,
        VblankEXT = VblankBitEXT
    };
    
    std::string_view    to_string_view(VqSurfaceCounterFlagBits);

    enum class VqSurfaceTransformFlagBits : uint32_t {
        IdentityBitKHR = 0x00000001,
        Rotate90BitKHR = 0x00000002,
        Rotate180BitKHR = 0x00000004,
        Rotate270BitKHR = 0x00000008,
        HorizontalMirrorBitKHR = 0x00000010,
        HorizontalMirrorRotate90BitKHR = 0x00000020,
        HorizontalMirrorRotate180BitKHR = 0x00000040,
        HorizontalMirrorRotate270BitKHR = 0x00000080,
        InheritBitKHR = 0x00000100
    };
    
    std::string_view    to_string_view(VqSurfaceTransformFlagBits);

    enum class VqSwapchainCreateFlagBits : uint32_t {
        SplitInstanceBindRegionsBitKHR = 0x00000001,
        ProtectedBitKHR = 0x00000002,
        MutableFormatBitKHR = 0x00000004,
        DeferredMemoryAllocationBitEXT = 0x00000008
    };
    
    std::string_view    to_string_view(VqSwapchainCreateFlagBits);

    enum class VqSystemAllocationScope : uint32_t {
        Command = 0,
        Object = 1,
        Cache = 2,
        Device = 3,
        Instance = 4
    };
    
    std::string_view    to_string_view(VqSystemAllocationScope);

    enum class VqTessellationDomainOrigin : uint32_t {
        UpperLeft = 0,
        LowerLeft = 1,
        UpperLeftKHR = UpperLeft,
        LowerLeftKHR = LowerLeft
    };
    
    std::string_view    to_string_view(VqTessellationDomainOrigin);

    enum class VqTimeDomain : uint32_t {
        DeviceKHR = 0,
        ClockMonotonicKHR = 1,
        ClockMonotonicRawKHR = 2,
        QueryPerformanceCounterKHR = 3,
        DeviceEXT = DeviceKHR,
        ClockMonotonicEXT = ClockMonotonicKHR,
        ClockMonotonicRawEXT = ClockMonotonicRawKHR,
        QueryPerformanceCounterEXT = QueryPerformanceCounterKHR
    };
    
    std::string_view    to_string_view(VqTimeDomain);

    enum class VqToolPurposeFlagBits : uint32_t {
        ValidationBit = 0x00000001,
        ProfilingBit = 0x00000002,
        TracingBit = 0x00000004,
        AdditionalFeaturesBit = 0x00000008,
        ModifyingFeaturesBit = 0x00000010,
        DebugReportingBitEXT = 0x00000020,
        DebugMarkersBitEXT = 0x00000040,
        ValidationBitEXT = ValidationBit,
        ProfilingBitEXT = ProfilingBit,
        TracingBitEXT = TracingBit,
        AdditionalFeaturesBitEXT = AdditionalFeaturesBit,
        ModifyingFeaturesBitEXT = ModifyingFeaturesBit
    };
    
    std::string_view    to_string_view(VqToolPurposeFlagBits);

    enum class VqValidationCacheHeaderVersion : uint32_t {
        OneEXT = 1
    };
    
    std::string_view    to_string_view(VqValidationCacheHeaderVersion);

    enum class VqValidationCheck : uint32_t {
        AllEXT = 0,
        ShadersEXT = 1
    };
    
    std::string_view    to_string_view(VqValidationCheck);

    enum class VqValidationFeatureDisable : uint32_t {
        AllEXT = 0,
        ShadersEXT = 1,
        ThreadSafetyEXT = 2,
        ApiParametersEXT = 3,
        ObjectLifetimesEXT = 4,
        CoreChecksEXT = 5,
        UniqueHandlesEXT = 6,
        ShaderValidationCacheEXT = 7
    };
    
    std::string_view    to_string_view(VqValidationFeatureDisable);

    enum class VqValidationFeatureEnable : uint32_t {
        GpuAssistedEXT = 0,
        GpuAssistedReserveBindingSlotEXT = 1,
        BestPracticesEXT = 2,
        DebugPrintfEXT = 3,
        SynchronizationValidationEXT = 4
    };
    
    std::string_view    to_string_view(VqValidationFeatureEnable);

    enum class VqVendorId : uint32_t {
        Khronos = 0x10000,
        Viv = 0x10001,
        Vsi = 0x10002,
        Kazan = 0x10003,
        Codeplay = 0x10004,
        Mesa = 0x10005,
        Pocl = 0x10006,
        Mobileye = 0x10007
    };
    
    std::string_view    to_string_view(VqVendorId);

    enum class VqVertexInputRate : uint32_t {
        Vertex = 0,
        Instance = 1
    };
    
    std::string_view    to_string_view(VqVertexInputRate);

    enum class VqVideoCapabilityFlagBits : uint32_t {
        ProtectedContentBitKHR = 0x00000001,
        SeparateReferenceImagesBitKHR = 0x00000002
    };
    
    std::string_view    to_string_view(VqVideoCapabilityFlagBits);

    enum class VqVideoChromaSubsamplingFlagBits : uint32_t {
        InvalidKHR = 0,
        MonochromeBitKHR = 0x00000001,
        420BitKHR = 0x00000002,
        422BitKHR = 0x00000004,
        444BitKHR = 0x00000008
    };
    
    std::string_view    to_string_view(VqVideoChromaSubsamplingFlagBits);

    enum class VqVideoCodecOperationFlagBits : uint32_t {
        NoneKHR = 0,
        EncodeH264BitKHR = 0x00010000,
        EncodeH265BitKHR = 0x00020000,
        DecodeH264BitKHR = 0x00000001,
        DecodeH265BitKHR = 0x00000002,
        DecodeAv1BitKHR = 0x00000004
    };
    
    std::string_view    to_string_view(VqVideoCodecOperationFlagBits);

    enum class VqVideoCodingControlFlagBits : uint32_t {
        ResetBitKHR = 0x00000001,
        EncodeRateControlBitKHR = 0x00000002,
        EncodeQualityLevelBitKHR = 0x00000004
    };
    
    std::string_view    to_string_view(VqVideoCodingControlFlagBits);

    enum class VqVideoComponentBitDepthFlagBits : uint32_t {
        InvalidKHR = 0,
        8BitKHR = 0x00000001,
        10BitKHR = 0x00000004,
        12BitKHR = 0x00000010
    };
    
    std::string_view    to_string_view(VqVideoComponentBitDepthFlagBits);

    enum class VqVideoDecodeCapabilityFlagBits : uint32_t {
        DpbAndOutputCoincideBitKHR = 0x00000001,
        DpbAndOutputDistinctBitKHR = 0x00000002
    };
    
    std::string_view    to_string_view(VqVideoDecodeCapabilityFlagBits);

    enum class VqVideoDecodeH264PictureLayoutFlagBits : uint32_t {
        ProgressiveKHR = 0,
        InterlacedInterleavedLinesBitKHR = 0x00000001,
        InterlacedSeparatePlanesBitKHR = 0x00000002
    };
    
    std::string_view    to_string_view(VqVideoDecodeH264PictureLayoutFlagBits);

    enum class VqVideoDecodeUsageFlagBits : uint32_t {
        DefaultKHR = 0,
        TranscodingBitKHR = 0x00000001,
        OfflineBitKHR = 0x00000002,
        StreamingBitKHR = 0x00000004
    };
    
    std::string_view    to_string_view(VqVideoDecodeUsageFlagBits);

    enum class VqVideoEncodeCapabilityFlagBits : uint32_t {
        PrecedingExternallyEncodedBytesBitKHR = 0x00000001,
        InsufficientBitstreamBufferRangeDetectionBitKHR = 0x00000002
    };
    
    std::string_view    to_string_view(VqVideoEncodeCapabilityFlagBits);

    enum class VqVideoEncodeContentFlagBits : uint32_t {
        DefaultKHR = 0,
        CameraBitKHR = 0x00000001,
        DesktopBitKHR = 0x00000002,
        RenderedBitKHR = 0x00000004
    };
    
    std::string_view    to_string_view(VqVideoEncodeContentFlagBits);

    enum class VqVideoEncodeFeedbackFlagBits : uint32_t {
        BitstreamBufferOffsetBitKHR = 0x00000001,
        BitstreamBytesWrittenBitKHR = 0x00000002,
        BitstreamHasOverridesBitKHR = 0x00000004
    };
    
    std::string_view    to_string_view(VqVideoEncodeFeedbackFlagBits);

    enum class VqVideoEncodeFlagBits : uint32_t {

    };
    
    std::string_view    to_string_view(VqVideoEncodeFlagBits);

    enum class VqVideoEncodeH264CapabilityFlagBits : uint32_t {
        HrdComplianceBitKHR = 0x00000001,
        PredictionWeightTableGeneratedBitKHR = 0x00000002,
        RowUnalignedSliceBitKHR = 0x00000004,
        DifferentSliceTypeBitKHR = 0x00000008,
        BFrameInL0ListBitKHR = 0x00000010,
        BFrameInL1ListBitKHR = 0x00000020,
        PerPictureTypeMinMaxQpBitKHR = 0x00000040,
        PerSliceConstantQpBitKHR = 0x00000080,
        GeneratePrefixNaluBitKHR = 0x00000100
    };
    
    std::string_view    to_string_view(VqVideoEncodeH264CapabilityFlagBits);

    enum class VqVideoEncodeH264RateControlFlagBits : uint32_t {
        AttemptHrdComplianceBitKHR = 0x00000001,
        RegularGopBitKHR = 0x00000002,
        ReferencePatternFlatBitKHR = 0x00000004,
        ReferencePatternDyadicBitKHR = 0x00000008,
        TemporalLayerPatternDyadicBitKHR = 0x00000010
    };
    
    std::string_view    to_string_view(VqVideoEncodeH264RateControlFlagBits);

    enum class VqVideoEncodeH264StdFlagBits : uint32_t {
        SeparateColorPlaneFlagSetBitKHR = 0x00000001,
        QpprimeYZeroTransformBypassFlagSetBitKHR = 0x00000002,
        ScalingMatrixPresentFlagSetBitKHR = 0x00000004,
        ChromaQpIndexOffsetBitKHR = 0x00000008,
        SecondChromaQpIndexOffsetBitKHR = 0x00000010,
        PicInitQpMinus26BitKHR = 0x00000020,
        WeightedPredFlagSetBitKHR = 0x00000040,
        WeightedBipredIdcExplicitBitKHR = 0x00000080,
        WeightedBipredIdcImplicitBitKHR = 0x00000100,
        Transform8x8ModeFlagSetBitKHR = 0x00000200,
        DirectSpatialMvPredFlagUnsetBitKHR = 0x00000400,
        EntropyCodingModeFlagUnsetBitKHR = 0x00000800,
        EntropyCodingModeFlagSetBitKHR = 0x00001000,
        Direct8x8InferenceFlagUnsetBitKHR = 0x00002000,
        ConstrainedIntraPredFlagSetBitKHR = 0x00004000,
        DeblockingFilterDisabledBitKHR = 0x00008000,
        DeblockingFilterEnabledBitKHR = 0x00010000,
        DeblockingFilterPartialBitKHR = 0x00020000,
        SliceQpDeltaBitKHR = 0x00080000,
        DifferentSliceQpDeltaBitKHR = 0x00100000
    };
    
    std::string_view    to_string_view(VqVideoEncodeH264StdFlagBits);

    enum class VqVideoEncodeH265CapabilityFlagBits : uint32_t {
        HrdComplianceBitKHR = 0x00000001,
        PredictionWeightTableGeneratedBitKHR = 0x00000002,
        RowUnalignedSliceSegmentBitKHR = 0x00000004,
        DifferentSliceSegmentTypeBitKHR = 0x00000008,
        BFrameInL0ListBitKHR = 0x00000010,
        BFrameInL1ListBitKHR = 0x00000020,
        PerPictureTypeMinMaxQpBitKHR = 0x00000040,
        PerSliceSegmentConstantQpBitKHR = 0x00000080,
        MultipleTilesPerSliceSegmentBitKHR = 0x00000100,
        MultipleSliceSegmentsPerTileBitKHR = 0x00000200
    };
    
    std::string_view    to_string_view(VqVideoEncodeH265CapabilityFlagBits);

    enum class VqVideoEncodeH265CtbSizeFlagBits : uint32_t {
        16BitKHR = 0x00000001,
        32BitKHR = 0x00000002,
        64BitKHR = 0x00000004
    };
    
    std::string_view    to_string_view(VqVideoEncodeH265CtbSizeFlagBits);

    enum class VqVideoEncodeH265RateControlFlagBits : uint32_t {
        AttemptHrdComplianceBitKHR = 0x00000001,
        RegularGopBitKHR = 0x00000002,
        ReferencePatternFlatBitKHR = 0x00000004,
        ReferencePatternDyadicBitKHR = 0x00000008,
        TemporalSubLayerPatternDyadicBitKHR = 0x00000010
    };
    
    std::string_view    to_string_view(VqVideoEncodeH265RateControlFlagBits);

    enum class VqVideoEncodeH265StdFlagBits : uint32_t {
        SeparateColorPlaneFlagSetBitKHR = 0x00000001,
        SampleAdaptiveOffsetEnabledFlagSetBitKHR = 0x00000002,
        ScalingListDataPresentFlagSetBitKHR = 0x00000004,
        PcmEnabledFlagSetBitKHR = 0x00000008,
        SpsTemporalMvpEnabledFlagSetBitKHR = 0x00000010,
        InitQpMinus26BitKHR = 0x00000020,
        WeightedPredFlagSetBitKHR = 0x00000040,
        WeightedBipredFlagSetBitKHR = 0x00000080,
        Log2ParallelMergeLevelMinus2BitKHR = 0x00000100,
        SignDataHidingEnabledFlagSetBitKHR = 0x00000200,
        TransformSkipEnabledFlagSetBitKHR = 0x00000400,
        TransformSkipEnabledFlagUnsetBitKHR = 0x00000800,
        PpsSliceChromaQpOffsetsPresentFlagSetBitKHR = 0x00001000,
        TransquantBypassEnabledFlagSetBitKHR = 0x00002000,
        ConstrainedIntraPredFlagSetBitKHR = 0x00004000,
        EntropyCodingSyncEnabledFlagSetBitKHR = 0x00008000,
        DeblockingFilterOverrideEnabledFlagSetBitKHR = 0x00010000,
        DependentSliceSegmentsEnabledFlagSetBitKHR = 0x00020000,
        DependentSliceSegmentFlagSetBitKHR = 0x00040000,
        SliceQpDeltaBitKHR = 0x00080000,
        DifferentSliceQpDeltaBitKHR = 0x00100000
    };
    
    std::string_view    to_string_view(VqVideoEncodeH265StdFlagBits);

    enum class VqVideoEncodeH265TransformBlockSizeFlagBits : uint32_t {
        4BitKHR = 0x00000001,
        8BitKHR = 0x00000002,
        16BitKHR = 0x00000004,
        32BitKHR = 0x00000008
    };
    
    std::string_view    to_string_view(VqVideoEncodeH265TransformBlockSizeFlagBits);

    enum class VqVideoEncodeRateControlModeFlagBits : uint32_t {
        DefaultKHR = 0,
        DisabledBitKHR = 0x00000001,
        CbrBitKHR = 0x00000002,
        VbrBitKHR = 0x00000004
    };
    
    std::string_view    to_string_view(VqVideoEncodeRateControlModeFlagBits);

    enum class VqVideoEncodeTuningMode : uint32_t {
        DefaultKHR = 0,
        HighQualityKHR = 1,
        LowLatencyKHR = 2,
        UltraLowLatencyKHR = 3,
        LosslessKHR = 4
    };
    
    std::string_view    to_string_view(VqVideoEncodeTuningMode);

    enum class VqVideoEncodeUsageFlagBits : uint32_t {
        DefaultKHR = 0,
        TranscodingBitKHR = 0x00000001,
        StreamingBitKHR = 0x00000002,
        RecordingBitKHR = 0x00000004,
        ConferencingBitKHR = 0x00000008
    };
    
    std::string_view    to_string_view(VqVideoEncodeUsageFlagBits);

    enum class VqVideoSessionCreateFlagBits : uint32_t {
        ProtectedContentBitKHR = 0x00000001,
        AllowEncodeParameterOptimizationsBitKHR = 0x00000002,
        InlineQueriesBitKHR = 0x00000004
    };
    
    std::string_view    to_string_view(VqVideoSessionCreateFlagBits);

    enum class VqViewportCoordinateSwizzle : uint32_t {
        PositiveXNV = 0,
        NegativeXNV = 1,
        PositiveYNV = 2,
        NegativeYNV = 3,
        PositiveZNV = 4,
        NegativeZNV = 5,
        PositiveWNV = 6,
        NegativeWNV = 7
    };
    
    std::string_view    to_string_view(VqViewportCoordinateSwizzle);

}
