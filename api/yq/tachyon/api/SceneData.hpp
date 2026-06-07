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
    class SceneSnap : public TachyonSnap {
        YQ_OBJECT_DECLARE(SceneSnap, TachyonSnap)
    public:
        std::vector<TypedID>    cameras;
        std::vector<TypedID>    lights;
        std::vector<TypedID>    rendereds;
        RGBA4F                  bgcolor = { 0.f, 0.f, 0.f, -1.f };
        
        SceneSnap();
        virtual ~SceneSnap();
        static void init_meta();
    };
    
    class SceneData : public TachyonData {
        YQ_OBJECT_DECLARE(SceneData, TachyonData)
    public:

        SceneData();
        virtual ~SceneData();
        static void init_meta();
    };
}
