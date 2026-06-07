////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/controller.hpp>

namespace yq::tachyon {
    class ControllerSnap : public TachyonSnap {
        YQ_OBJECT_DECLARE(ControllerSnap, ControllerSnap)
    public:
        std::set<TypedID>       controlled;
        std::set<TypedID>       listening;
        bool                    enabled = false;
        
        ControllerSnap();
        virtual ~ControllerSnap();
        static void init_meta();
    };
    
    class ControllerData : public TachyonData {
        YQ_OBJECT_DECLARE(ControllerData, ControllerSnap)
    public:
        ControllerData();
        virtual ~ControllerData();
        static void init_meta();
    };
}
