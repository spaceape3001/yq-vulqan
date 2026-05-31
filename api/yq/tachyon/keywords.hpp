////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#define YQ_KEYWORD_OMIT_CURSOR
#define YQ_KEYWORD_OMIT_LIGHT
#define YQ_KEYWORD_OMIT_MAX
#define YQ_KEYWORD_OMIT_MIN
#define YQ_KEYWORD_OMIT_NONE
#define YQ_KEYWORD_OMIT_THREAD
#define YQ_KEYWORD_OMIT_WIDGET

#include <yq/keywords.hpp>
#include <yq/math/Cardinal.hpp>
#include <yq/tachyon/api/StdThread.hpp>
#include <yq/tachyon/api/Type.hpp>
#include <yq/tachyon/pipeline/DataActivity.hpp>
#include <yq/tachyon/os/Platform.hpp>
#include <yq/tachyon/api/SizePolicy.hpp>
#include <yq/unit/declare.hpp>

namespace yq::tachyon {

    struct EveryTime;
    struct EveryCount;
    
    class Camera;
    class Camera³;
    class Collision;
    class Controller;
    class Cursor;
    class Desktop;
    class Domain;
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
    class Tachyon;
    class Thread;
    class Viewer;
    class Widget;
    class Window;

    // IF we define these in the toolbox, we'll derive the types
    struct align_k {};
    
    struct app_k {
        consteval operator StdThread() const noexcept  { return StdThread::App; }
    };
    
    
    struct audio_k {
        consteval operator StdThread() const noexcept  { return StdThread::Audio; }
    };

    struct auxillary_k {
        consteval operator StdThread() const noexcept  { return StdThread::Auxillary; }
    };
    
    struct available_k {};

    struct bar_k {};

    struct browse_k {};

    struct camera_k {
        using class_t = Camera;
        static constexpr const Type kType = Type::Camera;
        consteval operator Type() const noexcept { return kType; }
    };
    struct camera³_k {
        using class_t = Camera³;
        static constexpr const Type kType = Type::Camera³;
        consteval operator Type() const noexcept { return kType; }
    };
    struct center_k {
        consteval operator Cardinal() const noexcept { return Cardinal::Center; }
    };
    
    struct collision_k {
        using class_t = Collision;
        static constexpr const Type kType = Type::Collision;
        consteval operator Type() const noexcept { return kType; }
    };

    struct color_k {};

    struct common_k {
        consteval operator DataActivity() const noexcept { return DataActivity::COMMON; }
    };
    
    struct content_k {};
    
    struct controller_k {
        using class_t = Controller;
        static constexpr const Type kType = Type::Controller;
        consteval operator Type() const noexcept { return kType; }
    };
    
    struct controllers_k {};
    struct cursor_k : ::yq::cursor_k {
        using class_t = Cursor;
        static constexpr const Type kType = Type::Cursor;
        consteval operator Type() const noexcept { return kType; }
    };
    
    struct d2l_k    {};
    struct delegate_k {};
    struct depth_k {};
    struct desktop_k {
        using class_t = Desktop;
        static constexpr const Type kType = Type::Desktop;
        consteval operator Type() const noexcept { return kType; }
    };
    struct device_k {};
    struct dialog_k {};
    struct direct_k{};
    struct dock_k {};
    struct domain_k {
        using class_t = Domain;
        static constexpr const Type kType = Type::Domain;
        consteval operator Type() const noexcept { return kType; }
    };

    struct dynamic_k {
        consteval operator DataActivity() const noexcept { return DataActivity::DYNAMIC; }
    };
    
    struct east_k {
        consteval operator Cardinal() const noexcept { return Cardinal::East; }
    };
    
    struct edit_k {
        consteval operator StdThread() const noexcept  { return StdThread::Edit; }
    };
    
    struct emit_k {};
    
    struct engine_k {
        using class_t = Engine;
        static constexpr const Type kType = Type::Engine;
        consteval operator Type() const noexcept { return kType; }
    };
    
    struct event_k{};
    
    struct every_k : public ::yq::every_k {
        static constexpr EveryTime    operator()(unit::Second);
        static constexpr EveryCount   operator()(unsigned);
    };
    
    struct external_k { };

    struct face_k {};
    
    struct fixed_k {
        consteval operator DataActivity() const noexcept { return DataActivity::FIXED; }
        consteval operator SizePolicy() const noexcept { return kSizePolicy_Fixed; }
    };
    
