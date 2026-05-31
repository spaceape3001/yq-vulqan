////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Size⁴DUI : public UIEditor {
        YQ_OBJECT_DECLARE(Size⁴DUI, UIEditor)
    public:
        Size⁴DUI(UIFlags flags={});
        Size⁴DUI(const Size⁴DUI&);
        
        virtual Size⁴DUI* clone() const;
        
        void    size();
        
        static void init_meta();
    };
}
