////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Reply.hpp>

namespace yq::tachyon {
    class WindowReply : public Reply {
        YQ_OBJECT_DECLARE(WindowReply, Reply)
    public:
    
        static void init_info();

    protected:
        WindowReply(const Header&, const RequestCPtr&);
        WindowReply(const WindowReply&, const Header&);
        virtual ~WindowReply();
        
    private:
        WindowReply(const WindowReply&) = delete;
        WindowReply(WindowReply&&) = delete;
        
        WindowReply& operator=(const WindowReply&) = delete;
        WindowReply& operator=(WindowReply&&) = delete;
    };
}
