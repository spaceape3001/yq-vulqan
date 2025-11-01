////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Reply.hpp>

namespace yq::tachyon {
    class SimReply : public Reply {
        YQ_OBJECT_DECLARE(SimReply, Reply)
    public:

        static void init_meta();
    
    protected:
    
        SimReply(const Header&, const RequestCPtr&);
        SimReply(const SimReply&, const Header&);
        virtual ~SimReply();
        
    private:
        SimReply(const SimReply&) = delete;
        SimReply(SimReply&&) = delete;
        SimReply& operator=(const SimReply&) = delete;
        SimReply& operator=(SimReply&&) = delete;
    };
}
