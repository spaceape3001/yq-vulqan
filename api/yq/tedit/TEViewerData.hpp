////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once 

#include <yq/assetvk/widget/CompositeWidgetData.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/physics.hpp>

namespace yq::tachyon {
    struct TEViewerSnap : public CompositeWidgetSnap {
        PhysicsID                   physics;
    };
    
    struct TEViewerData : public CompositeWidgetData {
    };
}
