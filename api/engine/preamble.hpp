////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <sys/types.h>
#include <basic/Enum.hpp>
#include <basic/Flag.hpp>
#include <basic/Ref.hpp>
#include <basic/meta/InfoBinder.hpp>
#include <string>
#include <variant>

#include <engine/enum/BorderColor.hpp>
#include <engine/enum/ColorComponent.hpp>
#include <engine/enum/ComponentSwizzle.hpp>
#include <engine/enum/CullMode.hpp>
#include <engine/enum/DataActivity.hpp>
#include <engine/enum/DataFormat.hpp>
#include <engine/enum/DescriptorType.hpp>
#include <engine/enum/FilterType.hpp>
#include <engine/enum/FrontFace.hpp>
#include <engine/enum/ImageLayout.hpp>
#include <engine/enum/ImageTiling.hpp>
#include <engine/enum/ImageType.hpp>
#include <engine/enum/IndexType.hpp>
#include <engine/enum/LogicOp.hpp>
#include <engine/enum/MipmapMode.hpp>
#include <engine/enum/PolygonMode.hpp>
#include <engine/enum/PresentMode.hpp>
#include <engine/enum/PushConfigType.hpp>
#include <engine/enum/Required.hpp>
#include <engine/enum/SamplerAddressMode.hpp>
#include <engine/enum/SamplerMipmapMode.hpp>
#include <engine/enum/ShaderType.hpp>
#include <engine/enum/StencilOp.hpp>
#include <engine/enum/SubpassContents.hpp>
#include <engine/enum/SystemAllocationScope.hpp>
#include <engine/enum/Topology.hpp>
#include <engine/enum/Tristate.hpp>
#include <engine/enum/VertexInputRate.hpp>

namespace yq {
    namespace engine {
        static constexpr const size_t   MAX_PUSH                = 256;
        static constexpr const size_t   MAX_FRAMES_IN_FLIGHT    = 2;
        static constexpr const uint32_t MIN_DESCRIPTOR_COUNT    = 1024;

        class Asset;
        class AssetInfo;
        class AssetLoader;
        
        class Camera;
        using CameraPtr     = Ref<Camera>;
        using CameraCPtr    = Ref<const Camera>;
        
        class Event;
        
        class Manipulator;
        using ManipulatorPtr    = Ref<Manipulator>;
        
        struct ResultCC;
        
        class Shader;
        using ShaderCPtr        = Ref<const Shader>;
        using ShaderSpec        = std::variant<std::monostate, std::string, ShaderCPtr>;
        
        class Taskable;
        class TaskableInfo;

        class Texture;
        using TexturePtr    = Ref<const Texture>;
        
        class Viewer;
        class Visualizer;
    }
}


