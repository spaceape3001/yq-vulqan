////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/viewer.hpp>

namespace yq::tachyon {
    struct ViewerSnap : public TachyonSnap {
    };
    
    struct ViewerData : public TachyonData {
    };
}
