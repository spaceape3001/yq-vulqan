////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Physics.hpp>
#include <yq/tachyon/api/PhysicsData.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class PhysicsMeta::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(PhysicsMeta* physicsInfo) : TachyonMeta::Writer<C>(physicsInfo)
        {
        }
        
        Writer(PhysicsMeta& physicsInfo) : Writer(&physicsInfo)
        {
        }
    };

}
