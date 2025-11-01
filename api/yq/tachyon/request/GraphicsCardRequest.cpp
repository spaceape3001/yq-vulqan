////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/request/GraphicsCardRequest.hpp>
#include <yq/tachyon/api/RequestMetaWriter.hpp>

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
    
    void GraphicsCardRequest::init_meta()
    {
        auto w = writer<GraphicsCardRequest>();
        w.abstract();
        w.description("Graphics Card Request");
    }
}
