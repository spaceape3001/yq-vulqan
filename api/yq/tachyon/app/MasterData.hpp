////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ManagerData.hpp>
#include <yq/tachyon/enum/LengthUnit.hpp>
#include <yq/tachyon/typedef/master.hpp>

namespace yq::tachyon {
    class MasterSnap : public ManagerSnap {
        YQ_OBJECT_DECLARE(MasterSnap, ManagerSnap)
    public:
        MasterSnap();
        virtual ~MasterSnap();
        static void init_meta();
    };
    
    class MasterData : public ManagerData {
        YQ_OBJECT_DECLARE(MasterData, ManagerData)
    public:
        MasterData();
        virtual ~MasterData();
        static void init_meta();
    };
}
