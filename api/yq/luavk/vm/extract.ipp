////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "extract.hpp"
#include <yq/lua/impl.hpp>
#include <yq/lua/lualua.hpp>
#include <yq/luavk/errors.hpp>
#include <yq/tachyon/errors.hpp>
#include <yq/tachyon/api/Camera.hpp>
#include <yq/tachyon/api/Camera3.hpp>
#include <yq/tachyon/api/Controller.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/Group.hpp>
#include <yq/tachyon/api/Layer.hpp>
#include <yq/tachyon/api/Light.hpp>
#include <yq/tachyon/api/Light3.hpp>
#include <yq/tachyon/api/Manager.hpp>
#include <yq/tachyon/api/Model.hpp>
#include <yq/tachyon/api/Rendered.hpp>
#include <yq/tachyon/api/Rendered3.hpp>
#include <yq/tachyon/api/Scene.hpp>
#include <yq/tachyon/api/Scene3.hpp>
#include <yq/tachyon/api/Spatial.hpp>
#include <yq/tachyon/api/Spatial2.hpp>
#include <yq/tachyon/api/Spatial3.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/app/Viewer.hpp>
#include <yq/tachyon/api/Widget.hpp>
#include <yq/tachyon/os/Cursor.hpp>
#include <yq/tachyon/os/Desktop.hpp>
#include <yq/tachyon/os/Gamepad.hpp>
#include <yq/tachyon/os/GraphicsCard.hpp>
#include <yq/tachyon/os/Joystick.hpp>
#include <yq/tachyon/os/Keyboard.hpp>
#include <yq/tachyon/os/Mouse.hpp>
#include <yq/tachyon/os/Monitor.hpp>
#include <yq/tachyon/os/Window.hpp>
#include <lua.hpp>
#include <yq/lua/extract.hxx>

namespace yq::errors {
}

namespace yq::tachyon {
    Expect<TypedID>        typedID(lua_State* l, int n)
    {
        const Frame*    f   = Frame::current();
        if(!f)
            return errors::luavk_no_frame_available();

        if(lua_type(l,n) != LUA_TTABLE)
            return errors::luavk_not_a_table();
        const TypeMeta* tm  = lua::_meta(l, n, TYPE);
        if(!tm)
            return errors::luavk_not_a_table();
            
        uint64_t    id  = lua::_id(l,n);
            
        if(
            (tm == &meta<CameraID>()) ||
            (tm == &meta<Camera³ID>()) ||
            (tm == &meta<ControllerID>()) ||
            (tm == &meta<CursorID>()) ||
            (tm == &meta<DesktopID>()) ||
            (tm == &meta<GamepadID>()) ||
            (tm == &meta<GraphicsCardID>()) ||
            //(tm == &meta<GroupID>()) ||
            (tm == &meta<JoystickID>()) ||
            (tm == &meta<KeyboardID>()) ||
            (tm == &meta<LayerID>()) ||
            (tm == &meta<LightID>()) ||
            (tm == &meta<Light³ID>()) ||
            (tm == &meta<ManagerID>()) ||
            (tm == &meta<ModelID>()) ||
            (tm == &meta<MonitorID>()) ||
            (tm == &meta<MouseID>()) ||
            (tm == &meta<RenderedID>()) ||
            (tm == &meta<Rendered³ID>()) ||
            (tm == &meta<SceneID>()) ||
            (tm == &meta<Scene³ID>()) ||
            (tm == &meta<SpatialID>()) ||
            (tm == &meta<Spatial²ID>()) ||
            (tm == &meta<Spatial³ID>()) ||
            (tm == &meta<TachyonID>()) ||
            (tm == &meta<ThreadID>()) ||
            (tm == &meta<TypedID>()) || 
            (tm == &meta<ViewerID>()) ||
            (tm == &meta<WidgetID>()) ||
            (tm == &meta<WindowID>())
        )
        {
            return f->typed(TachyonID{id});
        }
        
        return TypedID(id);
    }

