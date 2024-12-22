////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/window.hpp>

namespace yq::tachyon {
    class Window;

    //! Utiltity to bind a viewer to the whatever...
    class WindowBind {
    public:
        WindowID    window() const { return m_window; }
        
    protected:
        WindowBind(WindowID v) : m_window(v) {}
        WindowBind(const Window* v);
        virtual ~WindowBind() {}
        
        WindowID const m_window;
    };
}
