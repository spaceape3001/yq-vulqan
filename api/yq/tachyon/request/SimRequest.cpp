////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/request/SimRequest.hpp>
#include <yq/tachyon/api/RequestMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SimRequest)

namespace yq::tachyon {
    SimRequest::SimRequest(const Header& h) : Request(h)
    {
    }
    
    SimRequest::SimRequest(const SimRequest&cp, const Header&h) : Request(cp, h)
    {
    }

    SimRequest::~SimRequest()
    {
    }
    
    void SimRequest::init_meta()
    {
        auto w = writer<SimRequest>();
        w.abstract();
        w.description("Sim Request");
    }
}
