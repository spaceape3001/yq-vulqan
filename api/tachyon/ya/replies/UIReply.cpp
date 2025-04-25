////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/replies/UIReply.hpp>
#include <tachyon/msg/ReplyInfoWriter.hpp>

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
    
    void UIReply::init_info()
    {
        auto w = writer<UIReply>();
        w.abstract();
        w.description("UI Reply");
    }
}
