////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Scale³UI : public UIEditor {
        YQ_OBJECT_DECLARE(Scale³UI, UIEditor)
    public:
        Scale³UI(UIFlags flags={});
        Scale³UI(const Scale³UI&);
        
        virtual Scale³UI* clone() const;
        
        void    scale();
        
        static void init_meta();
    };
}
