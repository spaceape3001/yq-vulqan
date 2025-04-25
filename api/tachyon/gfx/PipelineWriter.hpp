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

#include <tachyon/keywords.hpp>
#include <tachyon/gfx/SBO.hpp>
#include <tachyon/gfx/UBO.hpp>
#include <tachyon/gfx/VBO.hpp>
#include <tachyon/config/vulqan.hpp>
#include <tachyon/gfx/Pipeline.hpp>
#include <tachyon/gfx/PipelineUtils.hpp>
#include <tachyon/gfx/Texture.hpp>

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
    
        VBOMaker(Pipeline* b, DataActivity da, uint32_t stages) : m_pipeline(b)
        {
            stride      = sizeof(V);
            activity    = da;
            shaders     = stages;
        }
        

        Pipeline*    m_pipeline;

        template <typename A>
        requires is_type_v<A>
        void    typed_attribute(uint32_t offset)
        {
            attr_impl(data_format<A>(), offset, min_binding<A>(), &meta<A>());
        }
        
        void    attr_impl(DataFormat df, uint32_t offset, uint32_t bindReq, const TypeInfo* ti=nullptr)
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
    Pipeline::index_buffer_t  Pipeline::ibo_(DataActivity da)
    {
        index_buffer_t  cfg;
        cfg.type        = index_type<V>();
        cfg.activity    = da;
        cfg.stride      = sizeof(V);
        return cfg;
    }
    
    template <typename V>
    Pipeline::storage_buffer_t  Pipeline::sbo_(uint32_t cnt, DataActivity da, uint32_t stages)
    {
        storage_buffer_t  cfg;
        cfg.activity    = da;
        cfg.size        = sizeof(V);
        cfg.count       = cnt;
        cfg.shaders     = stages;
        return cfg;
    }

    template <typename V>
    Pipeline::uniform_buffer_t  Pipeline::ubo_(uint32_t cnt, DataActivity da, uint32_t stages)
    {
        uniform_buffer_t       cfg;
        cfg.activity    = da;
        cfg.size        = sizeof(V);
        cfg.count       = cnt;
        cfg.shaders     = stages;
        return cfg;
    }

    template <typename V>
    Pipeline::VBOMaker<V>     Pipeline::vbo_(DataActivity da, uint32_t stages)
    {
        return VBOMaker<V>(this, da, stages);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  PIPELINE

    template <typename V>
    uint32_t    Pipeline::index(DataActivity da)
    {
        index_buffer_t       cfg = ibo_<V>(da);
        uint32_t ret = (uint32_t) m_indexBuffers.size();
        m_indexBuffers.push_back(cfg);
        return ret;
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
    uint32_t    Pipeline::storage(DataActivity da, uint32_t stages)
    {
        storage_buffer_t       cfg = sbo_<V>(1, da, stages);
        uint32_t ret = (uint32_t) m_storageBuffers.size();
        m_storageBuffers.push_back(cfg);
        return ret;
    }
    
    template <typename V>
    uint32_t    Pipeline::storage(uint32_t cnt, DataActivity da, uint32_t stages)
    {
        storage_buffer_t       cfg = sbo_<V>(cnt, da, stages);
        uint32_t ret = (uint32_t) m_storageBuffers.size();
        m_storageBuffers.push_back(cfg);
        return ret;
    }

    template <typename V>
    uint32_t    Pipeline::uniform(uint32_t cnt, DataActivity da, uint32_t stages)
    {
        uniform_buffer_t       cfg = ubo_<V>(cnt, da, stages);
        uint32_t ret = (uint32_t) m_uniformBuffers.size();
        m_uniformBuffers.push_back(cfg);
        return ret;
    }

    template <typename V>
    uint32_t    Pipeline::uniform(DataActivity da, uint32_t stages)
    {
        uniform_buffer_t       cfg = ubo_<V>(1, da, stages);
        uint32_t ret = (uint32_t) m_uniformBuffers.size();
        m_uniformBuffers.push_back(cfg);
        return ret;
    }

    template <typename V>
    Pipeline::VBOMaker<V> Pipeline::vertex(DataActivity da, uint32_t stages)
    {
        auto cfg    = vbo_<V>(da, stages);
        return cfg;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  TYPED PIPELINE

    template <typename C>
    class Pipeline::Typed : public Pipeline {
    public:
    
        static_assert(is_type_v<C> || is_object_v<C>);
    
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

        template <typename T>
        void        push(T (C::*p))
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
        uint32_t    index(IBO<V>& p, DataActivity da=DataActivity::COMMON)
        {
            index_buffer_t       cfg = ibo_<V>(da);
            YQ_PIPELINE_COMMON_HANDLER
            uint32_t ret = (uint32_t) m_indexBuffers.size();
            m_indexBuffers.push_back(cfg);
            return ret;
        }

        template <typename V>
        uint32_t    index(IB1<V>& p, DataActivity da=DataActivity::COMMON)
        {
            index_buffer_t       cfg = ibo_<V>(da);
            YQ_PIPELINE_COMMON_HANDLER
            uint32_t ret = (uint32_t) m_indexBuffers.size();
            m_indexBuffers.push_back(cfg);
            return ret;
        }

        template <typename V>
        uint32_t   index(IBO<V> C::*p, DataActivity da=DataActivity::DYNAMIC)
        {
            index_buffer_t       cfg = ibo_<V>(da);
            YQ_PIPELINE_MEMBER_HANDLER
            uint32_t ret = (uint32_t) m_indexBuffers.size();
            m_indexBuffers.push_back(cfg);
            return ret;
        }

        template <typename V>
        uint32_t   index(IB1<V> C::*p, DataActivity da=DataActivity::DYNAMIC)
        {
            index_buffer_t       cfg = ibo_<V>(da);
            YQ_PIPELINE_MEMBER_HANDLER
            uint32_t ret = (uint32_t) m_indexBuffers.size();
            m_indexBuffers.push_back(cfg);
            return ret;
        }

        /*
            =======================================================
            STORAGE BUFFERS
            =======================================================
        */
        
        template <typename V>
        uint32_t    storage(SBO<V>& p, uint32_t cnt, DataActivity da=DataActivity::COMMON, uint32_t stages=0)
        {
            storage_buffer_t       cfg = sbo_<V>(cnt, da, stages);
            YQ_PIPELINE_COMMON_HANDLER
            uint32_t ret = (uint32_t) m_storageBuffers.size();
            m_storageBuffers.push_back(cfg);
            return ret;
        }
        
        template <typename V>
        uint32_t    storage(SB1<V>& p, uint32_t cnt, DataActivity da=DataActivity::COMMON, uint32_t stages=0)
        {
            storage_buffer_t       cfg = sbo_<V>(cnt, da, stages);
            YQ_PIPELINE_COMMON_HANDLER
            uint32_t ret = (uint32_t) m_storageBuffers.size();
            m_storageBuffers.push_back(cfg);
            return ret;
        }

        template <typename V>
        uint32_t    storage(SBO<V>& p, DataActivity da=DataActivity::COMMON, uint32_t stages=0)
        {
            return storage(p, 1, da, stages);
        }
        
        template <typename V>
        uint32_t    storage(SB1<V>& p, DataActivity da=DataActivity::COMMON, uint32_t stages=0)
        {
            return storage(p, 1, da, stages);
        }
        
        
        template <typename V>
        uint32_t    storage(SBO<V> C::*p, uint32_t cnt, DataActivity da=DataActivity::DYNAMIC, uint32_t stages=0)
        {
            storage_buffer_t       cfg = sbo_<V>(cnt, da, stages);
            YQ_PIPELINE_MEMBER_HANDLER
            uint32_t ret = (uint32_t) m_storageBuffers.size();
            m_storageBuffers.push_back(cfg);
            return ret;
        }
        
        template <typename V>
        uint32_t    storage(SB1<V> C::*p, uint32_t cnt, DataActivity da=DataActivity::DYNAMIC, uint32_t stages=0)
        {
            storage_buffer_t       cfg = sbo_<V>(cnt, da, stages);
            YQ_PIPELINE_MEMBER_HANDLER
            uint32_t ret = (uint32_t) m_storageBuffers.size();
            m_storageBuffers.push_back(cfg);
            return ret;
        }

        template <typename V>
        uint32_t    storage(SBO<V> C::*p, DataActivity da=DataActivity::DYNAMIC, uint32_t stages=0)
        {
            return storage(p, 1, da, stages);
        }
        
        template <typename V>
        uint32_t    storage(SB1<V> C::*p, DataActivity da=DataActivity::DYNAMIC, uint32_t stages=0)
        {
            return storage(p, 1, da, stages);
        }


        /*
            =======================================================
            UNIFORM BUFFERS
            =======================================================
        */
        
        template <typename V>
        uint32_t    uniform(UBO<V>& p, uint32_t cnt, DataActivity da=DataActivity::COMMON, uint32_t stages=0)
        {
            uniform_buffer_t       cfg = ubo_<V>(cnt, da, stages);
            YQ_PIPELINE_COMMON_HANDLER
            uint32_t ret = (uint32_t) m_uniformBuffers.size();
            m_uniformBuffers.push_back(cfg);
            return ret;
        }
        
        template <typename V>
        uint32_t    uniform(UB1<V>& p, uint32_t cnt, DataActivity da=DataActivity::COMMON, uint32_t stages=0)
        {
            uniform_buffer_t       cfg = ubo_<V>(cnt, da, stages);
            YQ_PIPELINE_COMMON_HANDLER
            uint32_t ret = (uint32_t) m_uniformBuffers.size();
            m_uniformBuffers.push_back(cfg);
            return ret;
        }

        template <typename V>
        uint32_t    uniform(UBO<V>& p, DataActivity da=DataActivity::COMMON, uint32_t stages=0)
        {
            return uniform(p, 1, da, stages);
        }
        
        template <typename V>
        uint32_t    uniform(UB1<V>& p, DataActivity da=DataActivity::COMMON, uint32_t stages=0)
        {
            return uniform(p, 1, da, stages);
        }
        
        
        template <typename V>
        uint32_t    uniform(UBO<V> C::*p, uint32_t cnt, DataActivity da=DataActivity::DYNAMIC, uint32_t stages=0)
        {
            uniform_buffer_t       cfg = ubo_<V>(cnt, da, stages);
            YQ_PIPELINE_MEMBER_HANDLER
            uint32_t ret = (uint32_t) m_uniformBuffers.size();
            m_uniformBuffers.push_back(cfg);
            return ret;
        }
        
        template <typename V>
        uint32_t    uniform(UB1<V> C::*p, uint32_t cnt, DataActivity da=DataActivity::DYNAMIC, uint32_t stages=0)
        {
            uniform_buffer_t       cfg = ubo_<V>(cnt, da, stages);
            YQ_PIPELINE_MEMBER_HANDLER
            uint32_t ret = (uint32_t) m_uniformBuffers.size();
            m_uniformBuffers.push_back(cfg);
            return ret;
        }

        template <typename V>
        uint32_t    uniform(UBO<V> C::*p, DataActivity da=DataActivity::DYNAMIC, uint32_t stages=0)
        {
            return uniform(p, 1, da, stages);
        }
        
        template <typename V>
        uint32_t    uniform(UB1<V> C::*p, DataActivity da=DataActivity::DYNAMIC, uint32_t stages=0)
        {
            return uniform(p, 1, da, stages);
        }
        
        /*
            =======================================================
            VERTEX BUFFERS
            =======================================================
        */

        template <typename V>
        VBOMaker<V> vertex(VBO<V>& p, DataActivity da=DataActivity::COMMON, uint32_t stages=0)
        {
            auto cfg    = vbo_<V>(da, stages);
            YQ_PIPELINE_COMMON_HANDLER
            return cfg;
        }
        
        template <typename V>
        VBOMaker<V> vertex(VB1<V>& p, DataActivity da=DataActivity::COMMON, uint32_t stages=0)
        {
            auto cfg    = vbo_<V>(da, stages);
            YQ_PIPELINE_COMMON_HANDLER
            return cfg;
        }

        template <typename V>
        VBOMaker<V> vertex(VBO<V> C::*p, DataActivity da=DataActivity::DYNAMIC, uint32_t stages=0)
        {
            auto cfg    = vbo_<V>(da, stages);
            YQ_PIPELINE_MEMBER_HANDLER
            return cfg;
        }
        
        template <typename V>
        VBOMaker<V> vertex(VB1<V> C::*p, DataActivity da=DataActivity::DYNAMIC, uint32_t stages=0)
        {
            auto cfg    = vbo_<V>(da, stages);
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

        uint32_t texture(Ref<const Texture> &p, DataActivity da=DataActivity::COMMON, uint32_t stages=0)
        {
            texture_t   cfg = tex_(da, stages);
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

        uint32_t    texture(Ref<const Texture> C::*p, DataActivity da=DataActivity::DYNAMIC, uint32_t stages=0)
        {
            texture_t   cfg = tex_(da, stages);
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

