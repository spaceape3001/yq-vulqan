////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/requests/app/SaveFileRequest.hpp>
#include <tachyon/msg/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SaveFileRequest)

namespace yq::tachyon {

    SaveFileRequest::SaveFileRequest(const Header&h) : AppRequest(h)
    {
    }

    SaveFileRequest::SaveFileRequest(const SaveFileRequest& cp, const Header& h) : AppRequest(cp, h)
    {
    }
    
    SaveFileRequest::~SaveFileRequest()
    {
    }

    PostCPtr    SaveFileRequest::clone(rebind_k, const Header&h) const 
    {
        return new SaveFileRequest(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SaveFileRequest::init_info()
    {
        auto w = writer<SaveFileRequest>();
        w.description("Browse to Save Request");
    }
}
