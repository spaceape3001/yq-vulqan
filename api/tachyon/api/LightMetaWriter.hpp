////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Light.hpp>
#include <tachyon/api/LightData.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>

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
