////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ID.hpp>
#include <yt/typedef/rendered3.hpp>

namespace yq::tachyon {
    class Rendered³;

    //! Utiltity to bind a viewer to the whatever...
    class Rendered³Bind {
    public:
        Rendered³ID    rendered³() const { return m_rendered³; }
        
    protected:
        Rendered³Bind(Rendered³ID v) : m_rendered³(v) {}
        Rendered³Bind(const Rendered³* v);
        virtual ~Rendered³Bind() {}
        
        Rendered³ID const m_rendered³;
    };
}
