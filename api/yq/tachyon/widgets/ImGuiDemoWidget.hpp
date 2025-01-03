////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Widget.hpp>

namespace yq::tachyon {
    //! ImGuiDemoWidget widget
    //!
    //! This shows the ImGui demo as a widget
    class ImGuiDemoWidget : public Widget {
        YQ_TACHYON_DECLARE(ImGuiDemoWidget, Widget)
    public:
    
        //! Default constructor
        ImGuiDemoWidget();
        
        //! Default destructor
        ~ImGuiDemoWidget();
    
        //! Imgui render
        virtual void    imgui_(ViContext&) override;
        
        static void init_info();
    };
}
