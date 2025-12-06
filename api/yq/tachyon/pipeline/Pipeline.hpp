////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Flags.hpp>
#include <yq/core/Tristate.hpp>

#include <yq/tachyon/keywords.hpp>

#include <yq/tachyon/pipeline/DataActivity.hpp>
#include <yq/tachyon/pipeline/ColorBlend.hpp>
#include <yq/tachyon/pipeline/CullMode.hpp>
#include <yq/tachyon/pipeline/DataFormat.hpp>
#include <yq/tachyon/pipeline/DynamicState.hpp>
#include <yq/tachyon/pipeline/FrontFace.hpp>
#include <yq/tachyon/pipeline/IndexType.hpp>
#include <yq/tachyon/pipeline/PipelineBinding.hpp>
#include <yq/tachyon/pipeline/PolygonMode.hpp>
#include <yq/tachyon/pipeline/PushConfigType.hpp>
#include <yq/tachyon/pipeline/Topology.hpp>
#include <yq/tachyon/pipeline/VertexInputRate.hpp>

#include <yq/tachyon/typedef/buffer.hpp>
#include <yq/tachyon/typedef/pipeline.hpp>
#include <yq/tachyon/typedef/push.hpp>
#include <yq/tachyon/typedef/shader.hpp>
#include <yq/tachyon/typedef/texture.hpp>

#include <set>
#include <optional>
#include <variant>

namespace yq {
    class CompoundMeta;
    class TypeMeta;
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
    class Pipeline {
    public:

        using role_t        = uint16_t;
        using variation_t   = uint16_t;

        /*! \brief Standard roles (can disobey below)
            
            The Role is a variation in layouts; so the attributes,
            buffers, etc can vary on a single rendered object.
            (ie...below has the solid as one option, corners
            as a second option, or textures as a third.)
        */
        //! 
        enum class Role : role_t {
            //! Invalid role (shouldn't ever get back unless no pipeline is available for current rendered)
            Invalid = (role_t) -1,
            
            //! Default pipeline
            Default = 0,
            
            //  Debug pipelines... solid?  

            //! Debug Black
            DbgBlack,

            //! Debug Red
            DbgRed,

            //! Debug Orange
            DbgOrange,

            //! Debug Yellow
            DbgYellow,

            //! Debug Green
            DbgGreen,

            //! Debug Blue
            DbgBlue,

            //! Debug Cyan
            DbgCyan,

            //! Debug Magenta
            DbgMagenta,

            //! Debug Gray
            DbgGray,

            //! Debug White
            DbgWhite,



            //! Single solid color 
            SolidColor,
            
            //! Solid color with lights
            SolidColorLit,
            
            //! Solid color with ray racing
            SolidColorRay,

            //! Color corners
            ColorCorner,

            //! Color corners with lights
            ColorCornerLit,

            //! Corner color with ray tracing
            ColorCornerRay,
            
            //! Regular textured
            Textured,
            
            //! Regular textured with lights
            TexturedLit,

            //! Regular texture with ray tracing
            TexturedRay,

            //! First user-based index (nice & large for future compatibility)
            User = 1001
        };
    
        //! Variation is a tweak to a pipeline while using the same layout 
        //  (This will likely be remapped to subpasses... later)
        enum class Variation : variation_t {
            //! Invalid variation (shouldn't ever get back)
            Invalid         = (variation_t) -1,
            
            //! Default variation... cannot be set
            Default         = 0,
            
            //! First user-based index (nice & large for future compatibility)
            User            = 1001
        };
    
        //! Handler to get a buffer from an object
        using fn_buffer     = std::function<BufferCPtr(const void*)>;;
        
        //! Handler to get a texture from an object
        using fn_texture    = std::function<TextureCPtr(const void*)>;
        
        //! Handler to get a push constant from an object
        using fn_push       = std::function<void(const void*, PushBuffer&)>;

        //! Handler to get a revision from an object
        using fn_revision   = std::function<uint64_t(const void*)>; //< TODO: This MAY be obsolete given current designs (16 JAN 2025)

        struct attribute_t {
            const TypeMeta* type    = nullptr;
            uint32_t        location    = UINT32_MAX;
            uint32_t        offset      = 0;
            DataFormat      format;
        };
        
