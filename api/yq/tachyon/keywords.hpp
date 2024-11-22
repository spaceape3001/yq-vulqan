////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/keywords.hpp>
#include <yq/tachyon/enum/DataActivity.hpp>

namespace yq::tachyon {

    // IF we define these in the toolbox, we'll derive the types
    struct common_t {
        consteval operator DataActivity() const noexcept { return DataActivity::COMMON; }
    };
    struct dynamic_t {
        consteval operator DataActivity() const noexcept { return DataActivity::DYNAMIC; }
    };
    struct fixed_t {
        consteval operator DataActivity() const noexcept { return DataActivity::FIXED; }
    };
    struct refresh_t {
        consteval operator DataActivity() const noexcept { return DataActivity::REFRESH; }
    };
    struct static_t {
        consteval operator DataActivity() const noexcept { return DataActivity::STATIC; }
    };
    
    struct abort_t {};
    struct accept_t {};
    struct changed_t {};
    struct children_t {};
    struct close_t {};
    struct continue_t {};
    struct controller_t {};
    struct controllers_t {};
    struct delete_t {};
    struct direct_t{};
    struct disable_t {};
    struct error_t {};
    struct for_t {};
    struct forward_t {};
    struct hash_t {};
    struct info_t {};
    struct lock_t {};
    struct locked_t {};
    struct number_t {};
    struct parent_t {};
    struct pause_t {};
    struct probe_t {};
    struct proxy_t {};
    struct queue_t {};
    struct reject_t {};
    struct resume_t {};
    struct settable_t {};
    struct stop_t {};
    struct tachyon_t {};
    struct target_t {};
    struct typed_t {};
    struct types_t {};
    struct unlock_t {};
    struct unlocked_t {};
    struct viewer_t {};
    struct widget_t {};
    struct window_t {};

    // any problematic macros....
    #ifdef LOCK
        #undef LOCK
    #endif
    #ifdef ERROR
        #undef ERROR
    #endif
    

    static constexpr abort_t        ABORT;
    static constexpr accept_t       ACCEPT;
    static constexpr changed_t      CHANGED;
    static constexpr children_t     CHILDREN;
    static constexpr close_t        CLOSE;
    static constexpr common_t       COMMON;
    static constexpr continue_t     CONTINUE;
    static constexpr controller_t   CONTROLLER;
    static constexpr controllers_t  CONTROLLERS;
    static constexpr delete_t       DELETE;
    static constexpr direct_t       DIRECT;
    static constexpr disable_t      DISABLE;
    static constexpr dynamic_t      DYNAMIC;
    static constexpr error_t        ERROR;
    static constexpr fixed_t        FIXED;
    static constexpr for_t          FOR;
    static constexpr forward_t      FORWARD;
    static constexpr hash_t         HASH;
    static constexpr info_t         INFO;
    static constexpr lock_t         LOCK;
    static constexpr locked_t       LOCKED;
    static constexpr number_t       NUMBER;
    static constexpr parent_t       PARENT;
    static constexpr pause_t        PAUSE;
    static constexpr probe_t        PROBE;
    static constexpr proxy_t        PROXY;
    static constexpr queue_t        QUEUE;
    static constexpr refresh_t      REFRESH;
    static constexpr reject_t       REJECT;
    static constexpr resume_t       RESUME;
    static constexpr settable_t     SETTABLE;
    static constexpr static_t       STATIC;
    static constexpr stop_t         STOP;
    static constexpr tachyon_t      TACHYON;
    static constexpr target_t       TARGET;
    static constexpr typed_t        TYPED;
    static constexpr types_t        TYPES;
    static constexpr unlock_t       UNLOCK;
    static constexpr unlocked_t     UNLOCKED;
    static constexpr viewer_t       VIEWER;
    static constexpr widget_t       WIDGET;
    static constexpr window_t       WINDOW;
}
