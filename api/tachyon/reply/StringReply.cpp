////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/reply/StringReply.hpp>
#include <tachyon/api/ReplyMetaWriter.hpp>

namespace yq::tachyon {
    StringReply::StringReply(const Header&h, const RequestCPtr&rq, std::string_view k) : Reply(h, rq), m_text(k)
    {
    }
    
    StringReply::StringReply(const StringReply& cp, const Header&h) : Reply(cp, h), m_text(cp.m_text)
    {
    }
    
    StringReply::~StringReply()
    {
    }
    
    PostCPtr    StringReply::clone(rebind_k, const Header& h) const 
    {
        return new StringReply(*this, h);
    }

    void StringReply::init_meta()
    {
        auto w = writer<StringReply>();
        w.description("Text Reply");
        w.property("text", &StringReply::m_text).tag(kTag_Save).tag(kTag_Log);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::StringReply)
