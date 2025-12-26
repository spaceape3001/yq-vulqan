////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/vulkan/ViData.hpp>

#include <yq/tachyon/errors.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/pipeline/Buffer.hpp>
#include <yq/tachyon/asset/Texture.hpp>
#include <yq/tachyon/api/RenderedData.hpp>
#include <yq/tachyon/vulkan/VqStructs.hpp>
#include <yq/tachyon/vulkan/ViBuffer.hpp>
#include <yq/tachyon/vulkan/ViDevice.hpp>
#include <yq/tachyon/vulkan/ViImage.hpp>
#include <yq/tachyon/vulkan/ViLogging.hpp>
#include <yq/tachyon/vulkan/ViTexture.hpp>
#include <yq/tachyon/vulkan/ViVisualizer.hpp>

#include <yq/text/format.hpp>

namespace yq::tachyon {

    //! TRUE if this needs a pointer
    static constexpr bool needs_pointer(DataActivity da)
    {
        switch(da){
        case DataActivity::UNSURE:
        case DataActivity::FIXED:
        case DataActivity::DYNAMIC:
        case DataActivity::REFRESH:
            return true;
        case DataActivity::STATIC:
        case DataActivity::COMMON:
        default:
            return false;
        }
    }
    
    static constexpr bool is_updater(DataActivity da)
    {
        switch(da){
        case DataActivity::UNSURE:
        case DataActivity::DYNAMIC:
        case DataActivity::REFRESH:
        case DataActivity::COMMON:
            return true;
        case DataActivity::FIXED:
        case DataActivity::STATIC:
        default:
            return false;
        }
    }


    ViData::BO::BO() = default;
    ViData::BO::~BO() = default;

    ViData::IBO::IBO() = default;
    ViData::IBO::~IBO() = default;

    ViData::SBO::SBO() = default;
    ViData::SBO::~SBO() = default;

    ViData::TO::TO() = default;
    ViData::TO::~TO() = default;

    ViData::UBO::UBO() = default;
    ViData::UBO::~UBO() = default;

    ViData::VBO::VBO() = default;
    ViData::VBO::~VBO() = default;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ViData::ViData()
    {
    }
    
    ViData::~ViData()
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ViData::SBO*        ViData::_sbo(uint32_t i)
    {
        auto x = m_sbo.find(i);
        if(x == m_sbo.end())
            return nullptr;
        return &x->second;
    }
    
    const ViData::SBO*  ViData::_sbo(uint32_t i) const
    {
        auto x = m_sbo.find(i);
        if(x == m_sbo.end())
            return nullptr;
        return &x->second;
    }

    ViData::TO*         ViData::_tex(uint32_t i)
    {
        auto x = m_tex.find(i);
        if(x == m_tex.end())
            return nullptr;
        return &x->second;
    }

    const ViData::TO*   ViData::_tex(uint32_t i) const
    {
        auto x = m_tex.find(i);
        if(x == m_tex.end())
            return nullptr;
        return &x->second;
    }

    ViData::UBO*        ViData::_ubo(uint32_t i)   
    {
        auto x = m_ubo.find(i);
        if(x == m_ubo.end())
            return nullptr;
        return &x->second;
    }

    const ViData::UBO*  ViData::_ubo(uint32_t i) const
    {
        auto x = m_ubo.find(i);
        if(x == m_ubo.end())
            return nullptr;
        return &x->second;
    }

    ViData::VBO*        ViData::_vbo(uint32_t i)
    {
        auto x = m_vbo.find(i);
        if(x == m_vbo.end())
            return nullptr;
        return &x->second;
    }

