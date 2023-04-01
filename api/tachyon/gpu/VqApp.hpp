////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/trait/not_copyable.hpp>
#include <basic/trait/not_moveable.hpp>
#include <tachyon/AppCreateInfo.hpp>

#include <system_error>
#include <vulkan/vulkan_core.h>

namespace yq {
    class BasicApp;
    
    namespace tachyon {
        class VqApp {
        public:

            //! Name of this engine
            static std::string_view     engine_name();
            
            //! Version of this engine
            static uint32_t             engine_version();

            //! Gets the instance (if any)
            static VkInstance           vulkan();

            VqApp(BasicApp&, const AppCreateInfo& aci=AppCreateInfo());
            ~VqApp();
            
            /*! \brief Initializes vulkan instance
            
                \note calling instance() will automatically call this, if necessary.
            */
            std::error_code     init_vulkan();
            
            const std::vector<const char*>&     extensions() const { return m_extensions; }
            const std::vector<const char*>&     layers() const { return m_layers; }
            
            const AppCreateInfo&                app_info() const { return m_appInfo; }
            
            VkInstance                          instance() const { return m_vulkan; }

        protected:
            void        kill_vulkan();
            
        private:
            AppCreateInfo                       m_appInfo;
            VkInstance                          m_vulkan        = nullptr;
            std::vector<const char*>            m_extensions;
            std::vector<const char*>            m_layers;
            VkDebugReportCallbackEXT            m_debug         = nullptr;
            bool                                m_init          = false;

            static VkInstance                   s_vulkan;
            static VqApp*                       s_app;
        
            std::error_code        add_layer(const char*);
            std::error_code        add_extension(const char*);

                //  Forces a general init
            virtual bool    vk_init();
            
            VqApp(const VqApp&) = delete;
            VqApp(VqApp&&) = delete;
            VqApp& operator=(const VqApp&) = delete;
            VqApp& operator=(VqApp&&) = delete;
        };
    }
    
    namespace engine {
        using tachyon::VqApp;
    }
}
