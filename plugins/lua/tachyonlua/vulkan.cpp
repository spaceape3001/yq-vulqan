////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/core/DelayInit.hpp>
#include <yq/lua/info.hpp>
#include <yq/lua/logging.hpp>
#include <yq/lua/lualua.hpp>
#include <yq/lua/keys.hpp>
#include <yq/lua/info/FunctionInfo.hpp>
#include <yq/lua/info/ModuleInfo.hpp>
#include <yq/tachyon/vulkan/VqUtils.hpp>
#include <yq/tachyon/vulkan/VulqanManager.hpp>
#include <yq/tachyon/vulkan/metatypes.hpp>


#include <lua.hpp>

#include <yq/lua/lualua.hxx>
#include <yq/lua/stdhandlers.hxx>

using namespace yq;
using namespace yq::tachyon;

namespace {
    template <typename T>
    bool vk_push(lua_State* l, const T& val)
    {
        lua_newtable(l);
        int n = lua_gettop(l);
        lua::push(l, RAW, val);
        lua_setfield(l, n, "_ptr");
        return true;
    }
    
    template <typename T>
    bool vk_extract(lua_State* l, int n, T& val)
    {
        auto x = lua::pointer(l, n, TABLE, "_ptr");
        if(!x){
            val = nullptr;
            return false;
        }
        val = (T) *x;
        return true;
    }

    template <typename T>
    T   extract(lua_State*l, int n)
    {
        auto tm = lua::type_meta(l, n);
        if(!tm)
            return nullptr;
        if(*tm != &meta<T>())
            return nullptr;
        auto x = lua::pointer(l, n, TABLE, "_ptr");
        if(!x)
            return nullptr;
        return (T) *x;
    }

    int lh_api_devices(lua_State* l)
    {
        auto data = vqEnumeratePhysicalDevices(VulqanManager::instance());
        
        lua_newtable(l);
        int n = lua_gettop(l);
        int cnt=0;
        for(VkPhysicalDevice dev : data){
            lua::push(l, ANY, dev);
            lua_seti(l, n, cnt);
            ++cnt;
        }
        
        return 1;
    }
    
    int _lh_api_extensions(lua_State*l)
    {
        auto data = yq::tachyon::vqEnumerateInstanceExtensionProperties();

        lua_newtable(l);
        int n = lua_gettop(l);
        int cnt=0;
        for(const auto& dev : data){
            lua::push(l, (std::string_view) dev.extensionName);
            lua_seti(l, n, cnt);
            ++cnt;
        }

        return 1;
    }
    
    int _lh_api_extensions(lua_State* l, VkPhysicalDevice pDev)
    {
        auto data = yq::tachyon::vqEnumerateDeviceExtensionProperties(pDev);

        lua_newtable(l);
        int n = lua_gettop(l);
        int cnt=0;
        for(const auto& dev : data){
            lua::push(l, (std::string_view) dev.extensionName);
            lua_seti(l, n, cnt);
            ++cnt;
        }

        return 1;
    }

    int lh_api_extensions(lua_State*l)
    {
        if(lua_gettop(l) == 0)
            return _lh_api_extensions(l);
        
        auto tmx = lua::type_meta(l, 1);
        if(tmx){
            auto p  = lua::pointer(l, 1, TABLE, "_ptr");
            if(p && *p){
                if(*tmx == &meta<VkPhysicalDevice>())
                    return _lh_api_extensions(l, (VkPhysicalDevice) *p);
            }
        }

        lua_pushnil(l);
        return 1;
    }

    int _lh_api_layers(lua_State*l)
    {
        auto data = yq::tachyon::vqEnumerateInstanceLayerProperties();

        lua_newtable(l);
        int n = lua_gettop(l);
        int cnt=0;
        for(const auto& lay : data){
            lua::push(l, (std::string_view) lay.layerName);
            lua_seti(l, n, cnt);
            ++cnt;
        }

        return 1;
    }
    
    int _lh_api_layers(lua_State*l, VkPhysicalDevice pDev)
    {
        auto data = yq::tachyon::vqEnumerateDeviceLayerProperties(pDev);

        lua_newtable(l);
        int n = lua_gettop(l);
        int cnt=0;
        for(const auto& lay : data){
            lua::push(l, (std::string_view) lay.layerName);
            lua_seti(l, n, cnt);
            ++cnt;
        }

        return 1;
    }

