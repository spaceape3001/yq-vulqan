////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/request/UIRequest.hpp>

namespace yq::tachyon {
    class CloseRequest : public UIRequest {
        YQ_OBJECT_DECLARE(CloseRequest, UIRequest)
    public:
        CloseRequest(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        CloseRequest(const CloseRequest&, const Header&);
        virtual ~CloseRequest();
        
    private:

        CloseRequest(const CloseRequest&) = delete;
        CloseRequest(CloseRequest&&) = delete;
        CloseRequest& operator=(const CloseRequest&) = delete;
        CloseRequest& operator=(CloseRequest&&) = delete;
    };
}
