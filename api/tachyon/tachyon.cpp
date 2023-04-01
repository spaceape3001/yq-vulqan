////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

/*
    Vulqan is the adapter to the vulkan driver.  Even though there's a lot of overlap, these
    are our C++ adapters for it.
*/

#include "host/Monitor.ipp"
#include "host/VideoMode.ipp"

#include "gpu/VqStructs.hpp"
#include "gpu/VqLogging.ipp"
#include "gpu/Visualizer.ipp"

#include "Viewer.ipp"

#include <tachyon/enum/BorderColor.hpp>
#include <tachyon/enum/ColorComponent.hpp>
#include <tachyon/enum/ComponentSwizzle.hpp>
#include <tachyon/enum/CullMode.hpp>
#include <tachyon/enum/DataActivity.hpp>
#include <tachyon/enum/DataFormat.hpp>
#include <tachyon/enum/DescriptorType.hpp>
#include <tachyon/enum/FilterType.hpp>
#include <tachyon/enum/FrontFace.hpp>
#include <tachyon/enum/ImageLayout.hpp>
#include <tachyon/enum/ImageTiling.hpp>
#include <tachyon/enum/ImageType.hpp>
#include <tachyon/enum/IndexType.hpp>
#include <tachyon/enum/LogicOp.hpp>
#include <tachyon/enum/MipmapMode.hpp>
#include <tachyon/enum/PolygonMode.hpp>
#include <tachyon/enum/PresentMode.hpp>
//#include <tachyon/enum/PushConfigType.hpp>
#include <tachyon/enum/Required.hpp>
#include <tachyon/enum/SamplerAddressMode.hpp>
#include <tachyon/enum/SamplerMipmapMode.hpp>
#include <tachyon/enum/ShaderType.hpp>
#include <tachyon/enum/StencilOp.hpp>
#include <tachyon/enum/SubpassContents.hpp>
#include <tachyon/enum/SystemAllocationScope.hpp>
#include <tachyon/enum/Topology.hpp>
#include <tachyon/enum/Tristate.hpp>
#include <tachyon/enum/VertexInputRate.hpp>

#include <basic/meta/Init.hpp>

YQ_TYPE_IMPLEMENT(yq::tachyon::BorderColor)
YQ_TYPE_IMPLEMENT(yq::tachyon::ColorComponent)
YQ_TYPE_IMPLEMENT(yq::tachyon::ColorComponentFlags)
YQ_TYPE_IMPLEMENT(yq::tachyon::ComponentSwizzle)
YQ_TYPE_IMPLEMENT(yq::tachyon::CullMode)
YQ_TYPE_IMPLEMENT(yq::tachyon::DataActivity)
YQ_TYPE_IMPLEMENT(yq::tachyon::DataFormat)
YQ_TYPE_IMPLEMENT(yq::tachyon::DescriptorType)
YQ_TYPE_IMPLEMENT(yq::tachyon::FilterType)
YQ_TYPE_IMPLEMENT(yq::tachyon::FrontFace)
YQ_TYPE_IMPLEMENT(yq::tachyon::ImageLayout)
YQ_TYPE_IMPLEMENT(yq::tachyon::ImageTiling)
YQ_TYPE_IMPLEMENT(yq::tachyon::ImageType)
YQ_TYPE_IMPLEMENT(yq::tachyon::IndexType)
YQ_TYPE_IMPLEMENT(yq::tachyon::LogicOp)
YQ_TYPE_IMPLEMENT(yq::tachyon::MipmapMode)
YQ_TYPE_IMPLEMENT(yq::tachyon::PolygonMode)
YQ_TYPE_IMPLEMENT(yq::tachyon::PresentMode)
YQ_TYPE_IMPLEMENT(yq::tachyon::SamplerAddressMode)
YQ_TYPE_IMPLEMENT(yq::tachyon::SamplerMipmapMode)
YQ_TYPE_IMPLEMENT(yq::tachyon::ShaderType)
YQ_TYPE_IMPLEMENT(yq::tachyon::ShaderTypeFlags)
YQ_TYPE_IMPLEMENT(yq::tachyon::StencilOp)
YQ_TYPE_IMPLEMENT(yq::tachyon::SubpassContents)
YQ_TYPE_IMPLEMENT(yq::tachyon::SystemAllocationScope)
YQ_TYPE_IMPLEMENT(yq::tachyon::Topology)
YQ_TYPE_IMPLEMENT(yq::tachyon::Tristate)