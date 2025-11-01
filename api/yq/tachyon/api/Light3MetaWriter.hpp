////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Light3.hpp>
#include <yq/tachyon/api/Light3Data.hpp>
#include <yq/tachyon/api/LightMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Light³Meta::Writer : public LightMeta::Writer<C> {
    public:
        Writer(Light³Meta* lightInfo) : LightMeta::Writer<C>(lightInfo)
        {
        }
        
        Writer(Light³Meta& lightInfo) : Writer(&lightInfo)
        {
        }
    };

}
