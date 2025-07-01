////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class FarPlaneUI : public UIEditor {
        YQ_OBJECT_DECLARE(FarPlaneUI, UIEditor)
    public:
        FarPlaneUI(UIFlags flags={});
        FarPlaneUI(const FarPlaneUI&);
        
        virtual FarPlaneUI* clone() const;
        
        void    far();
        
        static void init_meta();
    };
}
