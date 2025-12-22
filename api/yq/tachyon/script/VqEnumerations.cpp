////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

//  WARNING!  WARNING!  WARNNG!  WARNING!
//  This header file is AUTO-GENERATED, changes will be CLOBBERED

#include "VqEnumerations.hpp"

namespace yq::tachyon {

    static const std::string_view szUnknown   = "(unknown)";

    std::string_view    to_string_view(VqAccelerationStructureBuildType v)
    {
        switch(v){
        case VqAccelerationStructureBuildType::Host:
            return "Host";
        case VqAccelerationStructureBuildType::Device:
            return "Device";
        case VqAccelerationStructureBuildType::HostOrDevice:
            return "HostOrDevice";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqAccelerationStructureCompatibility v)
    {
        switch(v){
        case VqAccelerationStructureCompatibility::Compatible:
            return "Compatible";
        case VqAccelerationStructureCompatibility::Incompatible:
            return "Incompatible";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqAccelerationStructureCreateBit v)
    {
        switch(v){
        case VqAccelerationStructureCreateBit::DeviceAddressCaptureReplay:
            return "DeviceAddressCaptureReplay";
        case VqAccelerationStructureCreateBit::DescriptorBufferCaptureReplay:
            return "DescriptorBufferCaptureReplay";
        case VqAccelerationStructureCreateBit::Motion:
            return "Motion";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqAccelerationStructureMemoryRequirementsType v)
    {
        switch(v){
        case VqAccelerationStructureMemoryRequirementsType::Object:
            return "Object";
        case VqAccelerationStructureMemoryRequirementsType::BuildScratch:
            return "BuildScratch";
        case VqAccelerationStructureMemoryRequirementsType::UpdateScratch:
            return "UpdateScratch";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqAccelerationStructureMotionInstanceType v)
    {
        switch(v){
        case VqAccelerationStructureMotionInstanceType::Static:
            return "Static";
        case VqAccelerationStructureMotionInstanceType::MatrixMotion:
            return "MatrixMotion";
        case VqAccelerationStructureMotionInstanceType::SrtMotion:
            return "SrtMotion";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqAccelerationStructureType v)
    {
        switch(v){
        case VqAccelerationStructureType::TopLevel:
            return "TopLevel";
        case VqAccelerationStructureType::BottomLevel:
            return "BottomLevel";
        case VqAccelerationStructureType::Generic:
            return "Generic";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqAccessBit v)
    {
        switch(v){
        case VqAccessBit::IndirectCommandRead:
            return "IndirectCommandRead";
        case VqAccessBit::IndexRead:
            return "IndexRead";
        case VqAccessBit::VertexAttributeRead:
            return "VertexAttributeRead";
        case VqAccessBit::UniformRead:
            return "UniformRead";
        case VqAccessBit::InputAttachmentRead:
            return "InputAttachmentRead";
        case VqAccessBit::ShaderRead:
            return "ShaderRead";
        case VqAccessBit::ShaderWrite:
            return "ShaderWrite";
        case VqAccessBit::ColorAttachmentRead:
            return "ColorAttachmentRead";
        case VqAccessBit::ColorAttachmentWrite:
            return "ColorAttachmentWrite";
        case VqAccessBit::DepthStencilAttachmentRead:
            return "DepthStencilAttachmentRead";
        case VqAccessBit::DepthStencilAttachmentWrite:
            return "DepthStencilAttachmentWrite";
        case VqAccessBit::TransferRead:
            return "TransferRead";
        case VqAccessBit::TransferWrite:
            return "TransferWrite";
        case VqAccessBit::HostRead:
            return "HostRead";
        case VqAccessBit::HostWrite:
            return "HostWrite";
        case VqAccessBit::MemoryRead:
            return "MemoryRead";
        case VqAccessBit::MemoryWrite:
            return "MemoryWrite";
        case VqAccessBit::TransformFeedbackWrite:
            return "TransformFeedbackWrite";
        case VqAccessBit::TransformFeedbackCounterRead:
            return "TransformFeedbackCounterRead";
        case VqAccessBit::TransformFeedbackCounterWrite:
            return "TransformFeedbackCounterWrite";
        case VqAccessBit::ConditionalRenderingRead:
            return "ConditionalRenderingRead";
        case VqAccessBit::ColorAttachmentReadNoncoherent:
            return "ColorAttachmentReadNoncoherent";
        case VqAccessBit::AccelerationStructureRead:
            return "AccelerationStructureRead";
        case VqAccessBit::AccelerationStructureWrite:
            return "AccelerationStructureWrite";
        case VqAccessBit::FragmentDensityMapRead:
            return "FragmentDensityMapRead";
        case VqAccessBit::FragmentShadingRateAttachmentRead:
            return "FragmentShadingRateAttachmentRead";
        case VqAccessBit::CommandPreprocessRead:
            return "CommandPreprocessRead";
        case VqAccessBit::CommandPreprocessWrite:
            return "CommandPreprocessWrite";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqAcquireProfilingLockBit v)
    {
        switch(v){
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqAddressCopyBit v)
    {
        switch(v){
        case VqAddressCopyBit::DeviceLocal:
            return "DeviceLocal";
        case VqAddressCopyBit::Sparse:
            return "Sparse";
        case VqAddressCopyBit::Protected:
            return "Protected";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqAntiLagMode v)
    {
        switch(v){
        case VqAntiLagMode::DriverControlAMD:
            return "DriverControlAMD";
        case VqAntiLagMode::OnAMD:
            return "OnAMD";
        case VqAntiLagMode::OffAMD:
            return "OffAMD";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqAntiLagStage v)
    {
        switch(v){
        case VqAntiLagStage::InputAMD:
            return "InputAMD";
        case VqAntiLagStage::PresentAMD:
            return "PresentAMD";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqAttachmentDescriptionBit v)
    {
        switch(v){
        case VqAttachmentDescriptionBit::MayAlias:
            return "MayAlias";
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
        case VqAttachmentLoadOp::None:
            return "None";
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
        case VqBlendOp::Zero:
            return "Zero";
        case VqBlendOp::Src:
            return "Src";
        case VqBlendOp::Dst:
            return "Dst";
        case VqBlendOp::SrcOver:
            return "SrcOver";
        case VqBlendOp::DstOver:
            return "DstOver";
        case VqBlendOp::SrcIn:
            return "SrcIn";
        case VqBlendOp::DstIn:
            return "DstIn";
        case VqBlendOp::SrcOut:
            return "SrcOut";
        case VqBlendOp::DstOut:
            return "DstOut";
        case VqBlendOp::SrcAtop:
            return "SrcAtop";
        case VqBlendOp::DstAtop:
            return "DstAtop";
        case VqBlendOp::Xor:
            return "Xor";
        case VqBlendOp::Multiply:
            return "Multiply";
        case VqBlendOp::Screen:
            return "Screen";
        case VqBlendOp::Overlay:
            return "Overlay";
        case VqBlendOp::Darken:
            return "Darken";
        case VqBlendOp::Lighten:
            return "Lighten";
        case VqBlendOp::Colordodge:
            return "Colordodge";
        case VqBlendOp::Colorburn:
            return "Colorburn";
        case VqBlendOp::Hardlight:
            return "Hardlight";
        case VqBlendOp::Softlight:
            return "Softlight";
        case VqBlendOp::Difference:
            return "Difference";
        case VqBlendOp::Exclusion:
            return "Exclusion";
        case VqBlendOp::Invert:
            return "Invert";
        case VqBlendOp::InvertRgb:
            return "InvertRgb";
        case VqBlendOp::Lineardodge:
            return "Lineardodge";
        case VqBlendOp::Linearburn:
            return "Linearburn";
        case VqBlendOp::Vividlight:
            return "Vividlight";
        case VqBlendOp::Linearlight:
            return "Linearlight";
        case VqBlendOp::Pinlight:
            return "Pinlight";
        case VqBlendOp::Hardmix:
            return "Hardmix";
        case VqBlendOp::HslHue:
            return "HslHue";
        case VqBlendOp::HslSaturation:
            return "HslSaturation";
        case VqBlendOp::HslColor:
            return "HslColor";
        case VqBlendOp::HslLuminosity:
            return "HslLuminosity";
        case VqBlendOp::Plus:
            return "Plus";
        case VqBlendOp::PlusClamped:
            return "PlusClamped";
        case VqBlendOp::PlusClampedAlpha:
            return "PlusClampedAlpha";
        case VqBlendOp::PlusDarker:
            return "PlusDarker";
        case VqBlendOp::Minus:
            return "Minus";
        case VqBlendOp::MinusClamped:
            return "MinusClamped";
        case VqBlendOp::Contrast:
            return "Contrast";
        case VqBlendOp::InvertOvg:
            return "InvertOvg";
        case VqBlendOp::Red:
            return "Red";
        case VqBlendOp::Green:
            return "Green";
        case VqBlendOp::Blue:
            return "Blue";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqBlendOverlap v)
    {
        switch(v){
        case VqBlendOverlap::Uncorrelated:
            return "Uncorrelated";
        case VqBlendOverlap::Disjoint:
            return "Disjoint";
        case VqBlendOverlap::Conjoint:
            return "Conjoint";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqBlockMatchWindowCompareMode v)
    {
        switch(v){
        case VqBlockMatchWindowCompareMode::Min:
            return "Min";
        case VqBlockMatchWindowCompareMode::Max:
            return "Max";
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
        case VqBorderColor::FloatCustom:
            return "FloatCustom";
        case VqBorderColor::IntCustom:
            return "IntCustom";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqBufferCreateBit v)
    {
        switch(v){
        case VqBufferCreateBit::SparseBinding:
            return "SparseBinding";
        case VqBufferCreateBit::SparseResidency:
            return "SparseResidency";
        case VqBufferCreateBit::SparseAliased:
            return "SparseAliased";
        case VqBufferCreateBit::Protected:
            return "Protected";
        case VqBufferCreateBit::DeviceAddressCaptureReplay:
            return "DeviceAddressCaptureReplay";
        case VqBufferCreateBit::DescriptorBufferCaptureReplay:
            return "DescriptorBufferCaptureReplay";
        case VqBufferCreateBit::VideoProfileIndependent:
            return "VideoProfileIndependent";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqBufferUsageBit v)
    {
        switch(v){
        case VqBufferUsageBit::TransferSrc:
            return "TransferSrc";
        case VqBufferUsageBit::TransferDst:
            return "TransferDst";
        case VqBufferUsageBit::UniformTexelBuffer:
            return "UniformTexelBuffer";
        case VqBufferUsageBit::StorageTexelBuffer:
            return "StorageTexelBuffer";
        case VqBufferUsageBit::UniformBuffer:
            return "UniformBuffer";
        case VqBufferUsageBit::StorageBuffer:
            return "StorageBuffer";
        case VqBufferUsageBit::IndexBuffer:
            return "IndexBuffer";
        case VqBufferUsageBit::VertexBuffer:
            return "VertexBuffer";
        case VqBufferUsageBit::IndirectBuffer:
            return "IndirectBuffer";
        case VqBufferUsageBit::ShaderDeviceAddress:
            return "ShaderDeviceAddress";
        case VqBufferUsageBit::VideoDecodeSrc:
            return "VideoDecodeSrc";
        case VqBufferUsageBit::VideoDecodeDst:
            return "VideoDecodeDst";
        case VqBufferUsageBit::TransformFeedbackBuffer:
            return "TransformFeedbackBuffer";
        case VqBufferUsageBit::TransformFeedbackCounterBuffer:
            return "TransformFeedbackCounterBuffer";
        case VqBufferUsageBit::ConditionalRendering:
            return "ConditionalRendering";
        case VqBufferUsageBit::ExecutionGraphScratchBitAmdx:
            return "ExecutionGraphScratchBitAmdx";
        case VqBufferUsageBit::AccelerationStructureBuildInputReadOnly:
            return "AccelerationStructureBuildInputReadOnly";
        case VqBufferUsageBit::AccelerationStructureStorage:
            return "AccelerationStructureStorage";
        case VqBufferUsageBit::ShaderBindingTable:
            return "ShaderBindingTable";
        case VqBufferUsageBit::VideoEncodeDst:
            return "VideoEncodeDst";
        case VqBufferUsageBit::VideoEncodeSrc:
            return "VideoEncodeSrc";
        case VqBufferUsageBit::SamplerDescriptorBuffer:
            return "SamplerDescriptorBuffer";
        case VqBufferUsageBit::ResourceDescriptorBuffer:
            return "ResourceDescriptorBuffer";
        case VqBufferUsageBit::PushDescriptorsDescriptorBuffer:
            return "PushDescriptorsDescriptorBuffer";
        case VqBufferUsageBit::MicromapBuildInputReadOnly:
            return "MicromapBuildInputReadOnly";
        case VqBufferUsageBit::MicromapStorage:
            return "MicromapStorage";
        case VqBufferUsageBit::TileMemory:
            return "TileMemory";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqBuildAccelerationStructureBit v)
    {
        switch(v){
        case VqBuildAccelerationStructureBit::AllowUpdate:
            return "AllowUpdate";
        case VqBuildAccelerationStructureBit::AllowCompaction:
            return "AllowCompaction";
        case VqBuildAccelerationStructureBit::PreferFastTrace:
            return "PreferFastTrace";
        case VqBuildAccelerationStructureBit::PreferFastBuild:
            return "PreferFastBuild";
        case VqBuildAccelerationStructureBit::LowMemory:
            return "LowMemory";
        case VqBuildAccelerationStructureBit::Motion:
            return "Motion";
        case VqBuildAccelerationStructureBit::AllowOpacityMicromapUpdate:
            return "AllowOpacityMicromapUpdate";
        case VqBuildAccelerationStructureBit::AllowDisableOpacityMicromaps:
            return "AllowDisableOpacityMicromaps";
        case VqBuildAccelerationStructureBit::AllowOpacityMicromapDataUpdate:
            return "AllowOpacityMicromapDataUpdate";
        case VqBuildAccelerationStructureBit::AllowDisplacementMicromapUpdate:
            return "AllowDisplacementMicromapUpdate";
        case VqBuildAccelerationStructureBit::AllowDataAccess:
            return "AllowDataAccess";
        case VqBuildAccelerationStructureBit::AllowClusterOpacityMicromaps:
            return "AllowClusterOpacityMicromaps";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqBuildAccelerationStructureMode v)
    {
        switch(v){
        case VqBuildAccelerationStructureMode::Build:
            return "Build";
        case VqBuildAccelerationStructureMode::Update:
            return "Update";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqBuildMicromapBit v)
    {
        switch(v){
        case VqBuildMicromapBit::PreferFastTrace:
            return "PreferFastTrace";
        case VqBuildMicromapBit::PreferFastBuild:
            return "PreferFastBuild";
        case VqBuildMicromapBit::AllowCompaction:
            return "AllowCompaction";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqBuildMicromapMode v)
    {
        switch(v){
        case VqBuildMicromapMode::Build:
            return "Build";
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
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqClusterAccelerationStructureAddressResolutionBit v)
    {
        switch(v){
        case VqClusterAccelerationStructureAddressResolutionBit::IndirectedDstImplicitData:
            return "IndirectedDstImplicitData";
        case VqClusterAccelerationStructureAddressResolutionBit::IndirectedScratchData:
            return "IndirectedScratchData";
        case VqClusterAccelerationStructureAddressResolutionBit::IndirectedDstAddressArray:
            return "IndirectedDstAddressArray";
        case VqClusterAccelerationStructureAddressResolutionBit::IndirectedDstSizesArray:
            return "IndirectedDstSizesArray";
        case VqClusterAccelerationStructureAddressResolutionBit::IndirectedSrcInfosArray:
            return "IndirectedSrcInfosArray";
        case VqClusterAccelerationStructureAddressResolutionBit::IndirectedSrcInfosCount:
            return "IndirectedSrcInfosCount";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqClusterAccelerationStructureClusterBit v)
    {
        switch(v){
        case VqClusterAccelerationStructureClusterBit::AllowDisableOpacityMicromaps:
            return "AllowDisableOpacityMicromaps";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqClusterAccelerationStructureGeometryBit v)
    {
        switch(v){
        case VqClusterAccelerationStructureGeometryBit::CullDisable:
            return "CullDisable";
        case VqClusterAccelerationStructureGeometryBit::NoDuplicateAnyhitInvocation:
            return "NoDuplicateAnyhitInvocation";
        case VqClusterAccelerationStructureGeometryBit::Opaque:
            return "Opaque";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqClusterAccelerationStructureIndexFormatBit v)
    {
        switch(v){
        case VqClusterAccelerationStructureIndexFormatBit::_8bit:
            return "_8bit";
        case VqClusterAccelerationStructureIndexFormatBit::_16bit:
            return "_16bit";
        case VqClusterAccelerationStructureIndexFormatBit::_32bit:
            return "_32bit";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqClusterAccelerationStructureOpMode v)
    {
        switch(v){
        case VqClusterAccelerationStructureOpMode::ImplicitDestinations:
            return "ImplicitDestinations";
        case VqClusterAccelerationStructureOpMode::ExplicitDestinations:
            return "ExplicitDestinations";
        case VqClusterAccelerationStructureOpMode::ComputeSizes:
            return "ComputeSizes";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqClusterAccelerationStructureOpType v)
    {
        switch(v){
        case VqClusterAccelerationStructureOpType::MoveObjects:
            return "MoveObjects";
        case VqClusterAccelerationStructureOpType::BuildClustersBottomLevel:
            return "BuildClustersBottomLevel";
        case VqClusterAccelerationStructureOpType::BuildTriangleCluster:
            return "BuildTriangleCluster";
        case VqClusterAccelerationStructureOpType::BuildTriangleClusterTemplate:
            return "BuildTriangleClusterTemplate";
        case VqClusterAccelerationStructureOpType::InstantiateTriangleCluster:
            return "InstantiateTriangleCluster";
        case VqClusterAccelerationStructureOpType::GetClusterTemplateIndices:
            return "GetClusterTemplateIndices";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqClusterAccelerationStructureType v)
    {
        switch(v){
        case VqClusterAccelerationStructureType::ClustersBottomLevel:
            return "ClustersBottomLevel";
        case VqClusterAccelerationStructureType::TriangleCluster:
            return "TriangleCluster";
        case VqClusterAccelerationStructureType::TriangleClusterTemplate:
            return "TriangleClusterTemplate";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCoarseSampleOrderType v)
    {
        switch(v){
        case VqCoarseSampleOrderType::Default:
            return "Default";
        case VqCoarseSampleOrderType::Custom:
            return "Custom";
        case VqCoarseSampleOrderType::PixelMajor:
            return "PixelMajor";
        case VqCoarseSampleOrderType::SampleMajor:
            return "SampleMajor";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqColorComponentBit v)
    {
        switch(v){
        case VqColorComponentBit::R:
            return "R";
        case VqColorComponentBit::G:
            return "G";
        case VqColorComponentBit::B:
            return "B";
        case VqColorComponentBit::A:
            return "A";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqColorSpace v)
    {
        switch(v){
        case VqColorSpace::SrgbNonlinear:
            return "SrgbNonlinear";
        case VqColorSpace::DisplayP3Nonlinear:
            return "DisplayP3Nonlinear";
        case VqColorSpace::ExtendedSrgbLinear:
            return "ExtendedSrgbLinear";
        case VqColorSpace::DisplayP3Linear:
            return "DisplayP3Linear";
        case VqColorSpace::DciP3Nonlinear:
            return "DciP3Nonlinear";
        case VqColorSpace::Bt709Linear:
            return "Bt709Linear";
        case VqColorSpace::Bt709Nonlinear:
            return "Bt709Nonlinear";
        case VqColorSpace::Bt2020Linear:
            return "Bt2020Linear";
        case VqColorSpace::Hdr10St2084:
            return "Hdr10St2084";
        case VqColorSpace::Dolbyvision:
            return "Dolbyvision";
        case VqColorSpace::Hdr10Hlg:
            return "Hdr10Hlg";
        case VqColorSpace::AdobergbLinear:
            return "AdobergbLinear";
        case VqColorSpace::AdobergbNonlinear:
            return "AdobergbNonlinear";
        case VqColorSpace::PassThrough:
            return "PassThrough";
        case VqColorSpace::ExtendedSrgbNonlinear:
            return "ExtendedSrgbNonlinear";
        case VqColorSpace::DisplayNativeAMD:
            return "DisplayNativeAMD";
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

    std::string_view    to_string_view(VqCommandBufferResetBit v)
    {
        switch(v){
        case VqCommandBufferResetBit::ReleaseResources:
            return "ReleaseResources";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCommandBufferUsageBit v)
    {
        switch(v){
        case VqCommandBufferUsageBit::OneTimeSubmit:
            return "OneTimeSubmit";
        case VqCommandBufferUsageBit::RenderPassContinue:
            return "RenderPassContinue";
        case VqCommandBufferUsageBit::SimultaneousUse:
            return "SimultaneousUse";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCommandPoolCreateBit v)
    {
        switch(v){
        case VqCommandPoolCreateBit::Transient:
            return "Transient";
        case VqCommandPoolCreateBit::ResetCommandBuffer:
            return "ResetCommandBuffer";
        case VqCommandPoolCreateBit::Protected:
            return "Protected";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCommandPoolResetBit v)
    {
        switch(v){
        case VqCommandPoolResetBit::ReleaseResources:
            return "ReleaseResources";
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
        case VqComponentType::Float16:
            return "Float16";
        case VqComponentType::Float32:
            return "Float32";
        case VqComponentType::Float64:
            return "Float64";
        case VqComponentType::Sint8:
            return "Sint8";
        case VqComponentType::Sint16:
            return "Sint16";
        case VqComponentType::Sint32:
            return "Sint32";
        case VqComponentType::Sint64:
            return "Sint64";
        case VqComponentType::Uint8:
            return "Uint8";
        case VqComponentType::Uint16:
            return "Uint16";
        case VqComponentType::Uint32:
            return "Uint32";
        case VqComponentType::Uint64:
            return "Uint64";
        case VqComponentType::Bfloat16:
            return "Bfloat16";
        case VqComponentType::Sint8Packed:
            return "Sint8Packed";
        case VqComponentType::Uint8Packed:
            return "Uint8Packed";
        case VqComponentType::Float8E4m3:
            return "Float8E4m3";
        case VqComponentType::Float8E5m2:
            return "Float8E5m2";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCompositeAlphaBit v)
    {
        switch(v){
        case VqCompositeAlphaBit::Opaque:
            return "Opaque";
        case VqCompositeAlphaBit::PreMultiplied:
            return "PreMultiplied";
        case VqCompositeAlphaBit::PostMultiplied:
            return "PostMultiplied";
        case VqCompositeAlphaBit::Inherit:
            return "Inherit";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqConditionalRenderingBit v)
    {
        switch(v){
        case VqConditionalRenderingBit::Inverted:
            return "Inverted";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqConservativeRasterizationMode v)
    {
        switch(v){
        case VqConservativeRasterizationMode::Disabled:
            return "Disabled";
        case VqConservativeRasterizationMode::Overestimate:
            return "Overestimate";
        case VqConservativeRasterizationMode::Underestimate:
            return "Underestimate";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCooperativeVectorMatrixLayout v)
    {
        switch(v){
        case VqCooperativeVectorMatrixLayout::RowMajor:
            return "RowMajor";
        case VqCooperativeVectorMatrixLayout::ColumnMajor:
            return "ColumnMajor";
        case VqCooperativeVectorMatrixLayout::InferencingOptimal:
            return "InferencingOptimal";
        case VqCooperativeVectorMatrixLayout::TrainingOptimal:
            return "TrainingOptimal";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCopyAccelerationStructureMode v)
    {
        switch(v){
        case VqCopyAccelerationStructureMode::Clone:
            return "Clone";
        case VqCopyAccelerationStructureMode::Compact:
            return "Compact";
        case VqCopyAccelerationStructureMode::Serialize:
            return "Serialize";
        case VqCopyAccelerationStructureMode::Deserialize:
            return "Deserialize";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCopyMicromapMode v)
    {
        switch(v){
        case VqCopyMicromapMode::Clone:
            return "Clone";
        case VqCopyMicromapMode::Serialize:
            return "Serialize";
        case VqCopyMicromapMode::Deserialize:
            return "Deserialize";
        case VqCopyMicromapMode::Compact:
            return "Compact";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCoverageModulationMode v)
    {
        switch(v){
        case VqCoverageModulationMode::None:
            return "None";
        case VqCoverageModulationMode::Rgb:
            return "Rgb";
        case VqCoverageModulationMode::Alpha:
            return "Alpha";
        case VqCoverageModulationMode::Rgba:
            return "Rgba";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCoverageReductionMode v)
    {
        switch(v){
        case VqCoverageReductionMode::Merge:
            return "Merge";
        case VqCoverageReductionMode::Truncate:
            return "Truncate";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCubicFilterWeights v)
    {
        switch(v){
        case VqCubicFilterWeights::CatmullRom:
            return "CatmullRom";
        case VqCubicFilterWeights::ZeroTangentCardinal:
            return "ZeroTangentCardinal";
        case VqCubicFilterWeights::BSpline:
            return "BSpline";
        case VqCubicFilterWeights::MitchellNetravali:
            return "MitchellNetravali";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqCullModeBit v)
    {
        switch(v){
        case VqCullModeBit::Front:
            return "Front";
        case VqCullModeBit::Back:
            return "Back";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDataGraphPipelinePropertyARM v)
    {
        switch(v){
        case VqDataGraphPipelinePropertyARM::DataGraphPipelinePropertyCreationLogArm:
            return "DataGraphPipelinePropertyCreationLogArm";
        case VqDataGraphPipelinePropertyARM::DataGraphPipelinePropertyIdentifierArm:
            return "DataGraphPipelinePropertyIdentifierArm";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDataGraphPipelineSessionBindPointARM v)
    {
        switch(v){
        case VqDataGraphPipelineSessionBindPointARM::DataGraphPipelineSessionBindPointTransientArm:
            return "DataGraphPipelineSessionBindPointTransientArm";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDataGraphPipelineSessionBindPointTypeARM v)
    {
        switch(v){
        case VqDataGraphPipelineSessionBindPointTypeARM::DataGraphPipelineSessionBindPointTypeMemoryArm:
            return "DataGraphPipelineSessionBindPointTypeMemoryArm";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDebugReportBit v)
    {
        switch(v){
        case VqDebugReportBit::Information:
            return "Information";
        case VqDebugReportBit::Warning:
            return "Warning";
        case VqDebugReportBit::PerformanceWarning:
            return "PerformanceWarning";
        case VqDebugReportBit::Error:
            return "Error";
        case VqDebugReportBit::Debug:
            return "Debug";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDebugReportObjectType v)
    {
        switch(v){
        case VqDebugReportObjectType::Unknown:
            return "Unknown";
        case VqDebugReportObjectType::Instance:
            return "Instance";
        case VqDebugReportObjectType::PhysicalDevice:
            return "PhysicalDevice";
        case VqDebugReportObjectType::Device:
            return "Device";
        case VqDebugReportObjectType::Queue:
            return "Queue";
        case VqDebugReportObjectType::Semaphore:
            return "Semaphore";
        case VqDebugReportObjectType::CommandBuffer:
            return "CommandBuffer";
        case VqDebugReportObjectType::Fence:
            return "Fence";
        case VqDebugReportObjectType::DeviceMemory:
            return "DeviceMemory";
        case VqDebugReportObjectType::Buffer:
            return "Buffer";
        case VqDebugReportObjectType::Image:
            return "Image";
        case VqDebugReportObjectType::Event:
            return "Event";
        case VqDebugReportObjectType::QueryPool:
            return "QueryPool";
        case VqDebugReportObjectType::BufferView:
            return "BufferView";
        case VqDebugReportObjectType::ImageView:
            return "ImageView";
        case VqDebugReportObjectType::ShaderModule:
            return "ShaderModule";
        case VqDebugReportObjectType::PipelineCache:
            return "PipelineCache";
        case VqDebugReportObjectType::PipelineLayout:
            return "PipelineLayout";
        case VqDebugReportObjectType::RenderPass:
            return "RenderPass";
        case VqDebugReportObjectType::Pipeline:
            return "Pipeline";
        case VqDebugReportObjectType::DescriptorSetLayout:
            return "DescriptorSetLayout";
        case VqDebugReportObjectType::Sampler:
            return "Sampler";
        case VqDebugReportObjectType::DescriptorPool:
            return "DescriptorPool";
        case VqDebugReportObjectType::DescriptorSet:
            return "DescriptorSet";
        case VqDebugReportObjectType::Framebuffer:
            return "Framebuffer";
        case VqDebugReportObjectType::CommandPool:
            return "CommandPool";
        case VqDebugReportObjectType::Surface:
            return "Surface";
        case VqDebugReportObjectType::Swapchain:
            return "Swapchain";
        case VqDebugReportObjectType::DebugReportCallback:
            return "DebugReportCallback";
        case VqDebugReportObjectType::Display:
            return "Display";
        case VqDebugReportObjectType::DisplayMode:
            return "DisplayMode";
        case VqDebugReportObjectType::ValidationCache:
            return "ValidationCache";
        case VqDebugReportObjectType::SamplerYcbcrConversion:
            return "SamplerYcbcrConversion";
        case VqDebugReportObjectType::DescriptorUpdateTemplate:
            return "DescriptorUpdateTemplate";
        case VqDebugReportObjectType::CuModuleNvx:
            return "CuModuleNvx";
        case VqDebugReportObjectType::CuFunctionNvx:
            return "CuFunctionNvx";
        case VqDebugReportObjectType::AccelerationStructure:
            return "AccelerationStructure";
        case VqDebugReportObjectType::CudaModule:
            return "CudaModule";
        case VqDebugReportObjectType::CudaFunction:
            return "CudaFunction";
        case VqDebugReportObjectType::BufferCollectionFuchsia:
            return "BufferCollectionFuchsia";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDebugUtilsMessageSeverityBit v)
    {
        switch(v){
        case VqDebugUtilsMessageSeverityBit::Verbose:
            return "Verbose";
        case VqDebugUtilsMessageSeverityBit::Info:
            return "Info";
        case VqDebugUtilsMessageSeverityBit::Warning:
            return "Warning";
        case VqDebugUtilsMessageSeverityBit::Error:
            return "Error";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDebugUtilsMessageTypeBit v)
    {
        switch(v){
        case VqDebugUtilsMessageTypeBit::General:
            return "General";
        case VqDebugUtilsMessageTypeBit::Validation:
            return "Validation";
        case VqDebugUtilsMessageTypeBit::Performance:
            return "Performance";
        case VqDebugUtilsMessageTypeBit::DeviceAddressBinding:
            return "DeviceAddressBinding";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDefaultVertexAttributeValue v)
    {
        switch(v){
        case VqDefaultVertexAttributeValue::ZeroZeroZeroZero:
            return "ZeroZeroZeroZero";
        case VqDefaultVertexAttributeValue::ZeroZeroZeroOne:
            return "ZeroZeroZeroOne";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDependencyBit v)
    {
        switch(v){
        case VqDependencyBit::ByRegion:
            return "ByRegion";
        case VqDependencyBit::DeviceGroup:
            return "DeviceGroup";
        case VqDependencyBit::ViewLocal:
            return "ViewLocal";
        case VqDependencyBit::FeedbackLoop:
            return "FeedbackLoop";
        case VqDependencyBit::QueueFamilyOwnershipTransferUseAllStages:
            return "QueueFamilyOwnershipTransferUseAllStages";
        case VqDependencyBit::AsymmetricEvent:
            return "AsymmetricEvent";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDepthBiasRepresentation v)
    {
        switch(v){
        case VqDepthBiasRepresentation::LeastRepresentableValueFormat:
            return "LeastRepresentableValueFormat";
        case VqDepthBiasRepresentation::LeastRepresentableValueForceUnorm:
            return "LeastRepresentableValueForceUnorm";
        case VqDepthBiasRepresentation::Float:
            return "Float";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDepthClampMode v)
    {
        switch(v){
        case VqDepthClampMode::ViewportRange:
            return "ViewportRange";
        case VqDepthClampMode::UserDefinedRange:
            return "UserDefinedRange";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDescriptorBindingBit v)
    {
        switch(v){
        case VqDescriptorBindingBit::UpdateAfterBind:
            return "UpdateAfterBind";
        case VqDescriptorBindingBit::UpdateUnusedWhilePending:
            return "UpdateUnusedWhilePending";
        case VqDescriptorBindingBit::PartiallyBound:
            return "PartiallyBound";
        case VqDescriptorBindingBit::VariableDescriptorCount:
            return "VariableDescriptorCount";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDescriptorPoolCreateBit v)
    {
        switch(v){
        case VqDescriptorPoolCreateBit::FreeDescriptorSet:
            return "FreeDescriptorSet";
        case VqDescriptorPoolCreateBit::UpdateAfterBind:
            return "UpdateAfterBind";
        case VqDescriptorPoolCreateBit::HostOnly:
            return "HostOnly";
        case VqDescriptorPoolCreateBit::AllowOverallocationSets:
            return "AllowOverallocationSets";
        case VqDescriptorPoolCreateBit::AllowOverallocationPools:
            return "AllowOverallocationPools";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDescriptorSetLayoutCreateBit v)
    {
        switch(v){
        case VqDescriptorSetLayoutCreateBit::UpdateAfterBindPool:
            return "UpdateAfterBindPool";
        case VqDescriptorSetLayoutCreateBit::PushDescriptor:
            return "PushDescriptor";
        case VqDescriptorSetLayoutCreateBit::DescriptorBuffer:
            return "DescriptorBuffer";
        case VqDescriptorSetLayoutCreateBit::EmbeddedImmutableSamplers:
            return "EmbeddedImmutableSamplers";
        case VqDescriptorSetLayoutCreateBit::IndirectBindable:
            return "IndirectBindable";
        case VqDescriptorSetLayoutCreateBit::HostOnlyPool:
            return "HostOnlyPool";
        case VqDescriptorSetLayoutCreateBit::PerStage:
            return "PerStage";
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
        case VqDescriptorType::AccelerationStructure:
            return "AccelerationStructure";
        case VqDescriptorType::SampleWeightImage:
            return "SampleWeightImage";
        case VqDescriptorType::BlockMatchImage:
            return "BlockMatchImage";
        case VqDescriptorType::TensorArm:
            return "TensorArm";
        case VqDescriptorType::Mutable:
            return "Mutable";
        case VqDescriptorType::PartitionedAccelerationStructure:
            return "PartitionedAccelerationStructure";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDescriptorUpdateTemplateType v)
    {
        switch(v){
        case VqDescriptorUpdateTemplateType::DescriptorSet:
            return "DescriptorSet";
        case VqDescriptorUpdateTemplateType::PushDescriptors:
            return "PushDescriptors";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDeviceAddressBindingBit v)
    {
        switch(v){
        case VqDeviceAddressBindingBit::InternalObject:
            return "InternalObject";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDeviceAddressBindingType v)
    {
        switch(v){
        case VqDeviceAddressBindingType::Bind:
            return "Bind";
        case VqDeviceAddressBindingType::Unbind:
            return "Unbind";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDeviceDiagnosticsConfigBit v)
    {
        switch(v){
        case VqDeviceDiagnosticsConfigBit::EnableShaderDebugInfo:
            return "EnableShaderDebugInfo";
        case VqDeviceDiagnosticsConfigBit::EnableResourceTracking:
            return "EnableResourceTracking";
        case VqDeviceDiagnosticsConfigBit::EnableAutomaticCheckpoints:
            return "EnableAutomaticCheckpoints";
        case VqDeviceDiagnosticsConfigBit::EnableShaderErrorReporting:
            return "EnableShaderErrorReporting";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDeviceEventType v)
    {
        switch(v){
        case VqDeviceEventType::DisplayHotplug:
            return "DisplayHotplug";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDeviceFaultAddressType v)
    {
        switch(v){
        case VqDeviceFaultAddressType::None:
            return "None";
        case VqDeviceFaultAddressType::ReadInvalid:
            return "ReadInvalid";
        case VqDeviceFaultAddressType::WriteInvalid:
            return "WriteInvalid";
        case VqDeviceFaultAddressType::ExecuteInvalid:
            return "ExecuteInvalid";
        case VqDeviceFaultAddressType::InstructionPointerUnknown:
            return "InstructionPointerUnknown";
        case VqDeviceFaultAddressType::InstructionPointerInvalid:
            return "InstructionPointerInvalid";
        case VqDeviceFaultAddressType::InstructionPointerFault:
            return "InstructionPointerFault";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDeviceFaultVendorBinaryHeaderVersion v)
    {
        switch(v){
        case VqDeviceFaultVendorBinaryHeaderVersion::One:
            return "One";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDeviceGroupPresentModeBit v)
    {
        switch(v){
        case VqDeviceGroupPresentModeBit::Local:
            return "Local";
        case VqDeviceGroupPresentModeBit::Remote:
            return "Remote";
        case VqDeviceGroupPresentModeBit::Sum:
            return "Sum";
        case VqDeviceGroupPresentModeBit::LocalMultiDevice:
            return "LocalMultiDevice";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDeviceMemoryReportEventType v)
    {
        switch(v){
        case VqDeviceMemoryReportEventType::Allocate:
            return "Allocate";
        case VqDeviceMemoryReportEventType::Free:
            return "Free";
        case VqDeviceMemoryReportEventType::Import:
            return "Import";
        case VqDeviceMemoryReportEventType::Unimport:
            return "Unimport";
        case VqDeviceMemoryReportEventType::AllocationFailed:
            return "AllocationFailed";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDeviceQueueCreateBit v)
    {
        switch(v){
        case VqDeviceQueueCreateBit::Protected:
            return "Protected";
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
        case VqDiscardRectangleMode::Inclusive:
            return "Inclusive";
        case VqDiscardRectangleMode::Exclusive:
            return "Exclusive";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDisplayEventType v)
    {
        switch(v){
        case VqDisplayEventType::FirstPixelOut:
            return "FirstPixelOut";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDisplayPlaneAlphaBit v)
    {
        switch(v){
        case VqDisplayPlaneAlphaBit::Opaque:
            return "Opaque";
        case VqDisplayPlaneAlphaBit::Global:
            return "Global";
        case VqDisplayPlaneAlphaBit::PerPixel:
            return "PerPixel";
        case VqDisplayPlaneAlphaBit::PerPixelPremultiplied:
            return "PerPixelPremultiplied";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDisplayPowerState v)
    {
        switch(v){
        case VqDisplayPowerState::Off:
            return "Off";
        case VqDisplayPowerState::Suspend:
            return "Suspend";
        case VqDisplayPowerState::On:
            return "On";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqDisplaySurfaceStereoType v)
    {
        switch(v){
        case VqDisplaySurfaceStereoType::None:
            return "None";
        case VqDisplaySurfaceStereoType::OnboardDin:
            return "OnboardDin";
        case VqDisplaySurfaceStereoType::Hdmi3d:
            return "Hdmi3d";
        case VqDisplaySurfaceStereoType::InbandDisplayport:
            return "InbandDisplayport";
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
        case VqDriverId::VulkanScEmulationOnVulkan:
            return "VulkanScEmulationOnVulkan";
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
        case VqDynamicState::LineStipple:
            return "LineStipple";
        case VqDynamicState::ViewportWScaling:
            return "ViewportWScaling";
        case VqDynamicState::DiscardRectangle:
            return "DiscardRectangle";
        case VqDynamicState::DiscardRectangleEnable:
            return "DiscardRectangleEnable";
        case VqDynamicState::DiscardRectangleMode:
            return "DiscardRectangleMode";
        case VqDynamicState::SampleLocations:
            return "SampleLocations";
        case VqDynamicState::RayTracingPipelineStackSize:
            return "RayTracingPipelineStackSize";
        case VqDynamicState::ViewportShadingRatePalette:
            return "ViewportShadingRatePalette";
        case VqDynamicState::ViewportCoarseSampleOrder:
            return "ViewportCoarseSampleOrder";
        case VqDynamicState::ExclusiveScissorEnable:
            return "ExclusiveScissorEnable";
        case VqDynamicState::ExclusiveScissor:
            return "ExclusiveScissor";
        case VqDynamicState::FragmentShadingRate:
            return "FragmentShadingRate";
        case VqDynamicState::VertexInput:
            return "VertexInput";
        case VqDynamicState::PatchControlPoints:
            return "PatchControlPoints";
        case VqDynamicState::LogicOp:
            return "LogicOp";
        case VqDynamicState::ColorWriteEnable:
            return "ColorWriteEnable";
        case VqDynamicState::DepthClampEnable:
            return "DepthClampEnable";
        case VqDynamicState::PolygonMode:
            return "PolygonMode";
        case VqDynamicState::RasterizationSamples:
            return "RasterizationSamples";
        case VqDynamicState::SampleMask:
            return "SampleMask";
        case VqDynamicState::AlphaToCoverageEnable:
            return "AlphaToCoverageEnable";
        case VqDynamicState::AlphaToOneEnable:
            return "AlphaToOneEnable";
        case VqDynamicState::LogicOpEnable:
            return "LogicOpEnable";
        case VqDynamicState::ColorBlendEnable:
            return "ColorBlendEnable";
        case VqDynamicState::ColorBlendEquation:
            return "ColorBlendEquation";
        case VqDynamicState::ColorWriteMask:
            return "ColorWriteMask";
        case VqDynamicState::TessellationDomainOrigin:
            return "TessellationDomainOrigin";
        case VqDynamicState::RasterizationStream:
            return "RasterizationStream";
        case VqDynamicState::ConservativeRasterizationMode:
            return "ConservativeRasterizationMode";
        case VqDynamicState::ExtraPrimitiveOverestimationSize:
            return "ExtraPrimitiveOverestimationSize";
        case VqDynamicState::DepthClipEnable:
            return "DepthClipEnable";
        case VqDynamicState::SampleLocationsEnable:
            return "SampleLocationsEnable";
        case VqDynamicState::ColorBlendAdvanced:
            return "ColorBlendAdvanced";
        case VqDynamicState::ProvokingVertexMode:
            return "ProvokingVertexMode";
        case VqDynamicState::LineRasterizationMode:
            return "LineRasterizationMode";
        case VqDynamicState::LineStippleEnable:
            return "LineStippleEnable";
        case VqDynamicState::DepthClipNegativeOneToOne:
            return "DepthClipNegativeOneToOne";
        case VqDynamicState::ViewportWScalingEnable:
            return "ViewportWScalingEnable";
        case VqDynamicState::ViewportSwizzle:
            return "ViewportSwizzle";
        case VqDynamicState::CoverageToColorEnable:
            return "CoverageToColorEnable";
        case VqDynamicState::CoverageToColorLocation:
            return "CoverageToColorLocation";
        case VqDynamicState::CoverageModulationMode:
            return "CoverageModulationMode";
        case VqDynamicState::CoverageModulationTableEnable:
            return "CoverageModulationTableEnable";
        case VqDynamicState::CoverageModulationTable:
            return "CoverageModulationTable";
        case VqDynamicState::ShadingRateImageEnable:
            return "ShadingRateImageEnable";
        case VqDynamicState::RepresentativeFragmentTestEnable:
            return "RepresentativeFragmentTestEnable";
        case VqDynamicState::CoverageReductionMode:
            return "CoverageReductionMode";
        case VqDynamicState::AttachmentFeedbackLoopEnable:
            return "AttachmentFeedbackLoopEnable";
        case VqDynamicState::DepthClampRange:
            return "DepthClampRange";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqEventCreateBit v)
    {
        switch(v){
        case VqEventCreateBit::DeviceOnly:
            return "DeviceOnly";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqExternalFenceFeatureBit v)
    {
        switch(v){
        case VqExternalFenceFeatureBit::Exportable:
            return "Exportable";
        case VqExternalFenceFeatureBit::Importable:
            return "Importable";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqExternalFenceHandleTypeBit v)
    {
        switch(v){
        case VqExternalFenceHandleTypeBit::OpaqueFd:
            return "OpaqueFd";
        case VqExternalFenceHandleTypeBit::OpaqueWin32:
            return "OpaqueWin32";
        case VqExternalFenceHandleTypeBit::OpaqueWin32Kmt:
            return "OpaqueWin32Kmt";
        case VqExternalFenceHandleTypeBit::SyncFd:
            return "SyncFd";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqExternalMemoryFeatureBit v)
    {
        switch(v){
        case VqExternalMemoryFeatureBit::DedicatedOnly:
            return "DedicatedOnly";
        case VqExternalMemoryFeatureBit::Exportable:
            return "Exportable";
        case VqExternalMemoryFeatureBit::Importable:
            return "Importable";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqExternalMemoryHandleTypeBit v)
    {
        switch(v){
        case VqExternalMemoryHandleTypeBit::OpaqueFd:
            return "OpaqueFd";
        case VqExternalMemoryHandleTypeBit::OpaqueWin32:
            return "OpaqueWin32";
        case VqExternalMemoryHandleTypeBit::OpaqueWin32Kmt:
            return "OpaqueWin32Kmt";
        case VqExternalMemoryHandleTypeBit::D3d11Texture:
            return "D3d11Texture";
        case VqExternalMemoryHandleTypeBit::D3d11TextureKmt:
            return "D3d11TextureKmt";
        case VqExternalMemoryHandleTypeBit::D3d12Heap:
            return "D3d12Heap";
        case VqExternalMemoryHandleTypeBit::D3d12Resource:
            return "D3d12Resource";
        case VqExternalMemoryHandleTypeBit::DmaBuf:
            return "DmaBuf";
        case VqExternalMemoryHandleTypeBit::AndroidHardwareBufferBitAndroid:
            return "AndroidHardwareBufferBitAndroid";
        case VqExternalMemoryHandleTypeBit::HostAllocation:
            return "HostAllocation";
        case VqExternalMemoryHandleTypeBit::HostMappedForeignMemory:
            return "HostMappedForeignMemory";
        case VqExternalMemoryHandleTypeBit::ZirconVmoBitFuchsia:
            return "ZirconVmoBitFuchsia";
        case VqExternalMemoryHandleTypeBit::RdmaAddress:
            return "RdmaAddress";
        case VqExternalMemoryHandleTypeBit::ScreenBufferBitQnx:
            return "ScreenBufferBitQnx";
        case VqExternalMemoryHandleTypeBit::Mtlbuffer:
            return "Mtlbuffer";
        case VqExternalMemoryHandleTypeBit::Mtltexture:
            return "Mtltexture";
        case VqExternalMemoryHandleTypeBit::Mtlheap:
            return "Mtlheap";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqExternalSemaphoreFeatureBit v)
    {
        switch(v){
        case VqExternalSemaphoreFeatureBit::Exportable:
            return "Exportable";
        case VqExternalSemaphoreFeatureBit::Importable:
            return "Importable";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqExternalSemaphoreHandleTypeBit v)
    {
        switch(v){
        case VqExternalSemaphoreHandleTypeBit::OpaqueFd:
            return "OpaqueFd";
        case VqExternalSemaphoreHandleTypeBit::OpaqueWin32:
            return "OpaqueWin32";
        case VqExternalSemaphoreHandleTypeBit::OpaqueWin32Kmt:
            return "OpaqueWin32Kmt";
        case VqExternalSemaphoreHandleTypeBit::D3d12Fence:
            return "D3d12Fence";
        case VqExternalSemaphoreHandleTypeBit::SyncFd:
            return "SyncFd";
        case VqExternalSemaphoreHandleTypeBit::ZirconEventBitFuchsia:
            return "ZirconEventBitFuchsia";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqFenceCreateBit v)
    {
        switch(v){
        case VqFenceCreateBit::Signaled:
            return "Signaled";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqFenceImportBit v)
    {
        switch(v){
        case VqFenceImportBit::Temporary:
            return "Temporary";
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
        case VqFilter::Cubic:
            return "Cubic";
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
        case VqFormat::A1b5g5r5UnormPack16:
            return "A1b5g5r5UnormPack16";
        case VqFormat::A8Unorm:
            return "A8Unorm";
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
        case VqFormat::R8BoolArm:
            return "R8BoolArm";
        case VqFormat::R16g16Sfixed5:
            return "R16g16Sfixed5";
        case VqFormat::R10x6UintPack16Arm:
            return "R10x6UintPack16Arm";
        case VqFormat::R10x6g10x6Uint2pack16Arm:
            return "R10x6g10x6Uint2pack16Arm";
        case VqFormat::R10x6g10x6b10x6a10x6Uint4pack16Arm:
            return "R10x6g10x6b10x6a10x6Uint4pack16Arm";
        case VqFormat::R12x4UintPack16Arm:
            return "R12x4UintPack16Arm";
        case VqFormat::R12x4g12x4Uint2pack16Arm:
            return "R12x4g12x4Uint2pack16Arm";
        case VqFormat::R12x4g12x4b12x4a12x4Uint4pack16Arm:
            return "R12x4g12x4b12x4a12x4Uint4pack16Arm";
        case VqFormat::R14x2UintPack16Arm:
            return "R14x2UintPack16Arm";
        case VqFormat::R14x2g14x2Uint2pack16Arm:
            return "R14x2g14x2Uint2pack16Arm";
        case VqFormat::R14x2g14x2b14x2a14x2Uint4pack16Arm:
            return "R14x2g14x2b14x2a14x2Uint4pack16Arm";
        case VqFormat::R14x2UnormPack16Arm:
            return "R14x2UnormPack16Arm";
        case VqFormat::R14x2g14x2Unorm2pack16Arm:
            return "R14x2g14x2Unorm2pack16Arm";
        case VqFormat::R14x2g14x2b14x2a14x2Unorm4pack16Arm:
            return "R14x2g14x2b14x2a14x2Unorm4pack16Arm";
        case VqFormat::G14x2B14x2r14x22plane420Unorm3pack16Arm:
            return "G14x2B14x2r14x22plane420Unorm3pack16Arm";
        case VqFormat::G14x2B14x2r14x22plane422Unorm3pack16Arm:
            return "G14x2B14x2r14x22plane422Unorm3pack16Arm";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqFormatFeatureBit v)
    {
        switch(v){
        case VqFormatFeatureBit::SampledImage:
            return "SampledImage";
        case VqFormatFeatureBit::StorageImage:
            return "StorageImage";
        case VqFormatFeatureBit::StorageImageAtomic:
            return "StorageImageAtomic";
        case VqFormatFeatureBit::UniformTexelBuffer:
            return "UniformTexelBuffer";
        case VqFormatFeatureBit::StorageTexelBuffer:
            return "StorageTexelBuffer";
        case VqFormatFeatureBit::StorageTexelBufferAtomic:
            return "StorageTexelBufferAtomic";
        case VqFormatFeatureBit::VertexBuffer:
            return "VertexBuffer";
        case VqFormatFeatureBit::ColorAttachment:
            return "ColorAttachment";
        case VqFormatFeatureBit::ColorAttachmentBlend:
            return "ColorAttachmentBlend";
        case VqFormatFeatureBit::DepthStencilAttachment:
            return "DepthStencilAttachment";
        case VqFormatFeatureBit::BlitSrc:
            return "BlitSrc";
        case VqFormatFeatureBit::BlitDst:
            return "BlitDst";
        case VqFormatFeatureBit::SampledImageFilterLinear:
            return "SampledImageFilterLinear";
        case VqFormatFeatureBit::TransferSrc:
            return "TransferSrc";
        case VqFormatFeatureBit::TransferDst:
            return "TransferDst";
        case VqFormatFeatureBit::MidpointChromaSamples:
            return "MidpointChromaSamples";
        case VqFormatFeatureBit::SampledImageYcbcrConversionLinearFilter:
            return "SampledImageYcbcrConversionLinearFilter";
        case VqFormatFeatureBit::SampledImageYcbcrConversionSeparateReconstructionFilter:
            return "SampledImageYcbcrConversionSeparateReconstructionFilter";
        case VqFormatFeatureBit::SampledImageYcbcrConversionChromaReconstructionExplicit:
            return "SampledImageYcbcrConversionChromaReconstructionExplicit";
        case VqFormatFeatureBit::SampledImageYcbcrConversionChromaReconstructionExplicitForceable:
            return "SampledImageYcbcrConversionChromaReconstructionExplicitForceable";
        case VqFormatFeatureBit::Disjoint:
            return "Disjoint";
        case VqFormatFeatureBit::CositedChromaSamples:
            return "CositedChromaSamples";
        case VqFormatFeatureBit::SampledImageFilterMinmax:
            return "SampledImageFilterMinmax";
        case VqFormatFeatureBit::VideoDecodeOutput:
            return "VideoDecodeOutput";
        case VqFormatFeatureBit::VideoDecodeDpb:
            return "VideoDecodeDpb";
        case VqFormatFeatureBit::AccelerationStructureVertexBuffer:
            return "AccelerationStructureVertexBuffer";
        case VqFormatFeatureBit::SampledImageFilterCubic:
            return "SampledImageFilterCubic";
        case VqFormatFeatureBit::FragmentDensityMap:
            return "FragmentDensityMap";
        case VqFormatFeatureBit::FragmentShadingRateAttachment:
            return "FragmentShadingRateAttachment";
        case VqFormatFeatureBit::VideoEncodeInput:
            return "VideoEncodeInput";
        case VqFormatFeatureBit::VideoEncodeDpb:
            return "VideoEncodeDpb";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqFragmentShadingRate v)
    {
        switch(v){
        case VqFragmentShadingRate::_1InvocationPerPixel:
            return "_1InvocationPerPixel";
        case VqFragmentShadingRate::_1InvocationPer1x2Pixels:
            return "_1InvocationPer1x2Pixels";
        case VqFragmentShadingRate::_1InvocationPer2x1Pixels:
            return "_1InvocationPer2x1Pixels";
        case VqFragmentShadingRate::_1InvocationPer2x2Pixels:
            return "_1InvocationPer2x2Pixels";
        case VqFragmentShadingRate::_1InvocationPer2x4Pixels:
            return "_1InvocationPer2x4Pixels";
        case VqFragmentShadingRate::_1InvocationPer4x2Pixels:
            return "_1InvocationPer4x2Pixels";
        case VqFragmentShadingRate::_1InvocationPer4x4Pixels:
            return "_1InvocationPer4x4Pixels";
        case VqFragmentShadingRate::_2InvocationsPerPixel:
            return "_2InvocationsPerPixel";
        case VqFragmentShadingRate::_4InvocationsPerPixel:
            return "_4InvocationsPerPixel";
        case VqFragmentShadingRate::_8InvocationsPerPixel:
            return "_8InvocationsPerPixel";
        case VqFragmentShadingRate::_16InvocationsPerPixel:
            return "_16InvocationsPerPixel";
        case VqFragmentShadingRate::NoInvocations:
            return "NoInvocations";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqFragmentShadingRateCombinerOp v)
    {
        switch(v){
        case VqFragmentShadingRateCombinerOp::Keep:
            return "Keep";
        case VqFragmentShadingRateCombinerOp::Replace:
            return "Replace";
        case VqFragmentShadingRateCombinerOp::Min:
            return "Min";
        case VqFragmentShadingRateCombinerOp::Max:
            return "Max";
        case VqFragmentShadingRateCombinerOp::Mul:
            return "Mul";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqFragmentShadingRateType v)
    {
        switch(v){
        case VqFragmentShadingRateType::FragmentSize:
            return "FragmentSize";
        case VqFragmentShadingRateType::Enums:
            return "Enums";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqFrameBoundaryBit v)
    {
        switch(v){
        case VqFrameBoundaryBit::FrameEnd:
            return "FrameEnd";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqFramebufferCreateBit v)
    {
        switch(v){
        case VqFramebufferCreateBit::Imageless:
            return "Imageless";
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

    std::string_view    to_string_view(VqGeometryBit v)
    {
        switch(v){
        case VqGeometryBit::Opaque:
            return "Opaque";
        case VqGeometryBit::NoDuplicateAnyHitInvocation:
            return "NoDuplicateAnyHitInvocation";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqGeometryInstanceBit v)
    {
        switch(v){
        case VqGeometryInstanceBit::TriangleFacingCullDisable:
            return "TriangleFacingCullDisable";
        case VqGeometryInstanceBit::TriangleFlipFacing:
            return "TriangleFlipFacing";
        case VqGeometryInstanceBit::ForceOpaque:
            return "ForceOpaque";
        case VqGeometryInstanceBit::ForceNoOpaque:
            return "ForceNoOpaque";
        case VqGeometryInstanceBit::ForceOpacityMicromap2State:
            return "ForceOpacityMicromap2State";
        case VqGeometryInstanceBit::DisableOpacityMicromaps:
            return "DisableOpacityMicromaps";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqGeometryType v)
    {
        switch(v){
        case VqGeometryType::Triangles:
            return "Triangles";
        case VqGeometryType::Aabbs:
            return "Aabbs";
        case VqGeometryType::Instances:
            return "Instances";
        case VqGeometryType::Spheres:
            return "Spheres";
        case VqGeometryType::LinearSweptSpheres:
            return "LinearSweptSpheres";
        case VqGeometryType::DenseGeometryFormatTrianglesAmdx:
            return "DenseGeometryFormatTrianglesAmdx";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqGraphicsPipelineLibraryBit v)
    {
        switch(v){
        case VqGraphicsPipelineLibraryBit::VertexInputInterface:
            return "VertexInputInterface";
        case VqGraphicsPipelineLibraryBit::PreRasterizationShaders:
            return "PreRasterizationShaders";
        case VqGraphicsPipelineLibraryBit::FragmentShader:
            return "FragmentShader";
        case VqGraphicsPipelineLibraryBit::FragmentOutputInterface:
            return "FragmentOutputInterface";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqHostImageCopyBit v)
    {
        switch(v){
        case VqHostImageCopyBit::Memcpy:
            return "Memcpy";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqImageAspectBit v)
    {
        switch(v){
        case VqImageAspectBit::Color:
            return "Color";
        case VqImageAspectBit::Depth:
            return "Depth";
        case VqImageAspectBit::Stencil:
            return "Stencil";
        case VqImageAspectBit::Metadata:
            return "Metadata";
        case VqImageAspectBit::Plane0:
            return "Plane0";
        case VqImageAspectBit::Plane1:
            return "Plane1";
        case VqImageAspectBit::Plane2:
            return "Plane2";
        case VqImageAspectBit::MemoryPlane0:
            return "MemoryPlane0";
        case VqImageAspectBit::MemoryPlane1:
            return "MemoryPlane1";
        case VqImageAspectBit::MemoryPlane2:
            return "MemoryPlane2";
        case VqImageAspectBit::MemoryPlane3:
            return "MemoryPlane3";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqImageCompressionFixedRateBit v)
    {
        switch(v){
        case VqImageCompressionFixedRateBit::_1bpc:
            return "_1bpc";
        case VqImageCompressionFixedRateBit::_2bpc:
            return "_2bpc";
        case VqImageCompressionFixedRateBit::_3bpc:
            return "_3bpc";
        case VqImageCompressionFixedRateBit::_4bpc:
            return "_4bpc";
        case VqImageCompressionFixedRateBit::_5bpc:
            return "_5bpc";
        case VqImageCompressionFixedRateBit::_6bpc:
            return "_6bpc";
        case VqImageCompressionFixedRateBit::_7bpc:
            return "_7bpc";
        case VqImageCompressionFixedRateBit::_8bpc:
            return "_8bpc";
        case VqImageCompressionFixedRateBit::_9bpc:
            return "_9bpc";
        case VqImageCompressionFixedRateBit::_10bpc:
            return "_10bpc";
        case VqImageCompressionFixedRateBit::_11bpc:
            return "_11bpc";
        case VqImageCompressionFixedRateBit::_12bpc:
            return "_12bpc";
        case VqImageCompressionFixedRateBit::_13bpc:
            return "_13bpc";
        case VqImageCompressionFixedRateBit::_14bpc:
            return "_14bpc";
        case VqImageCompressionFixedRateBit::_15bpc:
            return "_15bpc";
        case VqImageCompressionFixedRateBit::_16bpc:
            return "_16bpc";
        case VqImageCompressionFixedRateBit::_17bpc:
            return "_17bpc";
        case VqImageCompressionFixedRateBit::_18bpc:
            return "_18bpc";
        case VqImageCompressionFixedRateBit::_19bpc:
            return "_19bpc";
        case VqImageCompressionFixedRateBit::_20bpc:
            return "_20bpc";
        case VqImageCompressionFixedRateBit::_21bpc:
            return "_21bpc";
        case VqImageCompressionFixedRateBit::_22bpc:
            return "_22bpc";
        case VqImageCompressionFixedRateBit::_23bpc:
            return "_23bpc";
        case VqImageCompressionFixedRateBit::_24bpc:
            return "_24bpc";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqImageCompressionBit v)
    {
        switch(v){
        case VqImageCompressionBit::Default:
            return "Default";
        case VqImageCompressionBit::FixedRateDefault:
            return "FixedRateDefault";
        case VqImageCompressionBit::FixedRateExplicit:
            return "FixedRateExplicit";
        case VqImageCompressionBit::Disabled:
            return "Disabled";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqImageCreateBit v)
    {
        switch(v){
        case VqImageCreateBit::SparseBinding:
            return "SparseBinding";
        case VqImageCreateBit::SparseResidency:
            return "SparseResidency";
        case VqImageCreateBit::SparseAliased:
            return "SparseAliased";
        case VqImageCreateBit::MutableFormat:
            return "MutableFormat";
        case VqImageCreateBit::CubeCompatible:
            return "CubeCompatible";
        case VqImageCreateBit::Alias:
            return "Alias";
        case VqImageCreateBit::SplitInstanceBindRegions:
            return "SplitInstanceBindRegions";
        case VqImageCreateBit::_2dArrayCompatible:
            return "_2dArrayCompatible";
        case VqImageCreateBit::BlockTexelViewCompatible:
            return "BlockTexelViewCompatible";
        case VqImageCreateBit::ExtendedUsage:
            return "ExtendedUsage";
        case VqImageCreateBit::Protected:
            return "Protected";
        case VqImageCreateBit::Disjoint:
            return "Disjoint";
        case VqImageCreateBit::CornerSampled:
            return "CornerSampled";
        case VqImageCreateBit::SampleLocationsCompatibleDepth:
            return "SampleLocationsCompatibleDepth";
        case VqImageCreateBit::Subsampled:
            return "Subsampled";
        case VqImageCreateBit::DescriptorBufferCaptureReplay:
            return "DescriptorBufferCaptureReplay";
        case VqImageCreateBit::MultisampledRenderToSingleSampled:
            return "MultisampledRenderToSingleSampled";
        case VqImageCreateBit::_2dViewCompatible:
            return "_2dViewCompatible";
        case VqImageCreateBit::VideoProfileIndependent:
            return "VideoProfileIndependent";
        case VqImageCreateBit::FragmentDensityMapOffset:
            return "FragmentDensityMapOffset";
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
        case VqImageLayout::RenderingLocalRead:
            return "RenderingLocalRead";
        case VqImageLayout::PresentSrc:
            return "PresentSrc";
        case VqImageLayout::VideoDecodeDst:
            return "VideoDecodeDst";
        case VqImageLayout::VideoDecodeSrc:
            return "VideoDecodeSrc";
        case VqImageLayout::VideoDecodeDpb:
            return "VideoDecodeDpb";
        case VqImageLayout::SharedPresent:
            return "SharedPresent";
        case VqImageLayout::FragmentDensityMapOptimal:
            return "FragmentDensityMapOptimal";
        case VqImageLayout::FragmentShadingRateAttachmentOptimal:
            return "FragmentShadingRateAttachmentOptimal";
        case VqImageLayout::VideoEncodeDst:
            return "VideoEncodeDst";
        case VqImageLayout::VideoEncodeSrc:
            return "VideoEncodeSrc";
        case VqImageLayout::VideoEncodeDpb:
            return "VideoEncodeDpb";
        case VqImageLayout::AttachmentFeedbackLoopOptimal:
            return "AttachmentFeedbackLoopOptimal";
        case VqImageLayout::TensorAliasingArm:
            return "TensorAliasingArm";
        case VqImageLayout::VideoEncodeQuantizationMap:
            return "VideoEncodeQuantizationMap";
        case VqImageLayout::ZeroInitialized:
            return "ZeroInitialized";
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
        case VqImageTiling::DrmFormatModifier:
            return "DrmFormatModifier";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqImageType v)
    {
        switch(v){
        case VqImageType::_1d:
            return "_1d";
        case VqImageType::_2d:
            return "_2d";
        case VqImageType::_3d:
            return "_3d";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqImageUsageBit v)
    {
        switch(v){
        case VqImageUsageBit::TransferSrc:
            return "TransferSrc";
        case VqImageUsageBit::TransferDst:
            return "TransferDst";
        case VqImageUsageBit::Sampled:
            return "Sampled";
        case VqImageUsageBit::Storage:
            return "Storage";
        case VqImageUsageBit::ColorAttachment:
            return "ColorAttachment";
        case VqImageUsageBit::DepthStencilAttachment:
            return "DepthStencilAttachment";
        case VqImageUsageBit::TransientAttachment:
            return "TransientAttachment";
        case VqImageUsageBit::InputAttachment:
            return "InputAttachment";
        case VqImageUsageBit::HostTransfer:
            return "HostTransfer";
        case VqImageUsageBit::VideoDecodeDst:
            return "VideoDecodeDst";
        case VqImageUsageBit::VideoDecodeSrc:
            return "VideoDecodeSrc";
        case VqImageUsageBit::VideoDecodeDpb:
            return "VideoDecodeDpb";
        case VqImageUsageBit::FragmentDensityMap:
            return "FragmentDensityMap";
        case VqImageUsageBit::FragmentShadingRateAttachment:
            return "FragmentShadingRateAttachment";
        case VqImageUsageBit::VideoEncodeDst:
            return "VideoEncodeDst";
        case VqImageUsageBit::VideoEncodeSrc:
            return "VideoEncodeSrc";
        case VqImageUsageBit::VideoEncodeDpb:
            return "VideoEncodeDpb";
        case VqImageUsageBit::AttachmentFeedbackLoop:
            return "AttachmentFeedbackLoop";
        case VqImageUsageBit::InvocationMaskBitHuawei:
            return "InvocationMaskBitHuawei";
        case VqImageUsageBit::SampleWeight:
            return "SampleWeight";
        case VqImageUsageBit::SampleBlockMatch:
            return "SampleBlockMatch";
        case VqImageUsageBit::TensorAliasingBitArm:
            return "TensorAliasingBitArm";
        case VqImageUsageBit::TileMemory:
            return "TileMemory";
        case VqImageUsageBit::VideoEncodeQuantizationDeltaMap:
            return "VideoEncodeQuantizationDeltaMap";
        case VqImageUsageBit::VideoEncodeEmphasisMap:
            return "VideoEncodeEmphasisMap";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqImageViewCreateBit v)
    {
        switch(v){
        case VqImageViewCreateBit::FragmentDensityMapDynamic:
            return "FragmentDensityMapDynamic";
        case VqImageViewCreateBit::DescriptorBufferCaptureReplay:
            return "DescriptorBufferCaptureReplay";
        case VqImageViewCreateBit::FragmentDensityMapDeferred:
            return "FragmentDensityMapDeferred";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqImageViewType v)
    {
        switch(v){
        case VqImageViewType::_1d:
            return "_1d";
        case VqImageViewType::_2d:
            return "_2d";
        case VqImageViewType::_3d:
            return "_3d";
        case VqImageViewType::Cube:
            return "Cube";
        case VqImageViewType::_1dArray:
            return "_1dArray";
        case VqImageViewType::_2dArray:
            return "_2dArray";
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
        case VqIndexType::Uint8:
            return "Uint8";
        case VqIndexType::None:
            return "None";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqIndirectCommandsInputModeBit v)
    {
        switch(v){
        case VqIndirectCommandsInputModeBit::VulkanIndexBuffer:
            return "VulkanIndexBuffer";
        case VqIndirectCommandsInputModeBit::DxgiIndexBuffer:
            return "DxgiIndexBuffer";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqIndirectCommandsLayoutUsageBit v)
    {
        switch(v){
        case VqIndirectCommandsLayoutUsageBit::ExplicitPreprocess:
            return "ExplicitPreprocess";
        case VqIndirectCommandsLayoutUsageBit::IndexedSequences:
            return "IndexedSequences";
        case VqIndirectCommandsLayoutUsageBit::UnorderedSequences:
            return "UnorderedSequences";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqIndirectCommandsTokenType v)
    {
        switch(v){
        case VqIndirectCommandsTokenType::ShaderGroup:
            return "ShaderGroup";
        case VqIndirectCommandsTokenType::StateFlags:
            return "StateFlags";
        case VqIndirectCommandsTokenType::IndexBuffer:
            return "IndexBuffer";
        case VqIndirectCommandsTokenType::VertexBuffer:
            return "VertexBuffer";
        case VqIndirectCommandsTokenType::PushConstant:
            return "PushConstant";
        case VqIndirectCommandsTokenType::DrawIndexed:
            return "DrawIndexed";
        case VqIndirectCommandsTokenType::Draw:
            return "Draw";
        case VqIndirectCommandsTokenType::DrawTasks:
            return "DrawTasks";
        case VqIndirectCommandsTokenType::DrawMeshTasks:
            return "DrawMeshTasks";
        case VqIndirectCommandsTokenType::Pipeline:
            return "Pipeline";
        case VqIndirectCommandsTokenType::Dispatch:
            return "Dispatch";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqIndirectExecutionSetInfoType v)
    {
        switch(v){
        case VqIndirectExecutionSetInfoType::Pipelines:
            return "Pipelines";
        case VqIndirectExecutionSetInfoType::ShaderObjects:
            return "ShaderObjects";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqIndirectStateBit v)
    {
        switch(v){
        case VqIndirectStateBit::FlagFrontface:
            return "FlagFrontface";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqInstanceCreateBit v)
    {
        switch(v){
        case VqInstanceCreateBit::EnumeratePortability:
            return "EnumeratePortability";
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
        case VqLatencyMarker::SimulationStart:
            return "SimulationStart";
        case VqLatencyMarker::SimulationEnd:
            return "SimulationEnd";
        case VqLatencyMarker::RendersubmitStart:
            return "RendersubmitStart";
        case VqLatencyMarker::RendersubmitEnd:
            return "RendersubmitEnd";
        case VqLatencyMarker::PresentStart:
            return "PresentStart";
        case VqLatencyMarker::PresentEnd:
            return "PresentEnd";
        case VqLatencyMarker::InputSample:
            return "InputSample";
        case VqLatencyMarker::TriggerFlash:
            return "TriggerFlash";
        case VqLatencyMarker::OutOfBandRendersubmitStart:
            return "OutOfBandRendersubmitStart";
        case VqLatencyMarker::OutOfBandRendersubmitEnd:
            return "OutOfBandRendersubmitEnd";
        case VqLatencyMarker::OutOfBandPresentStart:
            return "OutOfBandPresentStart";
        case VqLatencyMarker::OutOfBandPresentEnd:
            return "OutOfBandPresentEnd";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqLayerSettingType v)
    {
        switch(v){
        case VqLayerSettingType::Bool32:
            return "Bool32";
        case VqLayerSettingType::Int32:
            return "Int32";
        case VqLayerSettingType::Int64:
            return "Int64";
        case VqLayerSettingType::Uint32:
            return "Uint32";
        case VqLayerSettingType::Uint64:
            return "Uint64";
        case VqLayerSettingType::Float32:
            return "Float32";
        case VqLayerSettingType::Float64:
            return "Float64";
        case VqLayerSettingType::String:
            return "String";
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
        case VqLineRasterizationMode::Default:
            return "Default";
        case VqLineRasterizationMode::Rectangular:
            return "Rectangular";
        case VqLineRasterizationMode::Bresenham:
            return "Bresenham";
        case VqLineRasterizationMode::RectangularSmooth:
            return "RectangularSmooth";
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

    std::string_view    to_string_view(VqMemoryAllocateBit v)
    {
        switch(v){
        case VqMemoryAllocateBit::DeviceMask:
            return "DeviceMask";
        case VqMemoryAllocateBit::DeviceAddress:
            return "DeviceAddress";
        case VqMemoryAllocateBit::DeviceAddressCaptureReplay:
            return "DeviceAddressCaptureReplay";
        case VqMemoryAllocateBit::ZeroInitialize:
            return "ZeroInitialize";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqMemoryHeapBit v)
    {
        switch(v){
        case VqMemoryHeapBit::DeviceLocal:
            return "DeviceLocal";
        case VqMemoryHeapBit::MultiInstance:
            return "MultiInstance";
        case VqMemoryHeapBit::TileMemory:
            return "TileMemory";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqMemoryMapBit v)
    {
        switch(v){
        case VqMemoryMapBit::Placed:
            return "Placed";
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

    std::string_view    to_string_view(VqMemoryPropertyBit v)
    {
        switch(v){
        case VqMemoryPropertyBit::DeviceLocal:
            return "DeviceLocal";
        case VqMemoryPropertyBit::HostVisible:
            return "HostVisible";
        case VqMemoryPropertyBit::HostCoherent:
            return "HostCoherent";
        case VqMemoryPropertyBit::HostCached:
            return "HostCached";
        case VqMemoryPropertyBit::LazilyAllocated:
            return "LazilyAllocated";
        case VqMemoryPropertyBit::Protected:
            return "Protected";
        case VqMemoryPropertyBit::DeviceCoherentBitAMD:
            return "DeviceCoherentBitAMD";
        case VqMemoryPropertyBit::DeviceUncachedBitAMD:
            return "DeviceUncachedBitAMD";
        case VqMemoryPropertyBit::RdmaCapable:
            return "RdmaCapable";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqMemoryUnmapBit v)
    {
        switch(v){
        case VqMemoryUnmapBit::Reserve:
            return "Reserve";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqMicromapCreateBit v)
    {
        switch(v){
        case VqMicromapCreateBit::DeviceAddressCaptureReplay:
            return "DeviceAddressCaptureReplay";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqMicromapType v)
    {
        switch(v){
        case VqMicromapType::OpacityMicromap:
            return "OpacityMicromap";
        case VqMicromapType::DisplacementMicromap:
            return "DisplacementMicromap";
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
        case VqObjectType::Surface:
            return "Surface";
        case VqObjectType::Swapchain:
            return "Swapchain";
        case VqObjectType::Display:
            return "Display";
        case VqObjectType::DisplayMode:
            return "DisplayMode";
        case VqObjectType::DebugReportCallback:
            return "DebugReportCallback";
        case VqObjectType::VideoSession:
            return "VideoSession";
        case VqObjectType::VideoSessionParameters:
            return "VideoSessionParameters";
        case VqObjectType::CuModuleNvx:
            return "CuModuleNvx";
        case VqObjectType::CuFunctionNvx:
            return "CuFunctionNvx";
        case VqObjectType::DebugUtilsMessenger:
            return "DebugUtilsMessenger";
        case VqObjectType::AccelerationStructure:
            return "AccelerationStructure";
        case VqObjectType::ValidationCache:
            return "ValidationCache";
        case VqObjectType::PerformanceConfigurationINTEL:
            return "PerformanceConfigurationINTEL";
        case VqObjectType::DeferredOperation:
            return "DeferredOperation";
        case VqObjectType::IndirectCommandsLayout:
            return "IndirectCommandsLayout";
        case VqObjectType::CudaModule:
            return "CudaModule";
        case VqObjectType::CudaFunction:
            return "CudaFunction";
        case VqObjectType::BufferCollectionFuchsia:
            return "BufferCollectionFuchsia";
        case VqObjectType::Micromap:
            return "Micromap";
        case VqObjectType::TensorArm:
            return "TensorArm";
        case VqObjectType::TensorViewArm:
            return "TensorViewArm";
        case VqObjectType::OpticalFlowSession:
            return "OpticalFlowSession";
        case VqObjectType::Shader:
            return "Shader";
        case VqObjectType::PipelineBinary:
            return "PipelineBinary";
        case VqObjectType::DataGraphPipelineSessionArm:
            return "DataGraphPipelineSessionArm";
        case VqObjectType::ExternalComputeQueue:
            return "ExternalComputeQueue";
        case VqObjectType::IndirectExecutionSet:
            return "IndirectExecutionSet";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqOpacityMicromapFormat v)
    {
        switch(v){
        case VqOpacityMicromapFormat::_2State:
            return "_2State";
        case VqOpacityMicromapFormat::_4State:
            return "_4State";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqOpacityMicromapSpecialIndex v)
    {
        switch(v){
        case VqOpacityMicromapSpecialIndex::FullyTransparent:
            return "FullyTransparent";
        case VqOpacityMicromapSpecialIndex::FullyOpaque:
            return "FullyOpaque";
        case VqOpacityMicromapSpecialIndex::FullyUnknownTransparent:
            return "FullyUnknownTransparent";
        case VqOpacityMicromapSpecialIndex::FullyUnknownOpaque:
            return "FullyUnknownOpaque";
        case VqOpacityMicromapSpecialIndex::ClusterGeometryDisableOpacityMicromap:
            return "ClusterGeometryDisableOpacityMicromap";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqOpticalFlowExecuteBit v)
    {
        switch(v){
        case VqOpticalFlowExecuteBit::DisableTemporalHints:
            return "DisableTemporalHints";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqOpticalFlowGridSizeBit v)
    {
        switch(v){
        case VqOpticalFlowGridSizeBit::Unknown:
            return "Unknown";
        case VqOpticalFlowGridSizeBit::_1x1:
            return "_1x1";
        case VqOpticalFlowGridSizeBit::_2x2:
            return "_2x2";
        case VqOpticalFlowGridSizeBit::_4x4:
            return "_4x4";
        case VqOpticalFlowGridSizeBit::_8x8:
            return "_8x8";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqOpticalFlowPerformanceLevel v)
    {
        switch(v){
        case VqOpticalFlowPerformanceLevel::Unknown:
            return "Unknown";
        case VqOpticalFlowPerformanceLevel::Slow:
            return "Slow";
        case VqOpticalFlowPerformanceLevel::Medium:
            return "Medium";
        case VqOpticalFlowPerformanceLevel::Fast:
            return "Fast";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqOpticalFlowSessionBindingPoint v)
    {
        switch(v){
        case VqOpticalFlowSessionBindingPoint::Unknown:
            return "Unknown";
        case VqOpticalFlowSessionBindingPoint::Input:
            return "Input";
        case VqOpticalFlowSessionBindingPoint::Reference:
            return "Reference";
        case VqOpticalFlowSessionBindingPoint::Hint:
            return "Hint";
        case VqOpticalFlowSessionBindingPoint::FlowVector:
            return "FlowVector";
        case VqOpticalFlowSessionBindingPoint::BackwardFlowVector:
            return "BackwardFlowVector";
        case VqOpticalFlowSessionBindingPoint::Cost:
            return "Cost";
        case VqOpticalFlowSessionBindingPoint::BackwardCost:
            return "BackwardCost";
        case VqOpticalFlowSessionBindingPoint::GlobalFlow:
            return "GlobalFlow";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqOpticalFlowSessionCreateBit v)
    {
        switch(v){
        case VqOpticalFlowSessionCreateBit::EnableHint:
            return "EnableHint";
        case VqOpticalFlowSessionCreateBit::EnableCost:
            return "EnableCost";
        case VqOpticalFlowSessionCreateBit::EnableGlobalFlow:
            return "EnableGlobalFlow";
        case VqOpticalFlowSessionCreateBit::AllowRegions:
            return "AllowRegions";
        case VqOpticalFlowSessionCreateBit::BothDirections:
            return "BothDirections";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqOpticalFlowUsageBit v)
    {
        switch(v){
        case VqOpticalFlowUsageBit::Unknown:
            return "Unknown";
        case VqOpticalFlowUsageBit::Input:
            return "Input";
        case VqOpticalFlowUsageBit::Output:
            return "Output";
        case VqOpticalFlowUsageBit::Hint:
            return "Hint";
        case VqOpticalFlowUsageBit::Cost:
            return "Cost";
        case VqOpticalFlowUsageBit::GlobalFlow:
            return "GlobalFlow";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqOutOfBandQueueType v)
    {
        switch(v){
        case VqOutOfBandQueueType::Render:
            return "Render";
        case VqOutOfBandQueueType::Present:
            return "Present";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPartitionedAccelerationStructureInstanceBit v)
    {
        switch(v){
        case VqPartitionedAccelerationStructureInstanceBit::FlagTriangleFacingCullDisable:
            return "FlagTriangleFacingCullDisable";
        case VqPartitionedAccelerationStructureInstanceBit::FlagTriangleFlipFacing:
            return "FlagTriangleFlipFacing";
        case VqPartitionedAccelerationStructureInstanceBit::FlagForceOpaque:
            return "FlagForceOpaque";
        case VqPartitionedAccelerationStructureInstanceBit::FlagForceNoOpaque:
            return "FlagForceNoOpaque";
        case VqPartitionedAccelerationStructureInstanceBit::FlagEnableExplicitBoundingBox:
            return "FlagEnableExplicitBoundingBox";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPartitionedAccelerationStructureOpType v)
    {
        switch(v){
        case VqPartitionedAccelerationStructureOpType::WriteInstance:
            return "WriteInstance";
        case VqPartitionedAccelerationStructureOpType::UpdateInstance:
            return "UpdateInstance";
        case VqPartitionedAccelerationStructureOpType::WritePartitionTranslation:
            return "WritePartitionTranslation";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPeerMemoryFeatureBit v)
    {
        switch(v){
        case VqPeerMemoryFeatureBit::CopySrc:
            return "CopySrc";
        case VqPeerMemoryFeatureBit::CopyDst:
            return "CopyDst";
        case VqPeerMemoryFeatureBit::GenericSrc:
            return "GenericSrc";
        case VqPeerMemoryFeatureBit::GenericDst:
            return "GenericDst";
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

    std::string_view    to_string_view(VqPerformanceCounterDescriptionBit v)
    {
        switch(v){
        case VqPerformanceCounterDescriptionBit::PerformanceImpacting:
            return "PerformanceImpacting";
        case VqPerformanceCounterDescriptionBit::ConcurrentlyImpacted:
            return "ConcurrentlyImpacted";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPerformanceCounterScope v)
    {
        switch(v){
        case VqPerformanceCounterScope::CommandBuffer:
            return "CommandBuffer";
        case VqPerformanceCounterScope::RenderPass:
            return "RenderPass";
        case VqPerformanceCounterScope::Command:
            return "Command";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPerformanceCounterStorage v)
    {
        switch(v){
        case VqPerformanceCounterStorage::Int32:
            return "Int32";
        case VqPerformanceCounterStorage::Int64:
            return "Int64";
        case VqPerformanceCounterStorage::Uint32:
            return "Uint32";
        case VqPerformanceCounterStorage::Uint64:
            return "Uint64";
        case VqPerformanceCounterStorage::Float32:
            return "Float32";
        case VqPerformanceCounterStorage::Float64:
            return "Float64";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPerformanceCounterUnit v)
    {
        switch(v){
        case VqPerformanceCounterUnit::Generic:
            return "Generic";
        case VqPerformanceCounterUnit::Percentage:
            return "Percentage";
        case VqPerformanceCounterUnit::Nanoseconds:
            return "Nanoseconds";
        case VqPerformanceCounterUnit::Bytes:
            return "Bytes";
        case VqPerformanceCounterUnit::BytesPerSecond:
            return "BytesPerSecond";
        case VqPerformanceCounterUnit::Kelvin:
            return "Kelvin";
        case VqPerformanceCounterUnit::Watts:
            return "Watts";
        case VqPerformanceCounterUnit::Volts:
            return "Volts";
        case VqPerformanceCounterUnit::Amps:
            return "Amps";
        case VqPerformanceCounterUnit::Hertz:
            return "Hertz";
        case VqPerformanceCounterUnit::Cycles:
            return "Cycles";
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

    std::string_view    to_string_view(VqPhysicalDeviceDataGraphOperationTypeARM v)
    {
        switch(v){
        case VqPhysicalDeviceDataGraphOperationTypeARM::PhysicalDeviceDataGraphOperationTypeSpirvExtendedInstructionSetArm:
            return "PhysicalDeviceDataGraphOperationTypeSpirvExtendedInstructionSetArm";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPhysicalDeviceDataGraphProcessingEngineTypeARM v)
    {
        switch(v){
        case VqPhysicalDeviceDataGraphProcessingEngineTypeARM::PhysicalDeviceDataGraphProcessingEngineTypeDefaultArm:
            return "PhysicalDeviceDataGraphProcessingEngineTypeDefaultArm";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPhysicalDeviceLayeredApi v)
    {
        switch(v){
        case VqPhysicalDeviceLayeredApi::Vulkan:
            return "Vulkan";
        case VqPhysicalDeviceLayeredApi::D3d12:
            return "D3d12";
        case VqPhysicalDeviceLayeredApi::Metal:
            return "Metal";
        case VqPhysicalDeviceLayeredApi::Opengl:
            return "Opengl";
        case VqPhysicalDeviceLayeredApi::Opengles:
            return "Opengles";
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
        case VqPipelineBindPoint::RayTracing:
            return "RayTracing";
        case VqPipelineBindPoint::SubpassShadingHuawei:
            return "SubpassShadingHuawei";
        case VqPipelineBindPoint::DataGraphArm:
            return "DataGraphArm";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineCacheCreateBit v)
    {
        switch(v){
        case VqPipelineCacheCreateBit::ExternallySynchronized:
            return "ExternallySynchronized";
        case VqPipelineCacheCreateBit::InternallySynchronizedMerge:
            return "InternallySynchronizedMerge";
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

    std::string_view    to_string_view(VqPipelineColorBlendStateCreateBit v)
    {
        switch(v){
        case VqPipelineColorBlendStateCreateBit::RasterizationOrderAttachmentAccess:
            return "RasterizationOrderAttachmentAccess";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineCompilerControlBit v)
    {
        switch(v){
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineCreateBit v)
    {
        switch(v){
        case VqPipelineCreateBit::DisableOptimization:
            return "DisableOptimization";
        case VqPipelineCreateBit::AllowDerivatives:
            return "AllowDerivatives";
        case VqPipelineCreateBit::Derivative:
            return "Derivative";
        case VqPipelineCreateBit::ViewIndexFromDeviceIndex:
            return "ViewIndexFromDeviceIndex";
        case VqPipelineCreateBit::DispatchBase:
            return "DispatchBase";
        case VqPipelineCreateBit::FailOnPipelineCompileRequired:
            return "FailOnPipelineCompileRequired";
        case VqPipelineCreateBit::EarlyReturnOnFailure:
            return "EarlyReturnOnFailure";
        case VqPipelineCreateBit::NoProtectedAccess:
            return "NoProtectedAccess";
        case VqPipelineCreateBit::ProtectedAccessOnly:
            return "ProtectedAccessOnly";
        case VqPipelineCreateBit::RayTracingNoNullAnyHitShaders:
            return "RayTracingNoNullAnyHitShaders";
        case VqPipelineCreateBit::RayTracingNoNullClosestHitShaders:
            return "RayTracingNoNullClosestHitShaders";
        case VqPipelineCreateBit::RayTracingNoNullMissShaders:
            return "RayTracingNoNullMissShaders";
        case VqPipelineCreateBit::RayTracingNoNullIntersectionShaders:
            return "RayTracingNoNullIntersectionShaders";
        case VqPipelineCreateBit::RayTracingSkipTriangles:
            return "RayTracingSkipTriangles";
        case VqPipelineCreateBit::RayTracingSkipAabbs:
            return "RayTracingSkipAabbs";
        case VqPipelineCreateBit::RayTracingShaderGroupHandleCaptureReplay:
            return "RayTracingShaderGroupHandleCaptureReplay";
        case VqPipelineCreateBit::DeferCompile:
            return "DeferCompile";
        case VqPipelineCreateBit::RenderingFragmentDensityMapAttachment:
            return "RenderingFragmentDensityMapAttachment";
        case VqPipelineCreateBit::RenderingFragmentShadingRateAttachment:
            return "RenderingFragmentShadingRateAttachment";
        case VqPipelineCreateBit::CaptureStatistics:
            return "CaptureStatistics";
        case VqPipelineCreateBit::CaptureInternalRepresentations:
            return "CaptureInternalRepresentations";
        case VqPipelineCreateBit::IndirectBindable:
            return "IndirectBindable";
        case VqPipelineCreateBit::Library:
            return "Library";
        case VqPipelineCreateBit::DescriptorBuffer:
            return "DescriptorBuffer";
        case VqPipelineCreateBit::RetainLinkTimeOptimizationInfo:
            return "RetainLinkTimeOptimizationInfo";
        case VqPipelineCreateBit::LinkTimeOptimization:
            return "LinkTimeOptimization";
        case VqPipelineCreateBit::RayTracingAllowMotion:
            return "RayTracingAllowMotion";
        case VqPipelineCreateBit::ColorAttachmentFeedbackLoop:
            return "ColorAttachmentFeedbackLoop";
        case VqPipelineCreateBit::DepthStencilAttachmentFeedbackLoop:
            return "DepthStencilAttachmentFeedbackLoop";
        case VqPipelineCreateBit::RayTracingOpacityMicromap:
            return "RayTracingOpacityMicromap";
        case VqPipelineCreateBit::RayTracingDisplacementMicromap:
            return "RayTracingDisplacementMicromap";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineCreationFeedbackBit v)
    {
        switch(v){
        case VqPipelineCreationFeedbackBit::Valid:
            return "Valid";
        case VqPipelineCreationFeedbackBit::ApplicationPipelineCacheHit:
            return "ApplicationPipelineCacheHit";
        case VqPipelineCreationFeedbackBit::BasePipelineAcceleration:
            return "BasePipelineAcceleration";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineDepthStencilStateCreateBit v)
    {
        switch(v){
        case VqPipelineDepthStencilStateCreateBit::RasterizationOrderAttachmentDepthAccess:
            return "RasterizationOrderAttachmentDepthAccess";
        case VqPipelineDepthStencilStateCreateBit::RasterizationOrderAttachmentStencilAccess:
            return "RasterizationOrderAttachmentStencilAccess";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineExecutableStatisticFormat v)
    {
        switch(v){
        case VqPipelineExecutableStatisticFormat::Bool32:
            return "Bool32";
        case VqPipelineExecutableStatisticFormat::Int64:
            return "Int64";
        case VqPipelineExecutableStatisticFormat::Uint64:
            return "Uint64";
        case VqPipelineExecutableStatisticFormat::Float64:
            return "Float64";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineLayoutCreateBit v)
    {
        switch(v){
        case VqPipelineLayoutCreateBit::IndependentSets:
            return "IndependentSets";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineRobustnessBufferBehavior v)
    {
        switch(v){
        case VqPipelineRobustnessBufferBehavior::DeviceDefault:
            return "DeviceDefault";
        case VqPipelineRobustnessBufferBehavior::Disabled:
            return "Disabled";
        case VqPipelineRobustnessBufferBehavior::RobustBufferAccess:
            return "RobustBufferAccess";
        case VqPipelineRobustnessBufferBehavior::RobustBufferAccess2:
            return "RobustBufferAccess2";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineRobustnessImageBehavior v)
    {
        switch(v){
        case VqPipelineRobustnessImageBehavior::DeviceDefault:
            return "DeviceDefault";
        case VqPipelineRobustnessImageBehavior::Disabled:
            return "Disabled";
        case VqPipelineRobustnessImageBehavior::RobustImageAccess:
            return "RobustImageAccess";
        case VqPipelineRobustnessImageBehavior::RobustImageAccess2:
            return "RobustImageAccess2";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineShaderStageCreateBit v)
    {
        switch(v){
        case VqPipelineShaderStageCreateBit::AllowVaryingSubgroupSize:
            return "AllowVaryingSubgroupSize";
        case VqPipelineShaderStageCreateBit::RequireFullSubgroups:
            return "RequireFullSubgroups";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPipelineStageBit v)
    {
        switch(v){
        case VqPipelineStageBit::TopOfPipe:
            return "TopOfPipe";
        case VqPipelineStageBit::DrawIndirect:
            return "DrawIndirect";
        case VqPipelineStageBit::VertexInput:
            return "VertexInput";
        case VqPipelineStageBit::VertexShader:
            return "VertexShader";
        case VqPipelineStageBit::TessellationControlShader:
            return "TessellationControlShader";
        case VqPipelineStageBit::TessellationEvaluationShader:
            return "TessellationEvaluationShader";
        case VqPipelineStageBit::GeometryShader:
            return "GeometryShader";
        case VqPipelineStageBit::FragmentShader:
            return "FragmentShader";
        case VqPipelineStageBit::EarlyFragmentTests:
            return "EarlyFragmentTests";
        case VqPipelineStageBit::LateFragmentTests:
            return "LateFragmentTests";
        case VqPipelineStageBit::ColorAttachmentOutput:
            return "ColorAttachmentOutput";
        case VqPipelineStageBit::ComputeShader:
            return "ComputeShader";
        case VqPipelineStageBit::Transfer:
            return "Transfer";
        case VqPipelineStageBit::BottomOfPipe:
            return "BottomOfPipe";
        case VqPipelineStageBit::Host:
            return "Host";
        case VqPipelineStageBit::AllGraphics:
            return "AllGraphics";
        case VqPipelineStageBit::AllCommands:
            return "AllCommands";
        case VqPipelineStageBit::TransformFeedback:
            return "TransformFeedback";
        case VqPipelineStageBit::ConditionalRendering:
            return "ConditionalRendering";
        case VqPipelineStageBit::AccelerationStructureBuild:
            return "AccelerationStructureBuild";
        case VqPipelineStageBit::RayTracingShader:
            return "RayTracingShader";
        case VqPipelineStageBit::FragmentDensityProcess:
            return "FragmentDensityProcess";
        case VqPipelineStageBit::FragmentShadingRateAttachment:
            return "FragmentShadingRateAttachment";
        case VqPipelineStageBit::TaskShader:
            return "TaskShader";
        case VqPipelineStageBit::MeshShader:
            return "MeshShader";
        case VqPipelineStageBit::CommandPreprocess:
            return "CommandPreprocess";
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
        case VqPolygonMode::FillRectangle:
            return "FillRectangle";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPresentGravityBit v)
    {
        switch(v){
        case VqPresentGravityBit::Min:
            return "Min";
        case VqPresentGravityBit::Max:
            return "Max";
        case VqPresentGravityBit::Centered:
            return "Centered";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPresentMode v)
    {
        switch(v){
        case VqPresentMode::Immediate:
            return "Immediate";
        case VqPresentMode::Mailbox:
            return "Mailbox";
        case VqPresentMode::Fifo:
            return "Fifo";
        case VqPresentMode::FifoRelaxed:
            return "FifoRelaxed";
        case VqPresentMode::SharedDemandRefresh:
            return "SharedDemandRefresh";
        case VqPresentMode::SharedContinuousRefresh:
            return "SharedContinuousRefresh";
        case VqPresentMode::FifoLatestReady:
            return "FifoLatestReady";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqPresentScalingBit v)
    {
        switch(v){
        case VqPresentScalingBit::OneToOne:
            return "OneToOne";
        case VqPresentScalingBit::AspectRatioStretch:
            return "AspectRatioStretch";
        case VqPresentScalingBit::Stretch:
            return "Stretch";
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
        case VqProvokingVertexMode::FirstVertex:
            return "FirstVertex";
        case VqProvokingVertexMode::LastVertex:
            return "LastVertex";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqQueryControlBit v)
    {
        switch(v){
        case VqQueryControlBit::Precise:
            return "Precise";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqQueryPipelineStatisticBit v)
    {
        switch(v){
        case VqQueryPipelineStatisticBit::InputAssemblyVertices:
            return "InputAssemblyVertices";
        case VqQueryPipelineStatisticBit::InputAssemblyPrimitives:
            return "InputAssemblyPrimitives";
        case VqQueryPipelineStatisticBit::VertexShaderInvocations:
            return "VertexShaderInvocations";
        case VqQueryPipelineStatisticBit::GeometryShaderInvocations:
            return "GeometryShaderInvocations";
        case VqQueryPipelineStatisticBit::GeometryShaderPrimitives:
            return "GeometryShaderPrimitives";
        case VqQueryPipelineStatisticBit::ClippingInvocations:
            return "ClippingInvocations";
        case VqQueryPipelineStatisticBit::ClippingPrimitives:
            return "ClippingPrimitives";
        case VqQueryPipelineStatisticBit::FragmentShaderInvocations:
            return "FragmentShaderInvocations";
        case VqQueryPipelineStatisticBit::TessellationControlShaderPatches:
            return "TessellationControlShaderPatches";
        case VqQueryPipelineStatisticBit::TessellationEvaluationShaderInvocations:
            return "TessellationEvaluationShaderInvocations";
        case VqQueryPipelineStatisticBit::ComputeShaderInvocations:
            return "ComputeShaderInvocations";
        case VqQueryPipelineStatisticBit::TaskShaderInvocations:
            return "TaskShaderInvocations";
        case VqQueryPipelineStatisticBit::MeshShaderInvocations:
            return "MeshShaderInvocations";
        case VqQueryPipelineStatisticBit::ClusterCullingShaderInvocationsBitHuawei:
            return "ClusterCullingShaderInvocationsBitHuawei";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqQueryPoolCreateBit v)
    {
        switch(v){
        case VqQueryPoolCreateBit::Reset:
            return "Reset";
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

    std::string_view    to_string_view(VqQueryResultBit v)
    {
        switch(v){
        case VqQueryResultBit::_64:
            return "_64";
        case VqQueryResultBit::Wait:
            return "Wait";
        case VqQueryResultBit::WithAvailability:
            return "WithAvailability";
        case VqQueryResultBit::Partial:
            return "Partial";
        case VqQueryResultBit::WithStatus:
            return "WithStatus";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqQueryResultStatus v)
    {
        switch(v){
        case VqQueryResultStatus::Error:
            return "Error";
        case VqQueryResultStatus::NotReady:
            return "NotReady";
        case VqQueryResultStatus::Complete:
            return "Complete";
        case VqQueryResultStatus::InsufficientBitstreamBufferRange:
            return "InsufficientBitstreamBufferRange";
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
        case VqQueryType::ResultStatusOnly:
            return "ResultStatusOnly";
        case VqQueryType::TransformFeedbackStream:
            return "TransformFeedbackStream";
        case VqQueryType::PerformanceQuery:
            return "PerformanceQuery";
        case VqQueryType::AccelerationStructureCompactedSize:
            return "AccelerationStructureCompactedSize";
        case VqQueryType::AccelerationStructureSerializationSize:
            return "AccelerationStructureSerializationSize";
        case VqQueryType::PerformanceQueryINTEL:
            return "PerformanceQueryINTEL";
        case VqQueryType::VideoEncodeFeedback:
            return "VideoEncodeFeedback";
        case VqQueryType::MeshPrimitivesGenerated:
            return "MeshPrimitivesGenerated";
        case VqQueryType::PrimitivesGenerated:
            return "PrimitivesGenerated";
        case VqQueryType::AccelerationStructureSerializationBottomLevelPointers:
            return "AccelerationStructureSerializationBottomLevelPointers";
        case VqQueryType::AccelerationStructureSize:
            return "AccelerationStructureSize";
        case VqQueryType::MicromapSerializationSize:
            return "MicromapSerializationSize";
        case VqQueryType::MicromapCompactedSize:
            return "MicromapCompactedSize";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqQueueBit v)
    {
        switch(v){
        case VqQueueBit::Graphics:
            return "Graphics";
        case VqQueueBit::Compute:
            return "Compute";
        case VqQueueBit::Transfer:
            return "Transfer";
        case VqQueueBit::SparseBinding:
            return "SparseBinding";
        case VqQueueBit::Protected:
            return "Protected";
        case VqQueueBit::VideoDecode:
            return "VideoDecode";
        case VqQueueBit::VideoEncode:
            return "VideoEncode";
        case VqQueueBit::OpticalFlow:
            return "OpticalFlow";
        case VqQueueBit::DataGraphBitArm:
            return "DataGraphBitArm";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqQueueGlobalPriority v)
    {
        switch(v){
        case VqQueueGlobalPriority::Low:
            return "Low";
        case VqQueueGlobalPriority::Medium:
            return "Medium";
        case VqQueueGlobalPriority::High:
            return "High";
        case VqQueueGlobalPriority::Realtime:
            return "Realtime";
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
        case VqRayTracingInvocationReorderMode::None:
            return "None";
        case VqRayTracingInvocationReorderMode::Reorder:
            return "Reorder";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqRayTracingLssIndexingMode v)
    {
        switch(v){
        case VqRayTracingLssIndexingMode::List:
            return "List";
        case VqRayTracingLssIndexingMode::Successive:
            return "Successive";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqRayTracingLssPrimitiveEndCapsMode v)
    {
        switch(v){
        case VqRayTracingLssPrimitiveEndCapsMode::None:
            return "None";
        case VqRayTracingLssPrimitiveEndCapsMode::Chained:
            return "Chained";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqRayTracingShaderGroupType v)
    {
        switch(v){
        case VqRayTracingShaderGroupType::General:
            return "General";
        case VqRayTracingShaderGroupType::TrianglesHitGroup:
            return "TrianglesHitGroup";
        case VqRayTracingShaderGroupType::ProceduralHitGroup:
            return "ProceduralHitGroup";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqRenderPassCreateBit v)
    {
        switch(v){
        case VqRenderPassCreateBit::Transform:
            return "Transform";
        case VqRenderPassCreateBit::PerLayerFragmentDensityBitValve:
            return "PerLayerFragmentDensityBitValve";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqRenderingBit v)
    {
        switch(v){
        case VqRenderingBit::ContentsSecondaryCommandBuffers:
            return "ContentsSecondaryCommandBuffers";
        case VqRenderingBit::Suspending:
            return "Suspending";
        case VqRenderingBit::Resuming:
            return "Resuming";
        case VqRenderingBit::EnableLegacyDithering:
            return "EnableLegacyDithering";
        case VqRenderingBit::ContentsInline:
            return "ContentsInline";
        case VqRenderingBit::PerLayerFragmentDensityBitValve:
            return "PerLayerFragmentDensityBitValve";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqResolveModeBit v)
    {
        switch(v){
        case VqResolveModeBit::SampleZero:
            return "SampleZero";
        case VqResolveModeBit::Average:
            return "Average";
        case VqResolveModeBit::Min:
            return "Min";
        case VqResolveModeBit::Max:
            return "Max";
        case VqResolveModeBit::ExternalFormatDownsampleBitAndroid:
            return "ExternalFormatDownsampleBitAndroid";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqResult v)
    {
        switch(v){
        case VqResult::Success:
            return "Success";
        case VqResult::NotReady:
            return "NotReady";
        case VqResult::Timeout:
            return "Timeout";
        case VqResult::EventSet:
            return "EventSet";
        case VqResult::EventReset:
            return "EventReset";
        case VqResult::Incomplete:
            return "Incomplete";
        case VqResult::ErrorOutOfHostMemory:
            return "ErrorOutOfHostMemory";
        case VqResult::ErrorOutOfDeviceMemory:
            return "ErrorOutOfDeviceMemory";
        case VqResult::ErrorInitializationFailed:
            return "ErrorInitializationFailed";
        case VqResult::ErrorDeviceLost:
            return "ErrorDeviceLost";
        case VqResult::ErrorMemoryMapFailed:
            return "ErrorMemoryMapFailed";
        case VqResult::ErrorLayerNotPresent:
            return "ErrorLayerNotPresent";
        case VqResult::ErrorExtensionNotPresent:
            return "ErrorExtensionNotPresent";
        case VqResult::ErrorFeatureNotPresent:
            return "ErrorFeatureNotPresent";
        case VqResult::ErrorIncompatibleDriver:
            return "ErrorIncompatibleDriver";
        case VqResult::ErrorTooManyObjects:
            return "ErrorTooManyObjects";
        case VqResult::ErrorFormatNotSupported:
            return "ErrorFormatNotSupported";
        case VqResult::ErrorFragmentedPool:
            return "ErrorFragmentedPool";
        case VqResult::ErrorUnknown:
            return "ErrorUnknown";
        case VqResult::ErrorValidationFailed:
            return "ErrorValidationFailed";
        case VqResult::ErrorOutOfPoolMemory:
            return "ErrorOutOfPoolMemory";
        case VqResult::ErrorInvalidExternalHandle:
            return "ErrorInvalidExternalHandle";
        case VqResult::ErrorFragmentation:
            return "ErrorFragmentation";
        case VqResult::ErrorInvalidOpaqueCaptureAddress:
            return "ErrorInvalidOpaqueCaptureAddress";
        case VqResult::PipelineCompileRequired:
            return "PipelineCompileRequired";
        case VqResult::ErrorNotPermitted:
            return "ErrorNotPermitted";
        case VqResult::ErrorSurfaceLost:
            return "ErrorSurfaceLost";
        case VqResult::ErrorNativeWindowInUse:
            return "ErrorNativeWindowInUse";
        case VqResult::Suboptimal:
            return "Suboptimal";
        case VqResult::ErrorOutOfDate:
            return "ErrorOutOfDate";
        case VqResult::ErrorIncompatibleDisplay:
            return "ErrorIncompatibleDisplay";
        case VqResult::ErrorInvalidShader:
            return "ErrorInvalidShader";
        case VqResult::ErrorImageUsageNotSupported:
            return "ErrorImageUsageNotSupported";
        case VqResult::ErrorVideoPictureLayoutNotSupported:
            return "ErrorVideoPictureLayoutNotSupported";
        case VqResult::ErrorVideoProfileOperationNotSupported:
            return "ErrorVideoProfileOperationNotSupported";
        case VqResult::ErrorVideoProfileFormatNotSupported:
            return "ErrorVideoProfileFormatNotSupported";
        case VqResult::ErrorVideoProfileCodecNotSupported:
            return "ErrorVideoProfileCodecNotSupported";
        case VqResult::ErrorVideoStdVersionNotSupported:
            return "ErrorVideoStdVersionNotSupported";
        case VqResult::ErrorInvalidDrmFormatModifierPlaneLayout:
            return "ErrorInvalidDrmFormatModifierPlaneLayout";
        case VqResult::ErrorFullScreenExclusiveModeLost:
            return "ErrorFullScreenExclusiveModeLost";
        case VqResult::ThreadIdle:
            return "ThreadIdle";
        case VqResult::ThreadDone:
            return "ThreadDone";
        case VqResult::OperationDeferred:
            return "OperationDeferred";
        case VqResult::OperationNotDeferred:
            return "OperationNotDeferred";
        case VqResult::ErrorInvalidVideoStdParameters:
            return "ErrorInvalidVideoStdParameters";
        case VqResult::ErrorCompressionExhausted:
            return "ErrorCompressionExhausted";
        case VqResult::IncompatibleShaderBinary:
            return "IncompatibleShaderBinary";
        case VqResult::PipelineBinaryMissing:
            return "PipelineBinaryMissing";
        case VqResult::ErrorNotEnoughSpace:
            return "ErrorNotEnoughSpace";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSampleCountBit v)
    {
        switch(v){
        case VqSampleCountBit::_1:
            return "_1";
        case VqSampleCountBit::_2:
            return "_2";
        case VqSampleCountBit::_4:
            return "_4";
        case VqSampleCountBit::_8:
            return "_8";
        case VqSampleCountBit::_16:
            return "_16";
        case VqSampleCountBit::_32:
            return "_32";
        case VqSampleCountBit::_64:
            return "_64";
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
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSamplerCreateBit v)
    {
        switch(v){
        case VqSamplerCreateBit::Subsampled:
            return "Subsampled";
        case VqSamplerCreateBit::SubsampledCoarseReconstruction:
            return "SubsampledCoarseReconstruction";
        case VqSamplerCreateBit::DescriptorBufferCaptureReplay:
            return "DescriptorBufferCaptureReplay";
        case VqSamplerCreateBit::NonSeamlessCubeMap:
            return "NonSeamlessCubeMap";
        case VqSamplerCreateBit::ImageProcessing:
            return "ImageProcessing";
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
        case VqSamplerReductionMode::WeightedAverageRangeclamp:
            return "WeightedAverageRangeclamp";
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
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqScope v)
    {
        switch(v){
        case VqScope::Device:
            return "Device";
        case VqScope::Workgroup:
            return "Workgroup";
        case VqScope::Subgroup:
            return "Subgroup";
        case VqScope::QueueFamily:
            return "QueueFamily";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSemaphoreImportBit v)
    {
        switch(v){
        case VqSemaphoreImportBit::Temporary:
            return "Temporary";
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
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSemaphoreWaitBit v)
    {
        switch(v){
        case VqSemaphoreWaitBit::Any:
            return "Any";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqShaderCodeType v)
    {
        switch(v){
        case VqShaderCodeType::Binary:
            return "Binary";
        case VqShaderCodeType::Spirv:
            return "Spirv";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqShaderCorePropertiesBit v)
    {
        switch(v){
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqShaderCreateBit v)
    {
        switch(v){
        case VqShaderCreateBit::LinkStage:
            return "LinkStage";
        case VqShaderCreateBit::AllowVaryingSubgroupSize:
            return "AllowVaryingSubgroupSize";
        case VqShaderCreateBit::RequireFullSubgroups:
            return "RequireFullSubgroups";
        case VqShaderCreateBit::NoTaskShader:
            return "NoTaskShader";
        case VqShaderCreateBit::DispatchBase:
            return "DispatchBase";
        case VqShaderCreateBit::FragmentShadingRateAttachment:
            return "FragmentShadingRateAttachment";
        case VqShaderCreateBit::FragmentDensityMapAttachment:
            return "FragmentDensityMapAttachment";
        case VqShaderCreateBit::IndirectBindable:
            return "IndirectBindable";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqShaderFloatControlsIndependence v)
    {
        switch(v){
        case VqShaderFloatControlsIndependence::_32BitOnly:
            return "_32BitOnly";
        case VqShaderFloatControlsIndependence::All:
            return "All";
        case VqShaderFloatControlsIndependence::None:
            return "None";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqShaderGroupShader v)
    {
        switch(v){
        case VqShaderGroupShader::General:
            return "General";
        case VqShaderGroupShader::ClosestHit:
            return "ClosestHit";
        case VqShaderGroupShader::AnyHit:
            return "AnyHit";
        case VqShaderGroupShader::Intersection:
            return "Intersection";
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

    std::string_view    to_string_view(VqShaderStageBit v)
    {
        switch(v){
        case VqShaderStageBit::Vertex:
            return "Vertex";
        case VqShaderStageBit::TessellationControl:
            return "TessellationControl";
        case VqShaderStageBit::TessellationEvaluation:
            return "TessellationEvaluation";
        case VqShaderStageBit::Geometry:
            return "Geometry";
        case VqShaderStageBit::Fragment:
            return "Fragment";
        case VqShaderStageBit::Compute:
            return "Compute";
        case VqShaderStageBit::All:
            return "All";
        case VqShaderStageBit::Raygen:
            return "Raygen";
        case VqShaderStageBit::AnyHit:
            return "AnyHit";
        case VqShaderStageBit::ClosestHit:
            return "ClosestHit";
        case VqShaderStageBit::Miss:
            return "Miss";
        case VqShaderStageBit::Intersection:
            return "Intersection";
        case VqShaderStageBit::Callable:
            return "Callable";
        case VqShaderStageBit::Task:
            return "Task";
        case VqShaderStageBit::Mesh:
            return "Mesh";
        case VqShaderStageBit::SubpassShadingBitHuawei:
            return "SubpassShadingBitHuawei";
        case VqShaderStageBit::ClusterCullingBitHuawei:
            return "ClusterCullingBitHuawei";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqShadingRatePaletteEntry v)
    {
        switch(v){
        case VqShadingRatePaletteEntry::NoInvocations:
            return "NoInvocations";
        case VqShadingRatePaletteEntry::_16InvocationsPerPixel:
            return "_16InvocationsPerPixel";
        case VqShadingRatePaletteEntry::_8InvocationsPerPixel:
            return "_8InvocationsPerPixel";
        case VqShadingRatePaletteEntry::_4InvocationsPerPixel:
            return "_4InvocationsPerPixel";
        case VqShadingRatePaletteEntry::_2InvocationsPerPixel:
            return "_2InvocationsPerPixel";
        case VqShadingRatePaletteEntry::_1InvocationPerPixel:
            return "_1InvocationPerPixel";
        case VqShadingRatePaletteEntry::_1InvocationPer2x1Pixels:
            return "_1InvocationPer2x1Pixels";
        case VqShadingRatePaletteEntry::_1InvocationPer1x2Pixels:
            return "_1InvocationPer1x2Pixels";
        case VqShadingRatePaletteEntry::_1InvocationPer2x2Pixels:
            return "_1InvocationPer2x2Pixels";
        case VqShadingRatePaletteEntry::_1InvocationPer4x2Pixels:
            return "_1InvocationPer4x2Pixels";
        case VqShadingRatePaletteEntry::_1InvocationPer2x4Pixels:
            return "_1InvocationPer2x4Pixels";
        case VqShadingRatePaletteEntry::_1InvocationPer4x4Pixels:
            return "_1InvocationPer4x4Pixels";
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

    std::string_view    to_string_view(VqSparseImageFormatBit v)
    {
        switch(v){
        case VqSparseImageFormatBit::SingleMiptail:
            return "SingleMiptail";
        case VqSparseImageFormatBit::AlignedMipSize:
            return "AlignedMipSize";
        case VqSparseImageFormatBit::NonstandardBlockSize:
            return "NonstandardBlockSize";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSparseMemoryBindBit v)
    {
        switch(v){
        case VqSparseMemoryBindBit::Metadata:
            return "Metadata";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqStencilFaceBit v)
    {
        switch(v){
        case VqStencilFaceBit::Front:
            return "Front";
        case VqStencilFaceBit::Back:
            return "Back";
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

    std::string_view    to_string_view(VqSubgroupFeatureBit v)
    {
        switch(v){
        case VqSubgroupFeatureBit::Basic:
            return "Basic";
        case VqSubgroupFeatureBit::Vote:
            return "Vote";
        case VqSubgroupFeatureBit::Arithmetic:
            return "Arithmetic";
        case VqSubgroupFeatureBit::Ballot:
            return "Ballot";
        case VqSubgroupFeatureBit::Shuffle:
            return "Shuffle";
        case VqSubgroupFeatureBit::ShuffleRelative:
            return "ShuffleRelative";
        case VqSubgroupFeatureBit::Clustered:
            return "Clustered";
        case VqSubgroupFeatureBit::Quad:
            return "Quad";
        case VqSubgroupFeatureBit::Rotate:
            return "Rotate";
        case VqSubgroupFeatureBit::RotateClustered:
            return "RotateClustered";
        case VqSubgroupFeatureBit::Partitioned:
            return "Partitioned";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSubmitBit v)
    {
        switch(v){
        case VqSubmitBit::Protected:
            return "Protected";
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
        case VqSubpassContents::InlineAndSecondaryCommandBuffers:
            return "InlineAndSecondaryCommandBuffers";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSubpassDescriptionBit v)
    {
        switch(v){
        case VqSubpassDescriptionBit::PerViewAttributesBitNvx:
            return "PerViewAttributesBitNvx";
        case VqSubpassDescriptionBit::PerViewPositionXOnlyBitNvx:
            return "PerViewPositionXOnlyBitNvx";
        case VqSubpassDescriptionBit::FragmentRegion:
            return "FragmentRegion";
        case VqSubpassDescriptionBit::ShaderResolve:
            return "ShaderResolve";
        case VqSubpassDescriptionBit::TileShadingApron:
            return "TileShadingApron";
        case VqSubpassDescriptionBit::RasterizationOrderAttachmentColorAccess:
            return "RasterizationOrderAttachmentColorAccess";
        case VqSubpassDescriptionBit::RasterizationOrderAttachmentDepthAccess:
            return "RasterizationOrderAttachmentDepthAccess";
        case VqSubpassDescriptionBit::RasterizationOrderAttachmentStencilAccess:
            return "RasterizationOrderAttachmentStencilAccess";
        case VqSubpassDescriptionBit::EnableLegacyDithering:
            return "EnableLegacyDithering";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSubpassMergeStatus v)
    {
        switch(v){
        case VqSubpassMergeStatus::Merged:
            return "Merged";
        case VqSubpassMergeStatus::Disallowed:
            return "Disallowed";
        case VqSubpassMergeStatus::NotMergedSideEffects:
            return "NotMergedSideEffects";
        case VqSubpassMergeStatus::NotMergedSamplesMismatch:
            return "NotMergedSamplesMismatch";
        case VqSubpassMergeStatus::NotMergedViewsMismatch:
            return "NotMergedViewsMismatch";
        case VqSubpassMergeStatus::NotMergedAliasing:
            return "NotMergedAliasing";
        case VqSubpassMergeStatus::NotMergedDependencies:
            return "NotMergedDependencies";
        case VqSubpassMergeStatus::NotMergedIncompatibleInputAttachment:
            return "NotMergedIncompatibleInputAttachment";
        case VqSubpassMergeStatus::NotMergedTooManyAttachments:
            return "NotMergedTooManyAttachments";
        case VqSubpassMergeStatus::NotMergedInsufficientStorage:
            return "NotMergedInsufficientStorage";
        case VqSubpassMergeStatus::NotMergedDepthStencilCount:
            return "NotMergedDepthStencilCount";
        case VqSubpassMergeStatus::NotMergedResolveAttachmentReuse:
            return "NotMergedResolveAttachmentReuse";
        case VqSubpassMergeStatus::NotMergedSingleSubpass:
            return "NotMergedSingleSubpass";
        case VqSubpassMergeStatus::NotMergedUnspecified:
            return "NotMergedUnspecified";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSurfaceCounterBit v)
    {
        switch(v){
        case VqSurfaceCounterBit::Vblank:
            return "Vblank";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSurfaceTransformBit v)
    {
        switch(v){
        case VqSurfaceTransformBit::Identity:
            return "Identity";
        case VqSurfaceTransformBit::Rotate90:
            return "Rotate90";
        case VqSurfaceTransformBit::Rotate180:
            return "Rotate180";
        case VqSurfaceTransformBit::Rotate270:
            return "Rotate270";
        case VqSurfaceTransformBit::HorizontalMirror:
            return "HorizontalMirror";
        case VqSurfaceTransformBit::HorizontalMirrorRotate90:
            return "HorizontalMirrorRotate90";
        case VqSurfaceTransformBit::HorizontalMirrorRotate180:
            return "HorizontalMirrorRotate180";
        case VqSurfaceTransformBit::HorizontalMirrorRotate270:
            return "HorizontalMirrorRotate270";
        case VqSurfaceTransformBit::Inherit:
            return "Inherit";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqSwapchainCreateBit v)
    {
        switch(v){
        case VqSwapchainCreateBit::SplitInstanceBindRegions:
            return "SplitInstanceBindRegions";
        case VqSwapchainCreateBit::Protected:
            return "Protected";
        case VqSwapchainCreateBit::MutableFormat:
            return "MutableFormat";
        case VqSwapchainCreateBit::PresentId2:
            return "PresentId2";
        case VqSwapchainCreateBit::PresentWait2:
            return "PresentWait2";
        case VqSwapchainCreateBit::DeferredMemoryAllocation:
            return "DeferredMemoryAllocation";
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

    std::string_view    to_string_view(VqTensorTilingARM v)
    {
        switch(v){
        case VqTensorTilingARM::TensorTilingOptimalArm:
            return "TensorTilingOptimalArm";
        case VqTensorTilingARM::TensorTilingLinearArm:
            return "TensorTilingLinearArm";
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
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqTileShadingRenderPassBit v)
    {
        switch(v){
        case VqTileShadingRenderPassBit::Enable:
            return "Enable";
        case VqTileShadingRenderPassBit::PerTileExecution:
            return "PerTileExecution";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqTimeDomain v)
    {
        switch(v){
        case VqTimeDomain::Device:
            return "Device";
        case VqTimeDomain::ClockMonotonic:
            return "ClockMonotonic";
        case VqTimeDomain::ClockMonotonicRaw:
            return "ClockMonotonicRaw";
        case VqTimeDomain::QueryPerformanceCounter:
            return "QueryPerformanceCounter";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqToolPurposeBit v)
    {
        switch(v){
        case VqToolPurposeBit::Validation:
            return "Validation";
        case VqToolPurposeBit::Profiling:
            return "Profiling";
        case VqToolPurposeBit::Tracing:
            return "Tracing";
        case VqToolPurposeBit::AdditionalFeatures:
            return "AdditionalFeatures";
        case VqToolPurposeBit::ModifyingFeatures:
            return "ModifyingFeatures";
        case VqToolPurposeBit::DebugReporting:
            return "DebugReporting";
        case VqToolPurposeBit::DebugMarkers:
            return "DebugMarkers";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqValidationCacheHeaderVersion v)
    {
        switch(v){
        case VqValidationCacheHeaderVersion::One:
            return "One";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqValidationCheck v)
    {
        switch(v){
        case VqValidationCheck::All:
            return "All";
        case VqValidationCheck::Shaders:
            return "Shaders";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqValidationFeatureDisable v)
    {
        switch(v){
        case VqValidationFeatureDisable::All:
            return "All";
        case VqValidationFeatureDisable::Shaders:
            return "Shaders";
        case VqValidationFeatureDisable::ThreadSafety:
            return "ThreadSafety";
        case VqValidationFeatureDisable::ApiParameters:
            return "ApiParameters";
        case VqValidationFeatureDisable::ObjectLifetimes:
            return "ObjectLifetimes";
        case VqValidationFeatureDisable::CoreChecks:
            return "CoreChecks";
        case VqValidationFeatureDisable::UniqueHandles:
            return "UniqueHandles";
        case VqValidationFeatureDisable::ShaderValidationCache:
            return "ShaderValidationCache";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqValidationFeatureEnable v)
    {
        switch(v){
        case VqValidationFeatureEnable::GpuAssisted:
            return "GpuAssisted";
        case VqValidationFeatureEnable::GpuAssistedReserveBindingSlot:
            return "GpuAssistedReserveBindingSlot";
        case VqValidationFeatureEnable::BestPractices:
            return "BestPractices";
        case VqValidationFeatureEnable::DebugPrintf:
            return "DebugPrintf";
        case VqValidationFeatureEnable::SynchronizationValidation:
            return "SynchronizationValidation";
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

    std::string_view    to_string_view(VqVideoCapabilityBit v)
    {
        switch(v){
        case VqVideoCapabilityBit::ProtectedContent:
            return "ProtectedContent";
        case VqVideoCapabilityBit::SeparateReferenceImages:
            return "SeparateReferenceImages";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoChromaSubsamplingBit v)
    {
        switch(v){
        case VqVideoChromaSubsamplingBit::Invalid:
            return "Invalid";
        case VqVideoChromaSubsamplingBit::Monochrome:
            return "Monochrome";
        case VqVideoChromaSubsamplingBit::_420:
            return "_420";
        case VqVideoChromaSubsamplingBit::_422:
            return "_422";
        case VqVideoChromaSubsamplingBit::_444:
            return "_444";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoCodecOperationBit v)
    {
        switch(v){
        case VqVideoCodecOperationBit::EncodeH264:
            return "EncodeH264";
        case VqVideoCodecOperationBit::EncodeH265:
            return "EncodeH265";
        case VqVideoCodecOperationBit::DecodeH264:
            return "DecodeH264";
        case VqVideoCodecOperationBit::DecodeH265:
            return "DecodeH265";
        case VqVideoCodecOperationBit::DecodeAv1:
            return "DecodeAv1";
        case VqVideoCodecOperationBit::EncodeAv1:
            return "EncodeAv1";
        case VqVideoCodecOperationBit::DecodeVp9:
            return "DecodeVp9";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoCodingControlBit v)
    {
        switch(v){
        case VqVideoCodingControlBit::Reset:
            return "Reset";
        case VqVideoCodingControlBit::EncodeRateControl:
            return "EncodeRateControl";
        case VqVideoCodingControlBit::EncodeQualityLevel:
            return "EncodeQualityLevel";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoComponentBitDepthBit v)
    {
        switch(v){
        case VqVideoComponentBitDepthBit::Invalid:
            return "Invalid";
        case VqVideoComponentBitDepthBit::_8:
            return "_8";
        case VqVideoComponentBitDepthBit::_10:
            return "_10";
        case VqVideoComponentBitDepthBit::_12:
            return "_12";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoDecodeCapabilityBit v)
    {
        switch(v){
        case VqVideoDecodeCapabilityBit::DpbAndOutputCoincide:
            return "DpbAndOutputCoincide";
        case VqVideoDecodeCapabilityBit::DpbAndOutputDistinct:
            return "DpbAndOutputDistinct";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoDecodeH264PictureLayoutBit v)
    {
        switch(v){
        case VqVideoDecodeH264PictureLayoutBit::Progressive:
            return "Progressive";
        case VqVideoDecodeH264PictureLayoutBit::InterlacedInterleavedLines:
            return "InterlacedInterleavedLines";
        case VqVideoDecodeH264PictureLayoutBit::InterlacedSeparatePlanes:
            return "InterlacedSeparatePlanes";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoDecodeUsageBit v)
    {
        switch(v){
        case VqVideoDecodeUsageBit::Default:
            return "Default";
        case VqVideoDecodeUsageBit::Transcoding:
            return "Transcoding";
        case VqVideoDecodeUsageBit::Offline:
            return "Offline";
        case VqVideoDecodeUsageBit::Streaming:
            return "Streaming";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeAV1CapabilityBit v)
    {
        switch(v){
        case VqVideoEncodeAV1CapabilityBit::VideoEncodeAv1CapabilityPerRateControlGroupMinMaxQIndex:
            return "VideoEncodeAv1CapabilityPerRateControlGroupMinMaxQIndex";
        case VqVideoEncodeAV1CapabilityBit::VideoEncodeAv1CapabilityGenerateObuExtensionHeader:
            return "VideoEncodeAv1CapabilityGenerateObuExtensionHeader";
        case VqVideoEncodeAV1CapabilityBit::VideoEncodeAv1CapabilityPrimaryReferenceCdfOnly:
            return "VideoEncodeAv1CapabilityPrimaryReferenceCdfOnly";
        case VqVideoEncodeAV1CapabilityBit::VideoEncodeAv1CapabilityFrameSizeOverride:
            return "VideoEncodeAv1CapabilityFrameSizeOverride";
        case VqVideoEncodeAV1CapabilityBit::VideoEncodeAv1CapabilityMotionVectorScaling:
            return "VideoEncodeAv1CapabilityMotionVectorScaling";
        case VqVideoEncodeAV1CapabilityBit::VideoEncodeAv1CapabilityCompoundPredictionIntraRefresh:
            return "VideoEncodeAv1CapabilityCompoundPredictionIntraRefresh";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeAV1PredictionMode v)
    {
        switch(v){
        case VqVideoEncodeAV1PredictionMode::VideoEncodeAv1PredictionModeIntraOnly:
            return "VideoEncodeAv1PredictionModeIntraOnly";
        case VqVideoEncodeAV1PredictionMode::VideoEncodeAv1PredictionModeSingleReference:
            return "VideoEncodeAv1PredictionModeSingleReference";
        case VqVideoEncodeAV1PredictionMode::VideoEncodeAv1PredictionModeUnidirectionalCompound:
            return "VideoEncodeAv1PredictionModeUnidirectionalCompound";
        case VqVideoEncodeAV1PredictionMode::VideoEncodeAv1PredictionModeBidirectionalCompound:
            return "VideoEncodeAv1PredictionModeBidirectionalCompound";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeAV1RateControlBit v)
    {
        switch(v){
        case VqVideoEncodeAV1RateControlBit::VideoEncodeAv1RateControlRegularGop:
            return "VideoEncodeAv1RateControlRegularGop";
        case VqVideoEncodeAV1RateControlBit::VideoEncodeAv1RateControlTemporalLayerPatternDyadic:
            return "VideoEncodeAv1RateControlTemporalLayerPatternDyadic";
        case VqVideoEncodeAV1RateControlBit::VideoEncodeAv1RateControlReferencePatternFlat:
            return "VideoEncodeAv1RateControlReferencePatternFlat";
        case VqVideoEncodeAV1RateControlBit::VideoEncodeAv1RateControlReferencePatternDyadic:
            return "VideoEncodeAv1RateControlReferencePatternDyadic";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeAV1RateControlGroup v)
    {
        switch(v){
        case VqVideoEncodeAV1RateControlGroup::VideoEncodeAv1RateControlGroupIntra:
            return "VideoEncodeAv1RateControlGroupIntra";
        case VqVideoEncodeAV1RateControlGroup::VideoEncodeAv1RateControlGroupPredictive:
            return "VideoEncodeAv1RateControlGroupPredictive";
        case VqVideoEncodeAV1RateControlGroup::VideoEncodeAv1RateControlGroupBipredictive:
            return "VideoEncodeAv1RateControlGroupBipredictive";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeAV1StdBit v)
    {
        switch(v){
        case VqVideoEncodeAV1StdBit::VideoEncodeAv1StdUniformTileSpacing:
            return "VideoEncodeAv1StdUniformTileSpacing";
        case VqVideoEncodeAV1StdBit::VideoEncodeAv1StdSkipModePresentUnset:
            return "VideoEncodeAv1StdSkipModePresentUnset";
        case VqVideoEncodeAV1StdBit::VideoEncodeAv1StdPrimaryRefFrame:
            return "VideoEncodeAv1StdPrimaryRefFrame";
        case VqVideoEncodeAV1StdBit::VideoEncodeAv1StdDeltaQ:
            return "VideoEncodeAv1StdDeltaQ";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeAV1SuperblockSizeBit v)
    {
        switch(v){
        case VqVideoEncodeAV1SuperblockSizeBit::VideoEncodeAv1SuperblockSize64:
            return "VideoEncodeAv1SuperblockSize64";
        case VqVideoEncodeAV1SuperblockSizeBit::VideoEncodeAv1SuperblockSize128:
            return "VideoEncodeAv1SuperblockSize128";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeCapabilityBit v)
    {
        switch(v){
        case VqVideoEncodeCapabilityBit::PrecedingExternallyEncodedBytes:
            return "PrecedingExternallyEncodedBytes";
        case VqVideoEncodeCapabilityBit::InsufficientBitstreamBufferRangeDetection:
            return "InsufficientBitstreamBufferRangeDetection";
        case VqVideoEncodeCapabilityBit::QuantizationDeltaMap:
            return "QuantizationDeltaMap";
        case VqVideoEncodeCapabilityBit::EmphasisMap:
            return "EmphasisMap";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeContentBit v)
    {
        switch(v){
        case VqVideoEncodeContentBit::Default:
            return "Default";
        case VqVideoEncodeContentBit::Camera:
            return "Camera";
        case VqVideoEncodeContentBit::Desktop:
            return "Desktop";
        case VqVideoEncodeContentBit::Rendered:
            return "Rendered";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeFeedbackBit v)
    {
        switch(v){
        case VqVideoEncodeFeedbackBit::BitstreamBufferOffset:
            return "BitstreamBufferOffset";
        case VqVideoEncodeFeedbackBit::BitstreamBytesWritten:
            return "BitstreamBytesWritten";
        case VqVideoEncodeFeedbackBit::BitstreamHasOverrides:
            return "BitstreamHasOverrides";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeBit v)
    {
        switch(v){
        case VqVideoEncodeBit::IntraRefresh:
            return "IntraRefresh";
        case VqVideoEncodeBit::WithQuantizationDeltaMap:
            return "WithQuantizationDeltaMap";
        case VqVideoEncodeBit::WithEmphasisMap:
            return "WithEmphasisMap";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeH264CapabilityBit v)
    {
        switch(v){
        case VqVideoEncodeH264CapabilityBit::HrdCompliance:
            return "HrdCompliance";
        case VqVideoEncodeH264CapabilityBit::PredictionWeightTableGenerated:
            return "PredictionWeightTableGenerated";
        case VqVideoEncodeH264CapabilityBit::RowUnalignedSlice:
            return "RowUnalignedSlice";
        case VqVideoEncodeH264CapabilityBit::DifferentSliceType:
            return "DifferentSliceType";
        case VqVideoEncodeH264CapabilityBit::BFrameInL0List:
            return "BFrameInL0List";
        case VqVideoEncodeH264CapabilityBit::BFrameInL1List:
            return "BFrameInL1List";
        case VqVideoEncodeH264CapabilityBit::PerPictureTypeMinMaxQp:
            return "PerPictureTypeMinMaxQp";
        case VqVideoEncodeH264CapabilityBit::PerSliceConstantQp:
            return "PerSliceConstantQp";
        case VqVideoEncodeH264CapabilityBit::GeneratePrefixNalu:
            return "GeneratePrefixNalu";
        case VqVideoEncodeH264CapabilityBit::BPictureIntraRefresh:
            return "BPictureIntraRefresh";
        case VqVideoEncodeH264CapabilityBit::MbQpDiffWraparound:
            return "MbQpDiffWraparound";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeH264RateControlBit v)
    {
        switch(v){
        case VqVideoEncodeH264RateControlBit::AttemptHrdCompliance:
            return "AttemptHrdCompliance";
        case VqVideoEncodeH264RateControlBit::RegularGop:
            return "RegularGop";
        case VqVideoEncodeH264RateControlBit::ReferencePatternFlat:
            return "ReferencePatternFlat";
        case VqVideoEncodeH264RateControlBit::ReferencePatternDyadic:
            return "ReferencePatternDyadic";
        case VqVideoEncodeH264RateControlBit::TemporalLayerPatternDyadic:
            return "TemporalLayerPatternDyadic";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeH264StdBit v)
    {
        switch(v){
        case VqVideoEncodeH264StdBit::SeparateColorPlane:
            return "SeparateColorPlane";
        case VqVideoEncodeH264StdBit::QpprimeYZeroTransformBypass:
            return "QpprimeYZeroTransformBypass";
        case VqVideoEncodeH264StdBit::ScalingMatrixPresent:
            return "ScalingMatrixPresent";
        case VqVideoEncodeH264StdBit::ChromaQpIndexOffset:
            return "ChromaQpIndexOffset";
        case VqVideoEncodeH264StdBit::SecondChromaQpIndexOffset:
            return "SecondChromaQpIndexOffset";
        case VqVideoEncodeH264StdBit::PicInitQpMinus26:
            return "PicInitQpMinus26";
        case VqVideoEncodeH264StdBit::WeightedPred:
            return "WeightedPred";
        case VqVideoEncodeH264StdBit::WeightedBipredIdcExplicit:
            return "WeightedBipredIdcExplicit";
        case VqVideoEncodeH264StdBit::WeightedBipredIdcImplicit:
            return "WeightedBipredIdcImplicit";
        case VqVideoEncodeH264StdBit::Transform8x8Mode:
            return "Transform8x8Mode";
        case VqVideoEncodeH264StdBit::DirectSpatialMvPredFlagUnset:
            return "DirectSpatialMvPredFlagUnset";
        case VqVideoEncodeH264StdBit::EntropyCodingModeFlagUnset:
            return "EntropyCodingModeFlagUnset";
        case VqVideoEncodeH264StdBit::EntropyCodingMode:
            return "EntropyCodingMode";
        case VqVideoEncodeH264StdBit::Direct8x8InferenceFlagUnset:
            return "Direct8x8InferenceFlagUnset";
        case VqVideoEncodeH264StdBit::ConstrainedIntraPred:
            return "ConstrainedIntraPred";
        case VqVideoEncodeH264StdBit::DeblockingFilterDisabled:
            return "DeblockingFilterDisabled";
        case VqVideoEncodeH264StdBit::DeblockingFilterEnabled:
            return "DeblockingFilterEnabled";
        case VqVideoEncodeH264StdBit::DeblockingFilterPartial:
            return "DeblockingFilterPartial";
        case VqVideoEncodeH264StdBit::SliceQpDelta:
            return "SliceQpDelta";
        case VqVideoEncodeH264StdBit::DifferentSliceQpDelta:
            return "DifferentSliceQpDelta";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeH265CapabilityBit v)
    {
        switch(v){
        case VqVideoEncodeH265CapabilityBit::HrdCompliance:
            return "HrdCompliance";
        case VqVideoEncodeH265CapabilityBit::PredictionWeightTableGenerated:
            return "PredictionWeightTableGenerated";
        case VqVideoEncodeH265CapabilityBit::RowUnalignedSliceSegment:
            return "RowUnalignedSliceSegment";
        case VqVideoEncodeH265CapabilityBit::DifferentSliceSegmentType:
            return "DifferentSliceSegmentType";
        case VqVideoEncodeH265CapabilityBit::BFrameInL0List:
            return "BFrameInL0List";
        case VqVideoEncodeH265CapabilityBit::BFrameInL1List:
            return "BFrameInL1List";
        case VqVideoEncodeH265CapabilityBit::PerPictureTypeMinMaxQp:
            return "PerPictureTypeMinMaxQp";
        case VqVideoEncodeH265CapabilityBit::PerSliceSegmentConstantQp:
            return "PerSliceSegmentConstantQp";
        case VqVideoEncodeH265CapabilityBit::MultipleTilesPerSliceSegment:
            return "MultipleTilesPerSliceSegment";
        case VqVideoEncodeH265CapabilityBit::MultipleSliceSegmentsPerTile:
            return "MultipleSliceSegmentsPerTile";
        case VqVideoEncodeH265CapabilityBit::BPictureIntraRefresh:
            return "BPictureIntraRefresh";
        case VqVideoEncodeH265CapabilityBit::CuQpDiffWraparound:
            return "CuQpDiffWraparound";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeH265CtbSizeBit v)
    {
        switch(v){
        case VqVideoEncodeH265CtbSizeBit::_16:
            return "_16";
        case VqVideoEncodeH265CtbSizeBit::_32:
            return "_32";
        case VqVideoEncodeH265CtbSizeBit::_64:
            return "_64";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeH265RateControlBit v)
    {
        switch(v){
        case VqVideoEncodeH265RateControlBit::AttemptHrdCompliance:
            return "AttemptHrdCompliance";
        case VqVideoEncodeH265RateControlBit::RegularGop:
            return "RegularGop";
        case VqVideoEncodeH265RateControlBit::ReferencePatternFlat:
            return "ReferencePatternFlat";
        case VqVideoEncodeH265RateControlBit::ReferencePatternDyadic:
            return "ReferencePatternDyadic";
        case VqVideoEncodeH265RateControlBit::TemporalSubLayerPatternDyadic:
            return "TemporalSubLayerPatternDyadic";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeH265StdBit v)
    {
        switch(v){
        case VqVideoEncodeH265StdBit::SeparateColorPlane:
            return "SeparateColorPlane";
        case VqVideoEncodeH265StdBit::SampleAdaptiveOffsetEnabled:
            return "SampleAdaptiveOffsetEnabled";
        case VqVideoEncodeH265StdBit::ScalingListDataPresent:
            return "ScalingListDataPresent";
        case VqVideoEncodeH265StdBit::PcmEnabled:
            return "PcmEnabled";
        case VqVideoEncodeH265StdBit::SpsTemporalMvpEnabled:
            return "SpsTemporalMvpEnabled";
        case VqVideoEncodeH265StdBit::InitQpMinus26:
            return "InitQpMinus26";
        case VqVideoEncodeH265StdBit::WeightedPred:
            return "WeightedPred";
        case VqVideoEncodeH265StdBit::WeightedBipred:
            return "WeightedBipred";
        case VqVideoEncodeH265StdBit::Log2ParallelMergeLevelMinus2:
            return "Log2ParallelMergeLevelMinus2";
        case VqVideoEncodeH265StdBit::SignDataHidingEnabled:
            return "SignDataHidingEnabled";
        case VqVideoEncodeH265StdBit::TransformSkipEnabled:
            return "TransformSkipEnabled";
        case VqVideoEncodeH265StdBit::TransformSkipEnabledFlagUnset:
            return "TransformSkipEnabledFlagUnset";
        case VqVideoEncodeH265StdBit::PpsSliceChromaQpOffsetsPresent:
            return "PpsSliceChromaQpOffsetsPresent";
        case VqVideoEncodeH265StdBit::TransquantBypassEnabled:
            return "TransquantBypassEnabled";
        case VqVideoEncodeH265StdBit::ConstrainedIntraPred:
            return "ConstrainedIntraPred";
        case VqVideoEncodeH265StdBit::EntropyCodingSyncEnabled:
            return "EntropyCodingSyncEnabled";
        case VqVideoEncodeH265StdBit::DeblockingFilterOverrideEnabled:
            return "DeblockingFilterOverrideEnabled";
        case VqVideoEncodeH265StdBit::DependentSliceSegmentsEnabled:
            return "DependentSliceSegmentsEnabled";
        case VqVideoEncodeH265StdBit::DependentSliceSegment:
            return "DependentSliceSegment";
        case VqVideoEncodeH265StdBit::SliceQpDelta:
            return "SliceQpDelta";
        case VqVideoEncodeH265StdBit::DifferentSliceQpDelta:
            return "DifferentSliceQpDelta";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeH265TransformBlockSizeBit v)
    {
        switch(v){
        case VqVideoEncodeH265TransformBlockSizeBit::_4:
            return "_4";
        case VqVideoEncodeH265TransformBlockSizeBit::_8:
            return "_8";
        case VqVideoEncodeH265TransformBlockSizeBit::_16:
            return "_16";
        case VqVideoEncodeH265TransformBlockSizeBit::_32:
            return "_32";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeIntraRefreshModeBit v)
    {
        switch(v){
        case VqVideoEncodeIntraRefreshModeBit::PerPicturePartition:
            return "PerPicturePartition";
        case VqVideoEncodeIntraRefreshModeBit::BlockBased:
            return "BlockBased";
        case VqVideoEncodeIntraRefreshModeBit::BlockRowBased:
            return "BlockRowBased";
        case VqVideoEncodeIntraRefreshModeBit::BlockColumnBased:
            return "BlockColumnBased";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeRateControlModeBit v)
    {
        switch(v){
        case VqVideoEncodeRateControlModeBit::Default:
            return "Default";
        case VqVideoEncodeRateControlModeBit::Disabled:
            return "Disabled";
        case VqVideoEncodeRateControlModeBit::Cbr:
            return "Cbr";
        case VqVideoEncodeRateControlModeBit::Vbr:
            return "Vbr";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeRgbChromaOffsetFlagBitsVALVE v)
    {
        switch(v){
        case VqVideoEncodeRgbChromaOffsetFlagBitsVALVE::VideoEncodeRgbChromaOffsetCositedEvenBitValve:
            return "VideoEncodeRgbChromaOffsetCositedEvenBitValve";
        case VqVideoEncodeRgbChromaOffsetFlagBitsVALVE::VideoEncodeRgbChromaOffsetMidpointBitValve:
            return "VideoEncodeRgbChromaOffsetMidpointBitValve";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeRgbModelConversionFlagBitsVALVE v)
    {
        switch(v){
        case VqVideoEncodeRgbModelConversionFlagBitsVALVE::VideoEncodeRgbModelConversionRgbIdentityBitValve:
            return "VideoEncodeRgbModelConversionRgbIdentityBitValve";
        case VqVideoEncodeRgbModelConversionFlagBitsVALVE::VideoEncodeRgbModelConversionYcbcrIdentityBitValve:
            return "VideoEncodeRgbModelConversionYcbcrIdentityBitValve";
        case VqVideoEncodeRgbModelConversionFlagBitsVALVE::VideoEncodeRgbModelConversionYcbcr709BitValve:
            return "VideoEncodeRgbModelConversionYcbcr709BitValve";
        case VqVideoEncodeRgbModelConversionFlagBitsVALVE::VideoEncodeRgbModelConversionYcbcr601BitValve:
            return "VideoEncodeRgbModelConversionYcbcr601BitValve";
        case VqVideoEncodeRgbModelConversionFlagBitsVALVE::VideoEncodeRgbModelConversionYcbcr2020BitValve:
            return "VideoEncodeRgbModelConversionYcbcr2020BitValve";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeRgbRangeCompressionFlagBitsVALVE v)
    {
        switch(v){
        case VqVideoEncodeRgbRangeCompressionFlagBitsVALVE::VideoEncodeRgbRangeCompressionFullRangeBitValve:
            return "VideoEncodeRgbRangeCompressionFullRangeBitValve";
        case VqVideoEncodeRgbRangeCompressionFlagBitsVALVE::VideoEncodeRgbRangeCompressionNarrowRangeBitValve:
            return "VideoEncodeRgbRangeCompressionNarrowRangeBitValve";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeTuningMode v)
    {
        switch(v){
        case VqVideoEncodeTuningMode::Default:
            return "Default";
        case VqVideoEncodeTuningMode::HighQuality:
            return "HighQuality";
        case VqVideoEncodeTuningMode::LowLatency:
            return "LowLatency";
        case VqVideoEncodeTuningMode::UltraLowLatency:
            return "UltraLowLatency";
        case VqVideoEncodeTuningMode::Lossless:
            return "Lossless";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoEncodeUsageBit v)
    {
        switch(v){
        case VqVideoEncodeUsageBit::Default:
            return "Default";
        case VqVideoEncodeUsageBit::Transcoding:
            return "Transcoding";
        case VqVideoEncodeUsageBit::Streaming:
            return "Streaming";
        case VqVideoEncodeUsageBit::Recording:
            return "Recording";
        case VqVideoEncodeUsageBit::Conferencing:
            return "Conferencing";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoSessionCreateBit v)
    {
        switch(v){
        case VqVideoSessionCreateBit::ProtectedContent:
            return "ProtectedContent";
        case VqVideoSessionCreateBit::AllowEncodeParameterOptimizations:
            return "AllowEncodeParameterOptimizations";
        case VqVideoSessionCreateBit::InlineQueries:
            return "InlineQueries";
        case VqVideoSessionCreateBit::AllowEncodeQuantizationDeltaMap:
            return "AllowEncodeQuantizationDeltaMap";
        case VqVideoSessionCreateBit::AllowEncodeEmphasisMap:
            return "AllowEncodeEmphasisMap";
        case VqVideoSessionCreateBit::InlineSessionParameters:
            return "InlineSessionParameters";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqVideoSessionParametersCreateBit v)
    {
        switch(v){
        case VqVideoSessionParametersCreateBit::QuantizationMapCompatible:
            return "QuantizationMapCompatible";
        default:
            return szUnknown;
        }
    }

    std::string_view    to_string_view(VqViewportCoordinateSwizzle v)
    {
        switch(v){
        case VqViewportCoordinateSwizzle::PositiveX:
            return "PositiveX";
        case VqViewportCoordinateSwizzle::NegativeX:
            return "NegativeX";
        case VqViewportCoordinateSwizzle::PositiveY:
            return "PositiveY";
        case VqViewportCoordinateSwizzle::NegativeY:
            return "NegativeY";
        case VqViewportCoordinateSwizzle::PositiveZ:
            return "PositiveZ";
        case VqViewportCoordinateSwizzle::NegativeZ:
            return "NegativeZ";
        case VqViewportCoordinateSwizzle::PositiveW:
            return "PositiveW";
        case VqViewportCoordinateSwizzle::NegativeW:
            return "NegativeW";
        default:
            return szUnknown;
        }
    }

}
