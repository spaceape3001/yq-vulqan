////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/requests/WindowRequest.hpp>

namespace yq::tachyon {
    class WindowRefreshRequest : public WindowRequest {
        YQ_OBJECT_DECLARE(WindowRefreshRequest, WindowRequest)
    public:
    
        struct Param : public WindowRequest::Param {
        };
    
        WindowRefreshRequest(ViewerID, const Param& p = {});
        WindowRefreshRequest(const Viewer*, const Param& p = {});
        virtual ~WindowRefreshRequest();
        static void init_info();
    };
}
