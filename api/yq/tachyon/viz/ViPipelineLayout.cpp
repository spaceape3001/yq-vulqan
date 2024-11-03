////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViPipelineLayout.hpp"
#include <yq/keywords.hpp>
#include <yq/core/StreamOps.hpp>
#include <yq/tachyon/errors.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/Pipeline.hpp>
#include <yq/tachyon/PushData.hpp>
#include <yq/tachyon/Shader.hpp>
#include <yq/tachyon/v/VqEnums.hpp>
#include <yq/tachyon/v/VqStructs.hpp>
#include <yq/tachyon/viz/ViLogging.hpp>
#include <yq/tachyon/viz/ViShader.hpp>
#include <yq/tachyon/viz/ViVisualizer.hpp>

#include <yq/text/format.hpp>

namespace yq::tachyon {
    namespace errors {
        using pipeline_layout_bad_state         = error_db::entry<"Pipeline layout is in a bad state">;
        using pipeline_layout_bad_shaders       = error_db::entry<"Pipeline layout is unable to import all the shaders">;
        using pipeline_layout_cant_create       = error_db::entry<"Unable to create the pipeline layout">;
        using pipeline_layout_cant_import_data  = error_db::entry<"Unable to import static object data into the pipeline layout">;
        using pipeline_layout_existing          = error_db::entry<"Pipeline layout has already been created">;
        using pipeline_layout_null_pipeline     = error_db::entry<"Pipeline layout cannot be created from a NULL pointer pipeline">;
    }

    ViPipelineLayout::ViPipelineLayout()
    {
    }
    
    ViPipelineLayout::ViPipelineLayout(ViVisualizer& viz, const Pipeline* cfg, const ViPipelineLayoutOptions& opts)
    {
        if(viz.device() && cfg){
            std::error_code ec  = _init(viz, cfg, opts);
            if(ec != std::error_code()){
                vizWarning << "Unable to create a pipeline layout: " << ec.message();
                kill();
            }
        }
    }

    ViPipelineLayout::~ViPipelineLayout()
    {
        kill();
    }
    
    bool  ViPipelineLayout::_import_shaders()
    {
        m_shaderMask        = 0;
        m_shaders.reserve(m_config->m_shaders.size());
        m_shaderInfo.reserve(m_config->m_shaders.size());
        
        for(auto& s : m_config->m_shaders){
            ShaderCPtr  sh  = Shader::decode(s);
            if(!sh){
                vizWarning << "Unable to decode the shader number " << (m_shaders.size()+1) << " on this pipeline layout";
                return false;
            }
            
            ViShaderCPtr    xvs = m_viz -> shader_create(*sh);
            if(!xvs || !xvs->valid()){
                vizWarning << "Unable to load shader number " << (m_shaders.size()+1) << " on this pipeline layout into vulkan ";
                return false;
            }
            
            VqPipelineShaderStageCreateInfo stage;
            stage.stage     = xvs->mask();
            stage.pName     = "main";
            stage.module    = xvs->shader_module();
            m_shaderInfo.push_back(stage);
            m_shaderMask   |= xvs->mask();
            m_shaders.push_back(xvs);
        }
        
        return true;
    }
    
