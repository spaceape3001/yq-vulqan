////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/reply/TachyonReply.hpp>

#include <tachyon/api/ReplyInfoWriter.hpp>

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

    void TachyonReply::init_info()
    {
        auto w = writer<TachyonReply>();
        w.description("Tachyon reply base class");
    }
}
