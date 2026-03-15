////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Reply.hpp>
#include <yq/tachyon/api/ReplyMetaWriter.hpp>
#include <yq/tachyon/api/Request.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Reply)

namespace yq::tachyon {
    ReplyMeta::ReplyMeta(std::string_view zName, PostMeta& base, const std::source_location& sl) :
        PostMeta(zName, base, sl)
    {
        set(Flag::REPLY);
    }

    ////////////////////////////////////////////////////////////////////////////

    Reply::Reply(const RequestCPtr& req, const Param&) : Post({}), m_request(req)
    {
        // DEPRECATED
    }
    
    Reply::Reply(const Header& h, const RequestCPtr& req) : Post(h), m_request(req)
    {
    }

    Reply::Reply(const Reply& cp, const Header& h) : Post(cp, h), m_request(cp.m_request)
    {
    }
    
    Reply::~Reply()
    {
    }

    const Request*  Reply::request() const
    {
        return m_request.ptr();
    }

    ////////////////////////////////////////////////////////////////////////////

    void Reply::init_meta()
    {
        auto w = writer<Reply>();
        w.description("Abstract Reply Class");
    }
}
