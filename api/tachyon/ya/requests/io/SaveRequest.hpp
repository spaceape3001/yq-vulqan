////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/requests/IORequest.hpp>

namespace yq::tachyon {
    class SaveRequest : public IORequest {
        YQ_OBJECT_DECLARE(SaveRequest, IORequest)
    public:
        SaveRequest(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();
        
    protected:
        SaveRequest(const SaveRequest&, const Header&);
        virtual ~SaveRequest();
        
    private:
    
        SaveRequest(const SaveRequest&) = delete;
        SaveRequest(SaveRequest&&) = delete;
        SaveRequest& operator=(const SaveRequest&) = delete;
        SaveRequest& operator=(SaveRequest&&) = delete;
    };
}
