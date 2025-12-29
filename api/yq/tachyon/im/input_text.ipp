////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "input_text.hpp"

namespace yq::tachyon::im {
    bool            input(const char* label, std::string&v, const lineedit_t& opts)
    {
        return lineedit(label, v, opts);
    }
    
    BrowseResult    input(browse_k, const char* label, std::string&v, const lineedit_t& opts)
    {
        return lineedit(BROWSE, label, v, opts);
    }
}
