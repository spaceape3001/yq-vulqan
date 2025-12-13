////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Count²UI : public UIEditor {
        YQ_OBJECT_DECLARE(Count²UI, UIEditor)
    public:
        Count²UI(UIFlags flags={});
        Count²UI(const Count²UI&);
        
        virtual Count²UI* clone() const;
        
        void    count();
        
        static void init_meta();
    };
}
