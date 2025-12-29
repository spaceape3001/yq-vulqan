////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/im/lineedit.hpp>

namespace yq::tachyon::im {
    bool            input(const char* label, std::string&, const lineedit_t& opts={});
    BrowseResult    input(browse_k, const char* label, std::string&, const lineedit_t& opts={});
}
