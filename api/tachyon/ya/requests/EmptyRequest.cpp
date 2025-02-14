////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/requests/EmptyRequest.hpp>
#include <yt/msg/RequestInfoWriter.hpp>

namespace yq::tachyon {
    EmptyRequest::EmptyRequest(const Header& h) : Request(h) 
    {
    }
    
    EmptyRequest::EmptyRequest(const EmptyRequest& cp, const Header& h) : Request(cp, h) 
    {
    }
    
    EmptyRequest::~EmptyRequest()
    {
    }

    PostCPtr    EmptyRequest::clone(rebind_k, const Header& h) const 
    {
        return new EmptyRequest(*this, h);
    }
    
    void EmptyRequest::init_info()
    {
        auto w = writer<EmptyRequest>();
        w.description("Empty Request");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::EmptyRequest)
