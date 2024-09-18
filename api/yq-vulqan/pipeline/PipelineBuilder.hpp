////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/keywords.hpp>
#include <yq-toolbox/basic/Mutable.hpp>
#include <yq-toolbox/basic/steal.hpp>
#include <yq-toolbox/container/BasicBuffer.hpp>
#include <yq-toolbox/math/glm_types.hpp>
#include <yq-toolbox/trait/member_offset.hpp>
#include <yq-toolbox/trait/not_copyable.hpp>
#include <yq-toolbox/trait/not_moveable.hpp>

#include <yq-vulqan/texture/Texture.hpp>
#include <yq-vulqan/pipeline/SBO.hpp>
#include <yq-vulqan/pipeline/UBO.hpp>
#include <yq-vulqan/pipeline/VBO.hpp>

#include <yq-vulqan/pipeline/Pipeline.hpp>
#include <yq-vulqan/pipeline/PipelineConfig.hpp>
#include <yq-vulqan/pipeline/PipelineUtils.hpp>
#include <set>
#include <span>
#include <cassert>
#include <functional>
#include <type_traits>

namespace yq::tachyon {

    
    class Pipeline::Builder {
    public:
    
        using   AutoGen     = std::function<void(PipelineCPtr)>;
    
        //! Creates a new pipeline
        PipelineCPtr        create() const;
    
        void        shader(ShaderSpec);
        void        shaders(std::initializer_list<ShaderSpec>);
        void        topology(Topology);
        void        polygons(PolygonMode);
        void        front(FrontFace);
        void        culling(CullMode);
        void        wireframe_permitted(bool);
        void        line_width(float);
        void        primitive_restart(bool);
    
        template <typename T>
        void        push()
        {
            static_assert(std::is_trivially_copyable_v<T>, "Must be trivially copyable!");
            m_build.push.type  = PushConfigType::Custom;
            m_build.push.size  = sizeof(T);
        }
        
        void        push(PushConfigType);
        
            //! Equivalent to push(PushConfigType::None)
        void        push_none();
            //! Equivalent to push(PushConfigType::Full)
        void        push_full();
            //! Equivalent to push(PushConfigType::View)
        void        push_view();

        void        set_auto_gen(AutoGen);

        void        sbo(size_t cnt=1);
        
        void        ubo(size_t cnt=1);

        template <typename V>
        VBOMaker<V> vbo(DataActivity da=DataActivity::UNSURE, uint32_t stages=0);

    /// other stuff

        Builder(role_t role={});
        ~Builder();
        
        Builder(Builder&&);
        Builder& operator=(Builder&&);

        PipelineConfig&     config() { return m_build; }
        
        template <typename V>
        static IBOConfig    ibo_(DataActivity da)
        {
            IBOConfig       cfg;
            cfg.type        = index_type<V>();
            cfg.activity    = da;
            cfg.stride      = sizeof(V);
            return cfg;
        }
        
        template <typename V>
        static SBOConfig    sbo_(uint32_t cnt, DataActivity da, uint32_t stages=0)
        {
            SBOConfig       cfg;
            cfg.activity    = da;
            cfg.size        = sizeof(V);
            cfg.count       = cnt;
            cfg.shaders     = stages;
            return cfg;
        }

        template <typename V>
        static UBOConfig    ubo_(uint32_t cnt, DataActivity da, uint32_t stages=0)
        {
            UBOConfig       cfg;
            cfg.activity    = da;
            cfg.size        = sizeof(V);
            cfg.count       = cnt;
            cfg.shaders     = stages;
            return cfg;
        }
        
        static TexConfig    tex_(DataActivity da, uint32_t stages=0)
        {   
            TexConfig       cfg;
            cfg.activity    = da;
            cfg.shaders     = stages;
            return cfg;
        }

    protected:
        friend class Pipeline;
        template <typename> friend class VBOMaker;
        PipelineConfig      m_build;
        
        uint32_t            location_filter(uint32_t loc, uint32_t req);

    private:
        std::set<uint32_t>  m_locations;
        AutoGen             m_autoGen = {};
        Builder(const Builder&) = delete;
        Builder&    operator=(const Builder&) = delete;
    };
    
    
    template <typename V> 
    class Pipeline::VBOMaker : public VBOConfig {
    public:
    
