////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Response.hpp> 
#include <tachyon/reply/UIReply.hpp>

namespace yq::tachyon {
    class CloseReply : public UIReply {
        YQ_OBJECT_DECLARE(CloseReply, UIReply)
    public:
    
        CloseReply(const Header&, const RequestCPtr&, Response);
        
        Response     response() const { return m_response; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void  init_meta();
        
    protected:
        CloseReply(const CloseReply&, const Header&);
        virtual ~CloseReply();
        
    private:
        Response     m_response;
        
        CloseReply(const CloseReply&) = delete;
        CloseReply(CloseReply&&) = delete;
        CloseReply& operator=(const CloseReply&) = delete;
        CloseReply& operator=(CloseReply&&) = delete;
    };
}
