////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Request.hpp>

namespace yq::tachyon {
    class WindowRequest : public Request {
        YQ_OBJECT_DECLARE(WindowRequest, Request)
    public:
    
        static void init_info();
    
    protected:

        WindowRequest(const Header&);
        WindowRequest(const WindowRequest&, const Header&);
        virtual ~WindowRequest();
        
    private:
        WindowRequest(const WindowRequest&) = delete;
        WindowRequest(WindowRequest&&) = delete;
        WindowRequest& operator=(const WindowRequest&) = delete;
        WindowRequest& operator=(WindowRequest&&) = delete;
    };
}
