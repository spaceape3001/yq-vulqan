////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/3DData.hpp>
#include <tachyon/api/TachyonData.hpp>
#include <tachyon/api/SceneData.hpp>
#include <tachyon/typedef/scene3.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    struct Scene³Snap : public SceneSnap, public ③Snap {
        Scene³Snap();
        virtual ~Scene³Snap();
    };
    
    struct Scene³Data : public SceneData, public ③Data {
        Scene³Data();
        virtual ~Scene³Data();
    };
}

