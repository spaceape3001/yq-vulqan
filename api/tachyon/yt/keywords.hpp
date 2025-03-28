////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#define YQ_KEYWORD_OMIT_NONE

#include <yq/keywords.hpp>
#include <yt/api/StdThread.hpp>
#include <yt/gfx/DataActivity.hpp>
#include <yt/os/Platform.hpp>
#include <yt/ui/SizePolicy.hpp>
#include <yq/unit/declare.hpp>

namespace yq::tachyon {

    struct EveryTime;
    struct EveryCount;

    // IF we define these in the toolbox, we'll derive the types
    struct abort_k {};
    struct accept_k {};
    struct add_k {};
    struct addable_k {};
    struct adjust_k {};
    struct adjustable_k {};
    
    struct app_k {
        consteval operator StdThread() const noexcept  { return StdThread::App; }
    };
    
    struct asset_k {};
    
    struct audio_k {
        consteval operator StdThread() const noexcept  { return StdThread::Audio; }
    };

    struct calculate_k {};
    struct camera_k {};
    struct camera³_k {};
    struct changed_k {};
    struct child_k {};
    struct children_k {};
    struct close_k {};

    struct common_k {
        consteval operator DataActivity() const noexcept { return DataActivity::COMMON; }
    };
    
    struct continue_k {};
    struct controller_k {};
    struct controllers_k {};
    struct create_k {};
    struct cursor_k {};
    struct d2l_k    {};
    struct delegate_k {};
    struct delete_k {};
    struct desktop_k {};
    struct direct_k{};
    struct disable_k {};
    struct domain_k {};

    struct dynamic_k {
        consteval operator DataActivity() const noexcept { return DataActivity::DYNAMIC; }
    };
    
    struct emit_k {};
    struct enable_k {};
    struct enabled_k {};
    struct error_k {};

    struct every_k : public ::yq::every_k {
        static constexpr EveryTime    operator()(unit::Second);
        static constexpr EveryCount   operator()(unsigned);
    };
    
    struct failure_k {};

    struct fixed_k {
        consteval operator DataActivity() const noexcept { return DataActivity::FIXED; }
        consteval operator SizePolicy() const noexcept { return kSizePolicy_Fixed; }
    };
    
    struct for_k {};
    struct forward_k {};

    struct game_k {
        consteval operator StdThread() const noexcept  { return StdThread::Game; }
    };
    
    struct gamepad_k {};
    
    struct glfw_k {
        consteval operator Platform() const noexcept { return Platform::GLFW; }
    };
    
    struct graphics_card_k {};
    
    struct has_k {};
    struct hash_k {};
    struct heading_k {};
    struct headless_k {};
    struct inflatable_k {};
    struct info_k {};

    struct io_k {
        consteval operator StdThread() const noexcept  { return StdThread::IO; }
    };
    
    struct joystick_k {};
    struct keyboard_k {};
    struct l2d_k {};
    struct light_k {};
    struct light³_k {};
    struct lock_k {};
    struct locked_k {};
    struct manager_k {};
    struct maximum_k {
        consteval operator SizePolicy() const noexcept { return kSizePolicy_Maximum; }
    };
    struct minimum_k {
        consteval operator SizePolicy() const noexcept { return kSizePolicy_Minimum; }
    };
    struct mismatch_k {};
    struct model_k {};
    struct moveable_k {};
    struct monitor_k {};
    struct mouse_k {};
    struct multipliable_k {};
    struct multiply_k {};
    struct nested_k {};

    struct network_k {
        consteval operator StdThread() const noexcept  { return StdThread::Network; }
    };
    
    struct number_k {};
    
    struct none_k : public ::yq::none_k {
        consteval operator Platform() const noexcept { return Platform::None; }
    };
    
    struct object_k {};
    //struct once_k : public ::yq::once_k {};
    
