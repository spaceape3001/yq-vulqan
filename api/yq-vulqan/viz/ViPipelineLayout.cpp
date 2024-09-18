////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViPipelineLayout.hpp"
#include <yq-toolbox/keywords.hpp>
#include <yq-vulqan/errors.hpp>
#include <yq-vulqan/logging.hpp>
#include <yq-vulqan/pipeline/PipelineConfig.hpp>
#include <yq-vulqan/pipeline/PushData.hpp>
#include <yq-vulqan/shader/Shader.hpp>
#include <yq-vulqan/v/VqStructs.hpp>
#include <yq-vulqan/viz/ViShader.hpp>
#include <yq-vulqan/viz/ViVisualizer.hpp>

namespace yq::tachyon {
    namespace errors {
        using pipeline_layout_bad_state         = error_db::entry<"Pipeline layout is in a bad state">;
        using pipeline_layout_bad_shaders       = error_db::entry<"Pipeline layout is unable to import all the shaders">;
        using pipeline_layout_cant_create       = error_db::entry<"Unable to create the pipeline layout">;
        using pipeline_layout_cant_import_data  = error_db::entry<"Unable to import static object data into the pipeline layout">;
        using pipeline_layout_existing          = error_db::entry<"Pipeline layout has already been created">;
    }

    ViPipelineLayout::ViPipelineLayout()
    {
    }
    
    ViPipelineLayout::ViPipelineLayout(ViVisualizer& viz, SharedPipelineConfig cfg, const ViPipelineLayoutOptions& opts)
    {
        std::error_code ec  = _init(viz, cfg, opts);
        if(ec != std::error_code()){
            vizWarning << "Unable to create a pipeline layout: " << ec.message();
            kill();
        }
    }
    
    ViPipelineLayout::~ViPipelineLayout()
    {
        kill();
    }
    
    bool  ViPipelineLayout::_import_shaders()
    {
        auto & cfg  = *m_config;
    
        m_shaderMask        = 0;
        m_shaders.reserve(cfg.shaders.size());
        m_shaderInfo.reserve(cfg.shaders.size());
        
        for(auto& s : cfg.shaders){
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
    
    std::error_code ViPipelineLayout::_init(ViVisualizer&viz, SharedPipelineConfig cfg, const ViPipelineLayoutOptions& opts)
    {
        VqPipelineLayoutCreateInfo  pipelineLayoutInfo;

        m_viz       = &viz;
        m_config    = cfg;
        if(!_import_shaders()){
            return errors::pipeline_layout_bad_shaders();
        }
        
        std::error_code ec = _init_data(viz, cfg, {
            .descriptors    = ALLOCATE,
            .shaders        = m_shaderMask
        });
        if(ec != std::error_code()){
            return ec;
        }
        
        if(!_import_data()){
            return errors::pipeline_layout_cant_import_data();
        }
        
        //  VERTEX BUFFERS
        for(uint32_t i=0;i<cfg->vbos.size();++i){
            auto& v = cfg->vbos[i];
            
            VkVertexInputBindingDescription b;
            b.binding   = i;
            b.stride    = v.stride;
            b.inputRate = (VkVertexInputRate) v.inputRate.value();
            m_vertexBindings.push_back(b);
            
            for(auto& va : v.attrs){
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
        if(cfg->push.type != PushConfigType::None){
            push.offset     = 0;
            switch(cfg->push.type){
            case PushConfigType::Full:
            case PushConfigType::View:
                push.size   = sizeof(StdPushData);
                break;
            case PushConfigType::Custom:
                push.size   = cfg->push.size;
                break;
            default:
                break;
            }
            
            if(push.size != 0){
                if(cfg->push.shaders){
                    push.stageFlags = cfg->push.shaders;
                } else {
                    push.stageFlags = m_shaderMask;
                }
                
                pipelineLayoutInfo.pushConstantRangeCount = 1;
                pipelineLayoutInfo.pPushConstantRanges = &push;
            }
        }
        
        VkDescriptorSetLayout   descriptorLayouts[1] = { descriptor_set_layout() };
        if(descriptor_count()){
            pipelineLayoutInfo.setLayoutCount   = 1;
            pipelineLayoutInfo.pSetLayouts      = descriptorLayouts;
        }
        
        VkResult    res = vkCreatePipelineLayout(viz.device(), &pipelineLayoutInfo, nullptr, &m_pipelineLayout);
        if(res != VK_SUCCESS){
            vizWarning << "ViPipelineLayout(): Unable to create pipeline layout.  VkResult " << (int32_t) res;
            return errors::pipeline_layout_cant_create();
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
    

    std::error_code ViPipelineLayout::init(ViVisualizer& viz, SharedPipelineConfig cfg, const ViPipelineLayoutOptions& opts)
    {
        if(m_viz){
            if(!consistent()){
                return errors::pipeline_layout_bad_state();
            }
            return errors::pipeline_layout_existing();
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
    
    bool  ViPipelineLayout::valid() const
    {
        return m_viz && m_viz->device() && m_config && m_pipelineLayout;
    }

}
