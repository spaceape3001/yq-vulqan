////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Light.hpp>
#include <yq/tachyon/api/LightData.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class LightMeta::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(LightMeta* lightInfo) : TachyonMeta::Writer<C>(lightInfo)
        {
        }
        
        Writer(LightMeta& lightInfo) : Writer(&lightInfo)
        {
        }
    };

}
