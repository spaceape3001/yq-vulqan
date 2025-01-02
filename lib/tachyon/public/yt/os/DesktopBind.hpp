////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ID.hpp>
#include <yt/typedef/desktop.hpp>

namespace yq::tachyon {
    class Desktop;

    //! Utiltity to bind a viewer to the whatever...
    class DesktopBind {
    public:
        DesktopID    desktop() const { return m_desktop; }
        
    protected:
        DesktopBind(DesktopID v) : m_desktop(v) {}
        DesktopBind(const Desktop* v);
        virtual ~DesktopBind() {}
        
        DesktopID const m_desktop;
    };
}
