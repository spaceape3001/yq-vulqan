////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/macro/debugrel.hpp>
#include <yq-vulqan/basic/Required.hpp>
#include <yq-vulqan/viewer/ViewerCreateInfo.hpp>

#include <string>
#include <vector>

namespace yq::tachyon {
    struct NameRequired {
        const char*     name    = nullptr;
        Required        req     = Required::NO;
    };


    //! Info for initialization
    struct AppCreateInfo {
    
            //! Used for app-created viewers
        ViewerCreateInfo            view;
    
        //! Application name
        std::string                 app_name;
        
        //! Application version number
        uint32_t                    app_version     = 0;
        
        //! Vulkan API version (zero will default to latest)
        uint32_t                    vulkan_api      = 0;
        
        //! Add KHRONOS validation layer
        Required                    validation      = YQ_DBGREL( Required::YES, Required::NO);
        
        //! Desired extensions (taking optional & yes)
        std::vector<NameRequired>   extensions;
        
        //! Desired layers (taking optional & yes)
        std::vector<NameRequired>   layers;
        
        //! Extra strict validation!
        bool                        want_best_practices = true;
        
        //! Want the task-engine
        bool                        want_tasking        = false;
        
        //! Set to enable running w/o viewers
        bool                        run_without_viewers = false;
        
        AppCreateInfo() = default;
    };
}
