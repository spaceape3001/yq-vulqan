////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Flags.hpp>
#include <yq/core/Ref.hpp>
#include <tachyon/typedef/pipeline.hpp>
#include <tachyon/typedef/pipeline_layout.hpp>
#include <tachyon/typedef/shader.hpp>
#include <tachyon/viz/ViData.hpp>

#include <vulkan/vulkan_core.h>

#include <span>
#include <system_error>
#include <vector>

namespace yq {
    class Stream;
}

namespace yq::tachyon {
    struct ViPipelineLayoutOptions {
        //  here in case we need to add something in...
    };
    
    struct ViPipelineLayoutReportOptions {
        std::string_view    message;
    };
    
    
    /*! \brief Pipeline Layouts
    
        This encapsulates the pipeline layout.  It *ALSO* does the heavy lifting on pipeline creation (shaders, static-data).
    */
    class ViPipelineLayout : public ViData, public RefCount{
    public:
        
        ViPipelineLayout();
        ViPipelineLayout(ViVisualizer&, const Pipeline*, const ViPipelineLayoutOptions& options={});
        ~ViPipelineLayout();
        
        std::error_code init(ViVisualizer&, const Pipeline*, const ViPipelineLayoutOptions& options={});
        void            kill();
        
        bool                consistent() const;
        VkPipelineLayout    pipeline_layout() const { return m_pipelineLayout; }
        bool                push_enabled() const;
        const auto&         shaders() const { return m_shaders; }
        const auto&         shader_infos() const { return m_shaderInfo; }
        VkShaderStageFlags  shader_mask() const { return m_shaderMask; }
        bool                valid() const;
        const auto&         vertex_attributes() const { return m_vertexAttributes; }
        const auto&         vertex_bindings() const { return m_vertexBindings; }
        const auto&         vertex_create_info() const { return m_vertexCreateInfo; }
        const auto&         dynamic_states() const { return m_dynamicStates; }
        
        void                report(Stream&, const ViPipelineLayoutReportOptions& options={}) const;

    private:
    
        bool            _import_shaders();
    
        std::error_code _init(ViVisualizer&, const Pipeline*, const ViPipelineLayoutOptions& options);
        void            _kill();
        
        enum class S : uint8_t {
            Push
        };
        
        VkPipelineLayout                                m_pipelineLayout        = nullptr;
        VkShaderStageFlags                              m_shaderMask    = 0;
        std::vector<VkPipelineShaderStageCreateInfo>    m_shaderInfo;
        std::vector<ViShaderCPtr>                       m_shaders;
        std::vector<VkVertexInputAttributeDescription>  m_vertexAttributes;
        std::vector<VkVertexInputBindingDescription>    m_vertexBindings;
        VkPipelineVertexInputStateCreateInfo            m_vertexCreateInfo{};
        std::vector<VkDynamicState>                     m_dynamicStates;
        Flags<S>                                        m_status = {};

        ViPipelineLayout(const ViPipelineLayout&) = delete;
        ViPipelineLayout(ViPipelineLayout&&) = delete;
        ViPipelineLayout& operator=(const ViPipelineLayout&) = delete;
        ViPipelineLayout& operator=(ViPipelineLayout&&) = delete;
    };
}
