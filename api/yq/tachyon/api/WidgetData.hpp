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
    struct WidgetSnap : public TachyonSnap {
        TypedID         viewer;
        virtual ~WidgetSnap();
    };
    
    struct WidgetData : public TachyonData {
        virtual ~WidgetData();
    };
}
