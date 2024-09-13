////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

//  WARNING!  WARNING!  WARNNG!  WARNING!
//  This header file is AUTO-GENERATED, changes will be CLOBBERED

#include <string_view>
#include <yq-toolbox/basic/Flags.hpp>

namespace yq::tachyon {
    enum class VqAccelerationStructureBuildType : int32_t {
        Host = 0,
        Device = 1,
        HostOrDevice = 2
    };

    enum class VqAccelerationStructureCompatibility : int32_t {
        Compatible = 0,
        Incompatible = 1
    };

    enum class VqAccelerationStructureCreateBit : uint8_t {
        DeviceAddressCaptureReplay = 1,
        DescriptorBufferCaptureReplay = 4,
        Motion = 3
    };

    enum class VqAccelerationStructureMemoryRequirementsType : int32_t {
        Object = 0,
        BuildScratch = 1,
        UpdateScratch = 2
    };

    enum class VqAccelerationStructureMotionInstanceType : int32_t {
        Static = 0,
        MatrixMotion = 1,
        SrtMotion = 2
    };

    enum class VqAccelerationStructureType : int32_t {
        TopLevel = 0,
        BottomLevel = 1,
        Generic = 2
    };

    enum class VqAccessBit : uint8_t {
        IndirectCommandRead = 1,
        IndexRead = 2,
        VertexAttributeRead = 3,
        UniformRead = 4,
        InputAttachmentRead = 5,
        ShaderRead = 6,
        ShaderWrite = 7,
        ColorAttachmentRead = 8,
        ColorAttachmentWrite = 9,
        DepthStencilAttachmentRead = 10,
        DepthStencilAttachmentWrite = 11,
        TransferRead = 12,
        TransferWrite = 13,
        HostRead = 14,
        HostWrite = 15,
        MemoryRead = 16,
        MemoryWrite = 17,
        TransformFeedbackWrite = 26,
        TransformFeedbackCounterRead = 27,
        TransformFeedbackCounterWrite = 28,
        ConditionalRenderingRead = 21,
        ColorAttachmentReadNoncoherent = 20,
        AccelerationStructureRead = 22,
        AccelerationStructureWrite = 23,
        FragmentDensityMapRead = 25,
        FragmentShadingRateAttachmentRead = 24,
        CommandPreprocessRead = 18,
        CommandPreprocessWrite = 19,
        ShadingRateImageRead = FragmentShadingRateAttachmentRead
    };

    enum class VqAcquireProfilingLockBit : uint8_t {

    };

    enum class VqAttachmentDescriptionBit : uint8_t {
        MayAlias = 0
    };

    enum class VqAttachmentLoadOp : int32_t {
        Load = 0,
        Clear = 1,
        DontCare = 2,
        None = 1000400000
    };

    enum class VqAttachmentStoreOp : int32_t {
        Store = 0,
        DontCare = 1,
        None = 1000301000
    };

    enum class VqBlendFactor : int32_t {
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

    enum class VqBlendOp : int32_t {
        Add = 0,
        Subtract = 1,
        ReverseSubtract = 2,
        Min = 3,
        Max = 4,
        Zero = 1000148000,
        Src = 1000148001,
        Dst = 1000148002,
        SrcOver = 1000148003,
        DstOver = 1000148004,
        SrcIn = 1000148005,
        DstIn = 1000148006,
        SrcOut = 1000148007,
        DstOut = 1000148008,
        SrcAtop = 1000148009,
        DstAtop = 1000148010,
        Xor = 1000148011,
        Multiply = 1000148012,
        Screen = 1000148013,
        Overlay = 1000148014,
        Darken = 1000148015,
        Lighten = 1000148016,
        Colordodge = 1000148017,
        Colorburn = 1000148018,
        Hardlight = 1000148019,
        Softlight = 1000148020,
        Difference = 1000148021,
        Exclusion = 1000148022,
        Invert = 1000148023,
        InvertRgb = 1000148024,
        Lineardodge = 1000148025,
        Linearburn = 1000148026,
        Vividlight = 1000148027,
        Linearlight = 1000148028,
        Pinlight = 1000148029,
        Hardmix = 1000148030,
        HslHue = 1000148031,
        HslSaturation = 1000148032,
        HslColor = 1000148033,
        HslLuminosity = 1000148034,
        Plus = 1000148035,
        PlusClamped = 1000148036,
        PlusClampedAlpha = 1000148037,
        PlusDarker = 1000148038,
        Minus = 1000148039,
        MinusClamped = 1000148040,
        Contrast = 1000148041,
        InvertOvg = 1000148042,
        Red = 1000148043,
        Green = 1000148044,
        Blue = 1000148045
    };

    enum class VqBlendOverlap : int32_t {
        Uncorrelated = 0,
        Disjoint = 1,
        Conjoint = 2
    };

    enum class VqBlockMatchWindowCompareMode : int32_t {
        Min = 0,
        Max = 1
    };

    enum class VqBorderColor : int32_t {
        FloatTransparentBlack = 0,
        IntTransparentBlack = 1,
        FloatOpaqueBlack = 2,
        IntOpaqueBlack = 3,
        FloatOpaqueWhite = 4,
        IntOpaqueWhite = 5,
        FloatCustom = 1000287003,
        IntCustom = 1000287004
    };

    enum class VqBufferCreateBit : uint8_t {
        SparseBinding = 1,
        SparseResidency = 2,
        SparseAliased = 3,
        Protected = 4,
        DeviceAddressCaptureReplay = 5,
        DescriptorBufferCaptureReplay = 6,
        VideoProfileIndependent = 7
    };

    enum class VqBufferUsageBit : uint8_t {
        TransferSrc = 1,
        TransferDst = 2,
        UniformTexelBuffer = 3,
        StorageTexelBuffer = 4,
        UniformBuffer = 5,
        StorageBuffer = 6,
        IndexBuffer = 7,
        VertexBuffer = 8,
        IndirectBuffer = 9,
        ShaderDeviceAddress = 18,
        VideoDecodeSrc = 14,
        VideoDecodeDst = 15,
        TransformFeedbackBuffer = 12,
        TransformFeedbackCounterBuffer = 13,
        ConditionalRendering = 10,
        ExecutionGraphScratchBitAmdx = 26,
        AccelerationStructureBuildInputReadOnly = 20,
        AccelerationStructureStorage = 21,
        ShaderBindingTable = 11,
        VideoEncodeDst = 16,
        VideoEncodeSrc = 17,
        SamplerDescriptorBuffer = 22,
        ResourceDescriptorBuffer = 23,
        PushDescriptorsDescriptorBuffer = 27,
        MicromapBuildInputReadOnly = 24,
        MicromapStorage = 25,
        RayTracing = ShaderBindingTable
    };

    enum class VqBuildAccelerationStructureBit : uint8_t {
        AllowUpdate = 1,
        AllowCompaction = 2,
        PreferFastTrace = 3,
        PreferFastBuild = 4,
        LowMemory = 5,
        Motion = 6,
        AllowOpacityMicromapUpdate = 7,
        AllowDisableOpacityMicromaps = 8,
        AllowOpacityMicromapDataUpdate = 9,
        AllowDisplacementMicromapUpdate = 10,
        AllowDataAccess = 12
    };

    enum class VqBuildAccelerationStructureMode : int32_t {
        Build = 0,
        Update = 1
    };

    enum class VqBuildMicromapBit : uint8_t {
        PreferFastTrace = 1,
        PreferFastBuild = 2,
        AllowCompaction = 3
    };

    enum class VqBuildMicromapMode : int32_t {
        Build = 0
    };

    enum class VqChromaLocation : int32_t {
        CositedEven = 0,
        Midpoint = 1
    };

    enum class VqCoarseSampleOrderType : int32_t {
        Default = 0,
        Custom = 1,
        PixelMajor = 2,
        SampleMajor = 3
    };

    enum class VqColorComponentBit : uint8_t {
        R = 1,
        G = 2,
        B = 3,
        A = 4
    };

    enum class VqColorSpace : int32_t {
        SrgbNonlinear = 0,
        DisplayP3Nonlinear = 1000104001,
        ExtendedSrgbLinear = 1000104002,
        DisplayP3Linear = 1000104003,
        DciP3Nonlinear = 1000104004,
        Bt709Linear = 1000104005,
        Bt709Nonlinear = 1000104006,
        Bt2020Linear = 1000104007,
        Hdr10St2084 = 1000104008,
        Dolbyvision = 1000104009,
        Hdr10Hlg = 1000104010,
        AdobergbLinear = 1000104011,
        AdobergbNonlinear = 1000104012,
        PassThrough = 1000104013,
        ExtendedSrgbNonlinear = 1000104014,
        DisplayNativeAMD = 1000213000,
        ColorspaceSrgbNonlinear = SrgbNonlinear,
        DciP3Linear = DisplayP3Linear
    };

    enum class VqCommandBufferLevel : int32_t {
        Primary = 0,
        Secondary = 1
    };

    enum class VqCommandBufferResetBit : uint8_t {
        ReleaseResources = 1
    };

    enum class VqCommandBufferUsageBit : uint8_t {
        OneTimeSubmit = 1,
        RenderPassContinue = 2,
        SimultaneousUse = 3
    };

    enum class VqCommandPoolCreateBit : uint8_t {
        Transient = 1,
        ResetCommandBuffer = 2,
        Protected = 3
    };

    enum class VqCommandPoolResetBit : uint8_t {
        ReleaseResources = 1
    };

    enum class VqCompareOp : int32_t {
        Never = 0,
        Less = 1,
        Equal = 2,
        LessOrEqual = 3,
        Greater = 4,
        NotEqual = 5,
        GreaterOrEqual = 6,
        Always = 7
    };

    enum class VqComponentSwizzle : int32_t {
        Identity = 0,
        Zero = 1,
        One = 2,
        R = 3,
        G = 4,
        B = 5,
        A = 6
    };

    enum class VqComponentType : int32_t {
        Float16 = 0,
        Float32 = 1,
        Float64 = 2,
        Sint8 = 3,
        Sint16 = 4,
        Sint32 = 5,
        Sint64 = 6,
        Uint8 = 7,
        Uint16 = 8,
        Uint32 = 9,
        Uint64 = 10
    };

    enum class VqCompositeAlphaBit : uint8_t {
        Opaque = 1,
        PreMultiplied = 2,
        PostMultiplied = 3,
        Inherit = 4
    };

    enum class VqConditionalRenderingBit : uint8_t {
        Inverted = 1
    };

    enum class VqConservativeRasterizationMode : int32_t {
        Disabled = 0,
        Overestimate = 1,
        Underestimate = 2
    };

    enum class VqCopyAccelerationStructureMode : int32_t {
        Clone = 0,
        Compact = 1,
        Serialize = 2,
        Deserialize = 3
    };

    enum class VqCopyMicromapMode : int32_t {
        Clone = 0,
        Serialize = 1,
        Deserialize = 2,
        Compact = 3
    };

    enum class VqCoverageModulationMode : int32_t {
        None = 0,
        Rgb = 1,
        Alpha = 2,
        Rgba = 3
    };

    enum class VqCoverageReductionMode : int32_t {
        Merge = 0,
        Truncate = 1
    };

    enum class VqCubicFilterWeights : int32_t {
        CatmullRom = 0,
        ZeroTangentCardinal = 1,
        BSpline = 2,
        MitchellNetravali = 3
    };

