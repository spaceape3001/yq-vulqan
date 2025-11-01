////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Request.hpp>

namespace yq::tachyon {

    //! Test/general post type that's empty
    class EmptyRequest : public Request {
        YQ_OBJECT_DECLARE(EmptyRequest, Request)
    public:
        
        EmptyRequest(const Header&h);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void init_meta();

    protected:
        EmptyRequest(const EmptyRequest&, const Header&h);
        ~EmptyRequest();
        
    private:
        EmptyRequest(const EmptyRequest&) = delete;
        EmptyRequest(EmptyRequest&&) = delete;
        EmptyRequest& operator=(const EmptyRequest&) = delete;
        EmptyRequest& operator=(EmptyRequest&&) = delete;
    };
}
