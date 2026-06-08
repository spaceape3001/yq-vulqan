////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/graphics_card.hpp>

namespace yq::tachyon {
    class GraphicsCardSnap : public TachyonSnap {
        YQ_OBJECT_DECLARE(GraphicsCardSnap, TachyonSnap)
    public:
        size_t              heap    = 0;
        
        GraphicsCardSnap();
        ~GraphicsCardSnap();
        static void init_meta();
    };
    
    class GraphicsCardData : public TachyonData {
        YQ_OBJECT_DECLARE(GraphicsCardData, TachyonData)
    public:
        GraphicsCardData();
        ~GraphicsCardData();
        static void init_meta();
    };
}
