////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PipelineBuilder.hpp"

#include <yq-toolbox/meta/Init.hpp>
#include <yq-toolbox/meta/TypeInfo.hpp>
#include <yq-vulqan/pipeline/PushData.hpp>
#include <yq-vulqan/shader/Shader.hpp>

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

    void        Pipeline::Builder::line_width(float v)
    {
        m_build.line_width  = v;
    }
    
    void        Pipeline::Builder::polygons(PolygonMode v)
    {
        m_build.polymode    = v;
    }

    void        Pipeline::Builder::primitive_restart(bool v)
    {
        m_build.primitive_restart = v;
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

    void        Pipeline::Builder::wireframe_permitted(bool v)
    {
        m_build.wireframe_permitted   = v;
    }
}
