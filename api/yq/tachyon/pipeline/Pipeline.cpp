////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Pipeline.hpp"
#include <yq/meta/CompoundMeta.hpp>
#include <yq/tachyon/asset/Shader.hpp>
#include <yq/tachyon/pipeline/PushData.hpp>
#include <atomic>

namespace yq::tachyon {

    uint64_t  Pipeline::_make_id()
    {
        static std::atomic<uint64_t>    s_next(1);
        return s_next++;
    }
    
    static const DynamicState kStdDynamic[] = {
        //DynamicState::DepthBoundsTestEnable,
        //DynamicState::DepthCompareOp,
        //DynamicState::DepthTestEnable,
        //DynamicState::DepthWriteEnable,
        DynamicState::Scissor,
        DynamicState::Viewport
    };

    ///////////////////////////////////////////////////
    
    Pipeline::Pipeline(PipelineKey r) : Pipeline(nullptr, r)
    {
    }

    Pipeline::Pipeline(const CompoundMeta* cinfo, PipelineKey r) : 
        m_compound(cinfo), m_id(_make_id()), m_key(r)
    {
        for(DynamicState ds : kStdDynamic)
            m_dynamicStates.insert(ds);
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

    bool  Pipeline::is_dynamic() const noexcept
    {
        return static_cast<bool>(m_compound);
    }

    bool  Pipeline::is_static() const noexcept
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

    void  Pipeline::depth_buffer(Tristate v)
    {
        if(m_variation){
            m_variation -> depthBuffer = v;
        } else {
            m_depthBuffer   = v;
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
    
    void  Pipeline::patch_control_points(uint32_t u)
    {
        if(m_variation){
            m_variation -> patchControlPoints = u;
        } else {
            m_patchControlPoints = u;
        }
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
    
    void   Pipeline::stenciling(Tristate v)
    {
        if(m_variation){
            m_variation -> stenciling   = v;
        } else 
            m_stenciling    = v;
    }
    
    uint32_t        Pipeline::filter_binding(uint32_t b) const
    {
        uint32_t    mx = 0;
        for(auto& s : m_storageBuffers){
            if(b == s.binding)
                b   = UINT32_MAX;
            mx  = std::max(s.binding+1, mx);
        }

        for(auto& t : m_textures){
            if(b == t.binding)
                b   = UINT32_MAX;
            mx  = std::max(t.binding+1, mx);
        }

        for(auto& u : m_uniformBuffers){
            if(b == u.binding)
                b   = UINT32_MAX;
            mx  = std::max(u.binding+1, mx);
        }
        if(b == UINT32_MAX)
            b   = mx;
        return b;
    }

    Pipeline::texture_t  Pipeline::tex_(const t_config& cc)
    {   
        texture_t       cfg;
        cfg.activity    = cc.activity;
        cfg.stages      = cc.stages;
        cfg.external    = cc.external;
        cfg.binding     = filter_binding(cc.binding);
        return cfg;
    }
    

    uint32_t    Pipeline::texture(const t_config& cc)
    {
        texture_t   cfg = tex_(cc);
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
        if(m_variation)
            m_variation -> wireframePermitted = v ? Tristate::YES : Tristate::NO;
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
