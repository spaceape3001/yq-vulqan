////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/light.hpp>

namespace yq::tachyon {
    class Light;

    //! Utiltity to bind a viewer to the whatever...
    class LightBind {
    public:
        LightID    light() const { return m_light; }
        
    protected:
        LightBind(LightID v) : m_light(v) {}
        LightBind(const Light* v);
        virtual ~LightBind() {}
        
        LightID const m_light;
    };
}
