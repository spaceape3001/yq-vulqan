////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/render.hpp>

namespace yq::tachyon {
    class Render³;

    //! Utiltity to bind a viewer to the whatever...
    class Render³Bind {
    public:
        Render³ID    render³() const { return m_render³; }
        
    protected:
        Render³Bind(Render³ID v) : m_render³(v) {}
        Render³Bind(const Render³* v);
        virtual ~Render³Bind() {}
        
        Render³ID const m_render³;
    };
}
