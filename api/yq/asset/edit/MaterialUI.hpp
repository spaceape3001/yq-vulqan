////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class MaterialUI : public UIEditor {
        YQ_OBJECT_DECLARE(MaterialUI, UIEditor)
    public:
        MaterialUI(UIFlags flags={});
        MaterialUI(const MaterialUI&);
        
        virtual MaterialUI* clone() const;
        
        void    material();
        
        static void init_meta();
    };
}
