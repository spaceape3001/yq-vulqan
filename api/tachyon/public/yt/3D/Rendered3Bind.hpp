////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/ID.hpp>
#include <yt/typedef/rendered3.hpp>

namespace yq::tachyon {
    class Rendered³;
    struct TypedID;

    //! Utiltity to bind a viewer to the whatever...
    class Rendered³Bind {
    public:
        Rendered³ID    rendered³() const { return m_rendered³; }
        
    protected:
        constexpr Rendered³Bind(Rendered³ID v) noexcept : m_rendered³(v) {}
        Rendered³Bind(const Rendered³*);
        Rendered³Bind(TypedID);
        virtual ~Rendered³Bind() {}
        
        Rendered³ID const m_rendered³;
    };
}
