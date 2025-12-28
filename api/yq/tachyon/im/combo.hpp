////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/MyImGui.hpp>

namespace yq {
    struct combo_options_t {    
        ImGuiComboFlags     flags       = 0;
        bool                labelless   = true;
    };


    #if 0 // From ImGui.h
    IMGUI_API bool          Combo(const char* label, int* current_item, const char* const items[], int items_count, int popup_max_height_in_items = -1);
    IMGUI_API bool          Combo(const char* label, int* current_item, const char* items_separated_by_zeros, int popup_max_height_in_items = -1);      // Separate items with \0 within a string, end item-list with \0\0. e.g. "One\0Two\0Three\0"
    IMGUI_API bool          Combo(const char* label, int* current_item, const char* (*getter)(void* user_data, int idx), void* user_data, int items_count, int popup_max_height_in_items = -1);
    #endif

}
