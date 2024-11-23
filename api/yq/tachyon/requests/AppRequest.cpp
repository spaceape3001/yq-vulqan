////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AppRequest.hpp"

#include <yq/tachyon/api/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AppRequest)

namespace yq::tachyon {
    AppRequestInfo::AppRequestInfo(std::string_view zName, RequestInfo& base, const std::source_location& sl) :
        RequestInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    AppRequest::AppRequest(const Param& p) : Request(p)
    {
    }
    
    AppRequest::~AppRequest()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void AppRequest::init_info()
    {
        auto w = writer<AppRequest>();
        w.description("App request base class");
    }
}
