////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/WidgetData.hpp>

namespace yq::tachyon {
    struct Widget²Snap : public WidgetSnap {
        virtual ~Widget²Snap();
    };
    
    struct Widget²Data : public WidgetData {
        virtual ~Widget²Data();
    };
}
