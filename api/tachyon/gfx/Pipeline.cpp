////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/gfx/Pipeline.hpp>
#include <yq/meta/CompoundMeta.hpp>
#include <tachyon/gfx/Shader.hpp>
#include <tachyon/gfx/PushData.hpp>
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

    Pipeline::Pipeline(const CompoundMeta* cinfo, Role r) : 
        m_compound(cinfo), m_id(_make_id()), m_role(r)
    {
        m_dynamicStates.insert(DynamicState::Viewport);
        m_dynamicStates.insert(DynamicState::Scissor);
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
        if(m_variation){
            m_variation -> colorBlend   = v;
        } else {
            m_colorBlend = v;
        }
    }

    void  Pipeline::culling(CullMode v)
    {
        if(m_variation){
            m_variation -> cullMode = v;
        } else {
            m_cullMode  = v;
        }
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
        if(m_variation){
            m_variation -> frontFace = v;
        } else {
            m_frontFace  = v;
        }
    }
    
    void  Pipeline::line_width(float v)
    {
        if(m_variation){
            m_variation -> lineWidth    = v;
        } else {
            m_lineWidth = v;
        }
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
        if(m_variation){
            m_variation -> polygonMode = v;
        } else {
            m_polygonMode = v;
        }
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
            m_push.size     = sizeof(StdPushData);
            break;
        case PushConfigType::MVP:
            m_push.size     = sizeof(StdPushDataMVP);
            break;
        case PushConfigType::ViewProj:
            m_push.size     = sizeof(StdPushDataViewProj);
            break;
        case PushConfigType::View64Proj:
            m_push.size     = sizeof(StdPushDataView64Proj);
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
    
    void  Pipeline::push_mvp()
    {
        push(PushConfigType::MVP);
    }
    
    void  Pipeline::push_view()
    {
        push(PushConfigType::View);
    }

    void  Pipeline::shader(ShaderSpec ss)
    {
        if(m_variation){
            m_variation -> shaders.push_back(ss);
        } else
            m_shaders.push_back(ss);
    }
    
    void  Pipeline::shaders(std::initializer_list<ShaderSpec> sss)
    {
        if(m_variation){
            for(ShaderSpec ss : sss)
                m_variation->shaders.push_back(ss);
        } else {
            for(ShaderSpec ss : sss)
                m_shaders.push_back(ss);
        }
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
        if(m_variation){
            m_variation -> wireframePermitted = v ? Tristate::YES : Tristate::NO;
        }
        m_wireframePermitted    = v;
    }

        //! Creates/accesses the specified variation.
    Pipeline::VariationData*    Pipeline::variation(Variation v)
    {
        if(v == Variation::Invalid)
            return nullptr;
        if(v == Variation::Default)
            return nullptr;
        m_variation = &m_variations[v];
        return m_variation;
    }

    void    Pipeline::variation(reset_k)
    {
        m_variation = nullptr;
    }
}
