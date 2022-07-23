////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "preamble.hpp"
#include "Application.ipp"
#include "Camera.ipp"
#include "Editor.ipp"
#include "Event.ipp"
#include "Manipulator.ipp"
#include "Taskable.ipp"
#include "Tool.ipp"
#include "Undo.ipp"
#include "Widget.ipp"

#include "render/BufferObjectInfo.ipp"
#include "render/PipelineBuilder.ipp"
#include "render/PipelineConfig.ipp"
#include "render/PipelineUtils.ipp"

#include <basic/meta/Init.hpp>


#include "vulqan/VqBuffer.ipp"
#include "vulqan/VqCommand.ipp"
#include "vulqan/VqEnums.ipp"
#include "vulqan/VqJoystick.ipp"
#include "vulqan/VqLogging.ipp"
#include "vulqan/VqMonitor.ipp"
#include "vulqan/VqUtils.ipp"



YQ_TYPE_IMPLEMENT(yq::engine::BorderColor)
YQ_TYPE_IMPLEMENT(yq::engine::ColorComponent)
YQ_TYPE_IMPLEMENT(yq::engine::ColorComponentFlags)
YQ_TYPE_IMPLEMENT(yq::engine::ComponentSwizzle)
YQ_TYPE_IMPLEMENT(yq::engine::CullMode)
YQ_TYPE_IMPLEMENT(yq::engine::DataActivity)
YQ_TYPE_IMPLEMENT(yq::engine::DataFormat)
YQ_TYPE_IMPLEMENT(yq::engine::DescriptorType)
YQ_TYPE_IMPLEMENT(yq::engine::FilterType)
YQ_TYPE_IMPLEMENT(yq::engine::FrontFace)
YQ_TYPE_IMPLEMENT(yq::engine::ImageLayout)
YQ_TYPE_IMPLEMENT(yq::engine::ImageTiling)
YQ_TYPE_IMPLEMENT(yq::engine::ImageType)
YQ_TYPE_IMPLEMENT(yq::engine::IndexType)
YQ_TYPE_IMPLEMENT(yq::engine::LogicOp)
YQ_TYPE_IMPLEMENT(yq::engine::MipmapMode)
YQ_TYPE_IMPLEMENT(yq::engine::PolygonMode)
YQ_TYPE_IMPLEMENT(yq::engine::PresentMode)
YQ_TYPE_IMPLEMENT(yq::engine::SamplerAddressMode)
YQ_TYPE_IMPLEMENT(yq::engine::SamplerMipmapMode)
YQ_TYPE_IMPLEMENT(yq::engine::ShaderType)
YQ_TYPE_IMPLEMENT(yq::engine::ShaderTypeFlags)
YQ_TYPE_IMPLEMENT(yq::engine::StencilOp)
YQ_TYPE_IMPLEMENT(yq::engine::SubpassContents)
YQ_TYPE_IMPLEMENT(yq::engine::SystemAllocationScope)
YQ_TYPE_IMPLEMENT(yq::engine::Topology)
YQ_TYPE_IMPLEMENT(yq::engine::Tristate)
