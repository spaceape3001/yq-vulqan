////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ModelData.hpp>
#include <yq/tachyon/api/TypedID.hpp>
#include <yq/tachyon/typedef/mass.hpp>
#include <yq/units.hpp>

namespace yq::tachyon {
    class MassSnap : public ModelSnap {
        YQ_OBJECT_DECLARE(MassSnap, ModelSnap)
    public:
    
        Kilogram        mass{};
        
        MassSnap();
        virtual ~MassSnap();
        static void init_meta();
    };
    
    class MassData : public ModelData {
        YQ_OBJECT_DECLARE(MassData, ModelData)
    public:

        MassData();
        virtual ~MassData();
        static void init_meta();
    };
}
