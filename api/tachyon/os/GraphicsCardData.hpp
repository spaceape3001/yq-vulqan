////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/TachyonData.hpp>
#include <tachyon/typedef/graphics_card.hpp>

namespace yq::tachyon {
    struct GraphicsCardSnap : public TachyonSnap {
        std::string         name;
        size_t              heap    = 0;
    };
    
    struct GraphicsCardData : public TachyonData {
    };
}
