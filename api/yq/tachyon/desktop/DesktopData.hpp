////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ManagerData.hpp>
#include <yq/tachyon/typedef/desktop.hpp>

namespace yq::tachyon {
    struct DesktopSnap : public ManagerSnap {
    };
    
    struct DesktopData : public ManagerData {
    };
}
