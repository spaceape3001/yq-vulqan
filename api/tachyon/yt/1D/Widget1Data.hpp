////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/WidgetData.hpp>
#include <yq/shape/AxBox1.hpp>

namespace yq::tachyon {
    struct Widget¹Snap : public WidgetSnap {
        AxBox1D     aabb = ZERO;
        virtual ~Widget¹Snap();
    };
    
    struct Widget¹Data : public WidgetData {
        virtual ~Widget¹Data();
    };
}
