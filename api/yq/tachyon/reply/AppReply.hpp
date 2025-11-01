////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Reply.hpp>

namespace yq::tachyon {
    class AppRequest;

    class AppReplyMeta : public ReplyMeta {
    public:
        AppReplyMeta(std::string_view zName, ReplyMeta& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class AppReply : public Reply {
        YQ_OBJECT_META(AppReplyMeta)
        YQ_OBJECT_DECLARE(AppReply, Reply)
    public:
    
        AppReply(const Header& h, const RequestCPtr&);
        AppReply(const AppReply&, const Header& h);
        virtual ~AppReply();
        
        static void init_meta();
    };
}
