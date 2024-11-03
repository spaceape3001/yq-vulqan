////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Request.hpp>
#include <yq/tachyon/TachyonBind.hpp>

namespace yq::tachyon {
    class Tachyon;

    class TachyonRequestInfo : public post::RequestInfo {
    public:
        TachyonRequestInfo(std::string_view zName, post::RequestInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class TachyonRequest : public post::Request, public TachyonBind {
        YQ_OBJECT_INFO(TachyonRequestInfo)
        YQ_OBJECT_DECLARE(TachyonRequest, post::Request)
    public:
    
        struct Param : public post::Request::Param {
        };
    
        TachyonRequest(Tachyon*, const Param& p = {});
        virtual ~TachyonRequest();
        
    };
}
