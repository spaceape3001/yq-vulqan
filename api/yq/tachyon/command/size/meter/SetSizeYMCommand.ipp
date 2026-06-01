////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSizeYMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSizeʸMCommand)

namespace yq::tachyon {
    SetSizeʸMCommand::SetSizeʸMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSizeʸMCommand::SetSizeʸMCommand(const Header& h, Meter v) : 
        SizeCommand(h), m_y(v)
    {
    }

    SetSizeʸMCommand::SetSizeʸMCommand(const SetSizeʸMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetSizeʸMCommand::~SetSizeʸMCommand()
    {
    }

    PostCPtr    SetSizeʸMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSizeʸMCommand(*this, h);
    }
    
    void SetSizeʸMCommand::init_meta()
    {
        auto w = writer<SetSizeʸMCommand>();
        w.description("Set Size MCommand in Y");
        w.property("y", &SetSizeʸMCommand::m_y).tag(kTag_Log).tag(kTag_Save);
    }
}
