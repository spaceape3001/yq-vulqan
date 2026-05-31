////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Type.hpp>

namespace yq::tachyon {
    class Camera;
    class Camera³;
    class Controller;
    class Cursor;
    class Desktop;
    class Engine;
    class Gamepad;
    class GraphicsCard;
    class Group;
    class Joystick;
    class Keyboard;
    class Kinetic;
    class Kinetic³;
    class Layer;
    class Light;
    class Light³;
    class Manager;
    class Master;
    class Model;
    class Monitor;
    class Mouse;
    class Physics;
    class Rendered;
    class Rendered³;
    class Scene;
    class Scene³;
    class Spatial;
    class Spatial²;
    class Spatial³;
    class Thread;
    class Viewer;
    class Widget;
    class Window;

    template <typename T>
    struct TypeTypeDeducer {
        static constexpr const Type kType   = Type::Unknown;
    };
    
    #define YQ_TYPETYPE(name)                                   \
        template <> struct TypeTypeDeducer<name> {              \
            static constexpr const Type kType   = Type::name;   \
        };
        
    YQ_TYPETYPE(Camera)
    YQ_TYPETYPE(Camera)
    YQ_TYPETYPE(Controller)
    YQ_TYPETYPE(Cursor)
    YQ_TYPETYPE(Desktop)
    YQ_TYPETYPE(Engine)
    YQ_TYPETYPE(Gamepad)
    YQ_TYPETYPE(GraphicsCard)
    YQ_TYPETYPE(Group)
    YQ_TYPETYPE(Joystick)
    YQ_TYPETYPE(Keyboard)
    YQ_TYPETYPE(Kinetic)
    YQ_TYPETYPE(Kinetic³)
    YQ_TYPETYPE(Layer)
    YQ_TYPETYPE(Light)
    YQ_TYPETYPE(Light³)
    YQ_TYPETYPE(Manager)
    YQ_TYPETYPE(Master)
    YQ_TYPETYPE(Model)
    YQ_TYPETYPE(Monitor)
    YQ_TYPETYPE(Mouse)
    YQ_TYPETYPE(Physics)
    YQ_TYPETYPE(Rendered)
    YQ_TYPETYPE(Rendered³)
    YQ_TYPETYPE(Scene)
    YQ_TYPETYPE(Scene³)
    YQ_TYPETYPE(Spatial)
    YQ_TYPETYPE(Spatial²)
    YQ_TYPETYPE(Spatial³)
    YQ_TYPETYPE(Thread)
    YQ_TYPETYPE(Viewer)
    YQ_TYPETYPE(Widget)
    YQ_TYPETYPE(Window)

    #undef YQ_TYPETYPE
}
