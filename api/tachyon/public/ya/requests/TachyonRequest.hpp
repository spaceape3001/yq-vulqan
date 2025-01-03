////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Request.hpp>
#include <yt/api/TachyonBind.hpp>

namespace yq::tachyon {
    class Tachyon;

    class TachyonRequestInfo : public RequestInfo {
    public:
        TachyonRequestInfo(std::string_view zName, RequestInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class TachyonRequest : public Request, public TachyonBind {
        YQ_OBJECT_INFO(TachyonRequestInfo)
        YQ_OBJECT_DECLARE(TachyonRequest, Request)
    public:
    
        struct Param : public Request::Param {
        };
    
        TachyonRequest(TachyonID, const Param& p = {});
        TachyonRequest(const Tachyon*, const Param& p = {});
        virtual ~TachyonRequest();
        static void init_info();
    };
}
