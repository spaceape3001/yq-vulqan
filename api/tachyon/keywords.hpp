////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#define YQ_KEYWORD_OMIT_NONE

#include <yq/keywords.hpp>
#include <tachyon/api/StdThread.hpp>
#include <tachyon/gfx/DataActivity.hpp>
#include <tachyon/os/Platform.hpp>
#include <tachyon/enum/Cardinal.hpp>
#include <tachyon/api/SizePolicy.hpp>
#include <yq/unit/declare.hpp>

namespace yq::tachyon {

    struct EveryTime;
    struct EveryCount;

    // IF we define these in the toolbox, we'll derive the types
    struct align_k {};
    
    struct app_k {
        consteval operator StdThread() const noexcept  { return StdThread::App; }
    };
    
    
    struct audio_k {
        consteval operator StdThread() const noexcept  { return StdThread::Audio; }
    };

    struct bar_k {};

    struct camera_k {};
    struct camera³_k {};
    struct center_k {
        consteval operator Cardinal() const noexcept { return Cardinal::Center; }
    };

    struct common_k {
        consteval operator DataActivity() const noexcept { return DataActivity::COMMON; }
    };
    
    struct content_k {};
    
    struct controller_k {};
    struct controllers_k {};
    struct cursor_k {};
    struct d2l_k    {};
    struct delegate_k {};
    struct desktop_k {};
    struct dialog_k {};
    struct direct_k{};
    struct dock_k {};
    struct domain_k {};

    struct dynamic_k {
        consteval operator DataActivity() const noexcept { return DataActivity::DYNAMIC; }
    };
    
    struct east_k {
        consteval operator Cardinal() const noexcept { return Cardinal::East; }
    };
    
    struct emit_k {};

    struct every_k : public ::yq::every_k {
        static constexpr EveryTime    operator()(unit::Second);
        static constexpr EveryCount   operator()(unsigned);
    };
    
    struct fixed_k {
        consteval operator DataActivity() const noexcept { return DataActivity::FIXED; }
        consteval operator SizePolicy() const noexcept { return kSizePolicy_Fixed; }
    };
    

    struct game_k {
        consteval operator StdThread() const noexcept  { return StdThread::Game; }
    };
    
    struct gamepad_k {};
    
    struct glfw_k {
        consteval operator Platform() const noexcept { return Platform::GLFW; }
    };
    
    struct graphics_card_k {};
    
    struct headless_k {};

    struct io_k {
        consteval operator StdThread() const noexcept  { return StdThread::IO; }
    };
    
    struct joystick_k {};
    struct keyboard_k {};
    struct l2d_k {};
    struct layout_k {};
    struct light_k {};
    struct light³_k {};
    struct manager_k {};
    struct maximum_k {
        consteval operator SizePolicy() const noexcept { return kSizePolicy_Maximum; }
    };
    struct minimum_k {
        consteval operator SizePolicy() const noexcept { return kSizePolicy_Minimum; }
    };
    struct model_k {};
    struct monitor_k {};
    struct mouse_k {};

    struct network_k {
        consteval operator StdThread() const noexcept  { return StdThread::Network; }
    };
    
    struct none_k : public ::yq::none_k {
        consteval operator Platform() const noexcept { return Platform::None; }
    };
    
    struct north_k {
        consteval operator Cardinal() const noexcept { return Cardinal::North; }
    };
    
    //struct once_k : public ::yq::once_k {};
    
    
    struct popup_k {};
    struct probe_k {};
    struct proxy_k {};

    struct refresh_k {
        consteval operator DataActivity() const noexcept { return DataActivity::REFRESH; }
    };
    
    struct rendered_k {};
    struct rendered³_k {};
    struct resource_k {};
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
    
    struct south_k {
        consteval operator Cardinal() const noexcept { return Cardinal::South; }
    };
    
    struct spatial_k {};
    struct spatial²_k {};
    struct spatial³_k {};

    struct static_k {
        consteval operator DataActivity() const noexcept { return DataActivity::STATIC; }
    };
    
    struct sweep_k {};
    struct table_k {};
    struct tachyon_k {};

