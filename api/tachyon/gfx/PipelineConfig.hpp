////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <optional>
#include <vector>
#include <tachyon/preamble.hpp>
#include <functional>

#include <tachyon/enum/CullMode.hpp>
#include <tachyon/enum/DataActivity.hpp>
#include <tachyon/enum/DataFormat.hpp>
#include <tachyon/enum/FrontFace.hpp>
#include <tachyon/enum/IndexType.hpp>
#include <tachyon/enum/PipelineBinding.hpp>
#include <tachyon/enum/PolygonMode.hpp>
#include <tachyon/enum/PushConfigType.hpp>
#include <tachyon/enum/Topology.hpp>
#include <tachyon/enum/VertexInputRate.hpp>

namespace yq::tachyon {

    //! Gets a buffer from an object
    using FetchBuffer       = std::function<BufferCPtr(const void*)>;

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
        DataFormat              format;
        uint32_t                location    = UINT32_MAX;
        uint32_t                offset      = 0;
    };

    struct ABOConfig {
        //! Fetch handler to get the buffer from a suitable object
        FetchBuffer             fetch       = {};
        
        FetchRevision           revision    = {};

        //! Size of each element in the buffer
        uint32_t                stride      = 0;

        //! Expected update activity for this vertex buffer
        DataActivity            activity    = {};
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
    struct UBOConfig {
    
        //! Fetch for a uniform buffer object
        FetchBuffer             fetch       = {};
        FetchRevision           revision    = {};
        
        uint32_t                count       = 1;
        uint32_t                stage       = 0;
        uint32_t                size        = 0;

        //! Expected update activity for this uniform buffer
        DataActivity            activity    = {};
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
        
        //! Binding point for the texture
        uint32_t                binding     = 0;
        
        //! Expected update activity for this texture
        DataActivity            activity    = {};
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

        PipelineConfig();
        ~PipelineConfig();
    };
}
