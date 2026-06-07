////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ModelData.hpp>
#include <yq/tachyon/typedef/moment3.hpp>
#include <yq/vector/Vector3.hpp>
#include <yq/units.hpp>

namespace yq::tachyon {
    class Moment³Snap : public ModelSnap {
        YQ_OBJECT_DECLARE(Moment³Snap, ModelSnap)
    public:
        Moment³Snap();
        virtual ~Moment³Snap();
        static void init_meta();
    };
    
    class Moment³Data : public ModelData {
        YQ_OBJECT_DECLARE(Moment³Data, ModelData)
    public:
        Moment³Data();
        virtual ~Moment³Data();
        static void init_meta();
    };
}
