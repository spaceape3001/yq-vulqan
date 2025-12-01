////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////


#include <yq/tachyon/api/StdThread.hpp>


#include <yq/tachyon/api/Response.hpp>

#include <yq/tachyon/enum/AxisRemap.hpp>
#include <yq/tachyon/enum/RenderMode.hpp>

#include <yq/tachyon/os/HatState.hpp>
#include <yq/tachyon/os/MouseButton.hpp>
#include <yq/tachyon/os/MouseMode.hpp>
#include <yq/tachyon/os/Platform.hpp>

#include <yq/tachyon/pipeline/BorderColor.hpp>
#include <yq/tachyon/pipeline/BufferUsage.hpp>
#include <yq/tachyon/pipeline/CompareOp.hpp>
#include <yq/tachyon/pipeline/ComponentSwizzle.hpp>
#include <yq/tachyon/pipeline/CullMode.hpp>
#include <yq/tachyon/pipeline/DataActivity.hpp>
#include <yq/tachyon/pipeline/DataFormat.hpp>
#include <yq/tachyon/pipeline/DrawMode.hpp>
#include <yq/tachyon/pipeline/DynamicState.hpp>
#include <yq/tachyon/pipeline/FrontFace.hpp>
#include <yq/tachyon/pipeline/ImageAspect.hpp>
#include <yq/tachyon/pipeline/ImageLayout.hpp>
#include <yq/tachyon/pipeline/ImageTiling.hpp>
#include <yq/tachyon/pipeline/ImageViewCreateFlags.hpp>
#include <yq/tachyon/pipeline/ImageViewType.hpp>
#include <yq/tachyon/pipeline/IndexType.hpp>
#include <yq/tachyon/pipeline/LogicOp.hpp>
#include <yq/tachyon/pipeline/PipelineBinding.hpp>
#include <yq/tachyon/pipeline/PolygonMode.hpp>
#include <yq/tachyon/pipeline/PresentMode.hpp>
#include <yq/tachyon/pipeline/RasterType.hpp>
#include <yq/tachyon/pipeline/SamplerAddressMode.hpp>
#include <yq/tachyon/pipeline/SamplerCreateFlags.hpp>
#include <yq/tachyon/pipeline/SamplerFilter.hpp>
#include <yq/tachyon/pipeline/SamplerMipmapMode.hpp>
#include <yq/tachyon/pipeline/ShaderType.hpp>
#include <yq/tachyon/pipeline/SystemAllocationScope.hpp>
#include <yq/tachyon/pipeline/Topology.hpp>
#include <yq/tachyon/pipeline/VertexInputRate.hpp>

#include <yq/meta/Init.hpp>

YQ_TYPE_IMPLEMENT(yq::tachyon::AxisRemap)
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
YQ_TYPE_IMPLEMENT(yq::tachyon::RenderMode)
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


