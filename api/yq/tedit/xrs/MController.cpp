////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MController.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/api/Controller.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MController)

namespace yq::tachyon {
    MController::MController(TypedID tid) : MTachyon(tid)
    {
    }
    
    MController::~MController()
    {
    }
    
    void MController::init_meta()
    {
        auto w = writer<MController>();
        w.description("Controller Qt Binder");
        w.manage<Controller>();
    }
}


#include "moc_MController.cpp"
