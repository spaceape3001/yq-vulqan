////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class RangeʷDUI : public UIEditor {
        YQ_OBJECT_DECLARE(RangeʷDUI, UIEditor)
    public:
        RangeʷDUI(UIFlags flags={});
        RangeʷDUI(const RangeʷDUI&);
        
        virtual RangeʷDUI* clone() const;
        
        void    range();
        
        static void init_meta();
    };
}
