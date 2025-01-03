////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Response.hpp> 
#include <yq/tachyon/replies/ViewerReply.hpp>
#include <ya/typedef/requests.hpp>

namespace yq::tachyon {
    class ViewerCloseReply : public ViewerReply {
        YQ_OBJECT_DECLARE(ViewerCloseReply, ViewerReply)
    public:
    
        struct Param : public ViewerReply::Param {
        };
    
        ViewerCloseReply(const RequestCPtr&, const Viewer*, Response, const Param& p = {});
        ViewerCloseReply(const RequestCPtr&, ViewerID, Response, const Param& p = {});
        virtual ~ViewerCloseReply();
        
        Response     response() const { return m_response; }
        
        static void  init_info();
        
    private:
        Response     m_response;
    };
}
