////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/keywords.hpp>
#include <yq/core/Flags.hpp>
#include <yq/core/Ref.hpp>
#include <yq/tachyon/pipeline/Pipeline.hpp>
#include <yq/tachyon/typedef/vi_buffer.hpp>
#include <yq/tachyon/typedef/vi_pipeline.hpp>
#include <yq/tachyon/typedef/push.hpp>
#include <yq/tachyon/typedef/vi_texture.hpp>
#include <yq/tachyon/typedef/vi_buffer.hpp>
#include <yq/tachyon/vulkan/VqStructs.hpp>

#include <vulkan/vulkan_core.h>
#include <span>
#include <system_error>
#include <vector>
#include <variant>

namespace yq::tachyon {

    struct ViBufferObject;
    struct ViTextureObject;
    struct RenderedSnap;
    class ViDevice;
    
    // pending...    might be a setting to rendered's update
    struct ViDataMap {
        std::map<uint32_t, VkDescriptorSet> storages;
        std::map<uint32_t, VkDescriptorSet> textures; 
        std::map<uint32_t, VkDescriptorSet> uniforms; 
        std::map<uint32_t, VkBuffer>        vertices;
    };
    
    struct ViDataOptions {
        enum class F : uint8_t {
            StaticLayout
            // MakeDescriptorLayout    = 0
        };
        using descriptor_t  = std::variant<std::monostate, layout_k, allocate_k>;

        descriptor_t            descriptors;
        Flags<F>                flags               = {};
        VkDescriptorSetLayout   layout              = nullptr;
        const void*             object              = nullptr;
        const RenderedSnap*     snap                = nullptr;
        VkDescriptorPool        pool                = nullptr;
        VkShaderStageFlags      shaders             = {};
    };


    //! Render buffer object manager (Running out of good names)
    //!
    class ViData {
    public:
    
        struct Base {
            uint64_t        id          = 0;    // Buffer/Texture ID
            uint32_t        index       = 0;
            bool            external    = false;
        };
        
        struct BO : public Base {
            ViBufferCPtr    managed;
            uint32_t        bytes   = 0;    //!< Bytes of buffer (should be count * size)
            uint32_t        count   = 0;    //!< Number of items
            uint32_t        stride  = 0;    //!< Size of each item
            
            BO();
            ~BO();
        };
        
        struct IBO : public BO {
            const Pipeline::index_buffer_t*     config  = nullptr;
            VkBuffer        buffer  = nullptr;
            VkIndexType     type    = VK_INDEX_TYPE_UINT32;

            IBO();
            ~IBO();
        };
        
        struct VBO : public BO {
            const Pipeline::vertex_buffer_t*     config  = nullptr;
        
            uint32_t    vIndex  = 0;
            
            VBO();
            ~VBO();
        };
        
        struct SBO : public BO {
            const Pipeline::storage_buffer_t*     config  = nullptr;
            
            VqWriteDescriptorSet        write;
            VkDescriptorBufferInfo      info;
            uint32_t                    dIndex  = 0;
        
            SBO();
            ~SBO();
        };
        
        struct UBO : public BO {
            const Pipeline::uniform_buffer_t*     config  = nullptr;
            uint32_t                    dIndex  = 0;
            VqWriteDescriptorSet        write;
            VkDescriptorBufferInfo      info;

            UBO();
            ~UBO();
        };
        
        struct TO : public Base {
            const Pipeline::texture_t*     config  = nullptr;
            ViTextureCPtr           managed;
            VkExtent3D              extents;
            uint32_t                dIndex      = 0;
            VqWriteDescriptorSet    write;
            VkDescriptorImageInfo   info;

            TO();
            ~TO();
        };
    
        uint32_t                buffer_count() const;
        
        uint32_t                descriptor_count() const;
        
        VkDescriptorSetLayout   descriptor_set_layout() const { return m_descriptorLayout; }
        VkDescriptorPool        descriptor_pool() const { return m_descriptorPool; }
        bool                    descriptors_defined() const;
        
        std::span<const VkDescriptorSet>    descriptor_span() const;
    
        VkBuffer                index_buffer(uint32_t) const;
        uint32_t                index_bytes() const;
        uint32_t                index_bytes(uint32_t) const;
        uint32_t                index_count() const;
        uint32_t                index_max_size() const;
        
        const Pipeline*         pipeline_config() const { return m_config; }
        
        VkBuffer                storage_buffer(uint32_t) const;
        uint32_t                storage_bytes() const;
        uint32_t                storage_bytes(uint32_t) const;
        uint32_t                storage_count() const;

        uint32_t                texture_count() const;
        VkImageView             texture_image_view(uint32_t) const;
        VkSampler               texture_sampler(uint32_t) const;
        
        
        VkBuffer                uniform_buffer(uint32_t) const;
        uint32_t                uniform_bytes() const;
        uint32_t                uniform_bytes(uint32_t) const;
        uint32_t                uniform_count() const;
        
