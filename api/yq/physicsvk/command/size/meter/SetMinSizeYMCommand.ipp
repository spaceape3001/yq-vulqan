////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSizeYMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSizeʸMCommand)

namespace yq::tachyon {
    SetMinSizeʸMCommand::SetMinSizeʸMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSizeʸMCommand::SetMinSizeʸMCommand(const Header& h, Meter v) : 
        SizeCommand(h), m_y(v)
    {
    }

    SetMinSizeʸMCommand::SetMinSizeʸMCommand(const SetMinSizeʸMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetMinSizeʸMCommand::~SetMinSizeʸMCommand()
    {
    }

    PostCPtr    SetMinSizeʸMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSizeʸMCommand(*this, h);
    }
    
    void SetMinSizeʸMCommand::init_meta()
    {
        auto w = writer<SetMinSizeʸMCommand>();
        w.description("SetMin Size MCommand in Y");
        w.property("y", &SetMinSizeʸMCommand::m_y).tag(kTag_Log).tag(kTag_Save);
    }
}
