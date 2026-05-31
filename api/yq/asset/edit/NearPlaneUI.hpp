////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class NearPlaneUI : public UIEditor {
        YQ_OBJECT_DECLARE(NearPlaneUI, UIEditor)
    public:
        NearPlaneUI(UIFlags flags={});
        NearPlaneUI(const NearPlaneUI&);
        
        virtual NearPlaneUI* clone() const;
        
        void    near();
        
        static void init_meta();
    };
}
