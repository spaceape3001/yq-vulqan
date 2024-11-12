////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Request.hpp>
#include <yq/tachyon/camera/CameraBind.hpp>

namespace yq::tachyon {
    class Camera;

    class CameraRequestInfo : public post::RequestInfo {
    public:
        CameraRequestInfo(std::string_view zName, post::RequestInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class CameraRequest : public post::Request, public CameraBind {
        YQ_OBJECT_INFO(CameraRequestInfo)
        YQ_OBJECT_DECLARE(CameraRequest, post::Request)
    public:
    
        struct Param : public post::Request::Param {
        };
    
        CameraRequest(Camera*, const Param& p = {});
        virtual ~CameraRequest();
        static void init_info();
    };
}
