////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/WidgetData.hpp>
#include <yq/shape/AxBox1.hpp>
#include <yt/1D/Layout1Data.hpp>

namespace yq::tachyon {
    struct Widget¹Snap : public WidgetSnap, public Layout¹Snap {
        virtual ~Widget¹Snap();
    };
    
    struct Widget¹Data : public WidgetData {
        virtual ~Widget¹Data();
    };
}