    struct game_k {
        consteval operator StdThread() const noexcept  { return StdThread::Game; }
    };
    
    struct gamepad_k {
        using class_t = Gamepad;
        static constexpr const Type kType = Type::Gamepad;
        consteval operator Type() const noexcept { return kType; }
    };
    struct gesture_k {};
    
    struct glfw_k {
        consteval operator Platform() const noexcept { return Platform::GLFW; }
    };
    
    struct graphics_card_k {
        using class_t = GraphicsCard;
        static constexpr const Type kType = Type::GraphicsCard;
        consteval operator Type() const noexcept { return kType; }
    };
    
    struct group_k {
        using class_t = Group;
        static constexpr const Type kType = Type::Group;
        consteval operator Type() const noexcept { return kType; }
    };
    
    struct headless_k {};

    struct imgui_k {};

    struct indent_k {};
    struct insert_k {};
    struct insertable_k {};
    struct interface_k {};
    struct io_k {
        consteval operator StdThread() const noexcept  { return StdThread::IO; }
    };
    
    struct joystick_k {
        using class_t = Joystick;
        static constexpr const Type kType = Type::Joystick;
        consteval operator Type() const noexcept { return kType; }
    };
    struct keyboard_k {
        using class_t = Keyboard;
        static constexpr const Type kType = Type::Keyboard;
        consteval operator Type() const noexcept { return kType; }
    };
    struct kinetic_k {
        using class_t = Kinetic;
        static constexpr const Type kType = Type::Kinetic;
        consteval operator Type() const noexcept { return kType; }
    };
    struct kinetic³_k {
        using class_t = Kinetic³;
        static constexpr const Type kType = Type::Kinetic³;
        consteval operator Type() const noexcept { return kType; }
    };
    struct l2d_k {};
    struct layer_k {
        using class_t = Layer;
        static constexpr const Type kType = Type::Layer;
        consteval operator Type() const noexcept { return kType; }
    };
    struct layout_k {};
    struct light_k : public ::yq::light_k {
        using class_t = Light;
        static constexpr const Type kType = Type::Light;
        consteval operator Type() const noexcept { return kType; }
    };
    struct light³_k {
        using class_t = Light³;
        static constexpr const Type kType = Type::Light³;
        consteval operator Type() const noexcept { return kType; }
    };
    struct manager_k {
        using class_t = Manager;
        static constexpr const Type kType = Type::Manager;
        consteval operator Type() const noexcept { return kType; }
    };
    struct master_k {
        using class_t = Master;
        static constexpr const Type kType = Type::Master;
        consteval operator Type() const noexcept { return kType; }
    };
    struct maximum_k : public ::yq::maximum_k {
        consteval operator SizePolicy() const noexcept { return kSizePolicy_Maximum; }
    };
    struct mesh_k {};
    struct minimum_k : public ::yq::minimum_k {
        consteval operator SizePolicy() const noexcept { return kSizePolicy_Minimum; }
    };
    struct minmax_k {};
    struct model_k {
        using class_t = Model;
        static constexpr const Type kType = Type::Model;
        consteval operator Type() const noexcept { return kType; }
    };
    struct monitor_k {
        using class_t = Monitor;
        static constexpr const Type kType = Type::Monitor;
        consteval operator Type() const noexcept { return kType; }
    };
    struct mouse_k {
        using class_t = Mouse;
        static constexpr const Type kType = Type::Mouse;
        consteval operator Type() const noexcept { return kType; }
    };

    struct network_k {
        consteval operator StdThread() const noexcept  { return StdThread::Network; }
    };
    
    struct none_k : public ::yq::none_k {
        consteval operator Platform() const noexcept { return Platform::None; }
    };
    
    struct north_k {
        consteval operator Cardinal() const noexcept { return Cardinal::North; }
    };
    
    struct origin_k {};
    struct physics_k {
        using class_t = Physics;
        static constexpr const Type kType = Type::Physics;
        consteval operator Type() const noexcept { return kType; }
    };
    struct pivot_k {};
    
    struct point_k {};
    struct popup_k {};
    struct pre_k {};
    struct probe_k {};
    struct proxy_k {};

    struct refresh_k {
        consteval operator DataActivity() const noexcept { return DataActivity::REFRESH; }
    };
    
