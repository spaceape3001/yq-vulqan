////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Request.hpp>

namespace yq::tachyon {
    class Viewer;

    class ViewerRequest : public Request {
        YQ_OBJECT_DECLARE(ViewerRequest, Request)
    public:
    
        static void init_info();

    protected:
        ViewerRequest(const Header&);
        ViewerRequest(const ViewerRequest&, const Header&);
        virtual ~ViewerRequest();

    private:
        ViewerRequest(const ViewerRequest&) = delete;
        ViewerRequest(ViewerRequest&&) = delete;
        ViewerRequest& operator=(const ViewerRequest&) = delete;
        ViewerRequest& operator=(ViewerRequest&&) = delete;
    };
}
