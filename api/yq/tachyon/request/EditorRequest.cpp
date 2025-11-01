////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/request/EditorRequest.hpp>
#include <tachyon/api/RequestMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::EditorRequest)

namespace yq::tachyon {
    EditorRequest::EditorRequest(const Header&h) : Request(h)
    {
    }
    
    EditorRequest::EditorRequest(const EditorRequest& cp, const Header& h) : Request(cp, h)
    {
    }

    EditorRequest::~EditorRequest()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void EditorRequest::init_meta()
    {
        auto w = writer<EditorRequest>();
        w.description("Editor request base class");
    }
}
