////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Request.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class CameraRequest : public Request {
        YQ_OBJECT_DECLARE(CameraRequest, Request)
    public:
    
        static void init_meta();

    protected:
        CameraRequest(const Header&);
        CameraRequest(const CameraRequest&, const Header&);
        ~CameraRequest();
        
    private:
        CameraRequest(const CameraRequest&) = delete;
        CameraRequest(CameraRequest&&) = delete;
        CameraRequest& operator=(const CameraRequest&) = delete;
        CameraRequest& operator=(CameraRequest&&) = delete;
    };
}
