////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
//#include <tachyon/preamble.hpp>
#include <vulkan/vulkan_core.h>
#include <yq-toolbox/math/glm.hpp>
#include <yq-vulqan/basic/Tristate.hpp>

//namespace yq::engine { class Viewer; }
namespace yq::tachyon {

    struct ViRendered0;
    struct ViFrame0;
    class Visualizer;
    class Viewer;
    class Window;
    class ViFrame;
    class ViThread;
    class ViFrameThread;

    /*! \brief Mutable set of parameters that'll pass through
    
        \note If a caller MODIFIES this, they're obligated to restore before finishing
        
        We're making this structure so consumers can optionally extend with their own 
        custom data
    */
    struct ViContext {
        Visualizer*         viz() const { return m_viz; }
        VkCommandBuffer     command() const { return m_command; }
        uint64_t            frame_number() const { return m_frameNumber; }
        bool                imgui() const { return m_imgui; }
        
        Viewer*             viewer() const { return m_viewer; }
        Window*             window() const { return m_window; }
        
        Tristate            wireframe() const { return m_wireframe; }
        const glm::dmat4&   world2eye() const { return m_world2eye; }
        double              utime() const { return m_utime; }
        
        ViContext();
        ~ViContext();
        
        
        //  If modified, restore before return (or...make copy, use copy)
        Visualizer*         m_viz           = nullptr; 
        Viewer*             m_viewer        = nullptr;
        Window*             m_window        = nullptr;
        ViFrame0*           m_frame0        = nullptr;
        ViFrameThread*      m_frame_thread  = nullptr;
        ViThread*           m_thread        = nullptr;
        VkCommandBuffer     m_command       = nullptr;
        VkPipeline          m_pipeline      = nullptr;  // last pipeline set
        VkPipelineLayout    m_layout        = nullptr;  // last layout set
        glm::dmat4          m_world2eye;
        uint64_t            m_frameNumber   = 0;
        double              m_utime         = 0.;
        bool                m_imgui         = false;
        bool                m_rebuild       = false;    // rebulid pipelines?
        Tristate            m_wireframe     = Tristate::INHERIT;
    };
}
