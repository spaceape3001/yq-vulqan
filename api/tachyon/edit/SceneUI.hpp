////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class SceneUI : public UIEditor {
        YQ_OBJECT_DECLARE(SceneUI, UIEditor)
    public:
        static void init_info();
    
        SceneUI(UIFlags flags={});
        SceneUI(const SceneUI&);
        ~SceneUI();
        
        SceneUI*  clone() const override;
        
        void    bgcolor();
    };
}
