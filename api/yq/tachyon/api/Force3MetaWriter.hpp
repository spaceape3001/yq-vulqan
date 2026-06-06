////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Force3.hpp>
#include <yq/tachyon/api/Force3Data.hpp>
#include <yq/tachyon/api/PhysicsMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Force³Meta::Writer : public PhysicsMeta::Writer<C> {
    public:
        Writer(Force³Meta* myInfo) : PhysicsMeta::Writer<C>(myInfo)
        {
        }
        
        Writer(Force³Meta& myInfo) : Writer(&myInfo)
        {
        }
    };

}
