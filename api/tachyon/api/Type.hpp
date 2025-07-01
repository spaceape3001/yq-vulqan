////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Flag.hpp>
#include <yq/core/Enum.hpp>
#include <yq/meta/MetaBinder.hpp>

namespace yq::tachyon {

    /*
        This is meant for *FAST* type detection in the tachyon, should be 
        kept small... switch the actual type as we grow, until then...
    */
    
    YQ_ENUM(Type, , 
        Camera,
        Camera³,
        Controller,
        Cursor,
        Desktop,
        Editor,
        Gamepad,
        GraphicsCard,
        Group,
        ImGui,
        Joystick,
        Keyboard,
        Layer,
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
    );
    
    using Types = Flag<Type>;
}
