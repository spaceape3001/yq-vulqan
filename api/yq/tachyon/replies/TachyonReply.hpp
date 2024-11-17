////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Reply.hpp>
#include <yq/tachyon/core/TachyonBind.hpp>

namespace yq::tachyon {
    class Tachyon;
    class TachyonRequest;

    class TachyonReplyInfo : public ReplyInfo {
    public:
        TachyonReplyInfo(std::string_view zName, ReplyInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class TachyonReply : public Reply, public TachyonBind {
        YQ_OBJECT_INFO(TachyonReplyInfo)
        YQ_OBJECT_DECLARE(TachyonReply, Reply)
    public:
    
        struct Param : public Reply::Param {
        };
    
        TachyonReply(const RequestCPtr&, Tachyon*, const Param& p = {});
        virtual ~TachyonReply();
        
        static void init_info();
    };
}
