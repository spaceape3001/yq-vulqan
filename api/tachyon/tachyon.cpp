////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

/*
    Vulqan is the adapter to the vulkan driver.  Even though there's a lot of overlap, these
    are our C++ adapters for it.
*/


#include "Application.ipp"
#include "Buffer.ipp"
#include "Viewer.ipp"
#include "Widget.ipp"

#include "asset/camera/NullCamera.ipp"
#include "asset/camera/SpaceCamera.ipp"
#include "asset/camera/TargetCamera.ipp"
#include "asset/render/Quadrilateral.ipp"
#include "asset/render/Tetrahedron.ipp"
#include "asset/render/Triangle.ipp"

#include "core/Asset.ipp"
#include "core/AssetCache.ipp"
#include "core/AssetFactory.ipp"
#include "core/Memory.ipp"

#include "enum/KeyCode.ipp"

#include "gpu/ViBO.ipp"
#include "gpu/ViThing.ipp"
#include "gpu/VqApp.ipp"
#include "gpu/VqEnums.ipp"
#include "gpu/VqLogging.ipp"
#include "gpu/VqStructs.hpp"
#include "gpu/VqUtils.ipp"


#include "host/AppGLFW.ipp"
#include "host/Joystick.ipp"
#include "host/Monitor.ipp"
#include "host/VideoMode.ipp"
#include "host/Window.ipp"

#include "task/Task.ipp"
#include "task/TaskEngine.ipp"

#include "viz/BufferObject.ipp"
#include "viz/Image.ipp"
#include "viz/Shader.ipp"

#include "scene/Camera.ipp"
#include "scene/Perspective.ipp"
#include "scene/Render3D.ipp"
#include "scene/Rendered.ipp"

#include "viz/GLSLShader.ipp"
#include "viz/Pipeline.ipp"
#include "viz/PipelineUtils.ipp"
#include "viz/PipelineBuilder.ipp"
#include "viz/PipelineConfig.ipp"
#include "viz/STBImage.ipp"

#include "ui/Editor.ipp"

#include "widget/ImGuiDemo.ipp"
#include "widget/Scene3D.ipp"
#include "widget/Stacked.ipp"

#include <tachyon/enum/BorderColor.hpp>
#include <tachyon/enum/BufferUsage.hpp>
#include <tachyon/enum/ColorComponent.hpp>
#include <tachyon/enum/CompareOp.hpp>
#include <tachyon/enum/ComponentSwizzle.hpp>
#include <tachyon/enum/CullMode.hpp>
#include <tachyon/enum/DataActivity.hpp>
#include <tachyon/enum/DataFormat.hpp>
#include <tachyon/enum/DescriptorType.hpp>
#include <tachyon/enum/FrontFace.hpp>
#include <tachyon/enum/ImageAspect.hpp>
#include <tachyon/enum/ImageLayout.hpp>
#include <tachyon/enum/ImageTiling.hpp>
#include <tachyon/enum/ImageType.hpp>
#include <tachyon/enum/ImageViewCreateFlags.hpp>
#include <tachyon/enum/ImageViewType.hpp>
#include <tachyon/enum/IndexType.hpp>
#include <tachyon/enum/KeyCode.hpp>
#include <tachyon/enum/LogicOp.hpp>
#include <tachyon/enum/MipmapMode.hpp>
#include <tachyon/enum/ModifierKey.hpp>
#include <tachyon/enum/PipelineBinding.hpp>
#include <tachyon/enum/PolygonMode.hpp>
#include <tachyon/enum/PresentMode.hpp>
//#include <tachyon/enum/PushConfigType.hpp>
#include <tachyon/enum/Required.hpp>
#include <tachyon/enum/SamplerAddressMode.hpp>
#include <tachyon/enum/SamplerCreateFlags.hpp>
#include <tachyon/enum/SamplerFilter.hpp>
#include <tachyon/enum/SamplerMipmapMode.hpp>
#include <tachyon/enum/ShaderType.hpp>
#include <tachyon/enum/StencilOp.hpp>
#include <tachyon/enum/SubpassContents.hpp>
#include <tachyon/enum/SystemAllocationScope.hpp>
#include <tachyon/enum/Topology.hpp>
#include <tachyon/enum/Tristate.hpp>
#include <tachyon/enum/VertexInputRate.hpp>

