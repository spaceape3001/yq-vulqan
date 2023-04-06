////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/gpu/Visualizer.hpp>
#include <tachyon/host/Window.hpp>

struct ImGuiContext;

namespace yq {
    class Object;
    
    namespace tachyon {
        class Widget2;
        
        class Viewer : public Window, public Visualizer {
        public:
        
            /*! \brief Creates the viewer
            */
            Viewer();
            ~Viewer();
            
            /*! \brief Creates & initializes viewer 
            
                \note This one throws a std::error_code if problems occur
            */
            Viewer(const ViewerCreateInfo&vci, Widget2*);
            
            /*! \brief Initializes the viewer
                
                Initializes the viewer to render specified top-level widget
            */
            std::error_code     initialize(const ViewerCreateInfo&vci, Widget2*);
            
            //! Runs the draw sequence
            std::error_code     draw(UiContext&);
            std::error_code     draw();
            
            //! Time (in seconds) of last draw call
            double              draw_time() const { return m_drawTime; }
            
            //! Current frame number
            uint64_t            frame_number() const { return m_frameNumber; }
            
        private:
            void                record(UiContext&) override;

            Widget2*            m_widget        = nullptr;
            ImGuiContext*       m_imgui         = nullptr;
            double              m_drawTime      = 0;
            uint64_t            m_frameNumber   = 0;
            
            virtual void        kill_window() { kill(); }
            void                kill();
            
        };
    }
}
