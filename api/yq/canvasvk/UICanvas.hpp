////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size2.hpp>
#include <yq/tachyon/ui/UIElement.hpp>
#include <yq/typedef/axbox2.hpp>

namespace yq::tachyon {
    class UICanvasWriter;
    class UICanvas : public UIElement {
        YQ_OBJECT_DECLARE(UICanvas, UIElement)
    public:
        using Writer = UICanvasWriter;
        UICanvas(std::string_view k="##Canvas", UIFlags flags={});
        UICanvas(const UICanvas&);
        ~UICanvas();
        
        virtual UICanvas* clone() const override;
        using UIElement::content;
        virtual void content(const AxBox2F&);
        
        void render() override;
        
        const Size2F&   size() const { return m_size; }
        void            size(set_k, const Size2F&);

        static void init_meta();
    private:
        std::string     m_key;
        Size2F          m_size;
    };
}

