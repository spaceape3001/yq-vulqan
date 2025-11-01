////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Reply.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class UIReply : public Reply {
        YQ_OBJECT_DECLARE(UIReply, Reply)
    public:
    
        static void init_meta();

    protected:
        UIReply(const Header&, const RequestCPtr&);
        UIReply(const UIReply&, const Header&);
        ~UIReply();
        
    private:
        UIReply(const UIReply&) = delete;
        UIReply(UIReply&&) = delete;
        UIReply& operator=(const UIReply&) = delete;
        UIReply& operator=(UIReply&&) = delete;
    };
}
