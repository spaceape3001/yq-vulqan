////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Flags.hpp>
#include <yq-toolbox/basic/Ref.hpp>
#include <yq-vulqan/typedef/pipeline.hpp>
#include <yq-vulqan/typedef/pipeline_layout.hpp>
#include <yq-vulqan/typedef/shader.hpp>
#include <yq-vulqan/viz/ViData.hpp>

#include <vulkan/vulkan_core.h>

#include <span>
#include <system_error>
#include <vector>

namespace yq::tachyon {
    struct ViPipelineLayoutOptions {
        //  here in case we need to add something in...
    };
    
    /*! \brief Pipeline Layouts
    
        This encapsulates the pipeline layout.  It *ALSO* does the heavy lifting on pipeline creation (shaders, static-data).
    */
    class ViPipelineLayout : public RefCount, public ViData {
    public:
        
        ViPipelineLayout();
        ViPipelineLayout(ViVisualizer&, SharedPipelineConfig, const ViPipelineLayoutOptions& opts={});
        ViPipelineLayout(ViVisualizer&, const Pipeline&, const ViPipelineLayoutOptions& opts={});
        ~ViPipelineLayout();
        
        std::error_code init(ViVisualizer&, SharedPipelineConfig, const ViPipelineLayoutOptions& opts={});
        std::error_code init(ViVisualizer&, const Pipeline&, const ViPipelineLayoutOptions& opts={});
        void            kill();
        
        bool                consistent() const;
        VkPipelineLayout    pipeline_layout() const { return m_pipelineLayout; }
        const auto&         shaders() const { return m_shaders; }
        const auto&         shader_infos() const { return m_shaderInfo; }
        VkShaderStageFlags  shader_mask() const { return m_shaderMask; }
        bool                valid() const;
        const auto&         vertex_attributes() const { return m_vertexAttributes; }
        const auto&         vertex_bindings() const { return m_vertexBindings; }
        const auto&         vertex_create_info() const { return m_vertexCreateInfo; }
        
    private:
    
        bool            _import_shaders();
    
        std::error_code _init(ViVisualizer&, SharedPipelineConfig, const ViPipelineLayoutOptions& opts);
        void            _kill();
        
        VkPipelineLayout                                m_pipelineLayout        = nullptr;
        VkShaderStageFlags                              m_shaderMask    = 0;
        std::vector<VkPipelineShaderStageCreateInfo>    m_shaderInfo;
        std::vector<ViShaderCPtr>                       m_shaders;
        std::vector<VkVertexInputAttributeDescription>  m_vertexAttributes;
        std::vector<VkVertexInputBindingDescription>    m_vertexBindings;
        VkPipelineVertexInputStateCreateInfo            m_vertexCreateInfo{};

        ViPipelineLayout(const ViPipelineLayout&) = delete;
        ViPipelineLayout(ViPipelineLayout&&) = delete;
        ViPipelineLayout& operator=(const ViPipelineLayout&) = delete;
        ViPipelineLayout& operator=(ViPipelineLayout&&) = delete;
    };
}
