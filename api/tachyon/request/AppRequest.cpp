////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/request/AppRequest.hpp>
#include <tachyon/msg/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AppRequest)

namespace yq::tachyon {
    AppRequest::AppRequest(const Header& h) : Request(h)
    {
    }
    
    AppRequest::AppRequest(const AppRequest&cp, const Header&h) : Request(cp, h)
    {
    }

    AppRequest::~AppRequest()
    {
    }
    
    void AppRequest::init_info()
    {
        auto w = writer<AppRequest>();
        w.abstract();
        w.description("App Request");
    }
}
