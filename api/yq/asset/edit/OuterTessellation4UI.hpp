////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class OuterTessellation⁴UI : public UIEditor {
        YQ_OBJECT_DECLARE(OuterTessellation⁴UI, UIEditor)
    public:
        OuterTessellation⁴UI(UIFlags flags={});
        OuterTessellation⁴UI(const OuterTessellation⁴UI&);
        
        virtual OuterTessellation⁴UI* clone() const;
        
        void    outer_tessellation();
        
        static void init_meta();
    };
}
