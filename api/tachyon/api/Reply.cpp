////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Reply.hpp>
#include <tachyon/api/ReplyInfoWriter.hpp>
#include <tachyon/api/Request.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Reply)

namespace yq::tachyon {
    ReplyInfo::ReplyInfo(std::string_view zName, PostInfo& base, const std::source_location& sl) :
        PostInfo(zName, base, sl)
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

    void Reply::init_info()
    {
        auto w = writer<Reply>();
        w.description("Abstract Reply Class");
    }
}
