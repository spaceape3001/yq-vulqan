////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UICheckBox.hpp>

namespace yq::tachyon {
    class UICheckBox_Simple : public UICheckBox {
        YQ_OBJECT_DECLARE(UICheckBox_Simple, UICheckBox)
    public:
        UICheckBox_Simple(std::string_view, bool value=false, UIFlags={});
        UICheckBox_Simple(const UICheckBox_Simple&);
        ~UICheckBox_Simple();
        
        UICheckBox_Simple* clone() const override;
        bool    get() const override { return m_state; }
        void    set(bool) override;
        
        static void init_meta();
    private:
        bool    m_state = false;
    };
}
