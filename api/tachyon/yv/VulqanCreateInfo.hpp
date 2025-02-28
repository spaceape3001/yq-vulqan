////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Required.hpp>
#include <yq/macro/debugrel.hpp>
#include <yq/typedef/filesystem_path.hpp>
#include <yt/keywords.hpp>
#include <optional>
#include <vector>

namespace yq::tachyon {

    struct NameRequired {
        const char*     name    = nullptr;
        Required        req     = Required::NO;
    };

    struct VulqanCreateInfo {
        //bool        headless        = false;

        uint32_t                    api             = 0;

        bool                        best_practices  = true;

        bool                        enable          = true;

        
        //! Desired extensions (taking optional & yes)
        std::vector<NameRequired>   extensions;
        
        //! Add KHRONOS validation layer
        Required                    validation      = YQ_DBGREL( Required::YES, Required::NO);
            
        //! Desired layers (taking optional & yes)
        std::vector<NameRequired>   layers;
    };
}
