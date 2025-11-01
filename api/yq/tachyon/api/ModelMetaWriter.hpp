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