    Expect<CameraID>       cameraID(lua_State* l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Camera))
            return errors::luavk_not_valid_camera_id();
        return CameraID(x->id);
    }

    Expect<Camera³ID>       camera³ID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Camera³))
            return errors::luavk_not_valid_camera3_id();
        return Camera³ID(x->id);
    }
    
    //Expect<CollisionID>     collisionID(lua_State*, int);
    Expect<ControllerID>    controllerID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Controller))
            return errors::luavk_not_valid_controller_id();
        return ControllerID(x->id);
    }
    
    Expect<CursorID>        cursorID(lua_State* l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Cursor))
            return errors::luavk_not_valid_cursor_id();
        return CursorID(x->id);
    }
    
    Expect<DesktopID>       desktopID(lua_State* l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Desktop))
            return errors::luavk_not_valid_camera_id();
        return DesktopID(x->id);
    }

    Expect<GamepadID>       gamepadID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Gamepad))
            return errors::luavk_not_valid_gamepad_id();
        return GamepadID(x->id);
    }
    
    //Expect<GroupID>         groupID(lua_State*l, int n)

    Expect<GraphicsCardID>  graphicsCardID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::GraphicsCard))
            return errors::luavk_not_valid_graphics_card_id();
        return GraphicsCardID(x->id);
    }
    
    Expect<JoystickID>      joystickID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Joystick))
            return errors::luavk_not_valid_joystick_id();
        return JoystickID(x->id);
    }
    
    Expect<KeyboardID>      keyboardID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Keyboard))
            return errors::luavk_not_valid_keyboard_id();
        return KeyboardID(x->id);
    }
    
    Expect<LayerID>         layerID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Layer))
            return errors::luavk_not_valid_layer_id();
        return LayerID(x->id);
    }
    

    Expect<LightID>         lightID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Light))
            return errors::luavk_not_valid_light_id();
        return LightID(x->id);
    }
    
    Expect<Light³ID>        light³ID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Light³))
            return errors::luavk_not_valid_light3_id();
        return Light³ID(x->id);
    }
    
    Expect<ManagerID>       managerID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Manager))
            return errors::luavk_not_valid_manager_id();
        return ManagerID(x->id);
    }
    
    Expect<ModelID>         modelID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Model))
            return errors::luavk_not_valid_model_id();
        return ModelID(x->id);
    }
    
    Expect<MonitorID>       monitorID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Monitor))
            return errors::luavk_not_valid_monitor_id();
        return MonitorID(x->id);
    }
    
    Expect<MouseID>         mouseID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Mouse))
            return errors::luavk_not_valid_mouse_id();
        return MouseID(x->id);
    }
    
    #if 0
    Expect<PhysicsID>       physicsID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Physics))
            return errors::luavk_not_valid_physics_id();
        return PhysicsID(x->id);
    }
    #endif
    
    Expect<RenderedID>      renderedID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Rendered))
            return errors::luavk_not_valid_rendered_id();
        return RenderedID(x->id);
    }
    
    Expect<Rendered³ID>     rendered³ID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Rendered³))
            return errors::luavk_not_valid_rendered3_id();
        return Rendered³ID(x->id);
    }
    
    Expect<SceneID>         sceneID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Scene))
            return errors::luavk_not_valid_scene_id();
        return SceneID(x->id);
    }
    
    Expect<Scene³ID>        scene³ID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Scene³))
            return errors::luavk_not_valid_scene3_id();
        return Scene³ID(x->id);
    }
    
    Expect<SpatialID>       spatialID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Spatial))
            return errors::luavk_not_valid_spatial_id();
        return SpatialID(x->id);
    }
    
    Expect<Spatial²ID>      spatial²ID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Spatial²))
            return errors::luavk_not_valid_spatial2_id();
        return Spatial²ID(x->id);
    }
    
    Expect<Spatial³ID>      spatial³ID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Spatial³))
            return errors::luavk_not_valid_spatial3_id();
        return Spatial³ID(x->id);
    }
    
    Expect<StdThread>       stdThread(lua_State*l, int n)
    {
        return lua::enumeration<StdThread>(l,n);
    }
    
    Expect<TachyonID>       tachyonID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        return TachyonID(x->id);
    }
    
    Expect<ThreadID>        threadID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Thread))
            return errors::luavk_not_valid_thread_id();
        return ThreadID(x->id);
    }
    
    Expect<ViewerID>        viewerID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Viewer))
            return errors::luavk_not_valid_viewer_id();
        return ViewerID(x->id);
    }
    
    Expect<WidgetID>        widgetID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Widget))
            return errors::luavk_not_valid_widget_id();
        return WidgetID(x->id);
    }
    
    Expect<WindowID>        windowID(lua_State*l, int n)
    {
        auto x = typedID(l, n);
        if(!x)
            return unexpected(x.error());
        if(!x->types(Type::Window))
            return errors::luavk_not_valid_window_id();
        return WindowID(x->id);
    }
    


