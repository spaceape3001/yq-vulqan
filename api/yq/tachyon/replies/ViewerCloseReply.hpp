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
    class ViewerCloseReply : public ViewerReply {
        YQ_OBJECT_DECLARE(ViewerCloseReply, ViewerReply)
    public:
    
        struct Param : public ViewerReply::Param {
        };
    
        ViewerCloseReply(const ViewerCloseRequestCPtr&, const Viewer*, Response, const Param& p = {});
        ViewerCloseReply(const ViewerCloseRequestCPtr&, ViewerID, Response, const Param& p = {});
        virtual ~ViewerCloseReply();
        
        Response     response() const { return m_response; }
        
        static void  init_info();
        
    private:
        Response     m_response;
    };
}