        using attribute_vector_t    = std::vector<attribute_t>;

        struct buffer_t {
            fn_buffer       fetch       = {};
            fn_revision     revision    = {};
            DataActivity    activity    = {};
            uint32_t        binding     = UINT32_MAX;
            uint32_t        stages      = UINT32_MAX;
        };
        
        struct array_buffer_t : public buffer_t {
            //! Size of each element in the buffer
            uint32_t  stride  = 0;
        };
        
        
        struct vertex_buffer_t : public array_buffer_t {
            attribute_vector_t  attributes;
            VertexInputRate     inputRate;
        };
        
        struct index_buffer_t : public array_buffer_t {
            IndexType   type = IndexType::none;
        };

        struct uniform_buffer_t : public buffer_t {
            uint32_t  count   = 1;
            uint32_t  size    = 0;
        };
    
        struct storage_buffer_t : public buffer_t {
            uint32_t  count   = 1;
            uint32_t  size    = 0;
        };
        
        struct b_config {
            DataActivity    activity    = DataActivity::REFRESH;
            uint32_t        binding     = UINT32_MAX;   //!< Binding within the shader (not to be confused with compute/graphics)
            uint32_t        location    = UINT32_MAX;   //!< Location within the shader
            uint32_t        stages      = UINT32_MAX;   //!< Shader mask
        };
        
        using i_config = b_config;
        using s_config = b_config;
        using t_config = b_config;
        using u_config = b_config;
        using v_config = b_config;
        
        static constexpr const i_config i_common();
        static constexpr const i_config i_dynamic();
        static constexpr const i_config i_fixed();
        static constexpr const i_config i_refresh();
        static constexpr const i_config i_static();
        static constexpr const i_config i_unsure();

        static constexpr const s_config s_common();
        static constexpr const s_config s_dynamic();
        static constexpr const s_config s_fixed();
        static constexpr const s_config s_refresh();
        static constexpr const s_config s_static();
        static constexpr const s_config s_unsure();

        static constexpr const t_config t_common();
        static constexpr const t_config t_dynamic();
        static constexpr const t_config t_fixed();
        static constexpr const t_config t_refresh();
        static constexpr const t_config t_static();
        static constexpr const t_config t_unsure();

        static constexpr const u_config u_common();
        static constexpr const u_config u_dynamic();
        static constexpr const u_config u_fixed();
        static constexpr const u_config u_refresh();
        static constexpr const u_config u_static();
        static constexpr const u_config u_unsure();

        static constexpr const v_config v_common();
        static constexpr const v_config v_dynamic();
        static constexpr const v_config v_fixed();
        static constexpr const v_config v_refresh();
        static constexpr const v_config v_static();
        static constexpr const v_config v_unsure();

        struct push_t {
            fn_push         fetch = {};
            fn_revision     revision = {};
            size_t          size;
            
            //! Push type
            PushConfigType  type        = PushConfigType::None;
            
            //! Shader stage(s) to apply this to
            uint32_t        stages      = UINT32_MAX;
        };
        
        struct texture_t {
            fn_texture      fetch       = {};
            fn_revision     revision    = {};
            //! Expected update activity for this texture
            DataActivity    activity    = {};
            uint32_t        binding     = UINT32_MAX;
            uint32_t        stages      = UINT32_MAX;
        };
        
        template <typename> class Typed;
        template <typename> class VBOMaker;
        
        PipelineBinding         binding() const { return m_binding; }

        // Always good to call
        std::string_view        compound_name() const;
        // NULL is valid return result
        constexpr const CompoundMeta*     compound_type() const { return m_compound; }
        
        ColorBlend              color_blending() const { return m_colorBlend; }
        
        CullMode                culling() const { return m_cullMode; }
        FrontFace               front() const { return m_frontFace; }
        bool                    is_dynamic() const;
        bool                    is_static() const;
        float                   line_width() const { return m_lineWidth; }
        PolygonMode             polygons() const { return m_polygonMode; }
        bool                    primitive_restart() const { return m_primitiveRestart; }
        const push_t&           push() const { return m_push; }
        constexpr Role          role() const { return m_role; }
        Topology                topology() const { return m_topology; }
        bool                    wireframe_permitted() const { return m_wireframePermitted; }
        
