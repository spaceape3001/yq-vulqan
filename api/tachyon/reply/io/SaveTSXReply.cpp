////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveTSXReply.hpp"
#include <tachyon/api/ReplyMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SaveTSXReply)

namespace yq::tachyon {
    void  SaveTSXReply::init_info()
    {
        auto w = writer<SaveTSXReply>();
        w.description("TSX Save Reply");
    }
    
    SaveTSXReply::SaveTSXReply(const Header& h, const RequestCPtr& req, Response rep) :
        IOReply(h, req), m_response(rep)
    {
    }
    
    SaveTSXReply::SaveTSXReply(const SaveTSXReply&cp, const Header&h) :
        IOReply(cp, h), m_response(cp.m_response)
    {
    }
    
    SaveTSXReply::~SaveTSXReply()
    {
    }
    
    PostCPtr    SaveTSXReply::clone(rebind_k, const Header& h) const 
    {
        return new SaveTSXReply(*this, h);
    }
}
