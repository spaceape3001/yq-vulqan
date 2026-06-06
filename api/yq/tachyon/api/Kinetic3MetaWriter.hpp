////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Kinetic3.hpp>
#include <yq/tachyon/api/Kinetic3Data.hpp>
#include <yq/tachyon/api/KineticMetaWriter.hpp>

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
