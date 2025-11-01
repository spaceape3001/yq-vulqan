////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/request/ViewerRequest.hpp>

namespace yq::tachyon {
    class ViewerScreenshotRequest : public ViewerRequest {
        YQ_OBJECT_DECLARE(ViewerScreenshotRequest, ViewerRequest)
    public:
        ViewerScreenshotRequest(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        ViewerScreenshotRequest(const ViewerScreenshotRequest&, const Header&);
        virtual ~ViewerScreenshotRequest();
        
    private:

        ViewerScreenshotRequest(const ViewerScreenshotRequest&) = delete;
        ViewerScreenshotRequest(ViewerScreenshotRequest&&) = delete;
        ViewerScreenshotRequest& operator=(const ViewerScreenshotRequest&) = delete;
        ViewerScreenshotRequest& operator=(ViewerScreenshotRequest&&) = delete;
    };
}
