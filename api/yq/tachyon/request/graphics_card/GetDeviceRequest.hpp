////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/request/GraphicsCardRequest.hpp>

namespace yq::tachyon {
    class GetDeviceRequest : public GraphicsCardRequest {
        YQ_OBJECT_DECLARE(GetDeviceRequest, GraphicsCardRequest)
    public:
        GetDeviceRequest(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        GetDeviceRequest(const GetDeviceRequest&, const Header&);
        virtual ~GetDeviceRequest();
        
    private:

        GetDeviceRequest(const GetDeviceRequest&) = delete;
        GetDeviceRequest(GetDeviceRequest&&) = delete;
        GetDeviceRequest& operator=(const GetDeviceRequest&) = delete;
        GetDeviceRequest& operator=(GetDeviceRequest&&) = delete;
    };
}
