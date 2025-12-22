////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////
#include <yq/core/DelayInit.hpp>
#include <yq/lua/info.hpp>
#include <yq/lua/logging.hpp>
#include <yq/lua/lualua.hpp>
#include <yq/lua/info/FunctionInfo.hpp>
#include <yq/lua/info/ModuleInfo.hpp>
#include <yq/lua/info/ObjectInfo.hpp>
#include <yq/luavk/vm/extract.hpp>
#include <yq/luavk/vm/push.hpp>
#include <yq/tachyon/api/Camera.hpp>
#include <yq/tachyon/api/Camera3.hpp>
#include <yq/tachyon/api/Controller.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/Layer.hpp>
#include <yq/tachyon/api/Light.hpp>
#include <yq/tachyon/api/Manager.hpp>
#include <yq/tachyon/api/Model.hpp>
#include <yq/tachyon/api/Rendered.hpp>
#include <yq/tachyon/api/Scene.hpp>
#include <yq/tachyon/api/Spatial.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/api/Widget.hpp>
#include <yq/tachyon/app/Viewer.hpp>
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

#include <yq/lua/lualua.hxx>
#include <yq/lua/stdhandlers.hxx>
#include <yq/luavk/vm/push.hxx>
#include <yq/luavk/vm/extract.hxx>

using namespace yq;
using namespace yq::lua;
using namespace yq::tachyon;

namespace {
    template <typename T=Tachyon>
    void    push_ids(lua_State*l, const std::span<const TypedID>& sp)
    {
        lua_newtable(l);
        int tm = lua_gettop(l);
        int cnt = 0;
        for(auto& tid : sp){
            lua::push(l,(ID<T>)  tid);
            lua_seti(l, tm, ++cnt);
        }
    }

    template <typename T>
    void    push_ids(lua_State*l, const std::set<ID<T>>& sp)
    {
        lua_newtable(l);
        int tm = lua_gettop(l);
        int cnt = 0;
        for(auto& tid : sp){
            lua::push(l,(ID<T>)  tid);
            lua_seti(l, tm, ++cnt);
        }
    }

    template <typename Pred>
    int framing(lua_State* l, Pred&& fn)
    {
        Ref<const Frame>    frame = Frame::current();
        if(lua_gettop(l) > 1){
            auto fx = lua::object_as<Frame>(l, 1, CONST);
            if(fx && *fx){
                frame   = *fx;
                lua_remove(l, 1);
            }
        } 
        
        return fn(*frame);
    }
    
    ////////////////////////////
    
    int lh_frame_cameras(lua_State*l)
    {
        return framing(l, [&](const Frame&f) -> int {
            push_ids<Camera>(l, f.ids(CAMERA));
            return 1;
        });
    }

    int lh_frame_children(lua_State* l)
    {
        return framing(l, [&](const Frame& f) -> int {
            auto tidx   = tachyonID(l, -1);
            if(!tidx)
                return 0;
                
            push_ids(l, f.children(*tidx));
            return 1;
        });
    }
    
    int lh_frame_contains(lua_State* l)
    {
        return framing(l, [&](const Frame& f) -> int {
            auto tidx   = tachyonID(l, -1);
            if(!tidx)
                return 0;
            lua_pushboolean(l, f.contains(*tidx));
            return 1;
        });
    }

    int lh_frame_controllers(lua_State*l)
    {
        return framing(l, [&](const Frame&f) -> int {
            push_ids<Controller>(l, f.ids(CONTROLLER));
            return 1;
        });
    }

    int  lh_frame_current(lua_State* l)
    {
        Ref<const Frame>  frame   = Frame::current();
        lua::push(l, frame);
        return 1;
    }
    
    int lh_frame_cursors(lua_State*l)
    {
        return framing(l, [&](const Frame&f) -> int {
            push_ids<Cursor>(l, f.ids(CURSOR));
            return 1;
        });
    }

    int lh_frame_desktops(lua_State*l)
    {
        return framing(l, [&](const Frame&f) -> int {
            push_ids<Desktop>(l, f.ids(DESKTOP));
            return 1;
        });
    }

