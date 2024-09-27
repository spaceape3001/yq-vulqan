////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Ref.hpp>
#include <yq-toolbox/basic/UniqueID.hpp>

#include <yq-vulqan/data/DataFormat.hpp>
#include <yq-vulqan/pipeline/CullMode.hpp>
#include <yq-vulqan/pipeline/DataActivity.hpp>
#include <yq-vulqan/pipeline/FrontFace.hpp>
#include <yq-vulqan/pipeline/IndexType.hpp>
#include <yq-vulqan/pipeline/PipelineBinding.hpp>
#include <yq-vulqan/pipeline/PolygonMode.hpp>
#include <yq-vulqan/pipeline/PushConfigType.hpp>
#include <yq-vulqan/pipeline/Topology.hpp>
#include <yq-vulqan/pipeline/VertexInputRate.hpp>

#include <yq-vulqan/typedef/buffer.hpp>
#include <yq-vulqan/typedef/pipeline.hpp>
#include <yq-vulqan/typedef/push.hpp>
#include <yq-vulqan/typedef/shader.hpp>
#include <yq-vulqan/typedef/texture.hpp>

#include <set>
#include <variant>

namespace yq {
    class CompoundInfo;
    class TypeInfo;
}

namespace yq::tachyon {
    class ViData;
    class ViPipeline;
    class ViPipelineLayout;
    class ViRendered;

    /*! \brief Pipeline configuration
    
        This is a pipeline configuration.  Once created, can be submitted to the 
        visualizer for a proper VkPipeline.
    */
    class Pipeline : public UniqueID, public RefCount {
    public:

    
        //! Handler to get a buffer from an object
        using fn_buffer     = std::function<BufferCPtr(const void*)>;;
        
        //! Handler to get a texture from an object
        using fn_texture    = std::function<TextureCPtr(const void*)>;
        
        //! Handler to get a push constant from an object
        using fn_push       = std::function<void(const void*, PushBuffer&)>;

        //! Handler to get a revision from an object
        using fn_revision   = std::function<uint64_t(const void*)>;
        
        using role_t        = uint64_t;

        struct attribute_t {
            const TypeInfo* type    = nullptr;
            uint32_t        location    = UINT32_MAX;
            uint32_t        offset      = 0;
            DataFormat      format;
        };
        
        using attribute_vector_t    = std::vector<attribute_t>;

        struct buffer_t {
            fn_buffer       fetch       = {};
            fn_revision     revision    = {};
            DataActivity    activity    = {};
        };
        
        struct array_buffer_t : public buffer_t {
            //! Size of each element in the buffer
            uint32_t  stride      = 0;
        };
        
        
        struct vertex_buffer_t : public array_buffer_t {
            attribute_vector_t  attributes;
            //! Shader mask that this is available for (0 implies ALL shaders)
            uint32_t            shaders     = 0;
            VertexInputRate     inputRate;
        };
        
        struct index_buffer_t : public array_buffer_t {
            IndexType   type = IndexType::none;
        };

        struct uniform_buffer_t : public buffer_t {
            uint32_t  count   = 1;
            uint32_t  shaders = 0;
            uint32_t  size    = 0;
        };
    
        struct storage_buffer_t : public buffer_t {
            uint32_t  count   = 1;
            uint32_t  shaders = 0;
            uint32_t  size    = 0;
        };
        
        struct push_t {
            fn_push         fetch = {};
            fn_revision     revision = {};
            size_t          size;
            
            //! Push type
            PushConfigType  type        = PushConfigType::None;
            
            //! Shader stage(s) to apply this to
            uint32_t        shaders     = 0;            // shader mask (0 implies shaders)
            
        };
        
        struct texture_t {
            fn_texture      fetch = {};
            fn_revision     revision = {};
            //! Expected update activity for this texture
            DataActivity    activity    = {};
            uint32_t        shaders     = 0;            // shader mask (0 implies shaders)
        };
        
        template <typename> class Typed;
        template <typename> class VBOMaker;
        
        Pipeline(role_t r=0);
        Pipeline(const CompoundInfo&, role_t r=0);
        Pipeline(CompoundInfo&&, role_t r=0) = delete;

        PipelineBinding         binding() const { return m_binding; }

        // Always good to call
        std::string_view        compound_name() const;
        // NULL is valid return result
        const CompoundInfo*     compound_type() const { return m_compound; }
        
        CullMode                culling() const { return m_cullMode; }
        FrontFace               front() const { return m_frontFace; }
        float                   line_width() const { return m_lineWidth; }
        PolygonMode             polygons() const { return m_polygonMode; }
        bool                    primitive_restart() const { return m_primitiveRestart; }
        const push_t&           push() const { return m_push; }
        role_t                  role() const;
        Topology                topology() const { return m_topology; }
        bool                    wireframe_permitted() const { return m_wireframePermitted; }

        //  Building out the pipeline
        
        void  binding(PipelineBinding);
        void  culling(CullMode);
        void  front(FrontFace);
        void  line_width(float);
        void  polygons(PolygonMode);
        void  primitive_restart(bool);
        void  shader(ShaderSpec);
        void  shaders(std::initializer_list<ShaderSpec>);
        void  topology(Topology);
        void  wireframe_permitted(bool);

        template <typename T>
        void  push();
        void  push(PushConfigType);
        void  push_full();
        void  push_none();
        void  push_view();

        
        const auto& shaders() const { return m_shaders; }
        const auto& index_buffers() const { return m_indexBuffers; }
        const auto& storage_buffers() const { return m_storageBuffers; }
        const auto& textures() const { return m_textures; }
        const auto& uniform_buffers() const { return m_uniformBuffers; }
        const auto& vertex_buffers() const { return m_vertexBuffers; }
        
    protected:
        friend class ViData;
        friend class ViPipeline;
        friend class ViPipelineLayout;
        friend class ViRendered;

        template <typename V>
        VBOMaker<V>                 vbo_(DataActivity da=DataActivity::UNSURE, uint32_t stages=0);


        ~Pipeline();
        uint32_t                    location_filter(uint32_t loc, uint32_t req);

        template <typename V>
        static index_buffer_t       ibo_(DataActivity da);
        
        template <typename V>
        static storage_buffer_t     sbo_(uint32_t cnt, DataActivity da, uint32_t stages=0);
        template <typename V>
        static uniform_buffer_t     ubo_(uint32_t cnt, DataActivity da, uint32_t stages=0);
        static texture_t            tex_(DataActivity da, uint32_t stages=0);
        
        const CompoundInfo*             m_compound      = nullptr;
        //! Locations used
        std::set<uint32_t>              m_locations;
        role_t                          m_role          = {};
        
        PipelineBinding                 m_binding               = PipelineBinding::Graphics;
        CullMode                        m_cullMode              = CullMode::Back;
        FrontFace                       m_frontFace             = FrontFace::CounterClockwise;
        float                           m_lineWidth             = 1.0;
        PolygonMode                     m_polygonMode           = PolygonMode::Fill;
        bool                            m_primitiveRestart      = false;
        Topology                        m_topology              = Topology::TriangleList;
        bool                            m_wireframePermitted    = true;

        push_t                          m_push                  = {};
        std::vector<index_buffer_t>     m_indexBuffers;
        std::vector<storage_buffer_t>   m_storageBuffers;
        std::vector<ShaderSpec>         m_shaders;
        std::vector<uniform_buffer_t>   m_uniformBuffers;
        std::vector<texture_t>          m_textures;
        std::vector<vertex_buffer_t>    m_vertexBuffers;
    };
}
