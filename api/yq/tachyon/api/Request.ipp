////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Request.hpp>
#include <yq/tachyon/api/RequestMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Request)

namespace yq::tachyon {
    RequestMeta::RequestMeta(std::string_view zName, PostMeta& base, const std::source_location& sl) :
        PostMeta(zName, base, sl)
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

    void Request::init_meta()
    {
        auto w = writer<Request>();
        w.description("Abstract Request Class");
    }
}
