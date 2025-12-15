////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class OuterTessellation³UI : public UIEditor {
        YQ_OBJECT_DECLARE(OuterTessellation³UI, UIEditor)
    public:
        OuterTessellation³UI(UIFlags flags={});
        OuterTessellation³UI(const OuterTessellation³UI&);
        
        virtual OuterTessellation³UI* clone() const;
        
        void    outer_tessellation();
        
        static void init_meta();
    };
}
