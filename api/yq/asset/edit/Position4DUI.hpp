////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Position⁴DUI : public UIEditor {
        YQ_OBJECT_DECLARE(Position⁴DUI, UIEditor)
    public:
        Position⁴DUI(UIFlags flags={});
        Position⁴DUI(const Position⁴DUI&);
        
        virtual Position⁴DUI* clone() const;
        
        void    position();
        
        static void init_meta();
    };
}
