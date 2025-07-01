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
    class LightInfo::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(LightInfo* lightInfo) : TachyonMeta::Writer<C>(lightInfo)
        {
        }
        
        Writer(LightInfo& lightInfo) : Writer(&lightInfo)
        {
        }
    };

}
