////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Widget.hpp>

namespace yq::tachyon {
    //! ImGuiDemoWidget widget
    //!
    //! This shows the ImGui demo as a widget
    class ImGuiDemoWidget : public Widget {
        YQ_WIDGET_DECLARE(ImGuiDemoWidget, Widget)
    public:
    
        //! Default constructor
        ImGuiDemoWidget();
        
        //! Default destructor
        ~ImGuiDemoWidget();
    
        //! Imgui render
        virtual void    imgui(ViContext&) override;
        
        static void init_info();
    };
}
