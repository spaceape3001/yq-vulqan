////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Request.hpp>
#include <yt/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class AppRequest : public Request {
        YQ_OBJECT_DECLARE(AppRequest, Request)
    public:
    
        static void init_info();

    protected:
        AppRequest(const Header&);
        AppRequest(const AppRequest&, const Header&);
        ~AppRequest();
        
    private:
        AppRequest(const AppRequest&) = delete;
        AppRequest(AppRequest&&) = delete;
        AppRequest& operator=(const AppRequest&) = delete;
        AppRequest& operator=(AppRequest&&) = delete;
    };
}
