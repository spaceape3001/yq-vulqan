////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIToolBar.hpp>

namespace yq::tachyon {
    class UIInputBar : public UIWindow {
        YQ_OBJECT_DECLARE(UIInputBar, UIWindow)
    public:
    
        UIInputBar(std::string_view title={}, UIFlags flags={});
        UIInputBar(const UIInputBar&);
        
        ~UIInputBar();
        
        void                    content() override;
        const std::string&      label() const { return m_label; }
        std::string_view        text() const;
        const char*             title() const override;
        size_t                  capacity() const;
        
        ImGuiInputTextFlags     imflags() const { return m_imFlags; }

        void                    label(set_k, std::string_view);
        void                    text(set_k, std::string_view);
        void                    capacity(set_k, size_t);
        
        static void init_meta();
        
    protected:
        virtual UIInputBar*     clone() const override;

        virtual void            update(flags_k) override;
        virtual void            triggered() override;
        using UIElement::triggered;

    private:
        std::string             m_label;
        std::vector<char>       m_text;
        ImGuiInputTextFlags     m_imFlags;
    };
}
