////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViData.hpp"

#include <yq-vulqan/errors.hpp>
#include <yq-vulqan/logging.hpp>
#include <yq-vulqan/memory/Buffer.hpp>
#include <yq-vulqan/pipeline/PipelineConfig.hpp>
#include <yq-vulqan/texture/Texture.hpp>
#include <yq-vulqan/v/VqStructs.hpp>
#include <yq-vulqan/viz/ViBuffer.hpp>
#include <yq-vulqan/viz/ViTexture.hpp>
#include <yq-vulqan/viz/ViVisualizer.hpp>

namespace yq::tachyon {

    void    ViData::BB::import_stats(const BB& bb)
    {
        count       = bb.count;
        buf0        = bb.buf0;
        data0       = bb.data0;
        desc0       = bb.desc0;
        maxSize     = bb.maxSize;
    }

    void    ViData::TB::import_stats(const TB& tb)
    {
        count       = tb.count;
        data0       = tb.data0;
        desc0       = tb.desc0;
        tex0        = tb.tex0;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ViData::ViData()
    {
    }
    
    ViData::~ViData()
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void    ViData::_carve_buffer(BB&bb)
    {
        if(bb.count){
            bb.buffers  = &m_buffers[bb.buf0];
            bb.bytes    = &m_bytes[bb.buf0];
            bb.managed  = &m_bufferPtrs[bb.buf0];
            bb.offsets  = &m_offsets[bb.buf0];
            bb.pointers = &m_pointers[bb.buf0];
            bb.sizes    = &m_sizes[bb.buf0];
        }
    }
    
    void    ViData::_carve_data(BB&bb)
    {
        if(bb.count){
            bb.ids          = &m_ids[bb.data0];
            bb.revisions    = &m_revisions[bb.data0];
        }
    }
    
    void    ViData::_carve_data(TB&tb)
    {
        if(tb.count){
            tb.ids          = &m_ids[tb.data0];
            tb.revisions    = &m_revisions[tb.data0];
        }
    }

    void    ViData::_carve_descriptor(BB&bb)
    {
        if(bb.count){
            bb.descriptors  = &m_descriptors[bb.desc0];
            bb.writes       = &m_writes[bb.desc0];
            bb.infos        = &m_bufferInfos[bb.desc0];
        }
    }
    
    void    ViData::_carve_descriptor(TB&tb)
    {
        if(tb.count){
            tb.descriptors  = &m_descriptors[tb.desc0];
            tb.writes       = &m_writes[tb.desc0];
            tb.infos        = &m_imageInfos[0];
        }
    }

    void    ViData::_carve_texture(TB&tb)
    {
        if(tb.count){
            tb.views        = &m_imageViews[tb.tex0];
            tb.samplers     = &m_samplers[tb.tex0];
            tb.managed      = &m_texturePtrs[tb.tex0];
        }
    }

    bool    ViData::_create_descriptor_sets(const Options& opts)
    {
        uint32_t        nDesc   = m_texture.end_desc();
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
        
        m_writes.resize(nDesc, VqWriteDescriptorSet());
        m_dispatch.reserve(nDesc);
        
        if(m_storage.count || m_uniform.count){
            VkDescriptorBufferInfo  bufInfo {
                .buffer = nullptr,
                .offset = 0,
                .range  = VK_WHOLE_SIZE
            };
            
            m_bufferInfos.resize(m_uniform.end_desc(), bufInfo);
        }
        
        if(m_texture.count){
            VkDescriptorImageInfo   imgInfo {
                .imageLayout        = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL
            };
            m_imageInfos.resize(m_texture.count, imgInfo);
        }
        

        std::vector<VkDescriptorSetLayout>  layouts(nDesc, opts.layout);
    
        VqDescriptorSetAllocateInfo allocInfo;
        allocInfo.descriptorPool        = opts.pool;
        allocInfo.descriptorSetCount    = nDesc;
        allocInfo.pSetLayouts           = layouts.data();
        VkResult    res = vkAllocateDescriptorSets(m_viz->device(), &allocInfo, m_descriptors.data());
        if(res != VK_SUCCESS){
            vizWarning << "Unable to allocate descriptor sets.  VkResult " << (int32_t) res;
            return false;
        }
        
        _carve_descriptor(m_storage);
        _carve_descriptor(m_texture);
        _carve_descriptor(m_uniform);
        
        //  Pre-create/define the image/buffer descriptor informations (will make updating easier)
        
        for(uint32_t i=0;i<m_storage.count;++i){
            auto& w             = m_storage.writes[i];
            w.dstSet            = m_storage.descriptors[i];
            w.dstBinding        = i;
            w.descriptorType    = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
            w.descriptorCount   = 1;
            w.pBufferInfo       = &m_storage.infos[i];
        }
        
        for(uint32_t i=0;i<m_uniform.count;++i){
            auto& w             = m_uniform.writes[i];
            w.dstSet            = m_uniform.descriptors[i];
            w.dstBinding        = i;
            w.descriptorType    = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
            w.descriptorCount   = 1;
            w.pBufferInfo       = &m_uniform.infos[i];
        }

        for(uint32_t i=0;i<m_texture.count;++i){
            auto& w             = m_texture.writes[i];
            w.dstSet            = m_texture.descriptors[i];
            w.dstBinding        = i;
            w.descriptorType    = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
            w.descriptorCount   = 1;
            w.pImageInfo        = &m_texture.infos[i];
        }


        m_status |= S::DescSets;
        return true;
    }
    
    bool    ViData::_create_descriptor_layout(const Options& opts)
    {
        uint32_t        nDesc   = m_uniform.end_desc();
        if(!nDesc)
            return true;
            
        if(!opts.shaders){
            vizWarning << "Creating a descriptor layout without binding into any shader stages... you sure?";
        }

        std::vector<VkDescriptorSetLayoutBinding>   desc;
        uint32_t        binding = 0;
        for(const UBOConfig& cfg : m_config->ubos){
            VkDescriptorSetLayoutBinding a{};
            a.binding           = binding++;
            a.descriptorCount   = 1;
            a.descriptorType    = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
            if(cfg.shaders){
                a.stageFlags    = cfg.shaders;
            } else {
                a.stageFlags    = opts.shaders;
            }
            desc.push_back(a);
        }
        
        for(const TexConfig& cfg : m_config->texs){
            VkDescriptorSetLayoutBinding a{};
            a.binding           = binding++;
            a.descriptorCount   = 1;
            a.descriptorType    = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
            if(cfg.shaders){
                a.stageFlags    = cfg.shaders;
            } else {
                a.stageFlags    = opts.shaders;
            }
            desc.push_back(a);
        }

        for(const SBOConfig& cfg : m_config->sbos){
            VkDescriptorSetLayoutBinding a{};
            a.binding           = binding++;
            a.descriptorCount   = 1;
            a.descriptorType    = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
            if(cfg.shaders){
                a.stageFlags    = cfg.shaders;
            } else {
                a.stageFlags    = opts.shaders;
            }
            desc.push_back(a);
        }

            //allocInfo.flags                 = VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT;
        
        VqDescriptorSetLayoutCreateInfo layoutInfo;
        layoutInfo.bindingCount = desc.size();
        layoutInfo.pBindings    = desc.data();
        VkResult    res = vkCreateDescriptorSetLayout(m_viz->device(), &layoutInfo, nullptr, &m_descriptorLayout);
        if(res != VK_SUCCESS){
            vizWarning << "Unable to create a descriptor set layout.  VkResult " << (int32_t) res;
            return false;
        }
        
        m_status |= S::DescLayout;
        return true;
    }

    bool    ViData::_descriptors(const Options&opts)
    {
        // this order matters in the allocation step...
        m_storage.desc0     = 0;
        m_uniform.desc0     = m_storage.end_data();
        m_texture.desc0     = m_uniform.end_data();

        if(std::get_if<layout_t>(&opts.descriptors)){
            return _create_descriptor_layout(opts);
        } else if(std::get_if<allocate_t>(&opts.descriptors)){
            return _create_descriptor_sets(opts);
        } else {
            return true;
        }
    }

#if 0
    void    ViData::_import_options(const ViDataOptions&opts)
    {
        m_descriptorPool    = opts.descriptor_pool;
        if(m_desciptorPool)
            m_flags |= F::Descriptors;
        m_object            = opts.object;
        if(!m_object)
            m_flags |= F::Static;
    }
#endif

    //! TRUE if this needs a pointer
    static constexpr bool needs_pointer(DataActivity da)
    {
        switch(da){
        case DataActivity::UNSURE:
        case DataActivity::FIXED:
        case DataActivity::DYNAMIC:
        case DataActivity::REFRESH:
            return true;
        case DataActivity::COMMON:
        default:
            return false;
        }
    }
    

    bool    ViData::_import(BB&bb, uint32_t i, const BaseBOConfig& cfg)
    {
        if(i >= bb.count)
            return false;
        if(!cfg.fetch)
            return false;

        const void* ptr = nullptr;
        if(needs_pointer(cfg.activity)){
            if(!m_object){
                vizWarning << "ViData -- trying to fetch with a null pointer object";
                return false;
            }
            ptr = m_object;
        }
 
        if(cfg.revision)
            bb.revisions[i]  = cfg.revision(ptr);
            
        BufferCPtr c       = cfg.fetch(ptr);
        if(!c){
            vizWarning << "ViData -- failed to fetch the buffer";
            return false;
        }
        
        return _set(bb, i, *c);
    }
    

    bool    ViData::_import(TB&tb, uint32_t i, const TexConfig& cfg)
    {
        if(i >= tb.count)
            return false;
        if(!cfg.fetch)
            return false;
        
        const void* ptr = nullptr;
        if(needs_pointer(cfg.activity)){
            if(!m_object){
                vizWarning << "ViData -- trying to fetch with a null pointer object";
                return false;
            }
            ptr = m_object;
        }

        if(cfg.revision)
            tb.revisions[i]  = cfg.revision(ptr);

        TextureCPtr c       = cfg.fetch(ptr);
        if(!c){
            vizWarning << "ViData -- failed to fetch the texture";
            return false;
        }
        
        return _set(tb, i, *c);
    }

    bool                ViData::_import_data()
    {
        bool    success = true;
        for(uint32_t i=0;i<m_index.count;++i){
            success = _import(m_index, i, m_config->ibos[i]) && success;
        }
        for(uint32_t i=0;i<m_storage.count;++i){
            success = _import(m_storage, i, m_config->sbos[i]) && success;
        }
        for(uint32_t i=0;i<m_texture.count;++i){
            success = _import(m_texture, i, m_config->texs[i]) && success;
        }
        for(uint32_t i=0;i<m_uniform.count;++i){
            success = _import(m_uniform, i, m_config->ubos[i]) && success;
        }
        for(uint32_t i=0;i<m_vertex.count;++i){
            success = _import(m_vertex, i, m_config->vbos[i]) && success;
        }
        return success;
    }

    std::error_code     ViData::_init_data(ViVisualizer&viz, SharedPipelineConfig pipe, const Options& opts)
    {
        m_viz               = &viz;
        m_config            = pipe;
        m_object            = opts.object;
        if(m_object){
            m_status |= S::Dynamic;
        } else {
            m_status |= S::Static;
        }
        
        if(!m_config){
            vizWarning << "ViData() -- unable to create data structure to a NULL pipeline configuration.";
            return errors::data_cant_initialize();
        }
        
        //  some preliminary checks...
        for(auto& cfg : m_config->ibos){
            if(!cfg.fetch){
                vizWarning << "ViData() -- index buffer without a fetch method, bad configuration.";
            }
            if((cfg.activity == DataActivity::DYNAMIC) && !cfg.revision){
                vizWarning << "ViData() -- index buffer without a revision method, bad configuration.";
            }
        }
        for(auto& cfg : m_config->sbos){
            if(!cfg.fetch){
                vizWarning << "ViData() -- storage buffer without a fetch method, bad configuration.";
            }
            if((cfg.activity == DataActivity::DYNAMIC) && !cfg.revision){
                vizWarning << "ViData() -- storage buffer without a revision method, bad configuration.";
            }
        }
        for(auto& cfg : m_config->texs){
            if(!cfg.fetch){
                vizWarning << "ViData() -- texture without a fetch method, bad configuration.";
            }
            if((cfg.activity == DataActivity::DYNAMIC) && !cfg.revision){
                vizWarning << "ViData() -- texture without a revision method, bad configuration.";
            }
        }
        for(auto& cfg : m_config->ubos){
            if(!cfg.fetch){
                vizWarning << "ViData() -- uniform buffer without a fetch method, bad configuration.";
            }
            if((cfg.activity == DataActivity::DYNAMIC) && !cfg.revision){
                vizWarning << "ViData() -- uniform buffer without a revision method, bad configuration.";
            }
        }
        for(auto& cfg : m_config->vbos){
            if(!cfg.fetch){
                vizWarning << "ViData() -- vertex buffer without a fetch method, bad configuration.";
            }
            if((cfg.activity == DataActivity::DYNAMIC) && !cfg.revision){
                vizWarning << "ViData() -- vertex buffer without a revision method, bad configuration.";
            }
        }
        
        
        m_index.count       = pipe->ibos.size();
        m_storage.count     = pipe->sbos.size();
        m_uniform.count     = pipe->ubos.size();
        m_vertex.count      = pipe->vbos.size();
        m_texture.count     = pipe->texs.size();
        
        if(m_index.count > BB::kMaxBindings){
            vizWarning << "ViData() -- too many index buffers.  Max is " << BB::kMaxBindings;
            return errors::data_cant_initialize();
        }
        

        if(m_storage.count > BB::kMaxBindings){
            vizWarning << "ViData() -- too many storage buffers.  Max is " << BB::kMaxBindings;
            return errors::data_cant_initialize();
        }
        

        if(m_texture.count > BB::kMaxBindings){
            vizWarning << "ViData() -- too many texture buffers.  Max is " << TB::kMaxBindings;
            return errors::data_cant_initialize();
        }
        

        if(m_uniform.count > BB::kMaxBindings){
            vizWarning << "ViData() -- too many uniform buffers.  Max is " << BB::kMaxBindings;
            return errors::data_cant_initialize();
        }
        

        if(m_vertex.count > BB::kMaxBindings){
            vizWarning << "ViData() -- too many vertex buffers.  Max is " << BB::kMaxBindings;
            return errors::data_cant_initialize();
        }
        
        m_index.buf0        = 0;
        m_storage.buf0      = m_index.end_buf();
        m_uniform.buf0      = m_storage.end_buf();
        m_vertex.buf0       = m_uniform.end_buf();
        uint32_t  nBuf      = m_vertex.end_buf();
        
        if(nBuf){
            m_bufferPtrs.resize(nBuf);
            m_buffers.resize(nBuf, nullptr);
            m_bytes.resize(nBuf, 0);
            m_offsets.resize(nBuf, 0);
            m_pointers.resize(nBuf, nullptr);
            m_sizes.resize(nBuf, 0);

            _carve_buffer(m_index);
            _carve_buffer(m_storage);
            _carve_buffer(m_uniform);
            _carve_buffer(m_vertex);
        }


        m_index.data0       = 0;
        m_storage.data0     = m_index.end_data();
        m_texture.data0     = m_storage.end_data();
        m_uniform.data0     = m_texture.end_data();
        m_vertex.data0      = m_uniform.end_data();
        uint32_t    nData   = m_vertex.end_data();
        
        if(nData){
            m_ids.resize(nData, 0);
            m_revisions.resize(nData, 0);
         
            _carve_data(m_index);
            _carve_data(m_storage);
            _carve_data(m_texture);
            _carve_data(m_uniform);
            _carve_data(m_vertex);
        }

        uint32_t    nTex    = m_texture.end_tex();
        if(nTex){
            m_imageViews.resize(nTex, nullptr);
            m_samplers.resize(nTex, nullptr);
            m_texturePtrs.resize(nTex);
            
            _carve_texture(m_texture);
        }
        
        if(!_descriptors(opts))
            return errors::data_cant_initialize();
        return {};
    }

    std::error_code    ViData::_init_data(const ViData&vi, const Options& opts)
    {
        m_viz               = vi.m_viz;
        m_config            = vi.m_config;
        m_object            = opts.object;
        if(m_object){
            m_status |= S::Dynamic;
        } else {
            m_status |= S::Static;
        }

        if(!m_config){
            vizWarning << "Unable to create data structure to a NULL pipeline configuration.";
            return errors::data_cant_initialize();
        }
        
        m_bufferPtrs        = vi.m_bufferPtrs;
        m_texturePtrs       = vi.m_texturePtrs;

        m_buffers           = vi.m_buffers;
        m_bytes             = vi.m_bytes;
        m_ids               = vi.m_ids;
        m_imageViews        = vi.m_imageViews;
        m_offsets           = vi.m_offsets;
        m_revisions         = vi.m_revisions;
        m_samplers          = vi.m_samplers;
        m_sizes             = vi.m_sizes;
        
        m_vertex.import_stats(vi.m_vertex);
        m_index.import_stats(vi.m_index);
        m_storage.import_stats(vi.m_storage);
        m_uniform.import_stats(vi.m_uniform);
        m_texture.import_stats(vi.m_texture);

        if(!_descriptors(opts))
            return errors::data_cant_initialize();
        return {};
    }
    
    void                ViData::_kill_data()
    {
        if(m_viz && m_viz->device()){
            if(m_status(S::DescSets) && m_descriptorPool && !m_descriptors.empty()){
                vkFreeDescriptorSets(m_viz->device(), m_descriptorPool, m_descriptors.size(), m_descriptors.data());
            }
            if(m_status(S::DescLayout) && m_descriptorLayout){
                vkDestroyDescriptorSetLayout(m_viz->device(), m_descriptorLayout, nullptr);
            }
        }
        m_descriptors.clear();
        m_descriptorLayout  = nullptr;
        m_descriptorPool    = nullptr;

        m_vertex        = {};
        m_index         = {};
        m_storage       = {};
        m_uniform       = {};
        m_texture       = {};
        
        m_buffers.clear();
        m_bytes.clear();
        m_sizes.clear();
        m_ids.clear();
        m_imageViews.clear();
        m_offsets.clear();
        m_samplers.clear();

        m_bufferPtrs.clear();
        m_texturePtrs.clear();
    }

    void    ViData::_publish(BB&bb, uint32_t i)
    {
        if(!(bb.modified & (1<<i)))
            return ;
        
        bb.infos[i].buffer   = bb.buffers[i];
        m_dispatch.push_back(bb.writes[i]);
    }
    
    void    ViData::_publish(TB&tb, uint32_t i)
    {
        if(!(tb.modified & (1<<i)))
            return ;
        tb.infos[i].imageView   = tb.views[i];
        tb.infos[i].sampler     = tb.samplers[i];
        m_dispatch.push_back(tb.writes[i]);
    }

    void    ViData::_publish_data(bool all)
    {
        if(m_writes.empty())    // nothing to do... done
            return;
            
        m_dispatch.clear();
        if(all){
            m_uniform.modified  = m_storage.modified = m_texture.modified = ~ 0;
        }
        
        for(uint32_t i=0;i<m_storage.count;++i)
            _publish(m_storage, i);
        for(uint32_t i=0;i<m_uniform.count;++i)
            _publish(m_uniform, i);
        for(uint32_t i=0;i<m_texture.count;++i)
            _publish(m_texture, i);
        
        if(m_dispatch.empty())
            return;
        
        vkUpdateDescriptorSets(m_viz->device(), m_dispatch.size(), m_dispatch.data(), 0, nullptr);
    }

    bool    ViData::_set(BB& bb, uint32_t i, const Buffer& buf)
    {
        ViBufferCPtr  x     = m_viz->buffer_create(buf);
        if(!x || !x->valid()){
            vizWarning << "ViData -- unable to load buffer";
            return false;
        }
        
        bb.managed[i]   = x;
        bb.buffers[i]   = x->buffer();
        bb.sizes[i]     = buf.memory.count();
        bb.bytes[i]     = buf.memory.bytes();
        bb.ids[i]       = buf.id();
        bb.modified    |= 1 << i;
        return true;
    }

    bool    ViData::_set(TB&tb, uint32_t i, const Texture& tex)
    {
        ViTextureCPtr x = m_viz->texture_create(tex);
        if(!x || !x->valid()){
            vizWarning << "ViData -- unable to load texture";
            return false;
        }
        tb.managed[i]   = x;
        tb.ids[i]       = tex.id();
        tb.views[i]     = x->image_view();
        tb.samplers[i]  = x->sampler();
        tb.modified    |= 1 << i;
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

    bool    ViData::_update(BB& bb, uint32_t i, const BaseBOConfig& cfg)
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
    
    bool    ViData::_update(TB& tb, uint32_t i, const TexConfig& cfg)
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

    //! Update the data (second time)
    bool    ViData::_update_data()
    {
        m_index.modified = m_storage.modified = m_texture.modified = m_uniform.modified = m_vertex.modified = 0;
        m_index.maxSize  = m_vertex.maxSize = 0;
        bool    success  = true;
        for(uint32_t i=0;i<m_index.count;++i){
            success = _update(m_index, i, m_config->ibos[i]) && success;
            m_index.maxSize = std::max(m_index.maxSize, m_index.sizes[i]);
        }
        for(uint32_t i=0;i<m_storage.count;++i){
            success = _update(m_storage, i, m_config->sbos[i]) && success;
        }
        for(uint32_t i=0;i<m_texture.count;++i){
            success = _update(m_texture, i, m_config->texs[i]) && success;
        }
        for(uint32_t i=0;i<m_uniform.count;++i){
            success = _update(m_uniform, i, m_config->ubos[i]) && success;
        }
        for(uint32_t i=0;i<m_vertex.count;++i){
            success = _update(m_vertex, i, m_config->vbos[i]) && success;
            m_vertex.maxSize = std::max(m_vertex.maxSize, m_vertex.sizes[i]);
        }
        return success;
    }
    

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    uint32_t    ViData::buffer_count() const
    {
        return (uint32_t) m_buffers.size();
    }

    uint32_t    ViData::descriptor_count() const
    {
        return (uint32_t) m_descriptors.size();
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

    uint32_t    ViData::storage_count() const
    {
        return m_storage.count;
    }

    uint32_t    ViData::texture_count() const
    {
        return m_texture.count;
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
    
    uint32_t    ViData::vertex_count() const
    {
        return m_vertex.count;
    }
    
    uint32_t    ViData::vertex_max_size() const
    {
        return m_vertex.maxSize;
    }

}
