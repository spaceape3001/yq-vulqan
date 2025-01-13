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
    class UIRequest : public Request {
        YQ_OBJECT_DECLARE(UIRequest, Request)
    public:
    
        static void init_info();

    protected:
        UIRequest(const Header&);
        UIRequest(const UIRequest&, const Header&);
        ~UIRequest();
        
    private:
        UIRequest(const UIRequest&) = delete;
        UIRequest(UIRequest&&) = delete;
        UIRequest& operator=(const UIRequest&) = delete;
        UIRequest& operator=(UIRequest&&) = delete;
    };
}