    struct rendered_k {
        using class_t = Rendered;
        static constexpr const Type kType = Type::Rendered;
        consteval operator Type() const noexcept { return kType; }
    };
    struct rendered³_k {
        using class_t = Rendered³;
        static constexpr const Type kType = Type::Rendered³;
        consteval operator Type() const noexcept { return kType; }
    };
    struct resource_k {};
    struct rotation_k {};
    struct scale_k {};
    struct scene_k {
        using class_t = Scene;
        static constexpr const Type kType = Type::Scene;
        consteval operator Type() const noexcept { return kType; }
    };
    struct scene³_k {
        using class_t = Scene³;
        static constexpr const Type kType = Type::Scene³;
        consteval operator Type() const noexcept { return kType; }
    };
    
    struct schedule_k {};

    struct shared_k {
        consteval operator DataActivity() const noexcept { return DataActivity::SHARED; }
    };
    
    struct shutdown_k {};

    struct sim_k {
        consteval operator StdThread() const noexcept  { return StdThread::Sim; }
    };
    
    struct south_k {
        consteval operator Cardinal() const noexcept { return Cardinal::South; }
    };
    
    struct spatial_k {
        using class_t = Spatial;
        static constexpr const Type kType = Type::Spatial;
        consteval operator Type() const noexcept { return kType; }
    };
    struct spatial²_k {
        using class_t = Spatial²;
        static constexpr const Type kType = Type::Spatial²;
        consteval operator Type() const noexcept { return kType; }
    };
    struct spatial³_k {
        using class_t = Spatial³;
        static constexpr const Type kType = Type::Spatial³;
        consteval operator Type() const noexcept { return kType; }
    };

    struct static_k {
        consteval operator DataActivity() const noexcept { return DataActivity::STATIC; }
    };
    
    struct swapable_k {};
    
    struct sweep_k {};
    struct tachyon_k {
        using class_t = Tachyon;
    };

    struct task_k {
        consteval operator StdThread() const noexcept  { return StdThread::Task; }
    };
    
    struct teardown_k {};
    struct tex_k {};
    struct texture_k {};
    struct thread_k : public ::yq::thread_k {
        using class_t = Thread;
        static constexpr const Type kType = Type::Thread;
        consteval operator Type() const noexcept { return kType; }
    };
    struct toolbar_k {};
    struct transform_k {};
    struct ui_k {};
    
    struct viewer_k {
        using class_t = Viewer;
        static constexpr const Type kType = Type::Viewer;
        consteval operator Type() const noexcept { return kType; }
        consteval operator StdThread() const noexcept  { return StdThread::Viewer; }
    };

    struct vulqan_k {};
    
    struct west_k {
        consteval operator Cardinal() const noexcept { return Cardinal::West; }
    };
    struct widget_k : public ::yq::widget_k {
        using class_t = Widget;
        static constexpr const Type kType = Type::Widget;
        consteval operator Type() const noexcept { return kType; }
    };
    struct window_k {
        using class_t = Window;
        static constexpr const Type kType = Type::Window;
        consteval operator Type() const noexcept { return kType; }
    };
    
    // any problematic macros....
    #ifdef LOCK
        #undef LOCK
    #endif
    #ifdef ERROR
        #undef ERROR
    #endif
    #ifdef MAX
    #undef MAX
    #endif
    
    #ifdef MIN
    #undef MIN
    #endif
    

