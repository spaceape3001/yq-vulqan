////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Reply.hpp>
#include <yq/tachyon/camera/CameraBind.hpp>

namespace yq::tachyon {
    class Camera;
    class CameraRequest;

    class CameraReplyInfo : public post::ReplyInfo {
    public:
        CameraReplyInfo(std::string_view zName, post::ReplyInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class CameraReply : public post::Reply, public CameraBind {
        YQ_OBJECT_INFO(CameraReplyInfo)
        YQ_OBJECT_DECLARE(CameraReply, post::Reply)
    public:
    
        struct Param : public post::Reply::Param {
        };
    
        CameraReply(const post::RequestCPtr&, Camera*, const Param& p = {});
        virtual ~CameraReply();
        
        static void init_info();
    };
}
