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


    //! Render buffer object manager (Running out of good names)
    //!
    class ViData {
    public:
        struct Options;
        enum class F : uint8_t {
            MakeDescriptorLayout    = 0
        };
        using descriptor_t  = std::variant<std::monostate, layout_t, VkDescriptorPool>;
    
        VkBuffer            index_buffer(size_t) const;
        size_t              index_count() const;
        
        VkBuffer            storage_buffer(size_t) const;
        size_t              storage_count() const;

        size_t              texture_count() const;
        VkImageView         texture_image_view(size_t) const;
        VkSampler           texture_sampler(size_t) const;
        
        
        VkBuffer            uniform_buffer(size_t) const;
        size_t              uniform_count() const;
        
        VkBuffer            vertex_buffer(size_t) const;
        size_t              vertex_count() const;
        
        ViVisualizer*       visualizer() const { return m_viz; }
        
        
    protected:

        ViData();
        ~ViData();

        std::error_code     _init_data(ViVisualizer&, SharedPipelineConfig, const Options& opts);
        std::error_code     _init_data(const ViData&, const Options& opts);
        void                _kill_data();
        
        //! Imports the data
        void                _import_data();
        
        //! Update the data
        void                _update_data();
        
        //! Updates descriptors
        void                _publish_data();

    private:
        enum class S : uint8_t {
            DescSets    = 0,
            DescLayout,
            Static,
            Dynamic
        };

        struct BB {
            //VmaAllocation*      allocations     = nullptr;
            VkBuffer*           buffers         = nullptr;
            VkDescriptorSet*    descriptors     = nullptr;
            uint32_t*           counts          = nullptr;
            uint64_t*           ids             = nullptr;
            ViBufferCPtr*       managed         = nullptr;
            uint32_t*           offsets         = nullptr;
            const void**        pointers        = nullptr;
            uint64_t*           revisions       = nullptr;
            uint32_t*           sizes           = nullptr;
            
            // update bitmask
            uint32_t            update          = 0;    //!< Update mask
            uint32_t            count           = 0;    //!< Count of bindings/items
            uint32_t            buf0            = 0;    //!< Index in buffers to us
            uint32_t            data0           = 0;    //!< Index in data to us
            uint32_t            desc0           = 0;    //!< Index in descriptors to us
            uint32_t            maxCount        = 0;    //!< Max count seen
            
            static constexpr uint32_t   kMaxBindings = sizeof(update);
            
            uint32_t        end_buf() const { return count + buf0; }
            uint32_t        end_data() const { return count + data0; }
            uint32_t        end_desc() const { return count + desc0; }
            
            void    import_stats(const BB& bb);
        };
        
        struct TB {
            VkDescriptorSet*    descriptors     = nullptr;
            uint64_t*           ids             = nullptr;
            ViTextureCPtr*      managed         = nullptr;
            uint64_t*           revisions       = nullptr;
            VkSampler*          samplers        = nullptr;
            VkImageView*        views           = nullptr;

            uint32_t            update          = 0;    //!< Update mask
            uint32_t            count           = 0;    //!< Count of bindings/items
            uint32_t            data0           = 0;    //!< Index in data to us
            uint32_t            desc0           = 0;    //!< Index in descriptors to us
            uint32_t            tex0            = 0;    //!< Index in textures to us

            static constexpr uint32_t   kMaxBindings = sizeof(update);
            
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

        std::vector<ViBufferCPtr>       m_bufferPtrs;       // PER BUFFER
        std::vector<VkBuffer>           m_buffers;          // PER BUFFER
        std::vector<uint32_t>           m_counts;           // PER BUFFER
        std::vector<VkDescriptorSet>    m_descriptors;      // PER DESCRIPTOR (SBO+UBO+TEX)
        std::vector<uint64_t>           m_ids;              // ALL
        std::vector<uint64_t>           m_revisions;        // ALL
        std::vector<uint32_t>           m_sizes;            // PER BUFFER
        std::vector<uint32_t>           m_offsets;          // PER BUFFER
        std::vector<const void*>        m_pointers;         // PER BUFFER
        std::vector<VkImageView>        m_imageViews;       // PER TEXTURE
        std::vector<VkSampler>          m_samplers;         // PER TEXTURE
        std::vector<ViTextureCPtr>      m_texturePtrs;      // PER TEXTURE

        ViVisualizer*                   m_viz               = nullptr;
        const void*                     m_object            = nullptr;
        SharedPipelineConfig            m_config;
        VkDescriptorSetLayout           m_descriptorLayout  = nullptr;
        VkDescriptorPool                m_descriptorPool    = nullptr;
        Flags<S>                        m_status            = {};
        
        std::error_code    _create_descriptor_sets(VkDescriptorPool);
        std::error_code    _create_descriptor_layout();
        std::error_code    _descriptors(const Options& opts);
        void    _kill_descriptors();
        
        void    _carve_buffer(BB&);
        void    _carve_data(BB&);
        void    _carve_data(TB&);
        void    _carve_descriptor(BB&);
        void    _carve_descriptor(TB&);
        void    _carve_texture(TB&);
    };

    struct ViData::Options {
        descriptor_t            descriptors;
        Flags<F>                flags               = {};
        const void*             object              = nullptr;
    };
}