    enum class VqCullModeBit : uint8_t {
        Front = 1,
        Back = 2,
        FrontAndBack = 2
    };

    enum class VqDebugReportBit : uint8_t {
        Information = 1,
        Warning = 2,
        PerformanceWarning = 3,
        Error = 4,
        Debug = 5
    };

    enum class VqDebugReportObjectType : int32_t {
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
        Surface = 26,
        Swapchain = 27,
        DebugReportCallback = 28,
        Display = 29,
        DisplayMode = 30,
        ValidationCache = 33,
        SamplerYcbcrConversion = 1000156000,
        DescriptorUpdateTemplate = 1000085000,
        CuModuleNvx = 1000029000,
        CuFunctionNvx = 1000029001,
        AccelerationStructure = 1000150000,
        CudaModule = 1000307000,
        CudaFunction = 1000307001,
        BufferCollectionFuchsia = 1000366000,
        DebugReport = DebugReportCallback
    };

    enum class VqDebugUtilsMessageSeverityBit : uint8_t {
        Verbose = 1,
        Info = 5,
        Warning = 9,
        Error = 13
    };

    enum class VqDebugUtilsMessageTypeBit : uint8_t {
        General = 1,
        Validation = 2,
        Performance = 3,
        DeviceAddressBinding = 4
    };

    enum class VqDependencyBit : uint8_t {
        ByRegion = 1,
        DeviceGroup = 3,
        ViewLocal = 2,
        FeedbackLoop = 4
    };

    enum class VqDepthBiasRepresentation : int32_t {
        LeastRepresentableValueFormat = 0,
        LeastRepresentableValueForceUnorm = 1,
        Float = 2
    };

    enum class VqDescriptorBindingBit : uint8_t {
        UpdateAfterBind = 1,
        UpdateUnusedWhilePending = 2,
        PartiallyBound = 3,
        VariableDescriptorCount = 4
    };

    enum class VqDescriptorPoolCreateBit : uint8_t {
        FreeDescriptorSet = 1,
        UpdateAfterBind = 2,
        HostOnly = 3,
        AllowOverallocationSets = 4,
        AllowOverallocationPools = 5,
        HostOnlyBitValve = HostOnly
    };

    enum class VqDescriptorSetLayoutCreateBit : uint8_t {
        UpdateAfterBindPool = 2,
        PushDescriptor = 1,
        DescriptorBuffer = 5,
        EmbeddedImmutableSamplers = 6,
        IndirectBindable = 8,
        HostOnlyPool = 3,
        PerStage = 7,
        HostOnlyPoolBitValve = HostOnlyPool
    };

    enum class VqDescriptorType : int32_t {
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
        AccelerationStructure = 1000150000,
        SampleWeightImage = 1000440000,
        BlockMatchImage = 1000440001,
        Mutable = 1000351000,
        MutableValve = Mutable
    };

    enum class VqDescriptorUpdateTemplateType : int32_t {
        DescriptorSet = 0,
        PushDescriptors = 1
    };

    enum class VqDeviceAddressBindingBit : uint8_t {
        InternalObject = 1
    };

    enum class VqDeviceAddressBindingType : int32_t {
        Bind = 0,
        Unbind = 1
    };

    enum class VqDeviceDiagnosticsConfigBit : uint8_t {
        EnableShaderDebugInfo = 1,
        EnableResourceTracking = 2,
        EnableAutomaticCheckpoints = 3,
        EnableShaderErrorReporting = 4
    };

    enum class VqDeviceEventType : int32_t {
        DisplayHotplug = 0
    };

    enum class VqDeviceFaultAddressType : int32_t {
        None = 0,
        ReadInvalid = 1,
        WriteInvalid = 2,
        ExecuteInvalid = 3,
        InstructionPointerUnknown = 4,
        InstructionPointerInvalid = 5,
        InstructionPointerFault = 6
    };

    enum class VqDeviceFaultVendorBinaryHeaderVersion : int32_t {
        One = 1
    };

    enum class VqDeviceGroupPresentModeBit : uint8_t {
        Local = 1,
        Remote = 2,
        Sum = 3,
        LocalMultiDevice = 4
    };

    enum class VqDeviceMemoryReportEventType : int32_t {
        Allocate = 0,
        Free = 1,
        Import = 2,
        Unimport = 3,
        AllocationFailed = 4
    };

    enum class VqDeviceQueueCreateBit : uint8_t {
        Protected = 1
    };

    enum class VqDirectDriverLoadingMode : int32_t {
        ExclusiveLUNARG = 0,
        InclusiveLUNARG = 1
    };

    enum class VqDiscardRectangleMode : int32_t {
        Inclusive = 0,
        Exclusive = 1
    };

    enum class VqDisplayEventType : int32_t {
        FirstPixelOut = 0
    };

    enum class VqDisplayPlaneAlphaBit : uint8_t {
        Opaque = 1,
        Global = 2,
        PerPixel = 3,
        PerPixelPremultiplied = 4
    };

    enum class VqDisplayPowerState : int32_t {
        Off = 0,
        Suspend = 1,
        On = 2
    };

    enum class VqDriverId : int32_t {
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
        Reserved27 = 27
    };

    enum class VqDynamicState : int32_t {
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
    };

    enum class VqEventCreateBit : uint8_t {
        DeviceOnly = 1
    };

    enum class VqExternalFenceFeatureBit : uint8_t {
        Exportable = 1,
        Importable = 2
    };

    enum class VqExternalFenceHandleTypeBit : uint8_t {
        OpaqueFd = 1,
        OpaqueWin32 = 2,
        OpaqueWin32Kmt = 3,
        SyncFd = 4
    };

    enum class VqExternalMemoryFeatureBit : uint8_t {
        DedicatedOnly = 1,
        Exportable = 2,
        Importable = 3
    };

    enum class VqExternalMemoryHandleTypeBit : uint8_t {
        OpaqueFd = 1,
        OpaqueWin32 = 2,
        OpaqueWin32Kmt = 3,
        D3d11Texture = 4,
        D3d11TextureKmt = 5,
        D3d12Heap = 6,
        D3d12Resource = 7,
        DmaBuf = 10,
        AndroidHardwareBufferBitAndroid = 11,
        HostAllocation = 8,
        HostMappedForeignMemory = 9,
        ZirconVmoBitFuchsia = 12,
        RdmaAddress = 13,
        ScreenBufferBitQnx = 15
    };

    enum class VqExternalSemaphoreFeatureBit : uint8_t {
        Exportable = 1,
        Importable = 2
    };

    enum class VqExternalSemaphoreHandleTypeBit : uint8_t {
        OpaqueFd = 1,
        OpaqueWin32 = 2,
        OpaqueWin32Kmt = 3,
        D3d12Fence = 4,
        SyncFd = 5,
        ZirconEventBitFuchsia = 8,
        D3d11Fence = D3d12Fence
    };

    enum class VqFenceCreateBit : uint8_t {
        Signaled = 1
    };

    enum class VqFenceImportBit : uint8_t {
        Temporary = 1
    };

    enum class VqFilter : int32_t {
        Nearest = 0,
        Linear = 1,
        Cubic = 1000015000,
        CubicImg = Cubic
    };

    enum class VqFormat : int32_t {
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
        R16g16Sfixed5 = 1000464000,
        A1b5g5r5UnormPack16 = 1000470000,
        A8Unorm = 1000470001,
        R16g16S105 = R16g16Sfixed5
    };

    enum class VqFormatFeatureBit : uint8_t {
        SampledImage = 1,
        StorageImage = 2,
        StorageImageAtomic = 3,
        UniformTexelBuffer = 4,
        StorageTexelBuffer = 5,
        StorageTexelBufferAtomic = 6,
        VertexBuffer = 7,
        ColorAttachment = 8,
        ColorAttachmentBlend = 9,
        DepthStencilAttachment = 10,
        BlitSrc = 11,
        BlitDst = 12,
        SampledImageFilterLinear = 13,
        TransferSrc = 15,
        TransferDst = 16,
        MidpointChromaSamples = 18,
        SampledImageYcbcrConversionLinearFilter = 19,
        SampledImageYcbcrConversionSeparateReconstructionFilter = 20,
        SampledImageYcbcrConversionChromaReconstructionExplicit = 21,
        SampledImageYcbcrConversionChromaReconstructionExplicitForceable = 22,
        Disjoint = 23,
        CositedChromaSamples = 24,
        SampledImageFilterMinmax = 17,
        VideoDecodeOutput = 26,
        VideoDecodeDpb = 27,
        AccelerationStructureVertexBuffer = 30,
        SampledImageFilterCubic = 14,
        FragmentDensityMap = 25,
        FragmentShadingRateAttachment = 31,
        VideoEncodeInput = 28,
        VideoEncodeDpb = 29,
        SampledImageFilterCubicBitImg = SampledImageFilterCubic
    };

    enum class VqFragmentShadingRate : int32_t {
        _1InvocationPerPixel = 0,
        _1InvocationPer1x2Pixels = 1,
        _1InvocationPer2x1Pixels = 4,
        _1InvocationPer2x2Pixels = 5,
        _1InvocationPer2x4Pixels = 6,
        _1InvocationPer4x2Pixels = 9,
        _1InvocationPer4x4Pixels = 10,
        _2InvocationsPerPixel = 11,
        _4InvocationsPerPixel = 12,
        _8InvocationsPerPixel = 13,
        _16InvocationsPerPixel = 14,
        NoInvocations = 15
    };

    enum class VqFragmentShadingRateCombinerOp : int32_t {
        Keep = 0,
        Replace = 1,
        Min = 2,
        Max = 3,
        Mul = 4
    };

    enum class VqFragmentShadingRateType : int32_t {
        FragmentSize = 0,
        Enums = 1
    };

    enum class VqFrameBoundaryBit : uint8_t {
        FrameEnd = 1
    };

    enum class VqFramebufferCreateBit : uint8_t {
        Imageless = 0
    };

    enum class VqFrontFace : int32_t {
        CounterClockwise = 0,
        Clockwise = 1
    };

    enum class VqGeometryBit : uint8_t {
        Opaque = 1,
        NoDuplicateAnyHitInvocation = 2
    };

    enum class VqGeometryInstanceBit : uint8_t {
        TriangleFacingCullDisable = 1,
        TriangleFlipFacing = 2,
        ForceOpaque = 3,
        ForceNoOpaque = 4,
        ForceOpacityMicromap2State = 5,
        DisableOpacityMicromaps = 6,
        TriangleFrontCounterclockwise = TriangleFlipFacing,
        TriangleCullDisable = TriangleFacingCullDisable
    };

    enum class VqGeometryType : int32_t {
        Triangles = 0,
        Aabbs = 1,
        Instances = 2
    };

    enum class VqGraphicsPipelineLibraryBit : uint8_t {
        VertexInputInterface = 1,
        PreRasterizationShaders = 2,
        FragmentShader = 3,
        FragmentOutputInterface = 4
    };

    enum class VqHostImageCopyBit : uint8_t {
        Memcpy = 1
    };

    enum class VqImageAspectBit : uint8_t {
        Color = 1,
        Depth = 2,
        Stencil = 3,
        Metadata = 4,
        Plane0 = 5,
        Plane1 = 6,
        Plane2 = 7,
        MemoryPlane0 = 8,
        MemoryPlane1 = 9,
        MemoryPlane2 = 10,
        MemoryPlane3 = 11
    };

