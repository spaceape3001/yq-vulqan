////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/typedef/shader.hpp>
#include <tachyon/pipeline/ShaderType.hpp>

#include <vulkan/vulkan_core.h>
#include <system_error>
#include <yq/core/Ref.hpp>

namespace yq::tachyon {
    class ViDevice;
    class Shader;
    
    //! Shader storage (this is the shader module)
    class ViShader : public RefCount {
    public:
        
        ViShader();
        ViShader(ViDevice&, const Shader&);
        ViShader(VkDevice, const Shader&);
        ~ViShader();
        
        operator VkShaderModule() const { return m_shader; }

        bool                    consistent() const;
        VkShaderStageFlagBits   mask() const { return m_mask; }
        VkShaderModule          shader_module() const { return m_shader; }
        bool                    valid() const;
        //ViDevice*           visualizer() const { return m_viz; }
        
        std::error_code         create(ViDevice&, const Shader&);
        std::error_code         create(VkDevice, const Shader&);
        void                    kill();
        ShaderType              stage() const { return m_stage; }
        
    private:
        VkDevice                m_device    = nullptr;
        VkShaderModule          m_shader    = nullptr;
        VkShaderStageFlagBits   m_mask      = {};
        ShaderType              m_stage;
        
        ViShader(const ViShader&) = delete;
        ViShader(ViShader&&) = delete;
        ViShader& operator=(const ViShader&) = delete;
        ViShader& operator=(ViShader&&) = delete;
        
        std::error_code     _create(VkDevice, const Shader&);
        void                _kill();
        void                _wipe();
    };
}
