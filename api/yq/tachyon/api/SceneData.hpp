////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/api/TypedID.hpp>
#include <yq/tachyon/typedef/scene.hpp>
#include <yq/color/RGBA.hpp>

namespace yq::tachyon {
    struct SceneSnap : public TachyonSnap {
        std::vector<TypedID>    cameras;
        std::vector<TypedID>    lights;
        std::vector<TypedID>    rendereds;
        RGBA4F                  bgcolor = { 0.f, 0.f, 0.f, -1.f };
    };
    
    struct SceneData : public TachyonData {
    };
}
