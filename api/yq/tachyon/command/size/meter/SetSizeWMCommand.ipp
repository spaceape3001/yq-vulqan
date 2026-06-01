////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSizeWMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSizeʷMCommand)

namespace yq::tachyon {
    SetSizeʷMCommand::SetSizeʷMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSizeʷMCommand::SetSizeʷMCommand(const Header& h, Meter v) : 
        SizeCommand(h), m_w(v)
    {
    }

    SetSizeʷMCommand::SetSizeʷMCommand(const SetSizeʷMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_w(cp.m_w)
    {
    }
    
    SetSizeʷMCommand::~SetSizeʷMCommand()
    {
    }

    PostCPtr    SetSizeʷMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSizeʷMCommand(*this, h);
    }
    
    void SetSizeʷMCommand::init_meta()
    {
        auto w = writer<SetSizeʷMCommand>();
        w.description("Set Size MCommand in X");
        w.property("w", &SetSizeʷMCommand::m_w).tag(kTag_Log).tag(kTag_Save);
    }
}
