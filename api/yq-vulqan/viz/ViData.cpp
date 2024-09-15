////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViData.hpp"

#include <yq-vulqan/errors.hpp>
#include <yq-vulqan/logging.hpp>
#include <yq-vulqan/pipeline/PipelineConfig.hpp>
#include <yq-vulqan/viz/ViBuffer.hpp>
#include <yq-vulqan/viz/ViTexture.hpp>
#include <yq-vulqan/viz/ViVisualizer.hpp>

namespace yq::tachyon {

    void    ViData::BB::import_stats(const BB& bb)
    {
        update      = bb.update;
        count       = bb.count;
        buf0        = bb.buf0;
        data0       = bb.data0;
        desc0       = bb.desc0;
        maxCount    = bb.maxCount;
    }

    void    ViData::TB::import_stats(const TB& tb)
    {
        update      = tb.update;
        count       = tb.count;
        data0       = tb.data0;
        desc0       = tb.desc0;
        tex0        = tb.tex0;
    }


    ViData::ViData()
    {
    }
    
    ViData::~ViData()
    {
    }

    void    ViData::_carve_buffer(BB&bb)
    {
        if(bb.count){
            bb.buffers  = &m_buffers[bb.buf0];
            bb.counts   = &m_counts[bb.buf0];
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
        }
    }
    
    void    ViData::_carve_descriptor(TB&tb)
    {
        if(tb.count){
            tb.descriptors  = &m_descriptors[tb.desc0];
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

    std::error_code    ViData::_create_descriptor_sets(VkDescriptorPool dPool)
    {
        uint32_t        nDesc   = m_uniform.end_desc();
        if(!nDesc)
            return {};
        m_descriptors.resize(nDesc, nullptr);
        m_descriptorPool    = dPool;
        
        return errors::todo();
    }
    
    std::error_code    ViData::_create_descriptor_layout()
    {
        return errors::todo();
    }

    std::error_code    ViData::_descriptors(const Options&opts)
    {
        if(std::get_if<layout_t>(&opts.descriptors)){
            return _create_descriptor_layout();
        } else if(auto p = std::get_if<VkDescriptorPool>(&opts.descriptors)){
            return _create_descriptor_sets(*p);
        } else {
            return {};
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
        
        m_index.count       = pipe->ibos.size();
        m_storage.count     = pipe->sbos.size();
        m_uniform.count     = pipe->ubos.size();
        m_vertex.count      = pipe->vbos.size();
        m_texture.count     = pipe->texs.size();
        
        m_index.buf0        = 0;
        m_storage.buf0      = m_index.end_buf();
        m_uniform.buf0      = m_storage.end_buf();
        m_vertex.buf0       = m_uniform.end_buf();
        uint32_t  nBuf      = m_vertex.end_buf();
        
        m_storage.desc0     = 0;
        m_texture.desc0     = m_storage.end_data();
        m_uniform.desc0     = m_texture.end_data();
        
        
        if(nBuf){
            m_bufferPtrs.resize(nBuf);
            m_buffers.resize(nBuf, nullptr);
            m_counts.resize(nBuf, 0);
            m_pointers.resize(nBuf, nullptr);
            m_sizes.resize(nBuf, 0);
            m_offsets.resize(nBuf, 0);

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
        
        
        std::error_code ec  = _descriptors(opts);
        if(ec != std::error_code())
            return ec;
        
        return errors::todo();
    }

    std::error_code     ViData::_init_data(const ViData&vi, const Options& opts)
    {
        m_viz               = vi.m_viz;
        m_config            = vi.m_config;
        m_object            = opts.object;
        if(m_object){
            m_status |= S::Dynamic;
        } else {
            m_status |= S::Static;
        }

        m_bufferPtrs        = vi.m_bufferPtrs;
        m_texturePtrs       = vi.m_texturePtrs;

        m_buffers           = vi.m_buffers;
        m_counts            = vi.m_counts;
        m_ids               = vi.m_ids;
        m_revisions         = vi.m_revisions;
        m_sizes             = vi.m_sizes;
        m_offsets           = vi.m_offsets;
        m_imageViews        = vi.m_imageViews;
        m_samplers          = vi.m_samplers;
        
        m_vertex.import_stats(vi.m_vertex);
        m_index.import_stats(vi.m_index);
        m_storage.import_stats(vi.m_storage);
        m_uniform.import_stats(vi.m_uniform);
        m_texture.import_stats(vi.m_texture);

    

        std::error_code ec  = _descriptors(opts);
        if(ec != std::error_code())
            return ec;

        return errors::todo();
    }
    
    void                ViData::_kill_data()
    {
        if(m_viz && m_viz->device()){
            if(m_descriptorPool && !m_descriptors.empty()){
                vkFreeDescriptorSets(m_viz->device(), m_descriptorPool, m_descriptors.size(), m_descriptors.data());
            }
            if(m_descriptorLayout){
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
        m_bufferPtrs.clear();
        m_buffers.clear();
        m_counts.clear();
    }

}
