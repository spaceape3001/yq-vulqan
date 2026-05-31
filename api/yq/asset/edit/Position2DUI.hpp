////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Position²DUI : public UIEditor {
        YQ_OBJECT_DECLARE(Position²DUI, UIEditor)
    public:
        Position²DUI(UIFlags flags={});
        Position²DUI(const Position²DUI&);
        
        virtual Position²DUI* clone() const;
        
        void    position();
        
        static void init_meta();
    };
}
