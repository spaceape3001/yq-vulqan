////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/reply/EditorReply.hpp>

#include <tachyon/api/ReplyInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::EditorReply)

namespace yq::tachyon {
    EditorReply::EditorReply(const Header&h, const RequestCPtr& rq) : Reply(h, rq)
    {
    }
    
    EditorReply::EditorReply(const EditorReply&cp, const Header&h) : Reply(cp, h)
    {
    }

    EditorReply::~EditorReply()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void EditorReply::init_info()
    {
        auto w = writer<EditorReply>();
        w.description("Editor reply base class");
    }
}