    struct parent_k {};
    struct pause_k {};
    struct per_k {};
    struct pitch_k {};
    struct probe_k {};
    struct property_k {};
    struct proxy_k {};
    struct ptr_k {};
    struct queue_k {};
    struct read_k {};
    struct rebind_k {};

    struct refresh_k {
        consteval operator DataActivity() const noexcept { return DataActivity::REFRESH; }
    };
    
    struct reject_k {};
    struct rendered_k {};
    struct rendered³_k {};
    struct request_k {};
    struct reset_k {};
    struct resource_k {};
    struct resume_k {};
    struct roll_k {};
    struct root_k {};
    struct rotatable_k {};
    struct rotate_k {};
    struct scalable_k {};
    struct scene_k {};
    struct scene³_k {};
    struct settable_k {};
    
    struct schedule_k {};

    struct shared_k {
        consteval operator DataActivity() const noexcept { return DataActivity::SHARED; }
    };
    
    struct shutdown_k {};

    struct sim_k {
        consteval operator StdThread() const noexcept  { return StdThread::Sim; }
    };
    
    struct spatial_k {};
    struct spatial³_k {};
    struct start_k {};
    struct startup_k {};

    struct static_k {
        consteval operator DataActivity() const noexcept { return DataActivity::STATIC; }
    };
    
    struct stop_k {};
    struct sweep_k {};
    struct table_k {};
    struct tachyon_k {};
    struct target_k {};

    struct task_k {
        consteval operator StdThread() const noexcept  { return StdThread::Task; }
    };
    
    struct teardown_k {};
    struct top_k {};
    struct typed_k {};
    struct types_k {};
    struct unlock_k {};
    struct unlocked_k {};
    struct value_k {};
    struct variable_k {};

    struct viewer_k {
        consteval operator StdThread() const noexcept  { return StdThread::Viewer; }
    };

    struct vulqan_k {};
    struct wait_k {};
    struct widget_k {};
    struct window_k {};
    struct write_k {};
    struct yaw_k {};
    
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
    

