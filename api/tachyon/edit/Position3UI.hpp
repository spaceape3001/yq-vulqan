////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Position³UI : public UIEditor {
        YQ_OBJECT_DECLARE(Position³UI, UIEditor)
    public:
        Position³UI(UIFlags flags={});
        Position³UI(const Position³UI&);
        
        virtual Position³UI* clone() const;
        
        void    position();
        
        static void init_info();
    };
}
