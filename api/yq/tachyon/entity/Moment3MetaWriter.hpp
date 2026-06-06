////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/entity/Moment3.hpp>
#include <yq/tachyon/entity/Moment3Data.hpp>
#include <yq/tachyon/entity/MomentMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Moment³Meta::Writer : public MomentMeta::Writer<C> {
    public:
        Writer(Moment³Meta* myInfo) : MomentMeta::Writer<C>(myInfo)
        {
        }
        
        Writer(Moment³Meta& myInfo) : Writer(&myInfo)
        {
        }
    };

}
