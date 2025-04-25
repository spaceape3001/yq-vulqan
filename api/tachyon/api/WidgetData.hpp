////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/TachyonData.hpp>
#include <tachyon/typedef/widget.hpp>
#include <tachyon/typedef/viewer.hpp>

namespace yq::tachyon {
    struct WidgetSnap : public TachyonSnap {
        TypedID         viewer;
        virtual ~WidgetSnap();
    };
    
    struct WidgetData : public TachyonData {
        virtual ~WidgetData();
    };
}
