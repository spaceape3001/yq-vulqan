////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vulkan/vulkan_core.h>
#include <system_error>
#include <yq-vulqan/typedef/shader.hpp>

namespace yq::tachyon {
    class ShaderAsset;
    
    //! Shader storage
    //! \note the Client is expected to manually call create & destroy
    struct ViShader {
        VkShaderModule          shader  = nullptr;
        VkShaderStageFlagBits   mask    = {};
        
        std::error_code     create(VkDevice, const Shader&);
        void                destroy(VkDevice);
    };
}
