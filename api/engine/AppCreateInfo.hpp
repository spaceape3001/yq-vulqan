////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/DbgRel.hpp>
#include <engine/preamble.hpp>
#include <string>
#include <vector>

struct VkInstance_T;

namespace yq {
    namespace engine {

        struct NameRequired {
            const char*     name    = nullptr;
            Required        req     = Required::NO;
        };


        //! Info for initialization
        struct AppCreateInfo {
        
            //! Application name
            std::string                  app_name;
            
            //! Application version number
            uint32_t                     app_version     = 0;
            
            
            //! Vulkan API version (zero will default to latest)
            uint32_t                     vulkan_api      = 0;
            
            //! Add KHRONOS validation layer
            Required                     validation      = YQ_DBGREL( Required::YES, Required::NO);
            
            //! Desired extensions (taking optional & yes)
            std::vector<NameRequired>    extensions;
            
            //! Desired layers (taking optional & yes)
            std::vector<NameRequired>    layers;
            
            AppCreateInfo(){}
        };
    }
}
