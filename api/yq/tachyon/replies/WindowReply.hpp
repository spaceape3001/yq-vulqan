////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/post/Reply.hpp>
#include <yq/tachyon/viewer/ViewerBind.hpp>

namespace yq::tachyon {
    class WindowRequest;

    class WindowReplyInfo : public ReplyInfo {
    public:
        WindowReplyInfo(std::string_view zName, ReplyInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class WindowReply : public Reply, public ViewerBind {
        YQ_OBJECT_INFO(WindowReplyInfo)
        YQ_OBJECT_DECLARE(WindowReply, Reply)
    public:
    
        struct Param : public Reply::Param {
        };
    
        WindowReply(const RequestCPtr&, Viewer*, const Param& p = {});
        virtual ~WindowReply();
        
        static void init_info();
    };
}
