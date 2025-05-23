////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/TachyonData.hpp>
#include <tachyon/typedef/cursor.hpp>

namespace yq::tachyon {
    struct CursorSnap : public TachyonSnap {
    };
    
    struct CursorData : public TachyonData {
    };
}
