////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/model/Kinetic.hpp>
#include <yq/tachyon/model/KineticData.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class KineticMeta::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(KineticMeta* kineticInfo) : TachyonMeta::Writer<C>(kineticInfo)
        {
        }
        
        Writer(KineticMeta& kineticInfo) : Writer(&kineticInfo)
        {
        }
    };

}
