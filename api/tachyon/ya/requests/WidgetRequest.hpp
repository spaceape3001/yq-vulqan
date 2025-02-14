////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Request.hpp>

namespace yq::tachyon {
    class WidgetRequest : public Request {
        YQ_OBJECT_DECLARE(WidgetRequest, Request)
    public:
    
        static void init_info();

    protected:
        WidgetRequest(const Header&);
        WidgetRequest(const WidgetRequest&, const Header&);
        virtual ~WidgetRequest();
        
    private:
        WidgetRequest(const WidgetRequest&) = delete;
        WidgetRequest(WidgetRequest&&) = delete;
        WidgetRequest& operator=(const WidgetRequest&) = delete;
        WidgetRequest& operator=(WidgetRequest&&) = delete;
    };
}
