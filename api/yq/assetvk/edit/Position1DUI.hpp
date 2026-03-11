////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Position¹DUI : public UIEditor {
        YQ_OBJECT_DECLARE(Position¹DUI, UIEditor)
    public:
        Position¹DUI(UIFlags flags={});
        Position¹DUI(const Position¹DUI&);
        
        virtual Position¹DUI* clone() const;
        
        void    position();
        
        static void init_meta();
    };
}
