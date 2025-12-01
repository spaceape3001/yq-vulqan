////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Light3.hpp>

namespace yq::tachyon {
    /*! \brief Omnidirectional light
    
        This light produces no shadows, it's a color & intensity (with zero fadeout)
    */
    class OmniLight³ : public Light³ {
        YQ_TACHYON_DECLARE(OmniLight³, Light³)
    public:
        // TODO, all tentative
    };
}
