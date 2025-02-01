////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/TachyonData.hpp>
#include <yt/typedef/manager.hpp>

namespace yq::tachyon {
    struct ManagerSnap : public TachyonSnap {
        ManagerSnap();
        virtual ~ManagerSnap();
    };
    
    struct ManagerData : public TachyonData {
        ManagerData();
        virtual ~ManagerData();
    };
}
