////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MLayer.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/api/Layer.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MLayer)

namespace yq::tachyon {
    MLayer::MLayer(TypedID tid) : MTachyon(tid)
    {
    }
    
    MLayer::~MLayer()
    {
    }
    
    void MLayer::init_meta()
    {
        auto w = writer<MLayer>();
        w.description("Layer Qt Binder");
        w.manage<Layer>();
    }
}


#include "moc_MLayer.cpp"
