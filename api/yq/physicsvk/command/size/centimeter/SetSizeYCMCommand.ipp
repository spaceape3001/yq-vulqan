////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSizeYCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSizeʸCMCommand)

namespace yq::tachyon {
    SetSizeʸCMCommand::SetSizeʸCMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSizeʸCMCommand::SetSizeʸCMCommand(const Header& h, Centimeter v) : 
        SizeCommand(h), m_y(v)
    {
    }

    SetSizeʸCMCommand::SetSizeʸCMCommand(const SetSizeʸCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetSizeʸCMCommand::~SetSizeʸCMCommand()
    {
    }

    PostCPtr    SetSizeʸCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSizeʸCMCommand(*this, h);
    }
    
    void SetSizeʸCMCommand::init_meta()
    {
        auto w = writer<SetSizeʸCMCommand>();
        w.description("Set Size CMCommand in Y");
        w.property("y", &SetSizeʸCMCommand::m_y).tag(kTag_Log).tag(kTag_Save);
    }
}
