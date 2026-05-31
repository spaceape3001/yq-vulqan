////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class RangeʸDUI : public UIEditor {
        YQ_OBJECT_DECLARE(RangeʸDUI, UIEditor)
    public:
        RangeʸDUI(UIFlags flags={});
        RangeʸDUI(const RangeʸDUI&);
        
        virtual RangeʸDUI* clone() const;
        
        void    range();
        
        static void init_meta();
    };
}
