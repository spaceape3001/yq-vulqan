////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Widget.hpp>

namespace yq::tachyon {
    //! ImGuiDemo widget
    //!
    //! This shows the ImGui demo as a widget
    class ImGuiDemo : public Widget {
        YQ_OBJECT_DECLARE(ImGuiDemo, Widget)
    public:
    
        //! Default constructor
        ImGuiDemo();
        
        //! Default destructor
        ~ImGuiDemo();
    
        //! Imgui render
        virtual void    imgui_(ViContext&) override;
    };
}
