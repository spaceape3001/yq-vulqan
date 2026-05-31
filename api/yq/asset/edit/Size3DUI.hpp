////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Size³DUI : public UIEditor {
        YQ_OBJECT_DECLARE(Size³DUI, UIEditor)
    public:
        Size³DUI(UIFlags flags={});
        Size³DUI(const Size³DUI&);
        
        virtual Size³DUI* clone() const;
        
        void    size();
        
        static void init_meta();
    };
}
