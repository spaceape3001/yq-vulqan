////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/requests/ViewerRequest.hpp>

namespace yq::tachyon {
    class ViewerCloseRequest : public ViewerRequest {
        YQ_OBJECT_DECLARE(ViewerCloseRequest, ViewerRequest)
    public:
    
        struct Param : public ViewerRequest::Param {
        };
    
        ViewerCloseRequest(Viewer*, const Param& p = {});
        virtual ~ViewerCloseRequest();
        static void init_info();
    };
}
