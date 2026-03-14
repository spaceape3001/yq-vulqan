////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class RangeˣDUI : public UIEditor {
        YQ_OBJECT_DECLARE(RangeˣDUI, UIEditor)
    public:
        RangeˣDUI(UIFlags flags={});
        RangeˣDUI(const RangeˣDUI&);
        
        virtual RangeˣDUI* clone() const;
        
        void    range();
        
        static void init_meta();
    };
}
