////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ManagerData.hpp>
#include <yq/tachyon/enum/LengthUnit.hpp>
#include <yq/gamevk/typedef/master.hpp>

namespace yq::tachyon {
    struct MasterSnap : public ManagerSnap {
        MasterSnap();
        virtual ~MasterSnap();
    };
    
    struct MasterData : public ManagerData {
        MasterData();
        virtual ~MasterData();
    };
}
