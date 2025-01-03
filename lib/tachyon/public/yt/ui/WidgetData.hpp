////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yt/typedef/widget.hpp>
#include <yt/typedef/viewer.hpp>

namespace yq::tachyon {
    struct WidgetSnap : public TachyonSnap {
        ViewerID        viewer;
        virtual ~WidgetSnap();
    };
    
    struct WidgetData : public TachyonData {
        virtual ~WidgetData();
    };
}
