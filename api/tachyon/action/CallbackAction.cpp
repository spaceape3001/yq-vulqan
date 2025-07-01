////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CallbackAction.hpp"
#include <tachyon/api/ActionMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CallbackAction)

namespace yq::tachyon {
    CallbackAction::CallbackAction()
    {
    }
    
    CallbackAction::CallbackAction(const CallbackAction&cp) : Action(cp)
    {
    }
    
    CallbackAction::~CallbackAction()
    {
    
    }
    
    void CallbackAction::init_meta()
    {
        auto w = writer<CallbackAction>();
        w.description("Action that makes a callbac");
    }
}
