////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Size³UI : public UIEditor {
        YQ_OBJECT_DECLARE(Size³UI, UIEditor)
    public:
        Size³UI(UIFlags flags={});
        Size³UI(const Size³UI&);
        
        virtual Size³UI* clone() const;
        
        void    size();
        
        static void init_meta();
    };
}
