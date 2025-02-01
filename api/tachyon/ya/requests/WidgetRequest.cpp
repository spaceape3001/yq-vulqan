////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/requests/WidgetRequest.hpp>

#include <yt/msg/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WidgetRequest)

namespace yq::tachyon {
    WidgetRequestInfo::WidgetRequestInfo(std::string_view zName, RequestInfo& base, const std::source_location& sl) :
        RequestInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    WidgetRequest::WidgetRequest(WidgetID v, const Param& p) : Request(p), WidgetBind(v)
    {
    }
    
    WidgetRequest::WidgetRequest(const Widget* v, const Param& p) : Request(p), WidgetBind(v)
    {
    }

    WidgetRequest::~WidgetRequest()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WidgetRequest::init_info()
    {
        auto w = writer<WidgetRequest>();
        w.description("Widget request base class");
    }
}
