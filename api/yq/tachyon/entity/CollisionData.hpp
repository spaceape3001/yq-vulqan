////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ModelData.hpp>
#include <yq/tachyon/typedef/collision.hpp>

namespace yq::tachyon {
    class CollisionSnap : public ModelSnap {
        YQ_OBJECT_DECLARE(CollisionSnap, ModelSnap)
    public:
    
        CollisionSnap();
        virtual ~CollisionSnap();
        static void init_meta();
    };
    
    class CollisionData : public ModelData {
        YQ_OBJECT_DECLARE(CollisionData, ModelData)
    public:
        
        CollisionData();
        virtual ~CollisionData();
        static void init_meta();
    };
}
