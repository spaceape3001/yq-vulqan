////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Request.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class GraphicsCardRequest : public Request {
        YQ_OBJECT_DECLARE(GraphicsCardRequest, Request)
    public:
    
        static void init_info();

    protected:
        GraphicsCardRequest(const Header&);
        GraphicsCardRequest(const GraphicsCardRequest&, const Header&);
        ~GraphicsCardRequest();
        
    private:
        GraphicsCardRequest(const GraphicsCardRequest&) = delete;
        GraphicsCardRequest(GraphicsCardRequest&&) = delete;
        GraphicsCardRequest& operator=(const GraphicsCardRequest&) = delete;
        GraphicsCardRequest& operator=(GraphicsCardRequest&&) = delete;
    };
}
