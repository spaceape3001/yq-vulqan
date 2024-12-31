////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/rendered3.hpp>

namespace yq::tachyon {
    class Rendered³;

    //! Utiltity to bind a viewer to the whatever...
    class Rendered³Bind {
    public:
        Rendered³ID    rendered3() const { return m_rendered3; }
        
    protected:
        Rendered³Bind(Rendered³ID v) : m_rendered3(v) {}
        Rendered³Bind(const Rendered³* v);
        virtual ~Rendered³Bind() {}
        
        Rendered³ID const m_rendered3;
    };
}
