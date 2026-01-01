////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "vulqan.hpp"

#include <yq/core/StringLiteral.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/vulkan/VulqanManager.hpp>
#include <vulkan/vulkan_core.h>

//  UNITY BUILD HERE (if being done)

bool operator==(const VkOffset2D&a, const VkOffset2D&b)
{
    return (a.x == b.x) && (a.y == b.y);
}

bool operator==(const VkExtent2D&a, const VkExtent2D&b)
{
    return (a.width == b.width) && (a.height == b.height);
}

bool operator==(const VkRect2D&a, const VkRect2D&b)
{
    return (a.offset == b.offset) && (a.extent == b.extent);
}

bool operator==(const VkViewport&a, const VkViewport&b)
{
    return (a.x == b.x) && (a.y == b.y) && 
        (a.width == b.width) && (a.height == b.height) && 
        (a.minDepth == b.minDepth) && (a.maxDepth == b.maxDepth);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  THUNKING
//
//  This is simply wrapping what OUGHT to be a library linkage with the usual get/call function pointer cycle.
//  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename FN, typename ... T>
struct vk_thunk_deducer {
    using result_t  = std::invoke_result_t<FN, T...>;
    static constexpr const bool is_vkresult     = std::is_same_v<result_t,VkResult>;
    static constexpr const bool is_void         = std::is_same_v<result_t,void>;
    static constexpr const bool is_notvoid      = !is_void;
    static constexpr const bool is_returning    = !(is_vkresult || is_void);
};

template <yq::StringLiteral name, typename FN, typename ... T>
auto vk_thunk(T... args) -> typename vk_thunk_deducer<FN,T...>::result_t
{
    using traits_t  = vk_thunk_deducer<FN, T...>;
    
    static FN  func = nullptr;
    if(!func){
        static VkInstance   vkInstance;
        if(!vkInstance){
            vkInstance      = yq::tachyon::VulqanManager::instance();
            if(!vkInstance){
                if constexpr (traits_t::is_vkresult) { return VK_NOT_READY; }
                if constexpr (traits_t::is_returning) { return typename traits_t::result_t{}; }
                if constexpr (traits_t::is_void) { return ; }
            }
            func    = (FN) vkGetInstanceProcAddr( vkInstance, name.c_str());
        }
        
        if(!func){
            vqOnceAlert << "Unable to thunk vulkan call \"" << name.view() << "\", search for extension/version to use";
            if constexpr (traits_t::is_vkresult) { return VK_ERROR_INITIALIZATION_FAILED; }
            if constexpr (traits_t::is_returning) { return typename traits_t::result_t{}; }
            if constexpr (traits_t::is_void) { return ; }
        }
    }

    if constexpr (traits_t::is_notvoid)
        return (*func)(args...);
    if constexpr (traits_t::is_void)
        (*func)(args...);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  ADAPTER FUNCTIONS
//
//  Keep these listed alphabetically and we'll deprecate/remove as functions are brought into the vulkan standard linkage.
//  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static inline VkInstance vk_instance() { return yq::tachyon::VulqanManager::instance(); }




///////////////////////////////////////////////////////
//  THUNKING CODE ONLY!  (No interpretations here)

VkResult vkCreateDebugReportCallback(
    const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkDebugReportCallbackEXT* pCallback
)
{
    return vk_thunk<"vkCreateDebugReportCallbackEXT", PFN_vkCreateDebugReportCallbackEXT>(vk_instance(), pCreateInfo, pAllocator, pCallback);
}
    
VkResult vkCreateDebugUtilsMessenger(const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
    const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger
)
{
    return vk_thunk<"vkCreateDebugUtilsMessengerEXT", PFN_vkCreateDebugUtilsMessengerEXT>(vk_instance(), pCreateInfo, pAllocator, pMessenger);
}

void    vkDestroyDebugReportCallback(
                VkDebugReportCallbackEXT        callback,
                const VkAllocationCallbacks*    pAllocator
            )
{
    vk_thunk<"vkDestroyDebugReportCallbackEXT", PFN_vkDestroyDebugReportCallbackEXT>(vk_instance(), callback, pAllocator);
}

void vkDestroyDebugUtilsMessenger(VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks* pAllocator)
{
    vk_thunk<"vkDestroyDebugUtilsMessengerEXT", PFN_vkDestroyDebugUtilsMessengerEXT>(vk_instance(), messenger, pAllocator);
}

VkResult vkSetDebugUtilsObjectName(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo)
{
    return vk_thunk<"vkSetDebugUtilsObjectNameEXT", PFN_vkSetDebugUtilsObjectNameEXT>(device, pNameInfo);
}


