////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Size²DUI : public UIEditor {
        YQ_OBJECT_DECLARE(Size²DUI, UIEditor)
    public:
        Size²DUI(UIFlags flags={});
        Size²DUI(const Size²DUI&);
        
        virtual Size²DUI* clone() const;
        
        void    size();
        
        static void init_meta();
    };
}
