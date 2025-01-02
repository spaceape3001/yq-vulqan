////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/scene/LightData.hpp>
#include <yq/tachyon/typedef/light3.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    struct Light³Snap : public LightSnap {
        Spatial³ID      spatial;
    };
    
    struct Light³Data : public LightData {
    };
}
