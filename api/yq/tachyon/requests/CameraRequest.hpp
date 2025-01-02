////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Request.hpp>
#include <yq/tachyon/scene/CameraBind.hpp>

namespace yq::tachyon {
    class Camera;

    class CameraRequestInfo : public RequestInfo {
    public:
        CameraRequestInfo(std::string_view zName, RequestInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class CameraRequest : public Request, public CameraBind {
        YQ_OBJECT_INFO(CameraRequestInfo)
        YQ_OBJECT_DECLARE(CameraRequest, Request)
    public:
    
        struct Param : public Request::Param {
        };
    
        CameraRequest(CameraID, const Param& p = {});
        CameraRequest(const Camera*, const Param& p = {});
        virtual ~CameraRequest();
        static void init_info();
    };
}
