////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MCamera.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/api/Camera.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MCamera)

namespace yq::tachyon {
    MCamera::MCamera(TypedID tid) : MTachyon(tid)
    {
    }
    
    MCamera::~MCamera()
    {
    }
    
    void MCamera::init_meta()
    {
        auto w = writer<MCamera>();
        w.description("Camera Qt Binder");
        w.manage<Camera>();
    }
}


#include "moc_MCamera.cpp"
