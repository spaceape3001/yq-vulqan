////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "VqApp.hpp"
#include <yq-vulqan/errors.hpp>
#include <yq-vulqan/logging.hpp>
#include <yq-vulqan/v/VqEnums.hpp>
#include <yq-vulqan/v/VqUtils.hpp>
#include <yq-toolbox/basic/BasicApp.hpp>
#include <yq-toolbox/basic/ErrorDB.hpp>
#include <yq-toolbox/basic/ThreadId.hpp>
#include <yq/macro/make_version.hpp>
#include <tbb/spin_mutex.h>

#define vulkanAlert         yAlert("vulkan")
#define vulkanCritical      yCritical("vulkan")
#define vulkanDebug         yDebug("vulkan")
#define vulkanError         yError("vulkan")
#define vulkanEmergency     yEmergency("vulkan")
#define vulkanFatal         yFatal("vulkan")
#define vulkanInfo          yInfo("vulkan")
#define vulkanNotice        yNotice("vulkan")
#define vulkanWarning       yWarning("vulkan")


namespace yq::tachyon {
    namespace {
        static constexpr const uint32_t kEngineVersion      = YQ_MAKE_VERSION(0, 0, 2);
        static constexpr const char*    szEngineName        = "YQ Tachyon";

        VkBool32 vqDebuggingCallback(
            VkDebugReportFlagsEXT                       flags,
            VkDebugReportObjectTypeEXT                  objectType,
            uint64_t                                    object,
            [[maybe_unused]] size_t                     location,
            [[maybe_unused]] int32_t                    messageCode,
            const char*                                 pLayerPrefix,
            const char*                                 pMessage,
            [[maybe_unused]] void*                      pUserData
        )
        {
            {   // a simple little filter
                using key_t = std::pair<uint64_t, int32_t>;
                static std::set<key_t>  seen;
                static tbb::spin_mutex  mutex;
                key_t k(object, messageCode);
                tbb::spin_mutex::scoped_lock    _lock(mutex);
                auto [i,f]  = seen.insert(k);
                if(!f)
                    return VK_FALSE;
            }
        
            log4cpp::CategoryStream  yell  = (flags & VK_DEBUG_REPORT_ERROR_BIT_EXT) ? vulkanError : 
                                            ((flags & VK_DEBUG_REPORT_WARNING_BIT_EXT) ? vulkanWarning : 
                                             vulkanInfo);
            yell << "Object [" << to_string_view(objectType) << ": " << object << "] (layer " 
                << pLayerPrefix << "): " << pMessage;
        //assert(false && "Exiting");
            return VK_FALSE;
        }
    }

    //  ------------------------------------------------

    VkInstance           VqApp::s_vulkan    = nullptr;
    VqApp*               VqApp::s_app       = nullptr;

    std::string_view     VqApp::engine_name()
    {
        return szEngineName;
    }
    
    uint32_t             VqApp::engine_version()
    {
        return kEngineVersion;
    }

    VkInstance           VqApp::vulkan() 
    { 
        if(s_vulkan) [[likely]]
            return s_vulkan;
        
        if(!s_app){
            vqCritical << "No Engine App has been instantiated!";
            return nullptr;
        }

        static tbb::spin_mutex  mutex;
        tbb::spin_mutex::scoped_lock    _m(mutex);
        if(s_vulkan)
            return s_vulkan;
        if(!s_app-> vk_init())
            return nullptr;
        s_vulkan  = s_app -> m_vulkan;
        return s_vulkan;
    }

    //  ------------------------------------------------

    VqApp::VqApp(BasicApp& bapp, std::shared_ptr<AppCreateInfo>aci) : m_appInfo(aci)
    {
        assert(m_appInfo && "AppCreateInfo is not optional, it must be supplied.");
        if(m_appInfo->app_name.empty())
           m_appInfo->app_name = bapp.app_name();
        if(!m_appInfo->vulkan_api)
            m_appInfo->vulkan_api  = VK_API_VERSION_1_2;
        if((!thread::id()) && !s_app)
            s_app   = this;
    }
    
    VqApp::VqApp(BasicApp& bapp, const AppCreateInfo& aci) : VqApp(bapp, std::make_shared<AppCreateInfo>(aci))
    {
    }
    
    VqApp::~VqApp()
    {
        kill_vulkan();
    }
    
    std::error_code    VqApp::add_layer(const char*z)
    {
        if(!z)
            return errors::null_pointer();
        static const auto availableLayers     = vqNameSet(vqEnumerateInstanceLayerProperties());
        if(!availableLayers.contains(z))
            return create_error<"Unavailable layer requested">();
        m_layers.push_back(z);
        return std::error_code();
    }
    
    std::error_code    VqApp::add_extension(const char*z)
    {
        if(!z)
            return errors::null_pointer();

        static const auto availableExtensions = vqNameSet(vqEnumerateInstanceExtensionProperties());
        if(!availableExtensions.contains(z))
            return create_error<"Unavailable extension requested">();
        
        m_extensions.push_back(z);
        return std::error_code();
    }
    
