////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tags.hpp>

namespace yq::tachyon {
    //! Use this to make a property listable by a logger
    static constexpr const int kTag_Log         = 2000;
    static constexpr const int kTag_TachyonID   = 2001;
    
    //! Use to make a property show up on the proxy
    static constexpr const int kTag_Proxy       = 2002;
}
