////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/requests/GraphicsCardRequest.hpp>
#include <yt/msg/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::GraphicsCardRequest)

namespace yq::tachyon {
    GraphicsCardRequest::GraphicsCardRequest(const Header& h) : Request(h)
    {
    }
    
    GraphicsCardRequest::GraphicsCardRequest(const GraphicsCardRequest&cp, const Header&h) : Request(cp, h)
    {
    }

    GraphicsCardRequest::~GraphicsCardRequest()
    {
    }
    
    void GraphicsCardRequest::init_info()
    {
        auto w = writer<GraphicsCardRequest>();
        w.abstract();
        w.description("Graphics Card Request");
    }
}
