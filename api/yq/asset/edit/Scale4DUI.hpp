////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    /*
        LOL... edit for a proxy/interface not yet needed, retaining the code
    */

    class Scale⁴DUI : public UIEditor {
        YQ_OBJECT_DECLARE(Scale⁴DUI, UIEditor)
    public:
        Scale⁴DUI(UIFlags flags={});
        Scale⁴DUI(const Scale⁴DUI&);
        
        virtual Scale⁴DUI* clone() const;
        
        void    scale();
        
        static void init_meta();
    };
}
