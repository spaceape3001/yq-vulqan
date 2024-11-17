////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Reply.hpp>

namespace yq::tachyon {

    //! Test/general post type that's empty
    class EmptyReply : public Reply {
        YQ_OBJECT_DECLARE(EmptyReply, Reply)
    public:
        
        //  contributing nothing extra....
        using Reply::Param;
        
        EmptyReply(const RequestCPtr&, const Param& p = {});
        ~EmptyReply();
        
        static void init_info();
    };
}
