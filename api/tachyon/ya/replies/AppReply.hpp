////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/msg/Reply.hpp>

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
    
        AppReply(const Header& h, const RequestCPtr&);
        AppReply(const AppReply&, const Header& h);
        virtual ~AppReply();
        
        static void init_info();
    };
}
