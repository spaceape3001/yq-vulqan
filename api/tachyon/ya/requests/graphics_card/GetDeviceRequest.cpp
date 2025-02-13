////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/requests/graphics_card/GetDeviceRequest.hpp>
#include <yt/msg/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::GetDeviceRequest)

namespace yq::tachyon {

    GetDeviceRequest::GetDeviceRequest(const Header&h) : GraphicsCardRequest(h)
    {
    }

    GetDeviceRequest::GetDeviceRequest(const GetDeviceRequest& cp, const Header& h) : GraphicsCardRequest(cp, h)
    {
    }
    
    GetDeviceRequest::~GetDeviceRequest()
    {
    }

    PostCPtr    GetDeviceRequest::clone(rebind_k, const Header&h) const 
    {
        return new GetDeviceRequest(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void GetDeviceRequest::init_info()
    {
        auto w = writer<GetDeviceRequest>();
        w.description("Device Request");
    }
}
