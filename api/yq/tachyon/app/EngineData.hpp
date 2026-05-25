////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/api/ManagerData.hpp>
#include <yq/tachyon/typedef/engine.hpp>

namespace yq::tachyon {
    struct EngineSnap : public ManagerSnap {
    
        Meter               engine_scale;
    
        EngineSnap();
        virtual ~EngineSnap();
    };
    
    struct EngineData : public ManagerData {
        EngineData();
        virtual ~EngineData();
    };
}
