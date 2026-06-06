////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/entity/Kinetic3.hpp>
#include <yq/tachyon/entity/Kinetic3Data.hpp>
#include <yq/tachyon/entity/KineticMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Kinetic³Meta::Writer : public KineticMeta::Writer<C> {
    public:
        Writer(Kinetic³Meta* kinInfo) : KineticMeta::Writer<C>(kinInfo)
        {
        }
        
        Writer(Kinetic³Meta& kinInfo) : Writer(&kinInfo)
        {
        }
    };

}
