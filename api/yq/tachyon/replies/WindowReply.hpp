////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Reply.hpp>
#include <yq/tachyon/viewer/ViewerBind.hpp>

namespace yq::tachyon {
    class WindowRequest;

    class WindowReplyInfo : public post::ReplyInfo {
    public:
        WindowReplyInfo(std::string_view zName, post::ReplyInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class WindowReply : public post::Reply, public ViewerBind {
        YQ_OBJECT_INFO(WindowReplyInfo)
        YQ_OBJECT_DECLARE(WindowReply, post::Reply)
    public:
    
        struct Param : public post::Reply::Param {
        };
    
        WindowReply(const post::RequestCPtr&, Viewer*, const Param& p = {});
        virtual ~WindowReply();
        
        static void init_info();
    };
}
