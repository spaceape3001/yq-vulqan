////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Size²UI : public UIEditor {
        YQ_OBJECT_DECLARE(Size²UI, UIEditor)
    public:
        Size²UI(UIFlags flags={});
        Size²UI(const Size²UI&);
        
        virtual Size²UI* clone() const;
        
        void    size();
        
        static void init_meta();
    };
}
