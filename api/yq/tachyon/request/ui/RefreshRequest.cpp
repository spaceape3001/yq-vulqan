////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/request/ui/RefreshRequest.hpp>
#include <yq/tachyon/api/RequestMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RefreshRequest)

namespace yq::tachyon {

    RefreshRequest::RefreshRequest(const Header&h) : UIRequest(h)
    {
    }

    RefreshRequest::RefreshRequest(const RefreshRequest& cp, const Header& h) : UIRequest(cp, h)
    {
    }
    
    RefreshRequest::~RefreshRequest()
    {
    }

    PostCPtr    RefreshRequest::clone(rebind_k, const Header&h) const 
    {
        return new RefreshRequest(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void RefreshRequest::init_meta()
    {
        auto w = writer<RefreshRequest>();
        w.description("Refresh Request");
    }
}