        VBOMaker(VBOMaker&& mv) : VBOConfig(std::move(mv))
        {
            steal(m_builder, mv.m_builder);
        }

        VBOMaker(const VBOMaker&) = delete;
        VBOMaker&   operator=(const VBOMaker&) = delete;
        
        VBOMaker&   operator=(VBOMaker&& mv)
        {
            if(this != &mv){
                VBOConfig::operator=(std::move(mv));
                steal(m_builder, mv.m_builder);
            }
            return *this;
        }
        
        ~VBOMaker()
        {
            if(!m_builder)
                return ;
            
            if(attrs.empty()){
                if constexpr (is_type_v<V>){
                    typed_attribute<V>(0);
                }
            }
            assert(!attrs.empty());

            m_builder -> m_build.vbos.push_back(*this);
        }

        template  <typename M>
        requires is_type_v<M>
        VBOMaker& attribute(M V::*member)
        {
            typed_attribute<M>((uint32_t) member_offset(member));
            return *this;
        }
        
        template  <typename M>
        requires (!is_type_v<M>)
        VBOMaker& attribute(M V::*member, DataFormat fmt)
        {
            attr_impl(fmt, (uint32_t) member_offset(member), min_binding<M>());
            return *this;
        }
        
    
    private:
        friend class Builder;
    
        VBOMaker(Builder* b, DataActivity da, uint32_t stages) : m_builder(b)
        {
            stride      = sizeof(V);
            activity    = da;
            shaders     = stages;
        }
        

        Builder*    m_builder;

        template <typename A>
        requires is_type_v<A>
        void    typed_attribute(uint32_t offset)
        {
            attr_impl(data_format<A>(), offset, min_binding<A>(), &meta<A>());
        }
        
        void    attr_impl(DataFormat df, uint32_t offset, uint32_t bindReq, const TypeInfo* ti=nullptr)
        {
            if(!m_builder)
                return ;
                
            assert((df != DataFormat()) && "Bad data format!");
            if(df == DataFormat())
                return ;
                
            VBOAttr     a;
            a.location  = m_builder->location_filter(UINT32_MAX, bindReq);
            a.offset    = offset;
            a.format    = df;
            a.type      = ti;
            attrs.push_back(a);
        }
    };
    
    template <typename V>
    Pipeline::VBOMaker<V> Pipeline::Builder::vbo(DataActivity da, uint32_t stages)
    {
        return VBOMaker<V>(this, da, stages);
    }

    template <typename C>
    class Pipeline::Typed : public Builder {
    public:
    
    
        using Builder::push;
        
        template <typename T>
        void        push(T (C::*p))
        {
            static_assert(sizeof(T) <= MAX_PUSH, "T is TOO BIG!");
            static_assert(std::is_trivially_copyable_v<T>, "Must be trivially copyable!");
        
            m_build.push.type   = PushConfigType::Custom;
            m_build.push.size   = sizeof(T);
            m_build.push.fetch  = [p](const void* obj, PushBuffer& buf) {
                const C* c  = (const C*) obj;
                buf.paste( (c->*p) );
            };
        }
            
        Typed(role_t role={}) : Builder(role) 
        {
            if constexpr ( is_type_v<C>){
                m_build.object = &meta<C>();
            }
            if constexpr ( is_object_v<C>){
                m_build.object = &meta<C>();
            }
        }
        
        #define YQ_PIPELINE_COMMON_HANDLER                          \
            cfg.fetch       = [&p](const void*) -> BufferCPtr {     \
                return p.buffer;                                    \
            };                                                      \
            cfg.revision    = [&p](const void*) -> uint64_t {       \
                return p.buffer ? p.buffer -> id() : 0ULL;          \
            };

        #define YQ_PIPELINE_MEMBER_HANDLER                          \
            cfg.fetch       = [p](const void*v) -> BufferCPtr {     \
                const C* c = (const C*) v;                          \
                return (c->*p).buffer;                              \
            };                                                      \
            cfg.revision    = [p](const void*v) -> uint64_t {       \
                const C* c = (const C*) v;                          \
                auto& b = (c->*p).buffer;                           \
                return b ? b->id() : 0ULL;                          \
            };
        
        
        
        Typed(const Typed&) = default;
        Typed(Typed&&) = default;


        /*
            =======================================================
            INDEX BUFFERS
            =======================================================
        */