    enum class VqImageCompressionFixedRateBit : uint8_t {
        _1bpc = 1,
        _2bpc = 2,
        _3bpc = 3,
        _4bpc = 4,
        _5bpc = 5,
        _6bpc = 6,
        _7bpc = 7,
        _8bpc = 8,
        _9bpc = 9,
        _10bpc = 10,
        _11bpc = 11,
        _12bpc = 12,
        _13bpc = 13,
        _14bpc = 14,
        _15bpc = 15,
        _16bpc = 16,
        _17bpc = 17,
        _18bpc = 18,
        _19bpc = 19,
        _20bpc = 20,
        _21bpc = 21,
        _22bpc = 22,
        _23bpc = 23,
        _24bpc = 24
    };

    enum class VqImageCompressionBit : uint8_t {
        Default = 0,
        FixedRateDefault = 1,
        FixedRateExplicit = 2,
        Disabled = 3
    };

    enum class VqImageCreateBit : uint8_t {
        SparseBinding = 1,
        SparseResidency = 2,
        SparseAliased = 3,
        MutableFormat = 4,
        CubeCompatible = 5,
        Alias = 11,
        SplitInstanceBindRegions = 7,
        _2dArrayCompatible = 6,
        BlockTexelViewCompatible = 8,
        ExtendedUsage = 9,
        Protected = 12,
        Disjoint = 10,
        CornerSampled = 14,
        SampleLocationsCompatibleDepth = 13,
        Subsampled = 15,
        DescriptorBufferCaptureReplay = 17,
        MultisampledRenderToSingleSampled = 19,
        _2dViewCompatible = 18,
        FragmentDensityMapOffset = 16,
        VideoProfileIndependent = 21
    };

    enum class VqImageLayout : int32_t {
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
        PresentSrc = 1000001002,
        VideoDecodeDst = 1000024000,
        VideoDecodeSrc = 1000024001,
        VideoDecodeDpb = 1000024002,
        SharedPresent = 1000111000,
        FragmentDensityMapOptimal = 1000218000,
        FragmentShadingRateAttachmentOptimal = 1000164003,
        RenderingLocalRead = 1000232000,
        VideoEncodeDst = 1000299000,
        VideoEncodeSrc = 1000299001,
        VideoEncodeDpb = 1000299002,
        AttachmentFeedbackLoopOptimal = 1000339000,
        ShadingRateOptimal = FragmentShadingRateAttachmentOptimal
    };

    enum class VqImageTiling : int32_t {
        Optimal = 0,
        Linear = 1,
        DrmFormatModifier = 1000158000
    };

    enum class VqImageType : int32_t {
        _1d = 0,
        _2d = 1,
        _3d = 2
    };

    enum class VqImageUsageBit : uint8_t {
        TransferSrc = 1,
        TransferDst = 2,
        Sampled = 3,
        Storage = 4,
        ColorAttachment = 5,
        DepthStencilAttachment = 6,
        TransientAttachment = 7,
        InputAttachment = 8,
        VideoDecodeDst = 11,
        VideoDecodeSrc = 12,
        VideoDecodeDpb = 13,
        FragmentDensityMap = 10,
        FragmentShadingRateAttachment = 9,
        HostTransfer = 23,
        VideoEncodeDst = 14,
        VideoEncodeSrc = 15,
        VideoEncodeDpb = 16,
        AttachmentFeedbackLoop = 20,
        InvocationMaskBitHuawei = 19,
        SampleWeight = 21,
        SampleBlockMatch = 22,
        ShadingRateImage = FragmentShadingRateAttachment
    };

    enum class VqImageViewCreateBit : uint8_t {
        FragmentDensityMapDynamic = 1,
        DescriptorBufferCaptureReplay = 3,
        FragmentDensityMapDeferred = 2
    };

    enum class VqImageViewType : int32_t {
        _1d = 0,
        _2d = 1,
        _3d = 2,
        Cube = 3,
        _1dArray = 4,
        _2dArray = 5,
        CubeArray = 6
    };

    enum class VqIndexType : int32_t {
        Uint16 = 0,
        Uint32 = 1,
        None = 1000165000,
        Uint8 = 1000265000
    };

    enum class VqIndirectCommandsLayoutUsageBit : uint8_t {
        ExplicitPreprocess = 1,
        IndexedSequences = 2,
        UnorderedSequences = 3
    };

    enum class VqIndirectCommandsTokenType : int32_t {
        ShaderGroup = 0,
        StateFlags = 1,
        IndexBuffer = 2,
        VertexBuffer = 3,
        PushConstant = 4,
        DrawIndexed = 5,
        Draw = 6,
        DrawTasks = 7,
        DrawMeshTasks = 1000328000,
        Pipeline = 1000428003,
        Dispatch = 1000428004
    };

    enum class VqIndirectStateBit : uint8_t {
        FlagFrontface = 1
    };

    enum class VqInstanceCreateBit : uint8_t {
        EnumeratePortability = 1
    };

    enum class VqInternalAllocationType : int32_t {
        Executable = 0
    };

    enum class VqLatencyMarker : int32_t {
        SimulationStart = 0,
        SimulationEnd = 1,
        RendersubmitStart = 2,
        RendersubmitEnd = 3,
        PresentStart = 4,
        PresentEnd = 5,
        InputSample = 6,
        TriggerFlash = 7,
        OutOfBandRendersubmitStart = 8,
        OutOfBandRendersubmitEnd = 9,
        OutOfBandPresentStart = 10,
        OutOfBandPresentEnd = 11
    };

    enum class VqLayerSettingType : int32_t {
        Bool32 = 0,
        Int32 = 1,
        Int64 = 2,
        Uint32 = 3,
        Uint64 = 4,
        Float32 = 5,
        Float64 = 6,
        String = 7
    };

    enum class VqLayeredDriverUnderlyingApi : int32_t {
        NoneMSFT = 0,
        D3d12MSFT = 1
    };

    enum class VqLineRasterizationMode : int32_t {
        Default = 0,
        Rectangular = 1,
        Bresenham = 2,
        RectangularSmooth = 3
    };

    enum class VqLogicOp : int32_t {
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

    enum class VqMemoryAllocateBit : uint8_t {
        DeviceMask = 1,
        DeviceAddress = 2,
        DeviceAddressCaptureReplay = 3
    };

    enum class VqMemoryHeapBit : uint8_t {
        DeviceLocal = 1,
        MultiInstance = 2
    };

    enum class VqMemoryMapBit : uint8_t {
        Placed = 1
    };

    enum class VqMemoryOverallocationBehavior : int32_t {
        DefaultAMD = 0,
        AllowedAMD = 1,
        DisallowedAMD = 2
    };

    enum class VqMemoryPropertyBit : uint8_t {
        DeviceLocal = 1,
        HostVisible = 2,
        HostCoherent = 3,
        HostCached = 4,
        LazilyAllocated = 5,
        Protected = 6,
        DeviceCoherentBitAMD = 7,
        DeviceUncachedBitAMD = 8,
        RdmaCapable = 9
    };

    enum class VqMemoryUnmapBit : uint8_t {
        Reserve = 1
    };

    enum class VqMicromapCreateBit : uint8_t {
        DeviceAddressCaptureReplay = 1
    };

    enum class VqMicromapType : int32_t {
        OpacityMicromap = 0,
        DisplacementMicromap = 1000397000
    };

    enum class VqObjectType : int32_t {
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
        Surface = 1000000000,
        Swapchain = 1000001000,
        Display = 1000002000,
        DisplayMode = 1000002001,
        DebugReportCallback = 1000011000,
        VideoSession = 1000023000,
        VideoSessionParameters = 1000023001,
        CuModuleNvx = 1000029000,
        CuFunctionNvx = 1000029001,
        DebugUtilsMessenger = 1000128000,
        AccelerationStructure = 1000150000,
        ValidationCache = 1000160000,
        PerformanceConfigurationINTEL = 1000210000,
        DeferredOperation = 1000268000,
        IndirectCommandsLayout = 1000277000,
        CudaModule = 1000307000,
        CudaFunction = 1000307001,
        BufferCollectionFuchsia = 1000366000,
        Micromap = 1000396000,
        OpticalFlowSession = 1000464000,
        Shader = 1000482000
    };

    enum class VqOpacityMicromapFormat : int32_t {
        _2State = 1,
        _4State = 2
    };

    enum class VqOpacityMicromapSpecialIndex : int32_t {
        FullyTransparent = -1,
        FullyOpaque = -2,
        FullyUnknownTransparent = -3,
        FullyUnknownOpaque = -4
    };

    enum class VqOpticalFlowExecuteBit : uint8_t {
        DisableTemporalHints = 1
    };

    enum class VqOpticalFlowGridSizeBit : uint8_t {
        Unknown = 0,
        _1x1 = 1,
        _2x2 = 2,
        _4x4 = 3,
        _8x8 = 4
    };

    enum class VqOpticalFlowPerformanceLevel : int32_t {
        Unknown = 0,
        Slow = 1,
        Medium = 2,
        Fast = 3
    };

    enum class VqOpticalFlowSessionBindingPoint : int32_t {
        Unknown = 0,
        Input = 1,
        Reference = 2,
        Hint = 3,
        FlowVector = 4,
        BackwardFlowVector = 5,
        Cost = 6,
        BackwardCost = 7,
        GlobalFlow = 8
    };

    enum class VqOpticalFlowSessionCreateBit : uint8_t {
        EnableHint = 1,
        EnableCost = 2,
        EnableGlobalFlow = 3,
        AllowRegions = 4,
        BothDirections = 5
    };

    enum class VqOpticalFlowUsageBit : uint8_t {
        Unknown = 0,
        Input = 1,
        Output = 2,
        Hint = 3,
        Cost = 4,
        GlobalFlow = 5
    };

    enum class VqOutOfBandQueueType : int32_t {
        Render = 0,
        Present = 1
    };

    enum class VqPeerMemoryFeatureBit : uint8_t {
        CopySrc = 1,
        CopyDst = 2,
        GenericSrc = 3,
        GenericDst = 4
    };

    enum class VqPerformanceConfigurationType : int32_t {
        CommandQueueMetricsDiscoveryActivatedINTEL = 0
    };

    enum class VqPerformanceCounterDescriptionBit : uint8_t {
        PerformanceImpacting = 1,
        ConcurrentlyImpacted = 2
    };

    enum class VqPerformanceCounterScope : int32_t {
        CommandBuffer = 0,
        RenderPass = 1,
        Command = 2,
        QueryScopeCommandBuffer = CommandBuffer,
        QueryScopeRenderPass = RenderPass,
        QueryScopeCommand = Command
    };

    enum class VqPerformanceCounterStorage : int32_t {
        Int32 = 0,
        Int64 = 1,
        Uint32 = 2,
        Uint64 = 3,
        Float32 = 4,
        Float64 = 5
    };

    enum class VqPerformanceCounterUnit : int32_t {
        Generic = 0,
        Percentage = 1,
        Nanoseconds = 2,
        Bytes = 3,
        BytesPerSecond = 4,
        Kelvin = 5,
        Watts = 6,
        Volts = 7,
        Amps = 8,
        Hertz = 9,
        Cycles = 10
    };

    enum class VqPerformanceOverrideType : int32_t {
        NullHardwareINTEL = 0,
        FlushGpuCachesINTEL = 1
    };

