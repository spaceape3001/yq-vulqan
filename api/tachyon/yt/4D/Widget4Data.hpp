////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/WidgetData.hpp>
#include <yq/shape/AxBox4.hpp>

namespace yq::tachyon {
    struct Widget⁴Snap : public WidgetSnap {
        AxBox4D     aabb;
        virtual ~Widget⁴Snap();
    };
    
    struct Widget⁴Data : public WidgetData {
        virtual ~Widget⁴Data();
    };
}
