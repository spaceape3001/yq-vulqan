////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/reply/io/SaveReply.hpp>
#include <yq/tachyon/api/ReplyMetaWriter.hpp>
#include <yq/tachyon/io/Save.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SaveReply)

namespace yq::tachyon {

    SaveReply::SaveReply(const Header& h, const RequestCPtr&req, const SaveSPtr&save) :
        IOReply(h, req), m_save(save)
    {
    }

    SaveReply::SaveReply(const Header& h, const RequestCPtr&req, SaveSPtr&& save) :
        IOReply(h, req), m_save(std::move(save))
    {
    }
    
    SaveReply::SaveReply(const SaveReply&cp, const Header& h) : IOReply(cp, h), m_save(cp.m_save)
    {
    }
    
    SaveReply::~SaveReply()
    {
    }
    
    PostCPtr    SaveReply::clone(rebind_k, const Header&h) const
    {
        return new SaveReply(*this, h);
    }
    
    void SaveReply::init_meta()
    {
        auto w = writer<SaveReply>();
        w.description("Save Reply");
    }
}
