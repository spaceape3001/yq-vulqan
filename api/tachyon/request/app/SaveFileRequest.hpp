////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/request/AppRequest.hpp>

namespace yq::tachyon {
    class SaveFileRequest : public AppRequest {
        YQ_OBJECT_DECLARE(SaveFileRequest, AppRequest)
    public:
        // TODO (add filters ... second constructor)
    
        SaveFileRequest(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        SaveFileRequest(const SaveFileRequest&, const Header&);
        virtual ~SaveFileRequest();
        
    private:

        SaveFileRequest(const SaveFileRequest&) = delete;
        SaveFileRequest(SaveFileRequest&&) = delete;
        SaveFileRequest& operator=(const SaveFileRequest&) = delete;
        SaveFileRequest& operator=(SaveFileRequest&&) = delete;
    };
}