        constexpr uint64_t      id() const { return m_id; }

        //  Building out the pipeline

        
        //! Set the pipeline bind point
        //! \note This can NOT be altered by a variation
        void  binding(PipelineBinding);
        
        //! Set color blending
        //! \note Variation supported
        void  color_blending(ColorBlend);
        
        //! Set culling mode
        //! \note Variation supported
        void  culling(CullMode);
        
        //! Set dynamic states
        //! \note This can NOT be altered by a variation
        void  dynamic_state(DynamicState);

        //! Set dynamic states
        //! \note This can NOT be altered by a variation
        void  dynamic_states(std::initializer_list<DynamicState>);
        
        //! Set the front face
        //! \note Variation supported
        void  front(FrontFace);
        
        //! Set the line width
        //!
        //! If left NaN, the default line width will be used.  
        //! \note Variation supported
        void  line_width(float);
        
        //! Set the polygon mode
        //! \note Variation supported
        void  polygons(PolygonMode);
        
        //! Enable primitive restarting
        //! \note This can NOT be altered by a variation
        void  primitive_restart(bool);
        
        //! Set/change the shader
        //! \note Variation supported
        void  shader(ShaderSpec);
        
        //! Set/change the shaders
        //! \note Variation supported
        void  shaders(std::initializer_list<ShaderSpec>);
        
        //! Sets the pipeline's topology
        //! \note This can NOT be altered by a variation
        void  topology(Topology);
        
        //! Permit wireframe mode
        //! \note Variation supported
        void  wireframe_permitted(bool);
        
        /*! \brief Declares an index buffer 
        
            \note THIS routine assumes you're manually doing the import/record step
            \note This can NOT be altered by a variation
            \return Binding/Location (which is the index into the array)
        */
        template <typename V>
        uint32_t    index(const i_config& cc=i_refresh());
        
        /*! \brief Declares a storage buffer
        
            \note THIS routine assumes you're manually doing the import/record step
            \note This can NOT be altered by a variation
            \return Binding/Location (which is the index into the array)
        */
        template <typename V>
        uint32_t    storage(uint32_t cnt, const s_config& cc=s_refresh());

        template <typename V>
        uint32_t    storage(dynamic_k, const s_config& cc=s_refresh());

        /*! \brief Declares a storage buffer
        
            \note THIS routine assumes you're manually doing the import/record step
            \note This can NOT be altered by a variation
            \return Binding/Location (which is the index into the array)
        */
        template <typename V>
        uint32_t    storage(const s_config& cc=s_refresh());

        /*! \brief Declares a uniform buffer
        
            \note THIS routine assumes you're manually doing the import/record step
            \note This can NOT be altered by a variation
            \return Binding/Location (which is the index into the array)
        */
        template <typename V>
        uint32_t    uniform(uint32_t cnt, const u_config& cc=u_refresh());

        /*! \brief Declares a uniform buffer
        
            \note THIS routine assumes you're manually doing the import/record step
            \note This can NOT be altered by a variation
            \return Binding/Location (which is the index into the array)
        */
        template <typename V>
        uint32_t    uniform(const u_config& cc=u_refresh());
        
        /*! \brief Declares a vertex buffer
        
            \note THIS routine assumes you're manually doing the import/record step
            \note This can NOT be altered by a variation
            \return Binding/Location (which is the index into the array)
        */
        template <typename V>
        VBOMaker<V> vertex(const v_config& cc=v_refresh());
        
        /*! \brief Declares a texture
        
            \note THIS routine assumes you're manually doing the import/record step
            \note This can NOT be altered by a variation
            \return Binding/Location (which is the index into the array)
        */
        uint32_t    texture(const t_config& cc=t_refresh());

        /*! \brief Defines the push constant
            \note This can NOT be altered by a variation
        */
        template <typename T>
        void  push();

        /*! \brief Defines the push constant
            \note This can NOT be altered by a variation
        */
        void  push(PushConfigType);

        /*! \brief Defines the push constant
            \note This can NOT be altered by a variation
        */
        void  push_full();

        /*! \brief Defines the push constant
            \note This can NOT be altered by a variation
        */
        void  push_none();

        /*! \brief Defines the push constant
            \note This can NOT be altered by a variation
        */
        void  push_view();

