////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PostAction.hpp"
#include <tachyon/api/ActionMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::PostAction)

namespace yq::tachyon {
    PostAction::PostAction()
    {
    }
    
    PostAction::PostAction(const PostAction&cp) : Action(cp)
    {
    }
    
    PostAction::~PostAction()
    {
    
    }
    
    void PostAction::init_meta()
    {
        auto w = writer<PostAction>();
        w.description("Action that sends a post");
    }
}
