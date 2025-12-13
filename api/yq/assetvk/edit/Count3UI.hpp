////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Count³UI : public UIEditor {
        YQ_OBJECT_DECLARE(Count³UI, UIEditor)
    public:
        Count³UI(UIFlags flags={});
        Count³UI(const Count³UI&);
        
        virtual Count³UI* clone() const;
        
        void    count();
        
        static void init_meta();
    };
}
