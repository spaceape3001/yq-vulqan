////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGB.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/light.hpp>
#include <yq/tachyon/enum/LightType.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {
    struct LightSnap : public TachyonSnap {
    
            // As much as I'd love to have the lights be generic... we have limited GPU bandwidth....
    
        RGB3F       color       = {1., 1., 1. };
        float       intensity   = 1.f;
        LightType   type        = LightType::Unknown;   // unknown will likely be treated as a point light


        //  .......................................
        //  TBD

        //! Geo point (or plane with w as d)
        Vector3F    pt;
        
        //! Direction (with w as a soft corrective power?)
        Vector3F    dir;
        
        Radian      coneAngle   = { 0. };
        double      planeDist   = 0.;

        // primitive strength function
        
        //! constant
        float       f1          = 0.;

        //! ln R factor
        float       fLnR        = 0.;

        //! 1/R factor
        float       fR          = 0.;
        
        //! 1/R2 factor
        float       fR2         = 0.;
        
        
    };
    
    struct LightData : public TachyonData {
    };
}
