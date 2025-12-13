////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Position¹UI : public UIEditor {
        YQ_OBJECT_DECLARE(Position¹UI, UIEditor)
    public:
        Position¹UI(UIFlags flags={});
        Position¹UI(const Position¹UI&);
        
        virtual Position¹UI* clone() const;
        
        void    position();
        
        static void init_meta();
    };
}
