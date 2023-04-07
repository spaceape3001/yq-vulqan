////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/Widget.hpp>

namespace yq {
    namespace tachyon {
        namespace widget {
            class ImGuiDemo : public Widget {
                YQ_OBJECT_DECLARE(ImGuiDemo, Widget)
            public:
            
                ImGuiDemo();
                ~ImGuiDemo();
            
                virtual void    imgui_(ViContext&) override;
            };
        }
    }
}