        template <typename V>
        void    index(IBO<V>& p, DataActivity da=DataActivity::REFRESH)
        {
            IBOConfig       cfg = ibo_<V>(da);
            YQ_PIPELINE_COMMON_HANDLER
            m_build.ibos.push_back(cfg);
        }
        
        template <typename V>
        void    index(IB1<V>& p, DataActivity da=DataActivity::REFRESH)
        {
            IBOConfig       cfg = ibo_<V>(da);
            YQ_PIPELINE_COMMON_HANDLER
            m_build.ibos.push_back(cfg);
        }

        template <typename V>
        void    index(IBO<V> C::*p, DataActivity da=DataActivity::REFRESH)
        {
            IBOConfig       cfg = ibo_<V>(da);
            YQ_PIPELINE_MEMBER_HANDLER
            m_build.ibos.push_back(cfg);
        }
        
        template <typename V>
        void    index(IB1<V> C::*p, DataActivity da=DataActivity::REFRESH)
        {
            IBOConfig       cfg = ibo_<V>(da);
            YQ_PIPELINE_MEMBER_HANDLER
            m_build.ibos.push_back(cfg);
        }

        /*
            =======================================================
            UNIFORM BUFFERS
            =======================================================
        */
        
        template <typename V>
        void    storage(SBO<V>& p, uint32_t cnt, DataActivity da=DataActivity::REFRESH, uint32_t stages=0)
        {
            SBOConfig       cfg = sbo_<V>(cnt, da, stages);
            YQ_PIPELINE_COMMON_HANDLER
            m_build.sbos.push_back(cfg);
        }
        
        template <typename V>
        void    storage(SB1<V>& p, uint32_t cnt, DataActivity da=DataActivity::REFRESH, uint32_t stages=0)
        {
            SBOConfig       cfg = sbo_<V>(cnt, da, stages);
            YQ_PIPELINE_COMMON_HANDLER
            m_build.sbos.push_back(cfg);
        }

        template <typename V>
        void    storage(SBO<V>& p, DataActivity da=DataActivity::REFRESH, uint32_t stages=0)
        {
            storage(p, 1, da, stages);
        }
        
        template <typename V>
        void    storage(SB1<V>& p, DataActivity da=DataActivity::REFRESH, uint32_t stages=0)
        {
            storage(p, 1, da, stages);
        }
        
        
        template <typename V>
        void    storage(SBO<V> C::*p, uint32_t cnt, DataActivity da=DataActivity::REFRESH, uint32_t stages=0)
        {
            SBOConfig       cfg = sbo_<V>(cnt, da, stages);
            YQ_PIPELINE_MEMBER_HANDLER
            m_build.sbos.push_back(cfg);
        }
        
        template <typename V>
        void    storage(SB1<V> C::*p, uint32_t cnt, DataActivity da=DataActivity::REFRESH, uint32_t stages=0)
        {
            SBOConfig       cfg = sbo_<V>(cnt, da, stages);
            YQ_PIPELINE_MEMBER_HANDLER
            m_build.sbos.push_back(cfg);
        }

        template <typename V>
        void    storage(SBO<V> C::*p, DataActivity da=DataActivity::REFRESH, uint32_t stages=0)
        {
            storage(p, 1, da, stages);
        }
        
        template <typename V>
        void    storage(SB1<V> C::*p, DataActivity da=DataActivity::REFRESH, uint32_t stages=0)
        {
            storage(p, 1, da, stages);
        }


        /*
            =======================================================
            UNIFORM BUFFERS
            =======================================================
        */
        
        template <typename V>
        void    uniform(UBO<V>& p, uint32_t cnt, DataActivity da=DataActivity::REFRESH, uint32_t stages=0)
        {
            UBOConfig       cfg = ubo_<V>(cnt, da, stages);
            YQ_PIPELINE_COMMON_HANDLER
            m_build.ubos.push_back(cfg);
        }
        
        template <typename V>
        void    uniform(UB1<V>& p, uint32_t cnt, DataActivity da=DataActivity::REFRESH, uint32_t stages=0)
        {
            UBOConfig       cfg = ubo_<V>(cnt, da, stages);
            YQ_PIPELINE_COMMON_HANDLER
            m_build.ubos.push_back(cfg);
        }

        template <typename V>
        void    uniform(UBO<V>& p, DataActivity da=DataActivity::REFRESH, uint32_t stages=0)
        {
            uniform(p, 1, da, stages);
        }
        
