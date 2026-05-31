////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Light3.hpp>
#include <yq/tachyon/aspect/AColor.hpp>
#include <yq/tachyon/aspect/ADirection.hpp>
#include <yq/tachyon/aspect/AIntensity.hpp>

namespace yq::tachyon {

    /*! \brief Unidirectional light (x-direction)
    
        This is an unidirectional light that has no fadeout, but can produce shadows. 
        The premise is the light's sufficiently distant or large that it can be
        treated as unidirectional; use a spatial to set the direction (orientation)
    */
    class UniLight³ : public Light³ {
        YQ_TACHYON_DECLARE(UniLight³, Light³)
    public:
    
    
    };
}