    static constexpr const align_k              ALIGN;
    static constexpr const app_k                APP;
    static constexpr const audio_k              AUDIO;
    static constexpr const auxillary_k          AUX, AUXILLARY;
    static constexpr const available_k          AVAILABLE;
    static constexpr const bar_k                BAR;
    static constexpr const browse_k             BROWSE;
    static constexpr const camera_k             CAMERA;
    static constexpr const camera³_k            CAMERA³;
    static constexpr const center_k             CENTER, CENTRE;
    static constexpr const collision_k          COLLISION;
    static constexpr const color_k              COLOR;
    static constexpr const common_k             COMMON;
    static constexpr const content_k            CONTENT;
    static constexpr const controller_k         CONTROLLER;
    static constexpr const controllers_k        CONTROLLERS;
    static constexpr const cursor_k             CURSOR;
    static constexpr const d2l_k                D2L;
    static constexpr const delegate_k           DELEGATE;
    static constexpr const delete_k             DELETE;
    static constexpr const depth_k              DEPTH;
    static constexpr const desktop_k            DESKTOP;
    static constexpr const device_k             DEVICE;
    static constexpr const dialog_k             DIALOG;
    static constexpr const direct_k             DIRECT;
    static constexpr const dock_k               DOCK;
    static constexpr const domain_k             DOMAIN;
    static constexpr const dynamic_k            DYNAMIC;
    static constexpr const east_k               EAST;
    static constexpr const edit_k               EDIT;
    static constexpr const emit_k               EMIT;
    static constexpr const engine_k             ENGINE;
    static constexpr const event_k              EVENT;
    static constexpr const every_k              EVERY;
    static constexpr const external_k           EXTERNAL;
    static constexpr const face_k               FACE;
    static constexpr const fixed_k              FIXED;
    static constexpr const game_k               GAME;
    static constexpr const gamepad_k            GAMEPAD;
    static constexpr const gesture_k            GESTURE;
    static constexpr const glfw_k               GLFW;
    static constexpr const graphics_card_k      GRAPHICS_CARD;
    static constexpr const group_k              GROUP;
    static constexpr const headless_k           HEADLESS;
    static constexpr const imgui_k              IMGUI;
    static constexpr const indent_k             INDENT;
    static constexpr const insert_k             INSERT;
    static constexpr const insertable_k         INSERTABLE;
    static constexpr const interface_k          INTERFACE;
    static constexpr const io_k                 IO;
    static constexpr const joystick_k           JOYSTICK;
    static constexpr const keyboard_k           KEYBOARD;
    static constexpr const kinetic_k            KINETIC;
    static constexpr const kinetic³_k           KINETIC³;
    static constexpr const l2d_k                L2D;
    static constexpr const layer_k              LAYER;
    static constexpr const layout_k             LAYOUT;
    static constexpr const light_k              LIGHT;
    static constexpr const light³_k             LIGHT³;
    static constexpr const manager_k            MANAGER;
    static constexpr const master_k             MASTER;
    static constexpr const maximum_k            MAX;
    static constexpr const maximum_k            MAXIMUM;
    static constexpr const mesh_k               MESH;
    static constexpr const minimum_k            MIN;
    static constexpr const minimum_k            MINIMUM;
    static constexpr const minmax_k             MINMAX;
    static constexpr const model_k              MODEL;
    static constexpr const monitor_k            MONITOR;
    static constexpr const mouse_k              MOUSE;
    static constexpr const network_k            NETWORK;
    static constexpr const none_k               NONE;
    static constexpr const north_k              NORTH;
    static constexpr const origin_k             ORIGIN;
    static constexpr const physics_k            PHYSICS;
    static constexpr const pivot_k              PIVOT;
    static constexpr const point_k              POINT;
    static constexpr const popup_k              POPUP;
    static constexpr const pre_k                PRE;
    static constexpr const probe_k              PROBE;
    static constexpr const proxy_k              PROXY;
    static constexpr const refresh_k            REFRESH;
    static constexpr const rendered_k           RENDERED;
    static constexpr const rendered³_k          RENDERED³;
    static constexpr const resource_k           RESOURCE;
    static constexpr const rotation_k           ROTATION;
    static constexpr const scale_k              SCALE;
    static constexpr const scene_k              SCENE;
    static constexpr const scene³_k             SCENE³;
    static constexpr const schedule_k           SCHEDULE;
    static constexpr const shared_k             SHARED;
    static constexpr const shutdown_k           SHUTDOWN;
    static constexpr const sim_k                SIM;
    static constexpr const south_k              SOUTH;
    static constexpr const spatial_k            SPATIAL;
    static constexpr const spatial²_k           SPATIAL²;
    static constexpr const spatial³_k           SPATIAL³;
    static constexpr const static_k             STATIC;
    static constexpr const swapable_k           SWAPABLE;
    static constexpr const sweep_k              SWEEP;
    static constexpr const tachyon_k            TACHYON;
    static constexpr const task_k               TASK;
    static constexpr const teardown_k           TEARDOWN;
    static constexpr const tex_k                TEX;
    static constexpr const texture_k            TEXTURE;
    static constexpr const thread_k             THREAD;
    static constexpr const toolbar_k            TOOLBAR;
    static constexpr const transform_k          TRANSFORM;
    static constexpr const ui_k                 UI;
    static constexpr const viewer_k             VIEWER;
    static constexpr const vulqan_k             VULQAN;
    static constexpr const west_k               WEST;
    static constexpr const widget_k             WIDGET;
    static constexpr const window_k             WINDOW;
}