        template <typename V>
        void    uniform(UB1<V>& p, DataActivity da=DataActivity::REFRESH, uint32_t stages=0)
        {
            uniform(p, 1, da, stages);
        }
        
        
        template <typename V>
        void    uniform(UBO<V> C::*p, uint32_t cnt, DataActivity da=DataActivity::REFRESH, uint32_t stages=0)
        {
            UBOConfig       cfg = ubo_<V>(cnt, da, stages);
            YQ_PIPELINE_MEMBER_HANDLER
            m_build.ubos.push_back(cfg);
        }
        
        template <typename V>
        void    uniform(UB1<V> C::*p, uint32_t cnt, DataActivity da=DataActivity::REFRESH, uint32_t stages=0)
        {
            UBOConfig       cfg = ubo_<V>(cnt, da, stages);
            YQ_PIPELINE_MEMBER_HANDLER
            m_build.ubos.push_back(cfg);
        }

        template <typename V>
        void    uniform(UBO<V> C::*p, DataActivity da=DataActivity::REFRESH, uint32_t stages=0)
        {
            uniform(p, 1, da, stages);
        }
        
        template <typename V>
        void    uniform(UB1<V> C::*p, DataActivity da=DataActivity::REFRESH, uint32_t stages=0)
        {
            uniform(p, 1, da, stages);
        }
        
        /*
            =======================================================
            VERTEX BUFFERS
            =======================================================
        */

        template <typename V>
        VBOMaker<V> vertex(VBO<V>& p, DataActivity da=DataActivity::REFRESH, uint32_t stages=0)
        {
            auto cfg    = vbo<V>(da, stages);
            YQ_PIPELINE_COMMON_HANDLER
            return cfg;
        }
        
        template <typename V>
        VBOMaker<V> vertex(VB1<V>& p, DataActivity da=DataActivity::REFRESH, uint32_t stages=0)
        {
            auto cfg    = vbo<V>(da, stages);
            YQ_PIPELINE_COMMON_HANDLER
            return cfg;
        }

        template <typename V>
        VBOMaker<V> vertex(VBO<V> C::*p, DataActivity da=DataActivity::REFRESH, uint32_t stages=0)
        {
            auto cfg    = vbo<V>(da, stages);
            YQ_PIPELINE_MEMBER_HANDLER
            return cfg;
        }
        
        template <typename V>
        VBOMaker<V> vertex(VB1<V> C::*p, DataActivity da=DataActivity::REFRESH, uint32_t stages=0)
        {
            auto cfg    = vbo<V>(da, stages);
            YQ_PIPELINE_MEMBER_HANDLER
            return cfg;
        }
        
        #undef YQ_PIPELINE_COMMON_HANDLER
        #undef YQ_PIPELINE_MEMBER_HANDLER

        /*
            =======================================================
            TEXTURES
            =======================================================
        */


        #define YQ_PIPELINE_MEMBER_HANDLER                          \
            cfg.fetch       = [p](const void*v) -> BufferCPtr {     \
                const C* c = (const C*) v;                          \
                return (c->*p).buffer;                              \
            };                                                      \
            cfg.revision    = [p](const void*v) -> uint64_t {       \
                const C* c = (const C*) v;                          \
                auto& b = (c->*p).buffer;                           \
                return b ? b->id() : 0ULL;                          \
            };
        

        void    texture(Ref<const Texture> &p, DataActivity da=DataActivity::REFRESH, uint32_t stages=0)
        {
            TexConfig   cfg = tex_(da, stages);
            cfg.fetch       = [&p](const void*) -> TextureCPtr {
                return p;
            };
            cfg.revision    = [&p](const void*) -> uint64_t {
                return p ? p->id() : 0ULL;
            };
            m_build.texs.push_back(cfg);
        }

        void    texture(Ref<const Texture> C::*p, DataActivity da=DataActivity::REFRESH, uint32_t stages=0)
        {
            TexConfig   cfg = tex_(da, stages);
            cfg.fetch       = [p](const void*v) -> TextureCPtr {
                const C* c = (const C*) v;
                return (c->*p);
            };
            cfg.revision    = [p](const void*v) -> uint64_t {
                const C*c   = (const C*) v;
                const Ref<const Texture>&   t   = (c->*p);
                return t ? t->id() : 0ULL;
            };
            m_build.texs.push_back(cfg);
        }
    };

