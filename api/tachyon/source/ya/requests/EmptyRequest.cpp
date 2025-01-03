////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/requests/EmptyRequest.hpp>
#include <yt/msg/RequestInfoWriter.hpp>

namespace yq::tachyon {
    EmptyRequest::EmptyRequest(const Param& p) : Request(p) 
    {
    }
    
    EmptyRequest::~EmptyRequest()
    {
    }
    
    void EmptyRequest::init_info()
    {
        auto w = writer<EmptyRequest>();
        w.description("Empty Request");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::EmptyRequest)
