////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <0/meta/Init.hpp>
#include <0/meta/TypeInfo.hpp>
#include <tachyon/viz/Shader.hpp>
#include <tachyon/viz/PushData.hpp>
#include <tachyon/viz/PipelineBuilder.hpp>


namespace yq::tachyon {

    Pipeline::Builder::Builder(role_t role)
    {
        m_build.role    = role;
    }
    
    Pipeline::Builder::~Builder()
    {
        if(m_autoGen){
            m_autoGen(create());
            m_autoGen   = {};
        }
    }

    Pipeline::Builder::Builder(Builder&& mv)
    {
        m_build         = std::move(mv.m_build);
        m_locations     = std::move(mv.m_locations);
        m_autoGen       = mv.m_autoGen;
        mv.m_autoGen    = {};
    }
    
    Pipeline::Builder& Pipeline::Builder::operator=(Builder&& mv)
    {
        if(this != &mv){
            m_build         = std::move(mv.m_build);
            m_locations     = std::move(mv.m_locations);
            m_autoGen       = mv.m_autoGen;
            mv.m_autoGen    = {};
        }
        return *this;
    }

    PipelineCPtr        Pipeline::Builder::create() const
    {
        return new Pipeline(m_build);
    }
    
    void        Pipeline::Builder::culling(CullMode v)
    {
        m_build.culling     = v;
    }
    
    void        Pipeline::Builder::front(FrontFace v)
    {
        m_build.front       = v;
    }


    uint32_t    Pipeline::Builder::location_filter(uint32_t loc, uint32_t req)
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
    
    void        Pipeline::Builder::polygons(PolygonMode v)
    {
        m_build.polymode    = v;
    }

    void        Pipeline::Builder::push(PushConfigType v)
    {
        m_build.push.type   = v;
        switch(v){
        case PushConfigType::Full:
        case PushConfigType::View:
            m_build.push.size  = sizeof(StdPushData);
            break;
        default:
            m_build.push.size   = 0;
            break;
        }
    }

    void        Pipeline::Builder::push_full()
    {
        push(PushConfigType::Full);
    }
    
    void        Pipeline::Builder::push_none()
    {
        push(PushConfigType::None);
    }
    
    void        Pipeline::Builder::push_view()
    {
        push(PushConfigType::View);
    }
    
    void        Pipeline::Builder::set_auto_gen(AutoGen ag)
    {
        m_autoGen   = ag;
    }

    void        Pipeline::Builder::shader(ShaderSpec ss)
    {
        m_build.shaders.push_back(ss);
        #if 0
        ShaderCPtr      s   = Shader::decode(ss);
        if(!s){
            if(const std::string*sp = std::get_if<std::string>(&ss)){
                tachyonError    << "Unable to load shader '" << *sp << "'";
            } else
                tachyonError    << "Unable to load (unspecified) shader.";
            return ;
        }

        m_build.shaders.push_back(s);
        #endif
    }
    
    void        Pipeline::Builder::shaders(std::initializer_list<ShaderSpec> sss)
    {
        for(ShaderSpec ss : sss)
            shader(ss);
    }

    void        Pipeline::Builder::topology(Topology v)
    {
        m_build.topology    = v;
    }

////////////////////////////////////////////////////////////////////////////////
//  LEGACY BELOW
////////////////////////////////////////////////////////////////////////////////
#if 0
    LegacyPipelineBuilder::~LegacyPipelineBuilder() = default;

    LegacyPipelineBuilder::LegacyPipelineBuilder(PipelineConfig*cfg) : m_config(cfg)
    {
        for(auto& vbo : cfg->vbos)
            for(auto & a : vbo.attrs)
        {
            m_locations.insert(a.location);     // won't be perfect, should help though
        }
    }
    

    LegacyPipelineBuilder::LegacyPipelineBuilder(PipelineConfig& cfg) : LegacyPipelineBuilder(&cfg)
    {
    }

    void    LegacyPipelineBuilder::culling(CullMode v)
    {
        m_config->culling    = v;
    }
    
    void    LegacyPipelineBuilder::front(FrontFace v)
    {
        m_config->front = v;
    }

    uint32_t    LegacyPipelineBuilder::location_filter(uint32_t loc, uint32_t req)
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
    
    void    LegacyPipelineBuilder::polygons(PolygonMode v)
    {
        m_config->polymode   = v;
    }
    

    void    LegacyPipelineBuilder::push(PushConfigType v)
    {
        switch(v){
        case PushConfigType::Full:
        case PushConfigType::View:
            m_config->push.type  = v;
            m_config->push.size  = sizeof(StdPushData);
            break;
        default:
            break;
        }
    }

    void    LegacyPipelineBuilder::shader(ShaderSpec ss)
    {
        m_config->shaders.push_back(ss);
    }
    
    void    LegacyPipelineBuilder::shaders(std::initializer_list<ShaderSpec>sspecs)
    {
        for(const ShaderSpec& ss : sspecs)
            m_config->shaders.push_back(ss);
    }
    
        
    void    LegacyPipelineBuilder::topology(Topology v)
    {
        m_config->topology = v;
    }
    
    void    LegacyPipelineBuilder::ubo(size_t cnt)
    {
        UBOConfig   u;
        u.count = cnt;
        m_config->ubos.push_back(u);
    }
#endif
}
