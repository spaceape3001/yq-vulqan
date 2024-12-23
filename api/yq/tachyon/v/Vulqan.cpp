////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/errors.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/AppCreateInfo.hpp>
#include <yq/tachyon/api/ManagerInfoWriter.hpp>
#include "Vulqan.hpp"


#include <yq/tachyon/v/VqEnums.hpp>
#include <yq/tachyon/v/VqStructs.hpp>
#include <yq/tachyon/v/VqUtils.hpp>
#include <yq/tachyon/v/VulqanException.hpp>
#include <yq/tachyon/viz/ViLogging.hpp>

#include <yq/core/BasicApp.hpp>
#include <yq/core/DelayInit.hpp>
#include <yq/core/ThreadId.hpp>
#include <yq/macro/make_version.hpp>
#include <yq/typedef/string_sets.hpp>

#include <atomic>


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


    struct Vulqan::Common {
        Vulqan*                      manager         = nullptr;
        std::atomic_flag             claimed;
        VkInstance                   instance        = nullptr;
        std::string                  app_name;
        uint32_t                     vulkan_api      = 0;
        bool                         validation      = false;
        bool                         best_practices  = false;
        
        struct {
            std::string         name        = "YQ Tachyon";
            uint32_t            version     = YQ_MAKE_VERSION(0, 0, 3);
        } engine;
        
        struct {
            string_view_xset_t                  names;
            std::vector<VkLayerProperties>      properties;
            std::vector<const char*>            requested;
        } layers;

        struct {
            string_view_xset_t                  names;
            std::vector<VkExtensionProperties>  properties;
            std::vector<const char*>            requested;
        } extensions;

        VkDebugReportCallbackEXT                debug         = nullptr;

        
        void    enumerate_extensions();
        void    enumerate_layers();
        
        bool    add_extension(const char*);
        bool    add_layer(const char*);
    };
    
    Vulqan::Common& Vulqan::common()
    {
        static Common s_ret;
        return s_ret;
    }

    // ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    bool    Vulqan::Common::add_extension(const char*z)
    {
        if(!z)
            return false;
        if(!extensions.names.contains(z))
            return false;
        extensions.requested.push_back(z);
        return true;
    }
    
    bool    Vulqan::Common::add_layer(const char* z)
    {
        if(!z)
            return false;
        if(!layers.names.contains(z))
            return false;
        layers.requested.push_back(z);
        return true;
    }

    void    Vulqan::Common::enumerate_extensions()
    {
        uint32_t    count   = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &count, nullptr);
        if(count){
            extensions.properties.resize(count);
            vkEnumerateInstanceExtensionProperties(nullptr, &count, extensions.properties.data());
            for(auto& v : extensions.properties){
                extensions.names.insert(v.extensionName);
            }
        }
    }
    
    void    Vulqan::Common::enumerate_layers()
    {
        uint32_t    count   = 0;
        vkEnumerateInstanceLayerProperties(&count, nullptr);
        if(count){
            layers.properties.resize(count);
            vkEnumerateInstanceLayerProperties(&count, layers.properties.data());
            for(auto& v : layers.properties){
tachyonInfo << "VulqanLayer " << v.layerName;            
                layers.names.insert(v.layerName);
            }
        }
    }

    // ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    void  Vulqan::_init(const AppCreateInfo& aci)
    {
        Common& g   = common();
        
        g.vulkan_api       = aci.vulkan_api;
        if(!g.vulkan_api)
            g.vulkan_api   = VK_API_VERSION_1_3;
        

        g.enumerate_extensions();
        g.enumerate_layers();
        
        static const char*  kValidationLayer        = "VK_LAYER_KHRONOS_validation";
        bool    want_debug  = false;
        
        std::error_code     ec;

        if(aci.vulkan_validation != Required::NO){
            if(g.add_layer(kValidationLayer)){
                want_debug      = true;
                g.validation    = true;
            } else {
                {
                    auto stream    = (aci.vulkan_validation == Required::YES) ? tachyonCritical : tachyonError;
                    stream << "Vulqan: Unable to find validation layer: " << kValidationLayer;
                }
                if(aci.vulkan_validation == Required::YES)
                    throw VulqanException("VulganManager: Required validation layer is unavailable!");
            }
        }

        if(aci.glfw){
            g.extensions.requested = vqGlfwRequiredExtensions();
        }
        if(want_debug){
            g.extensions.requested.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
            g.extensions.requested.push_back("VK_EXT_debug_report");
        }


        for(auto& x : aci.vulkan_layers){
            if(!x.name)
                throw VulqanException("Vulqan: Specified layer name is a null pointer!");
            if(g.add_layer(x.name)){
                tachyonInfo << "Vulqan: Enabling vulkan layer '" << x.name << "'";
            } else {
                {
                    auto stream    = (x.req == Required::YES) ? vqCritical : vqError;
                    stream << "Vulqan: Unable to find requested layer '" << x.name << "'";
                }
                if(x.req == Required::YES){
                    throw VulqanException("Vulqan: Vulkan API missing required layer!");
                }
            }
        }

        for(auto& x : aci.vulkan_extensions){
            if(!x.name)
                throw VulqanException("Vulqan: Specified extension name is a null pointer!");
            if(g.add_extension(x.name)){
                tachyonInfo << "Vulqan: Enabling vulkan extension '" << x.name << "'";
            } else {
                {
                    auto stream    = (x.req == Required::YES) ? vqCritical : vqError;
                    stream << "Vulqan: Unable to find requested extension '" << x.name << "'";
                }
                if(x.req == Required::YES){
                    throw VulqanException("Vulqan: Vulkan API missing required extension!");
                }
            }
        }

            /*
                Create our instance
            */
        
        VqApplicationInfo       lai;
        lai.pApplicationName    = aci.app_name.c_str();
        lai.applicationVersion  = aci.app_version;
        lai.pEngineName         = g.engine.name.c_str();
        lai.engineVersion       = g.engine.version;
        lai.apiVersion          = g.vulkan_api;
        
        VqInstanceCreateInfo    createInfo;
        createInfo.pApplicationInfo             = &lai;
        createInfo.enabledLayerCount            = (uint32_t) g.layers.requested.size();
        if(createInfo.enabledLayerCount)
            createInfo.ppEnabledLayerNames      = g.layers.requested.data();
            
        createInfo.enabledExtensionCount        = (uint32_t) g.extensions.requested.size();
        if(createInfo.enabledExtensionCount)
            createInfo.ppEnabledExtensionNames  = g.extensions.requested.data();
            
        //  IF in debug, adding in best-practices
        VkValidationFeatureEnableEXT enables[] = {VK_VALIDATION_FEATURE_ENABLE_BEST_PRACTICES_EXT};
        VqValidationFeaturesEXT features;
        createInfo.pNext  = &features;
        
        if(aci.vulkan_best_practices && want_debug){
            g.best_practices    = true;
            features.enabledValidationFeatureCount  = 1;
            features.pEnabledValidationFeatures     = enables;
        }
            
        VkResult res = vkCreateInstance(&createInfo, nullptr, &g.instance);
        if(res != VK_SUCCESS){
            tachyonCritical << "Vulqan: unable to create vulkan instance.  Code " << (int) res;
            throw VulqanException("Vulqan: Unable to create vulkan instance!");
        }
        
        assert(g.instance != nullptr);
        if(g.instance == nullptr){
            tachyonCritical << "Vulqan: vulkan instance is a null pointer.";
            throw VulqanException("Vulqan: Vulkan instance is NULL!");
        } 
        
        if(want_debug){
            // Get the function pointer (required for any extensions)
            auto vkCreateDebugReportCallbackEXT = (PFN_vkCreateDebugReportCallbackEXT) vkGetInstanceProcAddr(g.instance, "vkCreateDebugReportCallbackEXT");
            VqDebugReportCallbackCreateInfoEXT debug_report_ci;
            debug_report_ci.flags = VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT | VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT;
            debug_report_ci.pfnCallback = vqDebuggingCallback;
            debug_report_ci.pUserData = nullptr;
            vkCreateDebugReportCallbackEXT(g.instance, &debug_report_ci, nullptr, &g.debug);
        }
    }
    
    void  Vulqan::_kill()
    {
        Common& g   = common();
        if(g.debug){
            auto vkDestroyDebugReportCallbackEXT = (PFN_vkDestroyDebugReportCallbackEXT)vkGetInstanceProcAddr(g.instance, "vkDestroyDebugReportCallbackEXT");
            if(vkDestroyDebugReportCallbackEXT)
                vkDestroyDebugReportCallbackEXT(g.instance, g.debug, nullptr);
        }
        if(g.instance){
            vkDestroyInstance(g.instance, nullptr);
            g.instance  = nullptr;
        }

    }
    
    // ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    Vulqan*   Vulqan::manager()
    {
        return common().manager;
    }
    
    VkInstance       Vulqan::instance()
    {
        return common().instance;
    }

    bool             Vulqan::initialized()
    {
        return static_cast<bool>(common().manager);
    }

    uint32_t         Vulqan::vulkan_api()
    {
        return common().vulkan_api;
    }

    // ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    Vulqan::Vulqan(const AppCreateInfo& appInfo)
    {
        if(yq::thread::id())    // not the main thread...
            throw VulqanException("Vulqan can only be initialized in the main thread!");

        Common&     g = common();
        if(g.claimed.test_and_set())
            throw VulqanException("Vulqan can only have one instance!");
        
        _init(appInfo);

        g.manager   = this;
        tachyonDebug << "Vulqan initialized";
    }
    
    Vulqan::~Vulqan()
    {
        Common& g   = common();
        if(g.manager != this)
            return;
            
        _kill();
        g.manager   = nullptr;
        tachyonDebug << "Vulqan destroyed";
    }

    //void Vulqan::handle(Event&evt)
    //{
        //// monitor connect/disconnect
    //}
    
    void Vulqan::init_info()
    {
        auto w = writer<Vulqan>();
        w.abstract();   // prohibit creation outside of main
        w.description("Tachyon Vulkan Manager");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Vulqan)