        /*! \brief Defines the push constant
            \note This can NOT be altered by a variation
        */
        void  push_viewproj();

        /*! \brief Defines the push constant
            \note This can NOT be altered by a variation
        */
        void  push_mvp();


        const auto& shaders() const { return m_shaders; }
        const auto& index_buffer() const { return m_indexBuffer; }
        const auto& storage_buffers() const { return m_storageBuffers; }
        const auto& textures() const { return m_textures; }
        const auto& uniform_buffers() const { return m_uniformBuffers; }
        const auto& vertex_buffers() const { return m_vertexBuffers; }
        const auto& dynamic_states() const { return m_dynamicStates; }

        Pipeline(Role r = Role::Default);

        struct VariationData {
            //  Unspecified values inherit from default
            
            /*! \brief Shaders
            
                Specifying these will replace the main shaders.
                
                \note Any missing shader stages will be filled in by 
                the main shaders.  No *NEW* shader stages may be 
                added.
            */
            std::vector<ShaderSpec>     shaders;
            std::optional<CullMode>     cullMode;
            std::optional<FrontFace>    frontFace;
            std::optional<float>        lineWidth;              //! If set, overrides default
            std::optional<float>        lineWidthMultiplier;    //! If set and lineWidth isn't, scales default line width
            std::optional<PolygonMode>  polygonMode;
            std::optional<ColorBlend>   colorBlend;
            Tristate                    wireframePermitted  = Tristate::INHERIT;
        };

        //! Creates/sets the variation for editing.
        //! \note The above modifiers will switch to using the variation, so define default *FIRST*
        //! \return pointer (if valid... null for default/invalid)
        VariationData*    variation(Variation);

        //! Resets the variation to default
        void    variation(reset_k);

        //! Finds/returns pointer (Note, this can get invalidated with map modifications)
        const VariationData*            variation(ptr_k, Variation) const;

    protected:
        friend class ViData;
        friend class ViPipeline;
        friend class ViPipelineLayout;
        friend class ViRendered;

        Pipeline(const CompoundMeta*, Role);
        

        template <typename V>
        VBOMaker<V>                 vbo_(const v_config&);


        virtual ~Pipeline();
        uint32_t                    location_filter(uint32_t loc, uint32_t req);

        template <typename V>
        static index_buffer_t       ibo_(const t_config&);
        
        template <typename V>
        storage_buffer_t            sbo_(uint32_t cnt, const s_config&);
        template <typename V>
        uniform_buffer_t            ubo_(uint32_t cnt, const u_config&);
        texture_t                   tex_(const t_config&);
        
        static uint64_t             _make_id();
        
        const CompoundMeta* const       m_compound;
        const uint64_t                  m_id;
        const Role                      m_role;
        
        
        using VariationMap = std::map<Variation, VariationData>;
        

        //! Locations used
        std::set<uint32_t>              m_locations;
        
        VariationMap                    m_variations;
        VariationData*                  m_variation             = nullptr;
        
        PipelineBinding                 m_binding               = PipelineBinding::Graphics;
        CullMode                        m_cullMode              = CullMode::Back;
        FrontFace                       m_frontFace             = FrontFace::CounterClockwise;
        float                           m_lineWidth             = 1.0;
        PolygonMode                     m_polygonMode           = PolygonMode::Fill;
        bool                            m_primitiveRestart      = false;
        Topology                        m_topology              = Topology::TriangleList;
        bool                            m_wireframePermitted    = true;
        ColorBlend                      m_colorBlend            = ColorBlend::Disabled;

        push_t                          m_push                  = {};
        std::optional<index_buffer_t>   m_indexBuffer;
        std::vector<storage_buffer_t>   m_storageBuffers;
        std::vector<ShaderSpec>         m_shaders;
        std::vector<uniform_buffer_t>   m_uniformBuffers;
        std::vector<texture_t>          m_textures;
        std::vector<vertex_buffer_t>    m_vertexBuffers;
        std::set<DynamicState>          m_dynamicStates;
    };
    
    enum {
        kbLight         = (uint32_t) 0,
        kbMaterial      = (uint32_t) 1,
        kbTexture       = (uint32_t) 2,
        kbNormalMap     = (uint32_t) 3
    };
    

