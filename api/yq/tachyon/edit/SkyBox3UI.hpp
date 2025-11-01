////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class SkyBox³UI : public UIEditor {
        YQ_OBJECT_DECLARE(SkyBox³UI, UIEditor)
    public:
        SkyBox³UI(UIFlags flags={});
        SkyBox³UI(const SkyBox³UI&);
        
        virtual SkyBox³UI* clone() const;
        
        static void init_meta();
    };
}
