////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <optional>
#include <vector>
#include <functional>

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
#include <yq-vulqan/typedef/push.hpp>
#include <yq-vulqan/typedef/shader.hpp>
#include <yq-vulqan/typedef/texture.hpp>

namespace yq {
    class CompoundInfo;
}

namespace yq::tachyon {

    //! Gets a buffer from an object
    using FetchBuffer       = std::function<BufferCPtr(const void*)>;

    //using FetchMemory       = const Memory& 

    //! Gets a texture from an object
    using FetchTexture      = std::function<TextureCPtr(const void*)>;

    //! Revision handler
    //! Revision is for those time-altering buffers/textures that don't 
    //! use the buffer system
    using FetchRevision     = std::function<uint64_t(const void*)>;
    
    //! Gets the push data from an object
    using FetchPush         = std::function<void(const void*, PushBuffer&)>;

    /*! \brief Configuration for an attribute of a vertex buffer
    */
    struct VBOAttr {
        const TypeInfo*         type        = nullptr;
        uint32_t                location    = UINT32_MAX;
        uint32_t                offset      = 0;
        DataFormat              format;
    };
    

    struct BaseBOConfig {
        //! Fetch handler to get the buffer from a suitable object
        FetchBuffer             fetch       = {};
        
        FetchRevision           revision    = {};

        //! Expected update activity for this vertex buffer
        DataActivity            activity    = {};
    };
    

    struct ABOConfig : public BaseBOConfig {

        //! Size of each element in the buffer
        uint32_t                stride      = 0;
    };

    /*! \brief Configuration for a Vertex Buffer
    */
    struct VBOConfig : public ABOConfig {
    
        //! VBO attributes
        std::vector<VBOAttr>    attrs;
        
        //! Shader mask that this is available for (0 implies ALL shaders)
        uint32_t                shaders     = 0;
        
        VertexInputRate         inputRate;
    };

    
    struct IBOConfig : public ABOConfig {
        IndexType               type        = IndexType::none;
    };
    

    /*! \brief Configuration for a uniform buffer
    */
    struct UBOConfig  : public BaseBOConfig {
    
        uint32_t                count       = 1;
        uint32_t                shaders     = 0;
        uint32_t                size        = 0;
    };

    /*! \brief Configuration for a storage buffer
    */
    struct SBOConfig  : public BaseBOConfig {
    
        uint32_t                count       = 1;
        uint32_t                shaders     = 0;
        uint32_t                size        = 0;
    };

    /*! \brief Configuration for the push operation
    */
    struct PushConfig {
        //! Fetch for a push constant
        FetchPush               fetch       = {};
        FetchRevision           revision    = {};
        
        //! Size of the push constant data
        size_t                  size        = 0;
        
        //! Push type
        PushConfigType          type        = PushConfigType::None;
        
        //! Shader stage(s) to apply this to
        uint32_t                shaders     = 0;            // shader mask (0 implies shaders)
    };
    
    /*! \brief Texture configuration
    */
    struct TexConfig {
        //! Fetches the texture from the object
        FetchTexture            fetch       = {};
        FetchRevision           revision    = {};
        
        //! Expected update activity for this texture
        DataActivity            activity    = {};
        uint32_t                shaders     = 0;            // shader mask (0 implies shaders)
    };
    
    struct PipelineConfig {
        //! Object that's being bound (optional)
        const CompoundInfo*         object      = nullptr;
        
        //! Shaders for the pipeline
        std::vector<ShaderSpec>     shaders;
        
        //! Vertex buffers for the pipeline
        std::vector<VBOConfig>      vbos;

        //! Index buffers for the pipeline
        std::vector<IBOConfig>      ibos;
        
        //! Storage buffers for the pipeline
        std::vector<SBOConfig>      sbos;

        //! Uniform buffers for the pipeline
        std::vector<UBOConfig>      ubos;
        
        //! Textures for this pipeline
        std::vector<TexConfig>      texs;
        
        //! Expected topology for the pipeline
        Topology                    topology    = Topology::TriangleList;
        
        //! Polygon mode
        PolygonMode                 polymode    = PolygonMode::Fill;
        
        //! Winding order of the polygon/triangle
        FrontFace                   front       = FrontFace::CounterClockwise;
        
        //! Culling mode
        CullMode                    culling     = CullMode::Back;
        
        //! Push configuration
        PushConfig                  push        = {};
        
        //! Type of pipeline binding
        PipelineBinding             binding     = PipelineBinding::Graphics;
        
        //! Object/Pipeline tracking role
        uint16_t                    role        = 0;

        //! Restart the primitives?  See VkPipelineInputAssemblyStateCreateInfo documentation for details
        bool                        primitive_restart   = false;
        
        bool                        wireframe_permitted = true;

        //! Line width in the rasterization
        float                       line_width          = 1.f;

        PipelineConfig();
        ~PipelineConfig();
    };
    
    log4cpp::CategoryStream& operator<<(log4cpp::CategoryStream&, const PipelineConfig&);
    
}
