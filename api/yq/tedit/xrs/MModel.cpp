////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MModel.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/api/Model.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MModel)

namespace yq::tachyon {
    MModel::MModel(TypedID tid) : MTachyon(tid)
    {
    }
    
    MModel::~MModel()
    {
    }
    
    void MModel::init_meta()
    {
        auto w = writer<MModel>();
        w.description("Model Qt Binder");
        w.manage<Model>();
    }
}


#include "moc_MModel.cpp"
