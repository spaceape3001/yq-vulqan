////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Light3.hpp>
#include <tachyon/api/Light3Data.hpp>
#include <tachyon/api/LightMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Light³Info::Writer : public LightMeta::Writer<C> {
    public:
        Writer(Light³Info* lightInfo) : LightMeta::Writer<C>(lightInfo)
        {
        }
        
        Writer(Light³Info& lightInfo) : Writer(&lightInfo)
        {
        }
    };

}
