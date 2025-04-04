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

    struct bar_k {};

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
    struct height_k {};
    struct inflatable_k {};
    struct info_k {};

    struct io_k {
        consteval operator StdThread() const noexcept  { return StdThread::IO; }
    };
    struct items_k {};
    
    struct joystick_k {};
    struct keyboard_k {};
    struct l2d_k {};
    struct light_k {};
    struct light³_k {};
    struct lock_k {};
    struct locked_k {};
    struct main_k {};
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
    
    struct popup_k {};
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
    struct ui_k {};
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
    

    static constexpr const abort_k              ABORT;
    static constexpr const accept_k             ACCEPT;
    static constexpr const add_k                ADD;
    static constexpr const addable_k            ADDABLE;
    static constexpr const adjust_k             ADJUST;
    static constexpr const adjustable_k         ADJUSTABLE;
    static constexpr const app_k                APP;
    static constexpr const asset_k              ASSET;
    static constexpr const audio_k              AUDIO;
    static constexpr const bar_k                BAR;
    static constexpr const calculate_k          CALCULATE;
    static constexpr const camera_k             CAMERA;
    static constexpr const camera³_k            CAMERA³;
    static constexpr const changed_k            CHANGED;
    static constexpr const child_k              CHILD;
    static constexpr const children_k           CHILDREN;
    static constexpr const close_k              CLOSE;
    static constexpr const common_k             COMMON;
    static constexpr const continue_k           CONTINUE;
    static constexpr const controller_k         CONTROLLER;
    static constexpr const controllers_k        CONTROLLERS;
    static constexpr const cursor_k             CURSOR;
    static constexpr const d2l_k                D2L;
    static constexpr const delegate_k           DELEGATE;
    static constexpr const delete_k             DELETE;
    static constexpr const desktop_k            DESKTOP;
    static constexpr const direct_k             DIRECT;
    static constexpr const disable_k            DISABLE;
    static constexpr const domain_k             DOMAIN;
    static constexpr const dynamic_k            DYNAMIC;
    static constexpr const emit_k               EMIT;
    static constexpr const enable_k             ENABLE;
    static constexpr const enabled_k            ENABLED;
    static constexpr const error_k              ERROR;
    static constexpr const every_k              EVERY;
    static constexpr const failure_k            FAILURE;
    static constexpr const fixed_k              FIXED;
    static constexpr const for_k                FOR;
    static constexpr const forward_k            FORWARD;
    static constexpr const game_k               GAME;
    static constexpr const gamepad_k            GAMEPAD;
    static constexpr const graphics_card_k      GRAPHICS_CARD;
    static constexpr const glfw_k               GLFW;
    static constexpr const has_k                HAS;
    static constexpr const hash_k               HASH;
    static constexpr const heading_k            HEADING;
    static constexpr const headless_k           HEADLESS;
    static constexpr const height_k             HEIGHT;
    static constexpr const inflatable_k         INFLATABLE;
    static constexpr const info_k               INFO;
    static constexpr const io_k                 IO;
    static constexpr const items_k              ITEMS;
    static constexpr const joystick_k           JOYSTICK;
    static constexpr const keyboard_k           KEYBOARD;
    static constexpr const l2d_k                L2D;
    static constexpr const light_k              LIGHT;
    static constexpr const light³_k             LIGHT³;
    static constexpr const lock_k               LOCK;
    static constexpr const locked_k             LOCKED;
    static constexpr const main_k               MAIN;
    static constexpr const manager_k            MANAGER;
    static constexpr const maximum_k            MAX;
    static constexpr const maximum_k            MAXIMUM;
    static constexpr const minimum_k            MIN;
    static constexpr const minimum_k            MINIMUM;
    static constexpr const mismatch_k           MISMATCH;
    static constexpr const model_k              MODEL;
    static constexpr const monitor_k            MONITOR;
    static constexpr const moveable_k           MOVEABLE;
    static constexpr const mouse_k              MOUSE;
    static constexpr const multipliable_k       MULTIPLIABLE;
    static constexpr const multiply_k           MULTIPLY;
    static constexpr const nested_k             NESTED;
    static constexpr const network_k            NETWORK;
    static constexpr const none_k               NONE;
    static constexpr const number_k             NUMBER;
    static constexpr const object_k             OBJECT;
    //static constexpr const once_k               ONCE;
    static constexpr const parent_k             PARENT;
    static constexpr const pause_k              PAUSE;
    static constexpr const per_k                PER;
    static constexpr const pitch_k              PITCH;
    static constexpr const popup_k              POPUP;
    static constexpr const probe_k              PROBE;
    static constexpr const property_k           PROPERTY;
    static constexpr const proxy_k              PROXY;
    static constexpr const ptr_k                PTR;
    static constexpr const queue_k              QUEUE;
    static constexpr const read_k               READ;
    static constexpr const rebind_k             REBIND;
    static constexpr const refresh_k            REFRESH;
    static constexpr const reject_k             REJECT;
    static constexpr const rendered_k           RENDERED;
    static constexpr const rendered³_k          RENDERED³;
    static constexpr const request_k            REQUEST;
    static constexpr const reset_k              RESET;
    static constexpr const resource_k           RESOURCE;
    static constexpr const resume_k             RESUME;
    static constexpr const roll_k               ROLL;
    static constexpr const root_k               ROOT;
    static constexpr const rotatable_k          ROTATABLE;
    static constexpr const rotate_k             ROTATE;
    static constexpr const scalable_k           SCALABLE;
    static constexpr const scene_k              SCENE;
    static constexpr const scene³_k             SCENE³;
    static constexpr const schedule_k           SCHEDULE;
    static constexpr const settable_k           SETTABLE;
    static constexpr const shared_k             SHARED;
    static constexpr const shutdown_k           SHUTDOWN;
    static constexpr const sim_k                SIM;
    static constexpr const spatial_k            SPATIAL;
    static constexpr const spatial³_k           SPATIAL³;
    static constexpr const start_k              START;
    static constexpr const startup_k            STARTUP;
    static constexpr const static_k             STATIC;
    static constexpr const stop_k               STOP;
    static constexpr const sweep_k              SWEEP;
    static constexpr const table_k              TABLE;
    static constexpr const tachyon_k            TACHYON;
    static constexpr const target_k             TARGET;
    static constexpr const task_k               TASK;
    static constexpr const teardown_k           TEARDOWN;
    static constexpr const top_k                TOP;
    static constexpr const typed_k              TYPED;
    static constexpr const types_k              TYPES;
    static constexpr const ui_k                 UI;
    static constexpr const unlock_k             UNLOCK;
    static constexpr const unlocked_k           UNLOCKED;
    static constexpr const value_k              VALUE;
    static constexpr const variable_k           VARIABLE;
    static constexpr const viewer_k             VIEWER;
    static constexpr const vulqan_k             VULQAN;
    static constexpr const wait_k               WAIT;
    static constexpr const widget_k             WIDGET;
    static constexpr const window_k             WINDOW;
    static constexpr const write_k              WRITE;
    static constexpr const yaw_k                YAW;
}
