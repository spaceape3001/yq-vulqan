////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Count⁴UUI : public UIEditor {
        YQ_OBJECT_DECLARE(Count⁴UUI, UIEditor)
    public:
        Count⁴UUI(UIFlags flags={});
        Count⁴UUI(const Count⁴UUI&);
        
        virtual Count⁴UUI* clone() const;
        
        void    count();
        
        static void init_meta();
    };
}
