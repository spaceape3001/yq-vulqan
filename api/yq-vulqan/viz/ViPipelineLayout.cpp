////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViPipelineLayout.hpp"
#include <yq-toolbox/keywords.hpp>
#include <yq-toolbox/io/StreamOps.hpp>
#include <yq-vulqan/errors.hpp>
#include <yq-vulqan/logging.hpp>
#include <yq-vulqan/pipeline/Pipeline.hpp>
#include <yq-vulqan/pipeline/PipelineConfig.hpp>
#include <yq-vulqan/pipeline/PushData.hpp>
#include <yq-vulqan/shader/Shader.hpp>
#include <yq-vulqan/v/VqEnums.hpp>
#include <yq-vulqan/v/VqStructs.hpp>
#include <yq-vulqan/viz/ViLogging.hpp>
#include <yq-vulqan/viz/ViShader.hpp>
#include <yq-vulqan/viz/ViVisualizer.hpp>

#include <yq-toolbox/text/format.hpp>

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

    ViPipelineLayout::ViPipelineLayout(ViVisualizer& viz, const Pipeline& pipe, const ViPipelineLayoutOptions& opts) :
        ViPipelineLayout(viz, pipe.config(), opts)
    {
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
                    push.stageFlags = (VkShaderStageFlags) cfg->push.shaders;
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

    std::error_code ViPipelineLayout::init(ViVisualizer&viz, const Pipeline&pipe, const ViPipelineLayoutOptions& opts)
    {
        return init(viz, pipe.config(), opts);
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
                "   location=" << attr.location << ", "
                "   binding=" << attr.binding << ", " 
                "   offset=" << attr.offset << ", "
                "   stride=" << bind.stride << ", "
                "   format=" << to_string_view(attr.format) <<
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
