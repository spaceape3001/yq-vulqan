////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/reply/TachyonReply.hpp>

#include <yq/tachyon/api/ReplyMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TachyonReply)

namespace yq::tachyon {
    TachyonReply::TachyonReply(const Header&h, const RequestCPtr& rq) : Reply(h, rq)
    {
    }
    
    TachyonReply::TachyonReply(const TachyonReply& cp, const Header&h) : Reply(cp, h)
    {
    }

    TachyonReply::~TachyonReply()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void TachyonReply::init_meta()
    {
        auto w = writer<TachyonReply>();
        w.description("Tachyon reply base class");
    }
}
