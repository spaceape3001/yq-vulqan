////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/BasicBuffer.hpp>
#include <tachyon/gfx/Pipeline.hpp>
#include <tachyon/gfx/PipelineConfig.hpp>
#include <tachyon/gfx/PipelineUtils.hpp>
#include <tachyon/gfx/UBO.hpp>
#include <tachyon/gfx/VBO.hpp>
#include <trait/not_copyable.hpp>
#include <trait/not_moveable.hpp>
#include <set>
#include <span>
#include <cassert>
#include <functional>
#include <type_traits>

namespace yq {
    namespace tachyon {
    
        
        class Pipeline::Builder {
        public:
        
        
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

            void        ubo(size_t cnt=1);

            template <typename V>
            VBOMaker<V> vbo();

        /// other stuff

            Builder(std::string_view name = std::string_view());
            ~Builder();

            PipelineConfig&     config() { return m_build; }
            
            template <typename V>
            static IndexType    index_type();
            

        protected:
            friend class Pipeline;
            template <typename> friend class VBOMaker;
            PipelineConfig      m_build;
            
            uint32_t            location_filter(uint32_t loc, uint32_t req);

        private:
            std::set<uint32_t>  m_locations;
        };
        
        
        template <typename V> 
        class Pipeline::VBOMaker : VBOConfig, not_copyable {
        public:
        
            VBOMaker(VBOMaker&& mv) : VBOConfig(std::move(mv))
            {
                steal(m_builder, mv.m_builder);
            }
            
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

            VBOMaker&     rate(VertexInputRate vr)
            {
                m_config.inputRate   = vr;
                return *this;
            }
            
            VBOMaker&   activity(DataActivity v)
            {
                m_config.activity    = v;
                return *this;
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
                m_config.stride  = sizeof(V);
            }
            

            Builder*    m_builder;
            VBOConfig   m_config;
            uint32_t    m_location  = UINT32_MAX;

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
        IndexType    Pipeline::Builder::index_type()
        {
            if constexpr (std::is_same_v<V,uint8_t>)
                return IndexType::uint8;
            if constexpr (std::is_same_v<V,uint16_t>)
                return IndexType::uint16;
            if constexpr (std::is_same_v<V,uint32_t>)
                return IndexType::uint32;
            return IndexType::none;
        }

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
                
            Typed(std::string_view name=std::string_view()) : Builder(name) 
            {
                if constexpr ( is_type_v<C>){
                    m_build.object = &meta<C>();
                }
                if constexpr ( is_object_v<C>){
                    m_build.object = &meta<C>();
                }
            }


                /*
                    -------------------------------------------------------
                    Common data is that which is *SHARED* between instances. 
                    For instance, standard vertices to a box.
                */
            
            template <typename V>
            void common(IBO<V>& p)
            {
                IBOConfig       cfg;
                cfg.type    = index_type<V>();
                cfg.fetch   = [&p](const void*) -> BufferCPtr {
                    return p.buffer;
                };
            }
            
            template <typename V>
            void common(IB1<V>& p)
            {
                IBOConfig       cfg;
                cfg.type    = index_type<V>();
                cfg.fetch   = [&p](const void*) -> BufferCPtr {
                    return p.buffer;
                };
            }
            
            #if 0
            template <typename V>
            void common(UBO<V>& p)
            {
            }
            
            template <typename V>
            void common(UB1<V>& p)
            {
            }
            #endif

            template <typename V>
            VBOMaker<V> common(VBO<V> &p)
            {
                auto vm    = vbo<V>();
                vm.activity = DataActivity::COMMON;
                vm.fetch    = [&p](const void*) -> BufferCPtr {
                    return p.buffer;
                };
                return vm;
            }
            
            template <typename V>
            VBOMaker<V> common(VB1<V> p)
            {
                auto vm    = vbo<V>();
                vm.activity = DataActivity::COMMON;
                vm.fetch    = [&p](const void*) -> BufferCPtr {
                    return p.buffer;
                };
                return vm;
            }

                /*
                    -------------------------------------------------------
                    Fixed data is specialized to the instance, but isn't going
                    to change (ie static mesh for a boulder)
                */

            template <typename V>
            VBOMaker<V> fixed(VBO<V> C::*p)
            {
                auto vm    = vbo<V>();
                vm.activity = DataActivity::STATIC;
                vm.fetch    = [&p](const void*v) -> BufferCPtr {
                    const C* c = (const C*) v;
                    return (v->*c).buffer;
                };
                return vm;
            }
            
            template <typename V>
            VBOMaker<V> fixed(VB1<V> C::*p)
            {
                auto vm    = vbo<V>();
                vm.activity = DataActivity::STATIC;
                vm.fetch    = [&p](const void*v) -> BufferCPtr {
                    const C* c = (const C*) v;
                    return (v->*c).buffer;
                };
                return vm;
            }

                /*
                    -------------------------------------------------------
                    Dynamic data is data that may change throughout the 
                    lifetime of the object, but on an infrequent basis
                */

            template <typename V>
            VBOMaker<V> dynamic(VBO<V> C::*p)
            {
                auto vm    = vbo<V>();
                vm.activity = DataActivity::DYNAMIC;
                vm.fetch    = [&p](const void*v) -> BufferCPtr {
                    const C* c = (const C*) v;
                    return (v->*c).buffer;
                };
                return vm;
            }
            
            template <typename V>
            VBOMaker<V> dynamic(VB1<V> C::*p)
            {
                auto vm    = vbo<V>();
                vm.activity = DataActivity::DYNAMIC;
                vm.fetch    = [&p](const void*v) -> BufferCPtr {
                    const C* c = (const C*) v;
                    return (v->*c).buffer;
                };
                return vm;
            }

                /*
                    -------------------------------------------------------
                    Frequent data is data that's expected to be changed more
                    or less at frame rate.
                */
            
            template <typename V>
            void frequent(IBO<V> C::*p)
            {
            }
            
            template <typename V>
            void frequent(IB1<V> C::*p)
            {
            }
            
            template <typename V>
            void frequent(UBO<V> C::*p)
            {
            }
            
            template <typename V>
            void frequent(UB1<V> C::*p)
            {
            }

            template <typename V>
            VBOMaker<V> frequent(VBO<V> C::*p)
            {
                auto vm    = vbo<V>();
                vm.activity = DataActivity::REFRESH;
                vm.fetch    = [&p](const void*v) -> BufferCPtr {
                    const C* c = (const C*) v;
                    return (v->*c).buffer;
                };
                return vm;
            }
            
            template <typename V>
            VBOMaker<V> frequent(VB1<V> C::*p)
            {
                auto vm    = vbo<V>();
                vm.activity = DataActivity::REFRESH;
                vm.fetch    = [&p](const void*v) -> BufferCPtr {
                    const C* c = (const C*) v;
                    return (v->*c).buffer;
                };
                return vm;
            }
        };

        template <typename C>
        auto Pipeline::build(std::string_view name)
        {
            if constexpr (std::is_same_v<C,void>)
                return Builder(name);
            if constexpr (!std::is_same_v<C,void>){
                static_assert(std::is_class_v<C>, "Must either build to void or a class/structure!");
                return Typed<C>(name);
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
}
