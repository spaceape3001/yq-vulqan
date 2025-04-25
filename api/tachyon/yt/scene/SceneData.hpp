////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/TachyonData.hpp>
#include <yt/api/TypedID.hpp>
#include <tachyon/typedef/scene.hpp>

namespace yq::tachyon {
    struct SceneSnap : public TachyonSnap {
        std::vector<TypedID>    cameras;
        std::vector<TypedID>    lights;
        std::vector<TypedID>    rendereds;
    };
    
    struct SceneData : public TachyonData {
    };
}
