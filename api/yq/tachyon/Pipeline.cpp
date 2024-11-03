////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Pipeline.hpp"
#include <yq/meta/CompoundInfo.hpp>
#include <yq/tachyon/Shader.hpp>
#include <yq/tachyon/pipeline/PushData.hpp>
#include <atomic>

namespace yq::tachyon {

    uint64_t  Pipeline::_make_id()
    {
        static std::atomic<uint64_t>    s_next(1);
        return s_next++;
    }

    Pipeline::texture_t  Pipeline::tex_(DataActivity da, uint32_t stages)
    {   
        texture_t       cfg;
        cfg.activity    = da;
        cfg.shaders     = stages;
        return cfg;
    }
    
    ///////////////////////////////////////////////////
    
    Pipeline::Pipeline(Role r) : Pipeline(nullptr, r)
    {
    }

    Pipeline::Pipeline(const CompoundInfo* cinfo, Role r) : 
        m_compound(cinfo), m_id(_make_id()), m_role(r)
    {
    }
    
    Pipeline::~Pipeline()
    {
    }

    std::string_view  Pipeline::compound_name() const
    {
        if(m_compound)
            return m_compound -> name();
        return {};
    }

    bool  Pipeline::is_dynamic() const
    {
        return static_cast<bool>(m_compound);
    }

    bool  Pipeline::is_static() const
    {
        return !m_compound;
    }

    //// SETTERS

    void  Pipeline::binding(PipelineBinding v)
    {
        m_binding = v;
    }
    
    void  Pipeline::color_blending(ColorBlend v)
    {
        m_colorBlend = v;
    }

    void  Pipeline::culling(CullMode v)
    {
        m_cullMode  = v;
    }

    void  Pipeline::dynamic_state(DynamicState ds)
    {
        m_dynamicStates.insert(ds);
    }
    
    void  Pipeline::dynamic_states(std::initializer_list<DynamicState> states)
    {
        for(DynamicState ds : states){
            m_dynamicStates.insert(ds);
        }
    }
    
    void  Pipeline::front(FrontFace v)
    {
        m_frontFace  = v;
    }
    
    void  Pipeline::line_width(float v)
    {
        m_lineWidth = v;
    }

    uint32_t    Pipeline::location_filter(uint32_t loc, uint32_t req)
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
    
    void  Pipeline::polygons(PolygonMode v)
    {
        m_polygonMode = v;
    }
    
    void  Pipeline::primitive_restart(bool v)
    {
        m_primitiveRestart  = v;
    }

    void  Pipeline::push(PushConfigType v)
    {
        m_push.type = v;
        switch(v){
        case PushConfigType::Full:
        case PushConfigType::View:
            m_push.size  = sizeof(StdPushData);
            break;
        default:
            m_push.size   = 0;
            break;
        }
    }
    
    void  Pipeline::push_full()
    {
        push(PushConfigType::Full);
    }
    
    void  Pipeline::push_none()
    {
        push(PushConfigType::None);
    }
    
    void  Pipeline::push_view()
    {
        push(PushConfigType::View);
    }

    void  Pipeline::shader(ShaderSpec ss)
    {
        m_shaders.push_back(ss);
    }
    
    void  Pipeline::shaders(std::initializer_list<ShaderSpec> sss)
    {
        for(ShaderSpec ss : sss)
            m_shaders.push_back(ss);
    }

    
    uint32_t    Pipeline::texture(DataActivity da, uint32_t stages)
    {
        texture_t   cfg = tex_(da, stages);
        uint32_t ret = (uint32_t) m_textures.size();
        m_textures.push_back(cfg);
        return ret;
    }

    void  Pipeline::topology(Topology v)
    {
        m_topology  = v;
    }
    
    void  Pipeline::wireframe_permitted(bool v)
    {
        m_wireframePermitted    = v;
    }
}
