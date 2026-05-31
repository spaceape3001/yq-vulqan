////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Count²UUI : public UIEditor {
        YQ_OBJECT_DECLARE(Count²UUI, UIEditor)
    public:
        Count²UUI(UIFlags flags={});
        Count²UUI(const Count²UUI&);
        
        virtual Count²UUI* clone() const;
        
        void    count();
        
        static void init_meta();
    };
}
