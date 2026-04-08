////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MLight3.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/api/Light3.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MLight3)

namespace yq::tachyon {
    MLight3::MLight3(TypedID tid) : MLight(tid)
    {
    }
    
    MLight3::~MLight3()
    {
    }
    
    void MLight3::init_meta()
    {
        auto w = writer<MLight3>();
        w.description("Light³ Qt Binder");
        w.manage<Light³>();
    }
}


#include "moc_MLight3.cpp"
