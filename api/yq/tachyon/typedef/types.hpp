////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Flags.hpp>

namespace yq::tachyon {

    /*
        This is meant for *FAST* type detection in the tachyon, should be 
        kept small... switch the actual type as we grow, until then...
    */
    
    enum class Type : uint8_t {
        Camera,
        Editor,
        ImGui,
        Manager,
        Rendered,
        Thread,
        Viewer,
        Visualizer,
        Widget
    };
    
    using Types = Flags<Type, uint32_t>;
}
