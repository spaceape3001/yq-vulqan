////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

struct lua_State;

#include <yq/core/Expect.hpp>
#include <yq/tachyon/typedef/camera.hpp>
#include <yq/tachyon/typedef/camera3.hpp>
//#include <yq/tachyon/typedef/collision.hpp>
#include <yq/tachyon/typedef/controller.hpp>
#include <yq/tachyon/typedef/cursor.hpp>
#include <yq/tachyon/typedef/desktop.hpp>
#include <yq/tachyon/typedef/gamepad.hpp>
#include <yq/tachyon/typedef/graphics_card.hpp>
#include <yq/tachyon/typedef/group.hpp>
#include <yq/tachyon/typedef/joystick.hpp>
#include <yq/tachyon/typedef/keyboard.hpp>
#include <yq/tachyon/typedef/layer.hpp>
#include <yq/tachyon/typedef/light.hpp>
#include <yq/tachyon/typedef/light3.hpp>
#include <yq/tachyon/typedef/manager.hpp>
#include <yq/tachyon/typedef/model.hpp>
#include <yq/tachyon/typedef/monitor.hpp>
#include <yq/tachyon/typedef/mouse.hpp>
//#include <yq/tachyon/typedef/physics.hpp>
#include <yq/tachyon/typedef/rendered.hpp>
#include <yq/tachyon/typedef/rendered3.hpp>
#include <yq/tachyon/typedef/scene.hpp>
#include <yq/tachyon/typedef/scene3.hpp>
#include <yq/tachyon/typedef/spatial.hpp>
#include <yq/tachyon/typedef/spatial3.hpp>
#include <yq/tachyon/typedef/spatial2.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>
#include <yq/tachyon/typedef/thread.hpp>
#include <yq/tachyon/typedef/viewer.hpp>
#include <yq/tachyon/typedef/widget.hpp>
#include <yq/tachyon/typedef/window.hpp>

namespace yq::tachyon {
    struct TypedID;


    Expect<CameraID>        cameraID(lua_State*, int);
    Expect<Camera³ID>       camera³ID(lua_State*, int);
    //Expect<CollisionID>     collisionID(lua_State*, int);
    Expect<ControllerID>    controllerID(lua_State*, int);
    Expect<CursorID>        cursorID(lua_State*, int);
    
    Expect<DesktopID>       desktopID(lua_State*, int);
    Expect<GamepadID>       gamepadID(lua_State*, int);
    //Expect<GroupID>         groupID(lua_State*, int);

    Expect<GraphicsCardID>  graphicsCardID(lua_State*, int);
    Expect<JoystickID>      joystickID(lua_State*, int);
    Expect<KeyboardID>      keyboardID(lua_State*, int);
    Expect<LayerID>         layerID(lua_State*, int);

    Expect<LightID>         lightID(lua_State*, int);
    Expect<Light³ID>        light³ID(lua_State*, int);
    Expect<ManagerID>       managerID(lua_State*, int);
    Expect<ModelID>         modelID(lua_State*, int);
    Expect<MonitorID>       monitorID(lua_State*, int);
    Expect<MouseID>         mouseID(lua_State*, int);
    //Expect<PhysicsID>       physicsID(lua_State*, int);

    Expect<RenderedID>      renderedID(lua_State*, int);
    Expect<Rendered³ID>     rendered³ID(lua_State*, int);
    Expect<SceneID>         sceneID(lua_State*, int);
    Expect<Scene³ID>        scene³ID(lua_State*, int);
    Expect<SpatialID>       spatialID(lua_State*, int);
    Expect<Spatial²ID>      spatial²ID(Spatial²ID*, int);
    Expect<Spatial³ID>      spatial³ID(lua_State*, int);
    Expect<StdThread>       stdThread(lua_State*, int);
    Expect<TachyonID>       tachyonID(lua_State*, int);
    Expect<ThreadID>        threadID(lua_State*, int);
    Expect<ViewerID>        viewerID(lua_State*, int);
    Expect<WidgetID>        widgetID(lua_State*, int);
    Expect<WindowID>        windowID(lua_State*, int);
    
}
