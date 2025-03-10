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
        Gamepad,
        GraphicsCard,
        ImGui,
        Joystick,
        Keyboard,
        Light,
        Light³,
        Manager,
        Model,
        Monitor,
        Mouse,
        Rendered,
        Rendered²,
        Rendered³,
        Scene,
        Scene³,
        Spatial,
        Spatial³,
        Thread,
        Viewer,
        Visualizer,
        Widget,
        Widget¹,
        Widget²,
        Widget³,
        Window
    };
    
    using Types = Flags<Type>;
}
