////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/mouse.hpp>

namespace yq::tachyon {
    class MouseSnap : public TachyonSnap {
        YQ_OBJECT_DECLARE(MouseSnap, TachyonSnap)
    public:
    
        MouseSnap();
        ~MouseSnap();
        static void init_meta();
    };
    
    class MouseData : public TachyonData {
        YQ_OBJECT_DECLARE(MouseData, TachyonData)
    public:
    
        MouseData();
        ~MouseData();
        static void init_meta();
    };
}