    enum class VqPerformanceParameterType : int32_t {
        HwCountersSupportedINTEL = 0,
        StreamMarkerValidBitsINTEL = 1
    };

    enum class VqPerformanceValueType : int32_t {
        Uint32INTEL = 0,
        Uint64INTEL = 1,
        FloatINTEL = 2,
        BoolINTEL = 3,
        StringINTEL = 4
    };

    enum class VqPhysicalDeviceLayeredApi : int32_t {
        Vulkan = 0,
        D3d12 = 1,
        Metal = 2,
        Opengl = 3,
        Opengles = 4
    };

    enum class VqPhysicalDeviceType : int32_t {
        Other = 0,
        IntegratedGpu = 1,
        DiscreteGpu = 2,
        VirtualGpu = 3,
        Cpu = 4
    };

    enum class VqPipelineBindPoint : int32_t {
        Graphics = 0,
        Compute = 1,
        ExecutionGraphAmdx = 1000134000,
        RayTracing = 1000165000,
        SubpassShadingHuawei = 1000369003
    };

    enum class VqPipelineCacheCreateBit : uint8_t {
        ExternallySynchronized = 1
    };

    enum class VqPipelineCacheHeaderVersion : int32_t {
        One = 1
    };

    enum class VqPipelineColorBlendStateCreateBit : uint8_t {
        RasterizationOrderAttachmentAccess = 1,
        RasterizationOrderAttachmentAccessBitArm = RasterizationOrderAttachmentAccess
    };

    enum class VqPipelineCompilerControlBit : uint8_t {

    };

    enum class VqPipelineCreateBit : uint8_t {
        DisableOptimization = 1,
        AllowDerivatives = 2,
        Derivative = 3,
        ViewIndexFromDeviceIndex = 4,
        DispatchBase = 5,
        FailOnPipelineCompileRequired = 9,
        EarlyReturnOnFailure = 10,
        RenderingFragmentShadingRateAttachment = 22,
        RenderingFragmentDensityMapAttachment = 23,
        RayTracingNoNullAnyHitShaders = 15,
        RayTracingNoNullClosestHitShaders = 16,
        RayTracingNoNullMissShaders = 17,
        RayTracingNoNullIntersectionShaders = 18,
        RayTracingSkipTriangles = 13,
        RayTracingSkipAabbs = 14,
        RayTracingShaderGroupHandleCaptureReplay = 20,
        DeferCompile = 6,
        CaptureStatistics = 7,
        CaptureInternalRepresentations = 8,
        IndirectBindable = 19,
        Library = 12,
        DescriptorBuffer = 30,
        RetainLinkTimeOptimizationInfo = 24,
        LinkTimeOptimization = 11,
        RayTracingAllowMotion = 21,
        ColorAttachmentFeedbackLoop = 26,
        DepthStencilAttachmentFeedbackLoop = 27,
        RayTracingOpacityMicromap = 25,
        RayTracingDisplacementMicromap = 29,
        NoProtectedAccess = 28,
        ProtectedAccessOnly = 31,
        PipelineRasterizationStateCreateFragmentShadingRateAttachment = RenderingFragmentShadingRateAttachment,
        PipelineRasterizationStateCreateFragmentDensityMapAttachment = RenderingFragmentDensityMapAttachment
    };

    enum class VqPipelineCreationFeedbackBit : uint8_t {
        Valid = 1,
        ApplicationPipelineCacheHit = 2,
        BasePipelineAcceleration = 3
    };

    enum class VqPipelineDepthStencilStateCreateBit : uint8_t {
        RasterizationOrderAttachmentDepthAccess = 1,
        RasterizationOrderAttachmentStencilAccess = 2,
        RasterizationOrderAttachmentDepthAccessBitArm = RasterizationOrderAttachmentDepthAccess,
        RasterizationOrderAttachmentStencilAccessBitArm = RasterizationOrderAttachmentStencilAccess
    };

    enum class VqPipelineExecutableStatisticFormat : int32_t {
        Bool32 = 0,
        Int64 = 1,
        Uint64 = 2,
        Float64 = 3
    };

    enum class VqPipelineLayoutCreateBit : uint8_t {
        IndependentSets = 2
    };

    enum class VqPipelineRobustnessBufferBehavior : int32_t {
        DeviceDefault = 0,
        Disabled = 1,
        RobustBufferAccess = 2,
        RobustBufferAccess2 = 3
    };

    enum class VqPipelineRobustnessImageBehavior : int32_t {
        DeviceDefault = 0,
        Disabled = 1,
        RobustImageAccess = 2,
        RobustImageAccess2 = 3
    };

    enum class VqPipelineShaderStageCreateBit : uint8_t {
        AllowVaryingSubgroupSize = 1,
        RequireFullSubgroups = 2
    };

    enum class VqPipelineStageBit : uint8_t {
        TopOfPipe = 1,
        DrawIndirect = 2,
        VertexInput = 3,
        VertexShader = 4,
        TessellationControlShader = 5,
        TessellationEvaluationShader = 6,
        GeometryShader = 7,
        FragmentShader = 8,
        EarlyFragmentTests = 9,
        LateFragmentTests = 10,
        ColorAttachmentOutput = 11,
        ComputeShader = 12,
        Transfer = 13,
        BottomOfPipe = 14,
        Host = 15,
        AllGraphics = 16,
        AllCommands = 17,
        TransformFeedback = 25,
        ConditionalRendering = 19,
        AccelerationStructureBuild = 26,
        RayTracingShader = 22,
        FragmentDensityProcess = 24,
        FragmentShadingRateAttachment = 23,
        CommandPreprocess = 18,
        TaskShader = 20,
        MeshShader = 21,
        ShadingRateImage = FragmentShadingRateAttachment
    };

    enum class VqPointClippingBehavior : int32_t {
        AllClipPlanes = 0,
        UserClipPlanesOnly = 1
    };

    enum class VqPolygonMode : int32_t {
        Fill = 0,
        Line = 1,
        Point = 2,
        FillRectangle = 1000153000
    };

    enum class VqPresentGravityBit : uint8_t {
        Min = 1,
        Max = 2,
        Centered = 3
    };

    enum class VqPresentMode : int32_t {
        Immediate = 0,
        Mailbox = 1,
        Fifo = 2,
        FifoRelaxed = 3,
        SharedDemandRefresh = 1000111000,
        SharedContinuousRefresh = 1000111001
    };

    enum class VqPresentScalingBit : uint8_t {
        OneToOne = 1,
        AspectRatioStretch = 2,
        Stretch = 3
    };

    enum class VqPrimitiveTopology : int32_t {
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

    enum class VqProvokingVertexMode : int32_t {
        FirstVertex = 0,
        LastVertex = 1
    };

    enum class VqQueryControlBit : uint8_t {
        Precise = 1
    };

    enum class VqQueryPipelineStatisticBit : uint8_t {
        InputAssemblyVertices = 1,
        InputAssemblyPrimitives = 2,
        VertexShaderInvocations = 3,
        GeometryShaderInvocations = 4,
        GeometryShaderPrimitives = 5,
        ClippingInvocations = 6,
        ClippingPrimitives = 7,
        FragmentShaderInvocations = 8,
        TessellationControlShaderPatches = 9,
        TessellationEvaluationShaderInvocations = 10,
        ComputeShaderInvocations = 11,
        TaskShaderInvocations = 12,
        MeshShaderInvocations = 13,
        ClusterCullingShaderInvocationsBitHuawei = 14
    };

    enum class VqQueryPoolSamplingMode : int32_t {
        ManualINTEL = 0
    };

    enum class VqQueryResultBit : uint8_t {
        _64 = 1,
        Wait = 2,
        WithAvailability = 3,
        Partial = 4,
        WithStatus = 5
    };

    enum class VqQueryResultStatus : int32_t {
        Error = -1,
        NotReady = 0,
        Complete = 1,
        InsufficientBitstreamBufferRange = -1000299000
    };

    enum class VqQueryType : int32_t {
        Occlusion = 0,
        PipelineStatistics = 1,
        Timestamp = 2,
        ResultStatusOnly = 1000023000,
        TransformFeedbackStream = 1000028004,
        PerformanceQuery = 1000116000,
        AccelerationStructureCompactedSize = 1000150000,
        AccelerationStructureSerializationSize = 1000150001,
        PerformanceQueryINTEL = 1000210000,
        VideoEncodeFeedback = 1000299000,
        MeshPrimitivesGenerated = 1000328000,
        PrimitivesGenerated = 1000382000,
        AccelerationStructureSerializationBottomLevelPointers = 1000386000,
        AccelerationStructureSize = 1000386001,
        MicromapSerializationSize = 1000396000,
        MicromapCompactedSize = 1000396001
    };

    enum class VqQueueBit : uint8_t {
        Graphics = 1,
        Compute = 2,
        Transfer = 3,
        SparseBinding = 4,
        Protected = 5,
        VideoDecode = 6,
        VideoEncode = 7,
        OpticalFlow = 9
    };

    enum class VqQueueGlobalPriority : int32_t {
        Low = 128,
        Medium = 256,
        High = 512,
        Realtime = 1024
    };

    enum class VqRasterizationOrder : int32_t {
        StrictAMD = 0,
        RelaxedAMD = 1
    };

    enum class VqRayTracingInvocationReorderMode : int32_t {
        None = 0,
        Reorder = 1
    };

    enum class VqRayTracingShaderGroupType : int32_t {
        General = 0,
        TrianglesHitGroup = 1,
        ProceduralHitGroup = 2
    };

    enum class VqRenderPassCreateBit : uint8_t {
        Transform = 2
    };

    enum class VqRenderingBit : uint8_t {
        ContentsSecondaryCommandBuffers = 1,
        Suspending = 2,
        Resuming = 3,
        EnableLegacyDithering = 4,
        ContentsInline = 5
    };

    enum class VqResolveModeBit : uint8_t {
        SampleZero = 1,
        Average = 2,
        Min = 3,
        Max = 4,
        ExternalFormatDownsampleAndroid = 5
    };

    enum class VqResult : int32_t {
        Success = 0,
        NotReady = 1,
        Timeout = 2,
        EventSet = 3,
        EventReset = 4,
        Incomplete = 5,
        ErrorOutOfHostMemory = -1,
        ErrorOutOfDeviceMemory = -2,
        ErrorInitializationFailed = -3,
        ErrorDeviceLost = -4,
        ErrorMemoryMapFailed = -5,
        ErrorLayerNotPresent = -6,
        ErrorExtensionNotPresent = -7,
        ErrorFeatureNotPresent = -8,
        ErrorIncompatibleDriver = -9,
        ErrorTooManyObjects = -10,
        ErrorFormatNotSupported = -11,
        ErrorFragmentedPool = -12,
        ErrorUnknown = -13,
        ErrorOutOfPoolMemory = -1000069000,
        ErrorInvalidExternalHandle = -1000072003,
        ErrorFragmentation = -1000161000,
        ErrorInvalidOpaqueCaptureAddress = -1000257000,
        PipelineCompileRequired = 1000297000,
        ErrorSurfaceLost = -1000000000,
        ErrorNativeWindowInUse = -1000000001,
        Suboptimal = 1000001003,
        ErrorOutOfDate = -1000001004,
        ErrorIncompatibleDisplay = -1000003001,
        ErrorValidationFailed = -1000011001,
        ErrorInvalidShader = -1000012000,
        ErrorImageUsageNotSupported = -1000023000,
        ErrorVideoPictureLayoutNotSupported = -1000023001,
        ErrorVideoProfileOperationNotSupported = -1000023002,
        ErrorVideoProfileFormatNotSupported = -1000023003,
        ErrorVideoProfileCodecNotSupported = -1000023004,
        ErrorVideoStdVersionNotSupported = -1000023005,
        ErrorInvalidDrmFormatModifierPlaneLayout = -1000158000,
        ErrorNotPermitted = -1000174001,
        ErrorFullScreenExclusiveModeLost = -1000255000,
        ThreadIdle = 1000268000,
        ThreadDone = 1000268001,
        OperationDeferred = 1000268002,
        OperationNotDeferred = 1000268003,
        ErrorInvalidVideoStdParameters = -1000299000,
        ErrorCompressionExhausted = -1000338000,
        IncompatibleShaderBinary = 1000482000,
        ErrorInvalidDeviceAddress = ErrorInvalidOpaqueCaptureAddress,
        ErrorPipelineCompileRequired = PipelineCompileRequired,
        ErrorIncompatibleShaderBinary = IncompatibleShaderBinary
    };

