////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/ID.hpp>
#include <yt/typedef/light3.hpp>

namespace yq::tachyon {
    class Light³;
    struct TypedID;

    //! Utiltity to bind a viewer to the whatever...
    class Light³Bind {
    public:
        Light³ID    light³() const { return m_light³; }
        
    protected:
        constexpr Light³Bind(Light³ID v) noexcept : m_light³(v) {}
        Light³Bind(const Light³*);
        Light³Bind(TypedID);
        virtual ~Light³Bind() {}
        
        Light³ID const m_light³;
    };
}
