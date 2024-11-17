////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "EmptyReply.hpp"
#include <yq/tachyon/api/ReplyInfoWriter.hpp>

namespace yq::tachyon {
    EmptyReply::EmptyReply(const RequestCPtr& rq, const Param& p) : Reply(rq, p) 
    {
    }
    
    EmptyReply::~EmptyReply()
    {
    }
    
    void EmptyReply::init_info()
    {
        auto w = writer<EmptyReply>();
        w.description("Empty Reply");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::EmptyReply)
