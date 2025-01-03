////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/requests/WindowRequest.hpp>

namespace yq::tachyon {
    class WindowRefreshRequest : public WindowRequest {
        YQ_OBJECT_DECLARE(WindowRefreshRequest, WindowRequest)
    public:
    
        struct Param : public WindowRequest::Param {
        };
    
        WindowRefreshRequest(WindowID, const Param& p = {});
        WindowRefreshRequest(const Window*, const Param& p = {});
        virtual ~WindowRefreshRequest();
        static void init_info();
    };
}
