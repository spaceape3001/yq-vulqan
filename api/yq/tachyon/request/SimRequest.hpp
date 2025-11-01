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
    class SimRequest : public Request {
        YQ_OBJECT_DECLARE(SimRequest, Request)
    public:
    
        static void init_meta();

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