    enum class VqSampleCountBit : uint8_t {
        _1 = 1,
        _2 = 2,
        _4 = 3,
        _8 = 4,
        _16 = 5,
        _32 = 6,
        _64 = 7
    };

    enum class VqSamplerAddressMode : int32_t {
        Repeat = 0,
        MirroredRepeat = 1,
        ClampToEdge = 2,
        ClampToBorder = 3,
        MirrorClampToEdge = 4
    };

    enum class VqSamplerCreateBit : uint8_t {
        Subsampled = 1,
        SubsampledCoarseReconstruction = 2,
        DescriptorBufferCaptureReplay = 4,
        NonSeamlessCubeMap = 3,
        ImageProcessing = 5
    };

    enum class VqSamplerMipmapMode : int32_t {
        Nearest = 0,
        Linear = 1
    };

    enum class VqSamplerReductionMode : int32_t {
        WeightedAverage = 0,
        Min = 1,
        Max = 2,
        WeightedAverageRangeclamp = 1000521000
    };

    enum class VqSamplerYcbcrModelConversion : int32_t {
        RgbIdentity = 0,
        YcbcrIdentity = 1,
        Ycbcr709 = 2,
        Ycbcr601 = 3,
        Ycbcr2020 = 4
    };

    enum class VqSamplerYcbcrRange : int32_t {
        ItuFull = 0,
        ItuNarrow = 1
    };

    enum class VqScope : int32_t {
        Device = 1,
        Workgroup = 2,
        Subgroup = 3,
        QueueFamily = 5
    };

    enum class VqSemaphoreImportBit : uint8_t {
        Temporary = 1
    };

    enum class VqSemaphoreType : int32_t {
        Binary = 0,
        Timeline = 1
    };

    enum class VqSemaphoreWaitBit : uint8_t {
        Any = 1
    };

    enum class VqShaderCodeType : int32_t {
        Binary = 0,
        Spirv = 1
    };

    enum class VqShaderCorePropertiesBit : uint8_t {

    };

    enum class VqShaderCreateBit : uint8_t {
        LinkStage = 1,
        AllowVaryingSubgroupSize = 2,
        RequireFullSubgroups = 3,
        NoTaskShader = 4,
        DispatchBase = 5,
        FragmentShadingRateAttachment = 6,
        FragmentDensityMapAttachment = 7
    };

    enum class VqShaderFloatControlsIndependence : int32_t {
        _32BitOnly = 0,
        All = 1,
        None = 2
    };

    enum class VqShaderGroupShader : int32_t {
        General = 0,
        ClosestHit = 1,
        AnyHit = 2,
        Intersection = 3
    };

    enum class VqShaderInfoType : int32_t {
        StatisticsAMD = 0,
        BinaryAMD = 1,
        DisassemblyAMD = 2
    };

    enum class VqShaderStageBit : uint8_t {
        Vertex = 1,
        TessellationControl = 2,
        TessellationEvaluation = 3,
        Geometry = 4,
        Fragment = 5,
        Compute = 6,
        AllGraphics = 5,
        All = 31,
        Raygen = 9,
        AnyHit = 10,
        ClosestHit = 11,
        Miss = 12,
        Intersection = 13,
        Callable = 14,
        Task = 7,
        Mesh = 8,
        SubpassShadingBitHuawei = 15,
        ClusterCullingBitHuawei = 20
    };

    enum class VqShadingRatePaletteEntry : int32_t {
        NoInvocations = 0,
        _16InvocationsPerPixel = 1,
        _8InvocationsPerPixel = 2,
        _4InvocationsPerPixel = 3,
        _2InvocationsPerPixel = 4,
        _1InvocationPerPixel = 5,
        _1InvocationPer2x1Pixels = 6,
        _1InvocationPer1x2Pixels = 7,
        _1InvocationPer2x2Pixels = 8,
        _1InvocationPer4x2Pixels = 9,
        _1InvocationPer2x4Pixels = 10,
        _1InvocationPer4x4Pixels = 11
    };

    enum class VqSharingMode : int32_t {
        Exclusive = 0,
        Concurrent = 1
    };

    enum class VqSparseImageFormatBit : uint8_t {
        SingleMiptail = 1,
        AlignedMipSize = 2,
        NonstandardBlockSize = 3
    };

    enum class VqSparseMemoryBindBit : uint8_t {
        Metadata = 1
    };

    enum class VqStencilFaceBit : uint8_t {
        Front = 1,
        Back = 2,
        FrontAndBack = 2,
        StencilFrontAndBack = FrontAndBack
    };

    enum class VqStencilOp : int32_t {
        Keep = 0,
        Zero = 1,
        Replace = 2,
        IncrementAndClamp = 3,
        DecrementAndClamp = 4,
        Invert = 5,
        IncrementAndWrap = 6,
        DecrementAndWrap = 7
    };

    enum class VqSubgroupFeatureBit : uint8_t {
        Basic = 1,
        Vote = 2,
        Arithmetic = 3,
        Ballot = 4,
        Shuffle = 5,
        ShuffleRelative = 6,
        Clustered = 7,
        Quad = 8,
        Partitioned = 9,
        Rotate = 10,
        RotateClustered = 11
    };

    enum class VqSubmitBit : uint8_t {
        Protected = 1
    };

    enum class VqSubpassContents : int32_t {
        Inline = 0,
        SecondaryCommandBuffers = 1,
        InlineAndSecondaryCommandBuffers = 1000451000
    };

    enum class VqSubpassDescriptionBit : uint8_t {
        PerViewAttributesBitNvx = 1,
        PerViewPositionXOnlyBitNvx = 2,
        FragmentRegion = 3,
        ShaderResolve = 4,
        RasterizationOrderAttachmentColorAccess = 5,
        RasterizationOrderAttachmentDepthAccess = 6,
        RasterizationOrderAttachmentStencilAccess = 7,
        EnableLegacyDithering = 8,
        RasterizationOrderAttachmentColorAccessBitArm = RasterizationOrderAttachmentColorAccess,
        RasterizationOrderAttachmentDepthAccessBitArm = RasterizationOrderAttachmentDepthAccess,
        RasterizationOrderAttachmentStencilAccessBitArm = RasterizationOrderAttachmentStencilAccess
    };

    enum class VqSubpassMergeStatus : int32_t {
        Merged = 0,
        Disallowed = 1,
        NotMergedSideEffects = 2,
        NotMergedSamplesMismatch = 3,
        NotMergedViewsMismatch = 4,
        NotMergedAliasing = 5,
        NotMergedDependencies = 6,
        NotMergedIncompatibleInputAttachment = 7,
        NotMergedTooManyAttachments = 8,
        NotMergedInsufficientStorage = 9,
        NotMergedDepthStencilCount = 10,
        NotMergedResolveAttachmentReuse = 11,
        NotMergedSingleSubpass = 12,
        NotMergedUnspecified = 13
    };

    enum class VqSurfaceCounterBit : uint8_t {
        Vblank = 1
    };

    enum class VqSurfaceTransformBit : uint8_t {
        Identity = 1,
        Rotate90 = 2,
        Rotate180 = 3,
        Rotate270 = 4,
        HorizontalMirror = 5,
        HorizontalMirrorRotate90 = 6,
        HorizontalMirrorRotate180 = 7,
        HorizontalMirrorRotate270 = 8,
        Inherit = 9
    };

    enum class VqSwapchainCreateBit : uint8_t {
        SplitInstanceBindRegions = 1,
        Protected = 2,
        MutableFormat = 3,
        DeferredMemoryAllocation = 4
    };

    enum class VqSystemAllocationScope : int32_t {
        Command = 0,
        Object = 1,
        Cache = 2,
        Device = 3,
        Instance = 4
    };

    enum class VqTessellationDomainOrigin : int32_t {
        UpperLeft = 0,
        LowerLeft = 1
    };

    enum class VqTimeDomain : int32_t {
        Device = 0,
        ClockMonotonic = 1,
        ClockMonotonicRaw = 2,
        QueryPerformanceCounter = 3
    };

    enum class VqToolPurposeBit : uint8_t {
        Validation = 1,
        Profiling = 2,
        Tracing = 3,
        AdditionalFeatures = 4,
        ModifyingFeatures = 5,
        DebugReporting = 6,
        DebugMarkers = 7
    };

    enum class VqValidationCacheHeaderVersion : int32_t {
        One = 1
    };

    enum class VqValidationCheck : int32_t {
        All = 0,
        Shaders = 1
    };

    enum class VqValidationFeatureDisable : int32_t {
        All = 0,
        Shaders = 1,
        ThreadSafety = 2,
        ApiParameters = 3,
        ObjectLifetimes = 4,
        CoreChecks = 5,
        UniqueHandles = 6,
        ShaderValidationCache = 7
    };

    enum class VqValidationFeatureEnable : int32_t {
        GpuAssisted = 0,
        GpuAssistedReserveBindingSlot = 1,
        BestPractices = 2,
        DebugPrintf = 3,
        SynchronizationValidation = 4
    };

    enum class VqVendorId : int32_t {
        Khronos = 0x10000,
        Viv = 0x10001,
        Vsi = 0x10002,
        Kazan = 0x10003,
        Codeplay = 0x10004,
        Mesa = 0x10005,
        Pocl = 0x10006,
        Mobileye = 0x10007
    };

    enum class VqVertexInputRate : int32_t {
        Vertex = 0,
        Instance = 1
    };

    enum class VqVideoCapabilityBit : uint8_t {
        ProtectedContent = 1,
        SeparateReferenceImages = 2
    };

    enum class VqVideoChromaSubsamplingBit : uint8_t {
        Invalid = 0,
        Monochrome = 1,
        _420 = 2,
        _422 = 3,
        _444 = 4
    };

    enum class VqVideoCodecOperationBit : uint8_t {
        EncodeH264 = 17,
        EncodeH265 = 18,
        DecodeH264 = 1,
        DecodeH265 = 2,
        DecodeAv1 = 3
    };

    enum class VqVideoCodingControlBit : uint8_t {
        Reset = 1,
        EncodeRateControl = 2,
        EncodeQualityLevel = 3
    };

