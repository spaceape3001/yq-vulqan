////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/reply/EditorReply.hpp>

#include <yq/tachyon/api/ReplyMetaWriter.hpp>

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

    void EditorReply::init_meta()
    {
        auto w = writer<EditorReply>();
        w.description("Editor reply base class");
    }
}
