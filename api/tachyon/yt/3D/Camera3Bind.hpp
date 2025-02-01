////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/ID.hpp>
#include <yt/typedef/camera3.hpp>

namespace yq::tachyon {
    class Camera³;
    struct TypedID;

    //! Utiltity to bind a viewer to the whatever...
    class Camera³Bind {
    public:
        Camera³ID    camera³() const { return m_camera³; }
        
    protected:
        constexpr Camera³Bind(Camera³ID v) noexcept : m_camera³(v) {}
        Camera³Bind(const Camera³*);
        Camera³Bind(TypedID);
        virtual ~Camera³Bind() {}
        
        Camera³ID const m_camera³;
    };
}
