////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/request/AppRequest.hpp>

namespace yq::tachyon {
    class OpenFileRequest : public AppRequest {
        YQ_OBJECT_DECLARE(OpenFileRequest, AppRequest)
    public:
        // TODO (add filters ... second constructor)
    
        OpenFileRequest(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        OpenFileRequest(const OpenFileRequest&, const Header&);
        virtual ~OpenFileRequest();
        
    private:

        OpenFileRequest(const OpenFileRequest&) = delete;
        OpenFileRequest(OpenFileRequest&&) = delete;
        OpenFileRequest& operator=(const OpenFileRequest&) = delete;
        OpenFileRequest& operator=(OpenFileRequest&&) = delete;
    };
}
