////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PostAction.hpp"
#include <tachyon/api/ActionInfoWriter.hpp>

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
    
    void PostAction::init_info()
    {
        auto w = writer<PostAction>();
        w.description("Action that sends a post");
    }
}
