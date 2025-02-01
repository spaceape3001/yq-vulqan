////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/scene/Light.hpp>
#include <yt/scene/LightData.hpp>
#include <yt/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class LightInfo::Writer : public TachyonInfo::Writer<C> {
    public:
        Writer(LightInfo* lightInfo) : TachyonInfo::Writer<C>(lightInfo)
        {
        }
        
        Writer(LightInfo& lightInfo) : Writer(&lightInfo)
        {
        }
    };

}
