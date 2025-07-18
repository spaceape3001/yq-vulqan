////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/request/WidgetRequest.hpp>

#include <tachyon/api/RequestMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WidgetRequest)

namespace yq::tachyon {
    WidgetRequest::WidgetRequest(const Header&h) : Request(h)
    {
    }
    
    WidgetRequest::WidgetRequest(const WidgetRequest& cp, const Header&h) : Request(cp, h)
    {
    }

    WidgetRequest::~WidgetRequest()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WidgetRequest::init_meta()
    {
        auto w = writer<WidgetRequest>();
        w.description("Widget request base class");
    }
}
