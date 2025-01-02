////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/3D/Light3.hpp>
#include <yq/tachyon/3D/Light3Data.hpp>
#include <yq/tachyon/scene/LightInfoWriter.hpp>

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
