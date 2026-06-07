////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/dim/3DData.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/api/SceneData.hpp>
#include <yq/tachyon/typedef/scene3.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    class Scene³Snap : public SceneSnap, public ③Snap {
        YQ_OBJECT_DECLARE(Scene³Snap, SceneSnap)
    public:
        
        //  Move the mapping functions here...

        Scene³Snap();
        virtual ~Scene³Snap();
        
        static void init_meta();
    };
    
    class Scene³Data : public SceneData, public ③Data {
        YQ_OBJECT_DECLARE(Scene³Data, SceneData)
    public:
        Scene³Data();
        virtual ~Scene³Data();
        static void init_meta();
    };
}

