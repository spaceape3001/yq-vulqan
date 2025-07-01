////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Request.hpp>

namespace yq::tachyon {
    class WindowRequest : public Request {
        YQ_OBJECT_DECLARE(WindowRequest, Request)
    public:
    
        static void init_meta();
    
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
