////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/3D/3DData.hpp>
#include <yt/api/TachyonData.hpp>
#include <yt/scene/SceneData.hpp>
#include <yt/typedef/scene3.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    struct Scene³Snap : public SceneSnap, public ③Snap {
    };
    
    struct Scene³Data : public SceneData, public ③Data {
    };
}

