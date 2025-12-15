////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class RangeʷUI : public UIEditor {
        YQ_OBJECT_DECLARE(RangeʷUI, UIEditor)
    public:
        RangeʷUI(UIFlags flags={});
        RangeʷUI(const RangeʷUI&);
        
        virtual RangeʷUI* clone() const;
        
        void    range();
        
        static void init_meta();
    };
}
