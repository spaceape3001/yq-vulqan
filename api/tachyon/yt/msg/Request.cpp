////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/msg/Request.hpp>
#include <yt/msg/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Request)

namespace yq::tachyon {
    RequestInfo::RequestInfo(std::string_view zName, PostInfo& base, const std::source_location& sl) :
        PostInfo(zName, base, sl)
    {
        set(Flag::REQUEST);
    }

    ////////////////////////////////////////////////////////////////////////////

    Request::Request(const Param&) : Post({})
    {
        // DEPRECATED
    }

    Request::Request(const Header& h) : Post(h)
    {
    }
    
    Request::Request(const Request& cp, const Header& h) : Post(cp, h)
    {
    }
    
    Request::~Request()
    {
    }


    ////////////////////////////////////////////////////////////////////////////

    void Request::init_info()
    {
        auto w = writer<Request>();
        w.description("Abstract Request Class");
    }
}
