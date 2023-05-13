////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Widget.hpp>

namespace yq::tachyon {
    class ImGuiDemo : public Widget {
        YQ_OBJECT_DECLARE(ImGuiDemo, Widget)
    public:
    
        ImGuiDemo();
        ~ImGuiDemo();
    
        virtual void    imgui_(ViContext&) override;
    };
}