    const ViData::VBO*  ViData::_vbo(uint32_t i) const
    {
        auto x = m_vbo.find(i);
        if(x == m_vbo.end())
            return nullptr;
        return &x->second;
    }



    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool    ViData::_create_descriptor_layout(const ViDataOptions& opts)
    {
        std::vector<VkDescriptorSetLayoutBinding>   bindings;
        
        for(const auto & s : m_sbo){
            VkDescriptorSetLayoutBinding a{};
            a.binding           = s.first;
            a.descriptorCount   = 1;
            a.descriptorType    = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
            a.stageFlags        = s.second.config->stages & opts.shaders;
            a.pImmutableSamplers = nullptr;
            bindings.push_back(a);
        }
        
        for(const auto& t : m_tex){
            VkDescriptorSetLayoutBinding a{};
            a.binding           = t.first;
            a.descriptorCount   = 1;
            a.descriptorType    = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
            a.stageFlags        = t.second.config->stages & opts.shaders;
            a.pImmutableSamplers = nullptr;
            bindings.push_back(a);
        }
            //allocInfo.flags                 = VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT;

        for(const auto& u : m_ubo){
            VkDescriptorSetLayoutBinding a{};
            a.binding           = u.first;
            a.descriptorCount   = 1;
            a.descriptorType    = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
            a.stageFlags        = u.second.config->stages & opts.shaders;
            a.pImmutableSamplers = nullptr;
            bindings.push_back(a);
        }
        

        if(bindings.empty()){
            vizWarning << "ViData(" << hex(this) << ") no descriptor infos to create with!";
        }
        
        VqDescriptorSetLayoutCreateInfo layoutInfo;
        layoutInfo.bindingCount = bindings.size();
        layoutInfo.pBindings    = bindings.data();
        layoutInfo.flags        = 0;
        VkResult    res = vkCreateDescriptorSetLayout(m_device->device(), &layoutInfo, nullptr, &m_descriptorLayout);
        if(res != VK_SUCCESS){
            vizWarning << "Unable to create a descriptor set layout.  VkResult " << (int32_t) res;
            return false;
        }
        
        m_status |= S::DescLayout;
        return true;
    }
    
    bool    ViData::_create_descriptor_sets(const ViDataOptions& opts)
    {
        if(m_sbo.empty() && m_tex.empty() && m_ubo.empty())
            return true;
            
        uint32_t        nDesc   = (m_sbo.size() + m_tex.size() + m_ubo.size());
        if(!nDesc)
            return true;

        if(!opts.pool){
            vizWarning << "ViData(): Unable to allocate descriptor sets without a descriptor pool";
            return false;
        }
        
        if(!opts.layout){
            vizWarning << "Unable to allocate descriptors sets without a layout";
            return false;
        }
        
        m_descriptorPool    = opts.pool;
        m_descriptorLayout  = opts.layout;
        m_dispatch.reserve(nDesc);

        //std::vector<VkDescriptorSetLayout>  layouts(nDesc, opts.layout);

        VqDescriptorSetAllocateInfo allocInfo;
        allocInfo.descriptorPool        = m_descriptorPool;
        allocInfo.descriptorSetCount    = 1;
        allocInfo.pSetLayouts           = &m_descriptorLayout;

        VkResult    res = vkAllocateDescriptorSets(m_device->device(), &allocInfo, &m_descriptor);
        if(res != VK_SUCCESS){
            vizWarning << "Unable to allocate descriptor sets.  VkResult " << (int32_t) res;
            return false;
        }
        
        for(auto& itr : m_sbo){
            auto& s = itr.second;
            s.info.buffer           = nullptr;
            s.info.offset           = 0;
            s.info.range            = VK_WHOLE_SIZE;
            
            s.write.dstSet          = m_descriptor;
            s.write.dstBinding      = itr.first;
            s.write.descriptorType  = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
            s.write.descriptorCount = 1;
            s.write.pBufferInfo     = &s.info;
        }
        
        for(auto& itr : m_tex){
            auto& t = itr.second;
            t.info.sampler          = nullptr;
            t.info.imageView        = nullptr;
            t.info.imageLayout      = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
            t.write.dstSet          = m_descriptor;
            t.write.dstBinding      = itr.first;
            t.write.descriptorType  = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
            t.write.descriptorCount = 1;
            t.write.pImageInfo      = &t.info;
        }

        for(auto& itr : m_ubo){
            auto& u = itr.second;
            u.info.buffer           = nullptr;
            u.info.offset           = 0;
            u.info.range            = VK_WHOLE_SIZE;
            
            u.write.dstSet          = m_descriptor;
            u.write.dstBinding      = itr.first;
            u.write.descriptorType  = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
            u.write.descriptorCount = 1;
            u.write.pBufferInfo     = &u.info;
        }
        

        m_status |= S::DescSets;
        return true;
    }

