////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Request.hpp>
#include <tachyon/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class TachyonRequest : public Request {
        YQ_OBJECT_DECLARE(TachyonRequest, Request)
    public:
    
        static void init_info();

    protected:
        TachyonRequest(const Header&);
        TachyonRequest(const TachyonRequest&, const Header&);
        ~TachyonRequest();
        
    private:
        TachyonRequest(const TachyonRequest&) = delete;
        TachyonRequest(TachyonRequest&&) = delete;
        TachyonRequest& operator=(const TachyonRequest&) = delete;
        TachyonRequest& operator=(TachyonRequest&&) = delete;
    };
}
