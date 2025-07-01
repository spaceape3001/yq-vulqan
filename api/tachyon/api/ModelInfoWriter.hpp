////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Model.hpp>
#include <tachyon/api/ModelData.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class ModelInfo::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(ModelInfo* modelInfo) : TachyonMeta::Writer<C>(modelInfo)
        {
        }
        
        Writer(ModelInfo& modelInfo) : Writer(&modelInfo)
        {
        }
    };

}
