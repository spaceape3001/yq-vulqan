////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ModelData.hpp>
#include <yq/tachyon/typedef/kinetic.hpp>

namespace yq::tachyon {
    class KineticSnap : public ModelSnap {
        YQ_OBJECT_DECLARE(KineticSnap, ModelSnap)
    public:
        KineticSnap();
        virtual ~KineticSnap();
        static void init_meta();
    };
    
    class KineticData : public ModelData {
        YQ_OBJECT_DECLARE(KineticData, ModelData)
    public:
        KineticData();
        virtual ~KineticData();
        static void init_meta();
    };
}
