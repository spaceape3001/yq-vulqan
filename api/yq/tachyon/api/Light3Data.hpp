////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/dim/3DData.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/api/LightData.hpp>
#include <yq/tachyon/typedef/light3.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    class Light³Snap : public LightSnap, public ③Snap {
        YQ_OBJECT_DECLARE(Light³Snap, LightSnap)
    public:
        //  Need to capture the full "light function" here...
        
        Light³Snap();
        virtual ~Light³Snap();
        static void init_meta();
    };
    
    class Light³Data : public LightData, public ③Data {
        YQ_OBJECT_DECLARE(Light³Data, LightData)
    public:
        Light³Data();
        virtual ~Light³Data();
        static void init_meta();
    };
}

