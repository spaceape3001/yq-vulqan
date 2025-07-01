////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/request/TachyonRequest.hpp>
#include <tachyon/api/RequestMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TachyonRequest)

namespace yq::tachyon {
    TachyonRequest::TachyonRequest(const Header& h) : Request(h)
    {
    }
    
    TachyonRequest::TachyonRequest(const TachyonRequest&cp, const Header&h) : Request(cp, h)
    {
    }

    TachyonRequest::~TachyonRequest()
    {
    }
    
    void TachyonRequest::init_meta()
    {
        auto w = writer<TachyonRequest>();
        w.abstract();
        w.description("Tachyon Request");
    }
}
