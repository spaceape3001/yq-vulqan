////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Request.hpp>
#include <tachyon/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class IORequest : public Request {
        YQ_OBJECT_DECLARE(IORequest, Request)
    public:
    
        static void init_info();

    protected:
        IORequest(const Header&);
        IORequest(const IORequest&, const Header&);
        ~IORequest();
        
    private:
        IORequest(const IORequest&) = delete;
        IORequest(IORequest&&) = delete;
        IORequest& operator=(const IORequest&) = delete;
        IORequest& operator=(IORequest&&) = delete;
    };
}
