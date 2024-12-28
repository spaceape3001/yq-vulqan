////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>

namespace yq::tachyon {

    /*! \brief Short for spatial relations (ie transforms)
    
        The Spatial interfaces are the TRANSFORMS only, not
        the full build out (ie, positions, scales, etc)
    */
    class ISpatial {
    public:
        virtual TachyonID   spatial(domain_k) const { return {}; }
        virtual uint8_t     spatial(dimensions_k) const = 0;
        virtual Any         spatial(l2d_k) const = 0;
        virtual Any         spatial(d2l_k) const = 0;
    };
}
