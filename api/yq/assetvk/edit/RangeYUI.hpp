////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class RangeʸUI : public UIEditor {
        YQ_OBJECT_DECLARE(RangeʸUI, UIEditor)
    public:
        RangeʸUI(UIFlags flags={});
        RangeʸUI(const RangeʸUI&);
        
        virtual RangeʸUI* clone() const;
        
        void    range();
        
        static void init_meta();
    };
}
