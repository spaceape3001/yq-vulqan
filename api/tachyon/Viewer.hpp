////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/gpu/Visualizer.hpp>
#include <tachyon/host/Window.hpp>
#include <basic/Flags.hpp>

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
            std::error_code     draw(ViContext&);
            std::error_code     draw();
            
            //! Time (in seconds) of last draw call
            double              draw_time() const { return m_drawTime; }
            
            //! Current frame number
            uint64_t            frame_number() const { return tick(); }
            
        protected:
            virtual void        window_framebuffer_resized(const Size2I&) override;
            virtual void        window_resized(const Size2I&) override;
            
        private:
            void                record(ViContext&) override;

            Widget2*            m_widget        = nullptr;
            ImGuiContext*       m_imgui         = nullptr;
            double              m_drawTime      = 0;
            
            virtual void        kill_window() { kill(); }
            void                kill();
        };
    }
}
