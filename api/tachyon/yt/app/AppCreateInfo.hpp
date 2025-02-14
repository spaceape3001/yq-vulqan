////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Required.hpp>
#include <yq/macro/debugrel.hpp>
#include <yq/typedef/filesystem_path.hpp>
#include <yt/app/ViewerCreateInfo.hpp>
#include <yt/os/Platform.hpp>
#include <yt/keywords.hpp>

#include <optional>
#include <set>
#include <string>
#include <vector>

namespace yq::tachyon {
    struct NameRequired {
        const char*     name    = nullptr;
        Required        req     = Required::NO;
    };
    
    enum class ThreadPolicy {
        //! Viewers go on main thread
        Single,
        //! Viewers go onto seperate individual threads
        Individual
    };

    using thread_spec_t    = std::variant<bool,disabled_k,enabled_k,per_k,StdThread>;

    //! Info for initialization
    struct AppCreateInfo {
        //! Application name
        std::string                 app_name;
        
        //! Application version number
        uint32_t                    app_version             = 0;
        
        bool                        headless                = false;
 
        /*! Primary Platform
            
            The primary platform is the one that we'll create viewer windows from.
        */
        Platform                    platform                = GLFW;
        
        //! Other platforms desired (joysticks, keyboards, other things not accounted for in the primary platform)
        std::set<Platform>          platforms;
        
        //! Can be specific, or directories (not recursive)
        path_vector_t               plugins;
        
        /*
            Specify the standard threads.  When supported, the PER will be enabled with ONE dedicated 
            thread per major object (which, for the viewer thread is the Viewer)
        */
        struct {
            thread_spec_t audio       = DISABLED;
            thread_spec_t game        = DISABLED;
            thread_spec_t io          = DISABLED;
            thread_spec_t network     = DISABLED;
            thread_spec_t sim         = DISABLED;
            thread_spec_t task        = DISABLED;
            thread_spec_t viewer      = ENABLED;
        } thread;
        
        //! Used for app-created viewers
        ViewerCreateInfo            view;

        //! Viewer thread policy
        ThreadPolicy                vthreads                = ThreadPolicy::Single;

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
