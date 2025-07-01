////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/reply/EmptyReply.hpp>
#include <tachyon/api/ReplyMetaWriter.hpp>

namespace yq::tachyon {
    EmptyReply::EmptyReply(const Header&h, const RequestCPtr& rq) : Reply(h, rq) 
    {
    }
    
    EmptyReply::EmptyReply(const EmptyReply& cp, const Header&h) : Reply(cp, h) 
    {
    }

    PostCPtr    EmptyReply::clone(rebind_k, const Header&h) const 
    {
        return new EmptyReply(*this, h);
    }
    
    EmptyReply::~EmptyReply()
    {
    }
    
    void EmptyReply::init_info()
    {
        auto w = writer<EmptyReply>();
        w.description("Empty Reply");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::EmptyReply)
