////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/WidgetData.hpp>
#include <yq/shape/AxBox4.hpp>
#include <yt/4D/LayoutItem4Data.hpp>

namespace yq::tachyon {
    struct Widget⁴Snap : public WidgetSnap, public LayoutItem⁴Snap {
        virtual ~Widget⁴Snap();
    };
    
    struct Widget⁴Data : public WidgetData {
        virtual ~Widget⁴Data();
    };
}
