////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Position²UI : public UIEditor {
        YQ_OBJECT_DECLARE(Position²UI, UIEditor)
    public:
        Position²UI(UIFlags flags={});
        Position²UI(const Position²UI&);
        
        virtual Position²UI* clone() const;
        
        void    position();
        
        static void init_meta();
    };
}
