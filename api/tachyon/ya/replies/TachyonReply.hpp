////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Reply.hpp>

namespace yq::tachyon {
    class TachyonReply : public Reply {
        YQ_OBJECT_DECLARE(TachyonReply, Reply)
    public:
    
        static void init_info();

    protected:
        TachyonReply(const Header&, const RequestCPtr&);
        TachyonReply(const TachyonReply&, const Header&);
        virtual ~TachyonReply();
        
    private:
        TachyonReply(const TachyonReply&) = delete;
        TachyonReply(TachyonReply&&) = delete;
        TachyonReply& operator=(const TachyonReply&) = delete;
        TachyonReply& operator=(TachyonReply&&) = delete;
    };
}
