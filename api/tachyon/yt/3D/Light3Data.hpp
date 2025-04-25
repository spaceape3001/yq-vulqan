////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/3D/3DData.hpp>
#include <tachyon/api/TachyonData.hpp>
#include <tachyon/api/LightData.hpp>
#include <tachyon/typedef/light3.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    struct Light³Snap : public LightSnap, public ③Snap {
    };
    
    struct Light³Data : public LightData, public ③Data {
    };
}

