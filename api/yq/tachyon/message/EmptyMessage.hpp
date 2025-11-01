////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Message.hpp>

namespace yq::tachyon {

    //! Test/general post type that's empty
    class EmptyMessage : public Message {
        YQ_OBJECT_DECLARE(EmptyMessage, Message)
    public:
        
        //  contributing nothing extra....
        using Message::Param;
        
        EmptyMessage(const Param& p = {});
        ~EmptyMessage();
        
        static void init_meta();
    };
}
