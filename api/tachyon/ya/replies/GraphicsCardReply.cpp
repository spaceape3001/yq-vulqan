////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/replies/GraphicsCardReply.hpp>
#include <tachyon/msg/ReplyInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::GraphicsCardReply)

namespace yq::tachyon {
    GraphicsCardReply::GraphicsCardReply(const Header& h, const RequestCPtr& req) : Reply(h, req)
    {
    }
    
    GraphicsCardReply::GraphicsCardReply(const GraphicsCardReply&cp, const Header&h) : Reply(cp, h)
    {
    }

    GraphicsCardReply::~GraphicsCardReply()
    {
    }
    
    void GraphicsCardReply::init_info()
    {
        auto w = writer<GraphicsCardReply>();
        w.abstract();
        w.description("Graphics Card Reply");
    }
}