    struct task_k {
        consteval operator StdThread() const noexcept  { return StdThread::Task; }
    };
    
    struct teardown_k {};
    struct ui_k {};
    

    struct viewer_k {
        consteval operator StdThread() const noexcept  { return StdThread::Viewer; }
    };

    struct vulqan_k {};
    
    struct west_k {
        consteval operator Cardinal() const noexcept { return Cardinal::West; }
    };
    struct widget_k {};
    struct window_k {};
    
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
    static constexpr const bar_k                BAR;
    static constexpr const camera_k             CAMERA;
    static constexpr const camera³_k            CAMERA³;
    static constexpr const center_k             CENTER, CENTRE;
    static constexpr const common_k             COMMON;
    static constexpr const content_k            CONTENT;
    static constexpr const controller_k         CONTROLLER;
    static constexpr const controllers_k        CONTROLLERS;
    static constexpr const cursor_k             CURSOR;
    static constexpr const d2l_k                D2L;
    static constexpr const delegate_k           DELEGATE;
    static constexpr const delete_k             DELETE;
    static constexpr const desktop_k            DESKTOP;
    static constexpr const dialog_k             DIALOG;
    static constexpr const direct_k             DIRECT;
    static constexpr const dock_k               DOCK;
    static constexpr const domain_k             DOMAIN;
    static constexpr const dynamic_k            DYNAMIC;
    static constexpr const east_k               EAST;
    static constexpr const emit_k               EMIT;
    static constexpr const every_k              EVERY;
    static constexpr const fixed_k              FIXED;
    static constexpr const game_k               GAME;
    static constexpr const gamepad_k            GAMEPAD;
    static constexpr const graphics_card_k      GRAPHICS_CARD;
    static constexpr const glfw_k               GLFW;
    static constexpr const headless_k           HEADLESS;
    static constexpr const io_k                 IO;
    static constexpr const joystick_k           JOYSTICK;
    static constexpr const keyboard_k           KEYBOARD;
    static constexpr const l2d_k                L2D;
    static constexpr const layout_k             LAYOUT;
    static constexpr const light_k              LIGHT;
    static constexpr const light³_k             LIGHT³;
    static constexpr const manager_k            MANAGER;
    static constexpr const maximum_k            MAX;
    static constexpr const maximum_k            MAXIMUM;
    static constexpr const minimum_k            MIN;
    static constexpr const minimum_k            MINIMUM;
    static constexpr const model_k              MODEL;
    static constexpr const monitor_k            MONITOR;
    static constexpr const mouse_k              MOUSE;
    static constexpr const network_k            NETWORK;
    static constexpr const none_k               NONE;
    static constexpr const north_k              NORTH;
    //static constexpr const once_k               ONCE;
    static constexpr const popup_k              POPUP;
    static constexpr const probe_k              PROBE;
    static constexpr const proxy_k              PROXY;
    static constexpr const refresh_k            REFRESH;
    static constexpr const rendered_k           RENDERED;
    static constexpr const rendered³_k          RENDERED³;
    static constexpr const resource_k           RESOURCE;
    static constexpr const scene_k              SCENE;
    static constexpr const scene³_k             SCENE³;
    static constexpr const schedule_k           SCHEDULE;
    static constexpr const settable_k           SETTABLE;
    static constexpr const shared_k             SHARED;
    static constexpr const shutdown_k           SHUTDOWN;
    static constexpr const sim_k                SIM;
    static constexpr const south_k              SOUTH;
    static constexpr const spatial_k            SPATIAL;
    static constexpr const spatial²_k           SPATIAL²;
    static constexpr const spatial³_k           SPATIAL³;
    static constexpr const static_k             STATIC;
    static constexpr const sweep_k              SWEEP;
    static constexpr const table_k              TABLE;
    static constexpr const tachyon_k            TACHYON;
    static constexpr const task_k               TASK;
    static constexpr const teardown_k           TEARDOWN;
    static constexpr const ui_k                 UI;
    static constexpr const viewer_k             VIEWER;
    static constexpr const vulqan_k             VULQAN;
    static constexpr const west_k               WEST;
    static constexpr const widget_k             WIDGET;
    static constexpr const window_k             WINDOW;
}
