////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/requests/io/SaveRequest.hpp>
#include <yt/msg/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SaveRequest)

namespace yq::tachyon {

    SaveRequest::SaveRequest(const Header&h) : IORequest(h)
    {
    }

    SaveRequest::SaveRequest(const SaveRequest& cp, const Header& h) : IORequest(cp, h)
    {
    }
    
    SaveRequest::~SaveRequest()
    {
    }

    PostCPtr    SaveRequest::clone(rebind_k, const Header&h) const 
    {
        return new SaveRequest(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SaveRequest::init_info()
    {
        auto w = writer<SaveRequest>();
        w.description("Device Request");
    }
}
