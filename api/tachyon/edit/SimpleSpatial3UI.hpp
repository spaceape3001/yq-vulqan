////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class SimpleSpatial³UI : public UIEditor {
        YQ_OBJECT_DECLARE(SimpleSpatial³UI, UIEditor)
    public:
        SimpleSpatial³UI(UIFlags flags={});
        SimpleSpatial³UI(const SimpleSpatial³UI&);
        
        virtual SimpleSpatial³UI* clone() const;
        
        static void init_info();
    };
}
