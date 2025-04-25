////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/reply/AnyReply.hpp>
#include <tachyon/api/ReplyInfoWriter.hpp>

namespace yq::tachyon {
    AnyReply::AnyReply(const Header&h, const RequestCPtr& rq, const Any& val) : Reply(h, rq), m_value(val)
    {
    }
    
    AnyReply::AnyReply(const Header&h, const RequestCPtr& rq, Any&& val) : Reply(h, rq), m_value(std::move(val))
    {
    }
    

    AnyReply::AnyReply(const AnyReply& cp, const Header&h) : Reply(cp, h), m_value(cp.m_value)
    {
    }
    
    AnyReply::~AnyReply()
    {
    }

    PostCPtr    AnyReply::clone(rebind_k, const Header& h) const 
    {
        return new AnyReply(*this, h);
    }

    void AnyReply::init_info()
    {
        auto w = writer<AnyReply>();
        w.description("Any Reply");
        w.property("value", &AnyReply::value);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::AnyReply)
