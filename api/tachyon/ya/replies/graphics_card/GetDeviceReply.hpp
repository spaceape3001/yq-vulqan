////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Response.hpp> 
#include <ya/replies/GraphicsCardReply.hpp>
#include <yv/typedef/vi_device.hpp>
#include <yt/msg/Response.hpp>

namespace yq::tachyon {
    class GetDeviceReply : public GraphicsCardReply {
        YQ_OBJECT_DECLARE(GetDeviceReply, GraphicsCardReply)
    public:
    
        GetDeviceReply(const Header&, const RequestCPtr&, Response);
        GetDeviceReply(const Header&, const RequestCPtr&, ViDevicePtr);
        
        ViDevicePtr     device() const;
        Response        response() const { return m_response; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void  init_info();
        
    protected:
        GetDeviceReply(const GetDeviceReply&, const Header&);
        virtual ~GetDeviceReply();
        
    private:
        ViDevicePtr     m_device;
        Response        m_response;
        
        GetDeviceReply(const GetDeviceReply&) = delete;
        GetDeviceReply(GetDeviceReply&&) = delete;
        GetDeviceReply& operator=(const GetDeviceReply&) = delete;
        GetDeviceReply& operator=(GetDeviceReply&&) = delete;
    };
}
