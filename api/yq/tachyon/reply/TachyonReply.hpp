////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Reply.hpp>

namespace yq::tachyon {
    class TachyonReply : public Reply {
        YQ_OBJECT_DECLARE(TachyonReply, Reply)
    public:
    
        static void init_meta();

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
