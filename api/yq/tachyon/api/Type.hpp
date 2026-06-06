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
    
    enum class Type {
        Unknown,
        Acceleration³,
        Camera,
        Camera³,
        Collision,
        Controller,
        Cursor,
        Desktop,
        Domain,
        Editor,
        Engine,
        Entity,
        Entity³,
        Force³,
        Gamepad,
        GraphicsCard,
        Group,
        ImGui,
        Joystick,
        Keyboard,
        Kinetic,
        Kinetic³,
        Layer,
        Light,
        Light³,
        Manager,
        Mass,
        Master,
        Model,
        Moment³,
        Monitor,
        Mouse,
        Rendered,
        Rendered²,
        Rendered³,
        Physics,
        Scene,
        Scene³,
        Spatial,
        Spatial²,
        Spatial³,
        Thread,
        Viewer,
        Visualizer,
        Widget,
        Widget¹,
        Widget²,
        Widget³,
        Widget⁴,
        Window
    };
    
    // want to get the above into a hash/reflection to auto bind enum/type
    
    using Types = Flags<Type>;
}
