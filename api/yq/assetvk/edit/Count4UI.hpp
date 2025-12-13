////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Count⁴UI : public UIEditor {
        YQ_OBJECT_DECLARE(Count⁴UI, UIEditor)
    public:
        Count⁴UI(UIFlags flags={});
        Count⁴UI(const Count⁴UI&);
        
        virtual Count⁴UI* clone() const;
        
        void    count();
        
        static void init_meta();
    };
}
