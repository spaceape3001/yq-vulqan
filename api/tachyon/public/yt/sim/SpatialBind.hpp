////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/ID.hpp>
#include <yt/typedef/spatial.hpp>

namespace yq::tachyon {
    class Spatial;

    //! Utiltity to bind a viewer to the whatever...
    class SpatialBind {
    public:
        SpatialID    spatial() const { return m_spatial; }
        
    protected:
        SpatialBind(SpatialID v) : m_spatial(v) {}
        SpatialBind(const Spatial* v);
        virtual ~SpatialBind() {}
        
        SpatialID const m_spatial;
    };
}
