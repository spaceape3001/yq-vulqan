////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/request/SimRequest.hpp>
#include <tachyon/msg/RequestInfoWriter.hpp>

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
    
    void SimRequest::init_info()
    {
        auto w = writer<SimRequest>();
        w.abstract();
        w.description("Sim Request");
    }
}
