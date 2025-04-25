////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Light.hpp>
#include <tachyon/api/LightData.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>

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
