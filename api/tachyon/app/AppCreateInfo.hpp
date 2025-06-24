////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Required.hpp>
#include <yq/macro/debugrel.hpp>
#include <yq/typedef/filesystem_path.hpp>
#include <tachyon/app/ViewerCreateInfo.hpp>
#include <tachyon/os/Platform.hpp>
#include <tachyon/keywords.hpp>
#include <tachyon/vulkan/VulqanCreateInfo.hpp>

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
    class AudioThread;
    class AuxillaryThread;
    class EditThread;
    class GameThread;
    class IOThread;
    class NetworkThread;
    class SimThread;
    class TaskThread;
    class ViewerThread;
    
    using AppCreateThreadFN     = std::function<Ref<AppThread>(Application*)>;

    template <typename T>
    using thread_create_function    = std::function<Ref<T>(Application*)>;

    using thread_enabler_t          = std::variant<bool,disabled_k,enabled_k,per_k,StdThread>;
    
    template <typename T>
    struct thread_spec_t {
        thread_enabler_t            enable;
        thread_create_function<T>   create  = {};

        thread_spec_t(disabled_k) : enable(DISABLED) {}
        thread_spec_t(enabled_k) : enable(ENABLED) {}
        thread_spec_t(bool f) : enable(f) {}
        thread_spec_t(per_k) : enable(PER) {}
        thread_spec_t(const thread_enabler_t& enabled_={}) : enable(enabled_) {}
        thread_spec_t(const thread_create_function<T>& fn) : enable(ENABLED), create(fn) {}
    };

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
            AppCreateThreadFN                   app         = {};
            thread_spec_t<AudioThread>          audio       = DISABLED;
            thread_spec_t<AuxillaryThread>      auxillary   = DISABLED;
            thread_spec_t<EditThread>           edit        = DISABLED;
            thread_spec_t<GameThread>           game        = DISABLED;
            thread_spec_t<IOThread>             io          = DISABLED;
            thread_spec_t<NetworkThread>        network     = DISABLED;
            thread_spec_t<SimThread>            sim         = DISABLED;
            thread_spec_t<TaskThread>           task        = DISABLED;
            thread_spec_t<ViewerThread>         viewer      = ENABLED;
        } thread;
        
        //! Used for app-created viewers
        ViewerCreateInfo            view;

        //! Viewer thread policy
        //ThreadPolicy                vthreads                = ThreadPolicy::Single;
        
        VulqanCreateInfo            vulkan;

        
        AppCreateInfo() = default;
    };
}
