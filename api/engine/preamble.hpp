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
#include <meta/InfoBinder.hpp>
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


