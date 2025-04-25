////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/TachyonData.hpp>
#include <tachyon/api/TypedID.hpp>
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
