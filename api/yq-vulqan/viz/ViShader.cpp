////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViShader.hpp"
#include <yq-toolbox/basic/ErrorDB.hpp>
#include <yq-vulqan/shader/Shader.hpp>
#include <yq-vulqan/v/VqStructs.hpp>

namespace yq::tachyon {
    std::error_code     ViShader::create(VkDevice dev, const Shader& sh)
    {
        mask  = VkShaderStageFlagBits{};
        switch(sh.type){
        case ShaderType::VERT:
            mask    = VK_SHADER_STAGE_VERTEX_BIT;
            break;
        case ShaderType::TESC:
            mask    = VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT;
            break;
        case ShaderType::TESE:
            mask    = VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT;
            break;
        case ShaderType::FRAG:
            mask    = VK_SHADER_STAGE_FRAGMENT_BIT;
            break;
        case ShaderType::GEOM:
            mask    = VK_SHADER_STAGE_GEOMETRY_BIT;
            break;
        case ShaderType::COMP:
            mask    = VK_SHADER_STAGE_COMPUTE_BIT;
            break;
        default:
            return create_error<"Shader needs a valid/supported type!">();
        }
            
        VqShaderModuleCreateInfo createInfo;
        createInfo.codeSize = sh.payload.bytes();
        createInfo.pCode    = reinterpret_cast<const uint32_t*>(sh.payload.data());
        if (vkCreateShaderModule(dev, &createInfo, nullptr, &shader) != VK_SUCCESS) {
            shader  = nullptr;
            return create_error<"Shader creation failed">();
        }
        return std::error_code();
    }
    
    void                ViShader::destroy(VkDevice dev)
    {
        if(shader){
            vkDestroyShaderModule(dev, shader, nullptr);
            shader  = nullptr;
        }
    }
}
