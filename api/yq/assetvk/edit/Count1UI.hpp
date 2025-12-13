////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Count¹UI : public UIEditor {
        YQ_OBJECT_DECLARE(Count¹UI, UIEditor)
    public:
        Count¹UI(UIFlags flags={});
        Count¹UI(const Count¹UI&);
        
        virtual Count¹UI* clone() const;
        
        void    count();
        
        static void init_meta();
    };
}
