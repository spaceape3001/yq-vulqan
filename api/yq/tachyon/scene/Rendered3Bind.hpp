////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/rendered3.hpp>

namespace yq::tachyon {
    class Rendered3;

    //! Utiltity to bind a viewer to the whatever...
    class Rendered3Bind {
    public:
        Rendered3ID    rendered3() const { return m_rendered3; }
        
    protected:
        Rendered3Bind(Rendered3ID v) : m_rendered3(v) {}
        Rendered3Bind(const Rendered3* v);
        virtual ~Rendered3Bind() {}
        
        Rendered3ID const m_rendered3;
    };
}
