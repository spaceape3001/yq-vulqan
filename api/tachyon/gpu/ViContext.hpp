////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <tachyon/preamble.hpp>
#include <tachyon/gpu/ViPipeline.hpp>
#include <vulkan/vulkan_core.h>
#include <glm/glm.hpp>

namespace yq::engine { class Viewer; }
namespace yq::tachyon {

    /*! \brief Mutable set of parameters that'll pass through
    
        \note If a caller MODIFIES this, they're obligated to restore before finishing
        
        We're making this structure so consumers can optionally extend with their own 
        custom data
    */
    class ViContext {
    public:
        
        using DrawFunction  = std::function<void(ViContext&)>;
    
    
        Visualizer*         viz() const { return m_viz; }
        VkCommandBuffer     command() const { return m_command; }
        uint64_t            frame_number() const { return m_frameNumber; }
        bool                imgui() const { return m_imgui; }
        
        Viewer*             viewer() const { return m_viewer; }
        Window*             window() const { return m_window; }
        
        ViContext();
        ~ViContext();
        
        void    pipeline(const ViPipeline&);
        void    pipeline(const Pipeline&);
    
    private:
        friend class Visualizer;
        friend class Viewer;
        friend class engine::Viewer;    // temporary until we nuke that side
        
        //  If modified, restore before return
        Visualizer*         m_viz           = nullptr;  // yep, back to pointer
        Viewer*             m_viewer        = nullptr;
        Window*             m_window        = nullptr;
        VkCommandBuffer     m_command       = nullptr;
        VkPipeline          m_pipeline      = nullptr;  // last pipeline set
        VkPipelineLayout    m_layout        = nullptr;  // last layout set
        glm::dmat4          m_world2eye;
        uint64_t            m_frameNumber   = 0;
        float               m_utime         = 0.;
        bool                m_imgui         = false;
    };
}
