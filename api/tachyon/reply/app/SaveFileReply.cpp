////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/reply/app/SaveFileReply.hpp>
#include <tachyon/api/ReplyMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SaveFileReply)

namespace yq::tachyon {

    SaveFileReply::SaveFileReply(const Header& h, const RequestCPtr&req, const std::filesystem::path& fp) :
        AppReply(h, req), m_file(fp), m_response(Response::QaPla)
    {
    }
    
    SaveFileReply::SaveFileReply(const Header& h, const RequestCPtr& req, Response r) : 
        AppReply(h, req), m_response(r)
    {
    }

    SaveFileReply::SaveFileReply(const SaveFileReply&cp, const Header& h) : 
        AppReply(cp, h), m_file(cp.m_file), m_response(cp.m_response)
    {
    }
    
    SaveFileReply::~SaveFileReply()
    {
    }
    
    PostCPtr    SaveFileReply::clone(rebind_k, const Header&h) const
    {
        return new SaveFileReply(*this, h);
    }
    
    void SaveFileReply::init_meta()
    {
        auto w = writer<SaveFileReply>();
        w.description("SaveFile Reply");
    }
}
