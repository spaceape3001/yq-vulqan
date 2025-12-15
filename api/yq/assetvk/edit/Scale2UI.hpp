////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Scale²UI : public UIEditor {
        YQ_OBJECT_DECLARE(Scale²UI, UIEditor)
    public:
        Scale²UI(UIFlags flags={});
        Scale²UI(const Scale²UI&);
        
        virtual Scale²UI* clone() const;
        
        void    scale();
        
        static void init_meta();
    };
}