    constexpr const Pipeline::i_config  Pipeline::i_common()
    {
        return { .activity=DataActivity::COMMON };
    }
    
    constexpr const Pipeline::i_config  Pipeline::i_dynamic()
    {
        return { .activity=DataActivity::DYNAMIC };
    }
    
    constexpr const Pipeline::i_config  Pipeline::i_fixed()
    {
        return { .activity=DataActivity::FIXED };
    }
    
    constexpr const Pipeline::i_config  Pipeline::i_refresh()
    {
        return { .activity=DataActivity::REFRESH };
    }

    constexpr const Pipeline::i_config  Pipeline::i_static()
    {
        return { .activity=DataActivity::STATIC };
    }
    
    constexpr const Pipeline::i_config  Pipeline::i_unsure()
    {
        return { .activity=DataActivity::UNSURE };
    }

    constexpr const Pipeline::s_config  Pipeline::s_common()
    {
        return { .activity=DataActivity::COMMON };
    }
    
    constexpr const Pipeline::s_config  Pipeline::s_dynamic()
    {
        return { .activity=DataActivity::DYNAMIC };
    }
    
    constexpr const Pipeline::s_config  Pipeline::s_fixed()
    {
        return { .activity=DataActivity::FIXED };
    }

    constexpr const Pipeline::s_config  Pipeline::s_refresh()
    {
        return { .activity=DataActivity::REFRESH };
    }
    
    constexpr const Pipeline::s_config  Pipeline::s_static()
    {
        return { .activity=DataActivity::STATIC };
    }
    
    constexpr const Pipeline::s_config  Pipeline::s_unsure()
    {
        return { .activity=DataActivity::UNSURE };
    }

    constexpr const Pipeline::t_config  Pipeline::t_common()
    {
        return { .activity=DataActivity::COMMON };
    }
    
    constexpr const Pipeline::t_config  Pipeline::t_dynamic()
    {
        return { .activity=DataActivity::DYNAMIC };
    }
    
    constexpr const Pipeline::t_config  Pipeline::t_fixed()
    {
        return { .activity=DataActivity::FIXED };
    }
    
    constexpr const Pipeline::t_config  Pipeline::t_refresh()
    {
        return { .activity=DataActivity::REFRESH };
    }

    constexpr const Pipeline::t_config  Pipeline::t_static()
    {
        return { .activity=DataActivity::STATIC };
    }
    
    constexpr const Pipeline::t_config  Pipeline::t_unsure()
    {
        return { .activity=DataActivity::UNSURE };
    }

    constexpr const Pipeline::u_config  Pipeline::u_common()
    {
        return { .activity=DataActivity::COMMON };
    }

    constexpr const Pipeline::u_config  Pipeline::u_dynamic()
    {
        return { .activity=DataActivity::DYNAMIC };
    }

    constexpr const Pipeline::u_config  Pipeline::u_fixed()
    {
        return { .activity=DataActivity::FIXED };
    }
    
    constexpr const Pipeline::u_config  Pipeline::u_refresh()
    {
        return { .activity=DataActivity::REFRESH };
    }

    constexpr const Pipeline::u_config  Pipeline::u_static()
    {
        return { .activity=DataActivity::STATIC };
    }

    constexpr const Pipeline::u_config  Pipeline::u_unsure()
    {
        return { .activity=DataActivity::UNSURE };
    }

    constexpr const Pipeline::v_config  Pipeline::v_common()
    {
        return { .activity=DataActivity::COMMON };
    }
    
    constexpr const Pipeline::v_config  Pipeline::v_dynamic()
    {
        return { .activity=DataActivity::DYNAMIC };
    }
    
    constexpr const Pipeline::v_config  Pipeline::v_fixed()
    {
        return { .activity=DataActivity::FIXED };
    }
    
    constexpr const Pipeline::v_config  Pipeline::v_refresh()
    {
        return { .activity=DataActivity::REFRESH };
    }

    constexpr const Pipeline::v_config  Pipeline::v_static()
    {
        return { .activity=DataActivity::STATIC };
    }
    
    constexpr const Pipeline::v_config  Pipeline::v_unsure()
    {
        return { .activity=DataActivity::UNSURE };
    }
    

}
