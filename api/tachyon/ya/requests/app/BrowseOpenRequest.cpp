////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/requests/app/BrowseOpenRequest.hpp>
#include <yt/msg/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::BrowseOpenRequest)

namespace yq::tachyon {

    BrowseOpenRequest::BrowseOpenRequest(const Header&h) : AppRequest(h)
    {
    }

    BrowseOpenRequest::BrowseOpenRequest(const BrowseOpenRequest& cp, const Header& h) : AppRequest(cp, h)
    {
    }
    
    BrowseOpenRequest::~BrowseOpenRequest()
    {
    }

    PostCPtr    BrowseOpenRequest::clone(rebind_k, const Header&h) const 
    {
        return new BrowseOpenRequest(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void BrowseOpenRequest::init_info()
    {
        auto w = writer<BrowseOpenRequest>();
        w.description("Browse to Open Request");
    }
}
