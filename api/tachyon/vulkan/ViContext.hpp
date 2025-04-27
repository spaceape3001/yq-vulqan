////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
//#include <yq/tachyon/preamble.hpp>
#include <vulkan/vulkan_core.h>
#include <yq/core/Ref.hpp>
#include <yq/core/Tristate.hpp>
#include <yq/math/glm.hpp>
#include <yq/typedef/filesystem_path.hpp>
#include <tachyon/gfx/DataFormat.hpp>
#include <tachyon/typedef/pipeline.hpp>
#include <tachyon/typedef/vi_pipeline_manager.hpp>
#include <tachyon/typedef/raster.hpp>
#include <system_error>
#include <variant>

//namespace yq::engine { class Viewer; }
namespace yq::tachyon {

    struct ViFrame0;
    class Visualizer;
    class Viewer;
    //class Window;
    class ViFrame;
    class ViThread;
    class ViFrameThread;
    class ViGui;

    /*! \brief Mutable set of parameters that'll pass through
    
        \note If a caller MODIFIES this, they're obligated to restore before finishing
        
        We're making this structure so consumers can optionally extend with their own 
        custom data
    */
    struct ViContext {
        using snapshot_t    = std::variant<std::monostate, bool, DataFormat, RasterPtr, std::filesystem::path, std::error_code>;
    
        ViContext();
        ~ViContext();
        
        //  If modified, restore before return (or...make copy, use copy)
        
        //! Current command buffer
        VkCommandBuffer     command_buffer      = nullptr;
        
        //! Current command pool (if buffer needed)
        VkCommandPool       command_pool        = nullptr;
        
        //! Current descriptor pool (if allocations are necessary)
        VkDescriptorPool    descriptor_pool     = nullptr;
        
        //! Current frame 
        ViFrame0*           frame0              = nullptr;
        
        //! Current frame thread
        ViFrameThread*      frame_thread        = nullptr;
        
        //! SET if we're in imgui mode
        ViGui*              imgui               = nullptr;

        //! Current pipeline 
        VkPipeline          pipeline            = nullptr;  // last pipeline set

        //! Current pipeline layout
        VkPipelineLayout    pipeline_layout     = nullptr;  // last layout set
        
        //! TRUE if the pipelines need rebuilding (ie, swapchain rebuild occured)
        bool                pipeline_rebuild    = false; 
        
        VkShaderStageFlags  pipeline_shaders    = 0;

        //! Current pipeline manager
        ViPipelineManager*  pipelines           = nullptr;
        
        //! Grabs the previous frame's snapshot
        snapshot_t          snapshot;
        
        //! Current thread
        ViThread*           thread              = nullptr;

        //! Frame tick
        uint64_t            tick                = 0;

        //! Current "time"
        double              time                = 0.;
        
        //! Current viewer
        Viewer*             viewer              = nullptr;
        
        VkViewport          viewport;
        
        //! Current visualizer (may become deprecated TBD?)
        Visualizer*         viz                 = nullptr; 

        //! Current window
        //Window*             window              = nullptr;
        
        //! Set to override wireframe capability
        Tristate            wireframe           = Tristate::INHERIT;
    };
}
