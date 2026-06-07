////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/viewer.hpp>
#include <yq/tachyon/typedef/window.hpp>

namespace yq::tachyon {
    class ViewerSnap : public TachyonSnap {
        YQ_OBJECT_DECLARE(ViewerSnap, TachyonSnap)
    public:
        TypedID         window;
        TypedID         widget;
        TypedID         focus;
        //bool            paused  = false;

        ViewerSnap();
        virtual ~ViewerSnap();
        static void init_meta();
    };
    
    class ViewerData : public TachyonData {
        YQ_OBJECT_DECLARE(ViewerData, TachyonData)
    public:
    
        ViewerData();
        virtual ~ViewerData();
        static void init_meta();
    };
}
