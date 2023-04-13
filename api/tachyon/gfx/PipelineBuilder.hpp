////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/BasicBuffer.hpp>
#include <basic/Mutable.hpp>
#include <tachyon/gfx/Pipeline.hpp>
#include <tachyon/gfx/PipelineConfig.hpp>
#include <tachyon/gfx/PipelineUtils.hpp>
#include <tachyon/gfx/UBO.hpp>
#include <tachyon/gfx/VBO.hpp>
#include <math/glm_types.hpp>
#include <trait/not_copyable.hpp>
#include <trait/not_moveable.hpp>
#include <set>
#include <span>
#include <cassert>
#include <functional>
#include <type_traits>

namespace yq::tachyon {

    struct span_t {};
    struct copy_t {};
    static constexpr const span_t   SPAN;
    static constexpr const copy_t   COPY;

    
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
        
        void        ubo(size_t cnt=1);

        template <typename V>
        VBOMaker<V> vbo();

    /// other stuff

        Builder(role_t role={});
        ~Builder();
        
        Builder(Builder&&);
        Builder& operator=(Builder&&);

        PipelineConfig&     config() { return m_build; }
        
        template <typename V>
        static IBOConfig    ibo(DataActivity da)
        {
            IBOConfig       cfg;
            cfg.type        = index_type<V>();
            cfg.activity    = da;
            cfg.stride      = sizeof(V);
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
    
        VBOMaker(Builder* b) : m_builder(b)
        {
            stride  = sizeof(V);
        }
        

        Builder*    m_builder;

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
    Pipeline::VBOMaker<V> Pipeline::Builder::vbo()
    {
        return VBOMaker<V>(this);
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
        
        
        Typed(const Typed&) = default;
        Typed(Typed&&) = default;


        //  ------------------ general getters --------------------

        template <typename V>
        void    index(IBO<V>& p, DataActivity da)
        {
            IBOConfig       cfg = ibo<V>(da);
            cfg.fetch       = [&p](const void*) -> BufferCPtr {
                return p.buffer;
            };
            cfg.revision    = [&p](const void*) -> uint64_t {
                return p.buffer ? p.buffer -> id() : 0ULL;
            };
            m_build.ibos.push_back(cfg);
        }

        template <typename V>
        void    index(IB1<V>& p, DataActivity da)
        {
            IBOConfig       cfg = ibo<V>(da);
            cfg.fetch       = [&p](const void*) -> BufferCPtr {
                return p.buffer;
            };
            cfg.revision    = [&p](const void*) -> uint64_t {
                return p.buffer ? p.buffer -> id() : 0ULL;
            };
            m_build.ibos.push_back(cfg);
        }

        template <typename V, size_t N>
        void index(const V(&p)[N], DataActivity da)
        {
            IBOConfig       cfg = ibo<V>(da);
            cfg.fetch   = [p](const void*) -> BufferCPtr {
                return buffer_span(BufferUsage::Index, std::span<const V>(p, N));
            };
            m_build.ibos.push_back(cfg);
        }

        template <typename V, size_t N>
        void    index(std::array<V,N> C::*p, DataActivity da, bool copy_it)
        {
            IBOConfig       cfg = ibo<V>(da);
            if(copy_it){
                cfg.fetch   = [p](const void* v) -> BufferCPtr {
                    const C* c = (const C*) v;
                    return buffer_array(BufferUsage::Index, span(v->*c));
                };
            } else {
                cfg.fetch   = [p](const void* v) -> BufferCPtr {
                    const C* c = (const C*) v;
                    return buffer_span(BufferUsage::Index, span(v->*c));
                };
            }
            m_build.ibos.push_back(cfg);
        }

        template <typename V>
        void    index(std::vector<V> C::*p, DataActivity da, bool copy_it)
        {
            IBOConfig       cfg = ibo<V>(da);
            if(copy_it){
                cfg.fetch   = [p](const void* v) -> BufferCPtr {
                    const C* c = (const C*) v;
                    return buffer_array(BufferUsage::Index, (v->*c));
                };
            } else {
                cfg.fetch   = [p](const void* v) -> BufferCPtr {
                    const C* c = (const C*) v;
                    return buffer_span(BufferUsage::Index, (v->*c));
                };
            }
            m_build.ibos.push_back(cfg);
        }
        
        template <typename V>
        void    index(Mutable<std::vector<V>> C::*p, DataActivity da)
        {
            IBOConfig       cfg = ibo<V>(da);
            cfg.fetch   = [p](const void* v) -> BufferCPtr {
                const C* c = (const C*) v;
                const Mutable<std::vector<V>>& m    = *(c->*p);
                return buffer_array(BufferUsage::Index, m.get());
            };
            cfg.revision    = [p](const void* v) -> uint64_t {
                const C* c = (const C*) v;
                const Mutable<std::vector<V>>& m    = *(c->*p);
                return m.revision();
            };
            m_build.ibos.push_back(cfg);
        }

        template <typename V, size_t N>
        void    index(Mutable<std::array<V,N>> C::*p, DataActivity da)
        {
            IBOConfig       cfg = ibo<V>(da);
            cfg.fetch   = [p](const void* v) -> BufferCPtr {
                const C* c = (const C*) v;
                const Mutable<std::array<V,N>>& m    = *(c->*p);
                return buffer_array(BufferUsage::Index, span(m.get()));
            };
            cfg.revision    = [p](const void* v) -> uint64_t {
                const C* c = (const C*) v;
                const Mutable<std::array<V,N>>& m    = *(c->*p);
                return m.revision();
            };
            m_build.ibos.push_back(cfg);
        }
        
            //  ------- UNIFORMS GO HERE
        
            //  VERTEX CREATORS
        
        template <typename V, size_t N>
        VBOMaker<V> vertex(const V(&p)[N], DataActivity da)
        {
            auto vm = vbo<V>();
            vm.fetch   = [p](const void*) -> BufferCPtr {
                return buffer_span(BufferUsage::Vertex, std::span<const V>(p, N));
            };
            vm.activity    = da;
            return vm;
        }
        
        template <typename V>
        VBOMaker<V> vertex(VBO<V>& p, DataActivity da)
        {
            auto vm    = vbo<V>();
            vm.fetch    = [&p](const void*) -> BufferCPtr {
                return p.buffer;
            };
            vm.revision    = [&p](const void*) -> uint64_t {
                return p.buffer ? p.buffer -> id() : 0ULL;
            };
            vm.activity     = da;
            return vm;
        }

        template <typename V>
        VBOMaker<V> vertex(VB1<V>& p, DataActivity da)
        {
            auto vm    = vbo<V>();
            vm.fetch    = [&p](const void*) -> BufferCPtr {
                return p.buffer;
            };
            vm.revision    = [&p](const void*) -> uint64_t {
                return p.buffer ? p.buffer -> id() : 0ULL;
            };
            vm.activity     = da;
            return vm;
        }

        template <typename V>
        VBOMaker<V> vertex(VBO<V> C::*p, DataActivity da)
        {
            auto vm    = vbo<V>();
            vm.activity     = da;
            vm.fetch        = [p](const void*v) -> BufferCPtr {
                const C* c = (const C*) v;
                return (c->*p).buffer;
            };
            vm.revision    = [&p](const void*v) -> uint64_t {
                const C* c = (const C*) v;
                const auto &b = (c->*p).buffer;
                return b ? b->id() : 0ULL;
            };
            return vm;
        }
        
        template <typename V>
        VBOMaker<V> vertex(VB1<V> C::*p, DataActivity da)
        {
            auto vm    = vbo<V>();
            vm.activity     = da;
            vm.fetch        = [p](const void*v) -> BufferCPtr {
                const C* c = (const C*) v;
                return (c->*p).buffer;
            };
            vm.revision    = [&p](const void*v) -> uint64_t {
                const C* c = (const C*) v;
                const auto &b = (c->*p).buffer;
                return b ? b->id() : 0ULL;
            };
            return vm;
        }

        template <typename V>
        VBOMaker<V> vertex(Mutable<std::vector<V>> C::*p, DataActivity da)
        {
            auto vm = vbo<V>();
            vm.activity     = da;
            vm.fetch   = [p](const void* v) -> BufferCPtr {
                const C* c = (const C*) v;
                const Mutable<std::vector<V>>& m    = *(c->*p);
                return buffer_array(BufferUsage::Vertex, m.get());
            };
            vm.revision    = [p](const void* v) -> uint64_t {
                const C* c = (const C*) v;
                const Mutable<std::vector<V>>& m    = (c->*p);
                return m.revision();
            };
            return vm;
        }

        template <typename V, size_t N>
        VBOMaker<V> vertex(Mutable<std::array<V,N>> C::*p, DataActivity da)
        {
            auto vm = vbo<V>();
            vm.activity     = da;
            vm.fetch   = [p](const void* v) -> BufferCPtr {
                const C* c = (const C*) v;
                const Mutable<std::array<V,N>>& m    = *(c->*p);
                return buffer_array(BufferUsage::Vertex, span(m.get()));
            };
            vm.revision    = [p](const void* v) -> uint64_t {
                const C* c = (const C*) v;
                const Mutable<std::array<V,N>>& m    = (c->*p);
                return m.revision();
            };
            return vm;
        }

        template <typename V, size_t N>
        VBOMaker<V> vertex(std::array<V,N> C::*p, DataActivity da, bool copy_it)
        {
            auto vm = vbo<V>();
            vm.activity     = da;
            if(copy_it){
                vm.fetch    = [p](const void*v) -> BufferCPtr {
                    const C* c = (const C*) v;
                    return buffer_array(BufferUsage::Vertex, span(c->*p));
                };
            } else {
                vm.fetch    = [p](const void*v) -> BufferCPtr {
                    const C* c = (const C*) v;
                    return buffer_span(BufferUsage::Vertex, span(c->*p));
                };
            }
            return vm;
        }

        template <typename V>
        VBOMaker<V> vertex(std::vector<V> C::*p, DataActivity da, bool copy_it)
        {
            auto vm = vbo<V>();
            vm.activity = da;
            if(copy_it){
                vm.fetch    = [p](const void*v) -> BufferCPtr {
                    const C* c = (const C*) v;
                    return buffer_array(BufferUsage::Vertex, (c->*p));
                };
            } else {
                vm.fetch    = [p](const void*v) -> BufferCPtr {
                    const C* c = (const C*) v;
                    return buffer_span(BufferUsage::Vertex, (c->*p));
                };
            }
            return vm;
        }

            /*
                -------------------------------------------------------
                Common data is that which is *SHARED* between instances. 
                For instance, standard vertices to a box.
            */
        
        template <typename V>
        void common_index(IBO<V>& p)
        {
            index(p, DataActivity::COMMON);
        }
        
        template <typename V>
        void common_index(IB1<V>& p)
        {
            index(p, DataActivity::COMMON);
        }
        
        template <typename V, size_t N>
        void common_index(const V(&p)[N])
        {
            index(p, DataActivity::COMMON);
        }
        
        #if 0
        template <typename V>
        void common_uniform(UBO<V>& p)
        {
        }
        
        template <typename V>
        void common_uniform(UB1<V>& p)
        {
        }
        #endif


        template <typename V>
        VBOMaker<V> common_vertex(VBO<V> &p)
        {
            return vertex(p, DataActivity::COMMON);
        }
        
        template <typename V>
        VBOMaker<V> common_vertex(VB1<V> &p)
        {
            return vertex(p, DataActivity::COMMON);
        }
        
        template <typename V, size_t N>
        VBOMaker<V> common_vertex(const V (&p)[N])
        {
            return vertex(p, DataActivity::COMMON);
        }

        template <typename V, size_t N>
        VBOMaker<V> common_vertex(std::array<V, N> &p)
        {
            return vertex(p, DataActivity::COMMON);
        }
        
        template <typename V>
        VBOMaker<V> common_vertex(std::vector<V>& p)
        {
            return vertex(p, DataActivity::COMMON);
        }

            /*
                -------------------------------------------------------
                Fixed data is specialized to the instance, but isn't going
                to change (ie static mesh for a boulder)
            */
            
        template <typename V, size_t N>
        void    fixed_index(std::array<V,N> C::*p)
        {
            index(p, DataActivity::FIXED);
        }

        template <typename V>
        void    fixed_index(std::vector<V> C::*p)
        {
            index(p, DataActivity::FIXED);
        }

        template <typename V>
        VBOMaker<V> fixed_vertex(VBO<V> C::*p)
        {
            return vertex(p, DataActivity::FIXED);
        }
        
        template <typename V>
        VBOMaker<V> fixed_vertex(VB1<V> C::*p)
        {
            return vertex(p, DataActivity::FIXED);
        }
        
        template <typename V, size_t N>
        VBOMaker<V> fixed_vertex(std::array<V,N> C::*p)
        {
            return vertex(p, DataActivity::FIXED, false);
        }

        template <typename V>
        VBOMaker<V> fixed_vertex(std::vector<V> C::*p)
        {
            return vertex(p, DataActivity::FIXED, false);
        }

        template <typename V, size_t N>
        VBOMaker<V> fixed_vertex(Mutable<std::array<V, N>> C::*p)
        {
            return vertex(p, DataActivity::FIXED);
        }
        
        template <typename V>
        VBOMaker<V> fixed_vertex(Mutable<std::vector<V>> C::*p)
        {
            return vertex(p, DataActivity::FIXED);
        }
            /*
                -------------------------------------------------------
                Dynamic data is data that may change throughout the 
                lifetime of the object, but on an infrequent basis
            */

        template <typename V>
        VBOMaker<V> dynamic_vertex(VBO<V> C::*p)
        {
            return vertex(p, DataActivity::DYNAMIC);
        }
        
        template <typename V>
        VBOMaker<V> dynamic_vertex(VB1<V> C::*p)
        {
            return vertex(p, DataActivity::DYNAMIC);
        }

        template <typename V, size_t N>
        VBOMaker<V> dynamic_vertex(Mutable<std::array<V, N>> C::*p)
        {
            return vertex(p, DataActivity::DYNAMIC);
        }
        
        template <typename V>
        VBOMaker<V> dynamic_vertex(Mutable<std::vector<V>> C::*p)
        {
            return vertex(p, DataActivity::DYNAMIC);
        }

            /*
                -------------------------------------------------------
                Frequent data is data that's expected to be changed more
                or less at frame rate.
            */
        
        template <typename V>
        void highfreq_index(IBO<V> C::*p)
        {
            index(p, DataActivity::REFRESH);
        }
        
        template <typename V>
        void highfreq_index(IB1<V> C::*p)
        {
            index(p, DataActivity::REFRESH);
        }
        
        template <typename V>
        void highfreq_index(UBO<V> C::*p)
        {
            index(p, DataActivity::REFRESH);
        }
        
        template <typename V>
        void highfreq_index(UB1<V> C::*p)
        {
            index(p, DataActivity::REFRESH);
        }

        template <typename V>
        VBOMaker<V> highfreq_vertex(VBO<V> C::*p)
        {
            return vertex(p, DataActivity::REFRESH);
        }
        
        template <typename V>
        VBOMaker<V> highfreq_vertex(VB1<V> C::*p)
        {
            return vertex(p, DataActivity::REFRESH);
        }

        template <typename V, size_t N>
        VBOMaker<V> highfreq_vertex(std::array<V,N> C::*p)
        {
            return vertex(p, DataActivity::REFRESH, true);
        }

        template <typename V>
        VBOMaker<V> highfreq_vertex(std::vector<V> C::*p)
        {
            return vertex(p, DataActivity::REFRESH, true);
        }

        template <typename V, size_t N>
        VBOMaker<V> highfreq_vertex(Mutable<std::array<V, N>> C::*p)
        {
            return vertex(p, DataActivity::REFRESH);
        }
        
        template <typename V>
        VBOMaker<V> highfreq_vertex(Mutable<std::vector<V>> C::*p)
        {
            return vertex(p, DataActivity::REFRESH);
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
}
