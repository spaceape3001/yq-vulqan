////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/TachyonData.hpp>
#include <yt/typedef/widget.hpp>
#include <yt/typedef/viewer.hpp>

namespace yq::tachyon {
    struct WidgetSnap : public TachyonSnap {
        TypedID         viewer;
        virtual ~WidgetSnap();
    };
    
    struct WidgetData : public TachyonData {
        virtual ~WidgetData();
    };
}
