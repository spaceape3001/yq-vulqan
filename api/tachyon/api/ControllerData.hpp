////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/TachyonData.hpp>
#include <tachyon/typedef/controller.hpp>

namespace yq::tachyon {
    struct ControllerSnap : public TachyonSnap {
        std::set<TypedID>       controlled;
        std::set<TypedID>       listening;
        bool                    enabled = false;
        
        ControllerSnap();
        virtual ~ControllerSnap();
    };
    
    struct ControllerData : public TachyonData {
        ControllerData();
        virtual ~ControllerData();
    };
}
