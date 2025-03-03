////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yv/ViShader.hpp>
#include <yt/errors.hpp>
#include <yt/logging.hpp>
#include <yt/gfx/Shader.hpp>
#include <yv/VqStructs.hpp>
#include <yv/ViVisualizer.hpp>

namespace yq::tachyon {
    namespace errors {
        using shader_bad_state                  = error_db::entry<"Shader is in a bad state">;
        using shader_cant_create                = error_db::entry<"Unable to create vulkan shader module">;
        using shader_empty                      = error_db::entry<"Shader is empty">;
        using shader_existing                   = error_db::entry<"Shader already created">;
        using shader_uninitialized              = error_db::entry<"Attempting to use an uninitialized shader">;
        using shader_manager_uninitialized      = error_db::entry<"Shader manager is uninitialized">;
    }

    ViShader::ViShader()
    {
    }
    
    ViShader::ViShader(VkDevice dev, const Shader& sh)
    {
        if(dev && sh.payload.data() && sh.payload.bytes()){
            std::error_code ec  = _create(dev, sh);
            if(ec != std::error_code())
                _wipe();
        }
        
    }
    
    ViShader::ViShader(ViVisualizer& viz, const Shader& sh) : ViShader(viz.device(), sh)
    {
    }

    ViShader::~ViShader()
    {
        kill();
    }

    std::error_code     ViShader::_create(VkDevice dev, const Shader&sh)
    {
        m_mask  = {};
        m_stage = sh.type;
        switch(sh.type){
        case ShaderType::VERT:
            m_mask  = VK_SHADER_STAGE_VERTEX_BIT;
            break;
        case ShaderType::TESC:
            m_mask  = VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT;
            break;
        case ShaderType::TESE:
            m_mask  = VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT;
            break;
        case ShaderType::FRAG:
            m_mask  = VK_SHADER_STAGE_FRAGMENT_BIT;
            break;
        case ShaderType::GEOM:
            m_mask  = VK_SHADER_STAGE_GEOMETRY_BIT;
            break;
        case ShaderType::COMP:
            m_mask  = VK_SHADER_STAGE_COMPUTE_BIT;
            break;
        case ShaderType::MESH:
            m_mask  = VK_SHADER_STAGE_MESH_BIT_NV;
            break;
        case ShaderType::TASK:
            m_mask  = VK_SHADER_STAGE_TASK_BIT_NV;
            break;
        default:
            return create_error<"Shader needs a valid/supported type!">();
        }
        
        VqShaderModuleCreateInfo createInfo;
        createInfo.codeSize = sh.payload.bytes();
        createInfo.pCode    = reinterpret_cast<const uint32_t*>(sh.payload.data());
        VkResult res = vkCreateShaderModule(dev, &createInfo, nullptr, &m_shader);
        if(res != VK_SUCCESS){
            vizWarning << "vkCreateShaderModule(" << sh.type.key() << "): VkResult " << (int32_t) res;
            return errors::shader_cant_create();
        }
        
        m_device   = dev;
        return {};
    }
    
    void                ViShader::_kill()
    {
        if(m_shader && m_device){
            vkDestroyShaderModule(m_device, m_shader, nullptr);
        }
    }
    
    void                ViShader::_wipe()
    {
        m_shader    = nullptr;
        m_device    = nullptr;
        m_mask      = {};
    }

    bool  ViShader::consistent() const
    {
        return m_device ? static_cast<bool>(m_shader) : !m_shader;
    }
    
    std::error_code         ViShader::create(VkDevice dev, const Shader&sh)
    {
        if(m_shader)
            return m_device ? (std::error_code) errors::shader_existing() : (std::error_code) errors::shader_bad_state();
        if(!sh.payload.data() || !sh.payload.bytes())
            return errors::shader_empty();
        if(!dev)
            return errors::visualizer_uninitialized();
        
        std::error_code ec  = _create(dev, sh);
        if(ec != std::error_code()){
            _wipe();
        }
        return ec;
    }
    
    std::error_code         ViShader::create(ViVisualizer&viz, const Shader&sh)
    {
        return create(viz.device(), sh);
    }

    void                    ViShader::kill()
    {
        _kill();
        _wipe();
    }
    
    
    bool  ViShader::valid() const
    {
        return m_device && m_shader;
    }
}
