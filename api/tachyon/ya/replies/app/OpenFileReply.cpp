////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/replies/app/OpenFileReply.hpp>
#include <yt/msg/ReplyInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::OpenFileReply)

namespace yq::tachyon {

    OpenFileReply::OpenFileReply(const Header& h, const RequestCPtr&req, const std::filesystem::path& fp) :
        AppReply(h, req), m_file(fp), m_response(Response::QaPla)
    {
    }
    
    OpenFileReply::OpenFileReply(const Header& h, const RequestCPtr& req, Response r) : 
        AppReply(h, req), m_response(r)
    {
    }

    OpenFileReply::OpenFileReply(const OpenFileReply&cp, const Header& h) : 
        AppReply(cp, h), m_file(cp.m_file), m_response(cp.m_response)
    {
    }
    
    OpenFileReply::~OpenFileReply()
    {
    }
    
    PostCPtr    OpenFileReply::clone(rebind_k, const Header&h) const
    {
        return new OpenFileReply(*this, h);
    }
    
    void OpenFileReply::init_info()
    {
        auto w = writer<OpenFileReply>();
        w.description("OpenFile Reply");
    }
}
