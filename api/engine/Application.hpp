////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/BasicApp.hpp>
#include <basic/DbgRel.hpp>
#include <engine/preamble.hpp>
#include <engine/AppCreateInfo.hpp>
#include <vulkan/vulkan_core.h>
#include <set>
#include <vector>

struct VkInstance_T;

namespace yq {
    namespace engine {

        class Application;
        class Viewer;
        
        /*! \brief Engine/Vulkan application
        
        */
        class Application : public BasicApp {
        public:
        
            //! Global application, if any
            static Application*       app() { return s_app; }
            
            //! Name of this engine
            static std::string_view             engine_name();
            
            //! Version of this engine
            static uint32_t                     engine_version();

            /*! \brief Vulkan instance
            
                If necessary, this will initialize the vulkan *IFF* the app exists and vulkan's not already been
                initialized.
            */
            static VkInstance    vulkan();
        
            /*! \brief Constructor
            
                \param[in]  argc    Pass onto me what the main() was given
                \param[in]  argv    Pass onto me what the main() was given
                \param[in]  aci     Initialization paraemters for this application
            */
            Application(int argc, char* argv[], const AppCreateInfo& aci=AppCreateInfo());
            ~Application();
            
            
            //void    run();
            
            /*!  Simple exec loop for a single window.
            
                Meant as a convienence function to run a single window in a tight event/draw loop
                until the window is ready to be closed
                
                \param[in] win          Viewer to watch
                \param[in] timeout      If positive, throttles the loop to the rate of user input, where timeout 
                                        is the max stall duration.
            */
            void    run_window(Viewer*win, double timeout=0.);
            
            /*! \brief Initializes the GLFW
            
                This initializes the GLFW.  
                
                \note calling instance() or init_vulkan() will automatically initialize GLFW.
            */
            void    init_glfw();
            
            /*! \brief Initializes vulkan instance
            
                \note calling instance() will automatically call this, if necessary.
            */
            bool    init_vulkan();
            
            const std::vector<const char*>&     extensions() const { return m_extensions; }
            const std::vector<const char*>&     layers() const { return m_layers; }
            
            const AppCreateInfo&                app_info() const { return m_appInfo; }
            
            VkInstance                          instance() const { return m_vulkan; }
            
            
        private:
            friend class Viewer;
            
            static Application*                 s_app;
            static VkInstance                   s_vulkan;

            AppCreateInfo                       m_appInfo;
            VkInstance                          m_vulkan        = nullptr;
            //std::vector<VkLayerProperties>      m_allLayerProps;
            //std::vector<VkExtensionProperties>  m_allExtensionProps;
            //std::set<std::string>               m_allLayerNames;
            //std::set<std::string>               m_allExtensionNames;
            std::vector<const char*>            m_extensions;
            std::vector<const char*>            m_layers;
            VkDebugReportCallbackEXT            m_debug         = nullptr;
            bool                                m_glfw        = false;
            
            bool        add_layer(const char*);
            bool        add_extension(const char*);
            
            
            bool        init();
            void        kill();
            
        };

    }
}
