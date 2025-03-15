////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/WidgetData.hpp>
#include <yq/shape/AxBox2.hpp>
#include <yt/2D/Layout2Data.hpp>

namespace yq::tachyon {
    struct Widget²Snap : public WidgetSnap, public Layout²Snap {
        virtual ~Widget²Snap();
    };
    
    struct Widget²Data : public WidgetData {
        virtual ~Widget²Data();
    };
}
