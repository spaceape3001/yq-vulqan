////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "XGController.hpp"
#include <yq/tachyon/api/ControllerMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::XGController)

namespace yq::tachyon {
    XGController::XGController()
    {
    }
    
    XGController::~XGController()
    {
    }
        
    void XGController::init_meta()
    {
        auto w = writer<XGController>();
        w.description("Executive Graph Controller");
    }
}
