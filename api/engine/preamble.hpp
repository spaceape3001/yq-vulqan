////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <sys/types.h>
#include <yq/basic/Enum.hpp>
#include <yq/basic/Flag.hpp>
#include <yq/basic/Ref.hpp>
#include <yq/meta/InfoBinder.hpp>
#include <string>
#include <variant>

#include <tachyon/preamble.hpp>

namespace yq::engine {
    class Event;
    
    class Manipulator;
    using ManipulatorPtr    = Ref<Manipulator>;
    
    class Taskable;
    class TaskableInfo;

    class Viewer;
    class Visualizer;
}

