////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <sys/types.h>
#include <0/basic/Enum.hpp>
#include <0/basic/Flag.hpp>
#include <0/basic/Ref.hpp>
#include <0/meta/InfoBinder.hpp>
#include <string>
#include <variant>

#include <tachyon/preamble.hpp>

namespace yq {
    namespace engine {
        class Event;
        
        class Manipulator;
        using ManipulatorPtr    = Ref<Manipulator>;
        
        class Taskable;
        class TaskableInfo;

        class Viewer;
        class Visualizer;
    }
}


