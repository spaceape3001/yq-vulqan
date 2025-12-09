////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class TachyonUI : public UIEditor {
        YQ_OBJECT_DECLARE(TachyonUI, UIEditor)
    public:
        static void init_meta();
    
        TachyonUI(UIFlags flags={});
        TachyonUI(const TachyonUI&);
        ~TachyonUI();
        
        TachyonUI*  clone() const override;
        
        void    id();
        void    edit_mode();
        void    type();
        void    name();
        void    thread();
        void    parent();
    };
}
