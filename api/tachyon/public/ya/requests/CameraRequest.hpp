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
    class CameraRequest : public Request {
        YQ_OBJECT_DECLARE(CameraRequest, Request)
    public:
    
        static void init_info();

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
