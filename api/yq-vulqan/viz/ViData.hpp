////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/keywords.hpp>
#include <yq-toolbox/basic/Flags.hpp>
#include <yq-vulqan/typedef/buffer.hpp>
#include <yq-vulqan/typedef/pipeline.hpp>
#include <yq-vulqan/typedef/push.hpp>
#include <yq-vulqan/typedef/texture.hpp>

#include <vulkan/vulkan_core.h>
#include <span>
#include <system_error>
#include <vector>
#include <variant>

namespace yq::tachyon {

    class ViVisualizer;
    struct ViBufferObject;
    struct ViTextureObject;
    struct BaseBOConfig;
    struct TexConfig;


    //! Render buffer object manager (Running out of good names)
    //!
    class ViData {
    public:
        struct Options;
        enum class F : uint8_t {
            // MakeDescriptorLayout    = 0
        };
        using descriptor_t  = std::variant<std::monostate, layout_t, allocate_t>;
        
        uint32_t                buffer_count() const;
        
        uint32_t                descriptor_count() const;
        
        VkDescriptorSetLayout   descriptor_set_layout() const { return m_descriptorLayout; }
        VkDescriptorPool        descriptor_pool() const { return m_descriptorPool; }
    
        VkBuffer            index_buffer(size_t) const;
        uint32_t            index_bytes() const;
        uint32_t            index_bytes(size_t) const;
        uint32_t            index_count() const;
        uint32_t            index_max_size() const;
        
        SharedPipelineConfig    pipeline_config() const;
        
        VkBuffer            storage_buffer(size_t) const;
        uint32_t            storage_bytes() const;
        uint32_t            storage_bytes(size_t) const;
        uint32_t            storage_count() const;

        uint32_t            texture_count() const;
        VkImageView         texture_image_view(size_t) const;
        VkSampler           texture_sampler(size_t) const;
        
        
        VkBuffer            uniform_buffer(size_t) const;
        uint32_t            uniform_bytes() const;
        uint32_t            uniform_bytes(size_t) const;
        uint32_t            uniform_count() const;
        
        VkBuffer            vertex_buffer(size_t) const;
        uint32_t            vertex_bytes() const;
        uint32_t            vertex_bytes(size_t) const;
        uint32_t            vertex_count() const;
        uint32_t            vertex_max_size() const;
        
        ViVisualizer*       visualizer() const { return m_viz; }
        
        
    protected:

        ViData();
        ~ViData();

        std::error_code     _init_data(ViVisualizer&, SharedPipelineConfig, const Options& opts);
        std::error_code     _init_data(const ViData&, const Options& opts);
        void                _kill_data();
        
        //! Imports the data (first time)
        bool                _import_data();
        
        //! Updates descriptors
        void                _publish_data(bool all=false);
        
        bool                _update_data();
        

    private:
        enum class S : uint8_t {
            DescSets    = 0,    // We own the descriptor sets
            DescLayout,         // We own the descriptor set layout
            Static,             // Static data set (no object)
            Dynamic             // Dynamic data set (with object)
        };

        struct BB {
            //VmaAllocation*      allocations     = nullptr;
            VkBuffer*               buffers         = nullptr;
            VkDescriptorSet*        descriptors     = nullptr;
            uint32_t*               sizes           = nullptr;
            uint64_t*               ids             = nullptr;
            ViBufferCPtr*           managed         = nullptr;
            uint32_t*               offsets         = nullptr;
            const void**            pointers        = nullptr;
            uint64_t*               revisions       = nullptr;
            uint32_t*               bytes           = nullptr;
            VkWriteDescriptorSet*   writes          = nullptr;
            VkDescriptorBufferInfo* infos           = nullptr;
            
            uint32_t    modified        = 0;    //!< Modified mask
            uint32_t    count           = 0;    //!< Count of bindings/items
            uint32_t    buf0            = 0;    //!< Index in buffers to us
            uint32_t    data0           = 0;    //!< Index in data to us
            uint32_t    desc0           = 0;    //!< Index in descriptors to us
            uint32_t    maxSize         = 0;    //!< Max size seen
            
            static constexpr uint32_t   kMaxBindings = sizeof(modified)*8;
            
            uint32_t        end_buf() const { return count + buf0; }
            uint32_t        end_data() const { return count + data0; }
            uint32_t        end_desc() const { return count + desc0; }
            
