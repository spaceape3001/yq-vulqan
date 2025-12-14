////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/util/steal.hpp>
#include <yq/container/BasicBuffer.hpp>
#include <yq/math/glm_types.hpp>
#include <yq/trait/member_offset.hpp>

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/pipeline/SBO.hpp>
#include <yq/tachyon/pipeline/UBO.hpp>
#include <yq/tachyon/pipeline/VBO.hpp>
#include <yq/tachyon/config/vulqan.hpp>
#include <yq/tachyon/pipeline/Pipeline.hpp>
#include <yq/tachyon/pipeline/PipelineUtils.hpp>
#include <yq/tachyon/asset/Texture.hpp>

namespace yq::tachyon {

    template <typename V> 
    class Pipeline::VBOMaker : public Pipeline::vertex_buffer_t {
    public:
    
        VBOMaker(VBOMaker&& mv) : vertex_buffer_t(std::move(mv))
        {
            steal(m_pipeline, mv.m_pipeline);
        }

        VBOMaker(const VBOMaker&) = delete;
        VBOMaker&   operator=(const VBOMaker&) = delete;
        
        VBOMaker&   operator=(VBOMaker&& mv)
        {
            if(this != &mv){
                vertex_buffer_t::operator=(std::move(mv));
                steal(m_pipeline, mv.m_pipeline);
            }
            return *this;
        }
        
        ~VBOMaker()
        {
            if(!m_pipeline)
                return ;
            
            if(attributes.empty()){
                if constexpr (is_type_v<V>){
                    typed_attribute<V>(0);
                }
            }
            assert(!attributes.empty());

            m_pipeline -> m_vertexBuffers.push_back(*this);
        }

        template  <typename M>
        requires is_type_v<M>
        VBOMaker& attribute(M V::*member)
        {
            typed_attribute<M>((uint32_t) member_offset(member));
            return *this;
        }
        
        template  <typename M>
        VBOMaker& attribute(M V::*member, DataFormat fmt)
        {
            attr_impl(fmt, (uint32_t) member_offset(member), min_binding<M>());
            return *this;
        }
        
    private:
        friend class Pipeline;
    
        VBOMaker(Pipeline* b, const v_config& cc) : m_pipeline(b)
        {
            stride      = sizeof(V);
            activity    = cc.activity;
            external    = cc.external;
            stages      = cc.stages;
            binding     = b->m_vertexBuffers.size();
        }
        

        Pipeline*    m_pipeline;

        template <typename A>
        requires is_type_v<A>
        void    typed_attribute(uint32_t offset)
        {
            attr_impl(data_format<A>(), offset, min_binding<A>(), &meta<A>());
        }
        
        void    attr_impl(DataFormat df, uint32_t offset, uint32_t bindReq, const TypeMeta* ti=nullptr)
        {
            if(!m_pipeline)
                return ;
                
            assert((df != DataFormat()) && "Bad data format!");
            if(df == DataFormat())
                return ;
                
            attribute_t     a;
            a.location  = m_pipeline->location_filter(UINT32_MAX, bindReq);
            a.offset    = offset;
            a.format    = df;
            a.type      = ti;
            attributes.push_back(a);
        }
    };
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  STATIC PIPELINE

    template <typename V>
    Pipeline::index_buffer_t  Pipeline::ibo_(const i_config& cc)
    {
        index_buffer_t  cfg;
        cfg.type        = index_type<V>();
        cfg.activity    = cc.activity;
        cfg.stride      = sizeof(V);
        cfg.stages      = cc.stages;
        cfg.external    = cc.external;
        return cfg;
    }
    
    template <typename V>
    Pipeline::storage_buffer_t  Pipeline::sbo_(uint32_t cnt, const s_config& cc)
    {
        storage_buffer_t  cfg;
        cfg.activity    = cc.activity;
        cfg.size        = sizeof(V);
        cfg.count       = cnt;
        cfg.stages      = cc.stages;
        cfg.binding     = filter_binding(cc.binding);
        cfg.external    = cc.external;
        
        if(cfg.binding == UINT32_MAX){
            cfg.binding = 0;
            for(auto& s : m_storageBuffers){
                if(cfg.binding <= s.binding)
                    cfg.binding = s.binding + 1;
            }
        }
        
        return cfg;
    }

