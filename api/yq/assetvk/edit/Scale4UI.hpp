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

    class Scale⁴UI : public UIEditor {
        YQ_OBJECT_DECLARE(Scale⁴UI, UIEditor)
    public:
        Scale⁴UI(UIFlags flags={});
        Scale⁴UI(const Scale⁴UI&);
        
        virtual Scale⁴UI* clone() const;
        
        void    scale();
        
        static void init_meta();
    };
}
