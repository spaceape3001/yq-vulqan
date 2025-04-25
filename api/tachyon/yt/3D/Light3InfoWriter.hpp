////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/3D/Light3.hpp>
#include <yt/3D/Light3Data.hpp>
#include <tachyon/api/LightInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Light³Info::Writer : public LightInfo::Writer<C> {
    public:
        Writer(Light³Info* lightInfo) : LightInfo::Writer<C>(lightInfo)
        {
        }
        
        Writer(Light³Info& lightInfo) : Writer(&lightInfo)
        {
        }
    };

}
