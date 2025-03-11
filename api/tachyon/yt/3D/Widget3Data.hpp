////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/WidgetData.hpp>
#include <yq/shape/AxBox3.hpp>

namespace yq::tachyon {
    struct Widget³Snap : public WidgetSnap {
        AxBox3D     bounds;
        virtual ~Widget³Snap();
    };
    
    struct Widget³Data : public WidgetData {
        virtual ~Widget³Data();
    };
}
