////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/replies/graphics_card/GetDeviceReply.hpp>
#include <yt/msg/ReplyInfoWriter.hpp>
#include <yv/ViDevice.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::GetDeviceReply)

namespace yq::tachyon {

    GetDeviceReply::GetDeviceReply(const Header& h, const RequestCPtr&req, ViDevicePtr dev) :
        GraphicsCardReply(h, req), m_device(dev), m_response(Response::QaPla)
    {
    }
    
    GetDeviceReply::GetDeviceReply(const Header& h, const RequestCPtr& req, Response r) : 
        GraphicsCardReply(h, req), m_response(r)
    {
    }

    GetDeviceReply::GetDeviceReply(const GetDeviceReply&cp, const Header& h) : 
        GraphicsCardReply(cp, h), m_device(cp.m_device)
    {
    }
    
    GetDeviceReply::~GetDeviceReply()
    {
    }
    
    PostCPtr    GetDeviceReply::clone(rebind_k, const Header&h) const
    {
        return new GetDeviceReply(*this, h);
    }
    
    ViDevicePtr   GetDeviceReply::device() const 
    { 
        return m_device; 
    }

    void GetDeviceReply::init_info()
    {
        auto w = writer<GetDeviceReply>();
        w.description("GetDevice Reply");
    }
}
