////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/post/Reply.hpp>

namespace yq::tachyon {
    class AppRequest;

    class AppReplyInfo : public ReplyInfo {
    public:
        AppReplyInfo(std::string_view zName, ReplyInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class AppReply : public Reply {
        YQ_OBJECT_INFO(AppReplyInfo)
        YQ_OBJECT_DECLARE(AppReply, Reply)
    public:
    
        struct Param : public Reply::Param {
        };
    
        AppReply(const RequestCPtr&, const Param& p = {});
        virtual ~AppReply();
        
        static void init_info();
    };
}
