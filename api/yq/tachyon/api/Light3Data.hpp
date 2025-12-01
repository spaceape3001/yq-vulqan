////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/3DData.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/api/LightData.hpp>
#include <yq/tachyon/typedef/light3.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    struct Light³Snap : public LightSnap, public ③Snap {
        //  Need to capture the full "light function" here...
    };
    
    struct Light³Data : public LightData, public ③Data {
    };
}

