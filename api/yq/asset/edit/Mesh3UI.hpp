////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Mesh³UI : public UIEditor {
        YQ_OBJECT_DECLARE(Mesh³UI, UIEditor)
    public:
        static void init_meta();
    
        Mesh³UI(UIFlags flags={});
        Mesh³UI(const Mesh³UI&);
        ~Mesh³UI();
        
        Mesh³UI*  clone() const override;
        
        void    axis();
    };
}
