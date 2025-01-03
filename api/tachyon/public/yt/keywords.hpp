////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/keywords.hpp>
#include <yt/gfx/DataActivity.hpp>
#include <yq/unit/declare.hpp>

namespace yq::tachyon {

    // IF we define these in the toolbox, we'll derive the types
    struct common_k {
        consteval operator DataActivity() const noexcept { return DataActivity::COMMON; }
    };
    struct dynamic_k {
        consteval operator DataActivity() const noexcept { return DataActivity::DYNAMIC; }
    };
    struct fixed_k {
        consteval operator DataActivity() const noexcept { return DataActivity::FIXED; }
    };
    struct refresh_k {
        consteval operator DataActivity() const noexcept { return DataActivity::REFRESH; }
    };
    struct static_k {
        consteval operator DataActivity() const noexcept { return DataActivity::STATIC; }
    };
    
    struct abort_k {};
    struct accept_k {};
    struct adjust_k {};
    struct adjustable_k {};
    struct app_k {};
    struct calculate_k {};
    struct camera_k {};
    struct camera³_k {};
    struct changed_k {};
    struct child_k {};
    struct children_k {};
    struct close_k {};
    struct continue_k {};
    struct controller_k {};
    struct controllers_k {};
    struct create_k {};
    struct cursor_k {};
    struct d2l_k    {};
    struct delete_k {};
    struct desktop_k {};
    struct direct_k{};
    struct disable_k {};
    struct domain_k {};
    struct enable_k {};
    struct enabled_k {};
    struct error_k {};
    
    struct EveryTime;
    struct EveryCount;
    
    struct every_k : public ::yq::every_k {
        static constexpr EveryTime    operator()(unit::Second);
        static constexpr EveryCount   operator()(unsigned);
    };
    
    struct failure_k {};
    struct for_k {};
    struct forward_k {};
    struct glfw_k {};
    struct hash_k {};
    struct heading_k {};
    struct inflatable_k {};
    struct info_k {};
    struct joystick_k {};
    struct keyboard_k {};
    struct l2d_k {};
    struct light_k {};
    struct light³_k {};
    struct lock_k {};
    struct locked_k {};
    struct manager_k {};
    struct mismatch_k {};
    struct model_k {};
    struct moveable_k {};
    struct monitor_k {};
    struct mouse_k {};
    struct number_k {};
    
    struct once_k : public ::yq::once_k {
    };
    
    struct parent_k {};
    struct pause_k {};
    struct pitch_k {};
    struct probe_k {};
    struct proxy_k {};
    struct ptr_k {};
    struct queue_k {};
    struct reject_k {};
    struct rendered³_k {};
    struct rendered_k {};
    struct resume_k {};
    struct roll_k {};
    struct root_k {};
    struct scalable_k {};
    struct scene_k {};
    struct scene³_k {};
    struct settable_k {};
    struct spatial_k {};
    struct spatial³_k {};
    struct stop_k {};
    struct tachyon_k {};
    struct task_k {};
    struct target_k {};
    struct top_k {};
    struct typed_k {};
    struct types_k {};
    struct unlock_k {};
    struct unlocked_k {};
    struct viewer_k {};
    struct vulqan_k {};
    struct widget_k {};
    struct window_k {};
    struct yaw_k {};
    
    // any problematic macros....
    #ifdef LOCK
        #undef LOCK
    #endif
    #ifdef ERROR
        #undef ERROR
    #endif
    

    static constexpr abort_k        ABORT;
    static constexpr accept_k       ACCEPT;
    static constexpr adjust_k       ADJUST;
    static constexpr adjustable_k   ADJUSTABLE;
    static constexpr app_k          APP;
    static constexpr calculate_k    CALCULATE;
    static constexpr camera_k       CAMERA;
    static constexpr camera³_k      CAMERA³;
    static constexpr changed_k      CHANGED;
    static constexpr child_k        CHILD;
    static constexpr children_k     CHILDREN;
    static constexpr close_k        CLOSE;
    static constexpr common_k       COMMON;
    static constexpr continue_k     CONTINUE;
    static constexpr controller_k   CONTROLLER;
    static constexpr controllers_k  CONTROLLERS;
    static constexpr create_k       CREATE;
    static constexpr cursor_k       CURSOR;
    static constexpr d2l_k          D2L;
    static constexpr delete_k       DELETE;
    static constexpr desktop_k      DESKTOP;
    static constexpr direct_k       DIRECT;
    static constexpr disable_k      DISABLE;
    static constexpr domain_k       DOMAIN;
    static constexpr dynamic_k      DYNAMIC;
    static constexpr enable_k       ENABLE;
    static constexpr enabled_k      ENABLED;
    static constexpr error_k        ERROR;
    static constexpr every_k        EVERY;
    static constexpr failure_k      FAILURE;
    static constexpr fixed_k        FIXED;
    static constexpr for_k          FOR;
    static constexpr forward_k      FORWARD;
    static constexpr glfw_k         GLFW;
    static constexpr hash_k         HASH;
    static constexpr heading_k      HEADING;
    static constexpr inflatable_k   INFLATABLE;
    static constexpr info_k         INFO;
    static constexpr joystick_k     JOYSTICK;
    static constexpr keyboard_k     KEYBOARD;
    static constexpr l2d_k          L2D;
    static constexpr light_k        LIGHT;
    static constexpr light³_k       LIGHT³;
    static constexpr lock_k         LOCK;
    static constexpr locked_k       LOCKED;
    static constexpr manager_k      MANAGER;
    static constexpr mismatch_k     MISMATCH;
    static constexpr model_k        MODEL;
    static constexpr monitor_k      MONITOR;
    static constexpr moveable_k     MOVEABLE;
    static constexpr mouse_k        MOUSE;
    static constexpr number_k       NUMBER;
    static constexpr once_k         ONCE;
    static constexpr parent_k       PARENT;
    static constexpr pause_k        PAUSE;
    static constexpr pitch_k        PITCH;
    static constexpr probe_k        PROBE;
    static constexpr proxy_k        PROXY;
    static constexpr ptr_k          PTR;
    static constexpr queue_k        QUEUE;
    static constexpr refresh_k      REFRESH;
    static constexpr reject_k       REJECT;
    static constexpr rendered_k     RENDERED;
    static constexpr rendered³_k    RENDERED³;
    static constexpr resume_k       RESUME;
    static constexpr roll_k         ROLL;
    static constexpr root_k         ROOT;
    static constexpr scalable_k     SCALABLE;
    static constexpr scene_k        SCENE;
    static constexpr scene³_k       SCENE³;
    static constexpr settable_k     SETTABLE;
    static constexpr spatial_k      SPATIAL;
    static constexpr spatial³_k     SPATIAL³;
    static constexpr static_k       STATIC;
    static constexpr stop_k         STOP;
    static constexpr tachyon_k      TACHYON;
    static constexpr target_k       TARGET;
    static constexpr task_k         TASK;
    static constexpr top_k          TOP;
    static constexpr typed_k        TYPED;
    static constexpr types_k        TYPES;
    static constexpr unlock_k       UNLOCK;
    static constexpr unlocked_k     UNLOCKED;
    static constexpr viewer_k       VIEWER;
    static constexpr vulqan_k       VULQAN;
    static constexpr widget_k       WIDGET;
    static constexpr window_k       WINDOW;
    static constexpr yaw_k          YAW;
}
