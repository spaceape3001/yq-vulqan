////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "button.hpp"

namespace yq::tachyon::im {
    bool    button(const char* label, const button_options_t& opts)
    {
        //  TODO... want it different
        return ImGui::Button(label, opts.size);
    }
    
    bool    button(primary_k, const char* label, const button_options_t& opts)
    {
        //  TODO... want it different
        return button(label, opts);
    }
    
    bool    button(secondary_k, const char* label, const button_options_t& opts)
    {
        //  TODO... want it different
        return button(label, opts);
    }
}
