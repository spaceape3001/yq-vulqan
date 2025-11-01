////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Model.hpp>
#include <yq/tachyon/api/ModelData.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class ModelMeta::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(ModelMeta* modelInfo) : TachyonMeta::Writer<C>(modelInfo)
        {
        }
        
        Writer(ModelMeta& modelInfo) : Writer(&modelInfo)
        {
        }
    };

}
