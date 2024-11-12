////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/enum/Response.hpp> 
#include <yq/tachyon/replies/ViewerReply.hpp>
#include <yq/tachyon/typedef/requests.hpp>

namespace yq::tachyon {
    class ViewerWidgetReply : public ViewerReply {
        YQ_OBJECT_DECLARE(ViewerWidgetReply, ViewerReply)
    public:
    
        struct Param : public ViewerReply::Param {
        };
    
        ViewerWidgetReply(const ViewerWidgetRequestCPtr&, Viewer*, Response, const Param& p = {});
        virtual ~ViewerWidgetReply();
        
        Response     response() const { return m_response; }
        
        static void  init_info();
        
    private:
        Response     m_response;
    };
}