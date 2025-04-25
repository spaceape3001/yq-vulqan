////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/sim/Model.hpp>
#include <yt/sim/ModelData.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class ModelInfo::Writer : public TachyonInfo::Writer<C> {
    public:
        Writer(ModelInfo* modelInfo) : TachyonInfo::Writer<C>(modelInfo)
        {
        }
        
        Writer(ModelInfo& modelInfo) : Writer(&modelInfo)
        {
        }
    };

}
