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

#include <tachyon/preamble.hpp>

namespace yq {
    namespace engine {

        class Camera;
        using CameraPtr     = Ref<Camera>;
        using CameraCPtr    = Ref<const Camera>;
        
        class Event;
        
        class Manipulator;
        using ManipulatorPtr    = Ref<Manipulator>;
        
        class Taskable;
        class TaskableInfo;

        class Viewer;
        class Visualizer;
    }
}


