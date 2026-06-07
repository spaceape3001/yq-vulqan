////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/api/TypedID.hpp>
#include <yq/tachyon/typedef/scene.hpp>
#include <yq/color/RGBA.hpp>

namespace yq::tachyon {
    class LayerSnap : public TachyonSnap {
        YQ_OBJECT_DECLARE(LayerSnap, TachyonSnap)
    public:
    
        int         order = 0;
        
        LayerSnap();
        ~LayerSnap();
        static void init_meta();
    };
    
    class LayerData : public TachyonData {
        YQ_OBJECT_DECLARE(LayerData, TachyonData)
    public:
    
        LayerData();
        ~LayerData();
        static void init_meta();
    };
    
}