    bool    ViData::_descriptors(const ViDataOptions&opts)
    {
        if(m_sbo.empty() && m_tex.empty() && m_ubo.empty())
            return true;

        m_status |= S::DescDefined;
        if(std::get_if<layout_k>(&opts.descriptors)){
            return _create_descriptor_layout(opts);
        } else if(std::get_if<allocate_k>(&opts.descriptors)){
            return _create_descriptor_sets(opts);
        } else {
            return true;
        }
    }

    std::error_code     ViData::_init_data(ViDevice&viz, const Pipeline* pipe, const ViDataOptions& opts)
    {
        m_device            = &viz;
        m_config            = pipe;
        m_object            = opts.object;
        if(opts.flags(ViDataOptions::F::StaticLayout)){
            m_status |= S::Static;
        } else {
            m_status |= S::Dynamic;
        }
        
        if(!m_config){
            vizWarning << "ViData() -- unable to create data structure to a NULL pipeline configuration.";
            return errors::data_cant_initialize();
        }

        //  some preliminary checks...
        if(m_config->is_dynamic()){
            if(m_config->m_indexBuffer){
                const auto& cfg = *m_config->m_indexBuffer;
                if(!cfg.external){
                    if(!cfg.fetch){
                        vizWarning << "ViData() -- index buffer without a fetch method, bad configuration.";
                    }
                    if((cfg.activity == DataActivity::DYNAMIC) && !cfg.revision){
                        vizWarning << "ViData() -- index buffer without a revision method, bad configuration.";
                    }
                }
            }
            for(auto& cfg : m_config->m_storageBuffers){
                if(cfg.external)
                    continue;
                if(!cfg.fetch){
                    vizWarning << "ViData() -- storage buffer without a fetch method, bad configuration.";
                }
                if((cfg.activity == DYNAMIC) && !cfg.revision){
                    vizWarning << "ViData() -- storage buffer without a revision method, bad configuration.";
                }
            }
            for(auto& cfg : m_config->m_textures){
                if(cfg.external)
                    continue;
                if(!cfg.fetch){
                    vizWarning << "ViData() -- texture without a fetch method, bad configuration.";
                }
                if((cfg.activity == DYNAMIC) && !cfg.revision){
                    vizWarning << "ViData() -- texture without a revision method, bad configuration.";
                }
            }
            for(auto& cfg : m_config->m_uniformBuffers){
                if(cfg.external)
                    continue;
                if(!cfg.fetch){
                    vizWarning << "ViData() -- uniform buffer without a fetch method, bad configuration.";
                }
                if((cfg.activity == DYNAMIC) && !cfg.revision){
                    vizWarning << "ViData() -- uniform buffer without a revision method, bad configuration.";
                }
            }
            for(auto& cfg : m_config->m_vertexBuffers){
                if(cfg.external)
                    continue;
                if(!cfg.fetch){
                    vizWarning << "ViData() -- vertex buffer without a fetch method, bad configuration.";
                }
                if((cfg.activity == DYNAMIC) && !cfg.revision){
                    vizWarning << "ViData() -- vertex buffer without a revision method, bad configuration.";
                }
            }
        }
        
        uint32_t    dscnt   = 0;
        uint32_t    vbcnt   = 0;
        if(m_config->m_indexBuffer){
            m_ibo.config    = &*m_config->m_indexBuffer;
            m_ibo.external  = m_ibo.config->external;
            m_ibo.index     = 0;
            m_ibo.type      = (VkIndexType) m_ibo.config->type.value();
            switch(m_ibo.type){
            case VK_INDEX_TYPE_UINT8:
                m_ibo.stride    = sizeof(uint8_t);
                break;
            case VK_INDEX_TYPE_UINT16:
                m_ibo.stride    = sizeof(uint16_t);
                break;
            case VK_INDEX_TYPE_UINT32:
            default:
                m_ibo.stride    = sizeof(uint32_t);
                break;
            }
        }
        
        int32_t     n   = -1;
        for(auto& cfg : m_config->m_storageBuffers){
            ++n;
            auto& s = m_sbo[cfg.binding];
            if(s.config){
                vizWarning << "VizData() -- storage buffer duplicate binding " << cfg.binding;
                continue;
            }
            
            s.index     = n;
            s.config    = &cfg;
            s.external  = cfg.external;
            s.dIndex    = dscnt++;
            s.stride    = cfg.size;
            s.count     = cfg.count;
        }
        
        n   = -1;
        for(auto& cfg : m_config->m_uniformBuffers){
            ++n;
            auto& u = m_ubo[cfg.binding];
            if(u.config){
                vizWarning << "VizData() -- uniform buffer duplicate binding " << cfg.binding;
                continue;
            }
            u.index     = n;
            u.config    = &cfg;
            u.external  = cfg.external;
            u.dIndex    = dscnt++;
            u.stride    = cfg.size;
            u.count     = cfg.count;
        }
        
        n   = -1;
        for(auto& cfg : m_config->m_textures){
            ++n;
            auto& t = m_tex[cfg.binding];
            if(t.config){
                vizWarning << "VizData() -- texture duplicate binding " << cfg.binding;
                continue;
            }
            t.index     = n;
            t.config    = &cfg;
            t.external  = cfg.external;
            t.dIndex    = dscnt++;
        }
        
        n = -1;
        for(auto& cfg : m_config->m_vertexBuffers){
            ++n;
            auto& v = m_vbo[cfg.binding];
            if(v.config){
                vizWarning << "VizData() -- vertex duplicate binding " << cfg.binding;
                continue;
            }
            v.config    = &cfg;
            v.external  = cfg.external;
            v.vIndex    = vbcnt++;
            v.stride    = cfg.stride;
            v.count     = 0;
        }
        
        if(vbcnt){
            m_vboBuffers.resize(vbcnt, nullptr);
            m_vboOffsets.resize(vbcnt, 0);
        }
        
        if(dscnt){
            if(!_descriptors(opts))
                return errors::data_cant_initialize();
        }
        
        return {};
    }
    
