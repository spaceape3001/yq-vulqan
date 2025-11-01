////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/graphics_card.hpp>

namespace yq::tachyon {
    struct GraphicsCardSnap : public TachyonSnap {
        std::string         name;
        size_t              heap    = 0;
    };
    
    struct GraphicsCardData : public TachyonData {
    };
}
