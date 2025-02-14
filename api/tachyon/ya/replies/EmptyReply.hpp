////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Reply.hpp>

namespace yq::tachyon {

    //! Test/general post type that's empty
    class EmptyReply : public Reply {
        YQ_OBJECT_DECLARE(EmptyReply, Reply)
    public:
        
        EmptyReply(const Header&, const RequestCPtr&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        static void init_info();

    protected:

        EmptyReply(const EmptyReply&, const Header&);
        ~EmptyReply();
    
    private:
        EmptyReply(const EmptyReply&) = delete;
        EmptyReply(EmptyReply&&) = delete;
        EmptyReply& operator=(const EmptyReply&) = delete;
        EmptyReply& operator=(EmptyReply&&) = delete;
    };
}