            void    import_stats(const BB& bb);
        };
        
        struct TB {
            VkDescriptorSet*        descriptors     = nullptr;
            uint64_t*               ids             = nullptr;
            ViTextureCPtr*          managed         = nullptr;
            uint64_t*               revisions       = nullptr;
            VkSampler*              samplers        = nullptr;
            VkImageView*            views           = nullptr;
            VkWriteDescriptorSet*   writes          = nullptr;
            VkDescriptorImageInfo*  infos           = nullptr;

            uint32_t    modified        = 0;    //!< Modified mask
            uint32_t    count           = 0;    //!< Count of bindings/items
            uint32_t    data0           = 0;    //!< Index in data to us
            uint32_t    desc0           = 0;    //!< Index in descriptors to us
            uint32_t    tex0            = 0;    //!< Index in textures to us

            static constexpr uint32_t   kMaxBindings = sizeof(modified)*8;
            
            void    import_stats(const TB& tb);

            uint32_t        end_data() const { return count + data0; }
            uint32_t        end_desc() const { return count + desc0; }
            uint32_t        end_tex() const { return count + tex0; }
        };
    
        BB      m_index;
        BB      m_storage;
        BB      m_uniform;
        BB      m_vertex;
        TB      m_texture;

        std::vector<ViBufferCPtr>           m_bufferPtrs;       // PER BUFFER
        std::vector<VkBuffer>               m_buffers;          // PER BUFFER
        std::vector<uint32_t>               m_bytes;            // PER BUFFER
        std::vector<VkDescriptorSet>        m_descriptors;      // PER DESCRIPTOR (SBO+UBO+TEX)
        std::vector<uint64_t>               m_ids;              // ALL
        std::vector<uint64_t>               m_revisions;        // ALL
        std::vector<uint32_t>               m_offsets;          // PER BUFFER
        std::vector<const void*>            m_pointers;         // PER BUFFER
        std::vector<VkImageView>            m_imageViews;       // PER TEXTURE
        std::vector<VkSampler>              m_samplers;         // PER TEXTURE
        std::vector<uint32_t>               m_sizes;            // PER BUFFER
        std::vector<ViTextureCPtr>          m_texturePtrs;      // PER TEXTURE
        std::vector<VkWriteDescriptorSet>   m_writes;           // ALL DESCRIPTORS
        std::vector<VkDescriptorBufferInfo> m_bufferInfos;      // ALL BUFFER DESCRIPTORS
        std::vector<VkDescriptorImageInfo>  m_imageInfos;       // ALL TEXTURES
        std::vector<VkWriteDescriptorSet>   m_dispatch;         // (NOT CARVED)

    protected:
        ViVisualizer*           m_viz               = nullptr;
        SharedPipelineConfig    m_config;
    
    private:
        const void*             m_object            = nullptr;
        VkDescriptorSetLayout   m_descriptorLayout  = nullptr;
        VkDescriptorPool        m_descriptorPool    = nullptr;
        Flags<S>                m_status            = {};
        
        bool    _create_descriptor_sets(const Options& opts);
        bool    _create_descriptor_layout(const Options& opts);
        bool    _descriptors(const Options& opts);
        void    _kill_descriptors();
        
        void    _carve_buffer(BB&);
        void    _carve_data(BB&);
        void    _carve_data(TB&);
        void    _carve_descriptor(BB&);
        void    _carve_descriptor(TB&);
        void    _carve_texture(TB&);

        bool    _import(BB&, uint32_t, const BaseBOConfig&);
        bool    _import(TB&, uint32_t, const TexConfig&);

        bool    _set(BB&, uint32_t, const Buffer&);
        bool    _set(TB&, uint32_t, const Texture&);

        bool    _update(BB&, uint32_t, const BaseBOConfig&);
        bool    _update(TB&, uint32_t, const TexConfig&);

        void    _publish(BB&, uint32_t);
        void    _publish(TB&, uint32_t);
    };

    struct ViData::Options {
        descriptor_t            descriptors;
        Flags<F>                flags               = {};
        VkDescriptorSetLayout   layout              = nullptr;
        const void*             object              = nullptr;
        VkDescriptorPool        pool                = nullptr;
        VkShaderStageFlags      shaders             = {};
    };
}
