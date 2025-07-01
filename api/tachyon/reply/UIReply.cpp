////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/reply/UIReply.hpp>
#include <tachyon/api/ReplyMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIReply)

namespace yq::tachyon {
    UIReply::UIReply(const Header& h, const RequestCPtr& req) : Reply(h, req)
    {
    }
    
    UIReply::UIReply(const UIReply&cp, const Header&h) : Reply(cp, h)
    {
    }

    UIReply::~UIReply()
    {
    }
    
    void UIReply::init_meta()
    {
        auto w = writer<UIReply>();
        w.abstract();
        w.description("UI Reply");
    }
}
