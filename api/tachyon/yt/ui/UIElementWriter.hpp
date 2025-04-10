////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/enum/UIFlags.hpp>

namespace yq::tachyon {
    class UIElement;
    
    class UIElementWriter {
    public:
    
        UIElementWriter();
        UIElementWriter(UIElement*);
        UIElementWriter(const UIElementWriter&);
        ~UIElementWriter();

        UIElement*      element() { return m_ui; }

        void        flag(set_k, UIFlag);
        void        flag(set_k, UIFlags);
        void        flag(clear_k, UIFlag);
        void        flag(clear_k, UIFlags);

    protected:
        UIElement*      m_ui    = nullptr;
    };
}
