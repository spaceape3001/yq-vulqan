////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ModelData.hpp>
#include <yq/tachyon/typedef/entity.hpp>

namespace yq::tachyon {
    class EntitySnap : public ModelSnap {
        YQ_OBJECT_DECLARE(EntitySnap, ModelSnap)
    public:
    
        EntitySnap();
        virtual ~EntitySnap();
        static void init_meta();
    };
    
    class EntityData : public ModelData {
        YQ_OBJECT_DECLARE(EntityData, ModelData)
    public:

        EntityData();
        virtual ~EntityData();
        static void init_meta();
    };
}
