////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/manager.hpp>

namespace yq::tachyon {
    class ManagerSnap : public TachyonSnap {
        YQ_OBJECT_DECLARE(ManagerSnap, TachyonSnap)
    public:
        ManagerSnap();
        virtual ~ManagerSnap();
        static void init_meta();
    };
    
    class ManagerData : public TachyonData {
        YQ_OBJECT_DECLARE(ManagerData, TachyonData)
    public:
        ManagerData();
        virtual ~ManagerData();
        static void init_meta();
    };
}
