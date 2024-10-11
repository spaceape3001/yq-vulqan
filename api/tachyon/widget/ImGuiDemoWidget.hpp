////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/widget/Widget.hpp>

namespace yq::tachyon {
    //! ImGuiDemoWidget widget
    //!
    //! This shows the ImGui demo as a widget
    class ImGuiDemoWidget : public Widget {
        YQ_OBJECT_DECLARE(ImGuiDemoWidget, Widget)
    public:
    
        //! Default constructor
        ImGuiDemoWidget();
        
        //! Default destructor
        ~ImGuiDemoWidget();
    
        //! Imgui render
        virtual void    imgui_(ViContext&) override;
    };
}
