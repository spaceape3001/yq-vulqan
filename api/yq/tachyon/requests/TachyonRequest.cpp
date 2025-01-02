////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TachyonRequest.hpp"

#include <yt/msg/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TachyonRequest)

namespace yq::tachyon {
    TachyonRequestInfo::TachyonRequestInfo(std::string_view zName, RequestInfo& base, const std::source_location& sl) :
        RequestInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    TachyonRequest::TachyonRequest(TachyonID v, const Param& p) : Request(p), TachyonBind(v)
    {
    }
    
    TachyonRequest::TachyonRequest(const Tachyon* v, const Param& p) : Request(p), TachyonBind(v)
    {
    }
    
    TachyonRequest::~TachyonRequest()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void TachyonRequest::init_info()
    {
        auto w = writer<TachyonRequest>();
        w.description("Tachyon request base class");
    }
}
