////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/widget.hpp>
#include <yq/tachyon/typedef/viewer.hpp>

namespace yq::tachyon {
    class WidgetSnap : public TachyonSnap {
        YQ_OBJECT_DECLARE(WidgetSnap, TachyonSnap)
    public:
        TypedID         viewer;
        
        WidgetSnap();
        virtual ~WidgetSnap();
        
        static void init_meta();
    };
    
    class WidgetData : public TachyonData {
        YQ_OBJECT_DECLARE(WidgetData, TachyonData)
    public:
        WidgetData();
        virtual ~WidgetData();
        static void init_meta();
    };
}
