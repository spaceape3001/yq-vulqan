////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViShader.hpp"
#include <yq-vulqan/errors.hpp>
#include <yq-vulqan/logging.hpp>
#include <yq-vulqan/shader/Shader.hpp>
#include <yq-vulqan/v/VqEnumerations.hpp>
#include <yq-vulqan/v/VqStructs.hpp>
#include <yq-vulqan/viz/ViVisualizer.hpp>

namespace yq::tachyon {
    ViShader::ViShader()
    {
    }
    
    ViShader::ViShader(ViVisualizer& viz, const Shader& sh)
    {
        if(viz.device() && sh.payload.data() && sh.payload.bytes()){
            std::error_code ec  = _create(viz, sh);
            if(ec != std::error_code())
                _wipe();
        }
        
    }
    
    ViShader::~ViShader()
    {
        kill();
    }

    std::error_code     ViShader::_create(ViVisualizer&viz, const Shader&sh)
    {
        m_mask  = {};
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
        VkResult res = vkCreateShaderModule(viz.device(), &createInfo, nullptr, &m_shader);
        if(res != VK_SUCCESS){
            vizWarning << "vkCreateShaderModule(" << sh.type.key() << "): " << to_string_view((VqResult) res);
            return errors::shader_cant_create();
        }
        
        m_viz   = &viz;
        return {};
    }
    
    void                ViShader::_kill()
    {
        if(m_shader){
            vkDestroyShaderModule(m_viz->device(), m_shader, nullptr);
        }
    }
    
    void                ViShader::_wipe()
    {
        m_shader    = nullptr;
        m_viz       = nullptr;
        m_mask      = {};
    }

    bool  ViShader::consistent() const
    {
        return m_viz ? (m_shader && m_viz->device()) : !m_shader;
    }
    
    std::error_code         ViShader::create(ViVisualizer&viz, const Shader&sh)
    {
        if(m_shader)
            return m_viz ? (std::error_code) errors::shader_existing() : (std::error_code) errors::shader_bad_state();
        if(!sh.payload.data() || !sh.payload.bytes())
            return errors::shader_empty();
        if(!viz.device())
            return errors::visualizer_uninitialized();
        
        std::error_code ec  = _create(viz, sh);
        if(ec != std::error_code()){
            _wipe();
        }
        return ec;
    }
    
    void                    ViShader::kill()
    {
        if(valid()){
            _kill();
        }
        _wipe();
    }
    
    
    bool  ViShader::valid() const
    {
        return m_viz && m_shader && m_viz->device();
    }
}
