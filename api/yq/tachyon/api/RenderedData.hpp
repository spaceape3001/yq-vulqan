////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/rendered.hpp>

namespace yq::tachyon {
    struct RenderedSnap : public TachyonSnap {
    };
    
    struct RenderedData : public TachyonData {
    };
}