#include <meta/Init.hpp>

#include <math/shape/Size2.hxx>
#include <math/shape/Rectangle2.hxx>
#include <math/vector/Tensor44.hxx>
#include <math/vector/Vector3.hxx>


YQ_TYPE_IMPLEMENT(yq::tachyon::BorderColor)
YQ_TYPE_IMPLEMENT(yq::tachyon::BufferUsage)
YQ_TYPE_IMPLEMENT(yq::tachyon::BufferUsageFlags)
YQ_TYPE_IMPLEMENT(yq::tachyon::ColorComponent)
YQ_TYPE_IMPLEMENT(yq::tachyon::ColorComponentFlags)
YQ_TYPE_IMPLEMENT(yq::tachyon::CompareOp)
YQ_TYPE_IMPLEMENT(yq::tachyon::ComponentSwizzle)
YQ_TYPE_IMPLEMENT(yq::tachyon::CullMode)
YQ_TYPE_IMPLEMENT(yq::tachyon::DataActivity)
YQ_TYPE_IMPLEMENT(yq::tachyon::DataFormat)
YQ_TYPE_IMPLEMENT(yq::tachyon::DescriptorType)
YQ_TYPE_IMPLEMENT(yq::tachyon::FrontFace)
YQ_TYPE_IMPLEMENT(yq::tachyon::ImageAspect)
YQ_TYPE_IMPLEMENT(yq::tachyon::ImageLayout)
YQ_TYPE_IMPLEMENT(yq::tachyon::ImageTiling)
YQ_TYPE_IMPLEMENT(yq::tachyon::ImageType)
YQ_TYPE_IMPLEMENT(yq::tachyon::ImageViewCreateFlag)
YQ_TYPE_IMPLEMENT(yq::tachyon::ImageViewCreateFlags)
YQ_TYPE_IMPLEMENT(yq::tachyon::ImageViewType)
YQ_TYPE_IMPLEMENT(yq::tachyon::IndexType)
YQ_TYPE_IMPLEMENT(yq::tachyon::KeyCode)
YQ_TYPE_IMPLEMENT(yq::tachyon::LogicOp)
YQ_TYPE_IMPLEMENT(yq::tachyon::MipmapMode)
YQ_TYPE_IMPLEMENT(yq::tachyon::ModifierKey)
YQ_TYPE_IMPLEMENT(yq::tachyon::ModifierKeys)
YQ_TYPE_IMPLEMENT(yq::tachyon::PipelineBinding)
YQ_TYPE_IMPLEMENT(yq::tachyon::PolygonMode)
YQ_TYPE_IMPLEMENT(yq::tachyon::PresentMode)
YQ_TYPE_IMPLEMENT(yq::tachyon::SamplerAddressMode)
YQ_TYPE_IMPLEMENT(yq::tachyon::SamplerCreateFlag)
YQ_TYPE_IMPLEMENT(yq::tachyon::SamplerCreateFlags)
YQ_TYPE_IMPLEMENT(yq::tachyon::SamplerFilter)
YQ_TYPE_IMPLEMENT(yq::tachyon::SamplerMipmapMode)
YQ_TYPE_IMPLEMENT(yq::tachyon::ShaderType)
YQ_TYPE_IMPLEMENT(yq::tachyon::ShaderTypeFlags)
YQ_TYPE_IMPLEMENT(yq::tachyon::StencilOp)
YQ_TYPE_IMPLEMENT(yq::tachyon::SubpassContents)
YQ_TYPE_IMPLEMENT(yq::tachyon::SystemAllocationScope)
YQ_TYPE_IMPLEMENT(yq::tachyon::Topology)
YQ_TYPE_IMPLEMENT(yq::tachyon::Tristate)
