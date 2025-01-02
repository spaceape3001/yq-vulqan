////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/spatial3.hpp>

namespace yq::tachyon {
    class Spatial³;

    //! Utiltity to bind a viewer to the whatever...
    class Spatial³Bind {
    public:
        Spatial³ID    spatial³() const { return m_spatial³; }
        
    protected:
        Spatial³Bind(Spatial³ID v) : m_spatial³(v) {}
        Spatial³Bind(const Spatial³* v);
        virtual ~Spatial³Bind() {}
        
        Spatial³ID const m_spatial³;
    };
}
