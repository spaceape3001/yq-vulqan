////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/request/EmptyRequest.hpp>
#include <yq/tachyon/api/RequestMetaWriter.hpp>

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
    
    void EmptyRequest::init_meta()
    {
        auto w = writer<EmptyRequest>();
        w.description("Empty Request");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::EmptyRequest)
