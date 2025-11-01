////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UICheckBox.hpp>

namespace yq::tachyon {
    class UICheckBox_Visible : public UICheckBox {
        YQ_OBJECT_DECLARE(UICheckBox_Visible, UICheckBox)
    public:
        UICheckBox_Visible(std::string_view text, uint64_t, UIFlags={});
        UICheckBox_Visible(const UICheckBox_Visible&);
        ~UICheckBox_Visible();
        
        UICheckBox_Visible* clone() const override;
        bool                get() const;
        void                set(bool);
        
        static void init_meta();
    private:
        uint64_t    m_uiElementID   = 0;
    };
}
