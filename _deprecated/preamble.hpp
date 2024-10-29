////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <sys/types.h>
#include <yq-toolbox/basic/Enum.hpp>
#include <yq-toolbox/basic/Flag.hpp>
#include <yq-toolbox/basic/Ref.hpp>
#include <yq-toolbox/meta/InfoBinder.hpp>
#include <string>
#include <variant>

#include <yq/tachyon/preamble.hpp>

namespace yq::engine {
    class Event;
    
    class Manipulator;
    using ManipulatorPtr    = Ref<Manipulator>;
    
    class Taskable;
    class TaskableInfo;

    class Viewer;
    class Visualizer;
}

