////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/window.hpp>

namespace yq::tachyon {
    struct WindowSnap : public TachyonSnap {
    };
    
    struct WindowData : public TachyonData {
    };
}
