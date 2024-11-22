////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/rendered.hpp>

namespace yq::tachyon {
    class Rendered;

    //! Utiltity to bind a viewer to the whatever...
    class RenderedBind {
    public:
        RenderedID    rendered() const { return m_rendered; }
        
    protected:
        RenderedBind(RenderedID v) : m_rendered(v) {}
        RenderedBind(const Rendered* v);
        virtual ~RenderedBind() {}
        
        RenderedID const m_rendered;
    };
}
