////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/cursor.hpp>

namespace yq::tachyon {
    struct CursorSnap : public TachyonSnap {
    };
    
    struct CursorData : public TachyonData {
    };
}
