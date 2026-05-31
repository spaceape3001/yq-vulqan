////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class RangeᶻDUI : public UIEditor {
        YQ_OBJECT_DECLARE(RangeᶻDUI, UIEditor)
    public:
        RangeᶻDUI(UIFlags flags={});
        RangeᶻDUI(const RangeᶻDUI&);
        
        virtual RangeᶻDUI* clone() const;
        
        void    range();
        
        static void init_meta();
    };
}
