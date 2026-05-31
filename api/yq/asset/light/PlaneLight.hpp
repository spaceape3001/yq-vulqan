////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Light3.hpp>
#include <yq/tachyon/aspect/AColor.hpp>
#include <yq/tachyon/aspect/AIntensity.hpp>

namespace yq::tachyon {
    /*! \brief Plane Light
    
        This is a planar light... acts in the x-direction until a 
        spatial is attached.
    */
    class PlaneLight³ : public Light³ {
        YQ_TACHYON_DECLARE(PlaneLight, Light³)
    public:
        //  TODO
        
    };
}
