////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "PipelineConfig.hpp"
#include "PipelineUtils.hpp"
#include <basic/trait/not_copyable.hpp>
#include <basic/trait/not_moveable.hpp>
#include <set>
#include <span>
#include <cassert>
#include <functional>

namespace yq {
    namespace engine {

        class PipelineBuilder {
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
        
            PipelineBuilder(PipelineConfig& cfg);
            ~PipelineBuilder();
            
            void        ubo(size_t cnt=1);

        protected:
            PipelineBuilder(PipelineConfig*);
            uint32_t                location_filter(uint32_t loc, uint32_t req);

        private:
            PipelineConfig* const   m_config;
            std::set<uint32_t>      m_locations;
        };


        template <typename V>
        class PipelineBuilder::VBO : public VBOConfig, trait::not_copyable {
        public:
        
            VBO(PipelineBuilder* cfg, std::function<void(uint32_t)> info={}) : m_builder(cfg), m_info(info)
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

            PipelineBuilder*                m_builder   = nullptr;
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
        PipelineBuilder::VBO<V>     PipelineBuilder::vbo()
        {
            return VBO<V>(this);
        }
    }
}
