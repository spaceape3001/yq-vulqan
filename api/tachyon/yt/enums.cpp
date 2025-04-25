////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////


#include <yt/api/StdThread.hpp>

#include <tachyon/gfx/BorderColor.hpp>
#include <tachyon/gfx/BufferUsage.hpp>
#include <tachyon/gfx/CompareOp.hpp>
#include <tachyon/gfx/ComponentSwizzle.hpp>
#include <tachyon/gfx/CullMode.hpp>
#include <tachyon/gfx/DataActivity.hpp>
#include <tachyon/gfx/DataFormat.hpp>
#include <tachyon/gfx/DynamicState.hpp>
#include <tachyon/gfx/FrontFace.hpp>
#include <tachyon/gfx/ImageAspect.hpp>
#include <tachyon/gfx/ImageLayout.hpp>
#include <tachyon/gfx/ImageTiling.hpp>
#include <tachyon/gfx/ImageViewCreateFlags.hpp>
#include <tachyon/gfx/ImageViewType.hpp>
#include <tachyon/gfx/IndexType.hpp>
#include <tachyon/gfx/LogicOp.hpp>
#include <tachyon/gfx/PipelineBinding.hpp>
#include <tachyon/gfx/PolygonMode.hpp>
#include <tachyon/gfx/PresentMode.hpp>
#include <tachyon/gfx/RasterType.hpp>
#include <tachyon/gfx/SamplerAddressMode.hpp>
#include <tachyon/gfx/SamplerCreateFlags.hpp>
#include <tachyon/gfx/SamplerFilter.hpp>
#include <tachyon/gfx/SamplerMipmapMode.hpp>
#include <tachyon/gfx/ShaderType.hpp>
#include <tachyon/gfx/SystemAllocationScope.hpp>
#include <tachyon/gfx/Topology.hpp>
#include <tachyon/gfx/VertexInputRate.hpp>

#include <yt/msg/Response.hpp>

#include <yt/os/HatState.hpp>
#include <yt/os/MouseButton.hpp>
#include <yt/os/MouseMode.hpp>
#include <yt/os/Platform.hpp>

#include <yq/meta/Init.hpp>

YQ_TYPE_IMPLEMENT(yq::tachyon::BorderColor)
YQ_TYPE_IMPLEMENT(yq::tachyon::BufferUsage)
YQ_TYPE_IMPLEMENT(yq::tachyon::BufferUsageFlags)
YQ_TYPE_IMPLEMENT(yq::tachyon::CompareOp)
YQ_TYPE_IMPLEMENT(yq::tachyon::ComponentSwizzle)
YQ_TYPE_IMPLEMENT(yq::tachyon::CullMode)
YQ_TYPE_IMPLEMENT(yq::tachyon::DataActivity)
YQ_TYPE_IMPLEMENT(yq::tachyon::DataFormat)
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


