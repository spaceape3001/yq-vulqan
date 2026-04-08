////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MCamera3.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/api/Camera3.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MCamera3)

namespace yq::tachyon {
    MCamera3::MCamera3(TypedID tid) : MCamera(tid)
    {
    }
    
    MCamera3::~MCamera3()
    {
    }
    
    void MCamera3::init_meta()
    {
        auto w = writer<MCamera3>();
        w.description("Camera³ Qt Binder");
        w.manage<Camera³>();
    }
}


#include "moc_MCamera3.cpp"
