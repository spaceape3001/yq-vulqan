////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/requests/WindowRequest.hpp>

namespace yq::tachyon {
    class WindowCloseRequest : public WindowRequest {
        YQ_OBJECT_DECLARE(WindowCloseRequest, WindowRequest)
    public:
    
        struct Param : public WindowRequest::Param {
        };
    
        WindowCloseRequest(WindowID, const Param& p = {});
        WindowCloseRequest(const Window*, const Param& p = {});
        virtual ~WindowCloseRequest();
        static void init_info();
    };
}
