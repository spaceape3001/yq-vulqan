////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ManagerData.hpp>
#include <yq/tachyon/typedef/desktop.hpp>

namespace yq::tachyon {
    
    class DesktopSnap : public ManagerSnap {
        YQ_OBJECT_DECLARE(DesktopSnap, ManagerSnap)
    public:
    
        DesktopSnap();
        virtual ~DesktopSnap();
        static void init_meta();
    };
    
    class DesktopData : public ManagerData {
        YQ_OBJECT_DECLARE(DesktopData, ManagerData)
    public:
    
        DesktopData();
        virtual ~DesktopData();
        static void init_meta();
    };
}
