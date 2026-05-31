////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Count¹UUI : public UIEditor {
        YQ_OBJECT_DECLARE(Count¹UUI, UIEditor)
    public:
        Count¹UUI(UIFlags flags={});
        Count¹UUI(const Count¹UUI&);
        
        virtual Count¹UUI* clone() const;
        
        void    count();
        
        static void init_meta();
    };
}
