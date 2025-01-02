////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/camera3.hpp>

namespace yq::tachyon {
    class Camera³;

    //! Utiltity to bind a viewer to the whatever...
    class Camera³Bind {
    public:
        Camera³ID    camera³() const { return m_camera3; }
        
    protected:
        Camera³Bind(Camera³ID v) : m_camera3(v) {}
        Camera³Bind(const Camera³* v);
        virtual ~Camera³Bind() {}
        
        Camera³ID const m_camera3;
    };
}