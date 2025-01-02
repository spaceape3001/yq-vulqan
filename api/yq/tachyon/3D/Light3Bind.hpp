////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/light3.hpp>

namespace yq::tachyon {
    class Light³;

    //! Utiltity to bind a viewer to the whatever...
    class Light³Bind {
    public:
        Light³ID    light3() const { return m_light3; }
        
    protected:
        Light³Bind(Light³ID v) : m_light3(v) {}
        Light³Bind(const Light³* v);
        virtual ~Light³Bind() {}
        
        Light³ID const m_light3;
    };
}
