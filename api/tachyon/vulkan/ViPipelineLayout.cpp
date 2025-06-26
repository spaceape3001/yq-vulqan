////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/vulkan/ViPipelineLayout.hpp>
#include <yq/keywords.hpp>
#include <yq/core/StreamOps.hpp>
#include <tachyon/errors.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/gfx/Pipeline.hpp>
#include <tachyon/gfx/PushData.hpp>
#include <tachyon/gfx/Shader.hpp>
#include <tachyon/vulkan/VqEnums.hpp>
#include <tachyon/vulkan/VqStructs.hpp>
#include <tachyon/vulkan/ViDevice.hpp>
#include <tachyon/vulkan/ViLogging.hpp>
#include <tachyon/vulkan/ViShader.hpp>
#include <tachyon/vulkan/ViDevice.hpp>

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
    
    ViPipelineLayout::ViPipelineLayout(ViDevice& viz, const Pipeline* cfg, const ViPipelineLayoutOptions& opts)
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
        
        using ShaderMap = std::map<ShaderType, ViShaderCPtr>;
        
        ShaderMap  defShaders;
        
        for(auto& s : m_config->m_shaders){
            ShaderCPtr  sh  = Shader::decode(s);
            if(!sh){
                vizWarning << "Unable to decode the shader number " << (m_shaders.size()+1) << " on this pipeline layout";
                return false;
            }
            
            ViShaderCPtr    xvs = m_device -> shader_create(*sh);
            if(!xvs || !xvs->valid()){
                vizWarning << "Unable to load shader number " << (m_shaders.size()+1) << " on this pipeline layout into vulkan ";
                return false;
            }
            
            defShaders[xvs->stage()] = xvs;
            
            VqPipelineShaderStageCreateInfo stage;
            stage.stage     = xvs->mask();
            stage.pName     = "main";
            stage.module    = xvs->shader_module();
            m_shaderInfo.push_back(stage);
            m_shaderMask   |= xvs->mask();
            m_shaders.push_back(xvs);
        }
        
        for(auto& itr : m_variations){
            ShaderMap   shaders;
            V&          vd   = itr.second;
            for(auto& s : vd.define->shaders){
                ShaderCPtr  sh  = Shader::decode(s);
                if(!sh){
                    vizWarning << "Unable to decode a shader on this pipeline layout";
                    return false;
                }
                
                ViShaderCPtr    xvs = m_device -> shader_create(*sh);
                if(!xvs || !xvs->valid()){
                    vizWarning << "Unable to load shader on this pipeline layout into vulkan ";
                    return false;
                }
                
                m_shaderMask   |= xvs->mask();
                shaders[xvs->stage()]   = xvs;
            }
            
            for(auto& j : shaders){
                VqPipelineShaderStageCreateInfo stage;
                stage.stage     = j.second->mask();
                stage.pName     = "main";
                stage.module    = j.second->shader_module();
                vd.shaderInfo.push_back(stage);
                vd.shaders.push_back(j.second);
            }
        }
        
        return true;
    }
    
    std::error_code ViPipelineLayout::_init(ViDevice&viz, const Pipeline* cfg, const ViPipelineLayoutOptions& opts)
    {
        VqPipelineLayoutCreateInfo  pipelineLayoutInfo;

        m_device       = &viz;
        m_config    = cfg;
        m_id            = cfg -> id();
        
        // First, the variations
        for(auto itr : m_config->m_variations){
            m_variations[itr.first].define = &itr.second;
        }
        
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
            push.size       = m_config->m_push.size;
            
            if(push.size > MAX_PUSH){
                vizWarning << "Push size EXCEEDS " << MAX_PUSH << " maximum, shrinking size to fit!";
                push.size   = MAX_PUSH;
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
        if(m_device && m_device->device() && m_pipelineLayout){
            vkDestroyPipelineLayout(m_device->device(), m_pipelineLayout, nullptr);
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
        m_device               = nullptr;
    }
    

    std::error_code ViPipelineLayout::init(ViDevice& viz, const Pipeline* cfg, const ViPipelineLayoutOptions& opts)
    {
        if(m_device){
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
        return m_device ? (m_device->device() && m_config && m_pipelineLayout) : (!m_config && !m_pipelineLayout);
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
        return m_device && m_device->device() && m_config && m_pipelineLayout;
    }

}