    std::error_code     ViData::_init_data(const ViData& vi, const ViDataOptions& opts)
    {
        m_device            = vi.m_device;
        m_config            = vi.m_config;
        m_object            = opts.object;
        if(m_object || opts.snap){
            m_status |= S::Dynamic;
        } else {
            m_status |= S::Static;
        }

        if(!m_config){
            vizWarning << "Unable to create data structure to a NULL pipeline configuration.";
            return errors::data_cant_initialize();
        }
        
        m_push              = vi.m_push;
        m_ibo               = vi.m_ibo;
        m_sbo               = vi.m_sbo;
        m_tex               = vi.m_tex;
        m_ubo               = vi.m_ubo;
        m_vbo               = vi.m_vbo;
        m_vboBuffers        = vi.m_vboBuffers;
        m_vboOffsets        = vi.m_vboOffsets;
        m_vtxCount          = vi.m_vtxCount;
        

        if(!_descriptors(opts))
            return errors::data_cant_initialize();

        return {};
    }
    
    void    ViData::_kill_data()
    {
        if(m_device && m_device->device()){
            if(m_status(S::DescSets) && m_descriptorPool && m_descriptor){
                vkFreeDescriptorSets(m_device->device(), m_descriptorPool, 1, &m_descriptor);
            }
            if(m_status(S::DescLayout) && m_descriptorLayout){
                vkDestroyDescriptorSetLayout(m_device->device(), m_descriptorLayout, nullptr);
            }
        }
        
        m_ibo       = {};
        m_sbo.clear();
        m_tex.clear();
        m_ubo.clear();
        m_vbo.clear();
        m_dispatch.clear();
        m_vboBuffers.clear();
        m_vboOffsets.clear();

        m_status            = {};
        m_descriptor        = nullptr;
        m_descriptorPool    = nullptr;
        m_descriptorLayout  = nullptr;
        m_object            = nullptr;
    }
    
