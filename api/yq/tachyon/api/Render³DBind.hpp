////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/render.hpp>

namespace yq::tachyon {
    class Render³D;

    //! Utiltity to bind a viewer to the whatever...
    class Render³DBind {
    public:
        Render³DID    render³() const { return m_render³; }
        
    protected:
        Render³DBind(Render³DID v) : m_render³(v) {}
        Render³DBind(const Render³D* v);
        virtual ~Render³DBind() {}
        
        Render³DID const m_render³;
    };
}