    static constexpr abort_k            ABORT;
    static constexpr accept_k           ACCEPT;
    static constexpr add_k              ADD;
    static constexpr addable_k          ADDABLE;
    static constexpr adjust_k           ADJUST;
    static constexpr adjustable_k       ADJUSTABLE;
    static constexpr app_k              APP;
    static constexpr asset_k            ASSET;
    static constexpr audio_k            AUDIO;
    static constexpr calculate_k        CALCULATE;
    static constexpr camera_k           CAMERA;
    static constexpr camera³_k          CAMERA³;
    static constexpr changed_k          CHANGED;
    static constexpr child_k            CHILD;
    static constexpr children_k         CHILDREN;
    static constexpr close_k            CLOSE;
    static constexpr common_k           COMMON;
    static constexpr continue_k         CONTINUE;
    static constexpr controller_k       CONTROLLER;
    static constexpr controllers_k      CONTROLLERS;
    static constexpr create_k           CREATE;
    static constexpr cursor_k           CURSOR;
    static constexpr d2l_k              D2L;
    static constexpr delegate_k         DELEGATE;
    static constexpr delete_k           DELETE;
    static constexpr desktop_k          DESKTOP;
    static constexpr direct_k           DIRECT;
    static constexpr disable_k          DISABLE;
    static constexpr domain_k           DOMAIN;
    static constexpr dynamic_k          DYNAMIC;
    static constexpr emit_k             EMIT;
    static constexpr enable_k           ENABLE;
    static constexpr enabled_k          ENABLED;
    static constexpr error_k            ERROR;
    static constexpr every_k            EVERY;
    static constexpr failure_k          FAILURE;
    static constexpr fixed_k            FIXED;
    static constexpr for_k              FOR;
    static constexpr forward_k          FORWARD;
    static constexpr game_k             GAME;
    static constexpr gamepad_k          GAMEPAD;
    static constexpr graphics_card_k    GRAPHICS_CARD;
    static constexpr glfw_k             GLFW;
    static constexpr has_k              HAS;
    static constexpr hash_k             HASH;
    static constexpr heading_k          HEADING;
    static constexpr headless_k         HEADLESS;
    static constexpr inflatable_k       INFLATABLE;
    static constexpr info_k             INFO;
    static constexpr io_k               IO;
    static constexpr joystick_k         JOYSTICK;
    static constexpr keyboard_k         KEYBOARD;
    static constexpr l2d_k              L2D;
    static constexpr light_k            LIGHT;
    static constexpr light³_k           LIGHT³;
    static constexpr lock_k             LOCK;
    static constexpr locked_k           LOCKED;
    static constexpr manager_k          MANAGER;
    static constexpr maximum_k          MAX;
    static constexpr maximum_k          MAXIMUM;
    static constexpr minimum_k          MIN;
    static constexpr minimum_k          MINIMUM;
    static constexpr mismatch_k         MISMATCH;
    static constexpr model_k            MODEL;
    static constexpr monitor_k          MONITOR;
    static constexpr moveable_k         MOVEABLE;
    static constexpr mouse_k            MOUSE;
    static constexpr multipliable_k     MULTIPLIABLE;
    static constexpr multiply_k         MULTIPLY;
    static constexpr nested_k           NESTED;
    static constexpr network_k          NETWORK;
    static constexpr none_k             NONE;
    static constexpr number_k           NUMBER;
    static constexpr object_k           OBJECT;
    //static constexpr once_k             ONCE;
    static constexpr parent_k           PARENT;
    static constexpr pause_k            PAUSE;
    static constexpr per_k              PER;
    static constexpr pitch_k            PITCH;
    static constexpr probe_k            PROBE;
    static constexpr property_k         PROPERTY;
    static constexpr proxy_k            PROXY;
    static constexpr ptr_k              PTR;
    static constexpr queue_k            QUEUE;
    static constexpr read_k             READ;
    static constexpr rebind_k           REBIND;
    static constexpr refresh_k          REFRESH;
    static constexpr reject_k           REJECT;
    static constexpr rendered_k         RENDERED;
    static constexpr rendered³_k        RENDERED³;
    static constexpr request_k          REQUEST;
    static constexpr reset_k            RESET;
    static constexpr resource_k         RESOURCE;
    static constexpr resume_k           RESUME;
    static constexpr roll_k             ROLL;
    static constexpr root_k             ROOT;
    static constexpr rotatable_k        ROTATABLE;
    static constexpr rotate_k           ROTATE;
    static constexpr scalable_k         SCALABLE;
    static constexpr scene_k            SCENE;
    static constexpr scene³_k           SCENE³;
    static constexpr schedule_k         SCHEDULE;
    static constexpr settable_k         SETTABLE;
    static constexpr shared_k           SHARED;
    static constexpr shutdown_k         SHUTDOWN;
    static constexpr sim_k              SIM;
    static constexpr spatial_k          SPATIAL;
    static constexpr spatial³_k         SPATIAL³;
    static constexpr start_k            START;
    static constexpr startup_k          STARTUP;
    static constexpr static_k           STATIC;
    static constexpr stop_k             STOP;
    static constexpr sweep_k            SWEEP;
    static constexpr table_k            TABLE;
    static constexpr tachyon_k          TACHYON;
    static constexpr target_k           TARGET;
    static constexpr task_k             TASK;
    static constexpr teardown_k         TEARDOWN;
    static constexpr top_k              TOP;
    static constexpr typed_k            TYPED;
    static constexpr types_k            TYPES;
    static constexpr unlock_k           UNLOCK;
    static constexpr unlocked_k         UNLOCKED;
    static constexpr value_k            VALUE;
    static constexpr variable_k         VARIABLE;
    static constexpr viewer_k           VIEWER;
    static constexpr vulqan_k           VULQAN;
    static constexpr wait_k             WAIT;
    static constexpr widget_k           WIDGET;
    static constexpr window_k           WINDOW;
    static constexpr write_k            WRITE;
    static constexpr yaw_k              YAW;
}
