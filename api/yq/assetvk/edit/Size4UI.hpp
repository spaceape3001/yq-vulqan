////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Size⁴UI : public UIEditor {
        YQ_OBJECT_DECLARE(Size⁴UI, UIEditor)
    public:
        Size⁴UI(UIFlags flags={});
        Size⁴UI(const Size⁴UI&);
        
        virtual Size⁴UI* clone() const;
        
        void    size();
        
        static void init_meta();
    };
}