    enum class VqVideoComponentBitDepthBit : uint8_t {
        Invalid = 0,
        _8 = 1,
        _10 = 3,
        _12 = 5
    };

    enum class VqVideoDecodeCapabilityBit : uint8_t {
        DpbAndOutputCoincide = 1,
        DpbAndOutputDistinct = 2
    };

    enum class VqVideoDecodeH264PictureLayoutBit : uint8_t {
        Progressive = 0,
        InterlacedInterleavedLines = 1,
        InterlacedSeparatePlanes = 2
    };

    enum class VqVideoDecodeUsageBit : uint8_t {
        Default = 0,
        Transcoding = 1,
        Offline = 2,
        Streaming = 3
    };

    enum class VqVideoEncodeCapabilityBit : uint8_t {
        PrecedingExternallyEncodedBytes = 1,
        InsufficientBitstreamBufferRangeDetection = 2
    };

    enum class VqVideoEncodeContentBit : uint8_t {
        Default = 0,
        Camera = 1,
        Desktop = 2,
        Rendered = 3
    };

    enum class VqVideoEncodeFeedbackBit : uint8_t {
        BitstreamBufferOffset = 1,
        BitstreamBytesWritten = 2,
        BitstreamHasOverrides = 3
    };

    enum class VqVideoEncodeBit : uint8_t {

    };

    enum class VqVideoEncodeH264CapabilityBit : uint8_t {
        HrdCompliance = 1,
        PredictionWeightTableGenerated = 2,
        RowUnalignedSlice = 3,
        DifferentSliceType = 4,
        BFrameInL0List = 5,
        BFrameInL1List = 6,
        PerPictureTypeMinMaxQp = 7,
        PerSliceConstantQp = 8,
        GeneratePrefixNalu = 9
    };

    enum class VqVideoEncodeH264RateControlBit : uint8_t {
        AttemptHrdCompliance = 1,
        RegularGop = 2,
        ReferencePatternFlat = 3,
        ReferencePatternDyadic = 4,
        TemporalLayerPatternDyadic = 5
    };

    enum class VqVideoEncodeH264StdBit : uint8_t {
        SeparateColorPlane = 1,
        QpprimeYZeroTransformBypass = 2,
        ScalingMatrixPresent = 3,
        ChromaQpIndexOffset = 4,
        SecondChromaQpIndexOffset = 5,
        PicInitQpMinus26 = 6,
        WeightedPred = 7,
        WeightedBipredIdcExplicit = 8,
        WeightedBipredIdcImplicit = 9,
        Transform8x8Mode = 10,
        DirectSpatialMvPredFlagUnset = 11,
        EntropyCodingModeFlagUnset = 12,
        EntropyCodingMode = 13,
        Direct8x8InferenceFlagUnset = 14,
        ConstrainedIntraPred = 15,
        DeblockingFilterDisabled = 16,
        DeblockingFilterEnabled = 17,
        DeblockingFilterPartial = 18,
        SliceQpDelta = 20,
        DifferentSliceQpDelta = 21
    };

    enum class VqVideoEncodeH265CapabilityBit : uint8_t {
        HrdCompliance = 1,
        PredictionWeightTableGenerated = 2,
        RowUnalignedSliceSegment = 3,
        DifferentSliceSegmentType = 4,
        BFrameInL0List = 5,
        BFrameInL1List = 6,
        PerPictureTypeMinMaxQp = 7,
        PerSliceSegmentConstantQp = 8,
        MultipleTilesPerSliceSegment = 9,
        MultipleSliceSegmentsPerTile = 10
    };

    enum class VqVideoEncodeH265CtbSizeBit : uint8_t {
        _16 = 1,
        _32 = 2,
        _64 = 3
    };

    enum class VqVideoEncodeH265RateControlBit : uint8_t {
        AttemptHrdCompliance = 1,
        RegularGop = 2,
        ReferencePatternFlat = 3,
        ReferencePatternDyadic = 4,
        TemporalSubLayerPatternDyadic = 5
    };

    enum class VqVideoEncodeH265StdBit : uint8_t {
        SeparateColorPlane = 1,
        SampleAdaptiveOffsetEnabled = 2,
        ScalingListDataPresent = 3,
        PcmEnabled = 4,
        SpsTemporalMvpEnabled = 5,
        InitQpMinus26 = 6,
        WeightedPred = 7,
        WeightedBipred = 8,
        Log2ParallelMergeLevelMinus2 = 9,
        SignDataHidingEnabled = 10,
        TransformSkipEnabled = 11,
        TransformSkipEnabledFlagUnset = 12,
        PpsSliceChromaQpOffsetsPresent = 13,
        TransquantBypassEnabled = 14,
        ConstrainedIntraPred = 15,
        EntropyCodingSyncEnabled = 16,
        DeblockingFilterOverrideEnabled = 17,
        DependentSliceSegmentsEnabled = 18,
        DependentSliceSegment = 19,
        SliceQpDelta = 20,
        DifferentSliceQpDelta = 21
    };

    enum class VqVideoEncodeH265TransformBlockSizeBit : uint8_t {
        _4 = 1,
        _8 = 2,
        _16 = 3,
        _32 = 4
    };

    enum class VqVideoEncodeRateControlModeBit : uint8_t {
        Default = 0,
        Disabled = 1,
        Cbr = 2,
        Vbr = 3
    };

    enum class VqVideoEncodeTuningMode : int32_t {
        Default = 0,
        HighQuality = 1,
        LowLatency = 2,
        UltraLowLatency = 3,
        Lossless = 4
    };

    enum class VqVideoEncodeUsageBit : uint8_t {
        Default = 0,
        Transcoding = 1,
        Streaming = 2,
        Recording = 3,
        Conferencing = 4
    };

    enum class VqVideoSessionCreateBit : uint8_t {
        ProtectedContent = 1,
        AllowEncodeParameterOptimizations = 2,
        InlineQueries = 3
    };

    enum class VqViewportCoordinateSwizzle : int32_t {
        PositiveX = 0,
        NegativeX = 1,
        PositiveY = 2,
        NegativeY = 3,
        PositiveZ = 4,
        NegativeZ = 5,
        PositiveW = 6,
        NegativeW = 7
    };


