////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/requests/app/OpenFileRequest.hpp>
#include <yt/msg/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::OpenFileRequest)

namespace yq::tachyon {

    OpenFileRequest::OpenFileRequest(const Header&h) : AppRequest(h)
    {
    }

    OpenFileRequest::OpenFileRequest(const OpenFileRequest& cp, const Header& h) : AppRequest(cp, h)
    {
    }
    
    OpenFileRequest::~OpenFileRequest()
    {
    }

    PostCPtr    OpenFileRequest::clone(rebind_k, const Header&h) const 
    {
        return new OpenFileRequest(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void OpenFileRequest::init_info()
    {
        auto w = writer<OpenFileRequest>();
        w.description("Browse to Open Request");
    }
}
