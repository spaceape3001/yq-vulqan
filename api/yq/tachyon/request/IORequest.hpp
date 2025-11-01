////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Request.hpp>
#include <yq/tachyon/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class IORequest : public Request {
        YQ_OBJECT_DECLARE(IORequest, Request)
    public:
    
        static void init_meta();

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