    int lh_frame_gamepads(lua_State*l)
    {
        return framing(l, [&](const Frame&f) -> int {
            push_ids<Gamepad>(l, f.ids(GAMEPAD));
            return 1;
        });
    }

    int lh_frame_graphics_cards(lua_State*l)
    {
        return framing(l, [&](const Frame&f) -> int {
            push_ids<GraphicsCard>(l, f.ids(GRAPHICS_CARD));
            return 1;
        });
    }

    int lh_frame_joysticks(lua_State*l)
    {
        return framing(l, [&](const Frame&f) -> int {
            push_ids<Joystick>(l, f.ids(JOYSTICK));
            return 1;
        });
    }

    int lh_frame_keyboards(lua_State*l)
    {
        return framing(l, [&](const Frame&f) -> int {
            push_ids<Keyboard>(l, f.ids(KEYBOARD));
            return 1;
        });
    }

    int lh_frame_layers(lua_State*l)
    {
        return framing(l, [&](const Frame&f) -> int {
            push_ids<Layer>(l, f.ids(LAYER));
            return 1;
        });
    }

    int lh_frame_lights(lua_State*l)
    {
        return framing(l, [&](const Frame&f) -> int {
            push_ids<Light>(l, f.ids(LIGHT));
            return 1;
        });
    }
    
    int lh_frame_managers(lua_State*l)
    {
        return framing(l, [&](const Frame&f) -> int {
            push_ids<Manager>(l, f.ids(MANAGER));
            return 1;
        });
    }

    int lh_frame_models(lua_State*l)
    {
        return framing(l, [&](const Frame&f) -> int {
            push_ids<Model>(l, f.ids(MODEL));
            return 1;
        });
    }

    int lh_frame_mouses(lua_State*l)
    {
        return framing(l, [&](const Frame&f) -> int {
            push_ids<Mouse>(l, f.ids(MOUSE));
            return 1;
        });
    }

    int lh_frame_monitors(lua_State*l)
    {
        return framing(l, [&](const Frame&f) -> int {
            push_ids<Monitor>(l, f.ids(MONITOR));
            return 1;
        });
    }

    int lh_frame_rendereds(lua_State*l)
    {
        return framing(l, [&](const Frame&f) -> int {
            push_ids<Rendered>(l, f.ids(RENDERED));
            return 1;
        });
    }

    int lh_frame_scenes(lua_State*l)
    {
        return framing(l, [&](const Frame&f) -> int {
            push_ids<Scene>(l, f.ids(SCENE));
            return 1;
        });
    }

    int lh_frame_spatials(lua_State*l)
    {
        return framing(l, [&](const Frame&f) -> int {
            push_ids<Spatial>(l, f.ids(SPATIAL));
            return 1;
        });
    }

    int lh_frame_tachyons(lua_State*l)
    {
        return framing(l, [&](const Frame&f) -> int {
            push_ids<Tachyon>(l, f.ids(TACHYON));
            return 1;
        });
    }

    int lh_frame_threads(lua_State*l)
    {
        return framing(l, [&](const Frame&f) -> int {
            push_ids<Thread>(l, f.ids(THREAD));
            return 1;
        });
    }

    int lh_frame_tick(lua_State* l)
    {
        return framing(l, [&](const Frame& f) -> int {
            lua_pushinteger(l, (int) f.tick());
            return 1;
        });
    }

    int lh_frame_time(lua_State* l)
    {
        return framing(l, [&](const Frame& f) -> int {
            lua_pushnumber(l, f.time().value);
            return 1;
        });
    }

    int lh_frame_viewers(lua_State*l)
    {
        return framing(l, [&](const Frame&f) -> int {
            push_ids<Viewer>(l, f.ids(VIEWER));
            return 1;
        });
    }

    int lh_frame_widgets(lua_State*l)
    {
        return framing(l, [&](const Frame&f) -> int {
            push_ids<Widget>(l, f.ids(WIDGET));
            return 1;
        });
    }