#if 0

    
    Expect<LightID>        lightID(lua_State* l, int n)
    {
        if(lua_type(l,n) != LUA_TTABLE)
            return errors::not_a_table();
        auto tmx = lua::type_meta(l, n);
        if(!tmx)
            return errors::cannot_extract_meta();
        auto ix = lua::integer(l, n, TABLE, "_id");    
        if(!ix)
            return unexpected(ix.error());
        
        if(*tmx == &meta<LightID>)
            return LightID(*ix);
        if(*tmx == &meta<Light³ID>)
            return LightID(*ix);
        const Frame*    frame   = Frame::current();
        if(!frame)
            return errors::no_frame_available();
        TypedID typeId  = frame->typed({*ix});
        if(typedid(Type::Light))
            return LightID{*ix};
        return errors::not_valid_light_id();
    }
    
    Expect<RenderedID>     renderedID(lua_State* l, int n)
    {
        if(lua_type(l,n) != LUA_TTABLE)
            return errors::not_a_table();
        auto tmx = lua::type_meta(l, n);
        if(!tmx)
            return errors::cannot_extract_meta();
        auto ix = lua::integer(l, n, TABLE, "_id");    
        if(!ix)
            return unexpected(ix.error());
        
        if(*tmx == &meta<RenderedID>)
            return RenderedID(*ix);
        if(*tmx == &meta<Rendered³ID>)
            return RenderedID(*ix);
        const Frame*    frame   = Frame::current();
        if(!frame)
            return errors::no_frame_available();
        TypedID typeId  = frame->typed({*ix});
        if(typedid(Type::Rendered))
            return RenderedID{*ix};
        return errors::not_valid_rendered_id();
    }
    
    Expect<StdThread>      stdThread(lua_State* l, int n)
    {
    }
    
    Expect<TachyonID>      tachyonID(lua_State* l, int n)
    {
        if(lua_type(l,n) != LUA_TTABLE)
            return errors::not_a_table();
        auto tmx = lua::type_meta(l, n);
        if(!tmx)
            return errors::cannot_extract_meta();
        auto ix = lua::integer(l, n, TABLE, "_id");    
        if(!ix)
            return unexpected(ix.error());
        
    }
    
    Expect<ThreadID>       threadID(lua_State* l, int n)
    {
        if(lua_type(l,n) != LUA_TTABLE)
            return errors::not_a_table();
        auto tmx = lua::type_meta(l, n);
        if(!tmx)
            return errors::cannot_extract_meta();
        auto ix = lua::integer(l, n, TABLE, "_id");    
        if(!ix)
            return unexpected(ix.error());
        
    }
    
    Expect<ViewerID>       viewerID(lua_State* l, int n)
    {
    }
        auto tmx = lua::type_meta(l, n);
        if(!tmx)
            return errors::cannot_extract_meta();
        auto ix = lua::integer(l, n, TABLE, "_id");    
        if(!ix)
            return unexpected(ix.error());
        
    
    Expect<WidgetID>       widgetID(lua_State* l, int n)
    {
    }
#endif
}
