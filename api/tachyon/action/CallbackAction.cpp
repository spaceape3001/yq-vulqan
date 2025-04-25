////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CallbackAction.hpp"
#include <yt/api/ActionInfoWriter.hpp>

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
    
    void CallbackAction::init_info()
    {
        auto w = writer<CallbackAction>();
        w.description("Action that makes a callbac");
    }
}
