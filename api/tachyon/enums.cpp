////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////


#include <tachyon/api/StdThread.hpp>


#include <tachyon/api/Response.hpp>

#include <tachyon/os/HatState.hpp>
#include <tachyon/os/MouseButton.hpp>
#include <tachyon/os/MouseMode.hpp>
#include <tachyon/os/Platform.hpp>

#include <tachyon/pipeline/BorderColor.hpp>
#include <tachyon/pipeline/BufferUsage.hpp>
#include <tachyon/pipeline/CompareOp.hpp>
#include <tachyon/pipeline/ComponentSwizzle.hpp>
#include <tachyon/pipeline/CullMode.hpp>
#include <tachyon/pipeline/DataActivity.hpp>
#include <tachyon/pipeline/DataFormat.hpp>
#include <tachyon/pipeline/DrawMode.hpp>
#include <tachyon/pipeline/DynamicState.hpp>
#include <tachyon/pipeline/FrontFace.hpp>
#include <tachyon/pipeline/ImageAspect.hpp>
#include <tachyon/pipeline/ImageLayout.hpp>
#include <tachyon/pipeline/ImageTiling.hpp>
#include <tachyon/pipeline/ImageViewCreateFlags.hpp>
#include <tachyon/pipeline/ImageViewType.hpp>
#include <tachyon/pipeline/IndexType.hpp>
#include <tachyon/pipeline/LogicOp.hpp>
#include <tachyon/pipeline/PipelineBinding.hpp>
#include <tachyon/pipeline/PolygonMode.hpp>
#include <tachyon/pipeline/PresentMode.hpp>
#include <tachyon/pipeline/RasterType.hpp>
#include <tachyon/pipeline/SamplerAddressMode.hpp>
#include <tachyon/pipeline/SamplerCreateFlags.hpp>
#include <tachyon/pipeline/SamplerFilter.hpp>
#include <tachyon/pipeline/SamplerMipmapMode.hpp>
#include <tachyon/pipeline/ShaderType.hpp>
#include <tachyon/pipeline/SystemAllocationScope.hpp>
#include <tachyon/pipeline/Topology.hpp>
#include <tachyon/pipeline/VertexInputRate.hpp>

#include <yq/meta/Init.hpp>

YQ_TYPE_IMPLEMENT(yq::tachyon::BorderColor)
YQ_TYPE_IMPLEMENT(yq::tachyon::BufferUsage)
YQ_TYPE_IMPLEMENT(yq::tachyon::BufferUsageFlags)
YQ_TYPE_IMPLEMENT(yq::tachyon::CompareOp)
YQ_TYPE_IMPLEMENT(yq::tachyon::ComponentSwizzle)
YQ_TYPE_IMPLEMENT(yq::tachyon::CullMode)
YQ_TYPE_IMPLEMENT(yq::tachyon::DataActivity)
YQ_TYPE_IMPLEMENT(yq::tachyon::DataFormat)
YQ_TYPE_IMPLEMENT(yq::tachyon::DrawMode)
YQ_TYPE_IMPLEMENT(yq::tachyon::DynamicState)
YQ_TYPE_IMPLEMENT(yq::tachyon::FrontFace)
YQ_TYPE_IMPLEMENT(yq::tachyon::ImageAspect)
YQ_TYPE_IMPLEMENT(yq::tachyon::ImageAspectFlags)
YQ_TYPE_IMPLEMENT(yq::tachyon::ImageLayout)
YQ_TYPE_IMPLEMENT(yq::tachyon::ImageTiling)
YQ_TYPE_IMPLEMENT(yq::tachyon::ImageViewCreateFlag)
YQ_TYPE_IMPLEMENT(yq::tachyon::ImageViewCreateFlags)
YQ_TYPE_IMPLEMENT(yq::tachyon::ImageViewType)
YQ_TYPE_IMPLEMENT(yq::tachyon::IndexType)
YQ_TYPE_IMPLEMENT(yq::tachyon::HatState)
YQ_TYPE_IMPLEMENT(yq::tachyon::LogicOp)
YQ_TYPE_IMPLEMENT(yq::tachyon::MouseButton)
YQ_TYPE_IMPLEMENT(yq::tachyon::MouseButtons)
YQ_TYPE_IMPLEMENT(yq::tachyon::MouseMode)
YQ_TYPE_IMPLEMENT(yq::tachyon::PipelineBinding)
YQ_TYPE_IMPLEMENT(yq::tachyon::Platform)
YQ_TYPE_IMPLEMENT(yq::tachyon::PolygonMode)
YQ_TYPE_IMPLEMENT(yq::tachyon::PresentMode)
YQ_TYPE_IMPLEMENT(yq::tachyon::RasterType)
YQ_TYPE_IMPLEMENT(yq::tachyon::Response)
YQ_TYPE_IMPLEMENT(yq::tachyon::SamplerAddressMode)
YQ_TYPE_IMPLEMENT(yq::tachyon::SamplerCreateFlag)
YQ_TYPE_IMPLEMENT(yq::tachyon::SamplerCreateFlags)
YQ_TYPE_IMPLEMENT(yq::tachyon::SamplerFilter)
YQ_TYPE_IMPLEMENT(yq::tachyon::SamplerMipmapMode)
YQ_TYPE_IMPLEMENT(yq::tachyon::ShaderType)
YQ_TYPE_IMPLEMENT(yq::tachyon::ShaderTypeFlags)
YQ_TYPE_IMPLEMENT(yq::tachyon::StdThread)
YQ_TYPE_IMPLEMENT(yq::tachyon::SystemAllocationScope)
YQ_TYPE_IMPLEMENT(yq::tachyon::SystemAllocationScopeFlags)
YQ_TYPE_IMPLEMENT(yq::tachyon::Topology)
YQ_TYPE_IMPLEMENT(yq::tachyon::VertexInputRate)