    int lh_frame_windows(lua_State*l)
    {
        return framing(l, [&](const Frame&f) -> int {
            push_ids<Window>(l, f.ids(WINDOW));
            return 1;
        });
    }

    void reg_frame()
    {
        using namespace yq::lua;
        
        if(auto* mi  = reg(MODULE, "frame")){
            if(FunctionInfo* fi = mi->add("cameras", &lh_frame_cameras)){  
                fi->brief("Cameras on the current frame");
            }
            if(FunctionInfo* fi = mi->add("children", &lh_frame_children)){  
                fi->brief("Tachyon's children according to current frame" );
            }
            if(FunctionInfo* fi = mi->add("contains", &lh_frame_contains)){  
                fi->brief("Test if current frame contains TachyonID");
            }
            if(FunctionInfo* fi = mi->add("controllers", &lh_frame_controllers)){  
                fi->brief("Controllers on the frame");
            }
            if(FunctionInfo* fi = mi->add("current", &lh_frame_current)){  
                fi->brief("Current Frame");
            }
            if(FunctionInfo* fi = mi->add("cursors", &lh_frame_cursors)){  
                fi->brief("Cursors on the frame");
            }
            if(FunctionInfo* fi = mi->add("desktops", &lh_frame_desktops)){  
                fi->brief("Desktops on the frame");
            }
            if(FunctionInfo* fi = mi->add("gamepads", &lh_frame_gamepads)){  
                fi->brief("Gamepads on the frame");
            }
            if(FunctionInfo* fi = mi->add("gpus", &lh_frame_graphics_cards)){  
                fi->brief("Graphic Cards on the frame");
            }
            if(FunctionInfo* fi = mi->add("joysticks", &lh_frame_joysticks)){  
                fi->brief("Joysticks on the frame");
            }
            if(FunctionInfo* fi = mi->add("keyboards", &lh_frame_keyboards)){  
                fi->brief("Keyboards on the frame");
            }
            if(FunctionInfo* fi = mi->add("layers", &lh_frame_layers)){  
                fi->brief("Layers on the frame");
            }
            if(FunctionInfo* fi = mi->add("lights", &lh_frame_lights)){  
                fi->brief("Lights on the frame");
            }
            if(FunctionInfo* fi = mi->add("managers", &lh_frame_managers)){  
                fi->brief("Managers on the frame");
            }
            if(FunctionInfo* fi = mi->add("mice", &lh_frame_mouses)){  
                fi->brief("Mice on the frame");
            }
            if(FunctionInfo* fi = mi->add("models", &lh_frame_models)){  
                fi->brief("Models on the frame");
            }
            if(FunctionInfo* fi = mi->add("monitors", &lh_frame_monitors)){  
                fi->brief("Monitors on the frame");
            }
            if(FunctionInfo* fi = mi->add("rendereds", &lh_frame_rendereds)){  
                fi->brief("Rendereds on the frame");
            }
            if(FunctionInfo* fi = mi->add("scenes", &lh_frame_scenes)){  
                fi->brief("Scenes on the frame");
            }
            if(FunctionInfo* fi = mi->add("spatials", &lh_frame_spatials)){  
                fi->brief("Spatials on the frame");
            }
            if(FunctionInfo* fi = mi->add("tachyons", &lh_frame_tachyons)){  
                fi->brief("Tachyons on the frame");
            }
            if(FunctionInfo* fi = mi->add("threads", &lh_frame_threads)){  
                fi->brief("Threads on the frame");
            }
            if(FunctionInfo* fi = mi->add("tick", &lh_frame_tick)){  
                fi->brief("Current Frame Tick");
            }
            if(FunctionInfo* fi = mi->add("time", &lh_frame_time)){  
                fi->brief("Current Frame Time (seconds)");
            }
            if(FunctionInfo* fi = mi->add("viewers", &lh_frame_viewers)){  
                fi->brief("Viewers on the frame");
            }
            if(FunctionInfo* fi = mi->add("widgets", &lh_frame_widgets)){  
                fi->brief("Widgets on the frame");
            }
            if(FunctionInfo* fi = mi->add("windows", &lh_frame_windows)){  
                fi->brief("Windows on the frame");
            }
        }
        
        if(auto* mi = reg<Frame>()){
            if(FunctionInfo* fi = mi->add("cameras", &lh_frame_cameras)){  
                fi->brief("Cameras on the frame");
            }
            if(FunctionInfo* fi = mi->add("children", &lh_frame_children)){  
                fi->brief("Tachyon's children according to given frame");
            }
            if(FunctionInfo* fi = mi->add("contains", &lh_frame_contains)){  
                fi->brief("Test if frame contains tachyon");
            }
            if(FunctionInfo* fi = mi->add("controllers", &lh_frame_controllers)){  
                fi->brief("Controllers on the frame");
            }
            if(FunctionInfo* fi = mi->add("cursors", &lh_frame_cursors)){  
                fi->brief("Cursors on the frame");
            }
            if(FunctionInfo* fi = mi->add("desktops", &lh_frame_desktops)){  
                fi->brief("Desktops on the frame");
            }
            if(FunctionInfo* fi = mi->add("gamepads", &lh_frame_gamepads)){  
                fi->brief("Gamepads on the frame");
            }
            if(FunctionInfo* fi = mi->add("gpus", &lh_frame_graphics_cards)){  
                fi->brief("Graphic Cards on the frame");
            }
            if(FunctionInfo* fi = mi->add("joysticks", &lh_frame_joysticks)){  
                fi->brief("Joysticks on the frame");
            }
            if(FunctionInfo* fi = mi->add("keyboards", &lh_frame_keyboards)){  
                fi->brief("Keyboards on the frame");
            }
            if(FunctionInfo* fi = mi->add("layers", &lh_frame_layers)){  
                fi->brief("Layers on the frame");
            }
            if(FunctionInfo* fi = mi->add("lights", &lh_frame_lights)){  
                fi->brief("Lights on the frame");
            }
            if(FunctionInfo* fi = mi->add("managers", &lh_frame_managers)){  
                fi->brief("Managers on the frame");
            }
            if(FunctionInfo* fi = mi->add("mice", &lh_frame_mouses)){  
                fi->brief("Mice on the frame");
            }
            if(FunctionInfo* fi = mi->add("models", &lh_frame_models)){  
                fi->brief("Models on the frame");
            }
            if(FunctionInfo* fi = mi->add("monitors", &lh_frame_monitors)){  
                fi->brief("Monitors on the frame");
            }
            if(FunctionInfo* fi = mi->add("rendereds", &lh_frame_rendereds)){  
                fi->brief("Rendereds on the frame");
            }
            if(FunctionInfo* fi = mi->add("scenes", &lh_frame_scenes)){  
                fi->brief("Scenes on the frame");
            }
            if(FunctionInfo* fi = mi->add("spatials", &lh_frame_spatials)){  
                fi->brief("Spatials on the frame");
            }
            if(FunctionInfo* fi = mi->add("tachyons", &lh_frame_tachyons)){  
                fi->brief("Tachyons on the frame");
            }
            if(FunctionInfo* fi = mi->add("threads", &lh_frame_threads)){  
                fi->brief("Threads on the frame");
            }
            if(FunctionInfo* fi = mi->add("tick", &lh_frame_tick)){  
                fi->brief("Frame's tick");
            }
            if(FunctionInfo* fi = mi->add("time", &lh_frame_time)){  
                fi->brief("Frame's time (seconds)");
            }
            if(FunctionInfo* fi = mi->add("viewers", &lh_frame_viewers)){  
                fi->brief("Viewers on the frame");
            }
            if(FunctionInfo* fi = mi->add("widgets", &lh_frame_widgets)){  
                fi->brief("Widgets on the frame");
            }
            if(FunctionInfo* fi = mi->add("windows", &lh_frame_windows)){  
                fi->brief("Windows on the frame");
            }
        }
    }


    YQ_INVOKE(reg_frame();)
}
