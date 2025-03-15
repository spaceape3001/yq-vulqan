////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/WidgetData.hpp>
#include <yq/shape/AxBox2.hpp>

namespace yq::tachyon {
    struct Widget²Snap : public WidgetSnap {
        AxBox2D     aabb = ZERO;
        virtual ~Widget²Snap();
    };
    
    struct Widget²Data : public WidgetData {
        virtual ~Widget²Data();
    };
}
