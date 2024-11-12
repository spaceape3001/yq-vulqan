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
    
    struct close_t {};
    struct controller_t {};
    struct controllers_t {};
    struct direct_t{};
    struct forward_t {};
    struct number_t {};
    struct probe_t {};
    struct queue_t {};
    struct target_t {};
    struct unlock_t {};
    struct unlocked_t {};
    struct viewer_t {};
    struct widget_t {};
    struct window_t {};

    static constexpr close_t        CLOSE;
    static constexpr common_t       COMMON;
    static constexpr controller_t   CONTROLLER;
    static constexpr controllers_t  CONTROLLERS;
    static constexpr direct_t       DIRECT;
    static constexpr dynamic_t      DYNAMIC;
    static constexpr fixed_t        FIXED;
    static constexpr forward_t      FORWARD;
    static constexpr number_t       NUMBER;
    static constexpr probe_t        PROBE;
    static constexpr refresh_t      REFRESH;
    static constexpr static_t       STATIC;
    static constexpr target_t       TARGET;
    static constexpr queue_t        QUEUE;
    static constexpr unlock_t       UNLOCK;
    static constexpr unlocked_t     UNLOCKED;
    static constexpr viewer_t       VIEWER;
    static constexpr widget_t       WIDGET;
    static constexpr window_t       WINDOW;
}