    void    ViData::_publish_data(bool all)
    {
        if(!m_status(S::DescDefined))
            return ;
            
        if(all){
            m_dispatch.clear();
            for(auto& itr : m_sbo)
                m_dispatch.push_back(itr.second.write);
            for(auto& itr : m_ubo)
                m_dispatch.push_back(itr.second.write);
            for(auto& itr : m_tex)
                m_dispatch.push_back(itr.second.write);
        }
        
        if(m_dispatch.empty())
            return ;
        
        #ifdef _DEBUG
        for(auto& itr : m_dispatch){
            if(!itr.dstSet){
                tachyonFirstCritical(this) << "Descriptor is NULL!  on pipeline role=" << fmt_hex(m_config -> key());
                return ;
            }
        }
        #endif
            
        vkUpdateDescriptorSets(m_device->device(), m_dispatch.size(), m_dispatch.data(), 0, nullptr);
    }

    ViData::R      ViData::_set(BO&b, const Buffer& buf)
    {
        if(b.id == buf.id())
            return R::Success;
            
        auto vb = m_device->buffer_create(buf);
        if(!vb)
            return R::Failure;
            
        b.id        = buf.id();
        b.managed   = vb;
        b.bytes     = buf.memory.bytes();
        b.stride    = buf.memory.stride();
        b.count     = buf.memory.count();
        return R::Updated;
    }
    
    ViData::R      ViData::_set(TO&t, const Texture& tex)
    {
        if(tex.id() == t.id)
            return R::Success;
            
        auto vt         = m_device->texture_create(tex);
        if(!vt)
            return R::Failure;
        
        return _set(t, vt, tex.id());
    }
    
    ViData::R      ViData::_set(BO&b, const ViBufferCPtr&buf, uint64_t id)
    {
        b.id        = id;
        b.managed   = buf;
        b.bytes     = buf -> size();
        b.count     = b.bytes / b.stride;
        return R::Updated;
    }
    
    ViData::R      ViData::_set(TO&t, const ViTextureCPtr&tex, uint64_t id)
    {
        t.id            = id;
        t.managed       = tex;
        t.extents       = tex->extents();
        return R::Updated;
    }

    ViData::R       ViData::_update(BO& bo, const Buffered&buf)
    {
        if(auto p = std::get_if<BufferCPtr>(&buf)){
            if(!*p){
                vizWarning << "ViData -- failed to provide the buffer";
                return R::Failure;
            }
            
            return _set(bo, **p);
        }
        
        if(auto p = std::get_if<ViBufferCPtr>(&buf)){
            if(!*p){
                vizWarning << "ViData -- failed to provide the buffer";
                return R::Failure;
            }
            return _set(bo, *p);
        }
 
 
        vizWarning << "ViData -- failed to provide the buffer";
        return R::Failure;
    }
    
    ViData::R       ViData::_update(TO& to, const Textured& tex)
    {
        if(auto p = std::get_if<TextureCPtr>(&tex)){
            if(!*p){
                vizWarning << "ViData -- failed to provide the texture";
                return R::Failure;
            }
            
            return _set(to, **p);
        }
        
        if(auto p = std::get_if<ViTextureCPtr>(&tex)){
            if(!*p){
                vizWarning << "ViData -- failed to provide the texture";
                return R::Failure;
            }
            return _set(to, *p);
        }
 
        vizWarning << "ViData -- failed to provide the texture";
        return R::Failure;
    }

    template <typename T>
    bool        _update_(T& cur, T n)
    {
        if(cur == n)
            return false;
        cur    = n;
        return true;
    }

