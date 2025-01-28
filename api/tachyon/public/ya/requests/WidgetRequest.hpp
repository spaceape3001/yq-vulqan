////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Request.hpp>
#include <yt/ui/WidgetBind.hpp>

namespace yq::tachyon {
    class WidgetRequestInfo : public RequestInfo {
    public:
        WidgetRequestInfo(std::string_view zName, RequestInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class WidgetRequest : public Request, public WidgetBind {
        YQ_OBJECT_INFO(WidgetRequestInfo)
        YQ_OBJECT_DECLARE(WidgetRequest, Request)
    public:
    
        struct Param : public Request::Param {
        };
    
        WidgetRequest(WidgetID, const Param& p = {});
        WidgetRequest(const Widget*, const Param& p = {});
        virtual ~WidgetRequest();
        static void init_info();
    };
}
