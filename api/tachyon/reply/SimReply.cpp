////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/reply/SimReply.hpp>

#include <tachyon/msg/ReplyInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SimReply)

namespace yq::tachyon {

    SimReply::SimReply(const Header&h, const RequestCPtr& rq) : Reply(h, rq)
    {
    }
    
    SimReply::SimReply(const SimReply& cp, const Header& h) : Reply(cp, h)
    {
    }

    SimReply::~SimReply()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SimReply::init_info()
    {
        auto w = writer<SimReply>();
        w.description("Sim reply base class");
    }
}
