////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Type.hpp>

namespace yq::tachyon {
    class Tachyon;
    class TachyonData;
    class TachyonMeta;
    class TachyonSnap;

    template <typename T>
    struct TypeTypeDeducer {
        static constexpr const Type kType   = Type::Unknown;
        using MyMeta                        = TachyonMeta;
        using MyData                        = TachyonData;
        using MySnap                        = TachyonSnap;
    };
    
    template <typename T>
    static constexpr const Type type_v      = TypeTypeDeducer<T>::kType;
    template <typename T>
    using meta_t        = typename TypeTypeDeducer<T>::MyMeta;
    template <typename T>
    using data_t        = typename TypeTypeDeducer<T>::MyData;
    template <typename T>
    using snap_t        = typename TypeTypeDeducer<T>::MySnap;
    
    #define YQ_TYPETYPE(name)                                   \
        class name; \
        class name##Data; \
        class name##Meta; \
        class name##Snap; \
        template <> struct TypeTypeDeducer<name> {              \
            static constexpr const Type kType   = Type::name;   \
            using MyData                        = name##Data;   \
            using MyMeta                        = name##Meta;   \
            using MySnap                        = name##Snap;   \
        };
        
    YQ_TYPETYPE(Acceleration³)
    YQ_TYPETYPE(Camera)
    YQ_TYPETYPE(Camera³)
    YQ_TYPETYPE(Controller)
    YQ_TYPETYPE(Cursor)
    YQ_TYPETYPE(Desktop)
    YQ_TYPETYPE(Domain)
    YQ_TYPETYPE(Engine)
    YQ_TYPETYPE(Entity)
    YQ_TYPETYPE(Entity³)
    YQ_TYPETYPE(Force³)
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
    YQ_TYPETYPE(Mass)
    YQ_TYPETYPE(Master)
    YQ_TYPETYPE(Model)
    YQ_TYPETYPE(Moment³)
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