    using VqAccelerationStructureCreateFlags = Flags<VqAccelerationStructureCreateBit>;
    using VqAccessFlags = Flags<VqAccessBit>;
    using VqAcquireProfilingLockFlags = Flags<VqAcquireProfilingLockBit>;
    using VqAttachmentDescriptionFlags = Flags<VqAttachmentDescriptionBit>;
    using VqBufferCreateFlags = Flags<VqBufferCreateBit>;
    using VqBufferUsageFlags = Flags<VqBufferUsageBit>;
    using VqBuildAccelerationStructureFlags = Flags<VqBuildAccelerationStructureBit>;
    using VqBuildMicromapFlags = Flags<VqBuildMicromapBit>;
    using VqColorComponentFlags = Flags<VqColorComponentBit>;
    using VqCommandBufferResetFlags = Flags<VqCommandBufferResetBit>;
    using VqCommandBufferUsageFlags = Flags<VqCommandBufferUsageBit>;
    using VqCommandPoolCreateFlags = Flags<VqCommandPoolCreateBit>;
    using VqCommandPoolResetFlags = Flags<VqCommandPoolResetBit>;
    using VqCompositeAlphaFlags = Flags<VqCompositeAlphaBit>;
    using VqConditionalRenderingFlags = Flags<VqConditionalRenderingBit>;
    using VqCullModeFlags = Flags<VqCullModeBit>;
    using VqDebugReportFlags = Flags<VqDebugReportBit>;
    using VqDebugUtilsMessageSeverityFlags = Flags<VqDebugUtilsMessageSeverityBit>;
    using VqDebugUtilsMessageTypeFlags = Flags<VqDebugUtilsMessageTypeBit>;
    using VqDependencyFlags = Flags<VqDependencyBit>;
    using VqDescriptorBindingFlags = Flags<VqDescriptorBindingBit>;
    using VqDescriptorPoolCreateFlags = Flags<VqDescriptorPoolCreateBit>;
    using VqDescriptorSetLayoutCreateFlags = Flags<VqDescriptorSetLayoutCreateBit>;
    using VqDeviceAddressBindingFlags = Flags<VqDeviceAddressBindingBit>;
    using VqDeviceDiagnosticsConfigFlags = Flags<VqDeviceDiagnosticsConfigBit>;
    using VqDeviceGroupPresentModeFlags = Flags<VqDeviceGroupPresentModeBit>;
    using VqDeviceQueueCreateFlags = Flags<VqDeviceQueueCreateBit>;
    using VqDisplayPlaneAlphaFlags = Flags<VqDisplayPlaneAlphaBit>;
    using VqEventCreateFlags = Flags<VqEventCreateBit>;
    using VqExternalFenceFeatureFlags = Flags<VqExternalFenceFeatureBit>;
    using VqExternalFenceHandleTypeFlags = Flags<VqExternalFenceHandleTypeBit>;
    using VqExternalMemoryFeatureFlags = Flags<VqExternalMemoryFeatureBit>;
    using VqExternalMemoryFeatureFlags = Flags<VqExternalMemoryFeatureBit>;
    using VqExternalMemoryHandleTypeFlags = Flags<VqExternalMemoryHandleTypeBit>;
    using VqExternalMemoryHandleTypeFlags = Flags<VqExternalMemoryHandleTypeBit>;
    using VqExternalSemaphoreFeatureFlags = Flags<VqExternalSemaphoreFeatureBit>;
    using VqExternalSemaphoreHandleTypeFlags = Flags<VqExternalSemaphoreHandleTypeBit>;
    using VqFenceCreateFlags = Flags<VqFenceCreateBit>;
    using VqFenceImportFlags = Flags<VqFenceImportBit>;
    using VqFormatFeatureFlags = Flags<VqFormatFeatureBit>;
    using VqFrameBoundaryFlags = Flags<VqFrameBoundaryBit>;
    using VqFramebufferCreateFlags = Flags<VqFramebufferCreateBit>;
    using VqGeometryFlags = Flags<VqGeometryBit>;
    using VqGeometryInstanceFlags = Flags<VqGeometryInstanceBit>;
    using VqGraphicsPipelineLibraryFlags = Flags<VqGraphicsPipelineLibraryBit>;
    using VqHostImageCopyFlags = Flags<VqHostImageCopyBit>;
    using VqImageAspectFlags = Flags<VqImageAspectBit>;
    using VqImageCompressionFixedRateFlags = Flags<VqImageCompressionFixedRateBit>;
    using VqImageCompressionFlags = Flags<VqImageCompressionBit>;
    using VqImageCreateFlags = Flags<VqImageCreateBit>;
    using VqImageUsageFlags = Flags<VqImageUsageBit>;
    using VqImageViewCreateFlags = Flags<VqImageViewCreateBit>;
    using VqIndirectCommandsLayoutUsageFlags = Flags<VqIndirectCommandsLayoutUsageBit>;
    using VqIndirectStateFlags = Flags<VqIndirectStateBit>;
    using VqInstanceCreateFlags = Flags<VqInstanceCreateBit>;
    using VqMemoryAllocateFlags = Flags<VqMemoryAllocateBit>;
    using VqMemoryHeapFlags = Flags<VqMemoryHeapBit>;
    using VqMemoryMapFlags = Flags<VqMemoryMapBit>;
    using VqMemoryPropertyFlags = Flags<VqMemoryPropertyBit>;
    using VqMemoryUnmapFlags = Flags<VqMemoryUnmapBit>;
    using VqMicromapCreateFlags = Flags<VqMicromapCreateBit>;
    using VqOpticalFlowExecuteFlags = Flags<VqOpticalFlowExecuteBit>;
    using VqOpticalFlowGridSizeFlags = Flags<VqOpticalFlowGridSizeBit>;
    using VqOpticalFlowSessionCreateFlags = Flags<VqOpticalFlowSessionCreateBit>;
    using VqOpticalFlowUsageFlags = Flags<VqOpticalFlowUsageBit>;
    using VqPeerMemoryFeatureFlags = Flags<VqPeerMemoryFeatureBit>;
    using VqPerformanceCounterDescriptionFlags = Flags<VqPerformanceCounterDescriptionBit>;
    using VqPipelineCacheCreateFlags = Flags<VqPipelineCacheCreateBit>;
    using VqPipelineColorBlendStateCreateFlags = Flags<VqPipelineColorBlendStateCreateBit>;
    using VqPipelineCompilerControlFlags = Flags<VqPipelineCompilerControlBit>;
    using VqPipelineCreateFlags = Flags<VqPipelineCreateBit>;
    using VqPipelineCreationFeedbackFlags = Flags<VqPipelineCreationFeedbackBit>;
    using VqPipelineDepthStencilStateCreateFlags = Flags<VqPipelineDepthStencilStateCreateBit>;
    using VqPipelineLayoutCreateFlags = Flags<VqPipelineLayoutCreateBit>;
    using VqPipelineShaderStageCreateFlags = Flags<VqPipelineShaderStageCreateBit>;
    using VqPipelineStageFlags = Flags<VqPipelineStageBit>;
    using VqPresentGravityFlags = Flags<VqPresentGravityBit>;
    using VqPresentScalingFlags = Flags<VqPresentScalingBit>;
    using VqQueryControlFlags = Flags<VqQueryControlBit>;
    using VqQueryPipelineStatisticFlags = Flags<VqQueryPipelineStatisticBit>;
    using VqQueryResultFlags = Flags<VqQueryResultBit>;
    using VqQueueFlags = Flags<VqQueueBit>;
    using VqRenderPassCreateFlags = Flags<VqRenderPassCreateBit>;
    using VqRenderingFlags = Flags<VqRenderingBit>;
    using VqResolveModeFlags = Flags<VqResolveModeBit>;
    using VqSampleCountFlags = Flags<VqSampleCountBit>;
    using VqSamplerCreateFlags = Flags<VqSamplerCreateBit>;
    using VqSemaphoreImportFlags = Flags<VqSemaphoreImportBit>;
    using VqSemaphoreWaitFlags = Flags<VqSemaphoreWaitBit>;
    using VqShaderCorePropertiesFlags = Flags<VqShaderCorePropertiesBit>;
    using VqShaderCreateFlags = Flags<VqShaderCreateBit>;
    using VqShaderStageFlags = Flags<VqShaderStageBit>;
    using VqSparseImageFormatFlags = Flags<VqSparseImageFormatBit>;
    using VqSparseMemoryBindFlags = Flags<VqSparseMemoryBindBit>;
    using VqStencilFaceFlags = Flags<VqStencilFaceBit>;
    using VqSubgroupFeatureFlags = Flags<VqSubgroupFeatureBit>;
    using VqSubmitFlags = Flags<VqSubmitBit>;
    using VqSubpassDescriptionFlags = Flags<VqSubpassDescriptionBit>;
    using VqSurfaceCounterFlags = Flags<VqSurfaceCounterBit>;
    using VqSurfaceTransformFlags = Flags<VqSurfaceTransformBit>;
    using VqSwapchainCreateFlags = Flags<VqSwapchainCreateBit>;
    using VqToolPurposeFlags = Flags<VqToolPurposeBit>;
    using VqVideoCapabilityFlags = Flags<VqVideoCapabilityBit>;
    using VqVideoChromaSubsamplingFlags = Flags<VqVideoChromaSubsamplingBit>;
    using VqVideoCodecOperationFlags = Flags<VqVideoCodecOperationBit>;
    using VqVideoCodingControlFlags = Flags<VqVideoCodingControlBit>;
    using VqVideoComponentBitDepthFlags = Flags<VqVideoComponentBitDepthBit>;
    using VqVideoDecodeCapabilityFlags = Flags<VqVideoDecodeCapabilityBit>;
    using VqVideoDecodeH264PictureLayoutFlags = Flags<VqVideoDecodeH264PictureLayoutBit>;
    using VqVideoDecodeUsageFlags = Flags<VqVideoDecodeUsageBit>;
    using VqVideoEncodeCapabilityFlags = Flags<VqVideoEncodeCapabilityBit>;
    using VqVideoEncodeContentFlags = Flags<VqVideoEncodeContentBit>;
    using VqVideoEncodeFeedbackFlags = Flags<VqVideoEncodeFeedbackBit>;
    using VqVideoEncodeFlags = Flags<VqVideoEncodeBit>;
    using VqVideoEncodeH264CapabilityFlags = Flags<VqVideoEncodeH264CapabilityBit>;
    using VqVideoEncodeH264RateControlFlags = Flags<VqVideoEncodeH264RateControlBit>;
    using VqVideoEncodeH264StdFlags = Flags<VqVideoEncodeH264StdBit>;
    using VqVideoEncodeH265CapabilityFlags = Flags<VqVideoEncodeH265CapabilityBit>;
    using VqVideoEncodeH265CtbSizeFlags = Flags<VqVideoEncodeH265CtbSizeBit>;
    using VqVideoEncodeH265RateControlFlags = Flags<VqVideoEncodeH265RateControlBit>;
    using VqVideoEncodeH265StdFlags = Flags<VqVideoEncodeH265StdBit>;
    using VqVideoEncodeH265TransformBlockSizeFlags = Flags<VqVideoEncodeH265TransformBlockSizeBit>;
    using VqVideoEncodeRateControlModeFlags = Flags<VqVideoEncodeRateControlModeBit>;
    using VqVideoEncodeUsageFlags = Flags<VqVideoEncodeUsageBit>;
    using VqVideoSessionCreateFlags = Flags<VqVideoSessionCreateBit>;