    int lh_api_layers(lua_State* l)
    {
        if(lua_gettop(l) == 0)
            return _lh_api_layers(l);
        
        auto tmx = lua::type_meta(l, 1);
        if(tmx){
            auto p  = lua::pointer(l, 1, TABLE, "_ptr");
            if(p && *p){
                if(*tmx == &meta<VkPhysicalDevice>())
                    return _lh_api_layers(l, (VkPhysicalDevice) *p);
            }
        }

        lua_pushnil(l);
        return 1;
    }
    
    int _lh_api_name(lua_State *l, VkPhysicalDevice dev)
    {
        if(!dev){
            lua_pushnil(l);
            return 1;
        }
        
        VkPhysicalDeviceProperties  props;
        vkGetPhysicalDeviceProperties(dev, &props);
        lua_pushstring(l, props.deviceName);
        return 1;
    }

    int lh_api_name(lua_State *l)
    {
        if(lua_gettop(l) == 0){
            lua_pushnil(l);
            return 1;
        }
        
        auto tmx = lua::type_meta(l, 1);
        if(tmx){
            auto p  = lua::pointer(l, 1, TABLE, "_ptr");
            if(p && *p){
                if(*tmx == &meta<VkPhysicalDevice>())
                    return _lh_api_name(l, (VkPhysicalDevice) *p);
            }
        }

        lua_pushnil(l);
        return 1;
    }

    int lh_api_version(lua_State* l)
    {
        uint32_t    ver = VulqanManager::vulkan_api();
        std::string txt = std::format("{}.{}.{}", VK_API_VERSION_MAJOR(ver), VK_API_VERSION_MINOR(ver), VK_API_VERSION_PATCH(ver));
        lua::push(l, txt);
        return 1;
    }

    int lh_initialized(lua_State*l)
    {
        lua::push(l, VulqanManager::initialized());
        return 1;
    }

    #if 0
        typedef bool (*FNPush)(lua_State*, const T&);
        typedef bool (*FNExtract)(lua_State*, int, T&);
    #endif


    void reg_vulkan()
    {
        using namespace yq::lua;
        
        if(ModuleInfo* mi = reg(MODULE, "vkapi")){
            if(FunctionInfo* fi = mi->add("extensions", lh_api_extensions)){
                fi -> brief("All available extensions");
            }
            
            if(FunctionInfo* fi = mi->add("devices", lh_api_devices)){
                fi->brief("All available devices");
            }

            if(FunctionInfo* fi = mi->add("layers", lh_api_layers)){
                fi -> brief("All available layers");
            }

            if(FunctionInfo* fi = mi->add("version", lh_api_version)){
                fi -> brief("Vulkan API version in use");
            }
        }
        if(ModuleInfo* mi = reg(MODULE, "vulkan")){
            if(FunctionInfo* fi = mi->add("initialized", lh_initialized)){
                fi -> brief("Detects if vulkan is initialized (always true for vulkan lua)");
            }
        }
        if(auto* ti = reg<VkDevice>()){
            ti->pusher(vk_push<VkDevice>);
            ti->extractor(vk_extract<VkDevice>);
        }
        if(auto* ti = reg<VkPhysicalDevice>()){
            ti->pusher(vk_push<VkPhysicalDevice>);
            ti->extractor(vk_extract<VkPhysicalDevice>);
            if(FunctionInfo* fi = ti->add("extensions", lh_api_extensions)){
                fi -> brief("Device extensions");
            }
            if(FunctionInfo* fi = ti->add("layers", lh_api_layers)){
                fi -> brief("Device layers");
            }
            if(FunctionInfo* fi = ti->add("name", lh_api_name)){
                fi -> brief("Device name");
            }
        }
        if(auto* ti = reg<VkInstance>()){
            ti->pusher(vk_push<VkInstance>);
            ti->extractor(vk_extract<VkInstance>);
        }
    }
    
    YQ_INVOKE(reg_vulkan();)
}


