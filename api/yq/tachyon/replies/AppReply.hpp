////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Reply.hpp>

namespace yq::tachyon {
    class AppRequest;

    class AppReplyInfo : public post::ReplyInfo {
    public:
        AppReplyInfo(std::string_view zName, post::ReplyInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class AppReply : public post::Reply {
        YQ_OBJECT_INFO(AppReplyInfo)
        YQ_OBJECT_DECLARE(AppReply, post::Reply)
    public:
    
        struct Param : public post::Reply::Param {
        };
    
        AppReply(const post::RequestCPtr&, const Param& p = {});
        virtual ~AppReply();
        
        static void init_info();
    };
}
