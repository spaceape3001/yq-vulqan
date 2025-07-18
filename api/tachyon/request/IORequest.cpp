////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/request/IORequest.hpp>
#include <tachyon/api/RequestMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::IORequest)

namespace yq::tachyon {
    IORequest::IORequest(const Header& h) : Request(h)
    {
    }
    
    IORequest::IORequest(const IORequest&cp, const Header&h) : Request(cp, h)
    {
    }

    IORequest::~IORequest()
    {
    }
    
    void IORequest::init_meta()
    {
        auto w = writer<IORequest>();
        w.abstract();
        w.description("IO Request");
    }
}