    ViData::R    ViData::_update_data(const RenderedSnap* sn, const ViDataMap& dm)
    {
        /*
            Conceptually straight forward, though a PITA to split up, thus,
            the longer stride here...
        */
    
        bool    updated = false;
        
        if(m_ibo.config && !m_ibo.external){
            R   r   = _update(m_ibo, sn ? sn->ibo : Buffered());
            if(r == R::Failure)
                return R::Failure;
            if((r == R::Updated) && m_ibo.managed){
                m_ibo.buffer    = m_ibo.managed->buffer();
                updated = true;
            }
        }
        
        for(auto& itr : m_sbo){
            auto& s = itr.second;
            if(!s.config)
                continue;
                
            if(s.external){
            #if 0
                auto x = dm.storages.find(itr.first);
                if(x != dm.storages.end())
                    updated = _update_(m_descriptors[s.dIndex], x->second) || updated;
            #endif
                continue;
            }

            switch(_update(s, sn ? sn->sbos[s.index] : Buffered())){
            case R::Updated:
                if(s.managed){
                    s.info.buffer = s.managed->buffer();
                    s.info.offset = 0;
                    s.info.range  = s.managed->size();
                    updated = true;
                    m_dispatch.push_back(s.write);
                }
                break;
            case R::Success:
                break;
            case R::Failure:
            default:
                return R::Failure;
            }
        }
        
        for(auto& itr : m_tex){
            auto& t = itr.second;
            if(!t.config)
                continue;
            if(t.external){
            #if 0
                auto x = dm.textures.find(itr.first);
                if(x != dm.textures.end())
                    updated = _update_(m_descriptors[t.dIndex], x->second) || updated;
            #endif
                continue;
            }

            switch(_update(t, sn ? sn->texs[t.index] : Textured())){
            case R::Updated:
                if(t.managed){
                    t.info.sampler      = t.managed->sampler();
                    t.info.imageView    = t.managed->image_view();
                    m_dispatch.push_back(t.write);
                    updated = true;
                }
                break;
            case R::Success:
                break;
            case R::Failure:
            default:
                return R::Failure;
            }
        }
        for(auto& itr : m_ubo){
            auto& u = itr.second;
            if(!u.config)
                continue;
            if(u.external){
                #if 0
                auto x = dm.uniforms.find(itr.first);
                if(x != dm.uniforms.end())
                    updated = _update_(m_descriptors[u.dIndex], x->second) || updated;
                #endif
                continue;
            }
                
            switch(_update(u, sn ? sn->ubos[u.index] : Buffered())){
            case R::Updated:
                if(u.managed){
                    u.info.buffer = u.managed->buffer();
                    u.info.offset = 0;
                    u.info.range  = u.managed->size();
                    updated = true;
                    m_dispatch.push_back(u.write);
                }
                break;
            case R::Success:
                break;
            case R::Failure:
            default:
                return R::Failure;
            }
        }
        
        m_vtxCount      = 0;
        for(auto& itr : m_vbo){
            auto& v = itr.second;
            if(!v.config)
                continue;
                
            if(v.external){
                auto x = dm.vertices.find(itr.first);
                if(x != dm.vertices.end())
                    updated = _update_(m_vboBuffers[v.vIndex], x->second);
                continue;
            }

            switch(_update(v, sn ? sn->vbos[v.index] : Buffered())){
            case R::Updated:
                if(v.managed){
                    m_vboBuffers[v.vIndex]   = v.managed->buffer();
                    updated    = true;
                }
                break;
            case R::Success:
                break;
            case R::Failure:
            default:
                return R::Failure;
            }
            
            m_vtxCount   = std::max(m_vtxCount, v.count);
        }

        return updated ? R::Updated : R::Success;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    bool        ViData::descriptors_defined() const
    {
        return m_status(S::DescDefined);
    }

    bool    ViData::has_externals() const
    {
        return m_status(S::External);
    }

    uint32_t    ViData::storage_count() const
    {
        return m_sbo.size();
    }

    uint32_t    ViData::texture_count() const
    {
        return m_tex.size();
    }
    
    uint32_t    ViData::uniform_count() const
    {
        return m_ubo.size();
    }

    uint32_t    ViData::vertex_count() const
    {
        return m_vtxCount;
    }
    
}
