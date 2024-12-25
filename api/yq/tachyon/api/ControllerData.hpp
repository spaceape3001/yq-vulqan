////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/controller.hpp>

namespace yq::tachyon {
    struct ControllerSnap : public TachyonSnap {
        std::set<TachyonID>     controlled;
        std::set<TachyonID>     listening;
        bool                    enabled = false;
    };
    
    struct ControllerData : public TachyonData {
    };
}
