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
#include <yv/VulqanCreateInfo.hpp>

#include <optional>
#include <set>
#include <string>
#include <vector>
#include <functional>

namespace yq::tachyon {
    enum class ThreadPolicy {
        //! Viewers go on main thread
        Single,
        //! Viewers go onto seperate individual threads
        Individual
    };
    
    class AppThread;
    class Application;
    
    using AppCreateThreadFN     = std::function<Ref<AppThread>(Application*)>;

    using thread_spec_t         = std::variant<bool,disabled_k,enabled_k,per_k,StdThread>;

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
            AppCreateThreadFN   app     = {};
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
        //ThreadPolicy                vthreads                = ThreadPolicy::Single;
        
        VulqanCreateInfo            vulkan;

        
        AppCreateInfo() = default;
    };
}
