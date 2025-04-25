////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/msg/Response.hpp> 
#include <tachyon/reply/ViewerReply.hpp>
#include <ya/typedef/requests.hpp>

namespace yq::tachyon {
    class ViewerWidgetReply : public ViewerReply {
        YQ_OBJECT_DECLARE(ViewerWidgetReply, ViewerReply)
    public:
    
        struct Param : public ViewerReply::Param {
        };
    
        ViewerWidgetReply(const ViewerWidgetRequestCPtr&, ViewerID, Response, const Param& p = {});
        ViewerWidgetReply(const ViewerWidgetRequestCPtr&, const Viewer*, Response, const Param& p = {});
        virtual ~ViewerWidgetReply();
        
        Response     response() const { return m_response; }
        
        static void  init_info();
        
    private:
        Response     m_response;
    };
}
