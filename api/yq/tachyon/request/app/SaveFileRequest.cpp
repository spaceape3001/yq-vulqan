////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/request/app/SaveFileRequest.hpp>
#include <tachyon/api/RequestMetaWriter.hpp>

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

    void SaveFileRequest::init_meta()
    {
        auto w = writer<SaveFileRequest>();
        w.description("Browse to Save Request");
    }
}
