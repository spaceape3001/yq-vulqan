////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/light.hpp>

namespace yq::tachyon {
    class Desktop;

    //! Utiltity to bind a viewer to the whatever...
    class DesktopBind {
    public:
        DesktopID    light() const { return m_light; }
        
    protected:
        DesktopBind(DesktopID v) : m_light(v) {}
        DesktopBind(const Desktop* v);
        virtual ~DesktopBind() {}
        
        DesktopID const m_light;
    };
}
