////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/requests/AppRequest.hpp>

namespace yq::tachyon {
    class BrowseOpenRequest : public AppRequest {
        YQ_OBJECT_DECLARE(BrowseOpenRequest, AppRequest)
    public:
        // TODO (add filters ... second constructor)
    
        BrowseOpenRequest(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();

    protected:
        BrowseOpenRequest(const BrowseOpenRequest&, const Header&);
        virtual ~BrowseOpenRequest();
        
    private:

        BrowseOpenRequest(const BrowseOpenRequest&) = delete;
        BrowseOpenRequest(BrowseOpenRequest&&) = delete;
        BrowseOpenRequest& operator=(const BrowseOpenRequest&) = delete;
        BrowseOpenRequest& operator=(BrowseOpenRequest&&) = delete;
    };
}
