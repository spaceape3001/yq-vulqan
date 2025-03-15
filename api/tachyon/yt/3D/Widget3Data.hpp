////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/WidgetData.hpp>
#include <yq/shape/AxBox3.hpp>
#include <yt/3D/LayoutItem3Data.hpp>

namespace yq::tachyon {
    struct Widget³Snap : public WidgetSnap, public LayoutItem³Snap {
        virtual ~Widget³Snap();
    };
    
    struct Widget³Data : public WidgetData {
        virtual ~Widget³Data();
    };
}
