////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/request/UIRequest.hpp>

namespace yq::tachyon {
    class RefreshRequest : public UIRequest {
        YQ_OBJECT_DECLARE(RefreshRequest, UIRequest)
    public:
        RefreshRequest(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        RefreshRequest(const RefreshRequest&, const Header&);
        virtual ~RefreshRequest();
        
    private:

        RefreshRequest(const RefreshRequest&) = delete;
        RefreshRequest(RefreshRequest&&) = delete;
        RefreshRequest& operator=(const RefreshRequest&) = delete;
        RefreshRequest& operator=(RefreshRequest&&) = delete;
    };
}