        VkBuffer                vertex_buffer(uint32_t) const;
        uint32_t                vertex_bytes() const;
        uint32_t                vertex_bytes(uint32_t) const;
        uint32_t                vertex_count() const;
        uint32_t                vertex_max_size() const;

            //   used for external storages
        void    set_external_storage(uint32_t, VkDescriptorSet);
        
            //   used for external textures
        void    set_external_texture(uint32_t, VkDescriptorSet);

            //   used for external uniforms
        void    set_external_uniform(uint32_t, VkDescriptorSet);
        
        bool    has_externals() const;

    protected:

        enum class S : uint8_t {
            DescSets    = 0,    // We own the descriptor sets
            DescLayout,         // We own the descriptor set layout
            DescDefined,        // Descriptors were defined
            Static,             // Static data set (no object)
            Dynamic,            // Dynamic data set (with object)
            External
        };
        
        enum class R : int8_t {
            Updated = 1,    //!< Modifications
            Success = 0,    //!< Unmodified
            Failure = -1    //!< Failure
        };
        
        ViData();
        ~ViData();
        
        std::error_code     _init_data(ViDevice&, const Pipeline*, const ViDataOptions& options);
        std::error_code     _init_data(const ViData&, const ViDataOptions& options);
        void                _kill_data();
        
        //! Updates descriptors
        void                _publish_data(bool all=false);
        
        R                   _update_data(const RenderedSnap* sn=nullptr, const ViDataMap& dm={});
        
        const void*                     m_object            = nullptr;
        VkDescriptorSetLayout           m_descriptorLayout  = nullptr;
        VkDescriptorPool                m_descriptorPool    = nullptr;
        Flags<S>                        m_status            = {};
        ViDevice*                       m_device            = nullptr;
        const Pipeline*                 m_config            = nullptr;
        
        std::vector<VkDescriptorSetLayoutBinding>   m_layoutBindings;
        std::vector<VkDescriptorSet>                m_descriptors;
        std::vector<VkWriteDescriptorSet>           m_dispatch;
        
        const Pipeline::push_t*         m_push              = nullptr;
        IBO                             m_ibo;
        std::map<uint32_t, SBO>         m_sbo;
        std::map<uint32_t, TO>          m_tex;
        std::map<uint32_t, UBO>         m_ubo;
        std::map<uint32_t, VBO>         m_vbo;
        std::vector<VkBuffer>           m_vboBuffers;
        std::vector<VkDeviceSize>       m_vboOffsets;
        uint32_t                        m_vtxCount          = 0;
        
        SBO*        _sbo(uint32_t);        
        const SBO*  _sbo(uint32_t) const;        
        TO*         _tex(uint32_t);
        const TO*   _tex(uint32_t) const;
        UBO*        _ubo(uint32_t);        
        const UBO*  _ubo(uint32_t) const;        
        VBO*        _vbo(uint32_t);
        const VBO*  _vbo(uint32_t) const;
        
        bool    _create_descriptor_sets(const ViDataOptions& options);
        bool    _create_descriptor_layout(const ViDataOptions& options);
        bool    _descriptors(const ViDataOptions& options);
        void    _kill_descriptors();

        R       _update(BO&, const Buffered&);
        R       _update(TO&, const Textured&);

        R    _set(BO&, const Buffer&);
        R    _set(TO&, const Texture&);
        R    _set(BO&, const ViBufferCPtr&, uint64_t id=0);
        R    _set(TO&, const ViTextureCPtr&, uint64_t id=0);


        #if 0
    
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
        std::vector<uint64_t>               m_ids;              // ALL
        std::vector<uint64_t>               m_revisions;        // ALL
        std::vector<VkDeviceSize>           m_offsets;          // PER BUFFER
        std::vector<const void*>            m_pointers;         // PER BUFFER
        std::vector<VkImageView>            m_imageViews;       // PER TEXTURE
        std::vector<VkSampler>              m_samplers;         // PER TEXTURE
        std::vector<uint32_t>               m_sizes;            // PER BUFFER
        std::vector<ViTextureCPtr>          m_texturePtrs;      // PER TEXTURE
        std::vector<VkExtent3D>             m_extents;          // PER TEXTURE

    protected:
    
    private:

        
        bool    _import(BB&, uint32_t, const Pipeline::buffer_t&);
        bool    _import(BB&, uint32_t, const Pipeline::buffer_t&, const Buffered&);
        bool    _import(TB&, uint32_t, const Pipeline::texture_t&);
        bool    _import(TB&, uint32_t, const Pipeline::texture_t&, const Textured&);

        bool    _update(BB&, uint32_t, const Pipeline::buffer_t&);
        bool    _update(BB&, uint32_t, const Pipeline::buffer_t&, const Buffered&);
        bool    _update(TB&, uint32_t, const Pipeline::texture_t&);
        bool    _update(TB&, uint32_t, const Pipeline::texture_t&, const Textured&);

        bool    _import_from(const RenderedSnap* sn);
        bool    _update_from(const RenderedSnap* sn);

        bool    _import_self();
        bool    _update_self();

        void    _publish(BB&, uint32_t);
        void    _publish(TB&, uint32_t);
        #endif
    };
}
