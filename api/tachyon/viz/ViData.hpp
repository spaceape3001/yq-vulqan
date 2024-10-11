////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/keywords.hpp>
#include <yq/core/Flags.hpp>
#include <tachyon/pipeline/Pipeline.hpp>
#include <tachyon/typedef/buffer.hpp>
#include <tachyon/typedef/pipeline.hpp>
#include <tachyon/typedef/push.hpp>
#include <tachyon/typedef/texture.hpp>

#include <vulkan/vulkan_core.h>
#include <span>
#include <system_error>
#include <vector>
#include <variant>

namespace yq::tachyon {

    class ViVisualizer;
    struct ViBufferObject;
    struct ViTextureObject;

    struct ViDataOptions {
        enum class F : uint8_t {
            StaticLayout
            // MakeDescriptorLayout    = 0
        };
        using descriptor_t  = std::variant<std::monostate, layout_t, allocate_t>;

        descriptor_t            descriptors;
        Flags<F>                flags               = {};
        VkDescriptorSetLayout   layout              = nullptr;
        const void*             object              = nullptr;
        VkDescriptorPool        pool                = nullptr;
        VkShaderStageFlags      shaders             = {};
    };


    //! Render buffer object manager (Running out of good names)
    //!
    class ViData {
    public:
        
        uint32_t                buffer_count() const;
        
        uint32_t                descriptor_count() const;
        
        VkDescriptorSetLayout   descriptor_set_layout() const { return m_descriptorLayout; }
        VkDescriptorPool        descriptor_pool() const { return m_descriptorPool; }
        bool                    descriptors_defined() const;
        
        std::span<const VkDescriptorSet>    descriptor_span() const;
    
        VkBuffer                index_buffer(size_t) const;
        uint32_t                index_bytes() const;
        uint32_t                index_bytes(size_t) const;
        uint32_t                index_count() const;
        uint32_t                index_max_size() const;
        
        const Pipeline*         pipeline_config() const { return m_config; }
        
        VkBuffer                storage_buffer(size_t) const;
        uint32_t                storage_bytes() const;
        uint32_t                storage_bytes(size_t) const;
        uint32_t                storage_count() const;

        uint32_t                texture_count() const;
        VkImageView             texture_image_view(size_t) const;
        VkSampler               texture_sampler(size_t) const;
        
        
        VkBuffer                uniform_buffer(size_t) const;
        uint32_t                uniform_bytes() const;
        uint32_t                uniform_bytes(size_t) const;
        uint32_t                uniform_count() const;
        
        VkBuffer                vertex_buffer(size_t) const;
        uint32_t                vertex_bytes() const;
        uint32_t                vertex_bytes(size_t) const;
        uint32_t                vertex_count() const;
        uint32_t                vertex_max_size() const;
        
        ViVisualizer*           visualizer() const { return m_viz; }
        
    protected:

        ViData();
        ~ViData();

        std::error_code     _init_data(ViVisualizer&, const Pipeline*, const ViDataOptions& options);
        std::error_code     _init_data(const ViData&, const ViDataOptions& options);
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
            DescDefined,        // Descriptors were defined
            Static,             // Static data set (no object)
            Dynamic             // Dynamic data set (with object)
        };

    protected:
        struct BB {
            //VmaAllocation*      allocations     = nullptr;
            VkBuffer*               buffers         = nullptr;
            VkDescriptorSet*        descriptors     = nullptr;
            uint32_t*               sizes           = nullptr;
            uint64_t*               ids             = nullptr;
            ViBufferCPtr*           managed         = nullptr;
            VkDeviceSize*           offsets         = nullptr;
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
            VkExtent3D*             extents         = nullptr;

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
        std::vector<VkDeviceSize>           m_offsets;          // PER BUFFER
        std::vector<const void*>            m_pointers;         // PER BUFFER
        std::vector<VkImageView>            m_imageViews;       // PER TEXTURE
        std::vector<VkSampler>              m_samplers;         // PER TEXTURE
        std::vector<uint32_t>               m_sizes;            // PER BUFFER
        std::vector<ViTextureCPtr>          m_texturePtrs;      // PER TEXTURE
        std::vector<VkWriteDescriptorSet>   m_writes;           // ALL DESCRIPTORS
        std::vector<VkDescriptorBufferInfo> m_bufferInfos;      // ALL BUFFER DESCRIPTORS
        std::vector<VkDescriptorImageInfo>  m_imageInfos;       // ALL TEXTURES
        std::vector<VkWriteDescriptorSet>   m_dispatch;         // (NOT CARVED)
        std::vector<VkExtent3D>             m_extents;          // PER TEXTURE

    protected:
        ViVisualizer*       m_viz               = nullptr;
        const Pipeline*     m_config            = nullptr;
        std::vector<VkDescriptorSetLayoutBinding>   m_descriptorSetLayoutBindingVector;
    
    private:
        const void*             m_object            = nullptr;
        VkDescriptorSetLayout   m_descriptorLayout  = nullptr;
        VkDescriptorPool        m_descriptorPool    = nullptr;
        Flags<S>                m_status            = {};

        
        bool    _create_descriptor_sets(const ViDataOptions& options);
        bool    _create_descriptor_layout(const ViDataOptions& options);
        bool    _descriptors(const ViDataOptions& options);
        void    _kill_descriptors();
        
        void    _carve(BB&);
        void    _carve(TB&);
        void    _carve_descriptor(BB&);
        void    _carve_descriptor(TB&);

        bool    _import(BB&, uint32_t, const Pipeline::buffer_t&);
        bool    _import(TB&, uint32_t, const Pipeline::texture_t&);

        bool    _set(BB&, uint32_t, const Buffer&);
        bool    _set(TB&, uint32_t, const Texture&);

        bool    _update(BB&, uint32_t, const Pipeline::buffer_t&);
        bool    _update(TB&, uint32_t, const Pipeline::texture_t&);

        void    _publish(BB&, uint32_t);
        void    _publish(TB&, uint32_t);
    };
}
