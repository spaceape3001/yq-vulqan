////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/reply/viewer/ViewerScreenshotReply.hpp>
#include <tachyon/api/ReplyMetaWriter.hpp>
#include <tachyon/gfx/Raster.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerScreenshotReply)

namespace yq::tachyon {

    ViewerScreenshotReply::ViewerScreenshotReply(const Header&h, const RequestCPtr&req, Response r, const RasterCPtr& ras) :
        ViewerReply(h, req), m_response(r), m_raster(ras)
    {
    }
    
    ViewerScreenshotReply::ViewerScreenshotReply(const ViewerScreenshotReply&cp, const Header& h) : 
        ViewerReply(cp, h), m_response(cp.m_response), m_raster(cp.m_raster)
    {
    }
    
    ViewerScreenshotReply::~ViewerScreenshotReply()
    {
    }
    
    PostCPtr    ViewerScreenshotReply::clone(rebind_k, const Header&h) const
    {
        return new ViewerScreenshotReply(*this, h);
    }
    
    void ViewerScreenshotReply::init_info()
    {
        auto w = writer<ViewerScreenshotReply>();
        w.description("ViewerScreenshot Reply");
        w.property("response", &ViewerScreenshotReply::response).tag(kTag_Log);
    }
}
