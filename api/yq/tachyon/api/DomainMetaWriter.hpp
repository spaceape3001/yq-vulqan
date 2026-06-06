////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Domain.hpp>
#include <yq/tachyon/api/DomainData.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class DomainMeta::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(DomainMeta* lightInfo) : TachyonMeta::Writer<C>(lightInfo)
        {
        }
        
        Writer(DomainMeta& lightInfo) : Writer(&lightInfo)
        {
        }
    };

}