    std::string_view    to_string_view(VqAccelerationStructureBuildType);
    std::string_view    to_string_view(VqAccelerationStructureCompatibility);
    std::string_view    to_string_view(VqAccelerationStructureCreateBit);
    std::string_view    to_string_view(VqAccelerationStructureMemoryRequirementsType);
    std::string_view    to_string_view(VqAccelerationStructureMotionInstanceType);
    std::string_view    to_string_view(VqAccelerationStructureType);
    std::string_view    to_string_view(VqAccessBit);
    std::string_view    to_string_view(VqAcquireProfilingLockBit);
    std::string_view    to_string_view(VqAttachmentDescriptionBit);
    std::string_view    to_string_view(VqAttachmentLoadOp);
    std::string_view    to_string_view(VqAttachmentStoreOp);
    std::string_view    to_string_view(VqBlendFactor);
    std::string_view    to_string_view(VqBlendOp);
    std::string_view    to_string_view(VqBlendOverlap);
    std::string_view    to_string_view(VqBlockMatchWindowCompareMode);
    std::string_view    to_string_view(VqBorderColor);
    std::string_view    to_string_view(VqBufferCreateBit);
    std::string_view    to_string_view(VqBufferUsageBit);
    std::string_view    to_string_view(VqBuildAccelerationStructureBit);
    std::string_view    to_string_view(VqBuildAccelerationStructureMode);
    std::string_view    to_string_view(VqBuildMicromapBit);
    std::string_view    to_string_view(VqBuildMicromapMode);
    std::string_view    to_string_view(VqChromaLocation);
    std::string_view    to_string_view(VqCoarseSampleOrderType);
    std::string_view    to_string_view(VqColorComponentBit);
    std::string_view    to_string_view(VqColorSpace);
    std::string_view    to_string_view(VqCommandBufferLevel);
    std::string_view    to_string_view(VqCommandBufferResetBit);
    std::string_view    to_string_view(VqCommandBufferUsageBit);
    std::string_view    to_string_view(VqCommandPoolCreateBit);
    std::string_view    to_string_view(VqCommandPoolResetBit);
    std::string_view    to_string_view(VqCompareOp);
    std::string_view    to_string_view(VqComponentSwizzle);
    std::string_view    to_string_view(VqComponentType);
    std::string_view    to_string_view(VqCompositeAlphaBit);
    std::string_view    to_string_view(VqConditionalRenderingBit);
    std::string_view    to_string_view(VqConservativeRasterizationMode);
    std::string_view    to_string_view(VqCopyAccelerationStructureMode);
    std::string_view    to_string_view(VqCopyMicromapMode);
    std::string_view    to_string_view(VqCoverageModulationMode);
    std::string_view    to_string_view(VqCoverageReductionMode);
    std::string_view    to_string_view(VqCubicFilterWeights);
    std::string_view    to_string_view(VqCullModeBit);
    std::string_view    to_string_view(VqDebugReportBit);
    std::string_view    to_string_view(VqDebugReportObjectType);
    std::string_view    to_string_view(VqDebugUtilsMessageSeverityBit);
    std::string_view    to_string_view(VqDebugUtilsMessageTypeBit);
    std::string_view    to_string_view(VqDependencyBit);
    std::string_view    to_string_view(VqDepthBiasRepresentation);
    std::string_view    to_string_view(VqDescriptorBindingBit);
    std::string_view    to_string_view(VqDescriptorPoolCreateBit);
    std::string_view    to_string_view(VqDescriptorSetLayoutCreateBit);
    std::string_view    to_string_view(VqDescriptorType);
    std::string_view    to_string_view(VqDescriptorUpdateTemplateType);
    std::string_view    to_string_view(VqDeviceAddressBindingBit);
    std::string_view    to_string_view(VqDeviceAddressBindingType);
    std::string_view    to_string_view(VqDeviceDiagnosticsConfigBit);
    std::string_view    to_string_view(VqDeviceEventType);
    std::string_view    to_string_view(VqDeviceFaultAddressType);
    std::string_view    to_string_view(VqDeviceFaultVendorBinaryHeaderVersion);
    std::string_view    to_string_view(VqDeviceGroupPresentModeBit);
    std::string_view    to_string_view(VqDeviceMemoryReportEventType);
    std::string_view    to_string_view(VqDeviceQueueCreateBit);
    std::string_view    to_string_view(VqDirectDriverLoadingMode);
    std::string_view    to_string_view(VqDiscardRectangleMode);
    std::string_view    to_string_view(VqDisplayEventType);
    std::string_view    to_string_view(VqDisplayPlaneAlphaBit);
    std::string_view    to_string_view(VqDisplayPowerState);
    std::string_view    to_string_view(VqDriverId);
    std::string_view    to_string_view(VqDynamicState);
    std::string_view    to_string_view(VqEventCreateBit);
    std::string_view    to_string_view(VqExternalFenceFeatureBit);
    std::string_view    to_string_view(VqExternalFenceHandleTypeBit);
    std::string_view    to_string_view(VqExternalMemoryFeatureBit);
    std::string_view    to_string_view(VqExternalMemoryHandleTypeBit);
    std::string_view    to_string_view(VqExternalSemaphoreFeatureBit);
    std::string_view    to_string_view(VqExternalSemaphoreHandleTypeBit);
    std::string_view    to_string_view(VqFenceCreateBit);
    std::string_view    to_string_view(VqFenceImportBit);
    std::string_view    to_string_view(VqFilter);
    std::string_view    to_string_view(VqFormat);
    std::string_view    to_string_view(VqFormatFeatureBit);
    std::string_view    to_string_view(VqFragmentShadingRate);
    std::string_view    to_string_view(VqFragmentShadingRateCombinerOp);
    std::string_view    to_string_view(VqFragmentShadingRateType);
    std::string_view    to_string_view(VqFrameBoundaryBit);
    std::string_view    to_string_view(VqFramebufferCreateBit);
    std::string_view    to_string_view(VqFrontFace);
    std::string_view    to_string_view(VqGeometryBit);
    std::string_view    to_string_view(VqGeometryInstanceBit);
    std::string_view    to_string_view(VqGeometryType);
    std::string_view    to_string_view(VqGraphicsPipelineLibraryBit);
    std::string_view    to_string_view(VqHostImageCopyBit);
    std::string_view    to_string_view(VqImageAspectBit);
    std::string_view    to_string_view(VqImageCompressionFixedRateBit);
    std::string_view    to_string_view(VqImageCompressionBit);
    std::string_view    to_string_view(VqImageCreateBit);
    std::string_view    to_string_view(VqImageLayout);
    std::string_view    to_string_view(VqImageTiling);
    std::string_view    to_string_view(VqImageType);
    std::string_view    to_string_view(VqImageUsageBit);
    std::string_view    to_string_view(VqImageViewCreateBit);
    std::string_view    to_string_view(VqImageViewType);
    std::string_view    to_string_view(VqIndexType);
    std::string_view    to_string_view(VqIndirectCommandsLayoutUsageBit);
    std::string_view    to_string_view(VqIndirectCommandsTokenType);
    std::string_view    to_string_view(VqIndirectStateBit);
    std::string_view    to_string_view(VqInstanceCreateBit);
    std::string_view    to_string_view(VqInternalAllocationType);
    std::string_view    to_string_view(VqLatencyMarker);
    std::string_view    to_string_view(VqLayerSettingType);
    std::string_view    to_string_view(VqLayeredDriverUnderlyingApi);
    std::string_view    to_string_view(VqLineRasterizationMode);
    std::string_view    to_string_view(VqLogicOp);
    std::string_view    to_string_view(VqMemoryAllocateBit);
    std::string_view    to_string_view(VqMemoryHeapBit);
    std::string_view    to_string_view(VqMemoryMapBit);
    std::string_view    to_string_view(VqMemoryOverallocationBehavior);
    std::string_view    to_string_view(VqMemoryPropertyBit);
    std::string_view    to_string_view(VqMemoryUnmapBit);
    std::string_view    to_string_view(VqMicromapCreateBit);
    std::string_view    to_string_view(VqMicromapType);
    std::string_view    to_string_view(VqObjectType);
    std::string_view    to_string_view(VqOpacityMicromapFormat);
    std::string_view    to_string_view(VqOpacityMicromapSpecialIndex);
    std::string_view    to_string_view(VqOpticalFlowExecuteBit);
    std::string_view    to_string_view(VqOpticalFlowGridSizeBit);
    std::string_view    to_string_view(VqOpticalFlowPerformanceLevel);
    std::string_view    to_string_view(VqOpticalFlowSessionBindingPoint);
    std::string_view    to_string_view(VqOpticalFlowSessionCreateBit);
    std::string_view    to_string_view(VqOpticalFlowUsageBit);
    std::string_view    to_string_view(VqOutOfBandQueueType);
    std::string_view    to_string_view(VqPeerMemoryFeatureBit);
    std::string_view    to_string_view(VqPerformanceConfigurationType);
    std::string_view    to_string_view(VqPerformanceCounterDescriptionBit);
    std::string_view    to_string_view(VqPerformanceCounterScope);
    std::string_view    to_string_view(VqPerformanceCounterStorage);
    std::string_view    to_string_view(VqPerformanceCounterUnit);
    std::string_view    to_string_view(VqPerformanceOverrideType);
    std::string_view    to_string_view(VqPerformanceParameterType);
    std::string_view    to_string_view(VqPerformanceValueType);
    std::string_view    to_string_view(VqPhysicalDeviceLayeredApi);
    std::string_view    to_string_view(VqPhysicalDeviceType);
    std::string_view    to_string_view(VqPipelineBindPoint);
    std::string_view    to_string_view(VqPipelineCacheCreateBit);
    std::string_view    to_string_view(VqPipelineCacheHeaderVersion);
    std::string_view    to_string_view(VqPipelineColorBlendStateCreateBit);
    std::string_view    to_string_view(VqPipelineCompilerControlBit);
    std::string_view    to_string_view(VqPipelineCreateBit);
    std::string_view    to_string_view(VqPipelineCreationFeedbackBit);
    std::string_view    to_string_view(VqPipelineDepthStencilStateCreateBit);
    std::string_view    to_string_view(VqPipelineExecutableStatisticFormat);
    std::string_view    to_string_view(VqPipelineLayoutCreateBit);
    std::string_view    to_string_view(VqPipelineRobustnessBufferBehavior);
    std::string_view    to_string_view(VqPipelineRobustnessImageBehavior);
    std::string_view    to_string_view(VqPipelineShaderStageCreateBit);
    std::string_view    to_string_view(VqPipelineStageBit);
    std::string_view    to_string_view(VqPointClippingBehavior);
    std::string_view    to_string_view(VqPolygonMode);
    std::string_view    to_string_view(VqPresentGravityBit);
    std::string_view    to_string_view(VqPresentMode);
    std::string_view    to_string_view(VqPresentScalingBit);
    std::string_view    to_string_view(VqPrimitiveTopology);
    std::string_view    to_string_view(VqProvokingVertexMode);
    std::string_view    to_string_view(VqQueryControlBit);
    std::string_view    to_string_view(VqQueryPipelineStatisticBit);
    std::string_view    to_string_view(VqQueryPoolSamplingMode);
    std::string_view    to_string_view(VqQueryResultBit);
    std::string_view    to_string_view(VqQueryResultStatus);
    std::string_view    to_string_view(VqQueryType);
    std::string_view    to_string_view(VqQueueBit);
    std::string_view    to_string_view(VqQueueGlobalPriority);
    std::string_view    to_string_view(VqRasterizationOrder);
    std::string_view    to_string_view(VqRayTracingInvocationReorderMode);
    std::string_view    to_string_view(VqRayTracingShaderGroupType);
    std::string_view    to_string_view(VqRenderPassCreateBit);
    std::string_view    to_string_view(VqRenderingBit);
    std::string_view    to_string_view(VqResolveModeBit);
    std::string_view    to_string_view(VqResult);
    std::string_view    to_string_view(VqSampleCountBit);
    std::string_view    to_string_view(VqSamplerAddressMode);
    std::string_view    to_string_view(VqSamplerCreateBit);
    std::string_view    to_string_view(VqSamplerMipmapMode);
    std::string_view    to_string_view(VqSamplerReductionMode);
    std::string_view    to_string_view(VqSamplerYcbcrModelConversion);
    std::string_view    to_string_view(VqSamplerYcbcrRange);
    std::string_view    to_string_view(VqScope);
    std::string_view    to_string_view(VqSemaphoreImportBit);
    std::string_view    to_string_view(VqSemaphoreType);
    std::string_view    to_string_view(VqSemaphoreWaitBit);
    std::string_view    to_string_view(VqShaderCodeType);
    std::string_view    to_string_view(VqShaderCorePropertiesBit);
    std::string_view    to_string_view(VqShaderCreateBit);
    std::string_view    to_string_view(VqShaderFloatControlsIndependence);
    std::string_view    to_string_view(VqShaderGroupShader);
    std::string_view    to_string_view(VqShaderInfoType);
    std::string_view    to_string_view(VqShaderStageBit);
    std::string_view    to_string_view(VqShadingRatePaletteEntry);
    std::string_view    to_string_view(VqSharingMode);
    std::string_view    to_string_view(VqSparseImageFormatBit);
    std::string_view    to_string_view(VqSparseMemoryBindBit);
    std::string_view    to_string_view(VqStencilFaceBit);
    std::string_view    to_string_view(VqStencilOp);
    std::string_view    to_string_view(VqSubgroupFeatureBit);
    std::string_view    to_string_view(VqSubmitBit);
    std::string_view    to_string_view(VqSubpassContents);
    std::string_view    to_string_view(VqSubpassDescriptionBit);
    std::string_view    to_string_view(VqSubpassMergeStatus);
    std::string_view    to_string_view(VqSurfaceCounterBit);
    std::string_view    to_string_view(VqSurfaceTransformBit);
    std::string_view    to_string_view(VqSwapchainCreateBit);
    std::string_view    to_string_view(VqSystemAllocationScope);
    std::string_view    to_string_view(VqTessellationDomainOrigin);
    std::string_view    to_string_view(VqTimeDomain);
    std::string_view    to_string_view(VqToolPurposeBit);
    std::string_view    to_string_view(VqValidationCacheHeaderVersion);
    std::string_view    to_string_view(VqValidationCheck);
    std::string_view    to_string_view(VqValidationFeatureDisable);
    std::string_view    to_string_view(VqValidationFeatureEnable);
    std::string_view    to_string_view(VqVendorId);
    std::string_view    to_string_view(VqVertexInputRate);
    std::string_view    to_string_view(VqVideoCapabilityBit);
    std::string_view    to_string_view(VqVideoChromaSubsamplingBit);
    std::string_view    to_string_view(VqVideoCodecOperationBit);
    std::string_view    to_string_view(VqVideoCodingControlBit);
    std::string_view    to_string_view(VqVideoComponentBitDepthBit);
    std::string_view    to_string_view(VqVideoDecodeCapabilityBit);
    std::string_view    to_string_view(VqVideoDecodeH264PictureLayoutBit);
    std::string_view    to_string_view(VqVideoDecodeUsageBit);
    std::string_view    to_string_view(VqVideoEncodeCapabilityBit);
    std::string_view    to_string_view(VqVideoEncodeContentBit);
    std::string_view    to_string_view(VqVideoEncodeFeedbackBit);
    std::string_view    to_string_view(VqVideoEncodeBit);
    std::string_view    to_string_view(VqVideoEncodeH264CapabilityBit);
    std::string_view    to_string_view(VqVideoEncodeH264RateControlBit);
    std::string_view    to_string_view(VqVideoEncodeH264StdBit);
    std::string_view    to_string_view(VqVideoEncodeH265CapabilityBit);
    std::string_view    to_string_view(VqVideoEncodeH265CtbSizeBit);
    std::string_view    to_string_view(VqVideoEncodeH265RateControlBit);
    std::string_view    to_string_view(VqVideoEncodeH265StdBit);
    std::string_view    to_string_view(VqVideoEncodeH265TransformBlockSizeBit);
    std::string_view    to_string_view(VqVideoEncodeRateControlModeBit);
    std::string_view    to_string_view(VqVideoEncodeTuningMode);
    std::string_view    to_string_view(VqVideoEncodeUsageBit);
    std::string_view    to_string_view(VqVideoSessionCreateBit);
    std::string_view    to_string_view(VqViewportCoordinateSwizzle);
}
