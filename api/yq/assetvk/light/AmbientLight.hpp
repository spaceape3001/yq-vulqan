////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Light.hpp>

namespace yq::tachyon {
    /*! \brief Ambient light
    
        This light produces no shadows, it's a color & intensity (with zero fadeout)
    */
    class AmbientLight : public Light {
        YQ_TACHYON_DECLARE(AmbientLight, Light)
    public:
        // TODO, all tentative
        
        AmbientLight();
        ~AmbientLight();
        static void init_meta();
    protected:
        void        snap(LightSnap&) const;
    };
}
