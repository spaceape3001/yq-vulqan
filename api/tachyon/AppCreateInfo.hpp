////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/gpu/VqAppCreateInfo.hpp>

namespace yq {
    namespace tachyon {
        struct AppCreateInfo : public VqAppCreateInfo {
        };
    }
    
    namespace engine {
        using tachyon::AppCreateInfo;
    }
}

