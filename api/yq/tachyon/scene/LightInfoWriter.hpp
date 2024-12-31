////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/scene/Light.hpp>
#include <yq/tachyon/scene/LightData.hpp>
#include <yq/tachyon/api/TachyonInfoWriter.hpp>

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
