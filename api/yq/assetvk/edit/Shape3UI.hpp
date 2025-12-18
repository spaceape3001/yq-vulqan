////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Shape³UI : public UIEditor {
        YQ_OBJECT_DECLARE(Shape³UI, UIEditor)
    public:
        static void init_meta();
    
        Shape³UI(UIFlags flags={});
        Shape³UI(const Shape³UI&);
        ~Shape³UI();
        
        Shape³UI*  clone() const override;
        
        void    auto_center();
        void    normalize();
    };
}
