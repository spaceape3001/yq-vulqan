////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "NullAction.hpp"
#include <tachyon/api/ActionInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::NullAction)

namespace yq::tachyon {
    NullAction::NullAction()
    {
    }
    
    NullAction::~NullAction()
    {
    }

    bool  NullAction::action(Payload&) const 
    {
        return true;
    }
        
    void NullAction::init_info()
    {
        auto w = writer<NullAction>();
        w.description("Null Action");
    }
}
