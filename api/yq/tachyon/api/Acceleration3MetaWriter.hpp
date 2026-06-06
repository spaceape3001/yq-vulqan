////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Acceleration3.hpp>
#include <yq/tachyon/api/Acceleration3Data.hpp>
#include <yq/tachyon/api/PhysicsMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Acceleration³Meta::Writer : public PhysicsMeta::Writer<C> {
    public:
        Writer(Acceleration³Meta* myInfo) : PhysicsMeta::Writer<C>(myInfo)
        {
        }
        
        Writer(Acceleration³Meta& myInfo) : Writer(&myInfo)
        {
        }
    };

}