    template <typename V>
    Pipeline::uniform_buffer_t  Pipeline::ubo_(uint32_t cnt, const u_config& cc)
    {
        uniform_buffer_t       cfg;
        cfg.activity    = cc.activity;
        cfg.size        = sizeof(V);
        cfg.count       = cnt;
        cfg.stages      = cc.stages;
        cfg.binding     = filter_binding(cc.binding);
        cfg.external    = cc.external;
        if(cfg.binding == UINT32_MAX){
            cfg.binding = 0;
            for(auto& s : m_uniformBuffers){
                if(cfg.binding <= s.binding)
                    cfg.binding = s.binding + 1;
            }
        }
        return cfg;
    }

    template <typename V>
    Pipeline::VBOMaker<V>     Pipeline::vbo_(const v_config&cc)
    {
        return VBOMaker<V>(this, cc);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  PIPELINE

    template <typename V>
    uint32_t    Pipeline::index(const i_config&cc)
    {
        index_buffer_t       cfg = ibo_<V>(cc);
        m_indexBuffer   = cfg;
        return 0;
    }

    template <typename T>
    void            Pipeline::push()
    {
        static_assert(std::is_trivially_copyable_v<T>, "Must be trivially copyable!");
        static_assert(sizeof(T) <= MAX_PUSH, "Push type is TOO big!");
        m_push.type  = PushConfigType::Custom;
        m_push.size  = sizeof(T);
    }

    template <typename V>
    uint32_t    Pipeline::storage(const s_config& cc)
    {
        storage_buffer_t       cfg = sbo_<V>(1, cc);
        uint32_t ret = (uint32_t) m_storageBuffers.size();
        m_storageBuffers.push_back(cfg);
        return ret;
    }
    
    template <typename V>
    uint32_t    Pipeline::storage(uint32_t cnt, const s_config& cc)
    {
        storage_buffer_t       cfg = sbo_<V>(cnt, cc);
        uint32_t ret = (uint32_t) m_storageBuffers.size();
        m_storageBuffers.push_back(cfg);
        return ret;
    }

    template <typename V>
    uint32_t    Pipeline::storage(dynamic_k, const s_config& cc)
    {
        storage_buffer_t       cfg = sbo_<V>(0, cc);
        uint32_t ret = (uint32_t) m_storageBuffers.size();
        m_storageBuffers.push_back(cfg);
        return ret;
    }

    template <typename V>
    uint32_t    Pipeline::uniform(uint32_t cnt, const u_config& uc)
    {
        uniform_buffer_t       cfg = ubo_<V>(cnt, uc);
        uint32_t ret = (uint32_t) m_uniformBuffers.size();
        m_uniformBuffers.push_back(cfg);
        return ret;
    }

    template <typename V>
    uint32_t    Pipeline::uniform(const u_config& cc)
    {
        uniform_buffer_t       cfg = ubo_<V>(1, cc);
        uint32_t ret = (uint32_t) m_uniformBuffers.size();
        m_uniformBuffers.push_back(cfg);
        return ret;
    }


    template <typename V>
    Pipeline::VBOMaker<V> Pipeline::vertex(const v_config& cc)
    {
        auto cfg    = vbo_<V>(cc);
        return cfg;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  TYPED PIPELINE

    template <typename C>
    class Pipeline::Typed : public Pipeline {
    public:
    
        //static_assert(is_type_v<C> || is_object_v<C>);
    
        Typed(Role role) : Pipeline(&meta<C>(), role)
        {
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
        
        using Pipeline::push;

        template <typename T, typename B=C>
        requires std::is_base_of_v<B,C>
        void        push(T (B::*p))
        {
            static_assert(sizeof(T) <= MAX_PUSH, "T is TOO BIG!");
            static_assert(std::is_trivially_copyable_v<T>, "Must be trivially copyable!");
        
            m_push.type   = PushConfigType::Custom;
            m_push.size   = sizeof(T);
            m_push.fetch  = [p](const void* obj, PushBuffer& buf) {
                const C* c  = (const C*) obj;
                buf.paste( (c->*p) );
            };
        }
            

        /*
            =======================================================
            INDEX BUFFERS
            =======================================================
        */
        
        template <typename V>
        uint32_t    index(IBO<V>& p, const i_config& cc=i_static())
        {
            index_buffer_t       cfg = ibo_<V>(cc);
            YQ_PIPELINE_COMMON_HANDLER
            m_indexBuffer       = cfg;
            return 0;
        }

        template <typename V>
        uint32_t    index(IB1<V>& p, const i_config& cc=i_static())
        {
            index_buffer_t       cfg = ibo_<V>(cc);
            YQ_PIPELINE_COMMON_HANDLER
            m_indexBuffer       = cfg;
            return 0;
        }

        template <typename V, typename B=C>
        requires std::is_base_of_v<B,C>
        uint32_t   index(IBO<V> B::*p, const i_config& cc=i_dynamic())
        {
            index_buffer_t       cfg = ibo_<V>(cc);
            YQ_PIPELINE_MEMBER_HANDLER
            m_indexBuffer       = cfg;
            return 0;
        }

        template <typename V, typename B=C>
        requires std::is_base_of_v<B,C>
        uint32_t   index(IB1<V> B::*p, const i_config& cc=i_dynamic())
        {
            index_buffer_t       cfg = ibo_<V>(cc);
            YQ_PIPELINE_MEMBER_HANDLER
            m_indexBuffer       = cfg;
            return 0;
        }

        /*
            =======================================================
            STORAGE BUFFERS
            =======================================================
        */
        
        template <typename V>
        uint32_t    storage(SBO<V>& p, uint32_t cnt, const s_config& cc=s_common())
        {
            storage_buffer_t       cfg = sbo_<V>(cnt, cc);
            YQ_PIPELINE_COMMON_HANDLER
            uint32_t ret = (uint32_t) m_storageBuffers.size();
            m_storageBuffers.push_back(cfg);
            return ret;
        }
        
        template <typename V>
        uint32_t    storage(SB1<V>& p, uint32_t cnt, const s_config& cc=s_common())
        {
            storage_buffer_t       cfg = sbo_<V>(cnt, cc);
            YQ_PIPELINE_COMMON_HANDLER
            uint32_t ret = (uint32_t) m_storageBuffers.size();
            m_storageBuffers.push_back(cfg);
            return ret;
        }

        template <typename V>
        uint32_t    storage(SBO<V>& p, dynamic_k, const s_config& cc=s_common())
        {
            return storage(p, 0, cc);
        }
        
        template <typename V>
        uint32_t    storage(SB1<V>& p, dynamic_k, const s_config& cc=s_common())
        {
            return storage(p, 0, cc);
        }

        template <typename V>
        uint32_t    storage(SBO<V>& p, const s_config& cc=s_common())
        {
            return storage(p, 1, cc);
        }
        
        template <typename V>
        uint32_t    storage(SB1<V>& p, const s_config& cc=s_common())
        {
            return storage(p, 1, cc);
        }
        
        
        template <typename V, typename B=C>
        requires std::is_base_of_v<B,C>
        uint32_t    storage(SBO<V> B::*p, uint32_t cnt, const s_config& cc=s_dynamic())
        {
            storage_buffer_t       cfg = sbo_<V>(cnt, cc);
            YQ_PIPELINE_MEMBER_HANDLER
            uint32_t ret = (uint32_t) m_storageBuffers.size();
            m_storageBuffers.push_back(cfg);
            return ret;
        }
        
        template <typename V, typename B=C>
        requires std::is_base_of_v<B,C>
        uint32_t    storage(SB1<V> B::*p, uint32_t cnt, const s_config& cc=s_dynamic())
        {
            storage_buffer_t       cfg = sbo_<V>(cnt, cc);
            YQ_PIPELINE_MEMBER_HANDLER
            uint32_t ret = (uint32_t) m_storageBuffers.size();
            m_storageBuffers.push_back(cfg);
            return ret;
        }

        template <typename V, typename B=C>
        requires std::is_base_of_v<B,C>
        uint32_t    storage(SBO<V> B::*p, dynamic_k, const s_config& cc=s_dynamic())
        {
            return storage(p, 0, cc);
        }
        
        template <typename V, typename B=C>
        requires std::is_base_of_v<B,C>
        uint32_t    storage(SB1<V> B::*p, dynamic_k, const s_config& cc=s_dynamic())
        {
            return storage(p, 0, cc);
        }

        template <typename V, typename B=C>
        requires std::is_base_of_v<B,C>
        uint32_t    storage(SBO<V> B::*p, const s_config& cc=s_dynamic())
        {
            return storage(p, 1, cc);
        }
        
        template <typename V, typename B=C>
        requires std::is_base_of_v<B,C>
        uint32_t    storage(SB1<V> B::*p, const s_config& cc=s_dynamic())
        {
            return storage(p, 1, cc);
        }


        /*
            =======================================================
            UNIFORM BUFFERS
            =======================================================
        */
        
        template <typename V>
        uint32_t    uniform(UBO<V>& p, uint32_t cnt, const u_config& cc=u_common())
        {
            uniform_buffer_t       cfg = ubo_<V>(cnt, cc);
            YQ_PIPELINE_COMMON_HANDLER
            uint32_t ret = (uint32_t) m_uniformBuffers.size();
            m_uniformBuffers.push_back(cfg);
            return ret;
        }
        
        template <typename V>
        uint32_t    uniform(UB1<V>& p, uint32_t cnt, const u_config& cc=u_common())
        {
            uniform_buffer_t       cfg = ubo_<V>(cnt, cc);
            YQ_PIPELINE_COMMON_HANDLER
            uint32_t ret = (uint32_t) m_uniformBuffers.size();
            m_uniformBuffers.push_back(cfg);
            return ret;
        }

        template <typename V>
        uint32_t    uniform(UBO<V>& p, const u_config& cc=u_common())
        {
            return uniform(p, 1, cc);
        }
        
        template <typename V>
        uint32_t    uniform(UB1<V>& p, const u_config& cc=u_common())
        {
            return uniform(p, 1, cc);
        }
        
        
        template <typename V, typename B=C>
        requires std::is_base_of_v<B,C>
        uint32_t    uniform(UBO<V> B::*p, uint32_t cnt, const u_config& cc=u_dynamic())
        {
            uniform_buffer_t       cfg = ubo_<V>(cnt, cc);
            YQ_PIPELINE_MEMBER_HANDLER
            uint32_t ret = (uint32_t) m_uniformBuffers.size();
            m_uniformBuffers.push_back(cfg);
            return ret;
        }
        
        template <typename V, typename B=C>
        requires std::is_base_of_v<B,C>
        uint32_t    uniform(UB1<V> B::*p, uint32_t cnt, const u_config& cc=u_dynamic())
        {
            uniform_buffer_t       cfg = ubo_<V>(cnt, cc);
            YQ_PIPELINE_MEMBER_HANDLER
            uint32_t ret = (uint32_t) m_uniformBuffers.size();
            m_uniformBuffers.push_back(cfg);
            return ret;
        }

        template <typename V, typename B=C>
        requires std::is_base_of_v<B,C>
        uint32_t    uniform(UBO<V> B::*p, const u_config& cc=u_dynamic())
        {
            return uniform(p, 1, cc);
        }
        
        template <typename V, typename B=C>
        requires std::is_base_of_v<B,C>
        uint32_t    uniform(UB1<V> B::*p, const u_config& cc=u_dynamic())
        {
            return uniform(p, 1, cc);
        }
        
        /*
            =======================================================
            VERTEX BUFFERS
            =======================================================
        */

        template <typename V>
        VBOMaker<V> vertex(VBO<V>& p, const v_config& cc=v_common())
        {
            auto cfg    = vbo_<V>(cc);
            YQ_PIPELINE_COMMON_HANDLER
            return cfg;
        }
        
        template <typename V>
        VBOMaker<V> vertex(VB1<V>& p, const v_config& cc=v_common())
        {
            auto cfg    = vbo_<V>(cc);
            YQ_PIPELINE_COMMON_HANDLER
            return cfg;
        }

        template <typename V, typename B=C>
        requires std::is_base_of_v<B,C>
        VBOMaker<V> vertex(VBO<V> B::*p, const v_config& cc=v_refresh())
        {
            auto cfg    = vbo_<V>(cc);
            YQ_PIPELINE_MEMBER_HANDLER
            return cfg;
        }
        
        template <typename V, typename B=C>
        requires std::is_base_of_v<B,C>
        VBOMaker<V> vertex(VB1<V> B::*p, const v_config& cc=v_refresh())
        {
            auto cfg    = vbo_<V>(cc);
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

        uint32_t texture(Ref<const Texture> &p, const t_config& cc = t_common())
        {
            texture_t   cfg = tex_(cc);
            cfg.fetch       = [&p](const void*) -> TextureCPtr {
                return p;
            };
            cfg.revision    = [&p](const void*) -> uint64_t {
                return p ? p->id() : 0ULL;
            };
            uint32_t ret = (uint32_t) m_textures.size();
            m_textures.push_back(cfg);
            return ret;
        }

        template <typename B=C>
        requires std::is_base_of_v<B,C>
        uint32_t    texture(Ref<const Texture> B::*p, const t_config& cc = t_dynamic())
        {
            texture_t   cfg = tex_(cc);
            cfg.fetch       = [p](const void*v) -> TextureCPtr {
                const C* c = (const C*) v;
                return (c->*p);
            };
            cfg.revision    = [p](const void*v) -> uint64_t {
                const C*c   = (const C*) v;
                const Ref<const Texture>&   t   = (c->*p);
                return t ? t->id() : 0ULL;
            };
            uint32_t ret = (uint32_t) m_textures.size();
            m_textures.push_back(cfg);
            return ret;
        }

    };
}

