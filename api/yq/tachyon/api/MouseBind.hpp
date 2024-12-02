////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/mouse.hpp>

namespace yq::tachyon {
    class Mouse;

    //! Utiltity to bind a viewer to the whatever...
    class MouseBind {
    public:
        MouseID    mouse() const { return m_mouse; }
        
    protected:
        MouseBind(MouseID v) : m_mouse(v) {}
        MouseBind(const Mouse* v);
        virtual ~MouseBind() {}
        
        MouseID const m_mouse;
    };
}
