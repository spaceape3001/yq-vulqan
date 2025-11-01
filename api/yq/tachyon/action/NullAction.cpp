////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "NullAction.hpp"
#include <yq/tachyon/api/ActionMetaWriter.hpp>

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
        
    void NullAction::init_meta()
    {
        auto w = writer<NullAction>();
        w.description("Null Action");
    }
}
