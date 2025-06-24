////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Response.hpp> 
#include <tachyon/reply/ViewerReply.hpp>
#include <tachyon/typedef/raster.hpp>
#include <yq/core/Ref.hpp>

namespace yq::tachyon {
    class ViewerScreenshotReply : public ViewerReply {
        YQ_OBJECT_DECLARE(ViewerScreenshotReply, ViewerReply)
    public:
    
        ViewerScreenshotReply(const Header&, const RequestCPtr&, Response, const RasterCPtr& ras={});
        
        const RasterCPtr&   raster() const { return m_raster; }
        Response     response() const { return m_response; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void  init_info();
        
    protected:
        ViewerScreenshotReply(const ViewerScreenshotReply&, const Header&);
        virtual ~ViewerScreenshotReply();
        
    private:
        Response    m_response;
        RasterCPtr  m_raster;
        
        ViewerScreenshotReply(const ViewerScreenshotReply&) = delete;
        ViewerScreenshotReply(ViewerScreenshotReply&&) = delete;
        ViewerScreenshotReply& operator=(const ViewerScreenshotReply&) = delete;
        ViewerScreenshotReply& operator=(ViewerScreenshotReply&&) = delete;
    };
}
