////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/msg/Request.hpp>
#include <tachyon/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SimRequest : public Request {
        YQ_OBJECT_DECLARE(SimRequest, Request)
    public:
    
        static void init_info();

    protected:
        SimRequest(const Header&);
        SimRequest(const SimRequest&, const Header&);
        ~SimRequest();
        
    private:
        SimRequest(const SimRequest&) = delete;
        SimRequest(SimRequest&&) = delete;
        SimRequest& operator=(const SimRequest&) = delete;
        SimRequest& operator=(SimRequest&&) = delete;
    };
}
