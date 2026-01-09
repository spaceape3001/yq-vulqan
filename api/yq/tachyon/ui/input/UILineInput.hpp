////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/ui/UIElement.hpp>

namespace yq::tachyon {
    class UILineInputWriter;
    
    class UILineInput : public UIElement {
        YQ_OBJECT_DECLARE(UILineInput, UIElement)
    public:
        using Writer = UILineInputWriter;

        UILineInput(std::string_view label={}, UIFlags flags={});
        UILineInput(const UILineInput&);
        virtual ~UILineInput();
        void                    render();
        const std::string&      label() const { return m_label; }
        std::string_view        text() const;
        const char*             title() const override;
        size_t                  capacity() const;

        static void init_meta();
        
        void                    label(set_k, std::string_view);
        void                    text(set_k, std::string_view);
        void                    capacity(set_k, size_t);
        
    protected:
        virtual UILineInput*     clone() const override;

        virtual void            update(flags_k) override;
        virtual void            triggered() override;
        using UIElement::triggered;

    private:
        std::string             m_label;
        std::vector<char>       m_text;
        ImGuiInputTextFlags     m_imFlags;
    };
}
