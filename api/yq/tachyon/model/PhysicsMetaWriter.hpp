////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/model/Physics.hpp>
#include <yq/tachyon/model/PhysicsData.hpp>
#include <yq/tachyon/api/ModelMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class PhysicsMeta::Writer : public ModelMeta::Writer<C> {
    public:
        Writer(PhysicsMeta* physicsInfo) : ModelMeta::Writer<C>(physicsInfo)
        {
        }
        
        Writer(PhysicsMeta& physicsInfo) : Writer(&physicsInfo)
        {
        }
    };

}
