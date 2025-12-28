////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/MyImGui.hpp>
#include <yq/typedef/string_vectors.hpp>
#include <yq/typedef/url.hpp>

namespace yq::tachyon::im {

    /*
        TYPE -- ImGui imposes a 32-character limit on "type" names, so idea is
        
            (asset)_(qualifier)
            
        ${thing}_url    (urls -- preferred)
        
            payload should be string representation
        
        ${thing}_file   (filepaths)

            payload should be string representation

        ${thing}_id     IDs
        
            payload should be uint64
        
        ${thing}_meta   Meta
        
            payload should be uint64 (the meta id)

    */

    const ImGuiPayload*   accept_drop(const char* type, ImGuiDragDropFlags flags = 0);
    const ImGuiPayload*   accept_drop(const string_view_vector_t& types, ImGuiDragDropFlags flags = 0);
    
    bool    begin_drag_source(ImGuiDragDropFlags flags=0);
    bool    begin_drop_target();
    
    void    end_drag_source();
    void    end_drop_target();
    
    const ImGuiPayload* get_drag_payload();

    // Expecting overloads here...
        
    bool    set_drag_payload(const char* type, const void*, size_t, ImGuiCond cond = 0);
    bool    set_drag_payload(const char* type, std::string_view, ImGuiCond cond = 0);
    bool    set_drag_payload(const char* type, uint64_t, ImGuiCond cond = 0);
    bool    set_drag_payload(const char* type, const Url&, ImGuiCond cond = 0);
    
    // doing the filesystem path... leads to ambiguous errors... 
}

