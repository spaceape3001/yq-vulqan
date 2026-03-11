////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Position³DUI : public UIEditor {
        YQ_OBJECT_DECLARE(Position³DUI, UIEditor)
    public:
        Position³DUI(UIFlags flags={});
        Position³DUI(const Position³DUI&);
        
        virtual Position³DUI* clone() const;
        
        void    position();
        
        static void init_meta();
    };
}
