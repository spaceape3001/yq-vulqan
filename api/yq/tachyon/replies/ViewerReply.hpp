////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Reply.hpp>
#include <yq/tachyon/viewer/ViewerBind.hpp>

namespace yq::tachyon {
    class Viewer;
    class ViewerRequest;

    class ViewerReplyInfo : public post::ReplyInfo {
    public:
        ViewerReplyInfo(std::string_view zName, post::ReplyInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class ViewerReply : public post::Reply, public ViewerBind {
        YQ_OBJECT_INFO(ViewerReplyInfo)
        YQ_OBJECT_DECLARE(ViewerReply, post::Reply)
    public:
    
        struct Param : public post::Reply::Param {
        };
    
        ViewerReply(const post::RequestCPtr&, Viewer*, const Param& p = {});
        virtual ~ViewerReply();
        
        static void init_info();
    };
}
