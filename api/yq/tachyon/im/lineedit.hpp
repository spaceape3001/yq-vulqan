////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/typedef/string_vectors.hpp>

namespace yq::tachyon::im {
    struct lineedit_t {
        const char*             drag            = nullptr;
        ImGuiDragDropFlags      drag_flags      = 0;
        string_view_vector_t    drop;
        ImGuiDragDropFlags      drop_flags      = 0;
        ImGuiInputTextFlags     flags           = 0;
        bool                    labelless       = true;
    };
    
    enum class BrowseResult {
        None    = 0,
        Changed,
        Browse
    };
    
    bool            lineedit(const char* label, std::string&, const lineedit_t& opts={});
    BrowseResult    lineedit(browse_k, const char* label, std::string&, const lineedit_t& opts={});


}

