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
        Camera³,
        Controller,
        Cursor,
        Desktop,
        Editor,
        ImGui,
        Joystick,
        Keyboard,
        Light,
        Light³,
        Manager,
        Model,
        Monitor,
        Mouse,
        Rendered³,
        Rendered,
        Scene,
        Scene³,
        Spatial,
        Spatial³,
        Thread,
        Viewer,
        Visualizer,
        Widget,
        Window
    };
    
    using Types = Flags<Type>;
}