    std::error_code VqApp::init_vulkan()
    {
        if(m_init)
            return std::error_code();
        
        static const char*  kValidationLayer        = "VK_LAYER_KHRONOS_validation";
        
        bool    want_debug  = false;
        
        std::error_code     ec;

        /*
            Start by scanning the extensions for validation
        */
        if(m_appInfo->validation != Required::NO){
            ec  = add_layer(kValidationLayer);
            if(ec){
                auto stream    = (m_appInfo->validation == Required::YES) ? vqCritical : vqError;
                stream << "Unable to find validation layers!";
                if(m_appInfo->validation == Required::YES)
                    return create_error<"Validation layer is unavailable">();
            } else
                want_debug  = true;
        }

        m_extensions = vqGlfwRequiredExtensions();
        if(want_debug){
            m_extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
            m_extensions.push_back("VK_EXT_debug_report");
        }
        
        for(auto& x : m_appInfo->layers){
            if(!x.name)
                continue;
            ec  = add_layer(x.name);
            if(ec){
                if(x.req != Required::NO){
                    auto stream    = (x.req == Required::YES) ? vqCritical : vqError;
                    stream << "Unable to find vulkan layer: " << x.name;
                    if(x.req == Required::YES)
                        return ec;
                }
            } else {
                vqInfo << "Enabling vulkan layer: " << x.name;
                continue;
            }
        }

        for(auto& x : m_appInfo->extensions){
            if(!x.name)
                continue;
            ec = add_extension(x.name);
            if(ec){
                if(x.req != Required::NO){
                    auto stream    = (x.req == Required::YES) ? vqCritical : vqError;
                    stream << "Unable to find vulkan extension: " << x.name;
                    if(x.req == Required::YES)
                        return ec;
                }
            } else  {
                vqInfo << "Enabling vulkan extension: " << x.name;
                continue;
            }
        }
            
            /*
                Create our device
            */
        
        VqApplicationInfo       lai;
        lai.pApplicationName    = m_appInfo->app_name.c_str();
        lai.applicationVersion  = m_appInfo->app_version;
        lai.pEngineName         = szEngineName;
        lai.engineVersion       = kEngineVersion;
        lai.apiVersion          = m_appInfo->vulkan_api;
        
        VqInstanceCreateInfo    createInfo;
        createInfo.pApplicationInfo             = &lai;
        createInfo.enabledLayerCount            = (uint32_t) m_layers.size();
        if(createInfo.enabledLayerCount)
            createInfo.ppEnabledLayerNames      = m_layers.data();
            
        createInfo.enabledExtensionCount        = (uint32_t) m_extensions.size();
        if(createInfo.enabledExtensionCount)
            createInfo.ppEnabledExtensionNames  = m_extensions.data();
            
        //  IF in debug, adding in best-practices
        VkValidationFeatureEnableEXT enables[] = {VK_VALIDATION_FEATURE_ENABLE_BEST_PRACTICES_EXT};
        VqValidationFeaturesEXT features;
        createInfo.pNext  = &features;
        
        if(m_appInfo->want_best_practices && want_debug){
            features.enabledValidationFeatureCount  = 1;
            features.pEnabledValidationFeatures     = enables;
        }
            
        if(vkCreateInstance(&createInfo, nullptr, &m_vulkan) != VK_SUCCESS){
            vqCritical << "Unable to create vulkan instance!";
            m_vulkan   = nullptr;
            return errors::vulkan_instance_cant_create();
        }
        
        assert(m_vulkan != nullptr);
        if(m_vulkan == nullptr){
            vqCritical << "Vulkan instance is NULL!";
            return errors::vulkan_instance_cant_create();
        } 
        
        vqInfo << "Vulkan instance created.";
            
        if(want_debug){
            // Get the function pointer (required for any extensions)
            auto vkCreateDebugReportCallbackEXT = (PFN_vkCreateDebugReportCallbackEXT)vkGetInstanceProcAddr(m_vulkan, "vkCreateDebugReportCallbackEXT");
            VqDebugReportCallbackCreateInfoEXT debug_report_ci;
            debug_report_ci.flags = VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT | VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT;
            debug_report_ci.pfnCallback = vqDebuggingCallback;
            debug_report_ci.pUserData = nullptr;
            vkCreateDebugReportCallbackEXT(m_vulkan, &debug_report_ci, nullptr, &m_debug);
        }

        m_init  = true;
        return std::error_code();
    }
    
    void        VqApp::kill_vulkan()
    {
        if(m_init){
            if(this == s_app)
                s_app       = nullptr;
            if(m_vulkan == s_vulkan)
                s_vulkan    = nullptr;

            if(m_debug){
                auto vkDestroyDebugReportCallbackEXT = (PFN_vkDestroyDebugReportCallbackEXT)vkGetInstanceProcAddr(m_vulkan, "vkDestroyDebugReportCallbackEXT");
                if(vkDestroyDebugReportCallbackEXT)
                    vkDestroyDebugReportCallbackEXT(m_vulkan, m_debug, nullptr);
            }
        
            if(m_vulkan){
                vkDestroyInstance(m_vulkan, nullptr);
                m_vulkan  = nullptr;
            }
        }
    }

    bool    VqApp::vk_init()
    {
        return init_vulkan() == std::error_code();
    }
}

