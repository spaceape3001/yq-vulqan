////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class RangeᶻUI : public UIEditor {
        YQ_OBJECT_DECLARE(RangeᶻUI, UIEditor)
    public:
        RangeᶻUI(UIFlags flags={});
        RangeᶻUI(const RangeᶻUI&);
        
        virtual RangeᶻUI* clone() const;
        
        void    range();
        
        static void init_meta();
    };
}