    template <typename C>
    auto Pipeline::build(role_t r)
    {
        if constexpr (std::is_same_v<C,void>)
            return Builder(r);
        if constexpr (!std::is_same_v<C,void>){
            static_assert(std::is_class_v<C>, "Must either build to void or a class/structure!");
            return Typed<C>(r);
        }
    }

////////////////////////////////////////////////////////////////////////////////
//  LEGACY BELOW
////////////////////////////////////////////////////////////////////////////////

#if 0
    class LegacyPipelineBuilder {
    public:
    
        //  Used to track which locations have been used.
        
        void        shader(ShaderSpec);
        void        shaders(std::initializer_list<ShaderSpec>);
        void        topology(Topology);
        void        polygons(PolygonMode);
        void        front(FrontFace);
        void        culling(CullMode);

        template <typename T>
        void        push()
        {
            m_config->push.type  = PushConfigType::Custom;
            m_config->push.size  = sizeof(T);
        }
        
        void        push(PushConfigType);
        
        template <typename V> struct VBO;
        
        //! Used to create VBOs by those outside the render's pipeline writer
        template <typename V>
        VBO<V>      vbo();
    
        LegacyPipelineBuilder(PipelineConfig& cfg);
        ~LegacyPipelineBuilder();
        
        void        ubo(size_t cnt=1);

    protected:
        LegacyPipelineBuilder(PipelineConfig*);
        uint32_t                location_filter(uint32_t loc, uint32_t req);

    private:
        PipelineConfig* const   m_config;
        std::set<uint32_t>      m_locations;
    };


    template <typename V>
    class LegacyPipelineBuilder::VBO : public VBOConfig, not_copyable {
    public:
    
        VBO(LegacyPipelineBuilder* cfg, std::function<void(uint32_t)> info={}) : m_builder(cfg), m_info(info)
        {
            stride  = sizeof(V);
        }
        
        VBO(VBO& mv) : VBOConfig(std::move(mv))
        {
            steal(m_builder, mv.m_builder);
            m_info              = std::move(mv.m_info);
        }
        
        
        VBO& operator=(VBO&&mv) 
        {
            if(this != &mv){
                VBOConfig::operator=(std::move(mv));
                steal(m_builder, mv.m_builder);
                m_info          = std::move(mv.m_info);
            }
            return *this;
        }
        
        ~VBO()
        {
            if(!m_builder)
                return ;
            if(attrs.empty()){
                if constexpr (is_type_v<V>){
                    typed_attribute<V>(0);
                }
            }
            assert(!attrs.empty());
            
            if(m_info && !attrs.empty()){
                m_info(attrs.front().location);
            }
            
            m_builder -> m_config->vbos.push_back(*this);
        }

        VBO&     rate(VertexInputRate vr)
        {
            inputRate   = vr;
            return *this;
        }
        
        template  <typename M>
        requires is_type_v<M>
        VBO& attribute(M V::*member)
        {
            typed_attribute<M>((uint32_t) member_offset(member));
            return *this;
        }
        
        template  <typename M>
        requires (!is_type_v<M>)
        VBO& attribute(M V::*member, DataFormat fmt)
        {
            attr_impl(fmt, (uint32_t) member_offset(member), min_binding<M>());
            return *this;
        }
        

    private:

        LegacyPipelineBuilder*                m_builder   = nullptr;
        std::function<void(uint32_t)>   m_info      = nullptr;
        
        template <typename A>
        requires is_type_v<A>
        void    typed_attribute(uint32_t offset)
        {
            attr_impl(data_format<A>(), offset, min_binding<A>());
        }
        
        void    attr_impl(DataFormat df, uint32_t offset, uint32_t bindReq)
        {
            if(!m_builder)
                return ;
                
            assert((df != DataFormat()) && "Bad data format!");
            if(df == DataFormat())
                return ;
                
            VBOAttr     a;
            a.location  = m_builder->location_filter(UINT32_MAX, bindReq);
            a.offset    = offset;
            a.format    = df;
            attrs.push_back(a);
        }
        
    };

    template <typename V>
    LegacyPipelineBuilder::VBO<V>     LegacyPipelineBuilder::vbo()
    {
        return VBO<V>(this);
    }
#endif
}
