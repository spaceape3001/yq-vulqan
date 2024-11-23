////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Model.hpp>
#include <yq/tachyon/api/ModelData.hpp>
#include <yq/tachyon/api/TachyonInfoWriter.hpp>

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
