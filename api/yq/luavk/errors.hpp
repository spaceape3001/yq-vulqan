////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/ErrorDB.hpp>

namespace yq::errors {
    using luavk_cannot_extract_meta         = error_db::entry<"Cannot extract meta from table">;
    using luavk_no_frame_available          = error_db::entry<"No frame available to consult">;
    using luavk_not_valid_camera_id         = error_db::entry<"Not a valid camera ID">;
    using luavk_not_valid_camera3_id        = error_db::entry<"Not a valid camera³ ID">;
    using luavk_not_valid_collision_id      = error_db::entry<"Not a valid collision ID">;
    using luavk_not_valid_controller_id     = error_db::entry<"Not a valid controller ID">;
    using luavk_not_valid_cursor_id         = error_db::entry<"Not a valid cursor ID">;
    using luavk_not_valid_desktop_id        = error_db::entry<"Not a valid desktop ID">;
    using luavk_not_valid_gamepad_id        = error_db::entry<"Not a valid gamepad ID">;
    using luavk_not_valid_graphics_card_id  = error_db::entry<"Not a valid graphics card ID">;
    using luavk_not_valid_group_id          = error_db::entry<"Not a valid group ID">;
    using luavk_not_valid_joystick_id       = error_db::entry<"Not a valid joystick ID">;
    using luavk_not_valid_keyboard_id       = error_db::entry<"Not a valid keyboard ID">;
    using luavk_not_valid_layer_id          = error_db::entry<"Not a valid layer ID">;
    using luavk_not_valid_light_id          = error_db::entry<"Not a valid light ID">;
    using luavk_not_valid_light3_id         = error_db::entry<"Not a valid light³ ID">;
    using luavk_not_valid_manager_id        = error_db::entry<"Not a valid manager ID">;
    using luavk_not_valid_model_id          = error_db::entry<"Not a valid model ID">;
    using luavk_not_valid_monitor_id        = error_db::entry<"Not a valid monitor ID">;
    using luavk_not_valid_mouse_id          = error_db::entry<"Not a valid mouse ID">;
    using luavk_not_valid_physics_id        = error_db::entry<"Not a valid physics ID">;
    using luavk_not_valid_rendered_id       = error_db::entry<"Not a valid rendered ID">;
    using luavk_not_valid_rendered3_id      = error_db::entry<"Not a valid rendered³ ID">;
    using luavk_not_valid_scene_id          = error_db::entry<"Not a valid scene ID">;
    using luavk_not_valid_scene3_id         = error_db::entry<"Not a valid scene³ ID">;
    using luavk_not_valid_spatial_id        = error_db::entry<"Not a valid spatial ID">;
    using luavk_not_valid_spatial2_id       = error_db::entry<"Not a valid spatial² ID">;
    using luavk_not_valid_spatial3_id       = error_db::entry<"Not a valid spatial³ ID">;
    using luavk_not_valid_stdthread         = error_db::entry<"Not a valid standard thread">;
    using luavk_not_valid_thread_id         = error_db::entry<"Not a valid thread ID">;
    using luavk_not_valid_viewer_id         = error_db::entry<"Not a valid viewer ID">;
    using luavk_not_valid_widget_id         = error_db::entry<"Not a valid widget ID">;
    using luavk_not_valid_window_id         = error_db::entry<"Not a valid window ID">;
    using luavk_not_a_table                 = error_db::entry<"Not a lua table (which is what we use)">;
}
