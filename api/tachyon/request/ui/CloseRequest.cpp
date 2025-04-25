////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/request/ui/CloseRequest.hpp>
#include <tachyon/api/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CloseRequest)

namespace yq::tachyon {

    CloseRequest::CloseRequest(const Header&h) : UIRequest(h)
    {
    }

    CloseRequest::CloseRequest(const CloseRequest& cp, const Header& h) : UIRequest(cp, h)
    {
    }
    
    CloseRequest::~CloseRequest()
    {
    }

    PostCPtr    CloseRequest::clone(rebind_k, const Header&h) const 
    {
        return new CloseRequest(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void CloseRequest::init_info()
    {
        auto w = writer<CloseRequest>();
        w.description("Close Request");
    }
}
