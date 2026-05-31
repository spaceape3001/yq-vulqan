////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class BgColorUI : public UIEditor {
        YQ_OBJECT_DECLARE(BgColorUI, UIEditor)
    public:
        BgColorUI(UIFlags flags={});
        BgColorUI(const BgColorUI&);
        
        virtual BgColorUI* clone() const;
        
        void    bgcolor();
        
        static void init_meta();
    };
}
