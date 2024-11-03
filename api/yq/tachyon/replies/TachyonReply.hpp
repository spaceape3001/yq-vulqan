////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Reply.hpp>
#include <yq/tachyon/TachyonBind.hpp>

namespace yq::tachyon {
    class Tachyon;
    class TachyonRequest;

    class TachyonReplyInfo : public post::ReplyInfo {
    public:
        TachyonReplyInfo(std::string_view zName, post::ReplyInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class TachyonReply : public post::Reply, public TachyonBind {
        YQ_OBJECT_INFO(TachyonReplyInfo)
        YQ_OBJECT_DECLARE(TachyonReply, post::Reply)
    public:
    
        struct Param : public post::Reply::Param {
        };
    
        TachyonReply(const post::RequestCPtr&, Tachyon*, const Param& p = {});
        virtual ~TachyonReply();
        
        static void init_info();
    };
}
