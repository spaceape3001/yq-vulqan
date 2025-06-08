////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Position⁴UI : public UIEditor {
        YQ_OBJECT_DECLARE(Position⁴UI, UIEditor)
    public:
        Position⁴UI(UIFlags flags={});
        Position⁴UI(const Position⁴UI&);
        
        virtual Position⁴UI* clone() const;
        
        void    position();
        
        static void init_info();
    };
}
