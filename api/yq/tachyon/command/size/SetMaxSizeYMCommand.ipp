////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSizeYMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSizeʸMCommand)

namespace yq::tachyon {
    SetMaxSizeʸMCommand::SetMaxSizeʸMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSizeʸMCommand::SetMaxSizeʸMCommand(const Header& h, Meter v) : 
        SizeCommand(h), m_y(v)
    {
    }

    SetMaxSizeʸMCommand::SetMaxSizeʸMCommand(const SetMaxSizeʸMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetMaxSizeʸMCommand::~SetMaxSizeʸMCommand()
    {
    }

    PostCPtr    SetMaxSizeʸMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSizeʸMCommand(*this, h);
    }
    
    void SetMaxSizeʸMCommand::init_meta()
    {
        auto w = writer<SetMaxSizeʸMCommand>();
        w.description("SetMax Size MCommand in Y");
        w.property("y", &SetMaxSizeʸMCommand::m_y).tag(kTag_Log).tag(kTag_Save);
    }
}
