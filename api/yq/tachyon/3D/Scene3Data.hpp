////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/scene/SceneData.hpp>
#include <yt/typedef/scene3.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    struct Scene³Snap : public SceneSnap {
        Spatial³ID      spatial;
    };
    
    struct Scene³Data : public SceneData {
    };
}

