////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/reply/GraphicsCardReply.hpp>
#include <tachyon/api/ReplyMetaWriter.hpp>

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
