////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/typedef/shader.hpp>

#include <vulkan/vulkan_core.h>
#include <system_error>
#include <yq/core/Ref.hpp>

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

        bool                    consistent() const;
        VkShaderStageFlagBits   mask() const { return m_mask; }
        VkShaderModule          shader_module() const { return m_shader; }
        bool                    valid() const;
        ViVisualizer*           visualizer() const { return m_viz; }
        
        std::error_code         create(ViVisualizer&, const Shader&);
        void                    kill();
        
    private:
        ViVisualizer*           m_viz       = nullptr;
        VkShaderModule          m_shader    = nullptr;
        VkShaderStageFlagBits   m_mask      = {};
        
        ViShader(const ViShader&) = delete;
        ViShader(ViShader&&) = delete;
        ViShader& operator=(const ViShader&) = delete;
        ViShader& operator=(ViShader&&) = delete;
        
        std::error_code     _create(ViVisualizer&, const Shader&);
        void                _kill();
        void                _wipe();
    };
}
