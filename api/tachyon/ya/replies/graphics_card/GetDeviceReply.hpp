////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Response.hpp> 
#include <ya/replies/GraphicsCardReply.hpp>
#include <yv/typedef/vi_device.hpp>

namespace yq::tachyon {
    class GetDeviceReply : public GraphicsCardReply {
        YQ_OBJECT_DECLARE(GetDeviceReply, GraphicsCardReply)
    public:
    
        GetDeviceReply(const Header&, const RequestCPtr&, ViDevicePtr);
        
        ViDevicePtr   device() const;
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void  init_info();
        
    protected:
        GetDeviceReply(const GetDeviceReply&, const Header&);
        virtual ~GetDeviceReply();
        
    private:
        ViDevicePtr     m_device;
        
        GetDeviceReply(const GetDeviceReply&) = delete;
        GetDeviceReply(GetDeviceReply&&) = delete;
        GetDeviceReply& operator=(const GetDeviceReply&) = delete;
        GetDeviceReply& operator=(GetDeviceReply&&) = delete;
    };
}
