////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class FieldOfViewUI : public UIEditor {
        YQ_OBJECT_DECLARE(FieldOfViewUI, UIEditor)
    public:
        FieldOfViewUI(UIFlags flags={});
        FieldOfViewUI(const FieldOfViewUI&);
        
        virtual FieldOfViewUI* clone() const;
        
        void    fov();
        
        static void init_info();
    };
}
