////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LoadTSXReply.hpp"
#include <tachyon/api/ReplyMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::LoadTSXReply)

namespace yq::tachyon {
    void  LoadTSXReply::init_meta()
    {
        auto w = writer<LoadTSXReply>();
        w.description("TSX Load Reply");
    }

    LoadTSXReply::LoadTSXReply(const Header&h, const RequestCPtr&req, Response resp) :
        IOReply(h, req), m_response(resp)
    {
    }
    
    LoadTSXReply::LoadTSXReply(const Header&h, const RequestCPtr&req, const TachyonIDSet&tacs) :
        IOReply(h, req), m_response(Response::QaPla), m_tachyons(tacs)
    {
    }
    
    LoadTSXReply::LoadTSXReply(const Header&h, const RequestCPtr&req, TachyonIDSet&&tacs) :
        IOReply(h, req), m_response(Response::QaPla), m_tachyons(std::move(tacs))
    {
    }
    
    LoadTSXReply::LoadTSXReply(const LoadTSXReply&cp, const Header&h) : 
        IOReply(cp, h), m_response(cp.m_response), m_tachyons(cp.m_tachyons)
    {
    }
    
    LoadTSXReply::~LoadTSXReply()
    {
    }
    
    PostCPtr LoadTSXReply::clone(rebind_k, const Header&h) const 
    {
        return new LoadTSXReply(*this, h);
    }
}
