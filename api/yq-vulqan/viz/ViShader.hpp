////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/typedef/shader.hpp>

#include <vulkan/vulkan_core.h>
#include <system_error>
#include <yq-toolbox/basic/Ref.hpp>

namespace yq::tachyon {
    class ViVisualizer;
    class Shader;
    
    //! Shader storage
    //! \note the Client is expected to manually call create & destroy
    class ViShader : public RefCount {
    public:
        
        ViShader();
        ViShader(ViVisualizer&, const Shader&);
        ~ViShader();
        
        operator VkShaderModule() const { return m_shader; }
        VkShaderModule          shader_module() const { return m_shader; }
        
        std::error_code         create(ViVisualizer&, const Shader&);
        void                    kill();
        
        bool                    consistent() const;
        bool                    valid() const;
        
        VkShaderStageFlagBits   mask() const { return m_mask; }
        
    private:
        ViVisualizer*           m_viz       = nullptr;
        VkShaderModule          m_shader    = nullptr;
        VkShaderStageFlagBits   m_mask      = {};
        
        std::error_code     _create(ViVisualizer&, const Shader&);
        void                _kill();
        void                _wipe();
    };
}
