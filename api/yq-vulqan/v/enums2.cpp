////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "VqEnumerations.hpp"

namespace yq::tachyon {

    static const std::string_view szUnknown   = "(unknown)";

    std::string_view    to_string_view(VqAccelerationStructureBuildType v)
    {
        switch(v){
        case VqAccelerationStructureBuildType::HostKHR:
            return "HostKHR";
        case VqAccelerationStructureBuildType::DeviceKHR:
            return "DeviceKHR";
        case VqAccelerationStructureBuildType::HostOrDeviceKHR:
            return "HostOrDeviceKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqAccelerationStructureCompatibility v)
    {
        switch(v){
        case VqAccelerationStructureCompatibility::CompatibleKHR:
            return "CompatibleKHR";
        case VqAccelerationStructureCompatibility::IncompatibleKHR:
            return "IncompatibleKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqAccelerationStructureCreateFlagBits v)
    {
        switch(v){
        case VqAccelerationStructureCreateFlagBits::DeviceAddressCaptureReplayBitKHR:
            return "DeviceAddressCaptureReplayBitKHR";
        case VqAccelerationStructureCreateFlagBits::DescriptorBufferCaptureReplayBitEXT:
            return "DescriptorBufferCaptureReplayBitEXT";
        case VqAccelerationStructureCreateFlagBits::MotionBitNV:
            return "MotionBitNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqAccelerationStructureMemoryRequirementsType v)
    {
        switch(v){
        case VqAccelerationStructureMemoryRequirementsType::ObjectNV:
            return "ObjectNV";
        case VqAccelerationStructureMemoryRequirementsType::BuildScratchNV:
            return "BuildScratchNV";
        case VqAccelerationStructureMemoryRequirementsType::UpdateScratchNV:
            return "UpdateScratchNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqAccelerationStructureMotionInstanceType v)
    {
        switch(v){
        case VqAccelerationStructureMotionInstanceType::StaticNV:
            return "StaticNV";
        case VqAccelerationStructureMotionInstanceType::MatrixMotionNV:
            return "MatrixMotionNV";
        case VqAccelerationStructureMotionInstanceType::SrtMotionNV:
            return "SrtMotionNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqAccelerationStructureType v)
    {
        switch(v){
        case VqAccelerationStructureType::TopLevelKHR:
            return "TopLevelKHR";
        case VqAccelerationStructureType::BottomLevelKHR:
            return "BottomLevelKHR";
        case VqAccelerationStructureType::GenericKHR:
            return "GenericKHR";
        case VqAccelerationStructureType::TopLevelNV:
            return "TopLevelNV";
        case VqAccelerationStructureType::BottomLevelNV:
            return "BottomLevelNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqAccessFlagBits v)
    {
        switch(v){
        case VqAccessFlagBits::IndirectCommandReadBit:
            return "IndirectCommandReadBit";
        case VqAccessFlagBits::IndexReadBit:
            return "IndexReadBit";
        case VqAccessFlagBits::VertexAttributeReadBit:
            return "VertexAttributeReadBit";
        case VqAccessFlagBits::UniformReadBit:
            return "UniformReadBit";
        case VqAccessFlagBits::InputAttachmentReadBit:
            return "InputAttachmentReadBit";
        case VqAccessFlagBits::ShaderReadBit:
            return "ShaderReadBit";
        case VqAccessFlagBits::ShaderWriteBit:
            return "ShaderWriteBit";
        case VqAccessFlagBits::ColorAttachmentReadBit:
            return "ColorAttachmentReadBit";
        case VqAccessFlagBits::ColorAttachmentWriteBit:
            return "ColorAttachmentWriteBit";
        case VqAccessFlagBits::DepthStencilAttachmentReadBit:
            return "DepthStencilAttachmentReadBit";
        case VqAccessFlagBits::DepthStencilAttachmentWriteBit:
            return "DepthStencilAttachmentWriteBit";
        case VqAccessFlagBits::TransferReadBit:
            return "TransferReadBit";
        case VqAccessFlagBits::TransferWriteBit:
            return "TransferWriteBit";
        case VqAccessFlagBits::HostReadBit:
            return "HostReadBit";
        case VqAccessFlagBits::HostWriteBit:
            return "HostWriteBit";
        case VqAccessFlagBits::MemoryReadBit:
            return "MemoryReadBit";
        case VqAccessFlagBits::MemoryWriteBit:
            return "MemoryWriteBit";
        case VqAccessFlagBits::None:
            return "None";
        case VqAccessFlagBits::TransformFeedbackWriteBitEXT:
            return "TransformFeedbackWriteBitEXT";
        case VqAccessFlagBits::TransformFeedbackCounterReadBitEXT:
            return "TransformFeedbackCounterReadBitEXT";
        case VqAccessFlagBits::TransformFeedbackCounterWriteBitEXT:
            return "TransformFeedbackCounterWriteBitEXT";
        case VqAccessFlagBits::ConditionalRenderingReadBitEXT:
            return "ConditionalRenderingReadBitEXT";
        case VqAccessFlagBits::ColorAttachmentReadNoncoherentBitEXT:
            return "ColorAttachmentReadNoncoherentBitEXT";
        case VqAccessFlagBits::AccelerationStructureReadBitKHR:
            return "AccelerationStructureReadBitKHR";
        case VqAccessFlagBits::AccelerationStructureWriteBitKHR:
            return "AccelerationStructureWriteBitKHR";
        case VqAccessFlagBits::FragmentDensityMapReadBitEXT:
            return "FragmentDensityMapReadBitEXT";
        case VqAccessFlagBits::FragmentShadingRateAttachmentReadBitKHR:
            return "FragmentShadingRateAttachmentReadBitKHR";
        case VqAccessFlagBits::CommandPreprocessReadBitNV:
            return "CommandPreprocessReadBitNV";
        case VqAccessFlagBits::CommandPreprocessWriteBitNV:
            return "CommandPreprocessWriteBitNV";
        case VqAccessFlagBits::ShadingRateImageReadBitNV:
            return "ShadingRateImageReadBitNV";
        case VqAccessFlagBits::AccelerationStructureReadBitNV:
            return "AccelerationStructureReadBitNV";
        case VqAccessFlagBits::AccelerationStructureWriteBitNV:
            return "AccelerationStructureWriteBitNV";
        case VqAccessFlagBits::NoneKHR:
            return "NoneKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqAcquireProfilingLockFlagBits v)
    {
        switch(v){
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqAttachmentDescriptionFlagBits v)
    {
        switch(v){
        case VqAttachmentDescriptionFlagBits::MayAliasBit:
            return "MayAliasBit";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqAttachmentLoadOp v)
    {
        switch(v){
        case VqAttachmentLoadOp::Load:
            return "Load";
        case VqAttachmentLoadOp::Clear:
            return "Clear";
        case VqAttachmentLoadOp::DontCare:
            return "DontCare";
        case VqAttachmentLoadOp::NoneKHR:
            return "NoneKHR";
        case VqAttachmentLoadOp::NoneEXT:
            return "NoneEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqAttachmentStoreOp v)
    {
        switch(v){
        case VqAttachmentStoreOp::Store:
            return "Store";
        case VqAttachmentStoreOp::DontCare:
            return "DontCare";
        case VqAttachmentStoreOp::None:
            return "None";
        case VqAttachmentStoreOp::NoneKHR:
            return "NoneKHR";
        case VqAttachmentStoreOp::NoneQCOM:
            return "NoneQCOM";
        case VqAttachmentStoreOp::NoneEXT:
            return "NoneEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqBlendFactor v)
    {
        switch(v){
        case VqBlendFactor::Zero:
            return "Zero";
        case VqBlendFactor::One:
            return "One";
        case VqBlendFactor::SrcColor:
            return "SrcColor";
        case VqBlendFactor::OneMinusSrcColor:
            return "OneMinusSrcColor";
        case VqBlendFactor::DstColor:
            return "DstColor";
        case VqBlendFactor::OneMinusDstColor:
            return "OneMinusDstColor";
        case VqBlendFactor::SrcAlpha:
            return "SrcAlpha";
        case VqBlendFactor::OneMinusSrcAlpha:
            return "OneMinusSrcAlpha";
        case VqBlendFactor::DstAlpha:
            return "DstAlpha";
        case VqBlendFactor::OneMinusDstAlpha:
            return "OneMinusDstAlpha";
        case VqBlendFactor::ConstantColor:
            return "ConstantColor";
        case VqBlendFactor::OneMinusConstantColor:
            return "OneMinusConstantColor";
        case VqBlendFactor::ConstantAlpha:
            return "ConstantAlpha";
        case VqBlendFactor::OneMinusConstantAlpha:
            return "OneMinusConstantAlpha";
        case VqBlendFactor::SrcAlphaSaturate:
            return "SrcAlphaSaturate";
        case VqBlendFactor::Src1Color:
            return "Src1Color";
        case VqBlendFactor::OneMinusSrc1Color:
            return "OneMinusSrc1Color";
        case VqBlendFactor::Src1Alpha:
            return "Src1Alpha";
        case VqBlendFactor::OneMinusSrc1Alpha:
            return "OneMinusSrc1Alpha";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqBlendOp v)
    {
        switch(v){
        case VqBlendOp::Add:
            return "Add";
        case VqBlendOp::Subtract:
            return "Subtract";
        case VqBlendOp::ReverseSubtract:
            return "ReverseSubtract";
        case VqBlendOp::Min:
            return "Min";
        case VqBlendOp::Max:
            return "Max";
        case VqBlendOp::ZeroEXT:
            return "ZeroEXT";
        case VqBlendOp::SrcEXT:
            return "SrcEXT";
        case VqBlendOp::DstEXT:
            return "DstEXT";
        case VqBlendOp::SrcOverEXT:
            return "SrcOverEXT";
        case VqBlendOp::DstOverEXT:
            return "DstOverEXT";
        case VqBlendOp::SrcInEXT:
            return "SrcInEXT";
        case VqBlendOp::DstInEXT:
            return "DstInEXT";
        case VqBlendOp::SrcOutEXT:
            return "SrcOutEXT";
        case VqBlendOp::DstOutEXT:
            return "DstOutEXT";
        case VqBlendOp::SrcAtopEXT:
            return "SrcAtopEXT";
        case VqBlendOp::DstAtopEXT:
            return "DstAtopEXT";
        case VqBlendOp::XorEXT:
            return "XorEXT";
        case VqBlendOp::MultiplyEXT:
            return "MultiplyEXT";
        case VqBlendOp::ScreenEXT:
            return "ScreenEXT";
        case VqBlendOp::OverlayEXT:
            return "OverlayEXT";
        case VqBlendOp::DarkenEXT:
            return "DarkenEXT";
        case VqBlendOp::LightenEXT:
            return "LightenEXT";
        case VqBlendOp::ColordodgeEXT:
            return "ColordodgeEXT";
        case VqBlendOp::ColorburnEXT:
            return "ColorburnEXT";
        case VqBlendOp::HardlightEXT:
            return "HardlightEXT";
        case VqBlendOp::SoftlightEXT:
            return "SoftlightEXT";
        case VqBlendOp::DifferenceEXT:
            return "DifferenceEXT";
        case VqBlendOp::ExclusionEXT:
            return "ExclusionEXT";
        case VqBlendOp::InvertEXT:
            return "InvertEXT";
        case VqBlendOp::InvertRgbEXT:
            return "InvertRgbEXT";
        case VqBlendOp::LineardodgeEXT:
            return "LineardodgeEXT";
        case VqBlendOp::LinearburnEXT:
            return "LinearburnEXT";
        case VqBlendOp::VividlightEXT:
            return "VividlightEXT";
        case VqBlendOp::LinearlightEXT:
            return "LinearlightEXT";
        case VqBlendOp::PinlightEXT:
            return "PinlightEXT";
        case VqBlendOp::HardmixEXT:
            return "HardmixEXT";
        case VqBlendOp::HslHueEXT:
            return "HslHueEXT";
        case VqBlendOp::HslSaturationEXT:
            return "HslSaturationEXT";
        case VqBlendOp::HslColorEXT:
            return "HslColorEXT";
        case VqBlendOp::HslLuminosityEXT:
            return "HslLuminosityEXT";
        case VqBlendOp::PlusEXT:
            return "PlusEXT";
        case VqBlendOp::PlusClampedEXT:
            return "PlusClampedEXT";
        case VqBlendOp::PlusClampedAlphaEXT:
            return "PlusClampedAlphaEXT";
        case VqBlendOp::PlusDarkerEXT:
            return "PlusDarkerEXT";
        case VqBlendOp::MinusEXT:
            return "MinusEXT";
        case VqBlendOp::MinusClampedEXT:
            return "MinusClampedEXT";
        case VqBlendOp::ContrastEXT:
            return "ContrastEXT";
        case VqBlendOp::InvertOvgEXT:
            return "InvertOvgEXT";
        case VqBlendOp::RedEXT:
            return "RedEXT";
        case VqBlendOp::GreenEXT:
            return "GreenEXT";
        case VqBlendOp::BlueEXT:
            return "BlueEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqBlendOverlap v)
    {
        switch(v){
        case VqBlendOverlap::UncorrelatedEXT:
            return "UncorrelatedEXT";
        case VqBlendOverlap::DisjointEXT:
            return "DisjointEXT";
        case VqBlendOverlap::ConjointEXT:
            return "ConjointEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqBlockMatchWindowCompareMode v)
    {
        switch(v){
        case VqBlockMatchWindowCompareMode::MinQCOM:
            return "MinQCOM";
        case VqBlockMatchWindowCompareMode::MaxQCOM:
            return "MaxQCOM";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqBorderColor v)
    {
        switch(v){
        case VqBorderColor::FloatTransparentBlack:
            return "FloatTransparentBlack";
        case VqBorderColor::IntTransparentBlack:
            return "IntTransparentBlack";
        case VqBorderColor::FloatOpaqueBlack:
            return "FloatOpaqueBlack";
        case VqBorderColor::IntOpaqueBlack:
            return "IntOpaqueBlack";
        case VqBorderColor::FloatOpaqueWhite:
            return "FloatOpaqueWhite";
        case VqBorderColor::IntOpaqueWhite:
            return "IntOpaqueWhite";
        case VqBorderColor::FloatCustomEXT:
            return "FloatCustomEXT";
        case VqBorderColor::IntCustomEXT:
            return "IntCustomEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqBufferCreateFlagBits v)
    {
        switch(v){
        case VqBufferCreateFlagBits::SparseBindingBit:
            return "SparseBindingBit";
        case VqBufferCreateFlagBits::SparseResidencyBit:
            return "SparseResidencyBit";
        case VqBufferCreateFlagBits::SparseAliasedBit:
            return "SparseAliasedBit";
        case VqBufferCreateFlagBits::ProtectedBit:
            return "ProtectedBit";
        case VqBufferCreateFlagBits::DeviceAddressCaptureReplayBit:
            return "DeviceAddressCaptureReplayBit";
        case VqBufferCreateFlagBits::DescriptorBufferCaptureReplayBitEXT:
            return "DescriptorBufferCaptureReplayBitEXT";
        case VqBufferCreateFlagBits::VideoProfileIndependentBitKHR:
            return "VideoProfileIndependentBitKHR";
        case VqBufferCreateFlagBits::DeviceAddressCaptureReplayBitEXT:
            return "DeviceAddressCaptureReplayBitEXT";
        case VqBufferCreateFlagBits::DeviceAddressCaptureReplayBitKHR:
            return "DeviceAddressCaptureReplayBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqBufferUsageFlagBits v)
    {
        switch(v){
        case VqBufferUsageFlagBits::TransferSrcBit:
            return "TransferSrcBit";
        case VqBufferUsageFlagBits::TransferDstBit:
            return "TransferDstBit";
        case VqBufferUsageFlagBits::UniformTexelBufferBit:
            return "UniformTexelBufferBit";
        case VqBufferUsageFlagBits::StorageTexelBufferBit:
            return "StorageTexelBufferBit";
        case VqBufferUsageFlagBits::UniformBufferBit:
            return "UniformBufferBit";
        case VqBufferUsageFlagBits::StorageBufferBit:
            return "StorageBufferBit";
        case VqBufferUsageFlagBits::IndexBufferBit:
            return "IndexBufferBit";
        case VqBufferUsageFlagBits::VertexBufferBit:
            return "VertexBufferBit";
        case VqBufferUsageFlagBits::IndirectBufferBit:
            return "IndirectBufferBit";
        case VqBufferUsageFlagBits::ShaderDeviceAddressBit:
            return "ShaderDeviceAddressBit";
        case VqBufferUsageFlagBits::VideoDecodeSrcBitKHR:
            return "VideoDecodeSrcBitKHR";
        case VqBufferUsageFlagBits::VideoDecodeDstBitKHR:
            return "VideoDecodeDstBitKHR";
        case VqBufferUsageFlagBits::TransformFeedbackBufferBitEXT:
            return "TransformFeedbackBufferBitEXT";
        case VqBufferUsageFlagBits::TransformFeedbackCounterBufferBitEXT:
            return "TransformFeedbackCounterBufferBitEXT";
        case VqBufferUsageFlagBits::ConditionalRenderingBitEXT:
            return "ConditionalRenderingBitEXT";
        case VqBufferUsageFlagBits::ExecutionGraphScratchBitAmdx:
            return "ExecutionGraphScratchBitAmdx";
        case VqBufferUsageFlagBits::AccelerationStructureBuildInputReadOnlyBitKHR:
            return "AccelerationStructureBuildInputReadOnlyBitKHR";
        case VqBufferUsageFlagBits::AccelerationStructureStorageBitKHR:
            return "AccelerationStructureStorageBitKHR";
        case VqBufferUsageFlagBits::ShaderBindingTableBitKHR:
            return "ShaderBindingTableBitKHR";
        case VqBufferUsageFlagBits::VideoEncodeDstBitKHR:
            return "VideoEncodeDstBitKHR";
        case VqBufferUsageFlagBits::VideoEncodeSrcBitKHR:
            return "VideoEncodeSrcBitKHR";
        case VqBufferUsageFlagBits::SamplerDescriptorBufferBitEXT:
            return "SamplerDescriptorBufferBitEXT";
        case VqBufferUsageFlagBits::ResourceDescriptorBufferBitEXT:
            return "ResourceDescriptorBufferBitEXT";
        case VqBufferUsageFlagBits::PushDescriptorsDescriptorBufferBitEXT:
            return "PushDescriptorsDescriptorBufferBitEXT";
        case VqBufferUsageFlagBits::MicromapBuildInputReadOnlyBitEXT:
            return "MicromapBuildInputReadOnlyBitEXT";
        case VqBufferUsageFlagBits::MicromapStorageBitEXT:
            return "MicromapStorageBitEXT";
        case VqBufferUsageFlagBits::RayTracingBitNV:
            return "RayTracingBitNV";
        case VqBufferUsageFlagBits::ShaderDeviceAddressBitEXT:
            return "ShaderDeviceAddressBitEXT";
        case VqBufferUsageFlagBits::ShaderDeviceAddressBitKHR:
            return "ShaderDeviceAddressBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqBuildAccelerationStructureFlagBits v)
    {
        switch(v){
        case VqBuildAccelerationStructureFlagBits::AllowUpdateBitKHR:
            return "AllowUpdateBitKHR";
        case VqBuildAccelerationStructureFlagBits::AllowCompactionBitKHR:
            return "AllowCompactionBitKHR";
        case VqBuildAccelerationStructureFlagBits::PreferFastTraceBitKHR:
            return "PreferFastTraceBitKHR";
        case VqBuildAccelerationStructureFlagBits::PreferFastBuildBitKHR:
            return "PreferFastBuildBitKHR";
        case VqBuildAccelerationStructureFlagBits::LowMemoryBitKHR:
            return "LowMemoryBitKHR";
        case VqBuildAccelerationStructureFlagBits::MotionBitNV:
            return "MotionBitNV";
        case VqBuildAccelerationStructureFlagBits::AllowOpacityMicromapUpdateEXT:
            return "AllowOpacityMicromapUpdateEXT";
        case VqBuildAccelerationStructureFlagBits::AllowDisableOpacityMicromapsEXT:
            return "AllowDisableOpacityMicromapsEXT";
        case VqBuildAccelerationStructureFlagBits::AllowOpacityMicromapDataUpdateEXT:
            return "AllowOpacityMicromapDataUpdateEXT";
        case VqBuildAccelerationStructureFlagBits::AllowDisplacementMicromapUpdateNV:
            return "AllowDisplacementMicromapUpdateNV";
        case VqBuildAccelerationStructureFlagBits::AllowDataAccessKHR:
            return "AllowDataAccessKHR";
        case VqBuildAccelerationStructureFlagBits::AllowUpdateBitNV:
            return "AllowUpdateBitNV";
        case VqBuildAccelerationStructureFlagBits::AllowCompactionBitNV:
            return "AllowCompactionBitNV";
        case VqBuildAccelerationStructureFlagBits::PreferFastTraceBitNV:
            return "PreferFastTraceBitNV";
        case VqBuildAccelerationStructureFlagBits::PreferFastBuildBitNV:
            return "PreferFastBuildBitNV";
        case VqBuildAccelerationStructureFlagBits::LowMemoryBitNV:
            return "LowMemoryBitNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqBuildAccelerationStructureMode v)
    {
        switch(v){
        case VqBuildAccelerationStructureMode::BuildKHR:
            return "BuildKHR";
        case VqBuildAccelerationStructureMode::UpdateKHR:
            return "UpdateKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqBuildMicromapFlagBits v)
    {
        switch(v){
        case VqBuildMicromapFlagBits::PreferFastTraceBitEXT:
            return "PreferFastTraceBitEXT";
        case VqBuildMicromapFlagBits::PreferFastBuildBitEXT:
            return "PreferFastBuildBitEXT";
        case VqBuildMicromapFlagBits::AllowCompactionBitEXT:
            return "AllowCompactionBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqBuildMicromapMode v)
    {
        switch(v){
        case VqBuildMicromapMode::BuildEXT:
            return "BuildEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqChromaLocation v)
    {
        switch(v){
        case VqChromaLocation::CositedEven:
            return "CositedEven";
        case VqChromaLocation::Midpoint:
            return "Midpoint";
        case VqChromaLocation::CositedEvenKHR:
            return "CositedEvenKHR";
        case VqChromaLocation::MidpointKHR:
            return "MidpointKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCoarseSampleOrderType v)
    {
        switch(v){
        case VqCoarseSampleOrderType::DefaultNV:
            return "DefaultNV";
        case VqCoarseSampleOrderType::CustomNV:
            return "CustomNV";
        case VqCoarseSampleOrderType::PixelMajorNV:
            return "PixelMajorNV";
        case VqCoarseSampleOrderType::SampleMajorNV:
            return "SampleMajorNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqColorComponentFlagBits v)
    {
        switch(v){
        case VqColorComponentFlagBits::RBit:
            return "RBit";
        case VqColorComponentFlagBits::GBit:
            return "GBit";
        case VqColorComponentFlagBits::BBit:
            return "BBit";
        case VqColorComponentFlagBits::ABit:
            return "ABit";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqColorSpace v)
    {
        switch(v){
        case VqColorSpace::SrgbNonlinearKHR:
            return "SrgbNonlinearKHR";
        case VqColorSpace::DisplayP3NonlinearEXT:
            return "DisplayP3NonlinearEXT";
        case VqColorSpace::ExtendedSrgbLinearEXT:
            return "ExtendedSrgbLinearEXT";
        case VqColorSpace::DisplayP3LinearEXT:
            return "DisplayP3LinearEXT";
        case VqColorSpace::DciP3NonlinearEXT:
            return "DciP3NonlinearEXT";
        case VqColorSpace::Bt709LinearEXT:
            return "Bt709LinearEXT";
        case VqColorSpace::Bt709NonlinearEXT:
            return "Bt709NonlinearEXT";
        case VqColorSpace::Bt2020LinearEXT:
            return "Bt2020LinearEXT";
        case VqColorSpace::Hdr10St2084EXT:
            return "Hdr10St2084EXT";
        case VqColorSpace::DolbyvisionEXT:
            return "DolbyvisionEXT";
        case VqColorSpace::Hdr10HlgEXT:
            return "Hdr10HlgEXT";
        case VqColorSpace::AdobergbLinearEXT:
            return "AdobergbLinearEXT";
        case VqColorSpace::AdobergbNonlinearEXT:
            return "AdobergbNonlinearEXT";
        case VqColorSpace::PassThroughEXT:
            return "PassThroughEXT";
        case VqColorSpace::ExtendedSrgbNonlinearEXT:
            return "ExtendedSrgbNonlinearEXT";
        case VqColorSpace::DisplayNativeAMD:
            return "DisplayNativeAMD";
        case VqColorSpace::VkColorspaceSrgbNonlinearKHR:
            return "VkColorspaceSrgbNonlinearKHR";
        case VqColorSpace::DciP3LinearEXT:
            return "DciP3LinearEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCommandBufferLevel v)
    {
        switch(v){
        case VqCommandBufferLevel::Primary:
            return "Primary";
        case VqCommandBufferLevel::Secondary:
            return "Secondary";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCommandBufferResetFlagBits v)
    {
        switch(v){
        case VqCommandBufferResetFlagBits::ReleaseResourcesBit:
            return "ReleaseResourcesBit";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCommandBufferUsageFlagBits v)
    {
        switch(v){
        case VqCommandBufferUsageFlagBits::OneTimeSubmitBit:
            return "OneTimeSubmitBit";
        case VqCommandBufferUsageFlagBits::RenderPassContinueBit:
            return "RenderPassContinueBit";
        case VqCommandBufferUsageFlagBits::SimultaneousUseBit:
            return "SimultaneousUseBit";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCommandPoolCreateFlagBits v)
    {
        switch(v){
        case VqCommandPoolCreateFlagBits::TransientBit:
            return "TransientBit";
        case VqCommandPoolCreateFlagBits::ResetCommandBufferBit:
            return "ResetCommandBufferBit";
        case VqCommandPoolCreateFlagBits::ProtectedBit:
            return "ProtectedBit";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCommandPoolResetFlagBits v)
    {
        switch(v){
        case VqCommandPoolResetFlagBits::ReleaseResourcesBit:
            return "ReleaseResourcesBit";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCompareOp v)
    {
        switch(v){
        case VqCompareOp::Never:
            return "Never";
        case VqCompareOp::Less:
            return "Less";
        case VqCompareOp::Equal:
            return "Equal";
        case VqCompareOp::LessOrEqual:
            return "LessOrEqual";
        case VqCompareOp::Greater:
            return "Greater";
        case VqCompareOp::NotEqual:
            return "NotEqual";
        case VqCompareOp::GreaterOrEqual:
            return "GreaterOrEqual";
        case VqCompareOp::Always:
            return "Always";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqComponentSwizzle v)
    {
        switch(v){
        case VqComponentSwizzle::Identity:
            return "Identity";
        case VqComponentSwizzle::Zero:
            return "Zero";
        case VqComponentSwizzle::One:
            return "One";
        case VqComponentSwizzle::R:
            return "R";
        case VqComponentSwizzle::G:
            return "G";
        case VqComponentSwizzle::B:
            return "B";
        case VqComponentSwizzle::A:
            return "A";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqComponentType v)
    {
        switch(v){
        case VqComponentType::Float16KHR:
            return "Float16KHR";
        case VqComponentType::Float32KHR:
            return "Float32KHR";
        case VqComponentType::Float64KHR:
            return "Float64KHR";
        case VqComponentType::Sint8KHR:
            return "Sint8KHR";
        case VqComponentType::Sint16KHR:
            return "Sint16KHR";
        case VqComponentType::Sint32KHR:
            return "Sint32KHR";
        case VqComponentType::Sint64KHR:
            return "Sint64KHR";
        case VqComponentType::Uint8KHR:
            return "Uint8KHR";
        case VqComponentType::Uint16KHR:
            return "Uint16KHR";
        case VqComponentType::Uint32KHR:
            return "Uint32KHR";
        case VqComponentType::Uint64KHR:
            return "Uint64KHR";
        case VqComponentType::Float16NV:
            return "Float16NV";
        case VqComponentType::Float32NV:
            return "Float32NV";
        case VqComponentType::Float64NV:
            return "Float64NV";
        case VqComponentType::Sint8NV:
            return "Sint8NV";
        case VqComponentType::Sint16NV:
            return "Sint16NV";
        case VqComponentType::Sint32NV:
            return "Sint32NV";
        case VqComponentType::Sint64NV:
            return "Sint64NV";
        case VqComponentType::Uint8NV:
            return "Uint8NV";
        case VqComponentType::Uint16NV:
            return "Uint16NV";
        case VqComponentType::Uint32NV:
            return "Uint32NV";
        case VqComponentType::Uint64NV:
            return "Uint64NV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCompositeAlphaFlagBits v)
    {
        switch(v){
        case VqCompositeAlphaFlagBits::OpaqueBitKHR:
            return "OpaqueBitKHR";
        case VqCompositeAlphaFlagBits::PreMultipliedBitKHR:
            return "PreMultipliedBitKHR";
        case VqCompositeAlphaFlagBits::PostMultipliedBitKHR:
            return "PostMultipliedBitKHR";
        case VqCompositeAlphaFlagBits::InheritBitKHR:
            return "InheritBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqConditionalRenderingFlagBits v)
    {
        switch(v){
        case VqConditionalRenderingFlagBits::InvertedBitEXT:
            return "InvertedBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqConservativeRasterizationMode v)
    {
        switch(v){
        case VqConservativeRasterizationMode::DisabledEXT:
            return "DisabledEXT";
        case VqConservativeRasterizationMode::OverestimateEXT:
            return "OverestimateEXT";
        case VqConservativeRasterizationMode::UnderestimateEXT:
            return "UnderestimateEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCopyAccelerationStructureMode v)
    {
        switch(v){
        case VqCopyAccelerationStructureMode::CloneKHR:
            return "CloneKHR";
        case VqCopyAccelerationStructureMode::CompactKHR:
            return "CompactKHR";
        case VqCopyAccelerationStructureMode::SerializeKHR:
            return "SerializeKHR";
        case VqCopyAccelerationStructureMode::DeserializeKHR:
            return "DeserializeKHR";
        case VqCopyAccelerationStructureMode::CloneNV:
            return "CloneNV";
        case VqCopyAccelerationStructureMode::CompactNV:
            return "CompactNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCopyMicromapMode v)
    {
        switch(v){
        case VqCopyMicromapMode::CloneEXT:
            return "CloneEXT";
        case VqCopyMicromapMode::SerializeEXT:
            return "SerializeEXT";
        case VqCopyMicromapMode::DeserializeEXT:
            return "DeserializeEXT";
        case VqCopyMicromapMode::CompactEXT:
            return "CompactEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCoverageModulationMode v)
    {
        switch(v){
        case VqCoverageModulationMode::NoneNV:
            return "NoneNV";
        case VqCoverageModulationMode::RgbNV:
            return "RgbNV";
        case VqCoverageModulationMode::AlphaNV:
            return "AlphaNV";
        case VqCoverageModulationMode::RgbaNV:
            return "RgbaNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCoverageReductionMode v)
    {
        switch(v){
        case VqCoverageReductionMode::MergeNV:
            return "MergeNV";
        case VqCoverageReductionMode::TruncateNV:
            return "TruncateNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCubicFilterWeights v)
    {
        switch(v){
        case VqCubicFilterWeights::CatmullRomQCOM:
            return "CatmullRomQCOM";
        case VqCubicFilterWeights::ZeroTangentCardinalQCOM:
            return "ZeroTangentCardinalQCOM";
        case VqCubicFilterWeights::BSplineQCOM:
            return "BSplineQCOM";
        case VqCubicFilterWeights::MitchellNetravaliQCOM:
            return "MitchellNetravaliQCOM";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCullModeFlagBits v)
    {
        switch(v){
        case VqCullModeFlagBits::None:
            return "None";
        case VqCullModeFlagBits::FrontBit:
            return "FrontBit";
        case VqCullModeFlagBits::BackBit:
            return "BackBit";
        case VqCullModeFlagBits::FrontAndBack:
            return "FrontAndBack";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDebugReportFlagBits v)
    {
        switch(v){
        case VqDebugReportFlagBits::InformationBitEXT:
            return "InformationBitEXT";
        case VqDebugReportFlagBits::WarningBitEXT:
            return "WarningBitEXT";
        case VqDebugReportFlagBits::PerformanceWarningBitEXT:
            return "PerformanceWarningBitEXT";
        case VqDebugReportFlagBits::ErrorBitEXT:
            return "ErrorBitEXT";
        case VqDebugReportFlagBits::DebugBitEXT:
            return "DebugBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDebugReportObjectType v)
    {
        switch(v){
        case VqDebugReportObjectType::UnknownEXT:
            return "UnknownEXT";
        case VqDebugReportObjectType::InstanceEXT:
            return "InstanceEXT";
        case VqDebugReportObjectType::PhysicalDeviceEXT:
            return "PhysicalDeviceEXT";
        case VqDebugReportObjectType::DeviceEXT:
            return "DeviceEXT";
        case VqDebugReportObjectType::QueueEXT:
            return "QueueEXT";
        case VqDebugReportObjectType::SemaphoreEXT:
            return "SemaphoreEXT";
        case VqDebugReportObjectType::CommandBufferEXT:
            return "CommandBufferEXT";
        case VqDebugReportObjectType::FenceEXT:
            return "FenceEXT";
        case VqDebugReportObjectType::DeviceMemoryEXT:
            return "DeviceMemoryEXT";
        case VqDebugReportObjectType::BufferEXT:
            return "BufferEXT";
        case VqDebugReportObjectType::ImageEXT:
            return "ImageEXT";
        case VqDebugReportObjectType::EventEXT:
            return "EventEXT";
        case VqDebugReportObjectType::QueryPoolEXT:
            return "QueryPoolEXT";
        case VqDebugReportObjectType::BufferViewEXT:
            return "BufferViewEXT";
        case VqDebugReportObjectType::ImageViewEXT:
            return "ImageViewEXT";
        case VqDebugReportObjectType::ShaderModuleEXT:
            return "ShaderModuleEXT";
        case VqDebugReportObjectType::PipelineCacheEXT:
            return "PipelineCacheEXT";
        case VqDebugReportObjectType::PipelineLayoutEXT:
            return "PipelineLayoutEXT";
        case VqDebugReportObjectType::RenderPassEXT:
            return "RenderPassEXT";
        case VqDebugReportObjectType::PipelineEXT:
            return "PipelineEXT";
        case VqDebugReportObjectType::DescriptorSetLayoutEXT:
            return "DescriptorSetLayoutEXT";
        case VqDebugReportObjectType::SamplerEXT:
            return "SamplerEXT";
        case VqDebugReportObjectType::DescriptorPoolEXT:
            return "DescriptorPoolEXT";
        case VqDebugReportObjectType::DescriptorSetEXT:
            return "DescriptorSetEXT";
        case VqDebugReportObjectType::FramebufferEXT:
            return "FramebufferEXT";
        case VqDebugReportObjectType::CommandPoolEXT:
            return "CommandPoolEXT";
        case VqDebugReportObjectType::SurfaceKHREXT:
            return "SurfaceKHREXT";
        case VqDebugReportObjectType::SwapchainKHREXT:
            return "SwapchainKHREXT";
        case VqDebugReportObjectType::DebugReportCallbackEXTEXT:
            return "DebugReportCallbackEXTEXT";
        case VqDebugReportObjectType::DisplayKHREXT:
            return "DisplayKHREXT";
        case VqDebugReportObjectType::DisplayModeKHREXT:
            return "DisplayModeKHREXT";
        case VqDebugReportObjectType::ValidationCacheEXTEXT:
            return "ValidationCacheEXTEXT";
        case VqDebugReportObjectType::SamplerYcbcrConversionEXT:
            return "SamplerYcbcrConversionEXT";
        case VqDebugReportObjectType::DescriptorUpdateTemplateEXT:
            return "DescriptorUpdateTemplateEXT";
        case VqDebugReportObjectType::CuModuleNvxEXT:
            return "CuModuleNvxEXT";
        case VqDebugReportObjectType::CuFunctionNvxEXT:
            return "CuFunctionNvxEXT";
        case VqDebugReportObjectType::AccelerationStructureKHREXT:
            return "AccelerationStructureKHREXT";
        case VqDebugReportObjectType::AccelerationStructureNVEXT:
            return "AccelerationStructureNVEXT";
        case VqDebugReportObjectType::CudaModuleNVEXT:
            return "CudaModuleNVEXT";
        case VqDebugReportObjectType::CudaFunctionNVEXT:
            return "CudaFunctionNVEXT";
        case VqDebugReportObjectType::BufferCollectionFuchsiaEXT:
            return "BufferCollectionFuchsiaEXT";
        case VqDebugReportObjectType::DebugReportEXT:
            return "DebugReportEXT";
        case VqDebugReportObjectType::ValidationCacheEXT:
            return "ValidationCacheEXT";
        case VqDebugReportObjectType::DescriptorUpdateTemplateKHREXT:
            return "DescriptorUpdateTemplateKHREXT";
        case VqDebugReportObjectType::SamplerYcbcrConversionKHREXT:
            return "SamplerYcbcrConversionKHREXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDebugUtilsMessageSeverityFlagBits v)
    {
        switch(v){
        case VqDebugUtilsMessageSeverityFlagBits::VerboseBitEXT:
            return "VerboseBitEXT";
        case VqDebugUtilsMessageSeverityFlagBits::InfoBitEXT:
            return "InfoBitEXT";
        case VqDebugUtilsMessageSeverityFlagBits::WarningBitEXT:
            return "WarningBitEXT";
        case VqDebugUtilsMessageSeverityFlagBits::ErrorBitEXT:
            return "ErrorBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDebugUtilsMessageTypeFlagBits v)
    {
        switch(v){
        case VqDebugUtilsMessageTypeFlagBits::GeneralBitEXT:
            return "GeneralBitEXT";
        case VqDebugUtilsMessageTypeFlagBits::ValidationBitEXT:
            return "ValidationBitEXT";
        case VqDebugUtilsMessageTypeFlagBits::PerformanceBitEXT:
            return "PerformanceBitEXT";
        case VqDebugUtilsMessageTypeFlagBits::DeviceAddressBindingBitEXT:
            return "DeviceAddressBindingBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDependencyFlagBits v)
    {
        switch(v){
        case VqDependencyFlagBits::ByRegionBit:
            return "ByRegionBit";
        case VqDependencyFlagBits::DeviceGroupBit:
            return "DeviceGroupBit";
        case VqDependencyFlagBits::ViewLocalBit:
            return "ViewLocalBit";
        case VqDependencyFlagBits::FeedbackLoopBitEXT:
            return "FeedbackLoopBitEXT";
        case VqDependencyFlagBits::ViewLocalBitKHR:
            return "ViewLocalBitKHR";
        case VqDependencyFlagBits::DeviceGroupBitKHR:
            return "DeviceGroupBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDepthBiasRepresentation v)
    {
        switch(v){
        case VqDepthBiasRepresentation::LeastRepresentableValueFormatEXT:
            return "LeastRepresentableValueFormatEXT";
        case VqDepthBiasRepresentation::LeastRepresentableValueForceUnormEXT:
            return "LeastRepresentableValueForceUnormEXT";
        case VqDepthBiasRepresentation::FloatEXT:
            return "FloatEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDescriptorBindingFlagBits v)
    {
        switch(v){
        case VqDescriptorBindingFlagBits::UpdateAfterBindBit:
            return "UpdateAfterBindBit";
        case VqDescriptorBindingFlagBits::UpdateUnusedWhilePendingBit:
            return "UpdateUnusedWhilePendingBit";
        case VqDescriptorBindingFlagBits::PartiallyBoundBit:
            return "PartiallyBoundBit";
        case VqDescriptorBindingFlagBits::VariableDescriptorCountBit:
            return "VariableDescriptorCountBit";
        case VqDescriptorBindingFlagBits::UpdateAfterBindBitEXT:
            return "UpdateAfterBindBitEXT";
        case VqDescriptorBindingFlagBits::UpdateUnusedWhilePendingBitEXT:
            return "UpdateUnusedWhilePendingBitEXT";
        case VqDescriptorBindingFlagBits::PartiallyBoundBitEXT:
            return "PartiallyBoundBitEXT";
        case VqDescriptorBindingFlagBits::VariableDescriptorCountBitEXT:
            return "VariableDescriptorCountBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDescriptorPoolCreateFlagBits v)
    {
        switch(v){
        case VqDescriptorPoolCreateFlagBits::FreeDescriptorSetBit:
            return "FreeDescriptorSetBit";
        case VqDescriptorPoolCreateFlagBits::UpdateAfterBindBit:
            return "UpdateAfterBindBit";
        case VqDescriptorPoolCreateFlagBits::HostOnlyBitEXT:
            return "HostOnlyBitEXT";
        case VqDescriptorPoolCreateFlagBits::AllowOverallocationSetsBitNV:
            return "AllowOverallocationSetsBitNV";
        case VqDescriptorPoolCreateFlagBits::AllowOverallocationPoolsBitNV:
            return "AllowOverallocationPoolsBitNV";
        case VqDescriptorPoolCreateFlagBits::UpdateAfterBindBitEXT:
            return "UpdateAfterBindBitEXT";
        case VqDescriptorPoolCreateFlagBits::HostOnlyBitValve:
            return "HostOnlyBitValve";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDescriptorSetLayoutCreateFlagBits v)
    {
        switch(v){
        case VqDescriptorSetLayoutCreateFlagBits::UpdateAfterBindPoolBit:
            return "UpdateAfterBindPoolBit";
        case VqDescriptorSetLayoutCreateFlagBits::PushDescriptorBitKHR:
            return "PushDescriptorBitKHR";
        case VqDescriptorSetLayoutCreateFlagBits::DescriptorBufferBitEXT:
            return "DescriptorBufferBitEXT";
        case VqDescriptorSetLayoutCreateFlagBits::EmbeddedImmutableSamplersBitEXT:
            return "EmbeddedImmutableSamplersBitEXT";
        case VqDescriptorSetLayoutCreateFlagBits::IndirectBindableBitNV:
            return "IndirectBindableBitNV";
        case VqDescriptorSetLayoutCreateFlagBits::HostOnlyPoolBitEXT:
            return "HostOnlyPoolBitEXT";
        case VqDescriptorSetLayoutCreateFlagBits::PerStageBitNV:
            return "PerStageBitNV";
        case VqDescriptorSetLayoutCreateFlagBits::UpdateAfterBindPoolBitEXT:
            return "UpdateAfterBindPoolBitEXT";
        case VqDescriptorSetLayoutCreateFlagBits::HostOnlyPoolBitValve:
            return "HostOnlyPoolBitValve";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDescriptorType v)
    {
        switch(v){
        case VqDescriptorType::Sampler:
            return "Sampler";
        case VqDescriptorType::CombinedImageSampler:
            return "CombinedImageSampler";
        case VqDescriptorType::SampledImage:
            return "SampledImage";
        case VqDescriptorType::StorageImage:
            return "StorageImage";
        case VqDescriptorType::UniformTexelBuffer:
            return "UniformTexelBuffer";
        case VqDescriptorType::StorageTexelBuffer:
            return "StorageTexelBuffer";
        case VqDescriptorType::UniformBuffer:
            return "UniformBuffer";
        case VqDescriptorType::StorageBuffer:
            return "StorageBuffer";
        case VqDescriptorType::UniformBufferDynamic:
            return "UniformBufferDynamic";
        case VqDescriptorType::StorageBufferDynamic:
            return "StorageBufferDynamic";
        case VqDescriptorType::InputAttachment:
            return "InputAttachment";
        case VqDescriptorType::InlineUniformBlock:
            return "InlineUniformBlock";
        case VqDescriptorType::AccelerationStructureKHR:
            return "AccelerationStructureKHR";
        case VqDescriptorType::AccelerationStructureNV:
            return "AccelerationStructureNV";
        case VqDescriptorType::SampleWeightImageQCOM:
            return "SampleWeightImageQCOM";
        case VqDescriptorType::BlockMatchImageQCOM:
            return "BlockMatchImageQCOM";
        case VqDescriptorType::MutableEXT:
            return "MutableEXT";
        case VqDescriptorType::InlineUniformBlockEXT:
            return "InlineUniformBlockEXT";
        case VqDescriptorType::MutableValve:
            return "MutableValve";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDescriptorUpdateTemplateType v)
    {
        switch(v){
        case VqDescriptorUpdateTemplateType::DescriptorSet:
            return "DescriptorSet";
        case VqDescriptorUpdateTemplateType::PushDescriptorsKHR:
            return "PushDescriptorsKHR";
        case VqDescriptorUpdateTemplateType::DescriptorSetKHR:
            return "DescriptorSetKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDeviceAddressBindingFlagBits v)
    {
        switch(v){
        case VqDeviceAddressBindingFlagBits::InternalObjectBitEXT:
            return "InternalObjectBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDeviceAddressBindingType v)
    {
        switch(v){
        case VqDeviceAddressBindingType::BindEXT:
            return "BindEXT";
        case VqDeviceAddressBindingType::UnbindEXT:
            return "UnbindEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDeviceDiagnosticsConfigFlagBits v)
    {
        switch(v){
        case VqDeviceDiagnosticsConfigFlagBits::EnableShaderDebugInfoBitNV:
            return "EnableShaderDebugInfoBitNV";
        case VqDeviceDiagnosticsConfigFlagBits::EnableResourceTrackingBitNV:
            return "EnableResourceTrackingBitNV";
        case VqDeviceDiagnosticsConfigFlagBits::EnableAutomaticCheckpointsBitNV:
            return "EnableAutomaticCheckpointsBitNV";
        case VqDeviceDiagnosticsConfigFlagBits::EnableShaderErrorReportingBitNV:
            return "EnableShaderErrorReportingBitNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDeviceEventType v)
    {
        switch(v){
        case VqDeviceEventType::DisplayHotplugEXT:
            return "DisplayHotplugEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDeviceFaultAddressType v)
    {
        switch(v){
        case VqDeviceFaultAddressType::NoneEXT:
            return "NoneEXT";
        case VqDeviceFaultAddressType::ReadInvalidEXT:
            return "ReadInvalidEXT";
        case VqDeviceFaultAddressType::WriteInvalidEXT:
            return "WriteInvalidEXT";
        case VqDeviceFaultAddressType::ExecuteInvalidEXT:
            return "ExecuteInvalidEXT";
        case VqDeviceFaultAddressType::InstructionPointerUnknownEXT:
            return "InstructionPointerUnknownEXT";
        case VqDeviceFaultAddressType::InstructionPointerInvalidEXT:
            return "InstructionPointerInvalidEXT";
        case VqDeviceFaultAddressType::InstructionPointerFaultEXT:
            return "InstructionPointerFaultEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDeviceFaultVendorBinaryHeaderVersion v)
    {
        switch(v){
        case VqDeviceFaultVendorBinaryHeaderVersion::OneEXT:
            return "OneEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDeviceGroupPresentModeFlagBits v)
    {
        switch(v){
        case VqDeviceGroupPresentModeFlagBits::LocalBitKHR:
            return "LocalBitKHR";
        case VqDeviceGroupPresentModeFlagBits::RemoteBitKHR:
            return "RemoteBitKHR";
        case VqDeviceGroupPresentModeFlagBits::SumBitKHR:
            return "SumBitKHR";
        case VqDeviceGroupPresentModeFlagBits::LocalMultiDeviceBitKHR:
            return "LocalMultiDeviceBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDeviceMemoryReportEventType v)
    {
        switch(v){
        case VqDeviceMemoryReportEventType::AllocateEXT:
            return "AllocateEXT";
        case VqDeviceMemoryReportEventType::FreeEXT:
            return "FreeEXT";
        case VqDeviceMemoryReportEventType::ImportEXT:
            return "ImportEXT";
        case VqDeviceMemoryReportEventType::UnimportEXT:
            return "UnimportEXT";
        case VqDeviceMemoryReportEventType::AllocationFailedEXT:
            return "AllocationFailedEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDeviceQueueCreateFlagBits v)
    {
        switch(v){
        case VqDeviceQueueCreateFlagBits::ProtectedBit:
            return "ProtectedBit";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDirectDriverLoadingMode v)
    {
        switch(v){
        case VqDirectDriverLoadingMode::ExclusiveLUNARG:
            return "ExclusiveLUNARG";
        case VqDirectDriverLoadingMode::InclusiveLUNARG:
            return "InclusiveLUNARG";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDiscardRectangleMode v)
    {
        switch(v){
        case VqDiscardRectangleMode::InclusiveEXT:
            return "InclusiveEXT";
        case VqDiscardRectangleMode::ExclusiveEXT:
            return "ExclusiveEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDisplayEventType v)
    {
        switch(v){
        case VqDisplayEventType::FirstPixelOutEXT:
            return "FirstPixelOutEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDisplayPlaneAlphaFlagBits v)
    {
        switch(v){
        case VqDisplayPlaneAlphaFlagBits::OpaqueBitKHR:
            return "OpaqueBitKHR";
        case VqDisplayPlaneAlphaFlagBits::GlobalBitKHR:
            return "GlobalBitKHR";
        case VqDisplayPlaneAlphaFlagBits::PerPixelBitKHR:
            return "PerPixelBitKHR";
        case VqDisplayPlaneAlphaFlagBits::PerPixelPremultipliedBitKHR:
            return "PerPixelPremultipliedBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDisplayPowerState v)
    {
        switch(v){
        case VqDisplayPowerState::OffEXT:
            return "OffEXT";
        case VqDisplayPowerState::SuspendEXT:
            return "SuspendEXT";
        case VqDisplayPowerState::OnEXT:
            return "OnEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDriverId v)
    {
        switch(v){
        case VqDriverId::AMDProprietary:
            return "AMDProprietary";
        case VqDriverId::AMDOpenSource:
            return "AMDOpenSource";
        case VqDriverId::MesaRadv:
            return "MesaRadv";
        case VqDriverId::NvidiaProprietary:
            return "NvidiaProprietary";
        case VqDriverId::INTELProprietaryWindows:
            return "INTELProprietaryWindows";
        case VqDriverId::INTELOpenSourceMesa:
            return "INTELOpenSourceMesa";
        case VqDriverId::ImaginationProprietary:
            return "ImaginationProprietary";
        case VqDriverId::QualcommProprietary:
            return "QualcommProprietary";
        case VqDriverId::ArmProprietary:
            return "ArmProprietary";
        case VqDriverId::GoogleSwiftshader:
            return "GoogleSwiftshader";
        case VqDriverId::GgpProprietary:
            return "GgpProprietary";
        case VqDriverId::BroadcomProprietary:
            return "BroadcomProprietary";
        case VqDriverId::MesaLlvmpipe:
            return "MesaLlvmpipe";
        case VqDriverId::Moltenvk:
            return "Moltenvk";
        case VqDriverId::CoreaviProprietary:
            return "CoreaviProprietary";
        case VqDriverId::JuiceProprietary:
            return "JuiceProprietary";
        case VqDriverId::VerisiliconProprietary:
            return "VerisiliconProprietary";
        case VqDriverId::MesaTurnip:
            return "MesaTurnip";
        case VqDriverId::MesaV3dv:
            return "MesaV3dv";
        case VqDriverId::MesaPanvk:
            return "MesaPanvk";
        case VqDriverId::SamsungProprietary:
            return "SamsungProprietary";
        case VqDriverId::MesaVenus:
            return "MesaVenus";
        case VqDriverId::MesaDozen:
            return "MesaDozen";
        case VqDriverId::MesaNvk:
            return "MesaNvk";
        case VqDriverId::ImaginationOpenSourceMesa:
            return "ImaginationOpenSourceMesa";
        case VqDriverId::MesaHoneykrisp:
            return "MesaHoneykrisp";
        case VqDriverId::Reserved27:
            return "Reserved27";
        case VqDriverId::AMDProprietaryKHR:
            return "AMDProprietaryKHR";
        case VqDriverId::AMDOpenSourceKHR:
            return "AMDOpenSourceKHR";
        case VqDriverId::MesaRadvKHR:
            return "MesaRadvKHR";
        case VqDriverId::NvidiaProprietaryKHR:
            return "NvidiaProprietaryKHR";
        case VqDriverId::INTELProprietaryWindowsKHR:
            return "INTELProprietaryWindowsKHR";
        case VqDriverId::INTELOpenSourceMesaKHR:
            return "INTELOpenSourceMesaKHR";
        case VqDriverId::ImaginationProprietaryKHR:
            return "ImaginationProprietaryKHR";
        case VqDriverId::QualcommProprietaryKHR:
            return "QualcommProprietaryKHR";
        case VqDriverId::ArmProprietaryKHR:
            return "ArmProprietaryKHR";
        case VqDriverId::GoogleSwiftshaderKHR:
            return "GoogleSwiftshaderKHR";
        case VqDriverId::GgpProprietaryKHR:
            return "GgpProprietaryKHR";
        case VqDriverId::BroadcomProprietaryKHR:
            return "BroadcomProprietaryKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDynamicState v)
    {
        switch(v){
        case VqDynamicState::Viewport:
            return "Viewport";
        case VqDynamicState::Scissor:
            return "Scissor";
        case VqDynamicState::LineWidth:
            return "LineWidth";
        case VqDynamicState::DepthBias:
            return "DepthBias";
        case VqDynamicState::BlendConstants:
            return "BlendConstants";
        case VqDynamicState::DepthBounds:
            return "DepthBounds";
        case VqDynamicState::StencilCompareMask:
            return "StencilCompareMask";
        case VqDynamicState::StencilWriteMask:
            return "StencilWriteMask";
        case VqDynamicState::StencilReference:
            return "StencilReference";
        case VqDynamicState::CullMode:
            return "CullMode";
        case VqDynamicState::FrontFace:
            return "FrontFace";
        case VqDynamicState::PrimitiveTopology:
            return "PrimitiveTopology";
        case VqDynamicState::ViewportWithCount:
            return "ViewportWithCount";
        case VqDynamicState::ScissorWithCount:
            return "ScissorWithCount";
        case VqDynamicState::VertexInputBindingStride:
            return "VertexInputBindingStride";
        case VqDynamicState::DepthTestEnable:
            return "DepthTestEnable";
        case VqDynamicState::DepthWriteEnable:
            return "DepthWriteEnable";
        case VqDynamicState::DepthCompareOp:
            return "DepthCompareOp";
        case VqDynamicState::DepthBoundsTestEnable:
            return "DepthBoundsTestEnable";
        case VqDynamicState::StencilTestEnable:
            return "StencilTestEnable";
        case VqDynamicState::StencilOp:
            return "StencilOp";
        case VqDynamicState::RasterizerDiscardEnable:
            return "RasterizerDiscardEnable";
        case VqDynamicState::DepthBiasEnable:
            return "DepthBiasEnable";
        case VqDynamicState::PrimitiveRestartEnable:
            return "PrimitiveRestartEnable";
        case VqDynamicState::ViewportWScalingNV:
            return "ViewportWScalingNV";
        case VqDynamicState::DiscardRectangleEXT:
            return "DiscardRectangleEXT";
        case VqDynamicState::DiscardRectangleEnableEXT:
            return "DiscardRectangleEnableEXT";
        case VqDynamicState::DiscardRectangleModeEXT:
            return "DiscardRectangleModeEXT";
        case VqDynamicState::SampleLocationsEXT:
            return "SampleLocationsEXT";
        case VqDynamicState::RayTracingPipelineStackSizeKHR:
            return "RayTracingPipelineStackSizeKHR";
        case VqDynamicState::ViewportShadingRatePaletteNV:
            return "ViewportShadingRatePaletteNV";
        case VqDynamicState::ViewportCoarseSampleOrderNV:
            return "ViewportCoarseSampleOrderNV";
        case VqDynamicState::ExclusiveScissorEnableNV:
            return "ExclusiveScissorEnableNV";
        case VqDynamicState::ExclusiveScissorNV:
            return "ExclusiveScissorNV";
        case VqDynamicState::FragmentShadingRateKHR:
            return "FragmentShadingRateKHR";
        case VqDynamicState::VertexInputEXT:
            return "VertexInputEXT";
        case VqDynamicState::PatchControlPointsEXT:
            return "PatchControlPointsEXT";
        case VqDynamicState::LogicOpEXT:
            return "LogicOpEXT";
        case VqDynamicState::ColorWriteEnableEXT:
            return "ColorWriteEnableEXT";
        case VqDynamicState::DepthClampEnableEXT:
            return "DepthClampEnableEXT";
        case VqDynamicState::PolygonModeEXT:
            return "PolygonModeEXT";
        case VqDynamicState::RasterizationSamplesEXT:
            return "RasterizationSamplesEXT";
        case VqDynamicState::SampleMaskEXT:
            return "SampleMaskEXT";
        case VqDynamicState::AlphaToCoverageEnableEXT:
            return "AlphaToCoverageEnableEXT";
        case VqDynamicState::AlphaToOneEnableEXT:
            return "AlphaToOneEnableEXT";
        case VqDynamicState::LogicOpEnableEXT:
            return "LogicOpEnableEXT";
        case VqDynamicState::ColorBlendEnableEXT:
            return "ColorBlendEnableEXT";
        case VqDynamicState::ColorBlendEquationEXT:
            return "ColorBlendEquationEXT";
        case VqDynamicState::ColorWriteMaskEXT:
            return "ColorWriteMaskEXT";
        case VqDynamicState::TessellationDomainOriginEXT:
            return "TessellationDomainOriginEXT";
        case VqDynamicState::RasterizationStreamEXT:
            return "RasterizationStreamEXT";
        case VqDynamicState::ConservativeRasterizationModeEXT:
            return "ConservativeRasterizationModeEXT";
        case VqDynamicState::ExtraPrimitiveOverestimationSizeEXT:
            return "ExtraPrimitiveOverestimationSizeEXT";
        case VqDynamicState::DepthClipEnableEXT:
            return "DepthClipEnableEXT";
        case VqDynamicState::SampleLocationsEnableEXT:
            return "SampleLocationsEnableEXT";
        case VqDynamicState::ColorBlendAdvancedEXT:
            return "ColorBlendAdvancedEXT";
        case VqDynamicState::ProvokingVertexModeEXT:
            return "ProvokingVertexModeEXT";
        case VqDynamicState::LineRasterizationModeEXT:
            return "LineRasterizationModeEXT";
        case VqDynamicState::LineStippleEnableEXT:
            return "LineStippleEnableEXT";
        case VqDynamicState::DepthClipNegativeOneToOneEXT:
            return "DepthClipNegativeOneToOneEXT";
        case VqDynamicState::ViewportWScalingEnableNV:
            return "ViewportWScalingEnableNV";
        case VqDynamicState::ViewportSwizzleNV:
            return "ViewportSwizzleNV";
        case VqDynamicState::CoverageToColorEnableNV:
            return "CoverageToColorEnableNV";
        case VqDynamicState::CoverageToColorLocationNV:
            return "CoverageToColorLocationNV";
        case VqDynamicState::CoverageModulationModeNV:
            return "CoverageModulationModeNV";
        case VqDynamicState::CoverageModulationTableEnableNV:
            return "CoverageModulationTableEnableNV";
        case VqDynamicState::CoverageModulationTableNV:
            return "CoverageModulationTableNV";
        case VqDynamicState::ShadingRateImageEnableNV:
            return "ShadingRateImageEnableNV";
        case VqDynamicState::RepresentativeFragmentTestEnableNV:
            return "RepresentativeFragmentTestEnableNV";
        case VqDynamicState::CoverageReductionModeNV:
            return "CoverageReductionModeNV";
        case VqDynamicState::AttachmentFeedbackLoopEnableEXT:
            return "AttachmentFeedbackLoopEnableEXT";
        case VqDynamicState::LineStippleKHR:
            return "LineStippleKHR";
        case VqDynamicState::LineStippleEXT:
            return "LineStippleEXT";
        case VqDynamicState::CullModeEXT:
            return "CullModeEXT";
        case VqDynamicState::FrontFaceEXT:
            return "FrontFaceEXT";
        case VqDynamicState::PrimitiveTopologyEXT:
            return "PrimitiveTopologyEXT";
        case VqDynamicState::ViewportWithCountEXT:
            return "ViewportWithCountEXT";
        case VqDynamicState::ScissorWithCountEXT:
            return "ScissorWithCountEXT";
        case VqDynamicState::VertexInputBindingStrideEXT:
            return "VertexInputBindingStrideEXT";
        case VqDynamicState::DepthTestEnableEXT:
            return "DepthTestEnableEXT";
        case VqDynamicState::DepthWriteEnableEXT:
            return "DepthWriteEnableEXT";
        case VqDynamicState::DepthCompareOpEXT:
            return "DepthCompareOpEXT";
        case VqDynamicState::DepthBoundsTestEnableEXT:
            return "DepthBoundsTestEnableEXT";
        case VqDynamicState::StencilTestEnableEXT:
            return "StencilTestEnableEXT";
        case VqDynamicState::StencilOpEXT:
            return "StencilOpEXT";
        case VqDynamicState::RasterizerDiscardEnableEXT:
            return "RasterizerDiscardEnableEXT";
        case VqDynamicState::DepthBiasEnableEXT:
            return "DepthBiasEnableEXT";
        case VqDynamicState::PrimitiveRestartEnableEXT:
            return "PrimitiveRestartEnableEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqEventCreateFlagBits v)
    {
        switch(v){
        case VqEventCreateFlagBits::DeviceOnlyBit:
            return "DeviceOnlyBit";
        case VqEventCreateFlagBits::DeviceOnlyBitKHR:
            return "DeviceOnlyBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqExternalFenceFeatureFlagBits v)
    {
        switch(v){
        case VqExternalFenceFeatureFlagBits::ExportableBit:
            return "ExportableBit";
        case VqExternalFenceFeatureFlagBits::ImportableBit:
            return "ImportableBit";
        case VqExternalFenceFeatureFlagBits::ExportableBitKHR:
            return "ExportableBitKHR";
        case VqExternalFenceFeatureFlagBits::ImportableBitKHR:
            return "ImportableBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqExternalFenceHandleTypeFlagBits v)
    {
        switch(v){
        case VqExternalFenceHandleTypeFlagBits::OpaqueFdBit:
            return "OpaqueFdBit";
        case VqExternalFenceHandleTypeFlagBits::OpaqueWin32Bit:
            return "OpaqueWin32Bit";
        case VqExternalFenceHandleTypeFlagBits::OpaqueWin32KmtBit:
            return "OpaqueWin32KmtBit";
        case VqExternalFenceHandleTypeFlagBits::SyncFdBit:
            return "SyncFdBit";
        case VqExternalFenceHandleTypeFlagBits::OpaqueFdBitKHR:
            return "OpaqueFdBitKHR";
        case VqExternalFenceHandleTypeFlagBits::OpaqueWin32BitKHR:
            return "OpaqueWin32BitKHR";
        case VqExternalFenceHandleTypeFlagBits::OpaqueWin32KmtBitKHR:
            return "OpaqueWin32KmtBitKHR";
        case VqExternalFenceHandleTypeFlagBits::SyncFdBitKHR:
            return "SyncFdBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqExternalMemoryFeatureFlagBits v)
    {
        switch(v){
        case VqExternalMemoryFeatureFlagBits::DedicatedOnlyBit:
            return "DedicatedOnlyBit";
        case VqExternalMemoryFeatureFlagBits::ExportableBit:
            return "ExportableBit";
        case VqExternalMemoryFeatureFlagBits::ImportableBit:
            return "ImportableBit";
        case VqExternalMemoryFeatureFlagBits::DedicatedOnlyBitKHR:
            return "DedicatedOnlyBitKHR";
        case VqExternalMemoryFeatureFlagBits::ExportableBitKHR:
            return "ExportableBitKHR";
        case VqExternalMemoryFeatureFlagBits::ImportableBitKHR:
            return "ImportableBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqExternalMemoryFeatureFlagBits v)
    {
        switch(v){
        case VqExternalMemoryFeatureFlagBits::DedicatedOnlyBitNV:
            return "DedicatedOnlyBitNV";
        case VqExternalMemoryFeatureFlagBits::ExportableBitNV:
            return "ExportableBitNV";
        case VqExternalMemoryFeatureFlagBits::ImportableBitNV:
            return "ImportableBitNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqExternalMemoryHandleTypeFlagBits v)
    {
        switch(v){
        case VqExternalMemoryHandleTypeFlagBits::OpaqueFdBit:
            return "OpaqueFdBit";
        case VqExternalMemoryHandleTypeFlagBits::OpaqueWin32Bit:
            return "OpaqueWin32Bit";
        case VqExternalMemoryHandleTypeFlagBits::OpaqueWin32KmtBit:
            return "OpaqueWin32KmtBit";
        case VqExternalMemoryHandleTypeFlagBits::D3d11TextureBit:
            return "D3d11TextureBit";
        case VqExternalMemoryHandleTypeFlagBits::D3d11TextureKmtBit:
            return "D3d11TextureKmtBit";
        case VqExternalMemoryHandleTypeFlagBits::D3d12HeapBit:
            return "D3d12HeapBit";
        case VqExternalMemoryHandleTypeFlagBits::D3d12ResourceBit:
            return "D3d12ResourceBit";
        case VqExternalMemoryHandleTypeFlagBits::DmaBufBitEXT:
            return "DmaBufBitEXT";
        case VqExternalMemoryHandleTypeFlagBits::AndroidHardwareBufferBitAndroid:
            return "AndroidHardwareBufferBitAndroid";
        case VqExternalMemoryHandleTypeFlagBits::HostAllocationBitEXT:
            return "HostAllocationBitEXT";
        case VqExternalMemoryHandleTypeFlagBits::HostMappedForeignMemoryBitEXT:
            return "HostMappedForeignMemoryBitEXT";
        case VqExternalMemoryHandleTypeFlagBits::ZirconVmoBitFuchsia:
            return "ZirconVmoBitFuchsia";
        case VqExternalMemoryHandleTypeFlagBits::RdmaAddressBitNV:
            return "RdmaAddressBitNV";
        case VqExternalMemoryHandleTypeFlagBits::ScreenBufferBitQnx:
            return "ScreenBufferBitQnx";
        case VqExternalMemoryHandleTypeFlagBits::OpaqueFdBitKHR:
            return "OpaqueFdBitKHR";
        case VqExternalMemoryHandleTypeFlagBits::OpaqueWin32BitKHR:
            return "OpaqueWin32BitKHR";
        case VqExternalMemoryHandleTypeFlagBits::OpaqueWin32KmtBitKHR:
            return "OpaqueWin32KmtBitKHR";
        case VqExternalMemoryHandleTypeFlagBits::D3d11TextureBitKHR:
            return "D3d11TextureBitKHR";
        case VqExternalMemoryHandleTypeFlagBits::D3d11TextureKmtBitKHR:
            return "D3d11TextureKmtBitKHR";
        case VqExternalMemoryHandleTypeFlagBits::D3d12HeapBitKHR:
            return "D3d12HeapBitKHR";
        case VqExternalMemoryHandleTypeFlagBits::D3d12ResourceBitKHR:
            return "D3d12ResourceBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqExternalMemoryHandleTypeFlagBits v)
    {
        switch(v){
        case VqExternalMemoryHandleTypeFlagBits::OpaqueWin32BitNV:
            return "OpaqueWin32BitNV";
        case VqExternalMemoryHandleTypeFlagBits::OpaqueWin32KmtBitNV:
            return "OpaqueWin32KmtBitNV";
        case VqExternalMemoryHandleTypeFlagBits::D3d11ImageBitNV:
            return "D3d11ImageBitNV";
        case VqExternalMemoryHandleTypeFlagBits::D3d11ImageKmtBitNV:
            return "D3d11ImageKmtBitNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqExternalSemaphoreFeatureFlagBits v)
    {
        switch(v){
        case VqExternalSemaphoreFeatureFlagBits::ExportableBit:
            return "ExportableBit";
        case VqExternalSemaphoreFeatureFlagBits::ImportableBit:
            return "ImportableBit";
        case VqExternalSemaphoreFeatureFlagBits::ExportableBitKHR:
            return "ExportableBitKHR";
        case VqExternalSemaphoreFeatureFlagBits::ImportableBitKHR:
            return "ImportableBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqExternalSemaphoreHandleTypeFlagBits v)
    {
        switch(v){
        case VqExternalSemaphoreHandleTypeFlagBits::OpaqueFdBit:
            return "OpaqueFdBit";
        case VqExternalSemaphoreHandleTypeFlagBits::OpaqueWin32Bit:
            return "OpaqueWin32Bit";
        case VqExternalSemaphoreHandleTypeFlagBits::OpaqueWin32KmtBit:
            return "OpaqueWin32KmtBit";
        case VqExternalSemaphoreHandleTypeFlagBits::D3d12FenceBit:
            return "D3d12FenceBit";
        case VqExternalSemaphoreHandleTypeFlagBits::SyncFdBit:
            return "SyncFdBit";
        case VqExternalSemaphoreHandleTypeFlagBits::ZirconEventBitFuchsia:
            return "ZirconEventBitFuchsia";
        case VqExternalSemaphoreHandleTypeFlagBits::D3d11FenceBit:
            return "D3d11FenceBit";
        case VqExternalSemaphoreHandleTypeFlagBits::OpaqueFdBitKHR:
            return "OpaqueFdBitKHR";
        case VqExternalSemaphoreHandleTypeFlagBits::OpaqueWin32BitKHR:
            return "OpaqueWin32BitKHR";
        case VqExternalSemaphoreHandleTypeFlagBits::OpaqueWin32KmtBitKHR:
            return "OpaqueWin32KmtBitKHR";
        case VqExternalSemaphoreHandleTypeFlagBits::D3d12FenceBitKHR:
            return "D3d12FenceBitKHR";
        case VqExternalSemaphoreHandleTypeFlagBits::SyncFdBitKHR:
            return "SyncFdBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqFenceCreateFlagBits v)
    {
        switch(v){
        case VqFenceCreateFlagBits::SignaledBit:
            return "SignaledBit";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqFenceImportFlagBits v)
    {
        switch(v){
        case VqFenceImportFlagBits::TemporaryBit:
            return "TemporaryBit";
        case VqFenceImportFlagBits::TemporaryBitKHR:
            return "TemporaryBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqFilter v)
    {
        switch(v){
        case VqFilter::Nearest:
            return "Nearest";
        case VqFilter::Linear:
            return "Linear";
        case VqFilter::CubicEXT:
            return "CubicEXT";
        case VqFilter::CubicImg:
            return "CubicImg";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqFormat v)
    {
        switch(v){
        case VqFormat::Undefined:
            return "Undefined";
        case VqFormat::R4g4UnormPack8:
            return "R4g4UnormPack8";
        case VqFormat::R4g4b4a4UnormPack16:
            return "R4g4b4a4UnormPack16";
        case VqFormat::B4g4r4a4UnormPack16:
            return "B4g4r4a4UnormPack16";
        case VqFormat::R5g6b5UnormPack16:
            return "R5g6b5UnormPack16";
        case VqFormat::B5g6r5UnormPack16:
            return "B5g6r5UnormPack16";
        case VqFormat::R5g5b5a1UnormPack16:
            return "R5g5b5a1UnormPack16";
        case VqFormat::B5g5r5a1UnormPack16:
            return "B5g5r5a1UnormPack16";
        case VqFormat::A1r5g5b5UnormPack16:
            return "A1r5g5b5UnormPack16";
        case VqFormat::R8Unorm:
            return "R8Unorm";
        case VqFormat::R8Snorm:
            return "R8Snorm";
        case VqFormat::R8Uscaled:
            return "R8Uscaled";
        case VqFormat::R8Sscaled:
            return "R8Sscaled";
        case VqFormat::R8Uint:
            return "R8Uint";
        case VqFormat::R8Sint:
            return "R8Sint";
        case VqFormat::R8Srgb:
            return "R8Srgb";
        case VqFormat::R8g8Unorm:
            return "R8g8Unorm";
        case VqFormat::R8g8Snorm:
            return "R8g8Snorm";
        case VqFormat::R8g8Uscaled:
            return "R8g8Uscaled";
        case VqFormat::R8g8Sscaled:
            return "R8g8Sscaled";
        case VqFormat::R8g8Uint:
            return "R8g8Uint";
        case VqFormat::R8g8Sint:
            return "R8g8Sint";
        case VqFormat::R8g8Srgb:
            return "R8g8Srgb";
        case VqFormat::R8g8b8Unorm:
            return "R8g8b8Unorm";
        case VqFormat::R8g8b8Snorm:
            return "R8g8b8Snorm";
        case VqFormat::R8g8b8Uscaled:
            return "R8g8b8Uscaled";
        case VqFormat::R8g8b8Sscaled:
            return "R8g8b8Sscaled";
        case VqFormat::R8g8b8Uint:
            return "R8g8b8Uint";
        case VqFormat::R8g8b8Sint:
            return "R8g8b8Sint";
        case VqFormat::R8g8b8Srgb:
            return "R8g8b8Srgb";
        case VqFormat::B8g8r8Unorm:
            return "B8g8r8Unorm";
        case VqFormat::B8g8r8Snorm:
            return "B8g8r8Snorm";
        case VqFormat::B8g8r8Uscaled:
            return "B8g8r8Uscaled";
        case VqFormat::B8g8r8Sscaled:
            return "B8g8r8Sscaled";
        case VqFormat::B8g8r8Uint:
            return "B8g8r8Uint";
        case VqFormat::B8g8r8Sint:
            return "B8g8r8Sint";
        case VqFormat::B8g8r8Srgb:
            return "B8g8r8Srgb";
        case VqFormat::R8g8b8a8Unorm:
            return "R8g8b8a8Unorm";
        case VqFormat::R8g8b8a8Snorm:
            return "R8g8b8a8Snorm";
        case VqFormat::R8g8b8a8Uscaled:
            return "R8g8b8a8Uscaled";
        case VqFormat::R8g8b8a8Sscaled:
            return "R8g8b8a8Sscaled";
        case VqFormat::R8g8b8a8Uint:
            return "R8g8b8a8Uint";
        case VqFormat::R8g8b8a8Sint:
            return "R8g8b8a8Sint";
        case VqFormat::R8g8b8a8Srgb:
            return "R8g8b8a8Srgb";
        case VqFormat::B8g8r8a8Unorm:
            return "B8g8r8a8Unorm";
        case VqFormat::B8g8r8a8Snorm:
            return "B8g8r8a8Snorm";
        case VqFormat::B8g8r8a8Uscaled:
            return "B8g8r8a8Uscaled";
        case VqFormat::B8g8r8a8Sscaled:
            return "B8g8r8a8Sscaled";
        case VqFormat::B8g8r8a8Uint:
            return "B8g8r8a8Uint";
        case VqFormat::B8g8r8a8Sint:
            return "B8g8r8a8Sint";
        case VqFormat::B8g8r8a8Srgb:
            return "B8g8r8a8Srgb";
        case VqFormat::A8b8g8r8UnormPack32:
            return "A8b8g8r8UnormPack32";
        case VqFormat::A8b8g8r8SnormPack32:
            return "A8b8g8r8SnormPack32";
        case VqFormat::A8b8g8r8UscaledPack32:
            return "A8b8g8r8UscaledPack32";
        case VqFormat::A8b8g8r8SscaledPack32:
            return "A8b8g8r8SscaledPack32";
        case VqFormat::A8b8g8r8UintPack32:
            return "A8b8g8r8UintPack32";
        case VqFormat::A8b8g8r8SintPack32:
            return "A8b8g8r8SintPack32";
        case VqFormat::A8b8g8r8SrgbPack32:
            return "A8b8g8r8SrgbPack32";
        case VqFormat::A2r10g10b10UnormPack32:
            return "A2r10g10b10UnormPack32";
        case VqFormat::A2r10g10b10SnormPack32:
            return "A2r10g10b10SnormPack32";
        case VqFormat::A2r10g10b10UscaledPack32:
            return "A2r10g10b10UscaledPack32";
        case VqFormat::A2r10g10b10SscaledPack32:
            return "A2r10g10b10SscaledPack32";
        case VqFormat::A2r10g10b10UintPack32:
            return "A2r10g10b10UintPack32";
        case VqFormat::A2r10g10b10SintPack32:
            return "A2r10g10b10SintPack32";
        case VqFormat::A2b10g10r10UnormPack32:
            return "A2b10g10r10UnormPack32";
        case VqFormat::A2b10g10r10SnormPack32:
            return "A2b10g10r10SnormPack32";
        case VqFormat::A2b10g10r10UscaledPack32:
            return "A2b10g10r10UscaledPack32";
        case VqFormat::A2b10g10r10SscaledPack32:
            return "A2b10g10r10SscaledPack32";
        case VqFormat::A2b10g10r10UintPack32:
            return "A2b10g10r10UintPack32";
        case VqFormat::A2b10g10r10SintPack32:
            return "A2b10g10r10SintPack32";
        case VqFormat::R16Unorm:
            return "R16Unorm";
        case VqFormat::R16Snorm:
            return "R16Snorm";
        case VqFormat::R16Uscaled:
            return "R16Uscaled";
        case VqFormat::R16Sscaled:
            return "R16Sscaled";
        case VqFormat::R16Uint:
            return "R16Uint";
        case VqFormat::R16Sint:
            return "R16Sint";
        case VqFormat::R16Sfloat:
            return "R16Sfloat";
        case VqFormat::R16g16Unorm:
            return "R16g16Unorm";
        case VqFormat::R16g16Snorm:
            return "R16g16Snorm";
        case VqFormat::R16g16Uscaled:
            return "R16g16Uscaled";
        case VqFormat::R16g16Sscaled:
            return "R16g16Sscaled";
        case VqFormat::R16g16Uint:
            return "R16g16Uint";
        case VqFormat::R16g16Sint:
            return "R16g16Sint";
        case VqFormat::R16g16Sfloat:
            return "R16g16Sfloat";
        case VqFormat::R16g16b16Unorm:
            return "R16g16b16Unorm";
        case VqFormat::R16g16b16Snorm:
            return "R16g16b16Snorm";
        case VqFormat::R16g16b16Uscaled:
            return "R16g16b16Uscaled";
        case VqFormat::R16g16b16Sscaled:
            return "R16g16b16Sscaled";
        case VqFormat::R16g16b16Uint:
            return "R16g16b16Uint";
        case VqFormat::R16g16b16Sint:
            return "R16g16b16Sint";
        case VqFormat::R16g16b16Sfloat:
            return "R16g16b16Sfloat";
        case VqFormat::R16g16b16a16Unorm:
            return "R16g16b16a16Unorm";
        case VqFormat::R16g16b16a16Snorm:
            return "R16g16b16a16Snorm";
        case VqFormat::R16g16b16a16Uscaled:
            return "R16g16b16a16Uscaled";
        case VqFormat::R16g16b16a16Sscaled:
            return "R16g16b16a16Sscaled";
        case VqFormat::R16g16b16a16Uint:
            return "R16g16b16a16Uint";
        case VqFormat::R16g16b16a16Sint:
            return "R16g16b16a16Sint";
        case VqFormat::R16g16b16a16Sfloat:
            return "R16g16b16a16Sfloat";
        case VqFormat::R32Uint:
            return "R32Uint";
        case VqFormat::R32Sint:
            return "R32Sint";
        case VqFormat::R32Sfloat:
            return "R32Sfloat";
        case VqFormat::R32g32Uint:
            return "R32g32Uint";
        case VqFormat::R32g32Sint:
            return "R32g32Sint";
        case VqFormat::R32g32Sfloat:
            return "R32g32Sfloat";
        case VqFormat::R32g32b32Uint:
            return "R32g32b32Uint";
        case VqFormat::R32g32b32Sint:
            return "R32g32b32Sint";
        case VqFormat::R32g32b32Sfloat:
            return "R32g32b32Sfloat";
        case VqFormat::R32g32b32a32Uint:
            return "R32g32b32a32Uint";
        case VqFormat::R32g32b32a32Sint:
            return "R32g32b32a32Sint";
        case VqFormat::R32g32b32a32Sfloat:
            return "R32g32b32a32Sfloat";
        case VqFormat::R64Uint:
            return "R64Uint";
        case VqFormat::R64Sint:
            return "R64Sint";
        case VqFormat::R64Sfloat:
            return "R64Sfloat";
        case VqFormat::R64g64Uint:
            return "R64g64Uint";
        case VqFormat::R64g64Sint:
            return "R64g64Sint";
        case VqFormat::R64g64Sfloat:
            return "R64g64Sfloat";
        case VqFormat::R64g64b64Uint:
            return "R64g64b64Uint";
        case VqFormat::R64g64b64Sint:
            return "R64g64b64Sint";
        case VqFormat::R64g64b64Sfloat:
            return "R64g64b64Sfloat";
        case VqFormat::R64g64b64a64Uint:
            return "R64g64b64a64Uint";
        case VqFormat::R64g64b64a64Sint:
            return "R64g64b64a64Sint";
        case VqFormat::R64g64b64a64Sfloat:
            return "R64g64b64a64Sfloat";
        case VqFormat::B10g11r11UfloatPack32:
            return "B10g11r11UfloatPack32";
        case VqFormat::E5b9g9r9UfloatPack32:
            return "E5b9g9r9UfloatPack32";
        case VqFormat::D16Unorm:
            return "D16Unorm";
        case VqFormat::X8D24UnormPack32:
            return "X8D24UnormPack32";
        case VqFormat::D32Sfloat:
            return "D32Sfloat";
        case VqFormat::S8Uint:
            return "S8Uint";
        case VqFormat::D16UnormS8Uint:
            return "D16UnormS8Uint";
        case VqFormat::D24UnormS8Uint:
            return "D24UnormS8Uint";
        case VqFormat::D32SfloatS8Uint:
            return "D32SfloatS8Uint";
        case VqFormat::Bc1RgbUnormBlock:
            return "Bc1RgbUnormBlock";
        case VqFormat::Bc1RgbSrgbBlock:
            return "Bc1RgbSrgbBlock";
        case VqFormat::Bc1RgbaUnormBlock:
            return "Bc1RgbaUnormBlock";
        case VqFormat::Bc1RgbaSrgbBlock:
            return "Bc1RgbaSrgbBlock";
        case VqFormat::Bc2UnormBlock:
            return "Bc2UnormBlock";
        case VqFormat::Bc2SrgbBlock:
            return "Bc2SrgbBlock";
        case VqFormat::Bc3UnormBlock:
            return "Bc3UnormBlock";
        case VqFormat::Bc3SrgbBlock:
            return "Bc3SrgbBlock";
        case VqFormat::Bc4UnormBlock:
            return "Bc4UnormBlock";
        case VqFormat::Bc4SnormBlock:
            return "Bc4SnormBlock";
        case VqFormat::Bc5UnormBlock:
            return "Bc5UnormBlock";
        case VqFormat::Bc5SnormBlock:
            return "Bc5SnormBlock";
        case VqFormat::Bc6hUfloatBlock:
            return "Bc6hUfloatBlock";
        case VqFormat::Bc6hSfloatBlock:
            return "Bc6hSfloatBlock";
        case VqFormat::Bc7UnormBlock:
            return "Bc7UnormBlock";
        case VqFormat::Bc7SrgbBlock:
            return "Bc7SrgbBlock";
        case VqFormat::Etc2R8g8b8UnormBlock:
            return "Etc2R8g8b8UnormBlock";
        case VqFormat::Etc2R8g8b8SrgbBlock:
            return "Etc2R8g8b8SrgbBlock";
        case VqFormat::Etc2R8g8b8a1UnormBlock:
            return "Etc2R8g8b8a1UnormBlock";
        case VqFormat::Etc2R8g8b8a1SrgbBlock:
            return "Etc2R8g8b8a1SrgbBlock";
        case VqFormat::Etc2R8g8b8a8UnormBlock:
            return "Etc2R8g8b8a8UnormBlock";
        case VqFormat::Etc2R8g8b8a8SrgbBlock:
            return "Etc2R8g8b8a8SrgbBlock";
        case VqFormat::EacR11UnormBlock:
            return "EacR11UnormBlock";
        case VqFormat::EacR11SnormBlock:
            return "EacR11SnormBlock";
        case VqFormat::EacR11g11UnormBlock:
            return "EacR11g11UnormBlock";
        case VqFormat::EacR11g11SnormBlock:
            return "EacR11g11SnormBlock";
        case VqFormat::Astc4x4UnormBlock:
            return "Astc4x4UnormBlock";
        case VqFormat::Astc4x4SrgbBlock:
            return "Astc4x4SrgbBlock";
        case VqFormat::Astc5x4UnormBlock:
            return "Astc5x4UnormBlock";
        case VqFormat::Astc5x4SrgbBlock:
            return "Astc5x4SrgbBlock";
        case VqFormat::Astc5x5UnormBlock:
            return "Astc5x5UnormBlock";
        case VqFormat::Astc5x5SrgbBlock:
            return "Astc5x5SrgbBlock";
        case VqFormat::Astc6x5UnormBlock:
            return "Astc6x5UnormBlock";
        case VqFormat::Astc6x5SrgbBlock:
            return "Astc6x5SrgbBlock";
        case VqFormat::Astc6x6UnormBlock:
            return "Astc6x6UnormBlock";
        case VqFormat::Astc6x6SrgbBlock:
            return "Astc6x6SrgbBlock";
        case VqFormat::Astc8x5UnormBlock:
            return "Astc8x5UnormBlock";
        case VqFormat::Astc8x5SrgbBlock:
            return "Astc8x5SrgbBlock";
        case VqFormat::Astc8x6UnormBlock:
            return "Astc8x6UnormBlock";
        case VqFormat::Astc8x6SrgbBlock:
            return "Astc8x6SrgbBlock";
        case VqFormat::Astc8x8UnormBlock:
            return "Astc8x8UnormBlock";
        case VqFormat::Astc8x8SrgbBlock:
            return "Astc8x8SrgbBlock";
        case VqFormat::Astc10x5UnormBlock:
            return "Astc10x5UnormBlock";
        case VqFormat::Astc10x5SrgbBlock:
            return "Astc10x5SrgbBlock";
        case VqFormat::Astc10x6UnormBlock:
            return "Astc10x6UnormBlock";
        case VqFormat::Astc10x6SrgbBlock:
            return "Astc10x6SrgbBlock";
        case VqFormat::Astc10x8UnormBlock:
            return "Astc10x8UnormBlock";
        case VqFormat::Astc10x8SrgbBlock:
            return "Astc10x8SrgbBlock";
        case VqFormat::Astc10x10UnormBlock:
            return "Astc10x10UnormBlock";
        case VqFormat::Astc10x10SrgbBlock:
            return "Astc10x10SrgbBlock";
        case VqFormat::Astc12x10UnormBlock:
            return "Astc12x10UnormBlock";
        case VqFormat::Astc12x10SrgbBlock:
            return "Astc12x10SrgbBlock";
        case VqFormat::Astc12x12UnormBlock:
            return "Astc12x12UnormBlock";
        case VqFormat::Astc12x12SrgbBlock:
            return "Astc12x12SrgbBlock";
        case VqFormat::G8b8g8r8422Unorm:
            return "G8b8g8r8422Unorm";
        case VqFormat::B8g8r8g8422Unorm:
            return "B8g8r8g8422Unorm";
        case VqFormat::G8B8R83plane420Unorm:
            return "G8B8R83plane420Unorm";
        case VqFormat::G8B8r82plane420Unorm:
            return "G8B8r82plane420Unorm";
        case VqFormat::G8B8R83plane422Unorm:
            return "G8B8R83plane422Unorm";
        case VqFormat::G8B8r82plane422Unorm:
            return "G8B8r82plane422Unorm";
        case VqFormat::G8B8R83plane444Unorm:
            return "G8B8R83plane444Unorm";
        case VqFormat::R10x6UnormPack16:
            return "R10x6UnormPack16";
        case VqFormat::R10x6g10x6Unorm2pack16:
            return "R10x6g10x6Unorm2pack16";
        case VqFormat::R10x6g10x6b10x6a10x6Unorm4pack16:
            return "R10x6g10x6b10x6a10x6Unorm4pack16";
        case VqFormat::G10x6b10x6g10x6r10x6422Unorm4pack16:
            return "G10x6b10x6g10x6r10x6422Unorm4pack16";
        case VqFormat::B10x6g10x6r10x6g10x6422Unorm4pack16:
            return "B10x6g10x6r10x6g10x6422Unorm4pack16";
        case VqFormat::G10x6B10x6R10x63plane420Unorm3pack16:
            return "G10x6B10x6R10x63plane420Unorm3pack16";
        case VqFormat::G10x6B10x6r10x62plane420Unorm3pack16:
            return "G10x6B10x6r10x62plane420Unorm3pack16";
        case VqFormat::G10x6B10x6R10x63plane422Unorm3pack16:
            return "G10x6B10x6R10x63plane422Unorm3pack16";
        case VqFormat::G10x6B10x6r10x62plane422Unorm3pack16:
            return "G10x6B10x6r10x62plane422Unorm3pack16";
        case VqFormat::G10x6B10x6R10x63plane444Unorm3pack16:
            return "G10x6B10x6R10x63plane444Unorm3pack16";
        case VqFormat::R12x4UnormPack16:
            return "R12x4UnormPack16";
        case VqFormat::R12x4g12x4Unorm2pack16:
            return "R12x4g12x4Unorm2pack16";
        case VqFormat::R12x4g12x4b12x4a12x4Unorm4pack16:
            return "R12x4g12x4b12x4a12x4Unorm4pack16";
        case VqFormat::G12x4b12x4g12x4r12x4422Unorm4pack16:
            return "G12x4b12x4g12x4r12x4422Unorm4pack16";
        case VqFormat::B12x4g12x4r12x4g12x4422Unorm4pack16:
            return "B12x4g12x4r12x4g12x4422Unorm4pack16";
        case VqFormat::G12x4B12x4R12x43plane420Unorm3pack16:
            return "G12x4B12x4R12x43plane420Unorm3pack16";
        case VqFormat::G12x4B12x4r12x42plane420Unorm3pack16:
            return "G12x4B12x4r12x42plane420Unorm3pack16";
        case VqFormat::G12x4B12x4R12x43plane422Unorm3pack16:
            return "G12x4B12x4R12x43plane422Unorm3pack16";
        case VqFormat::G12x4B12x4r12x42plane422Unorm3pack16:
            return "G12x4B12x4r12x42plane422Unorm3pack16";
        case VqFormat::G12x4B12x4R12x43plane444Unorm3pack16:
            return "G12x4B12x4R12x43plane444Unorm3pack16";
        case VqFormat::G16b16g16r16422Unorm:
            return "G16b16g16r16422Unorm";
        case VqFormat::B16g16r16g16422Unorm:
            return "B16g16r16g16422Unorm";
        case VqFormat::G16B16R163plane420Unorm:
            return "G16B16R163plane420Unorm";
        case VqFormat::G16B16r162plane420Unorm:
            return "G16B16r162plane420Unorm";
        case VqFormat::G16B16R163plane422Unorm:
            return "G16B16R163plane422Unorm";
        case VqFormat::G16B16r162plane422Unorm:
            return "G16B16r162plane422Unorm";
        case VqFormat::G16B16R163plane444Unorm:
            return "G16B16R163plane444Unorm";
        case VqFormat::G8B8r82plane444Unorm:
            return "G8B8r82plane444Unorm";
        case VqFormat::G10x6B10x6r10x62plane444Unorm3pack16:
            return "G10x6B10x6r10x62plane444Unorm3pack16";
        case VqFormat::G12x4B12x4r12x42plane444Unorm3pack16:
            return "G12x4B12x4r12x42plane444Unorm3pack16";
        case VqFormat::G16B16r162plane444Unorm:
            return "G16B16r162plane444Unorm";
        case VqFormat::A4r4g4b4UnormPack16:
            return "A4r4g4b4UnormPack16";
        case VqFormat::A4b4g4r4UnormPack16:
            return "A4b4g4r4UnormPack16";
        case VqFormat::Astc4x4SfloatBlock:
            return "Astc4x4SfloatBlock";
        case VqFormat::Astc5x4SfloatBlock:
            return "Astc5x4SfloatBlock";
        case VqFormat::Astc5x5SfloatBlock:
            return "Astc5x5SfloatBlock";
        case VqFormat::Astc6x5SfloatBlock:
            return "Astc6x5SfloatBlock";
        case VqFormat::Astc6x6SfloatBlock:
            return "Astc6x6SfloatBlock";
        case VqFormat::Astc8x5SfloatBlock:
            return "Astc8x5SfloatBlock";
        case VqFormat::Astc8x6SfloatBlock:
            return "Astc8x6SfloatBlock";
        case VqFormat::Astc8x8SfloatBlock:
            return "Astc8x8SfloatBlock";
        case VqFormat::Astc10x5SfloatBlock:
            return "Astc10x5SfloatBlock";
        case VqFormat::Astc10x6SfloatBlock:
            return "Astc10x6SfloatBlock";
        case VqFormat::Astc10x8SfloatBlock:
            return "Astc10x8SfloatBlock";
        case VqFormat::Astc10x10SfloatBlock:
            return "Astc10x10SfloatBlock";
        case VqFormat::Astc12x10SfloatBlock:
            return "Astc12x10SfloatBlock";
        case VqFormat::Astc12x12SfloatBlock:
            return "Astc12x12SfloatBlock";
        case VqFormat::Pvrtc12bppUnormBlockImg:
            return "Pvrtc12bppUnormBlockImg";
        case VqFormat::Pvrtc14bppUnormBlockImg:
            return "Pvrtc14bppUnormBlockImg";
        case VqFormat::Pvrtc22bppUnormBlockImg:
            return "Pvrtc22bppUnormBlockImg";
        case VqFormat::Pvrtc24bppUnormBlockImg:
            return "Pvrtc24bppUnormBlockImg";
        case VqFormat::Pvrtc12bppSrgbBlockImg:
            return "Pvrtc12bppSrgbBlockImg";
        case VqFormat::Pvrtc14bppSrgbBlockImg:
            return "Pvrtc14bppSrgbBlockImg";
        case VqFormat::Pvrtc22bppSrgbBlockImg:
            return "Pvrtc22bppSrgbBlockImg";
        case VqFormat::Pvrtc24bppSrgbBlockImg:
            return "Pvrtc24bppSrgbBlockImg";
        case VqFormat::R16g16Sfixed5NV:
            return "R16g16Sfixed5NV";
        case VqFormat::A1b5g5r5UnormPack16KHR:
            return "A1b5g5r5UnormPack16KHR";
        case VqFormat::A8UnormKHR:
            return "A8UnormKHR";
        case VqFormat::Astc4x4SfloatBlockEXT:
            return "Astc4x4SfloatBlockEXT";
        case VqFormat::Astc5x4SfloatBlockEXT:
            return "Astc5x4SfloatBlockEXT";
        case VqFormat::Astc5x5SfloatBlockEXT:
            return "Astc5x5SfloatBlockEXT";
        case VqFormat::Astc6x5SfloatBlockEXT:
            return "Astc6x5SfloatBlockEXT";
        case VqFormat::Astc6x6SfloatBlockEXT:
            return "Astc6x6SfloatBlockEXT";
        case VqFormat::Astc8x5SfloatBlockEXT:
            return "Astc8x5SfloatBlockEXT";
        case VqFormat::Astc8x6SfloatBlockEXT:
            return "Astc8x6SfloatBlockEXT";
        case VqFormat::Astc8x8SfloatBlockEXT:
            return "Astc8x8SfloatBlockEXT";
        case VqFormat::Astc10x5SfloatBlockEXT:
            return "Astc10x5SfloatBlockEXT";
        case VqFormat::Astc10x6SfloatBlockEXT:
            return "Astc10x6SfloatBlockEXT";
        case VqFormat::Astc10x8SfloatBlockEXT:
            return "Astc10x8SfloatBlockEXT";
        case VqFormat::Astc10x10SfloatBlockEXT:
            return "Astc10x10SfloatBlockEXT";
        case VqFormat::Astc12x10SfloatBlockEXT:
            return "Astc12x10SfloatBlockEXT";
        case VqFormat::Astc12x12SfloatBlockEXT:
            return "Astc12x12SfloatBlockEXT";
        case VqFormat::G8b8g8r8422UnormKHR:
            return "G8b8g8r8422UnormKHR";
        case VqFormat::B8g8r8g8422UnormKHR:
            return "B8g8r8g8422UnormKHR";
        case VqFormat::G8B8R83plane420UnormKHR:
            return "G8B8R83plane420UnormKHR";
        case VqFormat::G8B8r82plane420UnormKHR:
            return "G8B8r82plane420UnormKHR";
        case VqFormat::G8B8R83plane422UnormKHR:
            return "G8B8R83plane422UnormKHR";
        case VqFormat::G8B8r82plane422UnormKHR:
            return "G8B8r82plane422UnormKHR";
        case VqFormat::G8B8R83plane444UnormKHR:
            return "G8B8R83plane444UnormKHR";
        case VqFormat::R10x6UnormPack16KHR:
            return "R10x6UnormPack16KHR";
        case VqFormat::R10x6g10x6Unorm2pack16KHR:
            return "R10x6g10x6Unorm2pack16KHR";
        case VqFormat::R10x6g10x6b10x6a10x6Unorm4pack16KHR:
            return "R10x6g10x6b10x6a10x6Unorm4pack16KHR";
        case VqFormat::G10x6b10x6g10x6r10x6422Unorm4pack16KHR:
            return "G10x6b10x6g10x6r10x6422Unorm4pack16KHR";
        case VqFormat::B10x6g10x6r10x6g10x6422Unorm4pack16KHR:
            return "B10x6g10x6r10x6g10x6422Unorm4pack16KHR";
        case VqFormat::G10x6B10x6R10x63plane420Unorm3pack16KHR:
            return "G10x6B10x6R10x63plane420Unorm3pack16KHR";
        case VqFormat::G10x6B10x6r10x62plane420Unorm3pack16KHR:
            return "G10x6B10x6r10x62plane420Unorm3pack16KHR";
        case VqFormat::G10x6B10x6R10x63plane422Unorm3pack16KHR:
            return "G10x6B10x6R10x63plane422Unorm3pack16KHR";
        case VqFormat::G10x6B10x6r10x62plane422Unorm3pack16KHR:
            return "G10x6B10x6r10x62plane422Unorm3pack16KHR";
        case VqFormat::G10x6B10x6R10x63plane444Unorm3pack16KHR:
            return "G10x6B10x6R10x63plane444Unorm3pack16KHR";
        case VqFormat::R12x4UnormPack16KHR:
            return "R12x4UnormPack16KHR";
        case VqFormat::R12x4g12x4Unorm2pack16KHR:
            return "R12x4g12x4Unorm2pack16KHR";
        case VqFormat::R12x4g12x4b12x4a12x4Unorm4pack16KHR:
            return "R12x4g12x4b12x4a12x4Unorm4pack16KHR";
        case VqFormat::G12x4b12x4g12x4r12x4422Unorm4pack16KHR:
            return "G12x4b12x4g12x4r12x4422Unorm4pack16KHR";
        case VqFormat::B12x4g12x4r12x4g12x4422Unorm4pack16KHR:
            return "B12x4g12x4r12x4g12x4422Unorm4pack16KHR";
        case VqFormat::G12x4B12x4R12x43plane420Unorm3pack16KHR:
            return "G12x4B12x4R12x43plane420Unorm3pack16KHR";
        case VqFormat::G12x4B12x4r12x42plane420Unorm3pack16KHR:
            return "G12x4B12x4r12x42plane420Unorm3pack16KHR";
        case VqFormat::G12x4B12x4R12x43plane422Unorm3pack16KHR:
            return "G12x4B12x4R12x43plane422Unorm3pack16KHR";
        case VqFormat::G12x4B12x4r12x42plane422Unorm3pack16KHR:
            return "G12x4B12x4r12x42plane422Unorm3pack16KHR";
        case VqFormat::G12x4B12x4R12x43plane444Unorm3pack16KHR:
            return "G12x4B12x4R12x43plane444Unorm3pack16KHR";
        case VqFormat::G16b16g16r16422UnormKHR:
            return "G16b16g16r16422UnormKHR";
        case VqFormat::B16g16r16g16422UnormKHR:
            return "B16g16r16g16422UnormKHR";
        case VqFormat::G16B16R163plane420UnormKHR:
            return "G16B16R163plane420UnormKHR";
        case VqFormat::G16B16r162plane420UnormKHR:
            return "G16B16r162plane420UnormKHR";
        case VqFormat::G16B16R163plane422UnormKHR:
            return "G16B16R163plane422UnormKHR";
        case VqFormat::G16B16r162plane422UnormKHR:
            return "G16B16r162plane422UnormKHR";
        case VqFormat::G16B16R163plane444UnormKHR:
            return "G16B16R163plane444UnormKHR";
        case VqFormat::G8B8r82plane444UnormEXT:
            return "G8B8r82plane444UnormEXT";
        case VqFormat::G10x6B10x6r10x62plane444Unorm3pack16EXT:
            return "G10x6B10x6r10x62plane444Unorm3pack16EXT";
        case VqFormat::G12x4B12x4r12x42plane444Unorm3pack16EXT:
            return "G12x4B12x4r12x42plane444Unorm3pack16EXT";
        case VqFormat::G16B16r162plane444UnormEXT:
            return "G16B16r162plane444UnormEXT";
        case VqFormat::A4r4g4b4UnormPack16EXT:
            return "A4r4g4b4UnormPack16EXT";
        case VqFormat::A4b4g4r4UnormPack16EXT:
            return "A4b4g4r4UnormPack16EXT";
        case VqFormat::R16g16S105NV:
            return "R16g16S105NV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqFormatFeatureFlagBits v)
    {
        switch(v){
        case VqFormatFeatureFlagBits::SampledImageBit:
            return "SampledImageBit";
        case VqFormatFeatureFlagBits::StorageImageBit:
            return "StorageImageBit";
        case VqFormatFeatureFlagBits::StorageImageAtomicBit:
            return "StorageImageAtomicBit";
        case VqFormatFeatureFlagBits::UniformTexelBufferBit:
            return "UniformTexelBufferBit";
        case VqFormatFeatureFlagBits::StorageTexelBufferBit:
            return "StorageTexelBufferBit";
        case VqFormatFeatureFlagBits::StorageTexelBufferAtomicBit:
            return "StorageTexelBufferAtomicBit";
        case VqFormatFeatureFlagBits::VertexBufferBit:
            return "VertexBufferBit";
        case VqFormatFeatureFlagBits::ColorAttachmentBit:
            return "ColorAttachmentBit";
        case VqFormatFeatureFlagBits::ColorAttachmentBlendBit:
            return "ColorAttachmentBlendBit";
        case VqFormatFeatureFlagBits::DepthStencilAttachmentBit:
            return "DepthStencilAttachmentBit";
        case VqFormatFeatureFlagBits::BlitSrcBit:
            return "BlitSrcBit";
        case VqFormatFeatureFlagBits::BlitDstBit:
            return "BlitDstBit";
        case VqFormatFeatureFlagBits::SampledImageFilterLinearBit:
            return "SampledImageFilterLinearBit";
        case VqFormatFeatureFlagBits::TransferSrcBit:
            return "TransferSrcBit";
        case VqFormatFeatureFlagBits::TransferDstBit:
            return "TransferDstBit";
        case VqFormatFeatureFlagBits::MidpointChromaSamplesBit:
            return "MidpointChromaSamplesBit";
        case VqFormatFeatureFlagBits::SampledImageYcbcrConversionLinearFilterBit:
            return "SampledImageYcbcrConversionLinearFilterBit";
        case VqFormatFeatureFlagBits::SampledImageYcbcrConversionSeparateReconstructionFilterBit:
            return "SampledImageYcbcrConversionSeparateReconstructionFilterBit";
        case VqFormatFeatureFlagBits::SampledImageYcbcrConversionChromaReconstructionExplicitBit:
            return "SampledImageYcbcrConversionChromaReconstructionExplicitBit";
        case VqFormatFeatureFlagBits::SampledImageYcbcrConversionChromaReconstructionExplicitForceableBit:
            return "SampledImageYcbcrConversionChromaReconstructionExplicitForceableBit";
        case VqFormatFeatureFlagBits::DisjointBit:
            return "DisjointBit";
        case VqFormatFeatureFlagBits::CositedChromaSamplesBit:
            return "CositedChromaSamplesBit";
        case VqFormatFeatureFlagBits::SampledImageFilterMinmaxBit:
            return "SampledImageFilterMinmaxBit";
        case VqFormatFeatureFlagBits::VideoDecodeOutputBitKHR:
            return "VideoDecodeOutputBitKHR";
        case VqFormatFeatureFlagBits::VideoDecodeDpbBitKHR:
            return "VideoDecodeDpbBitKHR";
        case VqFormatFeatureFlagBits::AccelerationStructureVertexBufferBitKHR:
            return "AccelerationStructureVertexBufferBitKHR";
        case VqFormatFeatureFlagBits::SampledImageFilterCubicBitEXT:
            return "SampledImageFilterCubicBitEXT";
        case VqFormatFeatureFlagBits::FragmentDensityMapBitEXT:
            return "FragmentDensityMapBitEXT";
        case VqFormatFeatureFlagBits::FragmentShadingRateAttachmentBitKHR:
            return "FragmentShadingRateAttachmentBitKHR";
        case VqFormatFeatureFlagBits::VideoEncodeInputBitKHR:
            return "VideoEncodeInputBitKHR";
        case VqFormatFeatureFlagBits::VideoEncodeDpbBitKHR:
            return "VideoEncodeDpbBitKHR";
        case VqFormatFeatureFlagBits::SampledImageFilterCubicBitImg:
            return "SampledImageFilterCubicBitImg";
        case VqFormatFeatureFlagBits::TransferSrcBitKHR:
            return "TransferSrcBitKHR";
        case VqFormatFeatureFlagBits::TransferDstBitKHR:
            return "TransferDstBitKHR";
        case VqFormatFeatureFlagBits::SampledImageFilterMinmaxBitEXT:
            return "SampledImageFilterMinmaxBitEXT";
        case VqFormatFeatureFlagBits::MidpointChromaSamplesBitKHR:
            return "MidpointChromaSamplesBitKHR";
        case VqFormatFeatureFlagBits::SampledImageYcbcrConversionLinearFilterBitKHR:
            return "SampledImageYcbcrConversionLinearFilterBitKHR";
        case VqFormatFeatureFlagBits::SampledImageYcbcrConversionSeparateReconstructionFilterBitKHR:
            return "SampledImageYcbcrConversionSeparateReconstructionFilterBitKHR";
        case VqFormatFeatureFlagBits::SampledImageYcbcrConversionChromaReconstructionExplicitBitKHR:
            return "SampledImageYcbcrConversionChromaReconstructionExplicitBitKHR";
        case VqFormatFeatureFlagBits::SampledImageYcbcrConversionChromaReconstructionExplicitForceableBitKHR:
            return "SampledImageYcbcrConversionChromaReconstructionExplicitForceableBitKHR";
        case VqFormatFeatureFlagBits::DisjointBitKHR:
            return "DisjointBitKHR";
        case VqFormatFeatureFlagBits::CositedChromaSamplesBitKHR:
            return "CositedChromaSamplesBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqFragmentShadingRate v)
    {
        switch(v){
        case VqFragmentShadingRate::1InvocationPerPixelNV:
            return "1InvocationPerPixelNV";
        case VqFragmentShadingRate::1InvocationPer1x2PixelsNV:
            return "1InvocationPer1x2PixelsNV";
        case VqFragmentShadingRate::1InvocationPer2x1PixelsNV:
            return "1InvocationPer2x1PixelsNV";
        case VqFragmentShadingRate::1InvocationPer2x2PixelsNV:
            return "1InvocationPer2x2PixelsNV";
        case VqFragmentShadingRate::1InvocationPer2x4PixelsNV:
            return "1InvocationPer2x4PixelsNV";
        case VqFragmentShadingRate::1InvocationPer4x2PixelsNV:
            return "1InvocationPer4x2PixelsNV";
        case VqFragmentShadingRate::1InvocationPer4x4PixelsNV:
            return "1InvocationPer4x4PixelsNV";
        case VqFragmentShadingRate::2InvocationsPerPixelNV:
            return "2InvocationsPerPixelNV";
        case VqFragmentShadingRate::4InvocationsPerPixelNV:
            return "4InvocationsPerPixelNV";
        case VqFragmentShadingRate::8InvocationsPerPixelNV:
            return "8InvocationsPerPixelNV";
        case VqFragmentShadingRate::16InvocationsPerPixelNV:
            return "16InvocationsPerPixelNV";
        case VqFragmentShadingRate::NoInvocationsNV:
            return "NoInvocationsNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqFragmentShadingRateCombinerOp v)
    {
        switch(v){
        case VqFragmentShadingRateCombinerOp::KeepKHR:
            return "KeepKHR";
        case VqFragmentShadingRateCombinerOp::ReplaceKHR:
            return "ReplaceKHR";
        case VqFragmentShadingRateCombinerOp::MinKHR:
            return "MinKHR";
        case VqFragmentShadingRateCombinerOp::MaxKHR:
            return "MaxKHR";
        case VqFragmentShadingRateCombinerOp::MulKHR:
            return "MulKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqFragmentShadingRateType v)
    {
        switch(v){
        case VqFragmentShadingRateType::FragmentSizeNV:
            return "FragmentSizeNV";
        case VqFragmentShadingRateType::EnumsNV:
            return "EnumsNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqFrameBoundaryFlagBits v)
    {
        switch(v){
        case VqFrameBoundaryFlagBits::FrameEndBitEXT:
            return "FrameEndBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqFramebufferCreateFlagBits v)
    {
        switch(v){
        case VqFramebufferCreateFlagBits::ImagelessBit:
            return "ImagelessBit";
        case VqFramebufferCreateFlagBits::ImagelessBitKHR:
            return "ImagelessBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqFrontFace v)
    {
        switch(v){
        case VqFrontFace::CounterClockwise:
            return "CounterClockwise";
        case VqFrontFace::Clockwise:
            return "Clockwise";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqGeometryFlagBits v)
    {
        switch(v){
        case VqGeometryFlagBits::OpaqueBitKHR:
            return "OpaqueBitKHR";
        case VqGeometryFlagBits::NoDuplicateAnyHitInvocationBitKHR:
            return "NoDuplicateAnyHitInvocationBitKHR";
        case VqGeometryFlagBits::OpaqueBitNV:
            return "OpaqueBitNV";
        case VqGeometryFlagBits::NoDuplicateAnyHitInvocationBitNV:
            return "NoDuplicateAnyHitInvocationBitNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqGeometryInstanceFlagBits v)
    {
        switch(v){
        case VqGeometryInstanceFlagBits::TriangleFacingCullDisableBitKHR:
            return "TriangleFacingCullDisableBitKHR";
        case VqGeometryInstanceFlagBits::TriangleFlipFacingBitKHR:
            return "TriangleFlipFacingBitKHR";
        case VqGeometryInstanceFlagBits::ForceOpaqueBitKHR:
            return "ForceOpaqueBitKHR";
        case VqGeometryInstanceFlagBits::ForceNoOpaqueBitKHR:
            return "ForceNoOpaqueBitKHR";
        case VqGeometryInstanceFlagBits::ForceOpacityMicromap2StateEXT:
            return "ForceOpacityMicromap2StateEXT";
        case VqGeometryInstanceFlagBits::DisableOpacityMicromapsEXT:
            return "DisableOpacityMicromapsEXT";
        case VqGeometryInstanceFlagBits::TriangleFrontCounterclockwiseBitKHR:
            return "TriangleFrontCounterclockwiseBitKHR";
        case VqGeometryInstanceFlagBits::TriangleCullDisableBitNV:
            return "TriangleCullDisableBitNV";
        case VqGeometryInstanceFlagBits::TriangleFrontCounterclockwiseBitNV:
            return "TriangleFrontCounterclockwiseBitNV";
        case VqGeometryInstanceFlagBits::ForceOpaqueBitNV:
            return "ForceOpaqueBitNV";
        case VqGeometryInstanceFlagBits::ForceNoOpaqueBitNV:
            return "ForceNoOpaqueBitNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqGeometryType v)
    {
        switch(v){
        case VqGeometryType::TrianglesKHR:
            return "TrianglesKHR";
        case VqGeometryType::AabbsKHR:
            return "AabbsKHR";
        case VqGeometryType::InstancesKHR:
            return "InstancesKHR";
        case VqGeometryType::TrianglesNV:
            return "TrianglesNV";
        case VqGeometryType::AabbsNV:
            return "AabbsNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqGraphicsPipelineLibraryFlagBits v)
    {
        switch(v){
        case VqGraphicsPipelineLibraryFlagBits::VertexInputInterfaceBitEXT:
            return "VertexInputInterfaceBitEXT";
        case VqGraphicsPipelineLibraryFlagBits::PreRasterizationShadersBitEXT:
            return "PreRasterizationShadersBitEXT";
        case VqGraphicsPipelineLibraryFlagBits::FragmentShaderBitEXT:
            return "FragmentShaderBitEXT";
        case VqGraphicsPipelineLibraryFlagBits::FragmentOutputInterfaceBitEXT:
            return "FragmentOutputInterfaceBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqHostImageCopyFlagBits v)
    {
        switch(v){
        case VqHostImageCopyFlagBits::MemcpyEXT:
            return "MemcpyEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqImageAspectFlagBits v)
    {
        switch(v){
        case VqImageAspectFlagBits::ColorBit:
            return "ColorBit";
        case VqImageAspectFlagBits::DepthBit:
            return "DepthBit";
        case VqImageAspectFlagBits::StencilBit:
            return "StencilBit";
        case VqImageAspectFlagBits::MetadataBit:
            return "MetadataBit";
        case VqImageAspectFlagBits::Plane0Bit:
            return "Plane0Bit";
        case VqImageAspectFlagBits::Plane1Bit:
            return "Plane1Bit";
        case VqImageAspectFlagBits::Plane2Bit:
            return "Plane2Bit";
        case VqImageAspectFlagBits::None:
            return "None";
        case VqImageAspectFlagBits::MemoryPlane0BitEXT:
            return "MemoryPlane0BitEXT";
        case VqImageAspectFlagBits::MemoryPlane1BitEXT:
            return "MemoryPlane1BitEXT";
        case VqImageAspectFlagBits::MemoryPlane2BitEXT:
            return "MemoryPlane2BitEXT";
        case VqImageAspectFlagBits::MemoryPlane3BitEXT:
            return "MemoryPlane3BitEXT";
        case VqImageAspectFlagBits::Plane0BitKHR:
            return "Plane0BitKHR";
        case VqImageAspectFlagBits::Plane1BitKHR:
            return "Plane1BitKHR";
        case VqImageAspectFlagBits::Plane2BitKHR:
            return "Plane2BitKHR";
        case VqImageAspectFlagBits::NoneKHR:
            return "NoneKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqImageCompressionFixedRateFlagBits v)
    {
        switch(v){
        case VqImageCompressionFixedRateFlagBits::NoneEXT:
            return "NoneEXT";
        case VqImageCompressionFixedRateFlagBits::1bpcBitEXT:
            return "1bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::2bpcBitEXT:
            return "2bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::3bpcBitEXT:
            return "3bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::4bpcBitEXT:
            return "4bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::5bpcBitEXT:
            return "5bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::6bpcBitEXT:
            return "6bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::7bpcBitEXT:
            return "7bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::8bpcBitEXT:
            return "8bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::9bpcBitEXT:
            return "9bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::10bpcBitEXT:
            return "10bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::11bpcBitEXT:
            return "11bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::12bpcBitEXT:
            return "12bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::13bpcBitEXT:
            return "13bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::14bpcBitEXT:
            return "14bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::15bpcBitEXT:
            return "15bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::16bpcBitEXT:
            return "16bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::17bpcBitEXT:
            return "17bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::18bpcBitEXT:
            return "18bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::19bpcBitEXT:
            return "19bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::20bpcBitEXT:
            return "20bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::21bpcBitEXT:
            return "21bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::22bpcBitEXT:
            return "22bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::23bpcBitEXT:
            return "23bpcBitEXT";
        case VqImageCompressionFixedRateFlagBits::24bpcBitEXT:
            return "24bpcBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqImageCompressionFlagBits v)
    {
        switch(v){
        case VqImageCompressionFlagBits::DefaultEXT:
            return "DefaultEXT";
        case VqImageCompressionFlagBits::FixedRateDefaultEXT:
            return "FixedRateDefaultEXT";
        case VqImageCompressionFlagBits::FixedRateExplicitEXT:
            return "FixedRateExplicitEXT";
        case VqImageCompressionFlagBits::DisabledEXT:
            return "DisabledEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqImageCreateFlagBits v)
    {
        switch(v){
        case VqImageCreateFlagBits::SparseBindingBit:
            return "SparseBindingBit";
        case VqImageCreateFlagBits::SparseResidencyBit:
            return "SparseResidencyBit";
        case VqImageCreateFlagBits::SparseAliasedBit:
            return "SparseAliasedBit";
        case VqImageCreateFlagBits::MutableFormatBit:
            return "MutableFormatBit";
        case VqImageCreateFlagBits::CubeCompatibleBit:
            return "CubeCompatibleBit";
        case VqImageCreateFlagBits::AliasBit:
            return "AliasBit";
        case VqImageCreateFlagBits::SplitInstanceBindRegionsBit:
            return "SplitInstanceBindRegionsBit";
        case VqImageCreateFlagBits::2dArrayCompatibleBit:
            return "2dArrayCompatibleBit";
        case VqImageCreateFlagBits::BlockTexelViewCompatibleBit:
            return "BlockTexelViewCompatibleBit";
        case VqImageCreateFlagBits::ExtendedUsageBit:
            return "ExtendedUsageBit";
        case VqImageCreateFlagBits::ProtectedBit:
            return "ProtectedBit";
        case VqImageCreateFlagBits::DisjointBit:
            return "DisjointBit";
        case VqImageCreateFlagBits::CornerSampledBitNV:
            return "CornerSampledBitNV";
        case VqImageCreateFlagBits::SampleLocationsCompatibleDepthBitEXT:
            return "SampleLocationsCompatibleDepthBitEXT";
        case VqImageCreateFlagBits::SubsampledBitEXT:
            return "SubsampledBitEXT";
        case VqImageCreateFlagBits::DescriptorBufferCaptureReplayBitEXT:
            return "DescriptorBufferCaptureReplayBitEXT";
        case VqImageCreateFlagBits::MultisampledRenderToSingleSampledBitEXT:
            return "MultisampledRenderToSingleSampledBitEXT";
        case VqImageCreateFlagBits::2dViewCompatibleBitEXT:
            return "2dViewCompatibleBitEXT";
        case VqImageCreateFlagBits::FragmentDensityMapOffsetBitQCOM:
            return "FragmentDensityMapOffsetBitQCOM";
        case VqImageCreateFlagBits::VideoProfileIndependentBitKHR:
            return "VideoProfileIndependentBitKHR";
        case VqImageCreateFlagBits::SplitInstanceBindRegionsBitKHR:
            return "SplitInstanceBindRegionsBitKHR";
        case VqImageCreateFlagBits::2dArrayCompatibleBitKHR:
            return "2dArrayCompatibleBitKHR";
        case VqImageCreateFlagBits::BlockTexelViewCompatibleBitKHR:
            return "BlockTexelViewCompatibleBitKHR";
        case VqImageCreateFlagBits::ExtendedUsageBitKHR:
            return "ExtendedUsageBitKHR";
        case VqImageCreateFlagBits::DisjointBitKHR:
            return "DisjointBitKHR";
        case VqImageCreateFlagBits::AliasBitKHR:
            return "AliasBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqImageLayout v)
    {
        switch(v){
        case VqImageLayout::Undefined:
            return "Undefined";
        case VqImageLayout::General:
            return "General";
        case VqImageLayout::ColorAttachmentOptimal:
            return "ColorAttachmentOptimal";
        case VqImageLayout::DepthStencilAttachmentOptimal:
            return "DepthStencilAttachmentOptimal";
        case VqImageLayout::DepthStencilReadOnlyOptimal:
            return "DepthStencilReadOnlyOptimal";
        case VqImageLayout::ShaderReadOnlyOptimal:
            return "ShaderReadOnlyOptimal";
        case VqImageLayout::TransferSrcOptimal:
            return "TransferSrcOptimal";
        case VqImageLayout::TransferDstOptimal:
            return "TransferDstOptimal";
        case VqImageLayout::Preinitialized:
            return "Preinitialized";
        case VqImageLayout::DepthReadOnlyStencilAttachmentOptimal:
            return "DepthReadOnlyStencilAttachmentOptimal";
        case VqImageLayout::DepthAttachmentStencilReadOnlyOptimal:
            return "DepthAttachmentStencilReadOnlyOptimal";
        case VqImageLayout::DepthAttachmentOptimal:
            return "DepthAttachmentOptimal";
        case VqImageLayout::DepthReadOnlyOptimal:
            return "DepthReadOnlyOptimal";
        case VqImageLayout::StencilAttachmentOptimal:
            return "StencilAttachmentOptimal";
        case VqImageLayout::StencilReadOnlyOptimal:
            return "StencilReadOnlyOptimal";
        case VqImageLayout::ReadOnlyOptimal:
            return "ReadOnlyOptimal";
        case VqImageLayout::AttachmentOptimal:
            return "AttachmentOptimal";
        case VqImageLayout::PresentSrcKHR:
            return "PresentSrcKHR";
        case VqImageLayout::VideoDecodeDstKHR:
            return "VideoDecodeDstKHR";
        case VqImageLayout::VideoDecodeSrcKHR:
            return "VideoDecodeSrcKHR";
        case VqImageLayout::VideoDecodeDpbKHR:
            return "VideoDecodeDpbKHR";
        case VqImageLayout::SharedPresentKHR:
            return "SharedPresentKHR";
        case VqImageLayout::FragmentDensityMapOptimalEXT:
            return "FragmentDensityMapOptimalEXT";
        case VqImageLayout::FragmentShadingRateAttachmentOptimalKHR:
            return "FragmentShadingRateAttachmentOptimalKHR";
        case VqImageLayout::RenderingLocalReadKHR:
            return "RenderingLocalReadKHR";
        case VqImageLayout::VideoEncodeDstKHR:
            return "VideoEncodeDstKHR";
        case VqImageLayout::VideoEncodeSrcKHR:
            return "VideoEncodeSrcKHR";
        case VqImageLayout::VideoEncodeDpbKHR:
            return "VideoEncodeDpbKHR";
        case VqImageLayout::AttachmentFeedbackLoopOptimalEXT:
            return "AttachmentFeedbackLoopOptimalEXT";
        case VqImageLayout::DepthReadOnlyStencilAttachmentOptimalKHR:
            return "DepthReadOnlyStencilAttachmentOptimalKHR";
        case VqImageLayout::DepthAttachmentStencilReadOnlyOptimalKHR:
            return "DepthAttachmentStencilReadOnlyOptimalKHR";
        case VqImageLayout::ShadingRateOptimalNV:
            return "ShadingRateOptimalNV";
        case VqImageLayout::DepthAttachmentOptimalKHR:
            return "DepthAttachmentOptimalKHR";
        case VqImageLayout::DepthReadOnlyOptimalKHR:
            return "DepthReadOnlyOptimalKHR";
        case VqImageLayout::StencilAttachmentOptimalKHR:
            return "StencilAttachmentOptimalKHR";
        case VqImageLayout::StencilReadOnlyOptimalKHR:
            return "StencilReadOnlyOptimalKHR";
        case VqImageLayout::ReadOnlyOptimalKHR:
            return "ReadOnlyOptimalKHR";
        case VqImageLayout::AttachmentOptimalKHR:
            return "AttachmentOptimalKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqImageTiling v)
    {
        switch(v){
        case VqImageTiling::Optimal:
            return "Optimal";
        case VqImageTiling::Linear:
            return "Linear";
        case VqImageTiling::DrmFormatModifierEXT:
            return "DrmFormatModifierEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqImageType v)
    {
        switch(v){
        case VqImageType::1d:
            return "1d";
        case VqImageType::2d:
            return "2d";
        case VqImageType::3d:
            return "3d";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqImageUsageFlagBits v)
    {
        switch(v){
        case VqImageUsageFlagBits::TransferSrcBit:
            return "TransferSrcBit";
        case VqImageUsageFlagBits::TransferDstBit:
            return "TransferDstBit";
        case VqImageUsageFlagBits::SampledBit:
            return "SampledBit";
        case VqImageUsageFlagBits::StorageBit:
            return "StorageBit";
        case VqImageUsageFlagBits::ColorAttachmentBit:
            return "ColorAttachmentBit";
        case VqImageUsageFlagBits::DepthStencilAttachmentBit:
            return "DepthStencilAttachmentBit";
        case VqImageUsageFlagBits::TransientAttachmentBit:
            return "TransientAttachmentBit";
        case VqImageUsageFlagBits::InputAttachmentBit:
            return "InputAttachmentBit";
        case VqImageUsageFlagBits::VideoDecodeDstBitKHR:
            return "VideoDecodeDstBitKHR";
        case VqImageUsageFlagBits::VideoDecodeSrcBitKHR:
            return "VideoDecodeSrcBitKHR";
        case VqImageUsageFlagBits::VideoDecodeDpbBitKHR:
            return "VideoDecodeDpbBitKHR";
        case VqImageUsageFlagBits::FragmentDensityMapBitEXT:
            return "FragmentDensityMapBitEXT";
        case VqImageUsageFlagBits::FragmentShadingRateAttachmentBitKHR:
            return "FragmentShadingRateAttachmentBitKHR";
        case VqImageUsageFlagBits::HostTransferBitEXT:
            return "HostTransferBitEXT";
        case VqImageUsageFlagBits::VideoEncodeDstBitKHR:
            return "VideoEncodeDstBitKHR";
        case VqImageUsageFlagBits::VideoEncodeSrcBitKHR:
            return "VideoEncodeSrcBitKHR";
        case VqImageUsageFlagBits::VideoEncodeDpbBitKHR:
            return "VideoEncodeDpbBitKHR";
        case VqImageUsageFlagBits::AttachmentFeedbackLoopBitEXT:
            return "AttachmentFeedbackLoopBitEXT";
        case VqImageUsageFlagBits::InvocationMaskBitHuawei:
            return "InvocationMaskBitHuawei";
        case VqImageUsageFlagBits::SampleWeightBitQCOM:
            return "SampleWeightBitQCOM";
        case VqImageUsageFlagBits::SampleBlockMatchBitQCOM:
            return "SampleBlockMatchBitQCOM";
        case VqImageUsageFlagBits::ShadingRateImageBitNV:
            return "ShadingRateImageBitNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqImageViewCreateFlagBits v)
    {
        switch(v){
        case VqImageViewCreateFlagBits::FragmentDensityMapDynamicBitEXT:
            return "FragmentDensityMapDynamicBitEXT";
        case VqImageViewCreateFlagBits::DescriptorBufferCaptureReplayBitEXT:
            return "DescriptorBufferCaptureReplayBitEXT";
        case VqImageViewCreateFlagBits::FragmentDensityMapDeferredBitEXT:
            return "FragmentDensityMapDeferredBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqImageViewType v)
    {
        switch(v){
        case VqImageViewType::1d:
            return "1d";
        case VqImageViewType::2d:
            return "2d";
        case VqImageViewType::3d:
            return "3d";
        case VqImageViewType::Cube:
            return "Cube";
        case VqImageViewType::1dArray:
            return "1dArray";
        case VqImageViewType::2dArray:
            return "2dArray";
        case VqImageViewType::CubeArray:
            return "CubeArray";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqIndexType v)
    {
        switch(v){
        case VqIndexType::Uint16:
            return "Uint16";
        case VqIndexType::Uint32:
            return "Uint32";
        case VqIndexType::NoneKHR:
            return "NoneKHR";
        case VqIndexType::Uint8KHR:
            return "Uint8KHR";
        case VqIndexType::NoneNV:
            return "NoneNV";
        case VqIndexType::Uint8EXT:
            return "Uint8EXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqIndirectCommandsLayoutUsageFlagBits v)
    {
        switch(v){
        case VqIndirectCommandsLayoutUsageFlagBits::ExplicitPreprocessBitNV:
            return "ExplicitPreprocessBitNV";
        case VqIndirectCommandsLayoutUsageFlagBits::IndexedSequencesBitNV:
            return "IndexedSequencesBitNV";
        case VqIndirectCommandsLayoutUsageFlagBits::UnorderedSequencesBitNV:
            return "UnorderedSequencesBitNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqIndirectCommandsTokenType v)
    {
        switch(v){
        case VqIndirectCommandsTokenType::ShaderGroupNV:
            return "ShaderGroupNV";
        case VqIndirectCommandsTokenType::StateFlagsNV:
            return "StateFlagsNV";
        case VqIndirectCommandsTokenType::IndexBufferNV:
            return "IndexBufferNV";
        case VqIndirectCommandsTokenType::VertexBufferNV:
            return "VertexBufferNV";
        case VqIndirectCommandsTokenType::PushConstantNV:
            return "PushConstantNV";
        case VqIndirectCommandsTokenType::DrawIndexedNV:
            return "DrawIndexedNV";
        case VqIndirectCommandsTokenType::DrawNV:
            return "DrawNV";
        case VqIndirectCommandsTokenType::DrawTasksNV:
            return "DrawTasksNV";
        case VqIndirectCommandsTokenType::DrawMeshTasksNV:
            return "DrawMeshTasksNV";
        case VqIndirectCommandsTokenType::PipelineNV:
            return "PipelineNV";
        case VqIndirectCommandsTokenType::DispatchNV:
            return "DispatchNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqIndirectStateFlagBits v)
    {
        switch(v){
        case VqIndirectStateFlagBits::FlagFrontfaceBitNV:
            return "FlagFrontfaceBitNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqInstanceCreateFlagBits v)
    {
        switch(v){
        case VqInstanceCreateFlagBits::EnumeratePortabilityBitKHR:
            return "EnumeratePortabilityBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqInternalAllocationType v)
    {
        switch(v){
        case VqInternalAllocationType::Executable:
            return "Executable";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqLatencyMarker v)
    {
        switch(v){
        case VqLatencyMarker::SimulationStartNV:
            return "SimulationStartNV";
        case VqLatencyMarker::SimulationEndNV:
            return "SimulationEndNV";
        case VqLatencyMarker::RendersubmitStartNV:
            return "RendersubmitStartNV";
        case VqLatencyMarker::RendersubmitEndNV:
            return "RendersubmitEndNV";
        case VqLatencyMarker::PresentStartNV:
            return "PresentStartNV";
        case VqLatencyMarker::PresentEndNV:
            return "PresentEndNV";
        case VqLatencyMarker::InputSampleNV:
            return "InputSampleNV";
        case VqLatencyMarker::TriggerFlashNV:
            return "TriggerFlashNV";
        case VqLatencyMarker::OutOfBandRendersubmitStartNV:
            return "OutOfBandRendersubmitStartNV";
        case VqLatencyMarker::OutOfBandRendersubmitEndNV:
            return "OutOfBandRendersubmitEndNV";
        case VqLatencyMarker::OutOfBandPresentStartNV:
            return "OutOfBandPresentStartNV";
        case VqLatencyMarker::OutOfBandPresentEndNV:
            return "OutOfBandPresentEndNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqLayerSettingType v)
    {
        switch(v){
        case VqLayerSettingType::Bool32EXT:
            return "Bool32EXT";
        case VqLayerSettingType::Int32EXT:
            return "Int32EXT";
        case VqLayerSettingType::Int64EXT:
            return "Int64EXT";
        case VqLayerSettingType::Uint32EXT:
            return "Uint32EXT";
        case VqLayerSettingType::Uint64EXT:
            return "Uint64EXT";
        case VqLayerSettingType::Float32EXT:
            return "Float32EXT";
        case VqLayerSettingType::Float64EXT:
            return "Float64EXT";
        case VqLayerSettingType::StringEXT:
            return "StringEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqLayeredDriverUnderlyingApi v)
    {
        switch(v){
        case VqLayeredDriverUnderlyingApi::NoneMSFT:
            return "NoneMSFT";
        case VqLayeredDriverUnderlyingApi::D3d12MSFT:
            return "D3d12MSFT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqLineRasterizationMode v)
    {
        switch(v){
        case VqLineRasterizationMode::DefaultKHR:
            return "DefaultKHR";
        case VqLineRasterizationMode::RectangularKHR:
            return "RectangularKHR";
        case VqLineRasterizationMode::BresenhamKHR:
            return "BresenhamKHR";
        case VqLineRasterizationMode::RectangularSmoothKHR:
            return "RectangularSmoothKHR";
        case VqLineRasterizationMode::DefaultEXT:
            return "DefaultEXT";
        case VqLineRasterizationMode::RectangularEXT:
            return "RectangularEXT";
        case VqLineRasterizationMode::BresenhamEXT:
            return "BresenhamEXT";
        case VqLineRasterizationMode::RectangularSmoothEXT:
            return "RectangularSmoothEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqLogicOp v)
    {
        switch(v){
        case VqLogicOp::Clear:
            return "Clear";
        case VqLogicOp::And:
            return "And";
        case VqLogicOp::AndReverse:
            return "AndReverse";
        case VqLogicOp::Copy:
            return "Copy";
        case VqLogicOp::AndInverted:
            return "AndInverted";
        case VqLogicOp::NoOp:
            return "NoOp";
        case VqLogicOp::Xor:
            return "Xor";
        case VqLogicOp::Or:
            return "Or";
        case VqLogicOp::Nor:
            return "Nor";
        case VqLogicOp::Equivalent:
            return "Equivalent";
        case VqLogicOp::Invert:
            return "Invert";
        case VqLogicOp::OrReverse:
            return "OrReverse";
        case VqLogicOp::CopyInverted:
            return "CopyInverted";
        case VqLogicOp::OrInverted:
            return "OrInverted";
        case VqLogicOp::Nand:
            return "Nand";
        case VqLogicOp::Set:
            return "Set";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqMemoryAllocateFlagBits v)
    {
        switch(v){
        case VqMemoryAllocateFlagBits::DeviceMaskBit:
            return "DeviceMaskBit";
        case VqMemoryAllocateFlagBits::DeviceAddressBit:
            return "DeviceAddressBit";
        case VqMemoryAllocateFlagBits::DeviceAddressCaptureReplayBit:
            return "DeviceAddressCaptureReplayBit";
        case VqMemoryAllocateFlagBits::DeviceMaskBitKHR:
            return "DeviceMaskBitKHR";
        case VqMemoryAllocateFlagBits::DeviceAddressBitKHR:
            return "DeviceAddressBitKHR";
        case VqMemoryAllocateFlagBits::DeviceAddressCaptureReplayBitKHR:
            return "DeviceAddressCaptureReplayBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqMemoryHeapFlagBits v)
    {
        switch(v){
        case VqMemoryHeapFlagBits::DeviceLocalBit:
            return "DeviceLocalBit";
        case VqMemoryHeapFlagBits::MultiInstanceBit:
            return "MultiInstanceBit";
        case VqMemoryHeapFlagBits::MultiInstanceBitKHR:
            return "MultiInstanceBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqMemoryMapFlagBits v)
    {
        switch(v){
        case VqMemoryMapFlagBits::PlacedBitEXT:
            return "PlacedBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqMemoryOverallocationBehavior v)
    {
        switch(v){
        case VqMemoryOverallocationBehavior::DefaultAMD:
            return "DefaultAMD";
        case VqMemoryOverallocationBehavior::AllowedAMD:
            return "AllowedAMD";
        case VqMemoryOverallocationBehavior::DisallowedAMD:
            return "DisallowedAMD";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqMemoryPropertyFlagBits v)
    {
        switch(v){
        case VqMemoryPropertyFlagBits::DeviceLocalBit:
            return "DeviceLocalBit";
        case VqMemoryPropertyFlagBits::HostVisibleBit:
            return "HostVisibleBit";
        case VqMemoryPropertyFlagBits::HostCoherentBit:
            return "HostCoherentBit";
        case VqMemoryPropertyFlagBits::HostCachedBit:
            return "HostCachedBit";
        case VqMemoryPropertyFlagBits::LazilyAllocatedBit:
            return "LazilyAllocatedBit";
        case VqMemoryPropertyFlagBits::ProtectedBit:
            return "ProtectedBit";
        case VqMemoryPropertyFlagBits::DeviceCoherentBitAMD:
            return "DeviceCoherentBitAMD";
        case VqMemoryPropertyFlagBits::DeviceUncachedBitAMD:
            return "DeviceUncachedBitAMD";
        case VqMemoryPropertyFlagBits::RdmaCapableBitNV:
            return "RdmaCapableBitNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqMemoryUnmapFlagBits v)
    {
        switch(v){
        case VqMemoryUnmapFlagBits::ReserveBitEXT:
            return "ReserveBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqMicromapCreateFlagBits v)
    {
        switch(v){
        case VqMicromapCreateFlagBits::DeviceAddressCaptureReplayBitEXT:
            return "DeviceAddressCaptureReplayBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqMicromapType v)
    {
        switch(v){
        case VqMicromapType::OpacityMicromapEXT:
            return "OpacityMicromapEXT";
        case VqMicromapType::DisplacementMicromapNV:
            return "DisplacementMicromapNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqObjectType v)
    {
        switch(v){
        case VqObjectType::Unknown:
            return "Unknown";
        case VqObjectType::Instance:
            return "Instance";
        case VqObjectType::PhysicalDevice:
            return "PhysicalDevice";
        case VqObjectType::Device:
            return "Device";
        case VqObjectType::Queue:
            return "Queue";
        case VqObjectType::Semaphore:
            return "Semaphore";
        case VqObjectType::CommandBuffer:
            return "CommandBuffer";
        case VqObjectType::Fence:
            return "Fence";
        case VqObjectType::DeviceMemory:
            return "DeviceMemory";
        case VqObjectType::Buffer:
            return "Buffer";
        case VqObjectType::Image:
            return "Image";
        case VqObjectType::Event:
            return "Event";
        case VqObjectType::QueryPool:
            return "QueryPool";
        case VqObjectType::BufferView:
            return "BufferView";
        case VqObjectType::ImageView:
            return "ImageView";
        case VqObjectType::ShaderModule:
            return "ShaderModule";
        case VqObjectType::PipelineCache:
            return "PipelineCache";
        case VqObjectType::PipelineLayout:
            return "PipelineLayout";
        case VqObjectType::RenderPass:
            return "RenderPass";
        case VqObjectType::Pipeline:
            return "Pipeline";
        case VqObjectType::DescriptorSetLayout:
            return "DescriptorSetLayout";
        case VqObjectType::Sampler:
            return "Sampler";
        case VqObjectType::DescriptorPool:
            return "DescriptorPool";
        case VqObjectType::DescriptorSet:
            return "DescriptorSet";
        case VqObjectType::Framebuffer:
            return "Framebuffer";
        case VqObjectType::CommandPool:
            return "CommandPool";
        case VqObjectType::SamplerYcbcrConversion:
            return "SamplerYcbcrConversion";
        case VqObjectType::DescriptorUpdateTemplate:
            return "DescriptorUpdateTemplate";
        case VqObjectType::PrivateDataSlot:
            return "PrivateDataSlot";
        case VqObjectType::SurfaceKHR:
            return "SurfaceKHR";
        case VqObjectType::SwapchainKHR:
            return "SwapchainKHR";
        case VqObjectType::DisplayKHR:
            return "DisplayKHR";
        case VqObjectType::DisplayModeKHR:
            return "DisplayModeKHR";
        case VqObjectType::DebugReportCallbackEXT:
            return "DebugReportCallbackEXT";
        case VqObjectType::VideoSessionKHR:
            return "VideoSessionKHR";
        case VqObjectType::VideoSessionParametersKHR:
            return "VideoSessionParametersKHR";
        case VqObjectType::CuModuleNvx:
            return "CuModuleNvx";
        case VqObjectType::CuFunctionNvx:
            return "CuFunctionNvx";
        case VqObjectType::DebugUtilsMessengerEXT:
            return "DebugUtilsMessengerEXT";
        case VqObjectType::AccelerationStructureKHR:
            return "AccelerationStructureKHR";
        case VqObjectType::ValidationCacheEXT:
            return "ValidationCacheEXT";
        case VqObjectType::AccelerationStructureNV:
            return "AccelerationStructureNV";
        case VqObjectType::PerformanceConfigurationINTEL:
            return "PerformanceConfigurationINTEL";
        case VqObjectType::DeferredOperationKHR:
            return "DeferredOperationKHR";
        case VqObjectType::IndirectCommandsLayoutNV:
            return "IndirectCommandsLayoutNV";
        case VqObjectType::CudaModuleNV:
            return "CudaModuleNV";
        case VqObjectType::CudaFunctionNV:
            return "CudaFunctionNV";
        case VqObjectType::BufferCollectionFuchsia:
            return "BufferCollectionFuchsia";
        case VqObjectType::MicromapEXT:
            return "MicromapEXT";
        case VqObjectType::OpticalFlowSessionNV:
            return "OpticalFlowSessionNV";
        case VqObjectType::ShaderEXT:
            return "ShaderEXT";
        case VqObjectType::DescriptorUpdateTemplateKHR:
            return "DescriptorUpdateTemplateKHR";
        case VqObjectType::SamplerYcbcrConversionKHR:
            return "SamplerYcbcrConversionKHR";
        case VqObjectType::PrivateDataSlotEXT:
            return "PrivateDataSlotEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqOpacityMicromapFormat v)
    {
        switch(v){
        case VqOpacityMicromapFormat::2StateEXT:
            return "2StateEXT";
        case VqOpacityMicromapFormat::4StateEXT:
            return "4StateEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqOpacityMicromapSpecialIndex v)
    {
        switch(v){
        case VqOpacityMicromapSpecialIndex::FullyTransparentEXT:
            return "FullyTransparentEXT";
        case VqOpacityMicromapSpecialIndex::FullyOpaqueEXT:
            return "FullyOpaqueEXT";
        case VqOpacityMicromapSpecialIndex::FullyUnknownTransparentEXT:
            return "FullyUnknownTransparentEXT";
        case VqOpacityMicromapSpecialIndex::FullyUnknownOpaqueEXT:
            return "FullyUnknownOpaqueEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqOpticalFlowExecuteFlagBits v)
    {
        switch(v){
        case VqOpticalFlowExecuteFlagBits::DisableTemporalHintsBitNV:
            return "DisableTemporalHintsBitNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqOpticalFlowGridSizeFlagBits v)
    {
        switch(v){
        case VqOpticalFlowGridSizeFlagBits::UnknownNV:
            return "UnknownNV";
        case VqOpticalFlowGridSizeFlagBits::1x1BitNV:
            return "1x1BitNV";
        case VqOpticalFlowGridSizeFlagBits::2x2BitNV:
            return "2x2BitNV";
        case VqOpticalFlowGridSizeFlagBits::4x4BitNV:
            return "4x4BitNV";
        case VqOpticalFlowGridSizeFlagBits::8x8BitNV:
            return "8x8BitNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqOpticalFlowPerformanceLevel v)
    {
        switch(v){
        case VqOpticalFlowPerformanceLevel::UnknownNV:
            return "UnknownNV";
        case VqOpticalFlowPerformanceLevel::SlowNV:
            return "SlowNV";
        case VqOpticalFlowPerformanceLevel::MediumNV:
            return "MediumNV";
        case VqOpticalFlowPerformanceLevel::FastNV:
            return "FastNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqOpticalFlowSessionBindingPoint v)
    {
        switch(v){
        case VqOpticalFlowSessionBindingPoint::UnknownNV:
            return "UnknownNV";
        case VqOpticalFlowSessionBindingPoint::InputNV:
            return "InputNV";
        case VqOpticalFlowSessionBindingPoint::ReferenceNV:
            return "ReferenceNV";
        case VqOpticalFlowSessionBindingPoint::HintNV:
            return "HintNV";
        case VqOpticalFlowSessionBindingPoint::FlowVectorNV:
            return "FlowVectorNV";
        case VqOpticalFlowSessionBindingPoint::BackwardFlowVectorNV:
            return "BackwardFlowVectorNV";
        case VqOpticalFlowSessionBindingPoint::CostNV:
            return "CostNV";
        case VqOpticalFlowSessionBindingPoint::BackwardCostNV:
            return "BackwardCostNV";
        case VqOpticalFlowSessionBindingPoint::GlobalFlowNV:
            return "GlobalFlowNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqOpticalFlowSessionCreateFlagBits v)
    {
        switch(v){
        case VqOpticalFlowSessionCreateFlagBits::EnableHintBitNV:
            return "EnableHintBitNV";
        case VqOpticalFlowSessionCreateFlagBits::EnableCostBitNV:
            return "EnableCostBitNV";
        case VqOpticalFlowSessionCreateFlagBits::EnableGlobalFlowBitNV:
            return "EnableGlobalFlowBitNV";
        case VqOpticalFlowSessionCreateFlagBits::AllowRegionsBitNV:
            return "AllowRegionsBitNV";
        case VqOpticalFlowSessionCreateFlagBits::BothDirectionsBitNV:
            return "BothDirectionsBitNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqOpticalFlowUsageFlagBits v)
    {
        switch(v){
        case VqOpticalFlowUsageFlagBits::UnknownNV:
            return "UnknownNV";
        case VqOpticalFlowUsageFlagBits::InputBitNV:
            return "InputBitNV";
        case VqOpticalFlowUsageFlagBits::OutputBitNV:
            return "OutputBitNV";
        case VqOpticalFlowUsageFlagBits::HintBitNV:
            return "HintBitNV";
        case VqOpticalFlowUsageFlagBits::CostBitNV:
            return "CostBitNV";
        case VqOpticalFlowUsageFlagBits::GlobalFlowBitNV:
            return "GlobalFlowBitNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqOutOfBandQueueType v)
    {
        switch(v){
        case VqOutOfBandQueueType::RenderNV:
            return "RenderNV";
        case VqOutOfBandQueueType::PresentNV:
            return "PresentNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPeerMemoryFeatureFlagBits v)
    {
        switch(v){
        case VqPeerMemoryFeatureFlagBits::CopySrcBit:
            return "CopySrcBit";
        case VqPeerMemoryFeatureFlagBits::CopyDstBit:
            return "CopyDstBit";
        case VqPeerMemoryFeatureFlagBits::GenericSrcBit:
            return "GenericSrcBit";
        case VqPeerMemoryFeatureFlagBits::GenericDstBit:
            return "GenericDstBit";
        case VqPeerMemoryFeatureFlagBits::CopySrcBitKHR:
            return "CopySrcBitKHR";
        case VqPeerMemoryFeatureFlagBits::CopyDstBitKHR:
            return "CopyDstBitKHR";
        case VqPeerMemoryFeatureFlagBits::GenericSrcBitKHR:
            return "GenericSrcBitKHR";
        case VqPeerMemoryFeatureFlagBits::GenericDstBitKHR:
            return "GenericDstBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPerformanceConfigurationType v)
    {
        switch(v){
        case VqPerformanceConfigurationType::CommandQueueMetricsDiscoveryActivatedINTEL:
            return "CommandQueueMetricsDiscoveryActivatedINTEL";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPerformanceCounterDescriptionFlagBits v)
    {
        switch(v){
        case VqPerformanceCounterDescriptionFlagBits::PerformanceImpactingBitKHR:
            return "PerformanceImpactingBitKHR";
        case VqPerformanceCounterDescriptionFlagBits::ConcurrentlyImpactedBitKHR:
            return "ConcurrentlyImpactedBitKHR";
        case VqPerformanceCounterDescriptionFlagBits::PerformanceImpactingKHR:
            return "PerformanceImpactingKHR";
        case VqPerformanceCounterDescriptionFlagBits::ConcurrentlyImpactedKHR:
            return "ConcurrentlyImpactedKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPerformanceCounterScope v)
    {
        switch(v){
        case VqPerformanceCounterScope::CommandBufferKHR:
            return "CommandBufferKHR";
        case VqPerformanceCounterScope::RenderPassKHR:
            return "RenderPassKHR";
        case VqPerformanceCounterScope::CommandKHR:
            return "CommandKHR";
        case VqPerformanceCounterScope::VkQueryScopeCommandBufferKHR:
            return "VkQueryScopeCommandBufferKHR";
        case VqPerformanceCounterScope::VkQueryScopeRenderPassKHR:
            return "VkQueryScopeRenderPassKHR";
        case VqPerformanceCounterScope::VkQueryScopeCommandKHR:
            return "VkQueryScopeCommandKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPerformanceCounterStorage v)
    {
        switch(v){
        case VqPerformanceCounterStorage::Int32KHR:
            return "Int32KHR";
        case VqPerformanceCounterStorage::Int64KHR:
            return "Int64KHR";
        case VqPerformanceCounterStorage::Uint32KHR:
            return "Uint32KHR";
        case VqPerformanceCounterStorage::Uint64KHR:
            return "Uint64KHR";
        case VqPerformanceCounterStorage::Float32KHR:
            return "Float32KHR";
        case VqPerformanceCounterStorage::Float64KHR:
            return "Float64KHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPerformanceCounterUnit v)
    {
        switch(v){
        case VqPerformanceCounterUnit::GenericKHR:
            return "GenericKHR";
        case VqPerformanceCounterUnit::PercentageKHR:
            return "PercentageKHR";
        case VqPerformanceCounterUnit::NanosecondsKHR:
            return "NanosecondsKHR";
        case VqPerformanceCounterUnit::BytesKHR:
            return "BytesKHR";
        case VqPerformanceCounterUnit::BytesPerSecondKHR:
            return "BytesPerSecondKHR";
        case VqPerformanceCounterUnit::KelvinKHR:
            return "KelvinKHR";
        case VqPerformanceCounterUnit::WattsKHR:
            return "WattsKHR";
        case VqPerformanceCounterUnit::VoltsKHR:
            return "VoltsKHR";
        case VqPerformanceCounterUnit::AmpsKHR:
            return "AmpsKHR";
        case VqPerformanceCounterUnit::HertzKHR:
            return "HertzKHR";
        case VqPerformanceCounterUnit::CyclesKHR:
            return "CyclesKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPerformanceOverrideType v)
    {
        switch(v){
        case VqPerformanceOverrideType::NullHardwareINTEL:
            return "NullHardwareINTEL";
        case VqPerformanceOverrideType::FlushGpuCachesINTEL:
            return "FlushGpuCachesINTEL";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPerformanceParameterType v)
    {
        switch(v){
        case VqPerformanceParameterType::HwCountersSupportedINTEL:
            return "HwCountersSupportedINTEL";
        case VqPerformanceParameterType::StreamMarkerValidBitsINTEL:
            return "StreamMarkerValidBitsINTEL";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPerformanceValueType v)
    {
        switch(v){
        case VqPerformanceValueType::Uint32INTEL:
            return "Uint32INTEL";
        case VqPerformanceValueType::Uint64INTEL:
            return "Uint64INTEL";
        case VqPerformanceValueType::FloatINTEL:
            return "FloatINTEL";
        case VqPerformanceValueType::BoolINTEL:
            return "BoolINTEL";
        case VqPerformanceValueType::StringINTEL:
            return "StringINTEL";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPhysicalDeviceLayeredApi v)
    {
        switch(v){
        case VqPhysicalDeviceLayeredApi::VulkanKHR:
            return "VulkanKHR";
        case VqPhysicalDeviceLayeredApi::D3d12KHR:
            return "D3d12KHR";
        case VqPhysicalDeviceLayeredApi::MetalKHR:
            return "MetalKHR";
        case VqPhysicalDeviceLayeredApi::OpenglKHR:
            return "OpenglKHR";
        case VqPhysicalDeviceLayeredApi::OpenglesKHR:
            return "OpenglesKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPhysicalDeviceType v)
    {
        switch(v){
        case VqPhysicalDeviceType::Other:
            return "Other";
        case VqPhysicalDeviceType::IntegratedGpu:
            return "IntegratedGpu";
        case VqPhysicalDeviceType::DiscreteGpu:
            return "DiscreteGpu";
        case VqPhysicalDeviceType::VirtualGpu:
            return "VirtualGpu";
        case VqPhysicalDeviceType::Cpu:
            return "Cpu";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineBindPoint v)
    {
        switch(v){
        case VqPipelineBindPoint::Graphics:
            return "Graphics";
        case VqPipelineBindPoint::Compute:
            return "Compute";
        case VqPipelineBindPoint::ExecutionGraphAmdx:
            return "ExecutionGraphAmdx";
        case VqPipelineBindPoint::RayTracingKHR:
            return "RayTracingKHR";
        case VqPipelineBindPoint::SubpassShadingHuawei:
            return "SubpassShadingHuawei";
        case VqPipelineBindPoint::RayTracingNV:
            return "RayTracingNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineCacheCreateFlagBits v)
    {
        switch(v){
        case VqPipelineCacheCreateFlagBits::ExternallySynchronizedBit:
            return "ExternallySynchronizedBit";
        case VqPipelineCacheCreateFlagBits::ExternallySynchronizedBitEXT:
            return "ExternallySynchronizedBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineCacheHeaderVersion v)
    {
        switch(v){
        case VqPipelineCacheHeaderVersion::One:
            return "One";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineColorBlendStateCreateFlagBits v)
    {
        switch(v){
        case VqPipelineColorBlendStateCreateFlagBits::RasterizationOrderAttachmentAccessBitEXT:
            return "RasterizationOrderAttachmentAccessBitEXT";
        case VqPipelineColorBlendStateCreateFlagBits::RasterizationOrderAttachmentAccessBitArm:
            return "RasterizationOrderAttachmentAccessBitArm";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineCompilerControlFlagBits v)
    {
        switch(v){
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineCreateFlagBits v)
    {
        switch(v){
        case VqPipelineCreateFlagBits::DisableOptimizationBit:
            return "DisableOptimizationBit";
        case VqPipelineCreateFlagBits::AllowDerivativesBit:
            return "AllowDerivativesBit";
        case VqPipelineCreateFlagBits::DerivativeBit:
            return "DerivativeBit";
        case VqPipelineCreateFlagBits::ViewIndexFromDeviceIndexBit:
            return "ViewIndexFromDeviceIndexBit";
        case VqPipelineCreateFlagBits::DispatchBaseBit:
            return "DispatchBaseBit";
        case VqPipelineCreateFlagBits::FailOnPipelineCompileRequiredBit:
            return "FailOnPipelineCompileRequiredBit";
        case VqPipelineCreateFlagBits::EarlyReturnOnFailureBit:
            return "EarlyReturnOnFailureBit";
        case VqPipelineCreateFlagBits::RenderingFragmentShadingRateAttachmentBitKHR:
            return "RenderingFragmentShadingRateAttachmentBitKHR";
        case VqPipelineCreateFlagBits::RenderingFragmentDensityMapAttachmentBitEXT:
            return "RenderingFragmentDensityMapAttachmentBitEXT";
        case VqPipelineCreateFlagBits::RayTracingNoNullAnyHitShadersBitKHR:
            return "RayTracingNoNullAnyHitShadersBitKHR";
        case VqPipelineCreateFlagBits::RayTracingNoNullClosestHitShadersBitKHR:
            return "RayTracingNoNullClosestHitShadersBitKHR";
        case VqPipelineCreateFlagBits::RayTracingNoNullMissShadersBitKHR:
            return "RayTracingNoNullMissShadersBitKHR";
        case VqPipelineCreateFlagBits::RayTracingNoNullIntersectionShadersBitKHR:
            return "RayTracingNoNullIntersectionShadersBitKHR";
        case VqPipelineCreateFlagBits::RayTracingSkipTrianglesBitKHR:
            return "RayTracingSkipTrianglesBitKHR";
        case VqPipelineCreateFlagBits::RayTracingSkipAabbsBitKHR:
            return "RayTracingSkipAabbsBitKHR";
        case VqPipelineCreateFlagBits::RayTracingShaderGroupHandleCaptureReplayBitKHR:
            return "RayTracingShaderGroupHandleCaptureReplayBitKHR";
        case VqPipelineCreateFlagBits::DeferCompileBitNV:
            return "DeferCompileBitNV";
        case VqPipelineCreateFlagBits::CaptureStatisticsBitKHR:
            return "CaptureStatisticsBitKHR";
        case VqPipelineCreateFlagBits::CaptureInternalRepresentationsBitKHR:
            return "CaptureInternalRepresentationsBitKHR";
        case VqPipelineCreateFlagBits::IndirectBindableBitNV:
            return "IndirectBindableBitNV";
        case VqPipelineCreateFlagBits::LibraryBitKHR:
            return "LibraryBitKHR";
        case VqPipelineCreateFlagBits::DescriptorBufferBitEXT:
            return "DescriptorBufferBitEXT";
        case VqPipelineCreateFlagBits::RetainLinkTimeOptimizationInfoBitEXT:
            return "RetainLinkTimeOptimizationInfoBitEXT";
        case VqPipelineCreateFlagBits::LinkTimeOptimizationBitEXT:
            return "LinkTimeOptimizationBitEXT";
        case VqPipelineCreateFlagBits::RayTracingAllowMotionBitNV:
            return "RayTracingAllowMotionBitNV";
        case VqPipelineCreateFlagBits::ColorAttachmentFeedbackLoopBitEXT:
            return "ColorAttachmentFeedbackLoopBitEXT";
        case VqPipelineCreateFlagBits::DepthStencilAttachmentFeedbackLoopBitEXT:
            return "DepthStencilAttachmentFeedbackLoopBitEXT";
        case VqPipelineCreateFlagBits::RayTracingOpacityMicromapBitEXT:
            return "RayTracingOpacityMicromapBitEXT";
        case VqPipelineCreateFlagBits::RayTracingDisplacementMicromapBitNV:
            return "RayTracingDisplacementMicromapBitNV";
        case VqPipelineCreateFlagBits::NoProtectedAccessBitEXT:
            return "NoProtectedAccessBitEXT";
        case VqPipelineCreateFlagBits::ProtectedAccessOnlyBitEXT:
            return "ProtectedAccessOnlyBitEXT";
        case VqPipelineCreateFlagBits::DispatchBase:
            return "DispatchBase";
        case VqPipelineCreateFlagBits::VkPipelineRasterizationStateCreateFragmentShadingRateAttachmentBitKHR:
            return "VkPipelineRasterizationStateCreateFragmentShadingRateAttachmentBitKHR";
        case VqPipelineCreateFlagBits::VkPipelineRasterizationStateCreateFragmentDensityMapAttachmentBitEXT:
            return "VkPipelineRasterizationStateCreateFragmentDensityMapAttachmentBitEXT";
        case VqPipelineCreateFlagBits::ViewIndexFromDeviceIndexBitKHR:
            return "ViewIndexFromDeviceIndexBitKHR";
        case VqPipelineCreateFlagBits::DispatchBaseKHR:
            return "DispatchBaseKHR";
        case VqPipelineCreateFlagBits::FailOnPipelineCompileRequiredBitEXT:
            return "FailOnPipelineCompileRequiredBitEXT";
        case VqPipelineCreateFlagBits::EarlyReturnOnFailureBitEXT:
            return "EarlyReturnOnFailureBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineCreationFeedbackFlagBits v)
    {
        switch(v){
        case VqPipelineCreationFeedbackFlagBits::ValidBit:
            return "ValidBit";
        case VqPipelineCreationFeedbackFlagBits::ApplicationPipelineCacheHitBit:
            return "ApplicationPipelineCacheHitBit";
        case VqPipelineCreationFeedbackFlagBits::BasePipelineAccelerationBit:
            return "BasePipelineAccelerationBit";
        case VqPipelineCreationFeedbackFlagBits::ValidBitEXT:
            return "ValidBitEXT";
        case VqPipelineCreationFeedbackFlagBits::ApplicationPipelineCacheHitBitEXT:
            return "ApplicationPipelineCacheHitBitEXT";
        case VqPipelineCreationFeedbackFlagBits::BasePipelineAccelerationBitEXT:
            return "BasePipelineAccelerationBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineDepthStencilStateCreateFlagBits v)
    {
        switch(v){
        case VqPipelineDepthStencilStateCreateFlagBits::RasterizationOrderAttachmentDepthAccessBitEXT:
            return "RasterizationOrderAttachmentDepthAccessBitEXT";
        case VqPipelineDepthStencilStateCreateFlagBits::RasterizationOrderAttachmentStencilAccessBitEXT:
            return "RasterizationOrderAttachmentStencilAccessBitEXT";
        case VqPipelineDepthStencilStateCreateFlagBits::RasterizationOrderAttachmentDepthAccessBitArm:
            return "RasterizationOrderAttachmentDepthAccessBitArm";
        case VqPipelineDepthStencilStateCreateFlagBits::RasterizationOrderAttachmentStencilAccessBitArm:
            return "RasterizationOrderAttachmentStencilAccessBitArm";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineExecutableStatisticFormat v)
    {
        switch(v){
        case VqPipelineExecutableStatisticFormat::Bool32KHR:
            return "Bool32KHR";
        case VqPipelineExecutableStatisticFormat::Int64KHR:
            return "Int64KHR";
        case VqPipelineExecutableStatisticFormat::Uint64KHR:
            return "Uint64KHR";
        case VqPipelineExecutableStatisticFormat::Float64KHR:
            return "Float64KHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineLayoutCreateFlagBits v)
    {
        switch(v){
        case VqPipelineLayoutCreateFlagBits::IndependentSetsBitEXT:
            return "IndependentSetsBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineRobustnessBufferBehavior v)
    {
        switch(v){
        case VqPipelineRobustnessBufferBehavior::DeviceDefaultEXT:
            return "DeviceDefaultEXT";
        case VqPipelineRobustnessBufferBehavior::DisabledEXT:
            return "DisabledEXT";
        case VqPipelineRobustnessBufferBehavior::RobustBufferAccessEXT:
            return "RobustBufferAccessEXT";
        case VqPipelineRobustnessBufferBehavior::RobustBufferAccess2EXT:
            return "RobustBufferAccess2EXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineRobustnessImageBehavior v)
    {
        switch(v){
        case VqPipelineRobustnessImageBehavior::DeviceDefaultEXT:
            return "DeviceDefaultEXT";
        case VqPipelineRobustnessImageBehavior::DisabledEXT:
            return "DisabledEXT";
        case VqPipelineRobustnessImageBehavior::RobustImageAccessEXT:
            return "RobustImageAccessEXT";
        case VqPipelineRobustnessImageBehavior::RobustImageAccess2EXT:
            return "RobustImageAccess2EXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineShaderStageCreateFlagBits v)
    {
        switch(v){
        case VqPipelineShaderStageCreateFlagBits::AllowVaryingSubgroupSizeBit:
            return "AllowVaryingSubgroupSizeBit";
        case VqPipelineShaderStageCreateFlagBits::RequireFullSubgroupsBit:
            return "RequireFullSubgroupsBit";
        case VqPipelineShaderStageCreateFlagBits::AllowVaryingSubgroupSizeBitEXT:
            return "AllowVaryingSubgroupSizeBitEXT";
        case VqPipelineShaderStageCreateFlagBits::RequireFullSubgroupsBitEXT:
            return "RequireFullSubgroupsBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineStageFlagBits v)
    {
        switch(v){
        case VqPipelineStageFlagBits::TopOfPipeBit:
            return "TopOfPipeBit";
        case VqPipelineStageFlagBits::DrawIndirectBit:
            return "DrawIndirectBit";
        case VqPipelineStageFlagBits::VertexInputBit:
            return "VertexInputBit";
        case VqPipelineStageFlagBits::VertexShaderBit:
            return "VertexShaderBit";
        case VqPipelineStageFlagBits::TessellationControlShaderBit:
            return "TessellationControlShaderBit";
        case VqPipelineStageFlagBits::TessellationEvaluationShaderBit:
            return "TessellationEvaluationShaderBit";
        case VqPipelineStageFlagBits::GeometryShaderBit:
            return "GeometryShaderBit";
        case VqPipelineStageFlagBits::FragmentShaderBit:
            return "FragmentShaderBit";
        case VqPipelineStageFlagBits::EarlyFragmentTestsBit:
            return "EarlyFragmentTestsBit";
        case VqPipelineStageFlagBits::LateFragmentTestsBit:
            return "LateFragmentTestsBit";
        case VqPipelineStageFlagBits::ColorAttachmentOutputBit:
            return "ColorAttachmentOutputBit";
        case VqPipelineStageFlagBits::ComputeShaderBit:
            return "ComputeShaderBit";
        case VqPipelineStageFlagBits::TransferBit:
            return "TransferBit";
        case VqPipelineStageFlagBits::BottomOfPipeBit:
            return "BottomOfPipeBit";
        case VqPipelineStageFlagBits::HostBit:
            return "HostBit";
        case VqPipelineStageFlagBits::AllGraphicsBit:
            return "AllGraphicsBit";
        case VqPipelineStageFlagBits::AllCommandsBit:
            return "AllCommandsBit";
        case VqPipelineStageFlagBits::None:
            return "None";
        case VqPipelineStageFlagBits::TransformFeedbackBitEXT:
            return "TransformFeedbackBitEXT";
        case VqPipelineStageFlagBits::ConditionalRenderingBitEXT:
            return "ConditionalRenderingBitEXT";
        case VqPipelineStageFlagBits::AccelerationStructureBuildBitKHR:
            return "AccelerationStructureBuildBitKHR";
        case VqPipelineStageFlagBits::RayTracingShaderBitKHR:
            return "RayTracingShaderBitKHR";
        case VqPipelineStageFlagBits::FragmentDensityProcessBitEXT:
            return "FragmentDensityProcessBitEXT";
        case VqPipelineStageFlagBits::FragmentShadingRateAttachmentBitKHR:
            return "FragmentShadingRateAttachmentBitKHR";
        case VqPipelineStageFlagBits::CommandPreprocessBitNV:
            return "CommandPreprocessBitNV";
        case VqPipelineStageFlagBits::TaskShaderBitEXT:
            return "TaskShaderBitEXT";
        case VqPipelineStageFlagBits::MeshShaderBitEXT:
            return "MeshShaderBitEXT";
        case VqPipelineStageFlagBits::ShadingRateImageBitNV:
            return "ShadingRateImageBitNV";
        case VqPipelineStageFlagBits::RayTracingShaderBitNV:
            return "RayTracingShaderBitNV";
        case VqPipelineStageFlagBits::AccelerationStructureBuildBitNV:
            return "AccelerationStructureBuildBitNV";
        case VqPipelineStageFlagBits::TaskShaderBitNV:
            return "TaskShaderBitNV";
        case VqPipelineStageFlagBits::MeshShaderBitNV:
            return "MeshShaderBitNV";
        case VqPipelineStageFlagBits::NoneKHR:
            return "NoneKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPointClippingBehavior v)
    {
        switch(v){
        case VqPointClippingBehavior::AllClipPlanes:
            return "AllClipPlanes";
        case VqPointClippingBehavior::UserClipPlanesOnly:
            return "UserClipPlanesOnly";
        case VqPointClippingBehavior::AllClipPlanesKHR:
            return "AllClipPlanesKHR";
        case VqPointClippingBehavior::UserClipPlanesOnlyKHR:
            return "UserClipPlanesOnlyKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPolygonMode v)
    {
        switch(v){
        case VqPolygonMode::Fill:
            return "Fill";
        case VqPolygonMode::Line:
            return "Line";
        case VqPolygonMode::Point:
            return "Point";
        case VqPolygonMode::FillRectangleNV:
            return "FillRectangleNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPresentGravityFlagBits v)
    {
        switch(v){
        case VqPresentGravityFlagBits::MinBitEXT:
            return "MinBitEXT";
        case VqPresentGravityFlagBits::MaxBitEXT:
            return "MaxBitEXT";
        case VqPresentGravityFlagBits::CenteredBitEXT:
            return "CenteredBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPresentMode v)
    {
        switch(v){
        case VqPresentMode::ImmediateKHR:
            return "ImmediateKHR";
        case VqPresentMode::MailboxKHR:
            return "MailboxKHR";
        case VqPresentMode::FifoKHR:
            return "FifoKHR";
        case VqPresentMode::FifoRelaxedKHR:
            return "FifoRelaxedKHR";
        case VqPresentMode::SharedDemandRefreshKHR:
            return "SharedDemandRefreshKHR";
        case VqPresentMode::SharedContinuousRefreshKHR:
            return "SharedContinuousRefreshKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPresentScalingFlagBits v)
    {
        switch(v){
        case VqPresentScalingFlagBits::OneToOneBitEXT:
            return "OneToOneBitEXT";
        case VqPresentScalingFlagBits::AspectRatioStretchBitEXT:
            return "AspectRatioStretchBitEXT";
        case VqPresentScalingFlagBits::StretchBitEXT:
            return "StretchBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPrimitiveTopology v)
    {
        switch(v){
        case VqPrimitiveTopology::PointList:
            return "PointList";
        case VqPrimitiveTopology::LineList:
            return "LineList";
        case VqPrimitiveTopology::LineStrip:
            return "LineStrip";
        case VqPrimitiveTopology::TriangleList:
            return "TriangleList";
        case VqPrimitiveTopology::TriangleStrip:
            return "TriangleStrip";
        case VqPrimitiveTopology::TriangleFan:
            return "TriangleFan";
        case VqPrimitiveTopology::LineListWithAdjacency:
            return "LineListWithAdjacency";
        case VqPrimitiveTopology::LineStripWithAdjacency:
            return "LineStripWithAdjacency";
        case VqPrimitiveTopology::TriangleListWithAdjacency:
            return "TriangleListWithAdjacency";
        case VqPrimitiveTopology::TriangleStripWithAdjacency:
            return "TriangleStripWithAdjacency";
        case VqPrimitiveTopology::PatchList:
            return "PatchList";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqProvokingVertexMode v)
    {
        switch(v){
        case VqProvokingVertexMode::FirstVertexEXT:
            return "FirstVertexEXT";
        case VqProvokingVertexMode::LastVertexEXT:
            return "LastVertexEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqQueryControlFlagBits v)
    {
        switch(v){
        case VqQueryControlFlagBits::PreciseBit:
            return "PreciseBit";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqQueryPipelineStatisticFlagBits v)
    {
        switch(v){
        case VqQueryPipelineStatisticFlagBits::InputAssemblyVerticesBit:
            return "InputAssemblyVerticesBit";
        case VqQueryPipelineStatisticFlagBits::InputAssemblyPrimitivesBit:
            return "InputAssemblyPrimitivesBit";
        case VqQueryPipelineStatisticFlagBits::VertexShaderInvocationsBit:
            return "VertexShaderInvocationsBit";
        case VqQueryPipelineStatisticFlagBits::GeometryShaderInvocationsBit:
            return "GeometryShaderInvocationsBit";
        case VqQueryPipelineStatisticFlagBits::GeometryShaderPrimitivesBit:
            return "GeometryShaderPrimitivesBit";
        case VqQueryPipelineStatisticFlagBits::ClippingInvocationsBit:
            return "ClippingInvocationsBit";
        case VqQueryPipelineStatisticFlagBits::ClippingPrimitivesBit:
            return "ClippingPrimitivesBit";
        case VqQueryPipelineStatisticFlagBits::FragmentShaderInvocationsBit:
            return "FragmentShaderInvocationsBit";
        case VqQueryPipelineStatisticFlagBits::TessellationControlShaderPatchesBit:
            return "TessellationControlShaderPatchesBit";
        case VqQueryPipelineStatisticFlagBits::TessellationEvaluationShaderInvocationsBit:
            return "TessellationEvaluationShaderInvocationsBit";
        case VqQueryPipelineStatisticFlagBits::ComputeShaderInvocationsBit:
            return "ComputeShaderInvocationsBit";
        case VqQueryPipelineStatisticFlagBits::TaskShaderInvocationsBitEXT:
            return "TaskShaderInvocationsBitEXT";
        case VqQueryPipelineStatisticFlagBits::MeshShaderInvocationsBitEXT:
            return "MeshShaderInvocationsBitEXT";
        case VqQueryPipelineStatisticFlagBits::ClusterCullingShaderInvocationsBitHuawei:
            return "ClusterCullingShaderInvocationsBitHuawei";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqQueryPoolSamplingMode v)
    {
        switch(v){
        case VqQueryPoolSamplingMode::ManualINTEL:
            return "ManualINTEL";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqQueryResultFlagBits v)
    {
        switch(v){
        case VqQueryResultFlagBits::64Bit:
            return "64Bit";
        case VqQueryResultFlagBits::WaitBit:
            return "WaitBit";
        case VqQueryResultFlagBits::WithAvailabilityBit:
            return "WithAvailabilityBit";
        case VqQueryResultFlagBits::PartialBit:
            return "PartialBit";
        case VqQueryResultFlagBits::WithStatusBitKHR:
            return "WithStatusBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqQueryResultStatus v)
    {
        switch(v){
        case VqQueryResultStatus::ErrorKHR:
            return "ErrorKHR";
        case VqQueryResultStatus::NotReadyKHR:
            return "NotReadyKHR";
        case VqQueryResultStatus::CompleteKHR:
            return "CompleteKHR";
        case VqQueryResultStatus::InsufficientBitstreamBufferRangeKHR:
            return "InsufficientBitstreamBufferRangeKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqQueryType v)
    {
        switch(v){
        case VqQueryType::Occlusion:
            return "Occlusion";
        case VqQueryType::PipelineStatistics:
            return "PipelineStatistics";
        case VqQueryType::Timestamp:
            return "Timestamp";
        case VqQueryType::ResultStatusOnlyKHR:
            return "ResultStatusOnlyKHR";
        case VqQueryType::TransformFeedbackStreamEXT:
            return "TransformFeedbackStreamEXT";
        case VqQueryType::PerformanceQueryKHR:
            return "PerformanceQueryKHR";
        case VqQueryType::AccelerationStructureCompactedSizeKHR:
            return "AccelerationStructureCompactedSizeKHR";
        case VqQueryType::AccelerationStructureSerializationSizeKHR:
            return "AccelerationStructureSerializationSizeKHR";
        case VqQueryType::AccelerationStructureCompactedSizeNV:
            return "AccelerationStructureCompactedSizeNV";
        case VqQueryType::PerformanceQueryINTEL:
            return "PerformanceQueryINTEL";
        case VqQueryType::VideoEncodeFeedbackKHR:
            return "VideoEncodeFeedbackKHR";
        case VqQueryType::MeshPrimitivesGeneratedEXT:
            return "MeshPrimitivesGeneratedEXT";
        case VqQueryType::PrimitivesGeneratedEXT:
            return "PrimitivesGeneratedEXT";
        case VqQueryType::AccelerationStructureSerializationBottomLevelPointersKHR:
            return "AccelerationStructureSerializationBottomLevelPointersKHR";
        case VqQueryType::AccelerationStructureSizeKHR:
            return "AccelerationStructureSizeKHR";
        case VqQueryType::MicromapSerializationSizeEXT:
            return "MicromapSerializationSizeEXT";
        case VqQueryType::MicromapCompactedSizeEXT:
            return "MicromapCompactedSizeEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqQueueFlagBits v)
    {
        switch(v){
        case VqQueueFlagBits::GraphicsBit:
            return "GraphicsBit";
        case VqQueueFlagBits::ComputeBit:
            return "ComputeBit";
        case VqQueueFlagBits::TransferBit:
            return "TransferBit";
        case VqQueueFlagBits::SparseBindingBit:
            return "SparseBindingBit";
        case VqQueueFlagBits::ProtectedBit:
            return "ProtectedBit";
        case VqQueueFlagBits::VideoDecodeBitKHR:
            return "VideoDecodeBitKHR";
        case VqQueueFlagBits::VideoEncodeBitKHR:
            return "VideoEncodeBitKHR";
        case VqQueueFlagBits::OpticalFlowBitNV:
            return "OpticalFlowBitNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqQueueGlobalPriority v)
    {
        switch(v){
        case VqQueueGlobalPriority::LowKHR:
            return "LowKHR";
        case VqQueueGlobalPriority::MediumKHR:
            return "MediumKHR";
        case VqQueueGlobalPriority::HighKHR:
            return "HighKHR";
        case VqQueueGlobalPriority::RealtimeKHR:
            return "RealtimeKHR";
        case VqQueueGlobalPriority::LowEXT:
            return "LowEXT";
        case VqQueueGlobalPriority::MediumEXT:
            return "MediumEXT";
        case VqQueueGlobalPriority::HighEXT:
            return "HighEXT";
        case VqQueueGlobalPriority::RealtimeEXT:
            return "RealtimeEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqRasterizationOrder v)
    {
        switch(v){
        case VqRasterizationOrder::StrictAMD:
            return "StrictAMD";
        case VqRasterizationOrder::RelaxedAMD:
            return "RelaxedAMD";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqRayTracingInvocationReorderMode v)
    {
        switch(v){
        case VqRayTracingInvocationReorderMode::NoneNV:
            return "NoneNV";
        case VqRayTracingInvocationReorderMode::ReorderNV:
            return "ReorderNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqRayTracingShaderGroupType v)
    {
        switch(v){
        case VqRayTracingShaderGroupType::GeneralKHR:
            return "GeneralKHR";
        case VqRayTracingShaderGroupType::TrianglesHitGroupKHR:
            return "TrianglesHitGroupKHR";
        case VqRayTracingShaderGroupType::ProceduralHitGroupKHR:
            return "ProceduralHitGroupKHR";
        case VqRayTracingShaderGroupType::GeneralNV:
            return "GeneralNV";
        case VqRayTracingShaderGroupType::TrianglesHitGroupNV:
            return "TrianglesHitGroupNV";
        case VqRayTracingShaderGroupType::ProceduralHitGroupNV:
            return "ProceduralHitGroupNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqRenderPassCreateFlagBits v)
    {
        switch(v){
        case VqRenderPassCreateFlagBits::TransformBitQCOM:
            return "TransformBitQCOM";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqRenderingFlagBits v)
    {
        switch(v){
        case VqRenderingFlagBits::ContentsSecondaryCommandBuffersBit:
            return "ContentsSecondaryCommandBuffersBit";
        case VqRenderingFlagBits::SuspendingBit:
            return "SuspendingBit";
        case VqRenderingFlagBits::ResumingBit:
            return "ResumingBit";
        case VqRenderingFlagBits::EnableLegacyDitheringBitEXT:
            return "EnableLegacyDitheringBitEXT";
        case VqRenderingFlagBits::ContentsInlineBitKHR:
            return "ContentsInlineBitKHR";
        case VqRenderingFlagBits::ContentsSecondaryCommandBuffersBitKHR:
            return "ContentsSecondaryCommandBuffersBitKHR";
        case VqRenderingFlagBits::SuspendingBitKHR:
            return "SuspendingBitKHR";
        case VqRenderingFlagBits::ResumingBitKHR:
            return "ResumingBitKHR";
        case VqRenderingFlagBits::ContentsInlineBitEXT:
            return "ContentsInlineBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqResolveModeFlagBits v)
    {
        switch(v){
        case VqResolveModeFlagBits::None:
            return "None";
        case VqResolveModeFlagBits::SampleZeroBit:
            return "SampleZeroBit";
        case VqResolveModeFlagBits::AverageBit:
            return "AverageBit";
        case VqResolveModeFlagBits::MinBit:
            return "MinBit";
        case VqResolveModeFlagBits::MaxBit:
            return "MaxBit";
        case VqResolveModeFlagBits::ExternalFormatDownsampleAndroid:
            return "ExternalFormatDownsampleAndroid";
        case VqResolveModeFlagBits::NoneKHR:
            return "NoneKHR";
        case VqResolveModeFlagBits::SampleZeroBitKHR:
            return "SampleZeroBitKHR";
        case VqResolveModeFlagBits::AverageBitKHR:
            return "AverageBitKHR";
        case VqResolveModeFlagBits::MinBitKHR:
            return "MinBitKHR";
        case VqResolveModeFlagBits::MaxBitKHR:
            return "MaxBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqResult v)
    {
        switch(v){
        case VqResult::VkSuccess:
            return "VkSuccess";
        case VqResult::VkNotReady:
            return "VkNotReady";
        case VqResult::VkTimeout:
            return "VkTimeout";
        case VqResult::VkEventSet:
            return "VkEventSet";
        case VqResult::VkEventReset:
            return "VkEventReset";
        case VqResult::VkIncomplete:
            return "VkIncomplete";
        case VqResult::VkErrorOutOfHostMemory:
            return "VkErrorOutOfHostMemory";
        case VqResult::VkErrorOutOfDeviceMemory:
            return "VkErrorOutOfDeviceMemory";
        case VqResult::VkErrorInitializationFailed:
            return "VkErrorInitializationFailed";
        case VqResult::VkErrorDeviceLost:
            return "VkErrorDeviceLost";
        case VqResult::VkErrorMemoryMapFailed:
            return "VkErrorMemoryMapFailed";
        case VqResult::VkErrorLayerNotPresent:
            return "VkErrorLayerNotPresent";
        case VqResult::VkErrorExtensionNotPresent:
            return "VkErrorExtensionNotPresent";
        case VqResult::VkErrorFeatureNotPresent:
            return "VkErrorFeatureNotPresent";
        case VqResult::VkErrorIncompatibleDriver:
            return "VkErrorIncompatibleDriver";
        case VqResult::VkErrorTooManyObjects:
            return "VkErrorTooManyObjects";
        case VqResult::VkErrorFormatNotSupported:
            return "VkErrorFormatNotSupported";
        case VqResult::VkErrorFragmentedPool:
            return "VkErrorFragmentedPool";
        case VqResult::VkErrorUnknown:
            return "VkErrorUnknown";
        case VqResult::VkErrorOutOfPoolMemory:
            return "VkErrorOutOfPoolMemory";
        case VqResult::VkErrorInvalidExternalHandle:
            return "VkErrorInvalidExternalHandle";
        case VqResult::VkErrorFragmentation:
            return "VkErrorFragmentation";
        case VqResult::VkErrorInvalidOpaqueCaptureAddress:
            return "VkErrorInvalidOpaqueCaptureAddress";
        case VqResult::VkPipelineCompileRequired:
            return "VkPipelineCompileRequired";
        case VqResult::VkErrorSurfaceLostKHR:
            return "VkErrorSurfaceLostKHR";
        case VqResult::VkErrorNativeWindowInUseKHR:
            return "VkErrorNativeWindowInUseKHR";
        case VqResult::VkSuboptimalKHR:
            return "VkSuboptimalKHR";
        case VqResult::VkErrorOutOfDateKHR:
            return "VkErrorOutOfDateKHR";
        case VqResult::VkErrorIncompatibleDisplayKHR:
            return "VkErrorIncompatibleDisplayKHR";
        case VqResult::VkErrorValidationFailedEXT:
            return "VkErrorValidationFailedEXT";
        case VqResult::VkErrorInvalidShaderNV:
            return "VkErrorInvalidShaderNV";
        case VqResult::VkErrorImageUsageNotSupportedKHR:
            return "VkErrorImageUsageNotSupportedKHR";
        case VqResult::VkErrorVideoPictureLayoutNotSupportedKHR:
            return "VkErrorVideoPictureLayoutNotSupportedKHR";
        case VqResult::VkErrorVideoProfileOperationNotSupportedKHR:
            return "VkErrorVideoProfileOperationNotSupportedKHR";
        case VqResult::VkErrorVideoProfileFormatNotSupportedKHR:
            return "VkErrorVideoProfileFormatNotSupportedKHR";
        case VqResult::VkErrorVideoProfileCodecNotSupportedKHR:
            return "VkErrorVideoProfileCodecNotSupportedKHR";
        case VqResult::VkErrorVideoStdVersionNotSupportedKHR:
            return "VkErrorVideoStdVersionNotSupportedKHR";
        case VqResult::VkErrorInvalidDrmFormatModifierPlaneLayoutEXT:
            return "VkErrorInvalidDrmFormatModifierPlaneLayoutEXT";
        case VqResult::VkErrorNotPermittedKHR:
            return "VkErrorNotPermittedKHR";
        case VqResult::VkErrorFullScreenExclusiveModeLostEXT:
            return "VkErrorFullScreenExclusiveModeLostEXT";
        case VqResult::VkThreadIdleKHR:
            return "VkThreadIdleKHR";
        case VqResult::VkThreadDoneKHR:
            return "VkThreadDoneKHR";
        case VqResult::VkOperationDeferredKHR:
            return "VkOperationDeferredKHR";
        case VqResult::VkOperationNotDeferredKHR:
            return "VkOperationNotDeferredKHR";
        case VqResult::VkErrorInvalidVideoStdParametersKHR:
            return "VkErrorInvalidVideoStdParametersKHR";
        case VqResult::VkErrorCompressionExhaustedEXT:
            return "VkErrorCompressionExhaustedEXT";
        case VqResult::VkIncompatibleShaderBinaryEXT:
            return "VkIncompatibleShaderBinaryEXT";
        case VqResult::VkErrorOutOfPoolMemoryKHR:
            return "VkErrorOutOfPoolMemoryKHR";
        case VqResult::VkErrorInvalidExternalHandleKHR:
            return "VkErrorInvalidExternalHandleKHR";
        case VqResult::VkErrorFragmentationEXT:
            return "VkErrorFragmentationEXT";
        case VqResult::VkErrorNotPermittedEXT:
            return "VkErrorNotPermittedEXT";
        case VqResult::VkErrorInvalidDeviceAddressEXT:
            return "VkErrorInvalidDeviceAddressEXT";
        case VqResult::VkErrorInvalidOpaqueCaptureAddressKHR:
            return "VkErrorInvalidOpaqueCaptureAddressKHR";
        case VqResult::VkPipelineCompileRequiredEXT:
            return "VkPipelineCompileRequiredEXT";
        case VqResult::VkErrorPipelineCompileRequiredEXT:
            return "VkErrorPipelineCompileRequiredEXT";
        case VqResult::VkErrorIncompatibleShaderBinaryEXT:
            return "VkErrorIncompatibleShaderBinaryEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSampleCountFlagBits v)
    {
        switch(v){
        case VqSampleCountFlagBits::1Bit:
            return "1Bit";
        case VqSampleCountFlagBits::2Bit:
            return "2Bit";
        case VqSampleCountFlagBits::4Bit:
            return "4Bit";
        case VqSampleCountFlagBits::8Bit:
            return "8Bit";
        case VqSampleCountFlagBits::16Bit:
            return "16Bit";
        case VqSampleCountFlagBits::32Bit:
            return "32Bit";
        case VqSampleCountFlagBits::64Bit:
            return "64Bit";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSamplerAddressMode v)
    {
        switch(v){
        case VqSamplerAddressMode::Repeat:
            return "Repeat";
        case VqSamplerAddressMode::MirroredRepeat:
            return "MirroredRepeat";
        case VqSamplerAddressMode::ClampToEdge:
            return "ClampToEdge";
        case VqSamplerAddressMode::ClampToBorder:
            return "ClampToBorder";
        case VqSamplerAddressMode::MirrorClampToEdge:
            return "MirrorClampToEdge";
        case VqSamplerAddressMode::MirrorClampToEdgeKHR:
            return "MirrorClampToEdgeKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSamplerCreateFlagBits v)
    {
        switch(v){
        case VqSamplerCreateFlagBits::SubsampledBitEXT:
            return "SubsampledBitEXT";
        case VqSamplerCreateFlagBits::SubsampledCoarseReconstructionBitEXT:
            return "SubsampledCoarseReconstructionBitEXT";
        case VqSamplerCreateFlagBits::DescriptorBufferCaptureReplayBitEXT:
            return "DescriptorBufferCaptureReplayBitEXT";
        case VqSamplerCreateFlagBits::NonSeamlessCubeMapBitEXT:
            return "NonSeamlessCubeMapBitEXT";
        case VqSamplerCreateFlagBits::ImageProcessingBitQCOM:
            return "ImageProcessingBitQCOM";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSamplerMipmapMode v)
    {
        switch(v){
        case VqSamplerMipmapMode::Nearest:
            return "Nearest";
        case VqSamplerMipmapMode::Linear:
            return "Linear";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSamplerReductionMode v)
    {
        switch(v){
        case VqSamplerReductionMode::WeightedAverage:
            return "WeightedAverage";
        case VqSamplerReductionMode::Min:
            return "Min";
        case VqSamplerReductionMode::Max:
            return "Max";
        case VqSamplerReductionMode::WeightedAverageRangeclampQCOM:
            return "WeightedAverageRangeclampQCOM";
        case VqSamplerReductionMode::WeightedAverageEXT:
            return "WeightedAverageEXT";
        case VqSamplerReductionMode::MinEXT:
            return "MinEXT";
        case VqSamplerReductionMode::MaxEXT:
            return "MaxEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSamplerYcbcrModelConversion v)
    {
        switch(v){
        case VqSamplerYcbcrModelConversion::RgbIdentity:
            return "RgbIdentity";
        case VqSamplerYcbcrModelConversion::YcbcrIdentity:
            return "YcbcrIdentity";
        case VqSamplerYcbcrModelConversion::Ycbcr709:
            return "Ycbcr709";
        case VqSamplerYcbcrModelConversion::Ycbcr601:
            return "Ycbcr601";
        case VqSamplerYcbcrModelConversion::Ycbcr2020:
            return "Ycbcr2020";
        case VqSamplerYcbcrModelConversion::RgbIdentityKHR:
            return "RgbIdentityKHR";
        case VqSamplerYcbcrModelConversion::YcbcrIdentityKHR:
            return "YcbcrIdentityKHR";
        case VqSamplerYcbcrModelConversion::Ycbcr709KHR:
            return "Ycbcr709KHR";
        case VqSamplerYcbcrModelConversion::Ycbcr601KHR:
            return "Ycbcr601KHR";
        case VqSamplerYcbcrModelConversion::Ycbcr2020KHR:
            return "Ycbcr2020KHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSamplerYcbcrRange v)
    {
        switch(v){
        case VqSamplerYcbcrRange::ItuFull:
            return "ItuFull";
        case VqSamplerYcbcrRange::ItuNarrow:
            return "ItuNarrow";
        case VqSamplerYcbcrRange::ItuFullKHR:
            return "ItuFullKHR";
        case VqSamplerYcbcrRange::ItuNarrowKHR:
            return "ItuNarrowKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqScope v)
    {
        switch(v){
        case VqScope::DeviceKHR:
            return "DeviceKHR";
        case VqScope::WorkgroupKHR:
            return "WorkgroupKHR";
        case VqScope::SubgroupKHR:
            return "SubgroupKHR";
        case VqScope::QueueFamilyKHR:
            return "QueueFamilyKHR";
        case VqScope::DeviceNV:
            return "DeviceNV";
        case VqScope::WorkgroupNV:
            return "WorkgroupNV";
        case VqScope::SubgroupNV:
            return "SubgroupNV";
        case VqScope::QueueFamilyNV:
            return "QueueFamilyNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSemaphoreImportFlagBits v)
    {
        switch(v){
        case VqSemaphoreImportFlagBits::TemporaryBit:
            return "TemporaryBit";
        case VqSemaphoreImportFlagBits::TemporaryBitKHR:
            return "TemporaryBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSemaphoreType v)
    {
        switch(v){
        case VqSemaphoreType::Binary:
            return "Binary";
        case VqSemaphoreType::Timeline:
            return "Timeline";
        case VqSemaphoreType::BinaryKHR:
            return "BinaryKHR";
        case VqSemaphoreType::TimelineKHR:
            return "TimelineKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSemaphoreWaitFlagBits v)
    {
        switch(v){
        case VqSemaphoreWaitFlagBits::AnyBit:
            return "AnyBit";
        case VqSemaphoreWaitFlagBits::AnyBitKHR:
            return "AnyBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqShaderCodeType v)
    {
        switch(v){
        case VqShaderCodeType::BinaryEXT:
            return "BinaryEXT";
        case VqShaderCodeType::SpirvEXT:
            return "SpirvEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqShaderCorePropertiesFlagBits v)
    {
        switch(v){
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqShaderCreateFlagBits v)
    {
        switch(v){
        case VqShaderCreateFlagBits::LinkStageBitEXT:
            return "LinkStageBitEXT";
        case VqShaderCreateFlagBits::AllowVaryingSubgroupSizeBitEXT:
            return "AllowVaryingSubgroupSizeBitEXT";
        case VqShaderCreateFlagBits::RequireFullSubgroupsBitEXT:
            return "RequireFullSubgroupsBitEXT";
        case VqShaderCreateFlagBits::NoTaskShaderBitEXT:
            return "NoTaskShaderBitEXT";
        case VqShaderCreateFlagBits::DispatchBaseBitEXT:
            return "DispatchBaseBitEXT";
        case VqShaderCreateFlagBits::FragmentShadingRateAttachmentBitEXT:
            return "FragmentShadingRateAttachmentBitEXT";
        case VqShaderCreateFlagBits::FragmentDensityMapAttachmentBitEXT:
            return "FragmentDensityMapAttachmentBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqShaderFloatControlsIndependence v)
    {
        switch(v){
        case VqShaderFloatControlsIndependence::32BitOnly:
            return "32BitOnly";
        case VqShaderFloatControlsIndependence::All:
            return "All";
        case VqShaderFloatControlsIndependence::None:
            return "None";
        case VqShaderFloatControlsIndependence::32BitOnlyKHR:
            return "32BitOnlyKHR";
        case VqShaderFloatControlsIndependence::AllKHR:
            return "AllKHR";
        case VqShaderFloatControlsIndependence::NoneKHR:
            return "NoneKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqShaderGroupShader v)
    {
        switch(v){
        case VqShaderGroupShader::GeneralKHR:
            return "GeneralKHR";
        case VqShaderGroupShader::ClosestHitKHR:
            return "ClosestHitKHR";
        case VqShaderGroupShader::AnyHitKHR:
            return "AnyHitKHR";
        case VqShaderGroupShader::IntersectionKHR:
            return "IntersectionKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqShaderInfoType v)
    {
        switch(v){
        case VqShaderInfoType::StatisticsAMD:
            return "StatisticsAMD";
        case VqShaderInfoType::BinaryAMD:
            return "BinaryAMD";
        case VqShaderInfoType::DisassemblyAMD:
            return "DisassemblyAMD";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqShaderStageFlagBits v)
    {
        switch(v){
        case VqShaderStageFlagBits::VertexBit:
            return "VertexBit";
        case VqShaderStageFlagBits::TessellationControlBit:
            return "TessellationControlBit";
        case VqShaderStageFlagBits::TessellationEvaluationBit:
            return "TessellationEvaluationBit";
        case VqShaderStageFlagBits::GeometryBit:
            return "GeometryBit";
        case VqShaderStageFlagBits::FragmentBit:
            return "FragmentBit";
        case VqShaderStageFlagBits::ComputeBit:
            return "ComputeBit";
        case VqShaderStageFlagBits::AllGraphics:
            return "AllGraphics";
        case VqShaderStageFlagBits::All:
            return "All";
        case VqShaderStageFlagBits::RaygenBitKHR:
            return "RaygenBitKHR";
        case VqShaderStageFlagBits::AnyHitBitKHR:
            return "AnyHitBitKHR";
        case VqShaderStageFlagBits::ClosestHitBitKHR:
            return "ClosestHitBitKHR";
        case VqShaderStageFlagBits::MissBitKHR:
            return "MissBitKHR";
        case VqShaderStageFlagBits::IntersectionBitKHR:
            return "IntersectionBitKHR";
        case VqShaderStageFlagBits::CallableBitKHR:
            return "CallableBitKHR";
        case VqShaderStageFlagBits::TaskBitEXT:
            return "TaskBitEXT";
        case VqShaderStageFlagBits::MeshBitEXT:
            return "MeshBitEXT";
        case VqShaderStageFlagBits::SubpassShadingBitHuawei:
            return "SubpassShadingBitHuawei";
        case VqShaderStageFlagBits::ClusterCullingBitHuawei:
            return "ClusterCullingBitHuawei";
        case VqShaderStageFlagBits::RaygenBitNV:
            return "RaygenBitNV";
        case VqShaderStageFlagBits::AnyHitBitNV:
            return "AnyHitBitNV";
        case VqShaderStageFlagBits::ClosestHitBitNV:
            return "ClosestHitBitNV";
        case VqShaderStageFlagBits::MissBitNV:
            return "MissBitNV";
        case VqShaderStageFlagBits::IntersectionBitNV:
            return "IntersectionBitNV";
        case VqShaderStageFlagBits::CallableBitNV:
            return "CallableBitNV";
        case VqShaderStageFlagBits::TaskBitNV:
            return "TaskBitNV";
        case VqShaderStageFlagBits::MeshBitNV:
            return "MeshBitNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqShadingRatePaletteEntry v)
    {
        switch(v){
        case VqShadingRatePaletteEntry::NoInvocationsNV:
            return "NoInvocationsNV";
        case VqShadingRatePaletteEntry::16InvocationsPerPixelNV:
            return "16InvocationsPerPixelNV";
        case VqShadingRatePaletteEntry::8InvocationsPerPixelNV:
            return "8InvocationsPerPixelNV";
        case VqShadingRatePaletteEntry::4InvocationsPerPixelNV:
            return "4InvocationsPerPixelNV";
        case VqShadingRatePaletteEntry::2InvocationsPerPixelNV:
            return "2InvocationsPerPixelNV";
        case VqShadingRatePaletteEntry::1InvocationPerPixelNV:
            return "1InvocationPerPixelNV";
        case VqShadingRatePaletteEntry::1InvocationPer2x1PixelsNV:
            return "1InvocationPer2x1PixelsNV";
        case VqShadingRatePaletteEntry::1InvocationPer1x2PixelsNV:
            return "1InvocationPer1x2PixelsNV";
        case VqShadingRatePaletteEntry::1InvocationPer2x2PixelsNV:
            return "1InvocationPer2x2PixelsNV";
        case VqShadingRatePaletteEntry::1InvocationPer4x2PixelsNV:
            return "1InvocationPer4x2PixelsNV";
        case VqShadingRatePaletteEntry::1InvocationPer2x4PixelsNV:
            return "1InvocationPer2x4PixelsNV";
        case VqShadingRatePaletteEntry::1InvocationPer4x4PixelsNV:
            return "1InvocationPer4x4PixelsNV";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSharingMode v)
    {
        switch(v){
        case VqSharingMode::Exclusive:
            return "Exclusive";
        case VqSharingMode::Concurrent:
            return "Concurrent";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSparseImageFormatFlagBits v)
    {
        switch(v){
        case VqSparseImageFormatFlagBits::SingleMiptailBit:
            return "SingleMiptailBit";
        case VqSparseImageFormatFlagBits::AlignedMipSizeBit:
            return "AlignedMipSizeBit";
        case VqSparseImageFormatFlagBits::NonstandardBlockSizeBit:
            return "NonstandardBlockSizeBit";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSparseMemoryBindFlagBits v)
    {
        switch(v){
        case VqSparseMemoryBindFlagBits::MetadataBit:
            return "MetadataBit";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqStencilFaceFlagBits v)
    {
        switch(v){
        case VqStencilFaceFlagBits::FrontBit:
            return "FrontBit";
        case VqStencilFaceFlagBits::BackBit:
            return "BackBit";
        case VqStencilFaceFlagBits::FrontAndBack:
            return "FrontAndBack";
        case VqStencilFaceFlagBits::VkStencilFrontAndBack:
            return "VkStencilFrontAndBack";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqStencilOp v)
    {
        switch(v){
        case VqStencilOp::Keep:
            return "Keep";
        case VqStencilOp::Zero:
            return "Zero";
        case VqStencilOp::Replace:
            return "Replace";
        case VqStencilOp::IncrementAndClamp:
            return "IncrementAndClamp";
        case VqStencilOp::DecrementAndClamp:
            return "DecrementAndClamp";
        case VqStencilOp::Invert:
            return "Invert";
        case VqStencilOp::IncrementAndWrap:
            return "IncrementAndWrap";
        case VqStencilOp::DecrementAndWrap:
            return "DecrementAndWrap";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSubgroupFeatureFlagBits v)
    {
        switch(v){
        case VqSubgroupFeatureFlagBits::BasicBit:
            return "BasicBit";
        case VqSubgroupFeatureFlagBits::VoteBit:
            return "VoteBit";
        case VqSubgroupFeatureFlagBits::ArithmeticBit:
            return "ArithmeticBit";
        case VqSubgroupFeatureFlagBits::BallotBit:
            return "BallotBit";
        case VqSubgroupFeatureFlagBits::ShuffleBit:
            return "ShuffleBit";
        case VqSubgroupFeatureFlagBits::ShuffleRelativeBit:
            return "ShuffleRelativeBit";
        case VqSubgroupFeatureFlagBits::ClusteredBit:
            return "ClusteredBit";
        case VqSubgroupFeatureFlagBits::QuadBit:
            return "QuadBit";
        case VqSubgroupFeatureFlagBits::PartitionedBitNV:
            return "PartitionedBitNV";
        case VqSubgroupFeatureFlagBits::RotateBitKHR:
            return "RotateBitKHR";
        case VqSubgroupFeatureFlagBits::RotateClusteredBitKHR:
            return "RotateClusteredBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSubmitFlagBits v)
    {
        switch(v){
        case VqSubmitFlagBits::ProtectedBit:
            return "ProtectedBit";
        case VqSubmitFlagBits::ProtectedBitKHR:
            return "ProtectedBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSubpassContents v)
    {
        switch(v){
        case VqSubpassContents::Inline:
            return "Inline";
        case VqSubpassContents::SecondaryCommandBuffers:
            return "SecondaryCommandBuffers";
        case VqSubpassContents::InlineAndSecondaryCommandBuffersKHR:
            return "InlineAndSecondaryCommandBuffersKHR";
        case VqSubpassContents::InlineAndSecondaryCommandBuffersEXT:
            return "InlineAndSecondaryCommandBuffersEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSubpassDescriptionFlagBits v)
    {
        switch(v){
        case VqSubpassDescriptionFlagBits::PerViewAttributesBitNvx:
            return "PerViewAttributesBitNvx";
        case VqSubpassDescriptionFlagBits::PerViewPositionXOnlyBitNvx:
            return "PerViewPositionXOnlyBitNvx";
        case VqSubpassDescriptionFlagBits::FragmentRegionBitQCOM:
            return "FragmentRegionBitQCOM";
        case VqSubpassDescriptionFlagBits::ShaderResolveBitQCOM:
            return "ShaderResolveBitQCOM";
        case VqSubpassDescriptionFlagBits::RasterizationOrderAttachmentColorAccessBitEXT:
            return "RasterizationOrderAttachmentColorAccessBitEXT";
        case VqSubpassDescriptionFlagBits::RasterizationOrderAttachmentDepthAccessBitEXT:
            return "RasterizationOrderAttachmentDepthAccessBitEXT";
        case VqSubpassDescriptionFlagBits::RasterizationOrderAttachmentStencilAccessBitEXT:
            return "RasterizationOrderAttachmentStencilAccessBitEXT";
        case VqSubpassDescriptionFlagBits::EnableLegacyDitheringBitEXT:
            return "EnableLegacyDitheringBitEXT";
        case VqSubpassDescriptionFlagBits::RasterizationOrderAttachmentColorAccessBitArm:
            return "RasterizationOrderAttachmentColorAccessBitArm";
        case VqSubpassDescriptionFlagBits::RasterizationOrderAttachmentDepthAccessBitArm:
            return "RasterizationOrderAttachmentDepthAccessBitArm";
        case VqSubpassDescriptionFlagBits::RasterizationOrderAttachmentStencilAccessBitArm:
            return "RasterizationOrderAttachmentStencilAccessBitArm";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSubpassMergeStatus v)
    {
        switch(v){
        case VqSubpassMergeStatus::MergedEXT:
            return "MergedEXT";
        case VqSubpassMergeStatus::DisallowedEXT:
            return "DisallowedEXT";
        case VqSubpassMergeStatus::NotMergedSideEffectsEXT:
            return "NotMergedSideEffectsEXT";
        case VqSubpassMergeStatus::NotMergedSamplesMismatchEXT:
            return "NotMergedSamplesMismatchEXT";
        case VqSubpassMergeStatus::NotMergedViewsMismatchEXT:
            return "NotMergedViewsMismatchEXT";
        case VqSubpassMergeStatus::NotMergedAliasingEXT:
            return "NotMergedAliasingEXT";
        case VqSubpassMergeStatus::NotMergedDependenciesEXT:
            return "NotMergedDependenciesEXT";
        case VqSubpassMergeStatus::NotMergedIncompatibleInputAttachmentEXT:
            return "NotMergedIncompatibleInputAttachmentEXT";
        case VqSubpassMergeStatus::NotMergedTooManyAttachmentsEXT:
            return "NotMergedTooManyAttachmentsEXT";
        case VqSubpassMergeStatus::NotMergedInsufficientStorageEXT:
            return "NotMergedInsufficientStorageEXT";
        case VqSubpassMergeStatus::NotMergedDepthStencilCountEXT:
            return "NotMergedDepthStencilCountEXT";
        case VqSubpassMergeStatus::NotMergedResolveAttachmentReuseEXT:
            return "NotMergedResolveAttachmentReuseEXT";
        case VqSubpassMergeStatus::NotMergedSingleSubpassEXT:
            return "NotMergedSingleSubpassEXT";
        case VqSubpassMergeStatus::NotMergedUnspecifiedEXT:
            return "NotMergedUnspecifiedEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSurfaceCounterFlagBits v)
    {
        switch(v){
        case VqSurfaceCounterFlagBits::VblankBitEXT:
            return "VblankBitEXT";
        case VqSurfaceCounterFlagBits::VblankEXT:
            return "VblankEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSurfaceTransformFlagBits v)
    {
        switch(v){
        case VqSurfaceTransformFlagBits::IdentityBitKHR:
            return "IdentityBitKHR";
        case VqSurfaceTransformFlagBits::Rotate90BitKHR:
            return "Rotate90BitKHR";
        case VqSurfaceTransformFlagBits::Rotate180BitKHR:
            return "Rotate180BitKHR";
        case VqSurfaceTransformFlagBits::Rotate270BitKHR:
            return "Rotate270BitKHR";
        case VqSurfaceTransformFlagBits::HorizontalMirrorBitKHR:
            return "HorizontalMirrorBitKHR";
        case VqSurfaceTransformFlagBits::HorizontalMirrorRotate90BitKHR:
            return "HorizontalMirrorRotate90BitKHR";
        case VqSurfaceTransformFlagBits::HorizontalMirrorRotate180BitKHR:
            return "HorizontalMirrorRotate180BitKHR";
        case VqSurfaceTransformFlagBits::HorizontalMirrorRotate270BitKHR:
            return "HorizontalMirrorRotate270BitKHR";
        case VqSurfaceTransformFlagBits::InheritBitKHR:
            return "InheritBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSwapchainCreateFlagBits v)
    {
        switch(v){
        case VqSwapchainCreateFlagBits::SplitInstanceBindRegionsBitKHR:
            return "SplitInstanceBindRegionsBitKHR";
        case VqSwapchainCreateFlagBits::ProtectedBitKHR:
            return "ProtectedBitKHR";
        case VqSwapchainCreateFlagBits::MutableFormatBitKHR:
            return "MutableFormatBitKHR";
        case VqSwapchainCreateFlagBits::DeferredMemoryAllocationBitEXT:
            return "DeferredMemoryAllocationBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSystemAllocationScope v)
    {
        switch(v){
        case VqSystemAllocationScope::Command:
            return "Command";
        case VqSystemAllocationScope::Object:
            return "Object";
        case VqSystemAllocationScope::Cache:
            return "Cache";
        case VqSystemAllocationScope::Device:
            return "Device";
        case VqSystemAllocationScope::Instance:
            return "Instance";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqTessellationDomainOrigin v)
    {
        switch(v){
        case VqTessellationDomainOrigin::UpperLeft:
            return "UpperLeft";
        case VqTessellationDomainOrigin::LowerLeft:
            return "LowerLeft";
        case VqTessellationDomainOrigin::UpperLeftKHR:
            return "UpperLeftKHR";
        case VqTessellationDomainOrigin::LowerLeftKHR:
            return "LowerLeftKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqTimeDomain v)
    {
        switch(v){
        case VqTimeDomain::DeviceKHR:
            return "DeviceKHR";
        case VqTimeDomain::ClockMonotonicKHR:
            return "ClockMonotonicKHR";
        case VqTimeDomain::ClockMonotonicRawKHR:
            return "ClockMonotonicRawKHR";
        case VqTimeDomain::QueryPerformanceCounterKHR:
            return "QueryPerformanceCounterKHR";
        case VqTimeDomain::DeviceEXT:
            return "DeviceEXT";
        case VqTimeDomain::ClockMonotonicEXT:
            return "ClockMonotonicEXT";
        case VqTimeDomain::ClockMonotonicRawEXT:
            return "ClockMonotonicRawEXT";
        case VqTimeDomain::QueryPerformanceCounterEXT:
            return "QueryPerformanceCounterEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqToolPurposeFlagBits v)
    {
        switch(v){
        case VqToolPurposeFlagBits::ValidationBit:
            return "ValidationBit";
        case VqToolPurposeFlagBits::ProfilingBit:
            return "ProfilingBit";
        case VqToolPurposeFlagBits::TracingBit:
            return "TracingBit";
        case VqToolPurposeFlagBits::AdditionalFeaturesBit:
            return "AdditionalFeaturesBit";
        case VqToolPurposeFlagBits::ModifyingFeaturesBit:
            return "ModifyingFeaturesBit";
        case VqToolPurposeFlagBits::DebugReportingBitEXT:
            return "DebugReportingBitEXT";
        case VqToolPurposeFlagBits::DebugMarkersBitEXT:
            return "DebugMarkersBitEXT";
        case VqToolPurposeFlagBits::ValidationBitEXT:
            return "ValidationBitEXT";
        case VqToolPurposeFlagBits::ProfilingBitEXT:
            return "ProfilingBitEXT";
        case VqToolPurposeFlagBits::TracingBitEXT:
            return "TracingBitEXT";
        case VqToolPurposeFlagBits::AdditionalFeaturesBitEXT:
            return "AdditionalFeaturesBitEXT";
        case VqToolPurposeFlagBits::ModifyingFeaturesBitEXT:
            return "ModifyingFeaturesBitEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqValidationCacheHeaderVersion v)
    {
        switch(v){
        case VqValidationCacheHeaderVersion::OneEXT:
            return "OneEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqValidationCheck v)
    {
        switch(v){
        case VqValidationCheck::AllEXT:
            return "AllEXT";
        case VqValidationCheck::ShadersEXT:
            return "ShadersEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqValidationFeatureDisable v)
    {
        switch(v){
        case VqValidationFeatureDisable::AllEXT:
            return "AllEXT";
        case VqValidationFeatureDisable::ShadersEXT:
            return "ShadersEXT";
        case VqValidationFeatureDisable::ThreadSafetyEXT:
            return "ThreadSafetyEXT";
        case VqValidationFeatureDisable::ApiParametersEXT:
            return "ApiParametersEXT";
        case VqValidationFeatureDisable::ObjectLifetimesEXT:
            return "ObjectLifetimesEXT";
        case VqValidationFeatureDisable::CoreChecksEXT:
            return "CoreChecksEXT";
        case VqValidationFeatureDisable::UniqueHandlesEXT:
            return "UniqueHandlesEXT";
        case VqValidationFeatureDisable::ShaderValidationCacheEXT:
            return "ShaderValidationCacheEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqValidationFeatureEnable v)
    {
        switch(v){
        case VqValidationFeatureEnable::GpuAssistedEXT:
            return "GpuAssistedEXT";
        case VqValidationFeatureEnable::GpuAssistedReserveBindingSlotEXT:
            return "GpuAssistedReserveBindingSlotEXT";
        case VqValidationFeatureEnable::BestPracticesEXT:
            return "BestPracticesEXT";
        case VqValidationFeatureEnable::DebugPrintfEXT:
            return "DebugPrintfEXT";
        case VqValidationFeatureEnable::SynchronizationValidationEXT:
            return "SynchronizationValidationEXT";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVendorId v)
    {
        switch(v){
        case VqVendorId::Khronos:
            return "Khronos";
        case VqVendorId::Viv:
            return "Viv";
        case VqVendorId::Vsi:
            return "Vsi";
        case VqVendorId::Kazan:
            return "Kazan";
        case VqVendorId::Codeplay:
            return "Codeplay";
        case VqVendorId::Mesa:
            return "Mesa";
        case VqVendorId::Pocl:
            return "Pocl";
        case VqVendorId::Mobileye:
            return "Mobileye";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVertexInputRate v)
    {
        switch(v){
        case VqVertexInputRate::Vertex:
            return "Vertex";
        case VqVertexInputRate::Instance:
            return "Instance";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoCapabilityFlagBits v)
    {
        switch(v){
        case VqVideoCapabilityFlagBits::ProtectedContentBitKHR:
            return "ProtectedContentBitKHR";
        case VqVideoCapabilityFlagBits::SeparateReferenceImagesBitKHR:
            return "SeparateReferenceImagesBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoChromaSubsamplingFlagBits v)
    {
        switch(v){
        case VqVideoChromaSubsamplingFlagBits::InvalidKHR:
            return "InvalidKHR";
        case VqVideoChromaSubsamplingFlagBits::MonochromeBitKHR:
            return "MonochromeBitKHR";
        case VqVideoChromaSubsamplingFlagBits::420BitKHR:
            return "420BitKHR";
        case VqVideoChromaSubsamplingFlagBits::422BitKHR:
            return "422BitKHR";
        case VqVideoChromaSubsamplingFlagBits::444BitKHR:
            return "444BitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoCodecOperationFlagBits v)
    {
        switch(v){
        case VqVideoCodecOperationFlagBits::NoneKHR:
            return "NoneKHR";
        case VqVideoCodecOperationFlagBits::EncodeH264BitKHR:
            return "EncodeH264BitKHR";
        case VqVideoCodecOperationFlagBits::EncodeH265BitKHR:
            return "EncodeH265BitKHR";
        case VqVideoCodecOperationFlagBits::DecodeH264BitKHR:
            return "DecodeH264BitKHR";
        case VqVideoCodecOperationFlagBits::DecodeH265BitKHR:
            return "DecodeH265BitKHR";
        case VqVideoCodecOperationFlagBits::DecodeAv1BitKHR:
            return "DecodeAv1BitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoCodingControlFlagBits v)
    {
        switch(v){
        case VqVideoCodingControlFlagBits::ResetBitKHR:
            return "ResetBitKHR";
        case VqVideoCodingControlFlagBits::EncodeRateControlBitKHR:
            return "EncodeRateControlBitKHR";
        case VqVideoCodingControlFlagBits::EncodeQualityLevelBitKHR:
            return "EncodeQualityLevelBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoComponentBitDepthFlagBits v)
    {
        switch(v){
        case VqVideoComponentBitDepthFlagBits::InvalidKHR:
            return "InvalidKHR";
        case VqVideoComponentBitDepthFlagBits::8BitKHR:
            return "8BitKHR";
        case VqVideoComponentBitDepthFlagBits::10BitKHR:
            return "10BitKHR";
        case VqVideoComponentBitDepthFlagBits::12BitKHR:
            return "12BitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoDecodeCapabilityFlagBits v)
    {
        switch(v){
        case VqVideoDecodeCapabilityFlagBits::DpbAndOutputCoincideBitKHR:
            return "DpbAndOutputCoincideBitKHR";
        case VqVideoDecodeCapabilityFlagBits::DpbAndOutputDistinctBitKHR:
            return "DpbAndOutputDistinctBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoDecodeH264PictureLayoutFlagBits v)
    {
        switch(v){
        case VqVideoDecodeH264PictureLayoutFlagBits::ProgressiveKHR:
            return "ProgressiveKHR";
        case VqVideoDecodeH264PictureLayoutFlagBits::InterlacedInterleavedLinesBitKHR:
            return "InterlacedInterleavedLinesBitKHR";
        case VqVideoDecodeH264PictureLayoutFlagBits::InterlacedSeparatePlanesBitKHR:
            return "InterlacedSeparatePlanesBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoDecodeUsageFlagBits v)
    {
        switch(v){
        case VqVideoDecodeUsageFlagBits::DefaultKHR:
            return "DefaultKHR";
        case VqVideoDecodeUsageFlagBits::TranscodingBitKHR:
            return "TranscodingBitKHR";
        case VqVideoDecodeUsageFlagBits::OfflineBitKHR:
            return "OfflineBitKHR";
        case VqVideoDecodeUsageFlagBits::StreamingBitKHR:
            return "StreamingBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeCapabilityFlagBits v)
    {
        switch(v){
        case VqVideoEncodeCapabilityFlagBits::PrecedingExternallyEncodedBytesBitKHR:
            return "PrecedingExternallyEncodedBytesBitKHR";
        case VqVideoEncodeCapabilityFlagBits::InsufficientBitstreamBufferRangeDetectionBitKHR:
            return "InsufficientBitstreamBufferRangeDetectionBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeContentFlagBits v)
    {
        switch(v){
        case VqVideoEncodeContentFlagBits::DefaultKHR:
            return "DefaultKHR";
        case VqVideoEncodeContentFlagBits::CameraBitKHR:
            return "CameraBitKHR";
        case VqVideoEncodeContentFlagBits::DesktopBitKHR:
            return "DesktopBitKHR";
        case VqVideoEncodeContentFlagBits::RenderedBitKHR:
            return "RenderedBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeFeedbackFlagBits v)
    {
        switch(v){
        case VqVideoEncodeFeedbackFlagBits::BitstreamBufferOffsetBitKHR:
            return "BitstreamBufferOffsetBitKHR";
        case VqVideoEncodeFeedbackFlagBits::BitstreamBytesWrittenBitKHR:
            return "BitstreamBytesWrittenBitKHR";
        case VqVideoEncodeFeedbackFlagBits::BitstreamHasOverridesBitKHR:
            return "BitstreamHasOverridesBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeFlagBits v)
    {
        switch(v){
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeH264CapabilityFlagBits v)
    {
        switch(v){
        case VqVideoEncodeH264CapabilityFlagBits::HrdComplianceBitKHR:
            return "HrdComplianceBitKHR";
        case VqVideoEncodeH264CapabilityFlagBits::PredictionWeightTableGeneratedBitKHR:
            return "PredictionWeightTableGeneratedBitKHR";
        case VqVideoEncodeH264CapabilityFlagBits::RowUnalignedSliceBitKHR:
            return "RowUnalignedSliceBitKHR";
        case VqVideoEncodeH264CapabilityFlagBits::DifferentSliceTypeBitKHR:
            return "DifferentSliceTypeBitKHR";
        case VqVideoEncodeH264CapabilityFlagBits::BFrameInL0ListBitKHR:
            return "BFrameInL0ListBitKHR";
        case VqVideoEncodeH264CapabilityFlagBits::BFrameInL1ListBitKHR:
            return "BFrameInL1ListBitKHR";
        case VqVideoEncodeH264CapabilityFlagBits::PerPictureTypeMinMaxQpBitKHR:
            return "PerPictureTypeMinMaxQpBitKHR";
        case VqVideoEncodeH264CapabilityFlagBits::PerSliceConstantQpBitKHR:
            return "PerSliceConstantQpBitKHR";
        case VqVideoEncodeH264CapabilityFlagBits::GeneratePrefixNaluBitKHR:
            return "GeneratePrefixNaluBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeH264RateControlFlagBits v)
    {
        switch(v){
        case VqVideoEncodeH264RateControlFlagBits::AttemptHrdComplianceBitKHR:
            return "AttemptHrdComplianceBitKHR";
        case VqVideoEncodeH264RateControlFlagBits::RegularGopBitKHR:
            return "RegularGopBitKHR";
        case VqVideoEncodeH264RateControlFlagBits::ReferencePatternFlatBitKHR:
            return "ReferencePatternFlatBitKHR";
        case VqVideoEncodeH264RateControlFlagBits::ReferencePatternDyadicBitKHR:
            return "ReferencePatternDyadicBitKHR";
        case VqVideoEncodeH264RateControlFlagBits::TemporalLayerPatternDyadicBitKHR:
            return "TemporalLayerPatternDyadicBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeH264StdFlagBits v)
    {
        switch(v){
        case VqVideoEncodeH264StdFlagBits::SeparateColorPlaneFlagSetBitKHR:
            return "SeparateColorPlaneFlagSetBitKHR";
        case VqVideoEncodeH264StdFlagBits::QpprimeYZeroTransformBypassFlagSetBitKHR:
            return "QpprimeYZeroTransformBypassFlagSetBitKHR";
        case VqVideoEncodeH264StdFlagBits::ScalingMatrixPresentFlagSetBitKHR:
            return "ScalingMatrixPresentFlagSetBitKHR";
        case VqVideoEncodeH264StdFlagBits::ChromaQpIndexOffsetBitKHR:
            return "ChromaQpIndexOffsetBitKHR";
        case VqVideoEncodeH264StdFlagBits::SecondChromaQpIndexOffsetBitKHR:
            return "SecondChromaQpIndexOffsetBitKHR";
        case VqVideoEncodeH264StdFlagBits::PicInitQpMinus26BitKHR:
            return "PicInitQpMinus26BitKHR";
        case VqVideoEncodeH264StdFlagBits::WeightedPredFlagSetBitKHR:
            return "WeightedPredFlagSetBitKHR";
        case VqVideoEncodeH264StdFlagBits::WeightedBipredIdcExplicitBitKHR:
            return "WeightedBipredIdcExplicitBitKHR";
        case VqVideoEncodeH264StdFlagBits::WeightedBipredIdcImplicitBitKHR:
            return "WeightedBipredIdcImplicitBitKHR";
        case VqVideoEncodeH264StdFlagBits::Transform8x8ModeFlagSetBitKHR:
            return "Transform8x8ModeFlagSetBitKHR";
        case VqVideoEncodeH264StdFlagBits::DirectSpatialMvPredFlagUnsetBitKHR:
            return "DirectSpatialMvPredFlagUnsetBitKHR";
        case VqVideoEncodeH264StdFlagBits::EntropyCodingModeFlagUnsetBitKHR:
            return "EntropyCodingModeFlagUnsetBitKHR";
        case VqVideoEncodeH264StdFlagBits::EntropyCodingModeFlagSetBitKHR:
            return "EntropyCodingModeFlagSetBitKHR";
        case VqVideoEncodeH264StdFlagBits::Direct8x8InferenceFlagUnsetBitKHR:
            return "Direct8x8InferenceFlagUnsetBitKHR";
        case VqVideoEncodeH264StdFlagBits::ConstrainedIntraPredFlagSetBitKHR:
            return "ConstrainedIntraPredFlagSetBitKHR";
        case VqVideoEncodeH264StdFlagBits::DeblockingFilterDisabledBitKHR:
            return "DeblockingFilterDisabledBitKHR";
        case VqVideoEncodeH264StdFlagBits::DeblockingFilterEnabledBitKHR:
            return "DeblockingFilterEnabledBitKHR";
        case VqVideoEncodeH264StdFlagBits::DeblockingFilterPartialBitKHR:
            return "DeblockingFilterPartialBitKHR";
        case VqVideoEncodeH264StdFlagBits::SliceQpDeltaBitKHR:
            return "SliceQpDeltaBitKHR";
        case VqVideoEncodeH264StdFlagBits::DifferentSliceQpDeltaBitKHR:
            return "DifferentSliceQpDeltaBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeH265CapabilityFlagBits v)
    {
        switch(v){
        case VqVideoEncodeH265CapabilityFlagBits::HrdComplianceBitKHR:
            return "HrdComplianceBitKHR";
        case VqVideoEncodeH265CapabilityFlagBits::PredictionWeightTableGeneratedBitKHR:
            return "PredictionWeightTableGeneratedBitKHR";
        case VqVideoEncodeH265CapabilityFlagBits::RowUnalignedSliceSegmentBitKHR:
            return "RowUnalignedSliceSegmentBitKHR";
        case VqVideoEncodeH265CapabilityFlagBits::DifferentSliceSegmentTypeBitKHR:
            return "DifferentSliceSegmentTypeBitKHR";
        case VqVideoEncodeH265CapabilityFlagBits::BFrameInL0ListBitKHR:
            return "BFrameInL0ListBitKHR";
        case VqVideoEncodeH265CapabilityFlagBits::BFrameInL1ListBitKHR:
            return "BFrameInL1ListBitKHR";
        case VqVideoEncodeH265CapabilityFlagBits::PerPictureTypeMinMaxQpBitKHR:
            return "PerPictureTypeMinMaxQpBitKHR";
        case VqVideoEncodeH265CapabilityFlagBits::PerSliceSegmentConstantQpBitKHR:
            return "PerSliceSegmentConstantQpBitKHR";
        case VqVideoEncodeH265CapabilityFlagBits::MultipleTilesPerSliceSegmentBitKHR:
            return "MultipleTilesPerSliceSegmentBitKHR";
        case VqVideoEncodeH265CapabilityFlagBits::MultipleSliceSegmentsPerTileBitKHR:
            return "MultipleSliceSegmentsPerTileBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeH265CtbSizeFlagBits v)
    {
        switch(v){
        case VqVideoEncodeH265CtbSizeFlagBits::16BitKHR:
            return "16BitKHR";
        case VqVideoEncodeH265CtbSizeFlagBits::32BitKHR:
            return "32BitKHR";
        case VqVideoEncodeH265CtbSizeFlagBits::64BitKHR:
            return "64BitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeH265RateControlFlagBits v)
    {
        switch(v){
        case VqVideoEncodeH265RateControlFlagBits::AttemptHrdComplianceBitKHR:
            return "AttemptHrdComplianceBitKHR";
        case VqVideoEncodeH265RateControlFlagBits::RegularGopBitKHR:
            return "RegularGopBitKHR";
        case VqVideoEncodeH265RateControlFlagBits::ReferencePatternFlatBitKHR:
            return "ReferencePatternFlatBitKHR";
        case VqVideoEncodeH265RateControlFlagBits::ReferencePatternDyadicBitKHR:
            return "ReferencePatternDyadicBitKHR";
        case VqVideoEncodeH265RateControlFlagBits::TemporalSubLayerPatternDyadicBitKHR:
            return "TemporalSubLayerPatternDyadicBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeH265StdFlagBits v)
    {
        switch(v){
        case VqVideoEncodeH265StdFlagBits::SeparateColorPlaneFlagSetBitKHR:
            return "SeparateColorPlaneFlagSetBitKHR";
        case VqVideoEncodeH265StdFlagBits::SampleAdaptiveOffsetEnabledFlagSetBitKHR:
            return "SampleAdaptiveOffsetEnabledFlagSetBitKHR";
        case VqVideoEncodeH265StdFlagBits::ScalingListDataPresentFlagSetBitKHR:
            return "ScalingListDataPresentFlagSetBitKHR";
        case VqVideoEncodeH265StdFlagBits::PcmEnabledFlagSetBitKHR:
            return "PcmEnabledFlagSetBitKHR";
        case VqVideoEncodeH265StdFlagBits::SpsTemporalMvpEnabledFlagSetBitKHR:
            return "SpsTemporalMvpEnabledFlagSetBitKHR";
        case VqVideoEncodeH265StdFlagBits::InitQpMinus26BitKHR:
            return "InitQpMinus26BitKHR";
        case VqVideoEncodeH265StdFlagBits::WeightedPredFlagSetBitKHR:
            return "WeightedPredFlagSetBitKHR";
        case VqVideoEncodeH265StdFlagBits::WeightedBipredFlagSetBitKHR:
            return "WeightedBipredFlagSetBitKHR";
        case VqVideoEncodeH265StdFlagBits::Log2ParallelMergeLevelMinus2BitKHR:
            return "Log2ParallelMergeLevelMinus2BitKHR";
        case VqVideoEncodeH265StdFlagBits::SignDataHidingEnabledFlagSetBitKHR:
            return "SignDataHidingEnabledFlagSetBitKHR";
        case VqVideoEncodeH265StdFlagBits::TransformSkipEnabledFlagSetBitKHR:
            return "TransformSkipEnabledFlagSetBitKHR";
        case VqVideoEncodeH265StdFlagBits::TransformSkipEnabledFlagUnsetBitKHR:
            return "TransformSkipEnabledFlagUnsetBitKHR";
        case VqVideoEncodeH265StdFlagBits::PpsSliceChromaQpOffsetsPresentFlagSetBitKHR:
            return "PpsSliceChromaQpOffsetsPresentFlagSetBitKHR";
        case VqVideoEncodeH265StdFlagBits::TransquantBypassEnabledFlagSetBitKHR:
            return "TransquantBypassEnabledFlagSetBitKHR";
        case VqVideoEncodeH265StdFlagBits::ConstrainedIntraPredFlagSetBitKHR:
            return "ConstrainedIntraPredFlagSetBitKHR";
        case VqVideoEncodeH265StdFlagBits::EntropyCodingSyncEnabledFlagSetBitKHR:
            return "EntropyCodingSyncEnabledFlagSetBitKHR";
        case VqVideoEncodeH265StdFlagBits::DeblockingFilterOverrideEnabledFlagSetBitKHR:
            return "DeblockingFilterOverrideEnabledFlagSetBitKHR";
        case VqVideoEncodeH265StdFlagBits::DependentSliceSegmentsEnabledFlagSetBitKHR:
            return "DependentSliceSegmentsEnabledFlagSetBitKHR";
        case VqVideoEncodeH265StdFlagBits::DependentSliceSegmentFlagSetBitKHR:
            return "DependentSliceSegmentFlagSetBitKHR";
        case VqVideoEncodeH265StdFlagBits::SliceQpDeltaBitKHR:
            return "SliceQpDeltaBitKHR";
        case VqVideoEncodeH265StdFlagBits::DifferentSliceQpDeltaBitKHR:
            return "DifferentSliceQpDeltaBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeH265TransformBlockSizeFlagBits v)
    {
        switch(v){
        case VqVideoEncodeH265TransformBlockSizeFlagBits::4BitKHR:
            return "4BitKHR";
        case VqVideoEncodeH265TransformBlockSizeFlagBits::8BitKHR:
            return "8BitKHR";
        case VqVideoEncodeH265TransformBlockSizeFlagBits::16BitKHR:
            return "16BitKHR";
        case VqVideoEncodeH265TransformBlockSizeFlagBits::32BitKHR:
            return "32BitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeRateControlModeFlagBits v)
    {
        switch(v){
        case VqVideoEncodeRateControlModeFlagBits::DefaultKHR:
            return "DefaultKHR";
        case VqVideoEncodeRateControlModeFlagBits::DisabledBitKHR:
            return "DisabledBitKHR";
        case VqVideoEncodeRateControlModeFlagBits::CbrBitKHR:
            return "CbrBitKHR";
        case VqVideoEncodeRateControlModeFlagBits::VbrBitKHR:
            return "VbrBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeTuningMode v)
    {
        switch(v){
        case VqVideoEncodeTuningMode::DefaultKHR:
            return "DefaultKHR";
        case VqVideoEncodeTuningMode::HighQualityKHR:
            return "HighQualityKHR";
        case VqVideoEncodeTuningMode::LowLatencyKHR:
            return "LowLatencyKHR";
        case VqVideoEncodeTuningMode::UltraLowLatencyKHR:
            return "UltraLowLatencyKHR";
        case VqVideoEncodeTuningMode::LosslessKHR:
            return "LosslessKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeUsageFlagBits v)
    {
        switch(v){
        case VqVideoEncodeUsageFlagBits::DefaultKHR:
            return "DefaultKHR";
        case VqVideoEncodeUsageFlagBits::TranscodingBitKHR:
            return "TranscodingBitKHR";
        case VqVideoEncodeUsageFlagBits::StreamingBitKHR:
            return "StreamingBitKHR";
        case VqVideoEncodeUsageFlagBits::RecordingBitKHR:
            return "RecordingBitKHR";
        case VqVideoEncodeUsageFlagBits::ConferencingBitKHR:
            return "ConferencingBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoSessionCreateFlagBits v)
    {
        switch(v){
        case VqVideoSessionCreateFlagBits::ProtectedContentBitKHR:
            return "ProtectedContentBitKHR";
        case VqVideoSessionCreateFlagBits::AllowEncodeParameterOptimizationsBitKHR:
            return "AllowEncodeParameterOptimizationsBitKHR";
        case VqVideoSessionCreateFlagBits::InlineQueriesBitKHR:
            return "InlineQueriesBitKHR";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqViewportCoordinateSwizzle v)
    {
        switch(v){
        case VqViewportCoordinateSwizzle::PositiveXNV:
            return "PositiveXNV";
        case VqViewportCoordinateSwizzle::NegativeXNV:
            return "NegativeXNV";
        case VqViewportCoordinateSwizzle::PositiveYNV:
            return "PositiveYNV";
        case VqViewportCoordinateSwizzle::NegativeYNV:
            return "NegativeYNV";
        case VqViewportCoordinateSwizzle::PositiveZNV:
            return "PositiveZNV";
        case VqViewportCoordinateSwizzle::NegativeZNV:
            return "NegativeZNV";
        case VqViewportCoordinateSwizzle::PositiveWNV:
            return "PositiveWNV";
        case VqViewportCoordinateSwizzle::NegativeWNV:
            return "NegativeWNV";
        default:
            return szUnknown;
        }
    }

}
