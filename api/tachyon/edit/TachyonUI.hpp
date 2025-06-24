////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class TachyonUI : public UIEditor {
        YQ_OBJECT_DECLARE(TachyonUI, UIEditor)
    public:
        static void init_info();
    
        TachyonUI(UIFlags flags={});
        TachyonUI(const TachyonUI&);
        ~TachyonUI();
        
        TachyonUI*  clone() const override;
        
        void    id();
        void    type();
        void    name();
        void    thread();
    };
}
