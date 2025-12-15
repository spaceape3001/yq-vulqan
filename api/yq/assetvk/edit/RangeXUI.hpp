////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class RangeˣUI : public UIEditor {
        YQ_OBJECT_DECLARE(RangeˣUI, UIEditor)
    public:
        RangeˣUI(UIFlags flags={});
        RangeˣUI(const RangeˣUI&);
        
        virtual RangeˣUI* clone() const;
        
        void    range();
        
        static void init_meta();
    };
}
