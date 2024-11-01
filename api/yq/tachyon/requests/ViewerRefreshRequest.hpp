////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/requests/ViewerRequest.hpp>

namespace yq::tachyon {
    class ViewerRefreshRequest : public ViewerRequest {
        YQ_OBJECT_DECLARE(ViewerRefreshRequest, ViewerRequest)
    public:
    
        struct Param : public ViewerRequest::Param {
        };
    
        ViewerRefreshRequest(Viewer*, const Param& p = {});
        virtual ~ViewerRefreshRequest();
        static void init_info();
    };
}
