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
        case DataActivity::EXTERNAL:
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
        case DataActivity::EXTERNAL:
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
        for(const auto & s : m_sbo){
            VkDescriptorSetLayoutBinding a{};
            a.binding           = s.first;
            a.descriptorCount   = 1;
            a.descriptorType    = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
            a.stageFlags        = s.second.config->stages & opts.shaders;
            a.pImmutableSamplers = nullptr;
            m_layoutBindings.push_back(a);
        }
        
        for(const auto& u : m_ubo){
            VkDescriptorSetLayoutBinding a{};
            a.binding           = u.first;
            a.descriptorCount   = 1;
            a.descriptorType    = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
            a.stageFlags        = u.second.config->stages & opts.shaders;
            a.pImmutableSamplers = nullptr;
            m_layoutBindings.push_back(a);
        }
        
        for(const auto& t : m_tex){
            VkDescriptorSetLayoutBinding a{};
            a.binding           = t.first;
            a.descriptorCount   = 1;
            a.descriptorType    = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
            a.stageFlags        = t.second.config->stages & opts.shaders;
            a.pImmutableSamplers = nullptr;
            m_layoutBindings.push_back(a);
        }
            //allocInfo.flags                 = VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT;

        if(m_layoutBindings.empty()){
            vizWarning << "ViData(" << hex(this) << ") no descriptor infos to create with!";
        }
        
        VqDescriptorSetLayoutCreateInfo layoutInfo;
        layoutInfo.bindingCount = m_layoutBindings.size();
        layoutInfo.pBindings    = m_layoutBindings.data();
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
        
        m_descriptors.resize(nDesc, nullptr);
        m_descriptorPool    = opts.pool;
        m_descriptorLayout  = opts.layout;
        m_dispatch.reserve(nDesc);

        VqDescriptorSetAllocateInfo allocInfo;
        allocInfo.descriptorPool        = opts.pool;
        allocInfo.descriptorSetCount    = 1;
        allocInfo.pSetLayouts           = &opts.layout;

        VkResult    res = vkAllocateDescriptorSets(m_device->device(), &allocInfo, m_descriptors.data());
        if(res != VK_SUCCESS){
            vizWarning << "Unable to allocate descriptor sets.  VkResult " << (int32_t) res;
            return false;
        }
        
        
        for(auto& itr : m_sbo){
            auto& s = itr.second;
            s.info.buffer           = nullptr;
            s.info.offset           = 0;
            s.info.range            = VK_WHOLE_SIZE;
            
            s.write.dstSet          = m_descriptors[s.dIndex];
            s.write.dstBinding      = itr.first;
            s.write.descriptorType  = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
            s.write.descriptorCount = 1;
            s.write.pBufferInfo     = &s.info;
        }
        
        for(auto& itr : m_ubo){
            auto& u = itr.second;
            u.info.buffer           = nullptr;
            u.info.offset           = 0;
            u.info.range            = VK_WHOLE_SIZE;
            
            u.write.dstSet          = m_descriptors[u.dIndex];
            u.write.dstBinding      = itr.first;
            u.write.descriptorType  = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
            u.write.descriptorCount = 1;
            u.write.pBufferInfo     = &u.info;
        }
        
        for(auto& itr : m_tex){
            auto& t = itr.second;
            t.info.sampler          = nullptr;
            t.info.imageView        = nullptr;
            t.info.imageLayout      = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
            t.write.dstSet          = m_descriptors[t.dIndex];
            t.write.dstBinding      = itr.first;
            t.write.descriptorType  = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
            t.write.descriptorCount = 1;
            t.write.pImageInfo      = &t.info;
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
                if(cfg.activity != EXTERNAL){
                    if(!cfg.fetch){
                        vizWarning << "ViData() -- index buffer without a fetch method, bad configuration.";
                    }
                    if((cfg.activity == DataActivity::DYNAMIC) && !cfg.revision){
                        vizWarning << "ViData() -- index buffer without a revision method, bad configuration.";
                    }
                }
            }
            for(auto& cfg : m_config->m_storageBuffers){
                if(cfg.activity == EXTERNAL)
                    continue;
                if(!cfg.fetch){
                    vizWarning << "ViData() -- storage buffer without a fetch method, bad configuration.";
                }
                if((cfg.activity == DYNAMIC) && !cfg.revision){
                    vizWarning << "ViData() -- storage buffer without a revision method, bad configuration.";
                }
            }
            for(auto& cfg : m_config->m_textures){
                if(cfg.activity == EXTERNAL)
                    continue;
                if(!cfg.fetch){
                    vizWarning << "ViData() -- texture without a fetch method, bad configuration.";
                }
                if((cfg.activity == DYNAMIC) && !cfg.revision){
                    vizWarning << "ViData() -- texture without a revision method, bad configuration.";
                }
            }
            for(auto& cfg : m_config->m_uniformBuffers){
                if(cfg.activity == EXTERNAL)
                    continue;
                if(!cfg.fetch){
                    vizWarning << "ViData() -- uniform buffer without a fetch method, bad configuration.";
                }
                if((cfg.activity == DYNAMIC) && !cfg.revision){
                    vizWarning << "ViData() -- uniform buffer without a revision method, bad configuration.";
                }
            }
            for(auto& cfg : m_config->m_vertexBuffers){
                if(cfg.activity == EXTERNAL)
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
            m_ibo.external  = m_ibo.config->activity == EXTERNAL;
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
            s.external  = cfg.activity == EXTERNAL;
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
            u.external  = cfg.activity == EXTERNAL;
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
            t.external  = cfg.activity == EXTERNAL;
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
            v.external  = cfg.activity == EXTERNAL;
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
            if(m_status(S::DescSets) && m_descriptorPool && !m_descriptors.empty()){
                vkFreeDescriptorSets(m_device->device(), m_descriptorPool, m_descriptors.size(), m_descriptors.data());
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
        m_layoutBindings.clear();
        m_descriptors.clear();
        m_dispatch.clear();
        m_vboBuffers.clear();
        m_vboOffsets.clear();

        m_status            = {};
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
            
        vkUpdateDescriptorSets(m_device->device(), m_dispatch.size(), m_dispatch.data(), 0, nullptr);
    }

    ViData::R      ViData::_set(BO&b, const Buffer& buf)
    {
        if(b.id == buf.id())
            return R::Success;
            
        auto vb = m_device->buffer_create(buf);
        if(!vb)
            return R::Failure;
            
            //  TODO... set vertex/index counts for managed in external buffers
            
        b.id        = buf.id();
        b.managed   = vb;
        b.bytes     = buf.memory.bytes();
        b.stride    = buf.memory.stride();
        b.count     = buf. memory.count();
        
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
            if(r == R::Updated)
                updated = true;
        }
        
        for(auto& itr : m_sbo){
            auto& s = itr.second;
            if(!s.config)
                continue;
                
            if(s.external){
                auto x = dm.storages.find(itr.first);
                if(x != dm.storages.end())
                    updated = _update_(m_descriptors[s.dIndex], x->second) || updated;
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
                auto x = dm.textures.find(itr.first);
                if(x != dm.textures.end())
                    updated = _update_(m_descriptors[t.dIndex], x->second) || updated;
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
                auto x = dm.uniforms.find(itr.first);
                if(x != dm.uniforms.end())
                    updated = _update_(m_descriptors[u.dIndex], x->second) || updated;
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
    
    uint32_t    ViData::descriptor_count() const
    {
        return (uint32_t) m_descriptors.size();
    }
    
    bool        ViData::descriptors_defined() const
    {
        return m_status(S::DescDefined);
    }

    bool    ViData::has_externals() const
    {
        return m_status(S::External);
    }

    void    ViData::set_external_storage(uint32_t i, VkDescriptorSet ds)
    {
        auto x = _sbo(i);
        if(!x || !x->external)
            return;
        m_descriptors[x->dIndex]    = ds;
    }
    
    void    ViData::set_external_texture(uint32_t i, VkDescriptorSet ds)
    {
        auto x = _tex(i);
        if(!x || !x->external)
            return;
        m_descriptors[x->dIndex]    = ds;
    }

    void    ViData::set_external_uniform(uint32_t i, VkDescriptorSet ds)
    {
        auto x = _ubo(i);
        if(!x || !x->external)
            return;
        m_descriptors[x->dIndex]    = ds;
    }

    uint32_t    ViData::storage_count() const
    {
        return m_sbo.size();
    }

    uint32_t    ViData::texture_count() const
    {
        return m_tex.size();
    }
    
    uint32_t    ViData::vertex_count() const
    {
        return m_vtxCount;
    }
    


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if 0
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool                ViData::_import_from(const RenderedSnap*sn)
    {
        bool    success = true;
        for(uint32_t i=0;i<std::min(m_index.count,(uint32_t) sn->ibos.size());++i){
            success = _import(m_index, i, m_config->m_indexBuffers[i], sn->ibos[i]) && success;
        }
        for(uint32_t i=0;i<std::min(m_storage.count,(uint32_t) sn->sbos.size());++i){
            success = _import(m_storage, i, m_config->m_storageBuffers[i], sn->sbos[i]) && success;
        }
        for(uint32_t i=0;i<std::min(m_texture.count,(uint32_t) sn->texs.size());++i){
            success = _import(m_texture, i, m_config->m_textures[i], sn->texs[i]) && success;
        }
        for(uint32_t i=0;i<std::min(m_uniform.count,(uint32_t) sn->ubos.size());++i){
            success = _import(m_uniform, i, m_config->m_uniformBuffers[i], sn->ubos[i]) && success;
        }
        for(uint32_t i=0;i<std::min(m_vertex.count,(uint32_t) sn->vbos.size());++i){
            success = _import(m_vertex, i, m_config->m_vertexBuffers[i], sn->vbos[i]) && success;
        }
        return success;
    }

    bool    ViData::_set(BB& bb, uint32_t i, const Buffer& buf)
    {
        return _set(bb, i, m_device->buffer_create(buf), buf.id());
    }

    bool    ViData::_set(BB& bb, uint32_t i, const ViBufferCPtr& x, uint64_t id)
    {
        if(!x || !x->valid()){
            vizWarning << "ViData -- unable to load buffer";
            return false;
        }
    
        bb.managed[i]   = x;
        bb.buffers[i]   = x->buffer();
        bb.sizes[i]     = x->count();   // yeah, bit reversed here in naming...
        bb.bytes[i]     = x->size();
        bb.ids[i]       = id;
        bb.modified    |= 1 << i;
        return true;
    }

    bool    ViData::_set(TB&tb, uint32_t i, const Texture& tex)
    {
        return _set(tb, i, m_device->texture_create(tex), tex.id());
    }
    
    bool    ViData::_set(TB&tb, uint32_t i, const ViTextureCPtr&x, uint64_t id)
    {
        if(!x || !x->valid()){
            vizWarning << "ViData -- unable to load texture";
            return false;
        }
        tb.managed[i]   = x;
        tb.ids[i]       = id;
        tb.views[i]     = x->image_view();
        tb.samplers[i]  = x->sampler();
        tb.extents[i]   = x->extents();
        
        return true;
    }

    static constexpr bool is_refreshed(DataActivity da)
    {
        switch(da){
        case DataActivity::COMMON:
        case DataActivity::FIXED:
            return false;
        case DataActivity::UNSURE:
        case DataActivity::DYNAMIC:
        case DataActivity::REFRESH:
        default:
            return true;
        }
    }

    bool    ViData::_update(BB& bb, uint32_t i, const Pipeline::buffer_t& cfg)
    {
        if(i >= bb.count)
            return false;
        if(!cfg.fetch)
            return false;
        if(!is_refreshed(cfg.activity))
            return true;
        if(!m_object)
            return false;

        if(cfg.activity == DataActivity::DYNAMIC){
            if(!cfg.revision)
                return false;
            uint64_t    n   = cfg.revision(m_object);
            if(n == bb.revisions[i])
                return true;
            bb.revisions[i] = n;
        }

        BufferCPtr c       = cfg.fetch(m_object);
        if(!c){
            vizWarning << "ViData -- failed to fetch the buffer";
            return false;
        }
        
        return _set(bb, i, *c);
    }

    bool    ViData::_update(BB& bb, uint32_t i, const Pipeline::buffer_t& cfg, const Buffered& buf)
    {
        if(i >= bb.count)
            return false;
        if(!is_refreshed(cfg.activity))
            return true;

        if(auto p = std::get_if<BufferCPtr>(&buf)){
            if(!*p){
                vizFirstWarning(this) << "ViData -- failed to update from a null (cbuffer) buffer";
                return false;
            }
            
            return _set(bb, i, **p);
        }
        
        if(auto p = std::get_if<ViBufferCPtr>(&buf)){
            if(!*p){
                vizFirstWarning(this) << "ViData -- failed to update from a null (vibuffer) buffer";
                return false;
            }

            return _set(bb, i, *p);
        }

            vizWarning << "ViData -- failed to update from an unspecified buffer";
        return false;
    }
    
    bool    ViData::_update(TB& tb, uint32_t i, const Pipeline::texture_t& cfg)
    {
        if(i >= tb.count)
            return false;
        if(!cfg.fetch)
            return false;
        if(!is_refreshed(cfg.activity))
            return true;
        if(!m_object)
            return false;

        if(cfg.activity == DataActivity::DYNAMIC){
            if(!cfg.revision)
                return false;
            uint64_t    n   = cfg.revision(m_object);
            if(n == tb.revisions[i])
                return true;
            tb.revisions[i] = n;
        }

        TextureCPtr c       = cfg.fetch(m_object);
        if(!c){
            vizWarning << "ViData -- failed to fetch the texture";
            return false;
        }
        
        return _set(tb, i, *c);
    }

    
    bool    ViData::_update(TB& tb, uint32_t i, const Pipeline::texture_t& cfg, const Textured& tex)
    {
        if(i >= tb.count)
            return false;
        if(!is_refreshed(cfg.activity))
            return true;

        if(auto p = std::get_if<TextureCPtr>(&tex)){
            if(!*p){
                vizWarning << "ViData -- failed to update from a null texture";
                return false;
            }
            return _set(tb, i, **p);
        }

        if(auto p = std::get_if<ViTextureCPtr>(&tex)){
            if(!*p){
                vizWarning << "ViData -- failed to update from a null texture";
                return false;
            }
            return _set(tb, i, *p);
        }

        vizWarning << "ViData -- failed to update from an unspecified texture";
        return false;
    }

    //! Update the data (second time)
    bool    ViData::_update_data(const RenderedSnap* sn)
    {
        if(m_config->is_static())
            return true;
    
        m_index.modified = m_storage.modified = m_texture.modified = m_uniform.modified = m_vertex.modified = 0;
        m_index.maxSize  = m_vertex.maxSize = 0;
        
        if(sn){
            return _update_from(sn);
        } else {
            return _update_self();
        }
    }

    bool    ViData::_update_from(const RenderedSnap* sn)
    {
        bool    success  = true;
        for(uint32_t i=0;i<m_index.count;++i){
            success = _update(m_index, i, m_config->m_indexBuffers[i], sn->ibos[i]) && success;
            m_index.maxSize = std::max(m_index.maxSize, m_index.sizes[i]);
        }
        for(uint32_t i=0;i<m_storage.count;++i){
            success = _update(m_storage, i, m_config->m_storageBuffers[i], sn->sbos[i]) && success;
        }
        for(uint32_t i=0;i<m_texture.count;++i){
            success = _update(m_texture, i, m_config->m_textures[i], sn->texs[i]) && success;
        }
        for(uint32_t i=0;i<m_uniform.count;++i){
            success = _update(m_uniform, i, m_config->m_uniformBuffers[i], sn->ubos[i]) && success;
        }
        for(uint32_t i=0;i<m_vertex.count;++i){
            success = _update(m_vertex, i, m_config->m_vertexBuffers[i], sn->vbos[i]) && success;
            m_vertex.maxSize = std::max(m_vertex.maxSize, m_vertex.sizes[i]);
        }
        return success;
    }

    bool    ViData::_update_self()
    {
        bool    success  = true;
        for(uint32_t i=0;i<m_index.count;++i){
            success = _update(m_index, i, m_config->m_indexBuffers[i]) && success;
            m_index.maxSize = std::max(m_index.maxSize, m_index.sizes[i]);
        }
        for(uint32_t i=0;i<m_storage.count;++i){
            success = _update(m_storage, i, m_config->m_storageBuffers[i]) && success;
        }
        for(uint32_t i=0;i<m_texture.count;++i){
            success = _update(m_texture, i, m_config->m_textures[i]) && success;
        }
        for(uint32_t i=0;i<m_uniform.count;++i){
            success = _update(m_uniform, i, m_config->m_uniformBuffers[i]) && success;
        }
        for(uint32_t i=0;i<m_vertex.count;++i){
            success = _update(m_vertex, i, m_config->m_vertexBuffers[i]) && success;
            m_vertex.maxSize = std::max(m_vertex.maxSize, m_vertex.sizes[i]);
        }
        return success;
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    uint32_t    ViData::buffer_count() const
    {
        return (uint32_t) m_buffers.size();
    }

    VkBuffer    ViData::index_buffer(size_t i) const
    {
        if((i>=m_index.count) || !m_index.buffers)
            return nullptr;
        return m_index.buffers[i];
    }
    
    uint32_t    ViData::index_bytes() const
    {
        if(!(m_index.bytes && m_index.count))
            return 0;
            
        uint32_t ret = 0;
        for(uint32_t i=0;i<m_index.count;++i)
            ret += m_index.bytes[i];
        return ret;
    }
    
    uint32_t    ViData::index_bytes(size_t i) const
    {
        if((i>=m_index.count) || !m_index.bytes)
            return 0;

        return m_index.bytes[i];
    }

    uint32_t    ViData::index_count() const
    {
        return m_index.count;
    }
    
    uint32_t    ViData::index_max_size() const
    {
        return m_index.maxSize;
    }

    VkBuffer    ViData::storage_buffer(size_t i) const
    {
        if((i>=m_storage.count) || !m_storage.buffers)
            return nullptr;
        return m_storage.buffers[i];
    }
    
    uint32_t    ViData::storage_bytes() const
    {
        if(!(m_storage.count && m_storage.bytes))
            return 0;
            
        uint32_t ret = 0;
        for(uint32_t i=0; i<m_storage.count; ++i)
            ret += m_storage.bytes[i];
        return ret;
    }
    
    uint32_t    ViData::storage_bytes(size_t i) const
    {
        if((i >= m_storage.count) || !m_storage.bytes)
            return 0;
        return m_storage.bytes[i];
    }
    VkImageView ViData::texture_image_view(size_t i) const
    {
        if((i>=m_texture.count) || !m_texture.views)
            return nullptr;
        return m_texture.views[i];
    }
    
    VkSampler   ViData::texture_sampler(size_t i) const
    {
        if((i>=m_texture.count) || !m_texture.samplers)
            return nullptr;
        return m_texture.samplers[i];
    }
    
    VkBuffer    ViData::uniform_buffer(size_t i) const
    {
        if((i>=m_uniform.count) || !m_uniform.buffers)
            return nullptr;
        return m_uniform.buffers[i];
    }
    
    uint32_t    ViData::uniform_bytes() const
    {
        if(!(m_uniform.count && m_uniform.bytes))
            return 0;
            
        uint32_t ret = 0;
        for(uint32_t i=0; i<m_uniform.count; ++i)
            ret += m_uniform.bytes[i];
        return ret;
    }
    
    uint32_t    ViData::uniform_bytes(size_t i) const
    {
        if((i >= m_uniform.count) || !m_uniform.bytes)
            return 0;
        return m_uniform.bytes[i];
    }
    
    uint32_t    ViData::uniform_count() const
    {
        return m_uniform.count;
    }
    
    VkBuffer    ViData::vertex_buffer(size_t i) const
    {
        if((i>=m_vertex.count) || !m_vertex.buffers)
            return nullptr;
        return m_vertex.buffers[i];
    }
    
    uint32_t    ViData::vertex_bytes() const
    {
        if(!(m_vertex.count && m_vertex.bytes))
            return 0;
            
        uint32_t ret = 0;
        for(uint32_t i=0; i<m_vertex.count; ++i)
            ret += m_vertex.bytes[i];
        return ret;
    }
    
    uint32_t    ViData::vertex_bytes(size_t i) const
    {
        if((i >= m_vertex.count) || !m_vertex.bytes)
            return 0;
        return m_vertex.bytes[i];
    }
    
    uint32_t    ViData::vertex_max_size() const
    {
        return m_vertex.maxSize;
    }
#endif
}
