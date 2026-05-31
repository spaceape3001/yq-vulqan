////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class HeightFieldUI : public UIEditor {
        YQ_OBJECT_DECLARE(HeightFieldUI, UIEditor)
    public:
        HeightFieldUI(UIFlags flags={});
        HeightFieldUI(const HeightFieldUI&);
        
        virtual HeightFieldUI* clone() const;
        
        void    height_field();
        
        static void init_meta();
    };
}
