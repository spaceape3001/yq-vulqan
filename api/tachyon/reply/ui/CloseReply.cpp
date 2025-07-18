////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/reply/ui/CloseReply.hpp>
#include <tachyon/api/ReplyMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CloseReply)

namespace yq::tachyon {

    CloseReply::CloseReply(const Header& h, const RequestCPtr&req, Response r) :
        UIReply(h, req), m_response(r)
    {
    }
    
    CloseReply::CloseReply(const CloseReply&cp, const Header& h) : UIReply(cp, h), m_response(cp.m_response)
    {
    }
    
    CloseReply::~CloseReply()
    {
    }
    
    PostCPtr    CloseReply::clone(rebind_k, const Header&h) const
    {
        return new CloseReply(*this, h);
    }
    
    void CloseReply::init_meta()
    {
        auto w = writer<CloseReply>();
        w.description("Close Reply");
        w.property("response", &CloseReply::response).tag(kTag_Log);
    }
}
