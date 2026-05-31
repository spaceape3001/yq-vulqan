////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Count³UUI : public UIEditor {
        YQ_OBJECT_DECLARE(Count³UUI, UIEditor)
    public:
        Count³UUI(UIFlags flags={});
        Count³UUI(const Count³UUI&);
        
        virtual Count³UUI* clone() const;
        
        void    count();
        
        static void init_meta();
    };
}
