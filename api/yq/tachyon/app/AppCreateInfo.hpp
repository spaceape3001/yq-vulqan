////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Required.hpp>
#include <yq/macro/debugrel.hpp>
#include <yq/tachyon/app/ViewerCreateInfo.hpp>

#include <optional>
#include <string>
#include <vector>

namespace yq::tachyon {
    struct NameRequired {
        const char*     name    = nullptr;
        Required        req     = Required::NO;
    };
    
    enum class ViewerThreadPolicy {
    
        //! Viewers go on main thread
        Main,
        //! Viewers go on a single viewer thread
        Single,
        //! Viewers go onto seperate individual threads
        Individual
    };


    //! Info for initialization
    struct AppCreateInfo {
        //! Application name
        std::string                 app_name;
        
        //! Application version number
        uint32_t                    app_version             = 0;
        
        //! Enable for GLFW support
        bool                        glfw                    = true;

        //! Set to enable running w/o viewers
        bool                        headless                = false;
        
        bool                        imgui                   = true;

        //! Want the task-engine
        bool                        tasking                 = false;
        
        //! Used for app-created viewers
        ViewerCreateInfo            view;

        ViewerThreadPolicy          vthreads                = ViewerThreadPolicy::Single;

        //! Set to enable vulkan
        bool                        vulkan                  = true;
            
        //! Vulkan API version (zero will default to latest)
        uint32_t                    vulkan_api              = 0;

        //! Extra strict validation!
        bool                        vulkan_best_practices   = true;
            
            
        //! Desired extensions (taking optional & yes)
        std::vector<NameRequired>   vulkan_extensions;
        
        //! Add KHRONOS validation layer
        Required                    vulkan_validation      = YQ_DBGREL( Required::YES, Required::NO);
            
        //! Desired layers (taking optional & yes)
        std::vector<NameRequired>   vulkan_layers;

        
        AppCreateInfo() = default;
    };
}
