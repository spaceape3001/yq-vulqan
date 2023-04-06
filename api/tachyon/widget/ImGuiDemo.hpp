////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/Widget2.hpp>

namespace yq {
    namespace tachyon {
        namespace widget {
            class ImGuiDemo : public Widget2 {
                YQ_OBJECT_DECLARE(ImGuiDemo, Widget2)
            public:
            
                ImGuiDemo();
                ~ImGuiDemo();
            
                virtual void    imgui_(ViContext&) override;
            };
        }
    }
}
