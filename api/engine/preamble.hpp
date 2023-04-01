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

#include <engine/enum/PushConfigType.hpp>

namespace yq {
    namespace engine {
        static constexpr const size_t   MAX_PUSH                = 256;
        static constexpr const size_t   MAX_FRAMES_IN_FLIGHT    = 2;
        static constexpr const uint32_t MIN_DESCRIPTOR_COUNT    = 1024;

        class Camera;
        using CameraPtr     = Ref<Camera>;
        using CameraCPtr    = Ref<const Camera>;
        
        class Event;
        
        class Manipulator;
        using ManipulatorPtr    = Ref<Manipulator>;
        
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