    std::error_code ViPipelineLayout::_init(ViVisualizer&viz, const Pipeline* cfg, const ViPipelineLayoutOptions& opts)
    {
        VqPipelineLayoutCreateInfo  pipelineLayoutInfo;

        m_viz       = &viz;
        m_config    = cfg;
        if(!_import_shaders()){
            return errors::pipeline_layout_bad_shaders();
        }
        
        std::error_code ec = _init_data(viz, cfg, {
            .descriptors    = LAYOUT,
            .flags          = ViDataOptions::F::StaticLayout,
            .shaders        = m_shaderMask
        });
        if(ec != std::error_code()){
            return ec;
        }
        
        if(!_import_data()){
            return errors::pipeline_layout_cant_import_data();
        }
        
        //  VERTEX BUFFERS
        for(uint32_t i=0;i<m_config->m_vertexBuffers.size();++i){
            auto& v = m_config->m_vertexBuffers[i];
            
            VkVertexInputBindingDescription b;
            b.binding   = i;
            b.stride    = v.stride;
            b.inputRate = (VkVertexInputRate) v.inputRate.value();
            m_vertexBindings.push_back(b);
            
            for(auto& va : v.attributes){
                VkVertexInputAttributeDescription   a;
                a.binding       = i;
                a.location      = va.location;
                a.offset        = va.offset;
                a.format        = (VkFormat) va.format.value();
                m_vertexAttributes.push_back(a);
            }
        }
        
        m_vertexCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
        m_vertexCreateInfo.vertexBindingDescriptionCount    = (uint32_t) m_vertexBindings.size();
        m_vertexCreateInfo.pVertexBindingDescriptions       = m_vertexBindings.data();
        m_vertexCreateInfo.vertexAttributeDescriptionCount  = (uint32_t) m_vertexAttributes.size();
        m_vertexCreateInfo.pVertexAttributeDescriptions     = m_vertexAttributes.data();
        
        VkPushConstantRange push{};
        if(m_config->m_push.type != PushConfigType::None){
            push.offset     = 0;
            switch(m_config->m_push.type){
            case PushConfigType::Full:
            case PushConfigType::View:
                push.size   = sizeof(StdPushData);
                break;
            case PushConfigType::Custom:
                push.size   = m_config->m_push.size;
                break;
            default:
                break;
            }
            
            if(push.size != 0){
                if(m_config->m_push.shaders){
                    push.stageFlags = (VkShaderStageFlags) m_config->m_push.shaders;
                } else {
                    push.stageFlags = m_shaderMask;
                }
                
                pipelineLayoutInfo.pushConstantRangeCount = 1;
                pipelineLayoutInfo.pPushConstantRanges = &push;
            }
            m_status |= S::Push;
        }
        
        VkDescriptorSetLayout   descriptorLayouts[1] = { descriptor_set_layout() };
        if(descriptors_defined()){
            pipelineLayoutInfo.setLayoutCount   = 1;
            pipelineLayoutInfo.pSetLayouts      = descriptorLayouts;
        }
        
        VkResult    res = vkCreatePipelineLayout(viz.device(), &pipelineLayoutInfo, nullptr, &m_pipelineLayout);
        if(res != VK_SUCCESS){
            vizWarning << "ViPipelineLayout(): Unable to create pipeline layout.  VkResult " << (int32_t) res;
            return errors::pipeline_layout_cant_create();
        }

        const auto & dynamicStates    = m_config -> dynamic_states();
        if(!dynamicStates.empty()){
            m_dynamicStates.reserve(dynamicStates.size());
            for(DynamicState ds : dynamicStates){
                m_dynamicStates.push_back((VkDynamicState) ds.value());
            }
        }

        return {};
    }
    
    void  ViPipelineLayout::_kill()
    {
        if(m_viz && m_viz->device() && m_pipelineLayout){
            vkDestroyPipelineLayout(m_viz->device(), m_pipelineLayout, nullptr);
        }
        
        m_pipelineLayout = nullptr;
        
        m_shaders.clear();
        m_shaderInfo.clear();
        m_vertexAttributes.clear();
        m_vertexBindings.clear();

        _kill_data();
        
        m_shaderMask        = 0;
        m_vertexCreateInfo  = {};
        m_config            = {};
        m_viz               = nullptr;
    }
    

    std::error_code ViPipelineLayout::init(ViVisualizer& viz, const Pipeline* cfg, const ViPipelineLayoutOptions& opts)
    {
        if(m_viz){
            if(!consistent()){
                return errors::pipeline_layout_bad_state();
            }
            return errors::pipeline_layout_existing();
        }
        if(!cfg){
            return errors::pipeline_layout_null_pipeline();
        }
        
        std::error_code ec = _init(viz, cfg, opts);
        if(ec != std::error_code()){
            vizWarning << "Unable to create a pipeline layout: " << ec.message();
            _kill();
        }
        return ec;
    }
    
    void  ViPipelineLayout::kill()
    {
        _kill();
    }
    
    bool  ViPipelineLayout::consistent() const
    {
        return m_viz ? (m_viz->device() && m_config && m_pipelineLayout) : (!m_config && !m_pipelineLayout);
    }
    
    bool  ViPipelineLayout::push_enabled() const
    {
        return m_status(S::Push);
    }

    void ViPipelineLayout::report(Stream& out, const ViPipelineLayoutReportOptions& options) const
    {
        out << "Report for ViPipelineLayout[" << hex(this) << "] " << options.message << "\n";
        out << "    VkPipelineLayout:           [" << hex(m_pipelineLayout) << "]\n";
        out << "    VkShaderStageFlags:         [" << hex(m_shaderMask) << "]\n";
        out << "    Shader(s):                  " << m_shaders.size() << "\n";
        for(uint32_t i=0;i<m_vertexAttributes.size();++i){
            auto& attr  = m_vertexAttributes[i];
            auto& bind  = m_vertexBindings[attr.binding];
            out << "    VBO(" << i << "): "
                "location=" << attr.location << ", "
                "binding=" << attr.binding << ", " 
                "offset=" << attr.offset << ", "
                "stride=" << bind.stride << ", "
                "format=" << to_string_view(attr.format) <<
                "\n"
            ;
        }
        if(descriptors_defined()){
            out << "    VkDescriptorSetLayout:      [" << hex(descriptor_set_layout()) << "]\n";
            for(const VkDescriptorSetLayoutBinding& desc : m_descriptorSetLayoutBindingVector){
                out << "        " << to_string_view(desc.descriptorType) << ", binding=" << desc.binding << ", count=" 
                    << desc.descriptorCount << ", shaders=" << hex(desc.stageFlags) << '\n';
            }
        }
    }

    bool  ViPipelineLayout::valid() const
    {
        return m_viz && m_viz->device() && m_config && m_pipelineLayout;
    }

}
