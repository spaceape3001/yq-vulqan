////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/replies/app/BrowseOpenReply.hpp>
#include <yt/msg/ReplyInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::BrowseOpenReply)

namespace yq::tachyon {

    BrowseOpenReply::BrowseOpenReply(const Header& h, const RequestCPtr&req, const std::filesystem::path& fp) :
        AppReply(h, req), m_file(fp), m_response(Response::QaPla)
    {
    }
    
    BrowseOpenReply::BrowseOpenReply(const Header& h, const RequestCPtr& req, Response r) : 
        AppReply(h, req), m_response(r)
    {
    }

    BrowseOpenReply::BrowseOpenReply(const BrowseOpenReply&cp, const Header& h) : 
        AppReply(cp, h), m_file(cp.m_file), m_response(cp.m_response)
    {
    }
    
    BrowseOpenReply::~BrowseOpenReply()
    {
    }
    
    PostCPtr    BrowseOpenReply::clone(rebind_k, const Header&h) const
    {
        return new BrowseOpenReply(*this, h);
    }
    
    void BrowseOpenReply::init_info()
    {
        auto w = writer<BrowseOpenReply>();
        w.description("BrowseOpen Reply");
    }
}
