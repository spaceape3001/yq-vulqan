////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/render.hpp>

namespace yq::tachyon {
    class Render3D;

    //! Utiltity to bind a viewer to the whatever...
    class Render3DBind {
    public:
        Render3DID    render³() const { return m_render³; }
        
    protected:
        Render3DBind(Render3DID v) : m_render³(v) {}
        Render3DBind(const Render3D* v);
        virtual ~Render3DBind() {}
        
        Render3DID const m_render³;
    };
}
