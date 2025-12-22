////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TypedID.hpp>
#include <yq/tachyon/ui/UIElement.hpp>

namespace yq::tachyon {
    class LuaInputBarUIWriter;

    class LuaInputBarUI : public UIElement {
        YQ_OBJECT_DECLARE(LuaInputBarUI, UIElement )
    public:
        using Writer = LuaInputBarUIWriter;
    
        LuaInputBarUI(UIFlags flags={});
        LuaInputBarUI(const LuaInputBarUI&);
        virtual ~LuaInputBarUI();

        void                    render();
        const std::string&      label() const { return m_label; }
        std::string_view        text() const;
        const char*             title() const override;
        size_t                  capacity() const;

        void                    label(set_k, std::string_view);
        void                    text(set_k, std::string_view);
        void                    capacity(set_k, size_t);
        
        const tachyon::TypedID& tvm() const { return m_tvm; }
        void                    tvm(set_k, tachyon::TypedID);
        
        static void init_meta();
        
        void                    clear();
        
    protected:
        virtual LuaInputBarUI*     clone() const override;

        virtual void            update(flags_k) override;
        virtual void            triggered() override;
        using UIElement::triggered;

    private:
        std::string             m_label;
        std::vector<char>       m_text;
        ImGuiInputTextFlags     m_imFlags;
        tachyon::TypedID        m_tvm;
    };
}
