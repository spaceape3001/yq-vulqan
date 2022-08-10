////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PipelineBuilder.hpp"
#include "StdPushConstant.hpp"

#include <basic/meta/Init.hpp>
#include <basic/meta/TypeInfo.hpp>
#include <engine/Shader.hpp>


namespace yq {
    namespace engine {

        PipelineBuilder::~PipelineBuilder() = default;

        PipelineBuilder::PipelineBuilder(PipelineConfig*cfg) : m_config(cfg)
        {
            for(auto& vbo : cfg->vbos)
                for(auto & a : vbo.attrs)
            {
                m_locations.insert(a.location);     // won't be perfect, should help though
            }
        }
        

        PipelineBuilder::PipelineBuilder(PipelineConfig& cfg) : PipelineBuilder(&cfg)
        {
        }

        void    PipelineBuilder::culling(CullMode v)
        {
            m_config->culling    = v;
        }
        
        void    PipelineBuilder::front(FrontFace v)
        {
            m_config->front = v;
        }

        uint32_t    PipelineBuilder::location_filter(uint32_t loc, uint32_t req)
        {
            if(loc != UINT32_MAX){
                for(uint32_t i=loc; i<loc+req; ++i){
                    [[maybe_unused]] auto j = m_locations.insert(i);
                    assert(j.second && "Location already assigned!");
                }
                return loc;
            }
            
            if(m_locations.empty()){
                for(uint32_t i=0; i<req; ++i){
                    m_locations.insert(i);
                }
                return 0;
            }
            
            loc = *(m_locations.rbegin()) + 1;
            for(uint32_t i=0; i<req; ++i){
                m_locations.insert(i+loc);
            }
            return loc;
        }
        
        void    PipelineBuilder::polygons(PolygonMode v)
        {
            m_config->polymode   = v;
        }
        

        void    PipelineBuilder::push(PushConfigType v)
        {
            switch(v){
            case PushConfigType::Full:
            case PushConfigType::View:
                m_config->push.type  = v;
                m_config->push.size  = sizeof(StdPushConstant);
                break;
            default:
                break;
            }
        }

        void    PipelineBuilder::shader(ShaderSpec ss)
        {
            m_config->shaders.push_back(ss);
        }
        
        void    PipelineBuilder::shaders(std::initializer_list<ShaderSpec>sspecs)
        {
            for(const ShaderSpec& ss : sspecs)
                m_config->shaders.push_back(ss);
        }
        
            
        void    PipelineBuilder::topology(Topology v)
        {
            m_config->topology = v;
        }
        
        void    PipelineBuilder::ubo(size_t cnt)
        {
            UBOConfig   u;
            u.count = cnt;
            m_config->ubos.push_back(u);
        }

    }
}
