////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/ID.hpp>
#include <yt/typedef/window.hpp>

namespace yq::tachyon {
    class Window;
    struct TypedID;

    //! Utiltity to bind a viewer to the whatever...
    class WindowBind {
    public:
        WindowID    window() const { return m_window; }
        
    protected:
        WindowBind(WindowID v) : m_window(v) {}
        WindowBind(const Window*);
        WindowBind(TypedID);
        virtual ~WindowBind() {}
        
        WindowID const m_window;
    };
}
