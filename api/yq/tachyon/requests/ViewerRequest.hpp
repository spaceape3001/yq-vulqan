////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Request.hpp>

namespace yq::tachyon {
    class Viewer;

    class ViewerRequestInfo : public post::RequestInfo {
    public:
        ViewerRequestInfo(std::string_view zName, post::RequestInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class ViewerRequest : public post::Request {
        YQ_OBJECT_INFO(ViewerRequestInfo)
        YQ_OBJECT_DECLARE(ViewerRequest, post::Request)
    public:
    
        struct Param : public post::Request::Param {
        };
    
        ViewerRequest(Viewer*, const Param& p = {});
        virtual ~ViewerRequest();
        
        Viewer*     viewer() const { return m_viewer; }
        
    private:
        Viewer*     m_viewer    = nullptr;
    };
}
