////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/msg/Reply.hpp>

namespace yq::tachyon {
    class IOReply : public Reply {
        YQ_OBJECT_DECLARE(IOReply, Reply)
    public:

        static void init_info();
    
    protected:
    
        IOReply(const Header&, const RequestCPtr&);
        IOReply(const IOReply&, const Header&);
        virtual ~IOReply();
        
    private:
        IOReply(const IOReply&) = delete;
        IOReply(IOReply&&) = delete;
        IOReply& operator=(const IOReply&) = delete;
        IOReply& operator=(IOReply&&) = delete;
    };
}
