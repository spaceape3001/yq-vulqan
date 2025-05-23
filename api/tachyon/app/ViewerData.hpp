////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/TachyonData.hpp>
#include <tachyon/api/ID.hpp>
#include <tachyon/typedef/viewer.hpp>
#include <tachyon/typedef/window.hpp>

namespace yq::tachyon {
    struct ViewerSnap : public TachyonSnap {
        TypedID         window;
        TypedID         widget;
        TypedID         focus;
        //bool            paused  = false;
    };
    
    struct ViewerData : public TachyonData {
    };
}
