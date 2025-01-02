////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/requests/ViewerRequest.hpp>
#include <yt/typedef/widget.hpp>

namespace yq::tachyon {
    class ViewerWidgetRequest : public ViewerRequest {
        YQ_OBJECT_DECLARE(ViewerWidgetRequest, ViewerRequest)
    public:
    
        struct Param : public ViewerRequest::Param {
        };
        
        /*
            Since this is transferring an actual object, don't think we need to go widget IDs
        */
    
        ViewerWidgetRequest(ViewerID, WidgetPtr, const Param& p = {});
        ViewerWidgetRequest(const Viewer*, WidgetPtr, const Param& p = {});
        virtual ~ViewerWidgetRequest();
        
        static void init_info();
        
        const WidgetPtr&    widget() const { return m_widget; }
        
    private:
        WidgetPtr   m_widget;
    };
}
